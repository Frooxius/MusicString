#include "VisualMusicString.h"
#include "ConfigLib.h"
#include "ConfigVisual.h"

const char *ALPHASEQUENCE =
	"aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";

const char *NOTESEQUENCE[] = {
	"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B", 0 };

VisualMusicString::VisualMusicString(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	// set the header
	this->setWindowTitle(
	this->windowTitle().replace("VISUAL_VER",
		VISUAL_MSTR_VERSION).replace("LIB_VER",
		MUSSTR_LIB_VERSION));

	docManager = new DocumentManager(ui.tabDocuments, this);

	// generate supported samplerates
	QActionGroup *samplerateGroup = new QActionGroup(this);
	ui.menuSet_Samplerate->clear();
	QList<int> samplerates = QAudioDeviceInfo::defaultOutputDevice().supportedSampleRates();
	// select the default samplerate
	if(samplerates.contains(44100))
		sampleRate = 44100;
	else
		sampleRate = samplerates.first();
	for(int i = 0; i < samplerates.size(); ++i)
	{
		QSampleRateAction *newAction = new QSampleRateAction(
			samplerates[i],	ui.menuSet_Samplerate);
		newAction->setCheckable(true);
		if(samplerates[i] == sampleRate)
			newAction->setChecked(true);
		newAction->setActionGroup(samplerateGroup);
		connect(newAction, SIGNAL(selected(uint)), this, SLOT(SetSamplerate(uint)));
		ui.menuSet_Samplerate->addAction(newAction);
	}

	volumeLock = false;
	aboutVisualMusicString = new AboutVisualMusicString();
	exportAudio = new ExportAudio();
	connect(ui.actionExport_to_Audio, SIGNAL(triggered()), this, SLOT(GenExportAudio()));
	connect(this, SIGNAL(OpenExportAudio(QString, QString)), exportAudio, SLOT(Open(QString, QString)));

	// create signals
	connect(ui.butt_Play, SIGNAL(pressed()), this, SLOT(Play()));
	connect(ui.butt_Stop, SIGNAL(pressed()), this, SLOT(Stop()));

	// menu
	connect(ui.actionNew, SIGNAL(triggered()), docManager, SLOT(New()));
	connect(ui.actionClose, SIGNAL(triggered()), docManager, SLOT(Close()));
	connect(ui.actionSave, SIGNAL(triggered()), docManager, SLOT(Save()));
	connect(ui.actionSave_as, SIGNAL(triggered()), docManager, SLOT(SaveAs()));
	connect(ui.actionOpen, SIGNAL(triggered()), docManager, SLOT(Open()));

	connect(ui.actionDonate_pleaseee_3, SIGNAL(triggered()), this, SLOT(AboutDonate()));
	connect(ui.actionDocumentation_PDF, SIGNAL(triggered()), this, SLOT(AboutPDF()));
	connect(ui.actionOfficial_Website, SIGNAL(triggered()), this, SLOT(AboutHomepage()));
	connect(ui.actionAbout_Visual_MusicString, SIGNAL(triggered()), this, SLOT(ShowAboutVisualMusicString()));

	// tools
	connect(ui.spinTempo, SIGNAL(valueChanged(double)), this, SLOT(UpdateTempo()));
	connect(ui.spinVolumePercent, SIGNAL(valueChanged(int)), this, SLOT(UpdateVolumeSpin(int)));
	connect(ui.sliderVolume, SIGNAL(valueChanged(int)), this, SLOT(UpdateVolume(int)));
	connect(ui.textVolume, SIGNAL(textChanged()), this, SLOT(UpdateVolumeText()));
	ui.sliderVolume->setValue(10);

	connect(ui.butt_FreqSemiShiftHigher, SIGNAL(pressed()), this, SLOT(FreqSemiUp()));
	connect(ui.butt_FreqShiftHigher, SIGNAL(pressed()), this, SLOT(FreqUp()));
	connect(ui.butt_FreqSemiShiftLower, SIGNAL(pressed()), this, SLOT(FreqSemiDown()));
	connect(ui.butt_FreqShiftLower, SIGNAL(pressed()), this, SLOT(FreqDown()));

	ui.tableFrequencies->verticalHeader()->setResizeMode(
		QHeaderView::Fixed);
	ui.tableFrequencies->horizontalHeader()->setResizeMode(
		QHeaderView::Fixed);
	for(int i = 0; i < 52; ++i)
		ui.tableFrequencies->setHorizontalHeaderItem(i,
			new QTableWidgetItem(QString(ALPHASEQUENCE[i])));
	m_param = 0;
    UpdateFrequencies();

	UpdateTempo();

	player = 0;
	generator = 0;

	ui.butt_Stop->setEnabled(false);
	ui.butt_Pause->setEnabled(false);
}

VisualMusicString::~VisualMusicString()
{

}

void VisualMusicString::Play()
{
	if(docManager->GetCurrentSource().length() == 0)
		return;

	Stop();
	docManager->StartPlay();
	generator = new MStr2Audio(
        docManager->GetCurrentSource().toAscii().data(), sampleRate);
    player = new Player(generator, sampleRate, this);
	connect(player, SIGNAL(Stopped()), this, SLOT(Stop()));
	connect(player, SIGNAL(SyntaxError(MusicStringException)),
		this, SLOT(SyntaxError(MusicStringException)));
	player->Start();

	QTimer::singleShot(15, this, SLOT(UpdateTones()));

	ui.butt_Stop->setEnabled(true);
	ui.butt_Play->setEnabled(false);
}

