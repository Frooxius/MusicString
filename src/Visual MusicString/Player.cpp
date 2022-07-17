#include "Player.h"

Player::Player(MusStr::MStr2Audio *mstr, uint samplerate,
	QObject *parent) : QObject(parent)
{
	audio = new AudioSource(mstr);
	connect(audio, SIGNAL(SyntaxError(MusicStringException)),
		this, SIGNAL(SyntaxError(MusicStringException)));

	QAudioFormat format;
	format.setSampleRate(samplerate);
	format.setChannels(1);
	format.setChannelCount(1);
	format.setSampleSize(16);
	format.setCodec("audio/pcm");
	format.setByteOrder(QAudioFormat::BigEndian);
	format.setSampleType(QAudioFormat::SignedInt);

	bool test = format.isValid();

	out = new QAudioOutput(format, this);
	connect(out, SIGNAL(stateChanged(QAudio::State)), this, SLOT(NewState(QAudio::State)));
}

void Player::Start()
{
	out->start(audio);
}

void Player::Stop()
{
	out->stop();
}

void Player::Pause()
{
	out->suspend();
}

void Player::Resume()
{
	out->resume();
}
