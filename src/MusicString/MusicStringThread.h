#pragma once
#include <string>
#include <stack>
#include <cmath>
#include "Tone.h"
#include "Utility.h"
#include "MusicStringException.h"

using namespace std;

namespace MusStr
{
	enum SpecialChars
	{
		SUBR_SKIP_CHAR = 128	// causes the thread to skip subroutine definition
	};

	class MusicStringThread
	{
		bool lastTickGenerated;	// did last tick generate audio?
		bool finished;			// is it done? 

		string *musstr;	// the music sting that it's being operated on
		string name;	// it's possible to name the thread

		int bpos,		// beginning position
			pos,		// current position in the string
			epos,		// ending position in the string
			lastpos,	// pos of the last character from the buffer
			repeat;		// how many times will it repeat

		int waiting;	// how many threads is this one waiting for

		Tone tone;		// last generated tone

		class MusicString *owner;	// who owns the thread
		MusicStringThread *parent;	// thread that craeated this thread

		float nextUpdate;

		struct Argument
		{
			uint e, p;
			Argument(uint begin, uint end)
			{	p = begin; e = end;		}
			Argument() { e = 0; p = 1; }
			bool Empty() { return p > e; }
		};

		struct ThreadStatus
		{
			float bpm;
			float volume;
			NoteDuration duration;
			int nshift;
			WaveForm wave;
			VolumeShape volshape;
			string soundfont;
			Argument args[32];
		} status;

		float ProcessChar(char ch);

		int CalcN(char letter, char center);

		float GenTone(char note);
		float GenPause();

		void SetDuration(char dur);
		void LoadChord();
		void LoadSubroutine();
		void LoadLoop();
		void LoadBpm();
		void LoadSoundfont();
		void LoadVolume();

		void PerformShift();
		void EvaluateCondition(char type);
		void SetWaveform(char wave);
		void SetVolumeShape(char shape);
		void SkipSubroutineDefinition();

		void LoadArg();	// load one argument into the string buffer

		stack<Argument> buffer;
		char GetChar(bool evalarg = true);	// gets a char from the buffer
		int GetPos();	// gets position of just loaded char

	public:
		MusicStringThread(string *musstr, class MusicString *owner,
			int pos = 0, int epos = -1, ThreadStatus *status = 0,
			MusicStringThread *parent = 0, int repeat = 1, string name = "");

		~MusicStringThread();

		void SubthreadDone(float nextUpdate);
		void TerminateLoop();

		void Tick();		// perform a single step - generate a tone

		bool Active() { return !waiting; }	// does it even have last tone?
		bool Finished() { return finished && !waiting; }
		bool LastTickGenerated() { return lastTickGenerated; }
		Tone GetLastTone() { return tone; }	// get the generated tone
		string GetName() { return name; }

		float NextUpdate() {
			return (waiting)?(float)FINF:nextUpdate; }
		void NextUpdate(float subtract) { nextUpdate = Max(0.0f, nextUpdate-subtract); }
	};
}