#include "Generator.h"

namespace MusStr
{
	Generator::Generator(Tone tone, uint samplerate)
	{
		this->tone = tone;
		this->samplerate = samplerate;

		softnoise = 0.0f;
		noiseval = frand()*0.5f;
		nextchange = 1.0f;

		// caculate the angular step
		angle = 0;
		angular_step = (2.0*PI*tone.GetFreq())/(double)this->samplerate;

		// caculate how many samples need to be rendered
		gen_samples = (uint)(samplerate*(double)tone.GetDuration());
		gen_sample = 0;
	}

	// Noise
	float Generator::noise(float r)
	{
		r = 1.0f-r;

		if(abs(nextchange) < 0.1f)
		{
			nextchange = 1.0f;
			noiseval = frand()*0.25f;
		}

		nextchange *= r;
		softnoise += noiseval;

		if(softnoise > 1.0f)
		{
			softnoise = 1.0f - frac(softnoise);
			noiseval = -abs(noiseval);
		}
		else if(softnoise < -1.0f)
		{
			softnoise = -1.0f + frac(softnoise);
			noiseval = abs(noiseval);
		}

		return softnoise;
	}

	float Generator::Amplitude()
	{
		return tone.GetVolume() *
			tone.GetShape(gen_sample/(float)gen_samples) *
			Min(1.0f, (gen_samples-gen_sample)/100.0f); // small fadeout
	}

	bool Generator::Generate(float *buffer, uint samples)
	{
		for(uint i = 0; i < samples; ++i)
		{
			*(buffer+i) = Signal(angle)*Amplitude();
			angle += angular_step;
			gen_sample++;
		}

		if(gen_sample >= gen_samples)
			return false;
		else
			return true;
	}

	float Generator::Signal(double angle)
	{
		switch(tone.GetWaveForm())
		{
		case waveSine:
			return (float)sin(angle);
		case waveTriangle:
			return triangle(angle);
		case waveSawtooth:
			return sawtooth(angle);
		case waveSquare:
			return square(angle);
		case waveNoise:
			return noise(tone.GetFreq()/5000.0f);
		case wavePluck:
			return ( square_flat(angle)*noise(gen_sample/(float)(gen_samples)) )
				*exp(-(gen_sample/(float)(gen_samples))*4.0f)*2.0f;
		}

		return 0.0f;	// flatlineeeee.....................
	}
}