#include "MusicStringThread.h"
#include "MusicString.h"	// cross dependency
#include "Tone.h"

namespace MusStr
{
	MusicStringThread::MusicStringThread(string *musstr,
	class MusicString *owner, int pos, int epos, ThreadStatus *status,
		MusicStringThread *parent, int repeat, string name)
	{
		this->lastTickGenerated = false;
		this->finished = false;

		this->musstr = musstr;
		this->bpos = this->pos = pos;
		this->epos = epos;
		this->owner = owner;
		this->repeat = repeat;
		this->name = name;

		this->waiting = 0;
		this->nextUpdate = 0.0f; // new threads are updated right way

		// copy the status if provided (it's a child thread)
		if(status)
			this->status = *status;
		else
		{
			// initialize the arguments
			this->status.bpm = 120.0f;
			this->status.duration = note4th;
			this->status.nshift = 0;
			this->status.soundfont = "0";
			this->status.volshape = volLinear;
			this->status.volume = 0.2f;
			this->status.wave = waveSine;
			for(int i = 0; i < 32; ++i)
				this->status.args[i] = Argument();
		}

		// set the parent thread (might be NULL, that's okay)
		this->parent = parent;
	}

	MusicStringThread::~MusicStringThread()
	{
		if(parent)
			parent->SubthreadDone(nextUpdate);
	}

	void MusicStringThread::Tick()
	{
		// nothing to do
		if(finished)
			return;

		nextUpdate = FINF;

		while(isinf(nextUpdate) && !waiting && !finished)
			nextUpdate = ProcessChar(GetChar());

		lastTickGenerated = !isinf(nextUpdate);
	}

	void MusicStringThread::SubthreadDone(float nextUpdate)
	{
		waiting--;
		if(isinf(this->nextUpdate))
			this->nextUpdate = nextUpdate;
		else
			this->nextUpdate = Max(nextUpdate, this->nextUpdate);
	}

	char MusicStringThread::GetChar(bool evalarg)
	{
		char ch;	// char to be returned

		do
		{
			// first, do buffer cleanup
			while((buffer.size() != 0) && (buffer.top().Empty() ))
					buffer.pop();

			if(buffer.empty())
			{
				lastpos = pos;
				ch = (*musstr)[Min(pos, (int)musstr->length()-1)];

				if( ((pos == epos) && (epos != -1)) || pos == musstr->length()-1)
				{
					if(--repeat == 0)
					{
						pos++;
						finished = true;
					}
					else
					{
						// reset it
						pos = bpos;
						if(repeat < 0)
							repeat = 0;
					}
				}
				else
					pos++;
			}
			else
			{
				lastpos = buffer.top().p++;
				ch = (*musstr)[Min(lastpos, (int)musstr->length()-1)];
			}

			if((ch == '$') && evalarg)
			{
				LoadArg();
				ch = GetChar();
			}
		} while((ch > 0) && isspace(ch));	// skip all whitespace characters

		return ch;
	}

	void MusicStringThread::LoadArg()
	{
		char ch = tolower(GetChar());
		int index = -1;

		// convert ch to index and then load it
		if(isdigit(ch))
			index = ch-'0';

		if(isalpha(ch))
			index = ch-'a' + 10;

		if(index != -1)
			buffer.push(status.args[index]);
	}

	float MusicStringThread::ProcessChar(char ch)
	{
		/* Must test high ASCII characters first, because
		standard library functions do bollocks when it's apssed
		to them */
		if(ch == (char)SUBR_SKIP_CHAR)
			SkipSubroutineDefinition();
		else if(isalpha(ch))
			return GenTone(ch);
		else if(ch == '.')
			return GenPause();
		else if(isalnum(ch))
			SetDuration(ch);
		else if(ch == '(')
			LoadChord();
		else if(ch == '{')
			LoadSubroutine();
		else if(ch == '[')
			LoadLoop();
		else if(ch == '&')
			PerformShift();
		else if(ch == '@')
			LoadBpm();
		else if(ch == '#')
			LoadSoundfont();
		else if(ch == '%')
			LoadVolume();
		else if(ch == '?' || ch == '!')
			EvaluateCondition(ch);
		else if(
			ch == '~' ||
			ch == '/' ||
			ch == '-' ||
			ch == '|' ||
			ch == '^' ||
			ch == '*')
			SetWaveform(ch);
		else if(
			ch == '=' ||
			ch == '<' ||
			ch == '>')
			SetVolumeShape(ch);
		else if(ch == (char)SUBR_SKIP_CHAR)
			SkipSubroutineDefinition();
		else throw MusicStringException(
			ERR_MUSSTR_ILLEGAL_SYMBOL, string(" \"") + ch + "\" - At pos: " + 
			ToString(GetPos()));

		return FINF;
	}

