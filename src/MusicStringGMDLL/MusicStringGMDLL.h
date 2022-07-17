// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the MUSICSTRINGGMDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// MUSICSTRINGGMDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef MUSICSTRINGGMDLL_EXPORTS
#define MUSICSTRINGGMDLL_API extern "C" __declspec(dllexport)
#else
#define MUSICSTRINGGMDLL_API extern "C" __declspec(dllimport)
#endif

// Gamemaker compatibility
MUSICSTRINGGMDLL_API double GMInit();
MUSICSTRINGGMDLL_API double GMSetMusicString(char *);
MUSICSTRINGGMDLL_API double GMSetOutFile(char *);
MUSICSTRINGGMDLL_API double GMSetSampleRate(double);
MUSICSTRINGGMDLL_API double GMSetSeconds(double);

MUSICSTRINGGMDLL_API double GMPlay();
MUSICSTRINGGMDLL_API double GMPause();
MUSICSTRINGGMDLL_API double GMStop();

MUSICSTRINGGMDLL_API char *GMGetStatus();
MUSICSTRINGGMDLL_API double GMPhaseCompile();
MUSICSTRINGGMDLL_API double GMCompile(char *, char *, double, double);




