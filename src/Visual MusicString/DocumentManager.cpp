#include "DocumentManager.h"

DocumentManager::DocumentManager(QTabWidget *tabbar, QWidget *parent)
	: QObject(parent)
{
	this->tabbar = tabbar;
	tabbar->clear();
	playing = false;

	connect(tabbar, SIGNAL(tabCloseRequested(int)), this, SLOT(Close(int)));

	// create first document
	document_index = 0;
	New();
}

void DocumentManager::New()
{
	New("New " + QString::number(document_index++));
}

void DocumentManager::New(QString name, QString source, QString path)
{
	if(name == "")
		name = GetName(path);

	tabbar->setCurrentIndex(tabbar->addTab(MakeTextEdit(), name));

	SetCurrentSource(source);
	CurrentTextEdit()->path = path;

	connect(tabbar->currentWidget(), SIGNAL(textChanged()),
		this, SLOT(CurrentModified()));
}

QString DocumentManager::GetName(QString path)
{
	return path.remove(0, 1+path.lastIndexOf(QRegExp("[/\\\\]")));
}

QTextEditPath *DocumentManager::MakeTextEdit()
{
	QTextEditPath *edit = new QTextEditPath(tabbar);
	edit->setAcceptRichText(false);
	edit->setFontFamily("Lucida Console");
	edit->setFont(QFont("Lucida Console", 10));
	edit->setUndoRedoEnabled(true);

	return edit;
}

QString DocumentManager::GetCurrentSource()
{
	return CurrentTextEdit()->toPlainText();
}

void DocumentManager::SetCurrentHTML(QString &text)
{
	CurrentTextEdit()->setHtml(text);
}

void DocumentManager::SetCurrentSource(QString &text)
{
	CurrentTextEdit()->setPlainText(text);
}

void DocumentManager::StartPlay()
{
	playing = true;
	tabbar->setEnabled(false);
}

void DocumentManager::StopPlay()
{
	playing = true;
	CurrentTextEdit()->setPlainText(GetCurrentSource());
	tabbar->setEnabled(true);
	playing = false;
}

void DocumentManager::Close(int index)
{
	if(tabbar->tabText(index)[0] == '*')
	{
		QMessageBox::StandardButton result = 
			QMessageBox::question((QWidget*)(this->parent()),
			"Save file?", "Warning! You're about to close file "
			+ tabbar->tabText(index) + " which has some unsaved changes. Do you wish to "
			+ "save them now?", QMessageBox::Save |
			QMessageBox::Discard | QMessageBox::Cancel,
			QMessageBox::Save);

		switch(result)
		{
		case QMessageBox::Save:
			Save(); break;
		case QMessageBox::Discard:
			break;
		default:
			return;	// cancel closing
		}
	}

	tabbar->removeTab(index);

	// there must be always at least one tab
	if(tabbar->count() == 0)
		New();
}

void DocumentManager::CurrentModified()
{
	if(playing)
		return;

	int index = tabbar->currentIndex();

	if(tabbar->tabText(index)[0] != '*')
		tabbar->setTabText(index,
			'*' + tabbar->tabText(index));	
}

void DocumentManager::SaveAs()
{
	QString fname = QFileDialog::getSaveFileName((QWidget*)(this->parent()),
		"Save MusicString sourcecode", "",
		"MusicString sources (*.mstr *.musicstring *.musstr *.txt)");

	if(!fname.isNull())
	{
		CurrentTextEdit()->path = fname;
		Save();
	}
}

void DocumentManager::Save()
{
	if(CurrentTextEdit()->path == "")
	{
		SaveAs();
		return;
	}

	QString fname = CurrentTextEdit()->path;

	QFile out(fname);
	if(!out.open( QIODevice::WriteOnly | QIODevice::Text ))
		return;	// maybe some error later?

	out.write(GetCurrentSource().toAscii());
	out.close();

	// set the tab name to the filename
	tabbar->setTabText(tabbar->currentIndex(), GetName(fname));
}

void DocumentManager::Open()
{
	QString fname = QFileDialog::getOpenFileName((QWidget*)(this->parent()),
		"Open MusicString sourcecode", "",
		"MusicString sources (*.mstr *.musicstring *.musstr *.txt)");

	if(!fname.isNull())
	{
		QFile in(fname);
		if(!in.open(QIODevice::ReadOnly | QIODevice::Text))
			return;	// some error later

		New("", in.readAll(), fname);

		in.close();
	}
}