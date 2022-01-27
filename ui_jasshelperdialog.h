/********************************************************************************
** Form generated from reading ui file 'jasshelperdialog.ui'
**
** Created: Sat Apr 4 13:48:20 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_JASSHELPERDIALOG_H
#define UI_JASSHELPERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_JasshelperDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *hboxLayout;
    QGroupBox *lookUpFoldersGroupBox;
    QGridLayout *gridLayout1;
    QListWidget *lookUpFolderListWidget;
    QHBoxLayout *hboxLayout1;
    QPushButton *addLookUpFolderPushButton;
    QPushButton *removeLookUpFolderPushButton;
    QGroupBox *externalToolsGroupBox;
    QGridLayout *gridLayout2;
    QListWidget *externalToolListWidget;
    QHBoxLayout *hboxLayout2;
    QPushButton *addExternalToolPushButton;
    QPushButton *removeExternalToolPushButton;
    QHBoxLayout *hboxLayout3;
    QVBoxLayout *vboxLayout;
    QGroupBox *mapModeGroupBox;
    QGridLayout *gridLayout3;
    QVBoxLayout *vboxLayout1;
    QPushButton *selectMapScriptPushButton;
    QPushButton *selectMapPushButton;
    QGroupBox *scriptonlyModeGroupBox;
    QGridLayout *gridLayout4;
    QVBoxLayout *vboxLayout2;
    QPushButton *selectInputFilePushButton;
    QPushButton *selectOutputFilePushButton;
    QVBoxLayout *vboxLayout3;
    QGroupBox *optionsGroupBox;
    QGridLayout *gridLayout5;
    QVBoxLayout *vboxLayout4;
    QPushButton *selectJasshelperPushButton;
    QPushButton *selectConfigFilePushButton;
    QPushButton *selectJassCompilerPushButton;
    QPushButton *selectWewarlockPushButton;
    QCheckBox *debugCheckBox;
    QCheckBox *nopreprocessorCheckBox;
    QCheckBox *nooptimizeCheckBox;
    QCheckBox *scriptonlyCheckBox;
    QCheckBox *warcityCheckBox;
    QCheckBox *showerrorsCheckBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *JasshelperDialog)
    {
        if (JasshelperDialog->objectName().isEmpty())
            JasshelperDialog->setObjectName(QString::fromUtf8("JasshelperDialog"));
        JasshelperDialog->resize(544, 555);
        JasshelperDialog->setModal(true);
        gridLayout = new QGridLayout(JasshelperDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        lookUpFoldersGroupBox = new QGroupBox(JasshelperDialog);
        lookUpFoldersGroupBox->setObjectName(QString::fromUtf8("lookUpFoldersGroupBox"));
        gridLayout1 = new QGridLayout(lookUpFoldersGroupBox);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        lookUpFolderListWidget = new QListWidget(lookUpFoldersGroupBox);
        lookUpFolderListWidget->setObjectName(QString::fromUtf8("lookUpFolderListWidget"));

        gridLayout1->addWidget(lookUpFolderListWidget, 0, 0, 1, 1);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        addLookUpFolderPushButton = new QPushButton(lookUpFoldersGroupBox);
        addLookUpFolderPushButton->setObjectName(QString::fromUtf8("addLookUpFolderPushButton"));
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/list-add.png")), QIcon::Normal, QIcon::Off);
        addLookUpFolderPushButton->setIcon(icon);

        hboxLayout1->addWidget(addLookUpFolderPushButton);

        removeLookUpFolderPushButton = new QPushButton(lookUpFoldersGroupBox);
        removeLookUpFolderPushButton->setObjectName(QString::fromUtf8("removeLookUpFolderPushButton"));
        removeLookUpFolderPushButton->setEnabled(false);
        QIcon icon1;
        icon1.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/list-remove.png")), QIcon::Normal, QIcon::Off);
        removeLookUpFolderPushButton->setIcon(icon1);

        hboxLayout1->addWidget(removeLookUpFolderPushButton);


        gridLayout1->addLayout(hboxLayout1, 1, 0, 1, 1);


        hboxLayout->addWidget(lookUpFoldersGroupBox);

        externalToolsGroupBox = new QGroupBox(JasshelperDialog);
        externalToolsGroupBox->setObjectName(QString::fromUtf8("externalToolsGroupBox"));
        gridLayout2 = new QGridLayout(externalToolsGroupBox);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        externalToolListWidget = new QListWidget(externalToolsGroupBox);
        externalToolListWidget->setObjectName(QString::fromUtf8("externalToolListWidget"));

        gridLayout2->addWidget(externalToolListWidget, 0, 0, 1, 1);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        addExternalToolPushButton = new QPushButton(externalToolsGroupBox);
        addExternalToolPushButton->setObjectName(QString::fromUtf8("addExternalToolPushButton"));
        addExternalToolPushButton->setIcon(icon);

        hboxLayout2->addWidget(addExternalToolPushButton);

        removeExternalToolPushButton = new QPushButton(externalToolsGroupBox);
        removeExternalToolPushButton->setObjectName(QString::fromUtf8("removeExternalToolPushButton"));
        removeExternalToolPushButton->setEnabled(false);
        removeExternalToolPushButton->setIcon(icon1);

        hboxLayout2->addWidget(removeExternalToolPushButton);


        gridLayout2->addLayout(hboxLayout2, 1, 0, 1, 1);


        hboxLayout->addWidget(externalToolsGroupBox);


        gridLayout->addLayout(hboxLayout, 0, 0, 1, 1);

        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        vboxLayout = new QVBoxLayout();
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        mapModeGroupBox = new QGroupBox(JasshelperDialog);
        mapModeGroupBox->setObjectName(QString::fromUtf8("mapModeGroupBox"));
        mapModeGroupBox->setEnabled(true);
        gridLayout3 = new QGridLayout(mapModeGroupBox);
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        selectMapScriptPushButton = new QPushButton(mapModeGroupBox);
        selectMapScriptPushButton->setObjectName(QString::fromUtf8("selectMapScriptPushButton"));

        vboxLayout1->addWidget(selectMapScriptPushButton);

        selectMapPushButton = new QPushButton(mapModeGroupBox);
        selectMapPushButton->setObjectName(QString::fromUtf8("selectMapPushButton"));

        vboxLayout1->addWidget(selectMapPushButton);


        gridLayout3->addLayout(vboxLayout1, 0, 0, 1, 1);


        vboxLayout->addWidget(mapModeGroupBox);

        scriptonlyModeGroupBox = new QGroupBox(JasshelperDialog);
        scriptonlyModeGroupBox->setObjectName(QString::fromUtf8("scriptonlyModeGroupBox"));
        scriptonlyModeGroupBox->setEnabled(false);
        gridLayout4 = new QGridLayout(scriptonlyModeGroupBox);
        gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        selectInputFilePushButton = new QPushButton(scriptonlyModeGroupBox);
        selectInputFilePushButton->setObjectName(QString::fromUtf8("selectInputFilePushButton"));

        vboxLayout2->addWidget(selectInputFilePushButton);

        selectOutputFilePushButton = new QPushButton(scriptonlyModeGroupBox);
        selectOutputFilePushButton->setObjectName(QString::fromUtf8("selectOutputFilePushButton"));

        vboxLayout2->addWidget(selectOutputFilePushButton);


        gridLayout4->addLayout(vboxLayout2, 0, 0, 1, 1);


        vboxLayout->addWidget(scriptonlyModeGroupBox);


        hboxLayout3->addLayout(vboxLayout);

        vboxLayout3 = new QVBoxLayout();
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        optionsGroupBox = new QGroupBox(JasshelperDialog);
        optionsGroupBox->setObjectName(QString::fromUtf8("optionsGroupBox"));
        gridLayout5 = new QGridLayout(optionsGroupBox);
        gridLayout5->setObjectName(QString::fromUtf8("gridLayout5"));
        vboxLayout4 = new QVBoxLayout();
        vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
        selectJasshelperPushButton = new QPushButton(optionsGroupBox);
        selectJasshelperPushButton->setObjectName(QString::fromUtf8("selectJasshelperPushButton"));

        vboxLayout4->addWidget(selectJasshelperPushButton);

        selectConfigFilePushButton = new QPushButton(optionsGroupBox);
        selectConfigFilePushButton->setObjectName(QString::fromUtf8("selectConfigFilePushButton"));

        vboxLayout4->addWidget(selectConfigFilePushButton);

        selectJassCompilerPushButton = new QPushButton(optionsGroupBox);
        selectJassCompilerPushButton->setObjectName(QString::fromUtf8("selectJassCompilerPushButton"));

        vboxLayout4->addWidget(selectJassCompilerPushButton);

        selectWewarlockPushButton = new QPushButton(optionsGroupBox);
        selectWewarlockPushButton->setObjectName(QString::fromUtf8("selectWewarlockPushButton"));

        vboxLayout4->addWidget(selectWewarlockPushButton);

        debugCheckBox = new QCheckBox(optionsGroupBox);
        debugCheckBox->setObjectName(QString::fromUtf8("debugCheckBox"));

        vboxLayout4->addWidget(debugCheckBox);

        nopreprocessorCheckBox = new QCheckBox(optionsGroupBox);
        nopreprocessorCheckBox->setObjectName(QString::fromUtf8("nopreprocessorCheckBox"));

        vboxLayout4->addWidget(nopreprocessorCheckBox);

        nooptimizeCheckBox = new QCheckBox(optionsGroupBox);
        nooptimizeCheckBox->setObjectName(QString::fromUtf8("nooptimizeCheckBox"));

        vboxLayout4->addWidget(nooptimizeCheckBox);

        scriptonlyCheckBox = new QCheckBox(optionsGroupBox);
        scriptonlyCheckBox->setObjectName(QString::fromUtf8("scriptonlyCheckBox"));

        vboxLayout4->addWidget(scriptonlyCheckBox);

        warcityCheckBox = new QCheckBox(optionsGroupBox);
        warcityCheckBox->setObjectName(QString::fromUtf8("warcityCheckBox"));

        vboxLayout4->addWidget(warcityCheckBox);

        showerrorsCheckBox = new QCheckBox(optionsGroupBox);
        showerrorsCheckBox->setObjectName(QString::fromUtf8("showerrorsCheckBox"));

        vboxLayout4->addWidget(showerrorsCheckBox);


        gridLayout5->addLayout(vboxLayout4, 0, 0, 1, 1);


        vboxLayout3->addWidget(optionsGroupBox);


        hboxLayout3->addLayout(vboxLayout3);


        gridLayout->addLayout(hboxLayout3, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(JasshelperDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok|QDialogButtonBox::RestoreDefaults);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);


        retranslateUi(JasshelperDialog);
        QObject::connect(warcityCheckBox, SIGNAL(toggled(bool)), scriptonlyCheckBox, SLOT(setChecked(bool)));
        QObject::connect(warcityCheckBox, SIGNAL(toggled(bool)), scriptonlyCheckBox, SLOT(setDisabled(bool)));
        QObject::connect(scriptonlyCheckBox, SIGNAL(toggled(bool)), scriptonlyModeGroupBox, SLOT(setEnabled(bool)));
        QObject::connect(scriptonlyCheckBox, SIGNAL(toggled(bool)), mapModeGroupBox, SLOT(setDisabled(bool)));
        QObject::connect(buttonBox, SIGNAL(accepted()), JasshelperDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), JasshelperDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(JasshelperDialog);
    } // setupUi

    void retranslateUi(QDialog *JasshelperDialog)
    {
        JasshelperDialog->setWindowTitle(QApplication::translate("JasshelperDialog", "vJass-Syntax \303\274berpr\303\274fen", 0, QApplication::UnicodeUTF8));
        lookUpFoldersGroupBox->setTitle(QApplication::translate("JasshelperDialog", "Nachschlagordner", 0, QApplication::UnicodeUTF8));
        addLookUpFolderPushButton->setText(QApplication::translate("JasshelperDialog", "Hinzuf\303\274gen", 0, QApplication::UnicodeUTF8));
        removeLookUpFolderPushButton->setText(QApplication::translate("JasshelperDialog", "Entfernen", 0, QApplication::UnicodeUTF8));
        externalToolsGroupBox->setTitle(QApplication::translate("JasshelperDialog", "Externe Werkzeuge", 0, QApplication::UnicodeUTF8));
        addExternalToolPushButton->setText(QApplication::translate("JasshelperDialog", "Hinzuf\303\274gen", 0, QApplication::UnicodeUTF8));
        removeExternalToolPushButton->setText(QApplication::translate("JasshelperDialog", "Entfernen", 0, QApplication::UnicodeUTF8));
        mapModeGroupBox->setTitle(QApplication::translate("JasshelperDialog", "Kartenmodus", 0, QApplication::UnicodeUTF8));
        selectMapScriptPushButton->setText(QApplication::translate("JasshelperDialog", "Kartenskript ausw\303\244hlen", 0, QApplication::UnicodeUTF8));
        selectMapPushButton->setText(QApplication::translate("JasshelperDialog", "Karte ausw\303\244hlen", 0, QApplication::UnicodeUTF8));
        scriptonlyModeGroupBox->setTitle(QApplication::translate("JasshelperDialog", "Skript-Modus", 0, QApplication::UnicodeUTF8));
        selectInputFilePushButton->setText(QApplication::translate("JasshelperDialog", "Eingabedatei ausw\303\244hlen", 0, QApplication::UnicodeUTF8));
        selectOutputFilePushButton->setText(QApplication::translate("JasshelperDialog", "Ausgabedatei ausw\303\244hlen", 0, QApplication::UnicodeUTF8));
        optionsGroupBox->setTitle(QApplication::translate("JasshelperDialog", "Optionen", 0, QApplication::UnicodeUTF8));
        selectJasshelperPushButton->setText(QApplication::translate("JasshelperDialog", "JassHelper ausw\303\244hlen", 0, QApplication::UnicodeUTF8));
        selectConfigFilePushButton->setText(QApplication::translate("JasshelperDialog", "Konfigurationsdatei ausw\303\244hlen", 0, QApplication::UnicodeUTF8));
        selectJassCompilerPushButton->setText(QApplication::translate("JasshelperDialog", "Jass-Compiler ausw\303\244hlen", 0, QApplication::UnicodeUTF8));
        selectWewarlockPushButton->setText(QApplication::translate("JasshelperDialog", "WEWarlock ausw\303\244hlen", 0, QApplication::UnicodeUTF8));
        debugCheckBox->setText(QApplication::translate("JasshelperDialog", "Debug-Modus", 0, QApplication::UnicodeUTF8));
        nopreprocessorCheckBox->setText(QApplication::translate("JasshelperDialog", "Keine Pr\303\244prozessoren", 0, QApplication::UnicodeUTF8));
        nooptimizeCheckBox->setText(QApplication::translate("JasshelperDialog", "Keine Optimierungen", 0, QApplication::UnicodeUTF8));
        scriptonlyCheckBox->setText(QApplication::translate("JasshelperDialog", "Nur Skripte", 0, QApplication::UnicodeUTF8));
        warcityCheckBox->setText(QApplication::translate("JasshelperDialog", "Warcity verwenden", 0, QApplication::UnicodeUTF8));
        showerrorsCheckBox->setText(QApplication::translate("JasshelperDialog", "Vorherige Fehler anzeigen", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(JasshelperDialog);
    } // retranslateUi

};

namespace Ui {
    class JasshelperDialog: public Ui_JasshelperDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JASSHELPERDIALOG_H
