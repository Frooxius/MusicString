#pragma once
#include <qaudiooutput.h>
#include <qiodevice.h>
#include "MStr2Audio.h"

using namespace MusStr;

class AudioSource : public QIODevice
{
	Q_OBJECT

	MStr2Audio *mstr;
	bool done;
	ull generated_samples;

	float max_amp;

public:
	AudioSource(MStr2Audio *mstr)
	{
		this->mstr = mstr;
		done = false;
		generated_samples = 0;
		max_amp = 0.0f;
		open(QIODevice::ReadOnly);
	}

	bool Done() { return done; }

	float MaxAmp() { return max_amp; }

	qint64 readData(char *data, qint64 len)
	{
		float *buf = new float[len/sizeof(float)];

		qint64 gen = 0;
		// catch any errors
		try
		{
			gen = mstr->Generate(buf, len/sizeof(float), true);
		}
		catch(MusicStringException err)
		{
			this->close();
			emit SyntaxError(err);
		}

		max_amp = 0.0f;
		for(int i = 0; i < gen; ++i)
		{
			short sample = (short) ((*(buf+i))*0x7FFF);
			max_amp = Max(abs(sample)/(float)0x7FFF, max_amp);
			*((short*)(data+i*2)) = sample;
		}
		delete buf;
		
		generated_samples += gen;
		return gen*sizeof(short);
	}

	qint64 writeData(const char *data, qint64 len)
	{ Q_UNUSED(data); Q_UNUSED(len); return 0; }

signals:
	void SyntaxError(MusicStringException err);
};

class Player : public QObject
{
	Q_OBJECT

	AudioSource *audio;
	QAudioOutput *out;

public:
	Player(MusStr::MStr2Audio *mstr, uint samplerate, QObject *parent);

	void Start();
	void Stop();
	void Pause();
	void Resume();

	float MaxAmp() { return audio->MaxAmp(); }

signals:
	void Stopped();
	void SyntaxError(MusicStringException err);

private slots:
	void NewState(QAudio::State s)
	{
		if(s == QAudio::State::IdleState)
			emit Stopped();
	}
};