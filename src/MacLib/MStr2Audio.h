#pragma once
#include "MusicString.h"
#include "AudioGen.h"
#include "Utility.h"

namespace MusStr
{
	/*
		This class handles converting MusicString to raw audio
		data.
	*/
	class MStr2Audio
	{
		MusicString *mstr;
		AudioGen *agen;

		std::list<MusListItem> *SnatchList(std::list<MusListItem> *in, 
			std::list<MusListItem> *copyto);

		float norm_level;

	public:
		MStr2Audio(string musstr, uint samplerate = 44100);

		// will generate audio and return how many samples were generated
		// cnorm - continuous normalization
		uint Generate(float *buf, uint samples, bool cnorm);
		uint Generate(float *buf, uint samples, bool cnorm, 
			std::list<MusListItem> *list);

		inline list<Tone> GetActiveTones() { return agen->GetActiveTones(); }
	};
}