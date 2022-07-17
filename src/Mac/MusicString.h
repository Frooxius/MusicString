#pragma once
#include <string>
#include <list>
#include <map>
#include "MusicStringThread.h"
#include "Tone.h"
#include "Utility.h"

using namespace std;

namespace MusStr
{
	struct StrRange
	{
		int posb, pose;
		StrRange() { posb = pose = -1; }
		StrRange(int posb, int pose)
		{
			this->posb = posb;
			this->pose = pose;
		}
	};

	struct MusListItem
	{
		double next_update;
		list<Tone> tones;

		MusListItem() { next_update = 0.0; tones = list<Tone>(); }
		MusListItem(string line)
		{
			// get the time
			next_update = FromString<float>(line);
			// remove it
			line = line.substr(line.find('-')+1);

			// get the tones 
			tones = list<Tone>();

			while(line.find(';') != line.npos)		
			{
				tones.push_back( Tone(
					line.substr(0, line.find(';'))) );
				// remove it
				line = line.substr(line.find(';')+1);
			}
		}
	};

	class MusicString
	{
	private:
		typedef MusicStringThread Thread;

		string musstr;			// the music string that's being processed 

		list<Thread*> threads;				// all the threads
		map<string, StrRange> subroutines;	// isn't this self explanatory? -_-

		float newthread_elapsed;

		void InitParse();		// must be called first, does the first pass parsing
		MusListItem GetLine();		// get a single line

	public:
		MusicString(string musstr);

		// Interacting with threads
		void InsertThread(MusicStringThread *mt, bool wait);
		void StopLoop(string name);

		string GetSoundfontList();
		list<MusListItem> *GenMusicList(int maxlines);

		// Getting info, mostly for threads
		StrRange GetSubroutinePos(string name);

		bool Done() {
			return threads.empty(); }
	};
}