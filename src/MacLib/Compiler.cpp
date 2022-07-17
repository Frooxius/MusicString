#include "Compiler.h"
#include <fstream>

using namespace std;

namespace MusStr
{
	struct wavfile
	{
		char    id[4];          // should always contain "RIFF"
		int     totallength;    // total file length minus 8
		char    wavefmt[8];     // should be "WAVEfmt "
		int     format;         // 16 for PCM format
		short   pcm;            // 1 for PCM format
		short   channels;       // channels
		int     frequency;      // sampling frequency
		int     bytes_per_second;
		short   bytes_by_capture;
		short   bits_per_sample;
		char    data[4];        // should always contain "data"
		int     bytes_in_data;
	};

	Compiler::~Compiler()
	{
		// deallocate memory
		if(buf)
			delete buf;
		if(mstr2audio)
			delete mstr2audio;
	}

	Compiler::Compiler(const string &source,const string &filename,
		uint sampleRate, uint seconds, float peak,
			Format header, SampleFormat samplef, Normalize norm)
	{
		mstr2audio = 0;
		buf = 0;

		this->sampleRate =  sampleRate;
		this->seconds = Max(1U, seconds);
		this->header = header;
		this->samplef = samplef;
		this->norm = norm;
		this->filename = filename;
		this->source = source;
		this->currentPhase = phaseInit;
		this->generated = 0;
		if(norm == normPeak)
			this->peak = peak;
		else
			this->peak = 0.95f;
	}

	bool Compiler::Compile(char **progress)
	{
		switch(currentPhase)
		{
		case phaseInit:
			// next phase
			currentPhase = phaseParsing;
			*progress = "Parsing...";
			return true;

		case phaseParsing:
			mstr2audio = new MStr2Audio(source, sampleRate);

			// next phase
			currentPhase = phaseGenerating;
			*progress = "Generating...";
			return true;

		case phaseGenerating:
			// allocate buffer
			buf = new float[sampleRate*seconds];
			generated = 
				mstr2audio->Generate(buf, sampleRate*seconds, false);

			// next phase
			if(norm == normNone)
			{
				currentPhase = phaseSaving;
				*progress = "Saving...";
			}
			else
			{
				currentPhase = phaseNormalizing;
				*progress = "Normalizing...";
			}
			return true;

		case phaseNormalizing:
		{
			float max_amp = -FINF;
			for(int i = 0; i < generated; ++i)
				max_amp = Max(abs(*(buf+i)), max_amp);

			// normalize the amplitude using the selected method
			if((norm == normClipping && max_amp > 0.95f) ||
				(norm == normPeak))
			{
				max_amp = peak / max_amp;
				for(int i = 0; i < generated; ++i)
					*(buf+i) *= max_amp;
			}

			currentPhase = phaseSaving;
			*progress = "Saving...";
			return true;
		}

		case phaseSaving:
		{			
			bool isSigned;
			uint sizeB;

			isSigned = (
				samplef == sampleSINT8 ||
				samplef == sampleSINT16 ||
				samplef == sampleSINT32);

			if(samplef == sampleSINT8 || samplef == sampleUINT8)
				sizeB = 1;
			else if(samplef == sampleSINT16 || samplef == sampleUINT16)
				sizeB = 2;
			else
				sizeB = 4;

			wavfile head;
			head.bits_per_sample = sizeB*8;
			head.bytes_by_capture = sizeB;
			head.bytes_in_data = generated*sizeB;
			head.bytes_per_second = sampleRate*sizeB;
			head.channels = 1;
			head.data[0] = 'd';
			head.data[1] = 'a';
			head.data[2] = 't';
			head.data[3] = 'a';
			head.format = 16;
			head.frequency = sampleRate;
			head.id[0] = 'R';
			head.id[1] = 'I';
			head.id[2] = 'F';
			head.id[3] = 'F';
			head.pcm = 1;
			head.totallength = sampleRate*sizeB+sizeof(head)-8;
			for(int i = 0; i < 8; ++i)
				head.wavefmt[i] = "WAVEfmt "[i];

			fstream file(filename.c_str(), std::ios::out | std::ios::binary);

			if(header == formatWAV)
				file.write((char *)&head, sizeof(head));

			// write PCM data
			for(int i = 0; i < generated; ++i)
			{
				union { byte i8; ushort i16; uint i32; float f32; }
					sample;

				switch(samplef)
				{
				case sampleUINT8:
					sample.i8 = ( ((*(buf+i))/2.0f+0.5f) * 0xFFU); break;
				case sampleUINT16:
					sample.i16 = ( ((*(buf+i))/2.0f+0.5f) * 0xFFFFU); break;
				case sampleUINT32:
					sample.i32 = ( ((*(buf+i))/2.0f+0.5f) * 0xFFFFFFFFU); break;

				case sampleSINT8:
					sample.i8 =  ( (*(buf+i)) * (0xFFU>>1)); break;
				case sampleSINT16:
					sample.i16 = ( (*(buf+i)) * (0xFFFFU>>1)); break;
				case sampleSINT32:
					sample.i32 = ( (*(buf+i)) * (0xFFFFFFFFU>>1)); break;

				case sampleFLOAT:
					sample.f32 = (*(buf+i));
				}
				file.write((char *)&sample, sizeB);
			}

			currentPhase = phaseDone;
			// if you remove the evil cat smiley I'm gonna kill you
			*progress = "Done! Happy listening! >:3";
			return true;
		}
		case phaseDone:
			*progress = "Done! Happy listening! >:3";
			return false;
		}
	}
}