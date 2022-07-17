/********************************************************************************
** Form generated from reading UI file 'ExportAudio.ui'
**
** Created: Tue 28. Feb 04:56:04 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTAUDIO_H
#define UI_EXPORTAUDIO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTimeEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExportAudio
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupFormat;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioWAV;
    QRadioButton *radioRAW;
    QGroupBox *groupSample;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioSInt8;
    QRadioButton *radioUInt8;
    QRadioButton *radioSInt16;
    QRadioButton *radioUInt16;
    QRadioButton *radioSInt32;
    QRadioButton *radioUInt32;
    QRadioButton *radioFloat;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinSampleRate;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QTimeEdit *spinTime;
    QLabel *labelMemory;
    QGroupBox *groupNormalize;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioNoNormalize;
    QRadioButton *radioNormalizeClipping;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioNormalizePeak;
    QSpinBox *spinPeak;
    QPushButton *pushButton;
    QLabel *labelIntro;

    void setupUi(QWidget *ExportAudio)
    {
        if (ExportAudio->objectName().isEmpty())
            ExportAudio->setObjectName(QString::fromUtf8("ExportAudio"));
        ExportAudio->resize(323, 331);
        layoutWidget = new QWidget(ExportAudio);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 60, 118, 256));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        groupFormat = new QGroupBox(layoutWidget);
        groupFormat->setObjectName(QString::fromUtf8("groupFormat"));
        verticalLayout_3 = new QVBoxLayout(groupFormat);
        verticalLayout_3->setSpacing(4);
        verticalLayout_3->setContentsMargins(6, 6, 6, 6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        radioWAV = new QRadioButton(groupFormat);
        radioWAV->setObjectName(QString::fromUtf8("radioWAV"));
        radioWAV->setChecked(true);

        verticalLayout_3->addWidget(radioWAV);

        radioRAW = new QRadioButton(groupFormat);
        radioRAW->setObjectName(QString::fromUtf8("radioRAW"));
        radioRAW->setChecked(false);

        verticalLayout_3->addWidget(radioRAW);


        verticalLayout_4->addWidget(groupFormat);

        groupSample = new QGroupBox(layoutWidget);
        groupSample->setObjectName(QString::fromUtf8("groupSample"));
        verticalLayout_2 = new QVBoxLayout(groupSample);
        verticalLayout_2->setSpacing(4);
        verticalLayout_2->setContentsMargins(6, 6, 6, 6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        radioSInt8 = new QRadioButton(groupSample);
        radioSInt8->setObjectName(QString::fromUtf8("radioSInt8"));

        verticalLayout_2->addWidget(radioSInt8);

        radioUInt8 = new QRadioButton(groupSample);
        radioUInt8->setObjectName(QString::fromUtf8("radioUInt8"));

        verticalLayout_2->addWidget(radioUInt8);

        radioSInt16 = new QRadioButton(groupSample);
        radioSInt16->setObjectName(QString::fromUtf8("radioSInt16"));
        radioSInt16->setChecked(true);

        verticalLayout_2->addWidget(radioSInt16);

        radioUInt16 = new QRadioButton(groupSample);
        radioUInt16->setObjectName(QString::fromUtf8("radioUInt16"));
        radioUInt16->setChecked(false);

        verticalLayout_2->addWidget(radioUInt16);

        radioSInt32 = new QRadioButton(groupSample);
        radioSInt32->setObjectName(QString::fromUtf8("radioSInt32"));

        verticalLayout_2->addWidget(radioSInt32);

        radioUInt32 = new QRadioButton(groupSample);
        radioUInt32->setObjectName(QString::fromUtf8("radioUInt32"));

        verticalLayout_2->addWidget(radioUInt32);

        radioFloat = new QRadioButton(groupSample);
        radioFloat->setObjectName(QString::fromUtf8("radioFloat"));

        verticalLayout_2->addWidget(radioFloat);


        verticalLayout_4->addWidget(groupSample);

        verticalLayout_4->setStretch(1, 1);
        layoutWidget1 = new QWidget(ExportAudio);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(140, 60, 171, 172));
        verticalLayout_5 = new QVBoxLayout(layoutWidget1);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        spinSampleRate = new QSpinBox(layoutWidget1);
        spinSampleRate->setObjectName(QString::fromUtf8("spinSampleRate"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinSampleRate->sizePolicy().hasHeightForWidth());
        spinSampleRate->setSizePolicy(sizePolicy);
        spinSampleRate->setMinimum(1);
        spinSampleRate->setMaximum(6144000);
        spinSampleRate->setSingleStep(1000);
        spinSampleRate->setValue(48000);

        horizontalLayout->addWidget(spinSampleRate);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spinTime = new QTimeEdit(layoutWidget1);
        spinTime->setObjectName(QString::fromUtf8("spinTime"));
        spinTime->setAccelerated(true);
        spinTime->setTime(QTime(0, 30, 0));
        spinTime->setMaximumTime(QTime(23, 59, 59));
        spinTime->setCurrentSection(QDateTimeEdit::MinuteSection);

        horizontalLayout_2->addWidget(spinTime);


        verticalLayout_5->addLayout(horizontalLayout_2);

        labelMemory = new QLabel(layoutWidget1);
        labelMemory->setObjectName(QString::fromUtf8("labelMemory"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        labelMemory->setFont(font);

        verticalLayout_5->addWidget(labelMemory);

        groupNormalize = new QGroupBox(layoutWidget1);
        groupNormalize->setObjectName(QString::fromUtf8("groupNormalize"));
        verticalLayout = new QVBoxLayout(groupNormalize);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radioNoNormalize = new QRadioButton(groupNormalize);
        radioNoNormalize->setObjectName(QString::fromUtf8("radioNoNormalize"));

        verticalLayout->addWidget(radioNoNormalize);

        radioNormalizeClipping = new QRadioButton(groupNormalize);
        radioNormalizeClipping->setObjectName(QString::fromUtf8("radioNormalizeClipping"));
        radioNormalizeClipping->setChecked(true);

        verticalLayout->addWidget(radioNormalizeClipping);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        radioNormalizePeak = new QRadioButton(groupNormalize);
        radioNormalizePeak->setObjectName(QString::fromUtf8("radioNormalizePeak"));

        horizontalLayout_3->addWidget(radioNormalizePeak);

        spinPeak = new QSpinBox(groupNormalize);
        spinPeak->setObjectName(QString::fromUtf8("spinPeak"));
        spinPeak->setMinimum(1);
        spinPeak->setMaximum(100);
        spinPeak->setValue(95);

        horizontalLayout_3->addWidget(spinPeak);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_5->addWidget(groupNormalize);

        pushButton = new QPushButton(ExportAudio);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 285, 171, 31));
        pushButton->setFont(font);
        labelIntro = new QLabel(ExportAudio);
        labelIntro->setObjectName(QString::fromUtf8("labelIntro"));
        labelIntro->setGeometry(QRect(15, 5, 296, 56));
        labelIntro->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        labelIntro->setWordWrap(true);

        retranslateUi(ExportAudio);

        QMetaObject::connectSlotsByName(ExportAudio);
    } // setupUi

    void retranslateUi(QWidget *ExportAudio)
    {
        ExportAudio->setWindowTitle(QApplication::translate("ExportAudio", "ExportAudio", 0, QApplication::UnicodeUTF8));
        groupFormat->setTitle(QApplication::translate("ExportAudio", "Select Format", 0, QApplication::UnicodeUTF8));
        radioWAV->setText(QApplication::translate("ExportAudio", "WAV (PCM)", 0, QApplication::UnicodeUTF8));
        radioRAW->setText(QApplication::translate("ExportAudio", "RAW (PCM)", 0, QApplication::UnicodeUTF8));
        groupSample->setTitle(QApplication::translate("ExportAudio", "Sample Datatype", 0, QApplication::UnicodeUTF8));
        radioSInt8->setText(QApplication::translate("ExportAudio", "Signed Int8", 0, QApplication::UnicodeUTF8));
        radioUInt8->setText(QApplication::translate("ExportAudio", "Unsigned Int8", 0, QApplication::UnicodeUTF8));
        radioSInt16->setText(QApplication::translate("ExportAudio", "Signed Int16", 0, QApplication::UnicodeUTF8));
        radioUInt16->setText(QApplication::translate("ExportAudio", "Unsigned Int16", 0, QApplication::UnicodeUTF8));
        radioSInt32->setText(QApplication::translate("ExportAudio", "Signed Int32", 0, QApplication::UnicodeUTF8));
        radioUInt32->setText(QApplication::translate("ExportAudio", "Unsigned Int32", 0, QApplication::UnicodeUTF8));
        radioFloat->setText(QApplication::translate("ExportAudio", "Float32", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ExportAudio", "Samplerate:", 0, QApplication::UnicodeUTF8));
        spinSampleRate->setSuffix(QApplication::translate("ExportAudio", " Hz", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ExportAudio", "Maximum length:", 0, QApplication::UnicodeUTF8));
        labelMemory->setText(QApplication::translate("ExportAudio", "Required memory: ??? MB", 0, QApplication::UnicodeUTF8));
        groupNormalize->setTitle(QApplication::translate("ExportAudio", "Normalize amplitude", 0, QApplication::UnicodeUTF8));
        radioNoNormalize->setText(QApplication::translate("ExportAudio", "No normalization", 0, QApplication::UnicodeUTF8));
        radioNormalizeClipping->setText(QApplication::translate("ExportAudio", "Only if clipping", 0, QApplication::UnicodeUTF8));
        radioNormalizePeak->setText(QApplication::translate("ExportAudio", "Set peak to:", 0, QApplication::UnicodeUTF8));
        spinPeak->setSuffix(QApplication::translate("ExportAudio", " %", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ExportAudio", "Export!", 0, QApplication::UnicodeUTF8));
        labelIntro->setText(QApplication::translate("ExportAudio", "<html><head/><body><p>This will allow you to generate an audio file from MusicString code <span style=\" font-weight:600;\">SOURCENAME</span>. Please select desired options and click Export. Depending on length, it might take a while.</p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ExportAudio: public Ui_ExportAudio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTAUDIO_H
