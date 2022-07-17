#include "AboutVisualMusicString.h"
#include "ConfigLib.h"
#include "ConfigVisual.h"

AboutVisualMusicString::AboutVisualMusicString(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.labelText->setText(ui.labelText->text().replace("VISUAL_VER",
		QString(VISUAL_MSTR_VERSION) + " (built on " + 
		VISUAL_MSTR_TIME + " " + VISUAL_MSTR_DATE + ")").replace("LIB_VER",
		QString(MUSSTR_LIB_VERSION) + " (built on " + 
		MUSSTR_LIB_TIME + " " + MUSSTR_LIB_DATE + ")"));
}

AboutVisualMusicString::~AboutVisualMusicString()
{
	
}
