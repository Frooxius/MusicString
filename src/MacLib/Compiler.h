#include "MStr2Audio.h"

namespace MusStr
{
	enum Format { formatWAV, formatRAW };
	enum SampleFormat { sampleUINT8, sampleSINT8,
		sampleUINT16, sampleSINT16,
		sampleUINT32, sampleSINT32,
		sampleFLOAT };
	enum Normalize { normNone, normClipping, normPeak };

	class Compiler
	{
		enum Phase { phaseInit, 
			phaseParsing, phaseGenerating,
			phaseNormalizing, phaseSaving, phaseDone }
		currentPhase;

		MStr2Audio *mstr2audio;
		uint sampleRate, seconds, generated;
		Format header;
		SampleFormat samplef;
		Normalize norm;
		string filename;
		string source;
		float *buf;	// internal buffer
		float peak;

	public:
		Compiler(const string &source, const string &filename,
			uint sampleRate, uint seconds, float peak,
			Format header, SampleFormat samplef, Normalize norm);

		~Compiler();

		bool Compile(char **progress);
	};
}