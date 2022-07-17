#include "Tone.h"

namespace MusStr
{
	const char *waveFormSymbol = "~-^/|*";
	const char *volumeShapeSymbol = "=<>";

	Tone::Tone()
	{
		freq = time = vol = 0;
		wave = waveSine;
		vshape = volLinear;
		sfont = "";
		pos = -1;
	}

	Tone::Tone(float freq, float time, float vol,
			WaveForm wave, VolumeShape vshape,
			string sfont, uint pos)
	{
		this->freq = freq;
		this->time = time;
		this->vol = vol;
		this->wave = wave;
		this->vshape = vshape;
		this->sfont = sfont;
		this->pos = pos;

		this->freq_target = freq;
		this->vib_freq = 0.0f;
		this->vib_ratio = 0.0f;
	}

	Tone::Tone(float freq, float time, float vol,
			 float freq_target, float vib_freq, float vib_ratio,
			WaveForm wave, VolumeShape vshape,
			string sfont, uint pos)
	{
		this->freq = freq;
		this->time = time;
		this->vol = vol;
		this->wave = wave;
		this->vshape = vshape;
		this->sfont = sfont;
		this->pos = pos;

		this->freq_target = freq_target;
		this->vib_freq = vib_freq;
		this->vib_ratio = vib_ratio;
	}

	string Tone::GetMusicListEntry()
	{
        return ToStringFixed(freq) + waveFormSymbol[wave] +
            ToStringFixed(vol) + volumeShapeSymbol[vshape] +
            ToStringFixed(time) + '"' + sfont + '"' + ';';
	}

	Tone::Tone(string tone)
	{
		int pos = 0;
		freq = FromString<float>(tone);

		while(tone[pos] == '.' || isdigit(tone[pos]) || isspace(tone[pos]))
			pos++;
		
		for(int i = 0; *(waveFormSymbol+i); ++i)
			if(*(waveFormSymbol+i) == tone[pos])
			{
				wave = (WaveForm)i;
				break;
			}

		// the volume
		vol = FromString<float>(tone.substr(++pos));
		
		while(tone[pos] == '.' || isdigit(tone[pos]) || isspace(tone[pos]))
			pos++;

		for(int i = 0; *(volumeShapeSymbol+i); ++i)
			if(*(volumeShapeSymbol+i) == tone[pos])
			{
				vshape = (VolumeShape)i;
				break;
			}

		// duration
		time = FromString<float>(tone.substr(++pos));

		// soundfont
		tone = tone.substr(tone.find('"')+1);
		sfont = tone.substr(0, tone.find('"'));
	}
}