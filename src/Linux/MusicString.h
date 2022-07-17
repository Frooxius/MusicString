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

	class MusicString
	{
	private:
		typedef MusicStringThread Thread;

		string musstr;			// the music string that's being processed 

		list<Thread*> threads;				// all the threads
		map<string, StrRange> subroutines;	// isn't this self explanatory? -_-

		float newthread_elapsed;

		void InitParse();		// must be called first, does the first pass parsing
		string GetLine();		// get a single line

	public:
		MusicString(string musstr);

		// Interacting with threads
		void InsertThread(MusicStringThread *mt, bool wait);
		void StopLoop(string name);

		string GetSoundfontList();
		list<string> *GenMusicList(int maxlines);

		// Getting info, mostly for threads
		StrRange GetSubroutinePos(string name);

		bool Done() { return threads.empty(); }
	};
}