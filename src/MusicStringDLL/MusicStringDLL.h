// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the MUSICSTRINGDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// MUSICSTRINGDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef MUSICSTRINGDLL_EXPORTS
#define MUSICSTRINGDLL_API extern "C" __declspec(dllexport)
#else
#define MUSICSTRINGDLL_API extern "C" __declspec(dllimport)
#endif

#include "windows.h"
#include <string>

using namespace std;

enum eCompileStatus
{
	compileOK,
	compileDONE,
	compileNOINIT,
	compileERROR
};

// API
MUSICSTRINGDLL_API bool Init();

MUSICSTRINGDLL_API void SetMusicString(char *);
MUSICSTRINGDLL_API void SetOutFile(char *);
MUSICSTRINGDLL_API void SetSampleRate(unsigned);
MUSICSTRINGDLL_API void SetSeconds(unsigned);

MUSICSTRINGDLL_API bool Play();
MUSICSTRINGDLL_API void Pause();
MUSICSTRINGDLL_API void Stop();

MUSICSTRINGDLL_API char *GetStatus();
MUSICSTRINGDLL_API eCompileStatus PhaseCompile();
MUSICSTRINGDLL_API bool Compile(char *, char *, unsigned, unsigned);
