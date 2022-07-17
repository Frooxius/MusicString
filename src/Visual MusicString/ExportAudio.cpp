#include "ExportAudio.h"
#include "Utility.h"

ExportAudio::ExportAudio(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	infolabel = ui.labelIntro->text();
	
	connect(ui.radioFloat, SIGNAL(clicked()), this, SLOT(UpdateSettings()));
	connect(ui.radioSInt16, SIGNAL(clicked()), this, SLOT(UpdateSettings()));
	connect(ui.radioUInt16, SIGNAL(clicked()), this, SLOT(UpdateSettings()));
	connect(ui.radioSInt8, SIGNAL(clicked()), this, SLOT(UpdateSettings()));
	connect(ui.radioUInt8, SIGNAL(clicked()), this, SLOT(UpdateSettings()));
	connect(ui.radioSInt32, SIGNAL(clicked()), this, SLOT(UpdateSettings()));
	connect(ui.radioUInt32, SIGNAL(clicked()), this, SLOT(UpdateSettings()));
	connect(ui.radioRAW, SIGNAL(clicked()), this, SLOT(UpdateSettings()));
	connect(ui.radioWAV, SIGNAL(clicked()), this, SLOT(UpdateSettings()));
	connect(ui.radioNoNormalize, SIGNAL(clicked()), this, SLOT(UpdateSettings()));
	connect(ui.radioNormalizeClipping, SIGNAL(clicked()), this, SLOT(UpdateSettings()));
	connect(ui.radioNormalizePeak, SIGNAL(clicked()), this, SLOT(UpdateSettings()));
	connect(ui.spinPeak, SIGNAL(valueChanged(int)), this, SLOT(UpdateSettings()));
	connect(ui.spinTime, SIGNAL(timeChanged(QTime)), this, SLOT(UpdateSettings()));
	connect(ui.spinSampleRate, SIGNAL(valueChanged(int)), this, SLOT(UpdateSettings()));

	UpdateSettings();
}

ExportAudio::~ExportAudio()
{

}

void ExportAudio::Open(QString name, QString source)
{
	QString newinfolabel(infolabel);
	this->show();
	ui.labelIntro->setText(
		newinfolabel.replace("SOURCENAME", name));

	// save the source
	this->source = source;
}

void ExportAudio::UpdateSettings()
{
	if(ui.radioWAV->isChecked())
		header = formatWAV;
	else
		header = formatRAW;

	if(ui.radioSInt8->isChecked())
		sample = sampleSINT8;
	else if(ui.radioUInt8->isChecked())
		sample = sampleUINT8;
	else if(ui.radioSInt16->isChecked())
		sample = sampleSINT16;
	else if(ui.radioUInt16->isChecked())
		sample = sampleUINT16;
	else if(ui.radioSInt32->isChecked())
		sample = sampleSINT32;
	else if(ui.radioUInt32->isChecked())
		sample = sampleUINT32;
	else if(ui.radioFloat->isChecked())
		sample = sampleFLOAT;

	ui.radioFloat->setEnabled(header == formatRAW);

	if(header == formatWAV && sample == sampleFLOAT)
	{
		// this will cause this slot to be called again
		ui.radioSInt16->setChecked(true);
		return;
	}

	samplerate = ui.spinSampleRate->value();
	seconds = ui.spinTime->time().second() + 
		ui.spinTime->time().minute()*60 +
		ui.spinTime->time().hour()*3600;

	peak = ui.spinPeak->value()/100.0f;

	if(ui.radioNoNormalize->isChecked())
		norm = normNone;
	else if(ui.radioNormalizeClipping->isChecked())
		norm = normClipping;
	else if(ui.radioNormalizePeak->isChecked())
		norm = normPeak;

	ui.radioNoNormalize->setEnabled(header == formatRAW);

	if(header == formatWAV && norm == normNone)
	{
		ui.radioNormalizeClipping->setChecked(true);
		return;
	}

	ui.labelMemory->setText("Required memory: "
		+ QString::fromStdString( AutoUnit(
		(samplerate*(float)seconds*(float)sizeof(float)), "B")));
}
