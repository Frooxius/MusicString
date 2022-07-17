/********************************************************************************
** Form generated from reading UI file 'AboutVisualMusicString.ui'
**
** Created: Tue 28. Feb 01:03:29 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTVISUALMUSICSTRING_H
#define UI_ABOUTVISUALMUSICSTRING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutVisualMusicString
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *AboutVisualMusicString)
    {
        if (AboutVisualMusicString->objectName().isEmpty())
            AboutVisualMusicString->setObjectName(QString::fromUtf8("AboutVisualMusicString"));
        AboutVisualMusicString->setWindowModality(Qt::WindowModal);
        AboutVisualMusicString->resize(480, 480);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AboutVisualMusicString->sizePolicy().hasHeightForWidth());
        AboutVisualMusicString->setSizePolicy(sizePolicy);
        AboutVisualMusicString->setMinimumSize(QSize(480, 480));
        AboutVisualMusicString->setMaximumSize(QSize(480, 480));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/VisualMusicString/logo64x64.png"), QSize(), QIcon::Normal, QIcon::Off);
        AboutVisualMusicString->setWindowIcon(icon);
        label = new QLabel(AboutVisualMusicString);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(15, 10, 446, 196));
        label->setPixmap(QPixmap(QString::fromUtf8(":/VisualMusicString/logotext800px.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(AboutVisualMusicString);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 215, 461, 251));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setTextFormat(Qt::RichText);
        label_2->setScaledContents(false);
        label_2->setWordWrap(true);

        retranslateUi(AboutVisualMusicString);

        QMetaObject::connectSlotsByName(AboutVisualMusicString);
    } // setupUi

    void retranslateUi(QWidget *AboutVisualMusicString)
    {
        AboutVisualMusicString->setWindowTitle(QApplication::translate("AboutVisualMusicString", "About Visual MusicString", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_2->setText(QApplication::translate("AboutVisualMusicString", "<html><head/><body><p><span style=\" font-weight:600;\">About Visual MusicString<br/></span>Visual MusicString is an IDE for the MusicString music programming language, designed to simplyfy creation, testing, playing and exporting of tunes created in this language. Visual MusicString is developed in conjuction with MusicString, GUI is created using Qt SDK by Nokia.</p><p><span style=\" font-weight:600;\">Author<br/></span>Tom\303\241\305\241 &quot;Frooxius&quot; Marian\304\215\303\255k, Developed under <a href=\"http://solirax.org\"><span style=\" text-decoration: underline; color:#0000ff;\">Solirax<br/></span></a>Personal website: <a href=\"http://frooxius.solirax.org\"><span style=\" text-decoration: underline; color:#0000ff;\">http://frooxius.solirax.org<br/></span></a>Email/GTalk: <a href=\"mailto:Tomas.Mariancik@gmail.com\"><span style=\" text-decoration: underline; color:#0000ff;\">Tomas.Mariancik@gmail.com<br/></span></a>Skype: frooxius<br/>WLM/MSN: Tomas.Mariancik@hotmail.com</p><p><span style=\" font-"
                        "weight:600;\">Version<br/></span>Visual MusicString - version 0.1 alpha preview<br/>MusicString compiler&amp;synthesis library - version 0.2.2 alpha</p><p><span style=\" font-weight:600;\">License<br/></span>Visual MusicString is distributed free to use, however if you wish to show your appreciation for the work done on this project in a form of donation, it will be highly appreciated.</p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AboutVisualMusicString: public Ui_AboutVisualMusicString {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTVISUALMUSICSTRING_H
