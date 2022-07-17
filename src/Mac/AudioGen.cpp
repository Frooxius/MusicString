#include "AudioGen.h"

namespace MusStr
{
	AudioGen::AudioGen(uint sampleRate,
		uint bufsize)
	{
		this->sampleRate = sampleRate;
		this->bufsize = bufsize;
		this->intern_buf_pos = bufsize;

		// create internal buffer
		intern_buffer = new float[bufsize];
		next_update = 0;	// update right away (when it's called)
	}

	bool AudioGen::Append(list<string> *appendlist, bool autodelete)
	{
		// create a list<MusListItem>
		list<MusListItem> *temp = new list<MusListItem>();

		for(list<string>::iterator i = appendlist->begin();
			i != appendlist->end(); ++i)
			temp->push_back(MusListItem(*i));

		if(autodelete)
			delete appendlist;

		return Append(temp, true);
	}

	bool AudioGen::Append(list<MusListItem> *appendlist, bool autodelete)
	{
		// append it
		muslist.insert(muslist.end(), appendlist->begin(),
			appendlist->end());

		if(autodelete)
			delete appendlist;

		// calculate if there's enough items to fill whole internal buffer
		return UpdateWarningItems();
	}

	uint AudioGen::Generate(float *buffer, uint samples, bool finalize)
	{
		uint generated = 0;
		bool breakout = false;
		while(samples)
		{
			for(; samples && (intern_buf_pos != bufsize);
				samples--, intern_buf_pos++, generated++)
				*(buffer+generated) = *(intern_buffer+intern_buf_pos);

			// need more MusicList data
			if(breakout && !finalize)
				break;

			// it's basically done
			if(generators.empty() && muslist.empty())
				break;

			if(intern_buf_pos == bufsize)
				// need to refill the buffer
				breakout = !FillInternBuff();
		}

		return generated;
	}

	bool AudioGen::UpdateWarningItems()
	{
		uint samples = 0;
		warning_items = 0;
		// start at the end and go back
		for(list<MusListItem>::reverse_iterator i = muslist.rbegin();
			i != muslist.rend(); i++)
		{
			samples += (uint)(i->next_update*sampleRate);
			warning_items++;

			if(samples >= bufsize)
				break;
		}
		if(samples < bufsize)
			return false;
		else
			return true;
	}

	bool AudioGen::FillInternBuff()
	{
		float *tempbuf = new float[bufsize];

		// reset the position
		intern_buf_pos = 0;

		// clean up buffer first
		for(uint i = 0; i < bufsize; ++i)
			*(intern_buffer+i) = 0.0f;

		uint offset = 0, remaining = bufsize, generated = 0;
		do
		{
			// calculate how much is going to be generated in this step
			generated = Min(next_update, remaining);
			next_update -= generated; // subtract how much is going to be generated

			// Go trough all the generators and generate audio
			for(list<GenItem>::iterator i = generators.begin();
				i != generators.end(); ++i)
			{
				i->active = i->gen->Generate(tempbuf+offset, generated);
				// add the data
				for(uint i = 0; i < generated; ++i)
					*(intern_buffer+offset+i) += *(tempbuf+offset+i);
			}

			// caltulate how much was generated and new offset and such
			offset += generated;
			remaining -= generated;

			// remove finished generators
			for(list<GenItem>::iterator i = generators.begin();
				i != generators.end(); ++i)
			{
				bool repeat;
				do
				{
					repeat = false;
					if(!i->active)
					{
						delete i->gen;
						i = generators.erase(i);
						if(i != generators.end())
							repeat = true;
					}
				} while(repeat);

				if(i == generators.end())
					break;
			}

			if(remaining)
				if(!LoadNextItem())
					break;
		} while(remaining);

		// cleanup
		delete tempbuf;

		return muslist.size() > warning_items;
	}

	bool AudioGen::LoadNextItem()
	{
		if(muslist.empty())
			return false;

		next_update = muslist.front().next_update*sampleRate;

		// go trough all the tones and make generators from them
		for(list<Tone>::iterator i = muslist.front().tones.begin();
			i != muslist.front().tones.end(); ++i)
			generators.push_back(
				GenItem(new Generator(*i, sampleRate))); 

		// remove the front entry
		muslist.pop_front();

		return true;
	}
}