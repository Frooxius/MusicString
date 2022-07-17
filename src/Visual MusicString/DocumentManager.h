#pragma once

#include <qtabbar.h>
#include <qtabwidget.h>
#include <qtextedit.h>
#include <vector>
#include <qfiledialog.h>
#include <qmessagebox.h>

using namespace std;

class QTextEditPath : public QTextEdit
{
	Q_OBJECT

public:
	QTextEditPath(QWidget *parent) : QTextEdit(parent)
		{ this->path = ""; }
	QString path;
};

class DocumentManager : public QObject
{
	Q_OBJECT

	bool playing;

	QTabWidget *tabbar;
	uint document_index;

	QString GetName(QString path);

	QTextEditPath *MakeTextEdit();
	QTextEditPath *CurrentTextEdit() 
		{ return ((QTextEditPath*)tabbar->currentWidget()); }

public:
	DocumentManager(QTabWidget *tabbar, QWidget *parent);

	void StartPlay();
	void StopPlay();

	QString GetCurrentSource();
	QString GetCurrentName() { return tabbar->tabText(tabbar->currentIndex()); }
	void SetCurrentSource(QString &text);
	void SetCurrentHTML(QString &text);

public slots:
	void New();
	void New(QString name, QString source = "", QString path = "");
	void Save();
	void SaveAs();
	void Open();
	void Close() { Close(tabbar->currentIndex()); }
	void Close(int index);
	void CurrentModified();
};