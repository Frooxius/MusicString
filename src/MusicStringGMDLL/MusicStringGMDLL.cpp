// MusicStringGMDLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "MusicStringGMDLL.h"
#include "MusicStringDLL.h"

/* ********************************************************
					GameMaker compatible API
	******************************************************/

MUSICSTRINGGMDLL_API double GMInit() { return (int)Init(); }
MUSICSTRINGGMDLL_API double GMSetMusicString(char *pch) { SetMusicString(pch); return 1.0; }
MUSICSTRINGGMDLL_API double GMSetOutFile(char *pch) { SetOutFile(pch); return 1.0; }
MUSICSTRINGGMDLL_API double GMSetSampleRate(double d) { SetSampleRate((unsigned)d); return 1.0; }
MUSICSTRINGGMDLL_API double GMSetSeconds(double d) { SetSeconds((unsigned)d); return 1.0; }

MUSICSTRINGGMDLL_API double GMPlay() { return (int)Play(); }
MUSICSTRINGGMDLL_API double GMPause() { Pause(); return 1.0; }
MUSICSTRINGGMDLL_API double GMStop() { Stop(); return 1.0; }

MUSICSTRINGGMDLL_API char *GMGetStatus() { return GetStatus(); }
MUSICSTRINGGMDLL_API double GMPhaseCompile() { return (int)PhaseCompile(); }
MUSICSTRINGGMDLL_API double GMCompile(char *ch0, char *ch1, double d0, double d1)
{ return (int)Compile(ch0, ch1, (unsigned)d0, (unsigned)d1); }