	int MusicStringThread::CalcN(char letter, char center)
	{
		return (tolower(letter)-(int)'a')*2
            + (bool)isupper(letter) -
            (tolower(center)-'a')*2 - (bool)isupper(center);
	}

	float MusicStringThread::GenTone(char note)
	{
		// first, compute the base n
		int n = CalcN(note, 'n');

		// now add the shift
		n += status.nshift;

		// calculate the frequency
		float f = pow(2.0f, n/12.0f)*440.0f;

		// calculate duration
		float d = pow(2.0f, status.duration - note4th)
			* (1.0f/(status.bpm/60.0f));

		// create new note
		tone = Tone(f, d, status.volume, status.wave,
			status.volshape, status.soundfont, GetPos());

		return d;
	}

	float MusicStringThread::GenPause()
	{
		// calculate duration
		float d = pow(2.0f, status.duration - note4th)
			* (1.0f/(status.bpm/60.0f));

		tone = Tone(0.0f, d, 0.0f, status.wave,
			status.volshape, status.soundfont, GetPos());

		return d;
	}

	void MusicStringThread::SetDuration(char dur)
	{
		status.duration = (NoteDuration)(dur-'0');
	}

	void MusicStringThread::LoadChord()
	{
		// load all parts and create respective threads
		int beginpos = -1, endpos = -1;
	
		int depth = 1;	// in case there are any nested
		do
		{
			char ch;
			endpos = GetPos();
			switch(ch = GetChar(false))
			{
			case '[':
			case '{':
			case '(':
			case (char)SUBR_SKIP_CHAR:
				depth++;
				break;
			case ']':
			case '}':
			case ')':
				depth--;

				if(depth != 0)
					break;
				// fall trough if it's existinng - there's still argument
			case ',':
				if(depth <= 1)
				{
					if(beginpos != -1)
					{
						MusicStringThread *mt = new MusicStringThread(
							musstr, owner, beginpos, endpos,
							&status, this);
						owner->InsertThread(mt, lastTickGenerated);
						waiting++;
						beginpos = -1;	// reset it
					}
					else
					{
						throw MusicStringException(
							ERR_MUSSTR_CHORD_EMPTY_ARG,
							" - At pos: " + ToString(GetPos()));
					}
				}
				break;
			}
			if(beginpos == -1 && ch != ',')
				beginpos = GetPos();
		} while(depth);
	}

	void MusicStringThread::LoadSubroutine()
	{
		// load the subroutine name first

		char ch;
		string subname;
		while((ch = GetChar()) != ':')
			subname += ch;

		// fetch the subroutine position from the owner
		StrRange sub = owner->GetSubroutinePos(subname);
		ThreadStatus newstatus = status;

		// load the arguments
		int depth = 1, argn = 0, beginpos = -1, endpos = -1;
		do
		{
			char ch;
			endpos = GetPos();
			switch(ch = GetChar())
			{
			case '[':
			case '{':
			case '(':
			case (char)SUBR_SKIP_CHAR:
				depth++;
				break;				
			case ']':
			case '}':
			case ')':
				depth--;

				// if there's still some part, load it
				if(depth)
					break;

			case ',':
				if(depth > 1)
					break;

				if(beginpos != -1)
				{
					// set the argument
					newstatus.args[argn] = Argument(beginpos, endpos);
					beginpos = -1; // rest it again
				}
				argn++;	// empty arguments are simply skipped

				if(argn == 32)
					throw MusicStringException(
						ERR_MUSSTR_SUB_TOO_MANY_ARGS);

				break;
			}
			if(beginpos == -1 && ch != ',')
				beginpos = GetPos();

		} while(depth);

		// make new thread
		MusicStringThread *mt = new MusicStringThread(
			musstr, owner, sub.posb, sub.pose,
			&newstatus, this);

		waiting++;
		owner->InsertThread(mt, lastTickGenerated);
	}

