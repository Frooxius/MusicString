#ifndef EXPORTAUDIO_H
#define EXPORTAUDIO_H

#include <QWidget>
#include "ui_ExportAudio.h"
#include "Compiler.h"
#include <qtimer.h>
#include <qfiledialog.h>
#include <qfile.h>

using namespace MusStr;

class ExportAudio : public QWidget
{
	Q_OBJECT

	QString infolabel,
		source, name;

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

	Compiler *compiler;

public slots:
	void Open(QString name, QString source);

private slots:
	void UpdateSettings();
	void RunExport();
};

#endif // EXPORTAUDIO_H
