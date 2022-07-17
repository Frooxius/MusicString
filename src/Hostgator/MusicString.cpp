#include "MusicString.h"

namespace MusStr
{
	bool DeleteThread(MusicStringThread *t)
	{
		if(t->Finished())
		{
			delete t;
			return true;
		}
		return false;
	}

	MusicString::MusicString(string musstr)
	{
		this->musstr = musstr;
		InitParse();

		newthread_elapsed = (float)FINF;
		// initialize first thread
		threads.push_back(new Thread(&this->musstr, this));
	}

	string MusicString::GetLine()
	{
		list<Tone> tones;	// all the tones for a single line

		float following_update = (float)FINF;

		do
		{
			// generate tones from all threads that are due to update
			for(list<Thread*>::iterator i = threads.begin();
				i != threads.end(); i++)
			{
				if((*i)->NextUpdate() == 0.0f || isinf((*i)->NextUpdate()))
				{
					(*i)->Tick();
					
					// thread generated something
					if((*i)->Active())
						tones.push_back(
						(*i)->GetLastTone());
				}
			}

			// delete all threads marked for deletion
			threads.remove_if(DeleteThread);

			// find next update time
			for(list<Thread*>::iterator i = threads.begin();
				i != threads.end(); i++)
				following_update = Min(following_update, (*i)->NextUpdate());

			// shift all of them to the next update
			for(list<Thread*>::iterator i = threads.begin();
				i != threads.end(); i++)
				(*i)->NextUpdate(following_update);

		} while(tones.empty() && !threads.empty());

		// it's last in the list
		if(isinf(following_update))
		{
			following_update = 0.0f;
			for(list<Tone>::iterator i = tones.begin();
				i != tones.end(); i++)
				following_update = 
					Max(i->GetDuration(), following_update);
		}

		string line = ToString(following_update) + " - ";

		for(list<Tone>::iterator i = tones.begin();
				i != tones.end(); i++)
			line += i->GetMusicListEntry();

		return line;
	}

	list<string> *MusicString::GenMusicList(int maxlines)
	{
		list<string> *muslist = new list<string>();

		for(; maxlines > 0 && !Done(); maxlines--)
 			muslist->push_back(GetLine());

		return muslist;
	}

	void MusicString::InitParse()
	{
		// Look for subroutine definitions
		int openpos = -1;
		bool openscan = false;
		string subname;
		for(uint p = 0; p < musstr.length(); ++p)
		{
			char ch = musstr[p];
			// beginning is found
			if(ch == '{' && !openscan)
			{
				// start scanning if it's a subroutine or not
				subname = "";
				openscan = true;
				openpos = p;
				continue;
			}
			if(openscan)
			{
				if((isalpha(ch) || isdigit(ch)))
					subname += ch;
				else if(ch == ';')
				{
					/*  first overwrite opening with special symbol
						so the definition is ignored when further
						parsing the code when generating tones */
					musstr[openpos] = (char)SUBR_SKIP_CHAR;

					int begin = ++p;
					int depth = 1;
					for(; p < musstr.length(); ++p)
					{
						ch = musstr[p];
						if(ch == '{')
							depth++;
						if(ch == '}')
							depth--;
						if(!depth)
						{
							// found end of the subroutine body
							subroutines.insert(
								pair<string, StrRange>(subname,
									StrRange(begin, p-1)));
							openscan = false;
							break;
						}
					}
				} else
				{
					// it's not a subroutine definition, discard
					openscan = false;
				}
			}
		}
	}

	void MusicString::InsertThread(MusicStringThread *mt, bool wait)
	{
		threads.push_back(mt);
	}

	void MusicString::StopLoop(string name)
	{
		for(list<Thread*>::iterator i = threads.begin();
				i != threads.end(); i++)
		{
			if((*i)->GetName() == name)
				(*i)->TerminateLoop();
		}
	}

	StrRange MusicString::GetSubroutinePos(string name)
	{
		map<string, StrRange>::iterator i =
			subroutines.find(name);
		if(i == subroutines.end())
			throw MusicStringException(ERR_MUSSTR_SUB_NOT_FOUND,
			"Name: " + name);
		return i->second;
	}
}