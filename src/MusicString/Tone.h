#pragma once
#include <string>
#include "Utility.h"
using namespace std;

namespace MusStr
{
	enum NoteDuration
	{
		note128th,
		note64th,
		note32th,
		note16th,
		note8th,
		note4th,
		note2th,
		note1x,
		note2x,
		note4x
	};

	enum WaveForm
	{
		waveSine,
		waveSquare,
		waveTriangle,
		waveSawtooth,
		wavePluck,
		waveNoise
	};

	enum VolumeShape
	{
		volLinear,
		volFadeIn,
		volFadeOut
	};

	class Tone
	{
		float freq,		// in hertz
			  time,		// in milliseconds
			  vol;	// 0.0 - 1.0
		WaveForm wave;
		VolumeShape vshape;
		string sfont;

		uint pos;	// position of the corresponding character in the string

	public:
		Tone();
		Tone(string tone);
		Tone(float freq, float time, float vol,
			WaveForm wave, VolumeShape vshape,
			string sfont, uint pos);

		inline float GetFreq() { return freq; }
		inline float GetDuration() { return time; }
		inline float GetVolume() { return vol; }
		inline float GetShape(float progress)
		{
			switch(vshape)
			{
			case volLinear:
				return 1.0f;
			case volFadeIn:
				return progress*progress;
			case volFadeOut:
				return (1.0f-progress)*(1.0f-progress);
			}
			return 0.0f;	// make compiler happy
		}
		inline WaveForm GetWaveForm() { return wave; }

		string GetMusicListEntry();
	};
}