void VisualMusicString::Stop()
{
	docManager->StopPlay();

	ui.progressVolume->setValue(0);

	if(!player)
		return;
	player->Stop();
	delete player;
	delete generator;
	player = 0;
	generator = 0;

	ui.butt_Stop->setEnabled(false);
	ui.butt_Play->setEnabled(true);
}

void VisualMusicString::UpdateTempo()
{
	double maxduration = 
		(1.0/(ui.spinTempo->value()/60.0))*16.0;

	for(int i = 0; i < 10; ++i)
	{
		ui.tableDurations->setItem(i, 2,
			new QTableWidgetItem(
			QString::fromStdString(
			AutoUnit(maxduration, "s")
			)));
		maxduration /= 2.0;
	}

	ui.tableDurations->resizeColumnsToContents();
	ui.tableDurations->setColumnWidth(0, 22);
}

void VisualMusicString::UpdateVolume(int vol)
{
	volumeLock = true;

	ui.spinVolumePercent->setValue( qRound((vol/51.0)*100) );
	ui.textVolume->setPlainText(QString("%") +
		(ALPHASEQUENCE[vol]));

	volumeLock = false;
}

void VisualMusicString::UpdateVolumeSpin(int val)
{
	if(volumeLock)
		return;
	volumeLock = true;

	int newval = qRound(( (val/100.0)*51.0 ));
	if(newval == ui.sliderVolume->value())
	{
		if( (val/100.0)*51.0 < ui.sliderVolume->value())
			newval--;
		else
			newval++;
	}
	
	ui.sliderVolume->setValue(newval);
}

void VisualMusicString::UpdateVolumeText()
{
	if(volumeLock)
		return;

	volumeLock = true;

	QString text = ui.textVolume->toPlainText();
	text = text.remove('%');
	text.truncate(1);	

	if(text.length() == 1)
	{
		for(int i = 0; i < 52; ++i)
			if(text[0] == 
				ALPHASEQUENCE[i])
			{
				if(ui.sliderVolume->value() == i)
					break;

				ui.sliderVolume->setValue(i);
				return;
			}
			ui.textVolume->setPlainText(text);
	}

	volumeLock = false;
}

void VisualMusicString::UpdateTones()
{
	if(!generator)
		return;

	ui.progressVolume->setValue(player->MaxAmp()*100);

	list<Tone> tones = generator->GetActiveTones();
	list<int> positions;
	QString source = docManager->GetCurrentSource(),
		front = "<span style=\"background-color:lime;\">",
		end = "</span>";

	// some quick and dirty escaping
	source.replace('<', 150);
	source.replace('>', 151);
	source.replace('&', 152);

	float mintime = FINF;
	int pos_off = 0;
	for(list<Tone>::iterator i = tones.begin();
		i != tones.end(); ++i)
	{
		mintime = Min(i->GetDuration(), mintime);
		positions.push_back(i->GetPos());
	}

	// sort them and then do marks
	positions.sort();
	positions.unique();
	for(list<int>::iterator i = positions.begin();
		i != positions.end(); ++i)
	{
		source.insert(*i + pos_off, front);
		pos_off += front.length();
		source.insert(*i + pos_off + 1, end);
		pos_off += end.length();
	}

	source.replace(150, "&lt;");
	source.replace(151, "&gt;");
	source.replace(152, "&amp;");
	source.replace('\n', "<br />");

	// set the new text
	docManager->SetCurrentHTML(source);

	// schedule next update
	//if(!isinf(mintime))
	QTimer::singleShot(15, this, SLOT(UpdateTones()));
}

void VisualMusicString::UpdateFrequencies()
{
	// contrain it between min and max
	m_param = Min(51, Max(-53, m_param));

	// set the textbox
	ui.textFreqShift->setPlainText( "&" + QString(((m_param&1) ?
		( (m_param>0)?"+":"-" ) : "") ) + 
		+ ALPHASEQUENCE[
			(m_param+53 + (m_param&1)*((m_param>0)?-1:1) )/2] );

	ui.labelFreqShift->setText("m = " + QString::number(m_param));

	int n, i;
	for(n = -26, i = 0; i < 52; n++, i++)
	{
		QTableWidgetItem *item = new QTableWidgetItem(
			NOTESEQUENCE[((n+m_param+81)%12)] +
			QString::number( ((n+m_param+81)/12) - 2 )
			);

		if(((n+m_param+81)%12) == 9)
			item->setBackgroundColor(QColor("yellow"));
		else if(((n+m_param+81)%12) == 0)
			item->setBackgroundColor(QColor("orange"));

		ui.tableFrequencies->setItem(0, i, item);
	}
	ui.tableFrequencies->resizeColumnsToContents();
}

void VisualMusicString::SyntaxError(MusicStringException err)
{
	QMessageBox::critical(this, "Syntax Error", 
		"Your MusicString code contains syntax error which prevents further execution\n" +
		QString(err.GetMsg()));
}
