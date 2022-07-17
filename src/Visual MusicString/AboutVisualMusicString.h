#ifndef ABOUTVISUALMUSICSTRING_H
#define ABOUTVISUALMUSICSTRING_H

#include <QWidget>
#include "ui_AboutVisualMusicString.h"

class AboutVisualMusicString : public QWidget
{
	Q_OBJECT

public:
	AboutVisualMusicString(QWidget *parent = 0);
	~AboutVisualMusicString();

private:
	Ui::AboutVisualMusicString ui;
};

#endif // ABOUTVISUALMUSICSTRING_H
