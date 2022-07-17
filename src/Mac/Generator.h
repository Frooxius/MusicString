#include "Tone.h"
#include <cmath>
#include <cstdlib>

using namespace std;

namespace MusStr
{
	class Generator
	{
		float softnoise, nextchange, noiseval;
		float flat_rand() { return rand()/(float)RAND_MAX; }
		float frand() { return flat_rand()*2.0f - 1.0f; }
		float noise(float r);
		float frac(float n) { return abs(n-(int)n); }

		float sawtooth(double angle) { return (float)(-1.0f + 2.0f*((angle/PI_HALF)-(uint)(angle/PI_HALF))); }
		float triangle(double angle) { return (float)(asin(sin(angle))/PI_HALF); }
		float square(double angle) { return (float)((sin(angle)>0.0)?1.0f:-1.0f); }
		float square_flat(double angle) { return (float)((sin(angle)>0.0)?1.0f:0.0f); }

		double CalcAngularStep(float f);

	protected:
		Tone tone;
		uint samplerate;
		uint gen_samples;
		uint gen_sample;
		double angular_step,
			   angle,
			   angular_step_change,
			   vib_angle,
			   vib_angular_step;
		//virtual void GenData(float *buffer, uint samples);

		inline float Amplitude();
		inline float Signal(double angle);

	public:
		Generator(Tone tone, uint samplerate);

		// returns false if it's finished
		bool Generate(float *buffer, uint samples);
	};
}