	void MusicStringThread::LoadLoop()
	{
		// first, determine what kind of statement it is
		StrRange part[3];

		int beginpos = -1, endpos = -1, p = 0, depth = 1;
		do
		{
			char ch;
			endpos = GetPos();
			switch(ch = GetChar(false))
			{
			case '[':
			case '{':
			case '(':
			case (char)SUBR_SKIP_CHAR:
				depth++;
				break;
			case ']':
			case '}':
			case ')':
				depth--;

				// fall trough if there's still some last part
				if(beginpos == -1 || depth != 0)
					break;
			case ':':
				if(depth > 1)
					break;

				if(beginpos == -1)
					throw MusicStringException(
						ERR_MUSSTR_LOOP_EMPTY_PART);

				if(p == 3)
					throw MusicStringException(
						ERR_MUSSTR_LOOP_TOO_MANY_PARTS);

				part[p].posb = beginpos;
				part[p].pose = endpos;
				beginpos = -1;
				p++;
				break;
			}
			if(beginpos == -1 && ch != ':')
					beginpos = GetPos();
		} while(depth);

		// now decide what to do, once all parts are loaded
		string loopname = "";
		int pshift = 0;	// to choose the best part
		if(p == 1 || p == 3)
		{
			// fetch the loop name, strip it from 
			loopname = StripSpaces(substrBetween(musstr,
				part[0].posb, part[0].pose+1));
			pshift = 1;	// first part is name
		}

		if(p == 1)
			owner->StopLoop(loopname);

		if(p == 2 || p == 3)
		{
			owner->InsertThread(new MusicStringThread(
				musstr, owner, part[0+pshift].posb, part[0+pshift].pose,
				&status, this, FromString<int>(
				substrBetween(musstr, part[1+pshift].posb,
				part[1+pshift].pose+1 )), loopname),
					lastTickGenerated);

			waiting++;
		}
	}

	void MusicStringThread::LoadBpm()
	{
		// read number
		char ch;
		string num;
		while((ch = GetChar()) != ';')
			num += ch;

		// convert it to number
		status.bpm = FromString<float>(num);
	}
	void MusicStringThread::LoadSoundfont()
	{
		// read soundfont
		status.soundfont = "";
		char ch;
		while((ch = GetChar()) != ';')
			status.soundfont += ch;
	}

	void MusicStringThread::LoadVolume()
	{
		char ch = GetChar();	// get volume index
		status.volume = CalcN(ch, 'a')/(float)CalcN('Z', 'a');
		// do some rounding, round doesn't work in VC++ :-/
		status.volume = floor(status.volume*100.0f + 0.5f)/100.0f;
	}

	void MusicStringThread::PerformShift()
	{
		char ch = GetChar();

		status.nshift = 0; // reset it first
		// check if it's halfshift
		if(ch == '-' || ch == '+')
		{
			if(ch == '+')
				status.nshift++;
			else
				status.nshift--;
			ch = GetChar(); // must load following character
		}

		// now translate the character into shift
		status.nshift += CalcN(ch, 'n')*2;
	}

	void MusicStringThread::EvaluateCondition(char type)
	{
		// TODO
	}

	void MusicStringThread::SetWaveform(char wave)
	{
		switch(wave)
		{
		case '~':
			status.wave = waveSine;
			break;
		case '-':
			status.wave = waveSquare;
			break;
		case '^':
			status.wave = waveTriangle;
			break;
		case '/':
			status.wave = waveSawtooth;
			break;
		case '|':
			status.wave = wavePluck;
			break;
		case '*':
			status.wave = waveNoise;
			break;
		}
	}

	void MusicStringThread::SetVolumeShape(char vshape)
	{
		switch(vshape)
		{
		case '=':
			status.volshape = volLinear;
			break;
		case '<':
			status.volshape = volFadeIn;
			break;
		case '>':
			status.volshape = volFadeOut;
			break;
		}
	}

	int MusicStringThread::GetPos()
	{
		return lastpos;
	}

	void MusicStringThread::TerminateLoop()
	{
		repeat = 1;
	}

	void MusicStringThread::SkipSubroutineDefinition()
	{
		// simply skip the whole subroutine definition
		int depth = 1;
		do
		{
			char ch = GetChar(false);
			if(ch == '{')
				depth++;
			else if(ch == '}')
				depth--;
		} while(depth);
	}
};