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

	public:
		MStr2Audio(string musstr, uint samplerate = 44100);

		// will generate audio and return how many samples were generated
		uint Generate(float *buf, uint samples);
	};
}