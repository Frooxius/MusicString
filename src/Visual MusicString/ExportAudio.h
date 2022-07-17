#ifndef EXPORTAUDIO_H
#define EXPORTAUDIO_H

#include <QWidget>
#include "ui_ExportAudio.h"

class ExportAudio : public QWidget
{
	Q_OBJECT

	QString infolabel,
		source;

	enum Format { formatWAV, formatRAW };
	enum SampleFormat { sampleUINT8, sampleSINT8,
		sampleUINT16, sampleSINT16,
		sampleUINT32, sampleSINT32,
		sampleFLOAT };
	enum Normalize { normNone, normClipping, normPeak };

public:
	ExportAudio(QWidget *parent = 0);
	~ExportAudio();

private:
	Ui::ExportAudio ui;

	Format header; 
	SampleFormat sample;
	uint samplerate;
	uint seconds;
	Normalize norm;
	float peak;

public slots:
	void Open(QString name, QString source);

private slots:
	void UpdateSettings();
};

#endif // EXPORTAUDIO_H
