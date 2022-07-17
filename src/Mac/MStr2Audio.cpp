#include "MStr2Audio.h"

namespace MusStr
{
	MStr2Audio::MStr2Audio(string musstr, uint samplerate)
	{
		mstr = new MusicString(musstr);
		agen = new AudioGen(samplerate);
	}

	uint MStr2Audio::Generate(float *buf, uint samples)
	{
		// keep on generating, until the MusicString is done (if even...)
		bool finalize = false;
		uint generated = 0;

		while((samples-generated) && !finalize)
		{
			// generate music list until it's enough for the generatator
			while(!(finalize = mstr->Done())
				&& !agen->Append(mstr->GenMusicList(50), true));

			generated +=
				agen->Generate(buf+generated, samples-generated, finalize);			
		}

		return generated;
	}
}