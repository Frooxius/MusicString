/********************************************************************************
** Form generated from reading UI file 'VisualMusicString.ui'
**
** Created: Tue 28. Feb 03:04:08 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISUALMUSICSTRING_H
#define UI_VISUALMUSICSTRING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VisualMusicStringClass
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionExport_to_Audio;
    QAction *actionExit;
    QAction *actionAbout_Visual_MusicString;
    QAction *actionAbout_MusicString;
    QAction *actionDocumentation_PDF;
    QAction *actionOfficial_Website;
    QAction *actionSet_Samplerate;
    QAction *actionSoundFont_Creator;
    QAction *actionUpdate_SoundFont_Database;
    QAction *actionDonate_pleaseee_3;
    QAction *actionCompress_ASCII;
    QAction *actionCompress_Encode_UTF_8;
    QAction *actionTweet_it;
    QAction *actionGoogle_it;
    QAction *actionMusicString_it;
    QAction *actionPastebin_it;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *butt_Play;
    QPushButton *butt_Pause;
    QPushButton *butt_Stop;
    QTabWidget *tabDocuments;
    QWidget *dummyTab;
    QHBoxLayout *tools_layout;
    QGroupBox *groupDurations;
    QGridLayout *gridLayout_2;
    QTableWidget *tableDurations;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelSetTempo;
    QDoubleSpinBox *spinTempo;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupFrequency;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *butt_FreqShiftLower;
    QPushButton *butt_FreqSemiShiftLower;
    QVBoxLayout *verticalLayout_5;
    QLabel *labelFreqShift;
    QPlainTextEdit *textFreqShift;
    QVBoxLayout *verticalLayout_4;
    QPushButton *butt_FreqShiftHigher;
    QPushButton *butt_FreqSemiShiftHigher;
    QTableWidget *tableFrequencies;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupVolume;
    QVBoxLayout *verticalLayout_2;
    QPlainTextEdit *textVolume;
    QSpinBox *spinVolumePercent;
    QHBoxLayout *horizontalLayout_4;
    QProgressBar *progressVolume;
    QSlider *sliderVolume;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuAbout;
    QMenu *menuSettings;
    QMenu *menuTools;
    QMenu *menuShare;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VisualMusicStringClass)
    {
        if (VisualMusicStringClass->objectName().isEmpty())
            VisualMusicStringClass->setObjectName(QString::fromUtf8("VisualMusicStringClass"));
        VisualMusicStringClass->resize(994, 688);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VisualMusicStringClass->sizePolicy().hasHeightForWidth());
        VisualMusicStringClass->setSizePolicy(sizePolicy);
        VisualMusicStringClass->setMinimumSize(QSize(640, 480));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/VisualMusicString/logo64x64.png"), QSize(), QIcon::Normal, QIcon::Off);
        VisualMusicStringClass->setWindowIcon(icon);
        actionNew = new QAction(VisualMusicStringClass);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionOpen = new QAction(VisualMusicStringClass);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionClose = new QAction(VisualMusicStringClass);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionSave = new QAction(VisualMusicStringClass);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_as = new QAction(VisualMusicStringClass);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionExport_to_Audio = new QAction(VisualMusicStringClass);
        actionExport_to_Audio->setObjectName(QString::fromUtf8("actionExport_to_Audio"));
        actionExit = new QAction(VisualMusicStringClass);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAbout_Visual_MusicString = new QAction(VisualMusicStringClass);
        actionAbout_Visual_MusicString->setObjectName(QString::fromUtf8("actionAbout_Visual_MusicString"));
        actionAbout_MusicString = new QAction(VisualMusicStringClass);
        actionAbout_MusicString->setObjectName(QString::fromUtf8("actionAbout_MusicString"));
        actionDocumentation_PDF = new QAction(VisualMusicStringClass);
        actionDocumentation_PDF->setObjectName(QString::fromUtf8("actionDocumentation_PDF"));
        actionOfficial_Website = new QAction(VisualMusicStringClass);
        actionOfficial_Website->setObjectName(QString::fromUtf8("actionOfficial_Website"));
        actionSet_Samplerate = new QAction(VisualMusicStringClass);
        actionSet_Samplerate->setObjectName(QString::fromUtf8("actionSet_Samplerate"));
        actionSoundFont_Creator = new QAction(VisualMusicStringClass);
        actionSoundFont_Creator->setObjectName(QString::fromUtf8("actionSoundFont_Creator"));
        actionUpdate_SoundFont_Database = new QAction(VisualMusicStringClass);
        actionUpdate_SoundFont_Database->setObjectName(QString::fromUtf8("actionUpdate_SoundFont_Database"));
        actionDonate_pleaseee_3 = new QAction(VisualMusicStringClass);
        actionDonate_pleaseee_3->setObjectName(QString::fromUtf8("actionDonate_pleaseee_3"));
        actionDonate_pleaseee_3->setIcon(icon);
        actionCompress_ASCII = new QAction(VisualMusicStringClass);
        actionCompress_ASCII->setObjectName(QString::fromUtf8("actionCompress_ASCII"));
        actionCompress_Encode_UTF_8 = new QAction(VisualMusicStringClass);
        actionCompress_Encode_UTF_8->setObjectName(QString::fromUtf8("actionCompress_Encode_UTF_8"));
        actionTweet_it = new QAction(VisualMusicStringClass);
        actionTweet_it->setObjectName(QString::fromUtf8("actionTweet_it"));
        actionGoogle_it = new QAction(VisualMusicStringClass);
        actionGoogle_it->setObjectName(QString::fromUtf8("actionGoogle_it"));
        actionMusicString_it = new QAction(VisualMusicStringClass);
        actionMusicString_it->setObjectName(QString::fromUtf8("actionMusicString_it"));
        actionPastebin_it = new QAction(VisualMusicStringClass);
        actionPastebin_it->setObjectName(QString::fromUtf8("actionPastebin_it"));
        centralWidget = new QWidget(VisualMusicStringClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setAutoFillBackground(false);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        butt_Play = new QPushButton(centralWidget);
        butt_Play->setObjectName(QString::fromUtf8("butt_Play"));

        horizontalLayout->addWidget(butt_Play);

        butt_Pause = new QPushButton(centralWidget);
        butt_Pause->setObjectName(QString::fromUtf8("butt_Pause"));

        horizontalLayout->addWidget(butt_Pause);

        butt_Stop = new QPushButton(centralWidget);
        butt_Stop->setObjectName(QString::fromUtf8("butt_Stop"));

        horizontalLayout->addWidget(butt_Stop);


        verticalLayout->addLayout(horizontalLayout);

        tabDocuments = new QTabWidget(centralWidget);
        tabDocuments->setObjectName(QString::fromUtf8("tabDocuments"));
        sizePolicy.setHeightForWidth(tabDocuments->sizePolicy().hasHeightForWidth());
        tabDocuments->setSizePolicy(sizePolicy);
        tabDocuments->setMaximumSize(QSize(16777215, 16777215));
        tabDocuments->setBaseSize(QSize(0, 0));
        tabDocuments->setTabShape(QTabWidget::Rounded);
        tabDocuments->setElideMode(Qt::ElideNone);
        tabDocuments->setDocumentMode(true);
        tabDocuments->setTabsClosable(true);
        tabDocuments->setMovable(true);
        dummyTab = new QWidget();
        dummyTab->setObjectName(QString::fromUtf8("dummyTab"));
        tabDocuments->addTab(dummyTab, QString());

        verticalLayout->addWidget(tabDocuments);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        tools_layout = new QHBoxLayout();
        tools_layout->setSpacing(6);
        tools_layout->setContentsMargins(0, 0, 0, 0);
        tools_layout->setObjectName(QString::fromUtf8("tools_layout"));
        tools_layout->setSizeConstraint(QLayout::SetDefaultConstraint);
        groupDurations = new QGroupBox(centralWidget);
        groupDurations->setObjectName(QString::fromUtf8("groupDurations"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupDurations->sizePolicy().hasHeightForWidth());
        groupDurations->setSizePolicy(sizePolicy2);
        groupDurations->setMinimumSize(QSize(0, 280));
        gridLayout_2 = new QGridLayout(groupDurations);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tableDurations = new QTableWidget(groupDurations);
        if (tableDurations->columnCount() < 3)
            tableDurations->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableDurations->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableDurations->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        tableDurations->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableDurations->rowCount() < 10)
            tableDurations->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableDurations->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableDurations->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableDurations->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableDurations->setVerticalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableDurations->setVerticalHeaderItem(4, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableDurations->setVerticalHeaderItem(5, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableDurations->setVerticalHeaderItem(6, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableDurations->setVerticalHeaderItem(7, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableDurations->setVerticalHeaderItem(8, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableDurations->setVerticalHeaderItem(9, __qtablewidgetitem12);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/NoteDuration/4x.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setIcon(icon1);
        tableDurations->setItem(0, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableDurations->setItem(0, 1, __qtablewidgetitem14);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/NoteDuration/2x.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setIcon(icon2);
        tableDurations->setItem(1, 0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableDurations->setItem(1, 1, __qtablewidgetitem16);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/NoteDuration/1x.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setIcon(icon3);
        tableDurations->setItem(2, 0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableDurations->setItem(2, 1, __qtablewidgetitem18);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/NoteDuration/2th.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setIcon(icon4);
        tableDurations->setItem(3, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableDurations->setItem(3, 1, __qtablewidgetitem20);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/NoteDuration/4th.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setIcon(icon5);
        tableDurations->setItem(4, 0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableDurations->setItem(4, 1, __qtablewidgetitem22);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/NoteDuration/8th.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setIcon(icon6);
        tableDurations->setItem(5, 0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableDurations->setItem(5, 1, __qtablewidgetitem24);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/NoteDuration/16th.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setIcon(icon7);
        tableDurations->setItem(6, 0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableDurations->setItem(6, 1, __qtablewidgetitem26);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/NoteDuration/32nd.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setIcon(icon8);
        tableDurations->setItem(7, 0, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableDurations->setItem(7, 1, __qtablewidgetitem28);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/NoteDuration/64th.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        __qtablewidgetitem29->setIcon(icon9);
        tableDurations->setItem(8, 0, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableDurations->setItem(8, 1, __qtablewidgetitem30);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/NoteDuration/128th.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        __qtablewidgetitem31->setIcon(icon10);
        tableDurations->setItem(9, 0, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableDurations->setItem(9, 1, __qtablewidgetitem32);
        tableDurations->setObjectName(QString::fromUtf8("tableDurations"));
        sizePolicy2.setHeightForWidth(tableDurations->sizePolicy().hasHeightForWidth());
        tableDurations->setSizePolicy(sizePolicy2);
        tableDurations->setMinimumSize(QSize(0, 220));
        tableDurations->setMaximumSize(QSize(160, 16777215));
        tableDurations->setFrameShape(QFrame::StyledPanel);
        tableDurations->setFrameShadow(QFrame::Sunken);
        tableDurations->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableDurations->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableDurations->setAutoScroll(true);
        tableDurations->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableDurations->setDragDropOverwriteMode(false);
        tableDurations->setDragDropMode(QAbstractItemView::DropOnly);
        tableDurations->setAlternatingRowColors(true);
        tableDurations->setSelectionMode(QAbstractItemView::NoSelection);
        tableDurations->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableDurations->setTextElideMode(Qt::ElideNone);
        tableDurations->setShowGrid(false);
        tableDurations->setWordWrap(false);
        tableDurations->setCornerButtonEnabled(false);
        tableDurations->horizontalHeader()->setVisible(false);
        tableDurations->horizontalHeader()->setCascadingSectionResizes(false);
        tableDurations->horizontalHeader()->setDefaultSectionSize(24);
        tableDurations->horizontalHeader()->setMinimumSectionSize(5);
        tableDurations->horizontalHeader()->setStretchLastSection(true);
        tableDurations->verticalHeader()->setDefaultSectionSize(22);
        tableDurations->verticalHeader()->setMinimumSectionSize(22);
        tableDurations->verticalHeader()->setStretchLastSection(false);

        gridLayout_2->addWidget(tableDurations, 3, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, -1, -1);
        labelSetTempo = new QLabel(groupDurations);
        labelSetTempo->setObjectName(QString::fromUtf8("labelSetTempo"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labelSetTempo->sizePolicy().hasHeightForWidth());
        labelSetTempo->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(labelSetTempo);

        spinTempo = new QDoubleSpinBox(groupDurations);
        spinTempo->setObjectName(QString::fromUtf8("spinTempo"));
        spinTempo->setMinimum(0.01);
        spinTempo->setMaximum(1e+06);
        spinTempo->setValue(120);

        horizontalLayout_2->addWidget(spinTempo);


        gridLayout_2->addLayout(horizontalLayout_2, 2, 1, 1, 1);


        tools_layout->addWidget(groupDurations);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        groupFrequency = new QGroupBox(centralWidget);
        groupFrequency->setObjectName(QString::fromUtf8("groupFrequency"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(groupFrequency->sizePolicy().hasHeightForWidth());
        groupFrequency->setSizePolicy(sizePolicy4);
        groupFrequency->setMinimumSize(QSize(0, 0));
        groupFrequency->setMaximumSize(QSize(16777215, 100));
        horizontalLayout_3 = new QHBoxLayout(groupFrequency);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, -1, -1, -1);
        butt_FreqShiftLower = new QPushButton(groupFrequency);
        butt_FreqShiftLower->setObjectName(QString::fromUtf8("butt_FreqShiftLower"));
        butt_FreqShiftLower->setMaximumSize(QSize(24, 16777215));

        verticalLayout_3->addWidget(butt_FreqShiftLower);

        butt_FreqSemiShiftLower = new QPushButton(groupFrequency);
        butt_FreqSemiShiftLower->setObjectName(QString::fromUtf8("butt_FreqSemiShiftLower"));
        butt_FreqSemiShiftLower->setMaximumSize(QSize(24, 16777215));

        verticalLayout_3->addWidget(butt_FreqSemiShiftLower);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_5->setContentsMargins(0, -1, -1, -1);
        labelFreqShift = new QLabel(groupFrequency);
        labelFreqShift->setObjectName(QString::fromUtf8("labelFreqShift"));
        sizePolicy3.setHeightForWidth(labelFreqShift->sizePolicy().hasHeightForWidth());
        labelFreqShift->setSizePolicy(sizePolicy3);

        verticalLayout_5->addWidget(labelFreqShift);

        textFreqShift = new QPlainTextEdit(groupFrequency);
        textFreqShift->setObjectName(QString::fromUtf8("textFreqShift"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(textFreqShift->sizePolicy().hasHeightForWidth());
        textFreqShift->setSizePolicy(sizePolicy5);
        textFreqShift->setMaximumSize(QSize(32, 24));
        textFreqShift->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textFreqShift->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textFreqShift->setReadOnly(true);

        verticalLayout_5->addWidget(textFreqShift);


        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, -1, -1, -1);
        butt_FreqShiftHigher = new QPushButton(groupFrequency);
        butt_FreqShiftHigher->setObjectName(QString::fromUtf8("butt_FreqShiftHigher"));
        butt_FreqShiftHigher->setMaximumSize(QSize(24, 16777215));

        verticalLayout_4->addWidget(butt_FreqShiftHigher);

        butt_FreqSemiShiftHigher = new QPushButton(groupFrequency);
        butt_FreqSemiShiftHigher->setObjectName(QString::fromUtf8("butt_FreqSemiShiftHigher"));
        butt_FreqSemiShiftHigher->setMaximumSize(QSize(24, 16777215));

        verticalLayout_4->addWidget(butt_FreqSemiShiftHigher);


        horizontalLayout_3->addLayout(verticalLayout_4);

        tableFrequencies = new QTableWidget(groupFrequency);
        if (tableFrequencies->columnCount() < 52)
            tableFrequencies->setColumnCount(52);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableFrequencies->setHorizontalHeaderItem(0, __qtablewidgetitem33);
        if (tableFrequencies->rowCount() < 1)
            tableFrequencies->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableFrequencies->setVerticalHeaderItem(0, __qtablewidgetitem34);
        tableFrequencies->setObjectName(QString::fromUtf8("tableFrequencies"));
        sizePolicy.setHeightForWidth(tableFrequencies->sizePolicy().hasHeightForWidth());
        tableFrequencies->setSizePolicy(sizePolicy);
        tableFrequencies->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableFrequencies->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableFrequencies->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableFrequencies->setDragDropOverwriteMode(false);
        tableFrequencies->setSelectionMode(QAbstractItemView::NoSelection);
        tableFrequencies->setSelectionBehavior(QAbstractItemView::SelectColumns);
        tableFrequencies->setWordWrap(false);
        tableFrequencies->setCornerButtonEnabled(false);
        tableFrequencies->setColumnCount(52);
        tableFrequencies->horizontalHeader()->setDefaultSectionSize(24);
        tableFrequencies->horizontalHeader()->setMinimumSectionSize(24);
        tableFrequencies->verticalHeader()->setDefaultSectionSize(24);
        tableFrequencies->verticalHeader()->setHighlightSections(true);

        horizontalLayout_3->addWidget(tableFrequencies);


        verticalLayout_6->addWidget(groupFrequency);

        verticalSpacer = new QSpacerItem(20, 170, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer);


        tools_layout->addLayout(verticalLayout_6);

        groupVolume = new QGroupBox(centralWidget);
        groupVolume->setObjectName(QString::fromUtf8("groupVolume"));
        sizePolicy2.setHeightForWidth(groupVolume->sizePolicy().hasHeightForWidth());
        groupVolume->setSizePolicy(sizePolicy2);
        groupVolume->setMinimumSize(QSize(0, 280));
        groupVolume->setMaximumSize(QSize(72, 16777215));
        verticalLayout_2 = new QVBoxLayout(groupVolume);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        textVolume = new QPlainTextEdit(groupVolume);
        textVolume->setObjectName(QString::fromUtf8("textVolume"));
        sizePolicy4.setHeightForWidth(textVolume->sizePolicy().hasHeightForWidth());
        textVolume->setSizePolicy(sizePolicy4);
        textVolume->setMinimumSize(QSize(0, 0));
        textVolume->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("Lucida Console"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        font.setStrikeOut(false);
        font.setKerning(true);
        textVolume->setFont(font);
        textVolume->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textVolume->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textVolume->setUndoRedoEnabled(false);
        textVolume->setLineWrapMode(QPlainTextEdit::NoWrap);
        textVolume->setReadOnly(false);
        textVolume->setOverwriteMode(false);
        textVolume->setTabStopWidth(2);
        textVolume->setCenterOnScroll(false);

        verticalLayout_2->addWidget(textVolume);

        spinVolumePercent = new QSpinBox(groupVolume);
        spinVolumePercent->setObjectName(QString::fromUtf8("spinVolumePercent"));
        spinVolumePercent->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        spinVolumePercent->setKeyboardTracking(false);
        spinVolumePercent->setMaximum(100);
        spinVolumePercent->setSingleStep(2);
        spinVolumePercent->setValue(100);

        verticalLayout_2->addWidget(spinVolumePercent);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 10, -1, -1);
        progressVolume = new QProgressBar(groupVolume);
        progressVolume->setObjectName(QString::fromUtf8("progressVolume"));
        progressVolume->setMaximumSize(QSize(14, 16777215));
        progressVolume->setValue(0);
        progressVolume->setTextVisible(false);
        progressVolume->setOrientation(Qt::Vertical);

        horizontalLayout_4->addWidget(progressVolume);

        sliderVolume = new QSlider(groupVolume);
        sliderVolume->setObjectName(QString::fromUtf8("sliderVolume"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(sliderVolume->sizePolicy().hasHeightForWidth());
        sliderVolume->setSizePolicy(sizePolicy6);
        sliderVolume->setMaximum(51);
        sliderVolume->setPageStep(5);
        sliderVolume->setOrientation(Qt::Vertical);

        horizontalLayout_4->addWidget(sliderVolume);


        verticalLayout_2->addLayout(horizontalLayout_4);


        tools_layout->addWidget(groupVolume);


        gridLayout->addLayout(tools_layout, 1, 0, 1, 1);

        VisualMusicStringClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VisualMusicStringClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 994, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuShare = new QMenu(menuBar);
        menuShare->setObjectName(QString::fromUtf8("menuShare"));
        VisualMusicStringClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(VisualMusicStringClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        VisualMusicStringClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuShare->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionClose);
        menuFile->addSeparator();
        menuFile->addAction(actionExport_to_Audio);
        menuFile->addAction(actionExit);
        menuAbout->addAction(actionDocumentation_PDF);
        menuAbout->addAction(actionAbout_MusicString);
        menuAbout->addAction(actionAbout_Visual_MusicString);
        menuAbout->addAction(actionOfficial_Website);
        menuAbout->addAction(actionDonate_pleaseee_3);
        menuSettings->addAction(actionSet_Samplerate);
        menuTools->addAction(actionSoundFont_Creator);
        menuTools->addAction(actionUpdate_SoundFont_Database);
        menuTools->addAction(actionCompress_ASCII);
        menuTools->addAction(actionCompress_Encode_UTF_8);
        menuShare->addAction(actionMusicString_it);
        menuShare->addAction(actionTweet_it);
        menuShare->addAction(actionGoogle_it);
        menuShare->addAction(actionPastebin_it);

        retranslateUi(VisualMusicStringClass);

        tabDocuments->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(VisualMusicStringClass);
    } // setupUi

    void retranslateUi(QMainWindow *VisualMusicStringClass)
    {
        VisualMusicStringClass->setWindowTitle(QApplication::translate("VisualMusicStringClass", "Visual MusicString - version 0.1 alpha preview", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("VisualMusicStringClass", "New", 0, QApplication::UnicodeUTF8));
        actionNew->setShortcut(QApplication::translate("VisualMusicStringClass", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("VisualMusicStringClass", "Open", 0, QApplication::UnicodeUTF8));
        actionOpen->setShortcut(QApplication::translate("VisualMusicStringClass", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("VisualMusicStringClass", "Close", 0, QApplication::UnicodeUTF8));
        actionClose->setShortcut(QApplication::translate("VisualMusicStringClass", "Ctrl+W", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("VisualMusicStringClass", "Save", 0, QApplication::UnicodeUTF8));
        actionSave->setShortcut(QApplication::translate("VisualMusicStringClass", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionSave_as->setText(QApplication::translate("VisualMusicStringClass", "Save as...", 0, QApplication::UnicodeUTF8));
        actionSave_as->setShortcut(QApplication::translate("VisualMusicStringClass", "Ctrl+Shift+S", 0, QApplication::UnicodeUTF8));
        actionExport_to_Audio->setText(QApplication::translate("VisualMusicStringClass", "Export to Audiofile...", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("VisualMusicStringClass", "Exit", 0, QApplication::UnicodeUTF8));
        actionAbout_Visual_MusicString->setText(QApplication::translate("VisualMusicStringClass", "About Visual MusicString", 0, QApplication::UnicodeUTF8));
        actionAbout_MusicString->setText(QApplication::translate("VisualMusicStringClass", "About MusicString", 0, QApplication::UnicodeUTF8));
        actionDocumentation_PDF->setText(QApplication::translate("VisualMusicStringClass", "Documentation (PDF)", 0, QApplication::UnicodeUTF8));
        actionOfficial_Website->setText(QApplication::translate("VisualMusicStringClass", "Oficial Website", 0, QApplication::UnicodeUTF8));
        actionSet_Samplerate->setText(QApplication::translate("VisualMusicStringClass", "Set Samplerate", 0, QApplication::UnicodeUTF8));
        actionSoundFont_Creator->setText(QApplication::translate("VisualMusicStringClass", "SoundFont Creator", 0, QApplication::UnicodeUTF8));
        actionUpdate_SoundFont_Database->setText(QApplication::translate("VisualMusicStringClass", "Update SoundFont Database", 0, QApplication::UnicodeUTF8));
        actionDonate_pleaseee_3->setText(QApplication::translate("VisualMusicStringClass", "Donate (pleeease? :3)", 0, QApplication::UnicodeUTF8));
        actionCompress_ASCII->setText(QApplication::translate("VisualMusicStringClass", "Compress (ASCII)", 0, QApplication::UnicodeUTF8));
        actionCompress_Encode_UTF_8->setText(QApplication::translate("VisualMusicStringClass", "Compress&Encode (UTF-8)", 0, QApplication::UnicodeUTF8));
        actionTweet_it->setText(QApplication::translate("VisualMusicStringClass", "Tweet it!", 0, QApplication::UnicodeUTF8));
        actionGoogle_it->setText(QApplication::translate("VisualMusicStringClass", "Google+ it!", 0, QApplication::UnicodeUTF8));
        actionMusicString_it->setText(QApplication::translate("VisualMusicStringClass", "MusicString it!", 0, QApplication::UnicodeUTF8));
        actionPastebin_it->setText(QApplication::translate("VisualMusicStringClass", "Pastebin it!", 0, QApplication::UnicodeUTF8));
        butt_Play->setText(QApplication::translate("VisualMusicStringClass", "Play", 0, QApplication::UnicodeUTF8));
        butt_Pause->setText(QApplication::translate("VisualMusicStringClass", "Pause", 0, QApplication::UnicodeUTF8));
        butt_Stop->setText(QApplication::translate("VisualMusicStringClass", "Stop", 0, QApplication::UnicodeUTF8));
        tabDocuments->setTabText(tabDocuments->indexOf(dummyTab), QApplication::translate("VisualMusicStringClass", "Dummy", 0, QApplication::UnicodeUTF8));
        groupDurations->setTitle(QApplication::translate("VisualMusicStringClass", "Tone Duration Reference", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableDurations->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("VisualMusicStringClass", "Symbol", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableDurations->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("VisualMusicStringClass", "Note", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableDurations->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("VisualMusicStringClass", "Length", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableDurations->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("VisualMusicStringClass", "9", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableDurations->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("VisualMusicStringClass", "8", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableDurations->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("VisualMusicStringClass", "7", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableDurations->verticalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("VisualMusicStringClass", "6", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableDurations->verticalHeaderItem(4);
        ___qtablewidgetitem7->setText(QApplication::translate("VisualMusicStringClass", "5", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableDurations->verticalHeaderItem(5);
        ___qtablewidgetitem8->setText(QApplication::translate("VisualMusicStringClass", "4", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableDurations->verticalHeaderItem(6);
        ___qtablewidgetitem9->setText(QApplication::translate("VisualMusicStringClass", "3", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableDurations->verticalHeaderItem(7);
        ___qtablewidgetitem10->setText(QApplication::translate("VisualMusicStringClass", "2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableDurations->verticalHeaderItem(8);
        ___qtablewidgetitem11->setText(QApplication::translate("VisualMusicStringClass", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = tableDurations->verticalHeaderItem(9);
        ___qtablewidgetitem12->setText(QApplication::translate("VisualMusicStringClass", "0", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = tableDurations->isSortingEnabled();
        tableDurations->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem13 = tableDurations->item(0, 1);
        ___qtablewidgetitem13->setText(QApplication::translate("VisualMusicStringClass", "Longa", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = tableDurations->item(1, 1);
        ___qtablewidgetitem14->setText(QApplication::translate("VisualMusicStringClass", "Double", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = tableDurations->item(2, 1);
        ___qtablewidgetitem15->setText(QApplication::translate("VisualMusicStringClass", "Whole", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem16 = tableDurations->item(3, 1);
        ___qtablewidgetitem16->setText(QApplication::translate("VisualMusicStringClass", "Half", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem17 = tableDurations->item(4, 1);
        ___qtablewidgetitem17->setText(QApplication::translate("VisualMusicStringClass", "Quarter", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem18 = tableDurations->item(5, 1);
        ___qtablewidgetitem18->setText(QApplication::translate("VisualMusicStringClass", "Eighth", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem19 = tableDurations->item(6, 1);
        ___qtablewidgetitem19->setText(QApplication::translate("VisualMusicStringClass", "16th", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem20 = tableDurations->item(7, 1);
        ___qtablewidgetitem20->setText(QApplication::translate("VisualMusicStringClass", "32th", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem21 = tableDurations->item(8, 1);
        ___qtablewidgetitem21->setText(QApplication::translate("VisualMusicStringClass", "64th", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem22 = tableDurations->item(9, 1);
        ___qtablewidgetitem22->setText(QApplication::translate("VisualMusicStringClass", "128th", 0, QApplication::UnicodeUTF8));
        tableDurations->setSortingEnabled(__sortingEnabled);

        labelSetTempo->setText(QApplication::translate("VisualMusicStringClass", "Tempo:", 0, QApplication::UnicodeUTF8));
        spinTempo->setSuffix(QApplication::translate("VisualMusicStringClass", " bpm", 0, QApplication::UnicodeUTF8));
        groupFrequency->setTitle(QApplication::translate("VisualMusicStringClass", "Tone Frequency Reference", 0, QApplication::UnicodeUTF8));
        butt_FreqShiftLower->setText(QApplication::translate("VisualMusicStringClass", "<<", 0, QApplication::UnicodeUTF8));
        butt_FreqSemiShiftLower->setText(QApplication::translate("VisualMusicStringClass", "<", 0, QApplication::UnicodeUTF8));
        labelFreqShift->setText(QApplication::translate("VisualMusicStringClass", "m = 20", 0, QApplication::UnicodeUTF8));
        textFreqShift->setPlainText(QApplication::translate("VisualMusicStringClass", "&n", 0, QApplication::UnicodeUTF8));
        butt_FreqShiftHigher->setText(QApplication::translate("VisualMusicStringClass", ">>", 0, QApplication::UnicodeUTF8));
        butt_FreqSemiShiftHigher->setText(QApplication::translate("VisualMusicStringClass", ">", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem23 = tableFrequencies->horizontalHeaderItem(0);
        ___qtablewidgetitem23->setText(QApplication::translate("VisualMusicStringClass", "Dummy", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem24 = tableFrequencies->verticalHeaderItem(0);
        ___qtablewidgetitem24->setText(QApplication::translate("VisualMusicStringClass", "Note", 0, QApplication::UnicodeUTF8));
        groupVolume->setTitle(QApplication::translate("VisualMusicStringClass", "Volume", 0, QApplication::UnicodeUTF8));
        textVolume->setPlainText(QApplication::translate("VisualMusicStringClass", "%f", 0, QApplication::UnicodeUTF8));
        spinVolumePercent->setSuffix(QApplication::translate("VisualMusicStringClass", " %", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("VisualMusicStringClass", "File", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("VisualMusicStringClass", "About", 0, QApplication::UnicodeUTF8));
        menuSettings->setTitle(QApplication::translate("VisualMusicStringClass", "Settings", 0, QApplication::UnicodeUTF8));
        menuTools->setTitle(QApplication::translate("VisualMusicStringClass", "Tools", 0, QApplication::UnicodeUTF8));
        menuShare->setTitle(QApplication::translate("VisualMusicStringClass", "Share", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VisualMusicStringClass: public Ui_VisualMusicStringClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALMUSICSTRING_H
