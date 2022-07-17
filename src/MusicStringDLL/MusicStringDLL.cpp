#include "MusicStringDLL.h"

#include "MStr2Audio.h"
#include "Compiler.h"

#include "SDL.h"
#include "SDL_audio.h"

using namespace MusStr;

Compiler *compiler = 0;
MStr2Audio *mstr2audio = 0;

bool initialized = false;

// settings
uint bufzize = 4098;
uint sampleRate = 44100;
uint seconds = 30*60;
float peak = 0.95;

bool pause = false;

string code;
string outfile;

// status
char *compilerMsg = "Not Initialized";

bool Init()
{
	//atexit(SDL_Quit);

	if (SDL_Init (SDL_INIT_AUDIO) < 0)
		return false;
	return true;
}

MUSICSTRINGDLL_API void SetMusicString(char *musstr)
{
	if(musstr)
		code = musstr;
}

MUSICSTRINGDLL_API void SetOutFile(char *fname)
{
	if(fname)
		outfile = fname;
}

MUSICSTRINGDLL_API void SetSampleRate(uint rate)
{
	if(rate != 0)
		sampleRate = rate;
}

MUSICSTRINGDLL_API void SetSeconds(uint newseconds)
{
	if(newseconds != 0)
		seconds = newseconds;
}

MUSICSTRINGDLL_API char *GetStatus()
{
	return compilerMsg;
}

MUSICSTRINGDLL_API bool Compile(char *musstr, char *filename,
	uint rate, uint time)
{
	string code_backup = code,
		outfile_backup = outfile;
	uint sampleRate_backup = sampleRate,
		seconds_backup = seconds;
	Compiler *compiler_backup = compiler;

	SetOutFile(filename);
	SetMusicString(musstr);
	SetSampleRate(rate);
	SetSeconds(time);

	compiler = 0;
	eCompileStatus status;

	while(!(status = PhaseCompile()));
	
	code = code_backup;
	outfile = outfile_backup;
	sampleRate = sampleRate_backup;
	seconds = seconds_backup;

	return status == compileDONE;
}

MUSICSTRINGDLL_API eCompileStatus PhaseCompile()
{
	if(code.empty() || outfile.empty())
	{
		compilerMsg = "Not Initialized";
		return compileNOINIT;
	}

	// we ought to make compiler first
	if(!compiler)
	{
		compiler = new Compiler(code, outfile, sampleRate, seconds, 
			peak, formatWAV, sampleSINT16, normClipping);
	}

	try
	{
		if(compiler->Compile(&compilerMsg))
		{
			return compileOK;
		}
		else
		{
			delete compiler;
			return compileDONE;
		}
	}
	catch(MusicStringException err)
	{
		compilerMsg = "Error!";
		delete compiler;
		return compileERROR;
	}
}

void GenAudio(void *nothing, byte *stream, int len)
{
	ushort *data = (ushort*)stream;

	// generate data from MStr2Audio
	float *buf = new float[len/sizeof(short)];
	
	uint generated = 0;

	try
	{
	generated += mstr2audio->Generate(buf, len/sizeof(short), true);
	}
	catch(...)
	{
	}

	for(int i = generated; i < len/sizeof(short); ++i)
		buf[i] = 0.0f;

	// convert it
	for(int i = 0; i < len/sizeof(short); ++i)
		*(data+i) = (short) ((*(buf+i))*0x7FFF);
}

MUSICSTRINGDLL_API bool Play()
{
	Stop();

	SDL_AudioSpec spec;
    spec.freq = sampleRate;
    spec.format = AUDIO_S16SYS;
    spec.channels = 1;
    spec.silence = 0;
    spec.samples = bufzize;
    spec.padding = 0;
    spec.size = 0;    
    spec.userdata = 0;

	mstr2audio = new MStr2Audio(code, sampleRate);

    spec.callback = GenAudio;
    if (SDL_OpenAudio (&spec, NULL) < 0)
		return false;

	pause = false;
    SDL_PauseAudio (0);
}

MUSICSTRINGDLL_API void Pause()
{
	pause = !pause;
	SDL_PauseAudio(pause);
}

MUSICSTRINGDLL_API void Stop()
{
	pause = false;
	SDL_CloseAudio();
	if(mstr2audio)
		delete mstr2audio;
}



