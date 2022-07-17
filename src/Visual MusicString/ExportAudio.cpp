#include "ExportAudio.h"
#include "Utility.h"
#include <qmessagebox.h>

ExportAudio::ExportAudio(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	compiler = 0;

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

	connect(ui.buttExport, SIGNAL(clicked()), this, SLOT(RunExport()));

	UpdateSettings();
}

ExportAudio::~ExportAudio()
{

}

void ExportAudio::RunExport()
{
	// first time it's called, create compiler
	if(!compiler)
	{
		// a bit dirty, but works for now :P 
		if(ui.buttExport->text() != "Export")
			return;

		ui.groupFormat->setEnabled(false);
		ui.groupNormalize->setEnabled(false);
		ui.groupSample->setEnabled(false);

        compiler = new Compiler(source.toStdString(), string("gen.temp"),
            (uint)samplerate, (uint)seconds, (float)peak, (Format)header,
                                (SampleFormat)sample, (Normalize)norm);
	}

	// run a compile step and schedule next phase if needed
	char *msg = "Oops! Error...";
	try
	{
		if(compiler->Compile(&msg))
			QTimer::singleShot(10, this, SLOT(RunExport()));
		else
		{
			// otherwise free memory and prompt where to save file
			delete compiler;
			compiler = 0;

			QString fname = QFileDialog::getSaveFileName(this, 
				"Save exported file", name, 
				(header == formatWAV)?"WAVE Audio File (*.wav *.wave)":
				"RAW Audio File (*.raw *.bin *.dat)");

			if(!fname.isNull())
				QFile::copy("gen.temp", fname);

			QFile::remove("gen.temp");
		}
	}
	catch(MusicStringException err)
	{
		QMessageBox::critical(this, "Syntax Error", 
		"Your MusicString code contains syntax error which prevents further execution\n" +
		QString(err.GetMsg()));

		delete compiler;
		compiler = 0;
	}
	catch(bad_alloc xa)
	{
		QMessageBox::critical(this, "Memory Allocation Error", 
		QString("Cannot allocate memory to store generated audio data. Try lowering quality/length settings or wait") +
		" for the next version which will include memory usage limitation.");

		delete compiler;
		compiler = 0;
	}

	ui.buttExport->setText(QString(msg));
	ui.buttExport->update();
}

void ExportAudio::Open(QString name, QString source)
{
	QString newinfolabel(infolabel);
	this->show();
	ui.labelIntro->setText(
		newinfolabel.replace("SOURCENAME", name));

	// save the source and name
	this->source = source;
	name.replace("*","").remove(name.lastIndexOf('.'), 0xFFFF);
	this->name = name;

	ui.groupFormat->setEnabled(true);
	ui.groupNormalize->setEnabled(true);
	ui.groupSample->setEnabled(true);
	ui.buttExport->setText("Export");
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
	ui.radioSInt8->setEnabled(header == formatRAW);
	ui.radioUInt16->setEnabled(header == formatRAW);
	ui.radioUInt32->setEnabled(header == formatRAW);

	if(header == formatWAV && 
		(sample == sampleFLOAT ||
		sample == sampleUINT16 ||
		sample == sampleSINT8  ||
		sample == sampleUINT32)  )
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
