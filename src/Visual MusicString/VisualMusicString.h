#ifndef VISUALMUSICSTRING_H
#define VISUALMUSICSTRING_H

#include <QtGui/QMainWindow>
#include <qtimer.h>
#include "ui_VisualMusicString.h"
#include <qtextedit.h>
#include <qdesktopservices.h>
#include <qurl.h>

#include "MStr2Audio.h"
#include "Utility.h"
#include "Player.h"
#include "DocumentManager.h"
#include "AboutVisualMusicString.h"
#include "ExportAudio.h"

using namespace MusStr;

class VisualMusicString : public QMainWindow
{
	Q_OBJECT

public:
	VisualMusicString(QWidget *parent = 0, Qt::WFlags flags = 0);
	~VisualMusicString();

private:
	Ui::VisualMusicStringClass ui;
	AboutVisualMusicString *aboutVisualMusicString;
	ExportAudio *exportAudio;

	// Audio generation
	Player *player;
	MStr2Audio *generator;
	uint sampleRate;

	// Document management
	DocumentManager *docManager;

	// Locking
	bool volumeLock;

	// Tools
	int m_param;

private slots:
	void Play();
	void Stop();

	// UI stuff
	void UpdateTempo();
	void UpdateTones();

	void UpdateVolume(int vol);
	void UpdateVolumeSpin(int val);
	void UpdateVolumeText();

	void UpdateFrequencies();

	void FreqSemiDown() { m_param--; UpdateFrequencies(); }
	void FreqDown() { m_param -= 2 ; UpdateFrequencies(); }
	void FreqSemiUp() { m_param++; UpdateFrequencies(); }
	void FreqUp() { m_param += 2 ; UpdateFrequencies(); }

	// Menu
	void AboutDonate() { QDesktopServices::openUrl(
		QUrl("http://musicstring.solirax.org/content/donate-pleeease-3")); }
	void AboutPDF() { QDesktopServices::openUrl(
		QUrl("http://data.solirax.org/musicstring/Documentation.pdf")); }
	void AboutHomepage() { QDesktopServices::openUrl(
		QUrl("http://musicstring.solirax.org")); }
	void ShowAboutVisualMusicString() { aboutVisualMusicString->show(); }

	void SyntaxError(MusicStringException err);

	void GenExportAudio() {
		emit OpenExportAudio(docManager->GetCurrentName(),
			docManager->GetCurrentSource()); }

signals:
	void OpenExportAudio(QString name, QString source);
};

#endif // VISUALMUSICSTRING_H