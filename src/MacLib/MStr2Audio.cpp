#include "MStr2Audio.h"

namespace MusStr
{
	MStr2Audio::MStr2Audio(string musstr, uint samplerate)
	{
		mstr = new MusicString(musstr);
		agen = new AudioGen(samplerate, 512);
		norm_level = 1.0f;
	}

	uint MStr2Audio::Generate(float *buf, uint samples, bool cnorm)
	{
		return Generate(buf, samples, cnorm, 0);
	}

	uint MStr2Audio::Generate(float *buf, uint samples, bool cnorm,
		std::list<MusListItem> *list)
	{
		// keep on generating, until the MusicString is done (if even...)
		bool finalize = false;
		uint generated = 0;

		while((samples-generated) && !finalize)
		{
			// generate music list until it's enough for the generatator
			if(!agen->NeedList())
			while(!(finalize = mstr->Done())
				&& !agen->Append(
				SnatchList(mstr->GenMusicList(50), list), true));

			generated +=
				agen->Generate(buf+generated, samples-generated, finalize);			
		}

		if(cnorm)
		{
			for(int i = 0; i < generated; ++i)
			{
				norm_level += 0.0001;
				if(norm_level > 1.0f)
					norm_level = 1.0f;

				if( abs(*(buf+i) *= norm_level) > 0.95f )
				{
					norm_level = abs(0.75f/(*(buf+i)));
					*(buf+i) *= norm_level;
				}
			}
		}

		return generated;
	}

	std::list<MusListItem> *MStr2Audio::SnatchList(std::list<MusListItem> *in, 
			std::list<MusListItem> *copyto)
	{
		if(copyto && in)
			copyto->insert(copyto->end(), in->begin(),
				in->end());
		return in;
	}
}