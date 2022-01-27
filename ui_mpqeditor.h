/********************************************************************************
** Form generated from reading ui file 'mpqeditor.ui'
**
** Created: Sat Apr 4 13:48:20 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MPQEDITOR_H
#define UI_MPQEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MpqEditor
{
public:
    QGridLayout *gridLayout;
    QTreeWidget *archiveTreeWidget;
    QGroupBox *mpqArchiveGroupBox;
    QGridLayout *gridLayout1;
    QVBoxLayout *vboxLayout;
    QPushButton *createNewArchivePushButton;
    QPushButton *openArchivePushButton;
    QPushButton *closeCurrentArchivePushButton;
    QGroupBox *fileGroupBox;
    QGridLayout *gridLayout2;
    QVBoxLayout *vboxLayout1;
    QPushButton *addFilesPushButton;
    QPushButton *extractSelectedFilesPushButton;
    QPushButton *openSelectedFilesPushButton;
    QPushButton *deleteSelectedFilesPushButton;
    QHBoxLayout *hboxLayout;
    QPushButton *settingsPushButton;
    QPushButton *closePushButton;

    void setupUi(QDialog *MpqEditor)
    {
        if (MpqEditor->objectName().isEmpty())
            MpqEditor->setObjectName(QString::fromUtf8("MpqEditor"));
        MpqEditor->resize(572, 344);
        const QIcon icon = QIcon(QString::fromUtf8(":/images/vjasside.png"));
        MpqEditor->setWindowIcon(icon);
        gridLayout = new QGridLayout(MpqEditor);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        archiveTreeWidget = new QTreeWidget(MpqEditor);
        archiveTreeWidget->setObjectName(QString::fromUtf8("archiveTreeWidget"));
        archiveTreeWidget->setColumnCount(7);

        gridLayout->addWidget(archiveTreeWidget, 0, 0, 2, 1);

        mpqArchiveGroupBox = new QGroupBox(MpqEditor);
        mpqArchiveGroupBox->setObjectName(QString::fromUtf8("mpqArchiveGroupBox"));
        gridLayout1 = new QGridLayout(mpqArchiveGroupBox);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        vboxLayout = new QVBoxLayout();
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        createNewArchivePushButton = new QPushButton(mpqArchiveGroupBox);
        createNewArchivePushButton->setObjectName(QString::fromUtf8("createNewArchivePushButton"));

        vboxLayout->addWidget(createNewArchivePushButton);

        openArchivePushButton = new QPushButton(mpqArchiveGroupBox);
        openArchivePushButton->setObjectName(QString::fromUtf8("openArchivePushButton"));

        vboxLayout->addWidget(openArchivePushButton);

        closeCurrentArchivePushButton = new QPushButton(mpqArchiveGroupBox);
        closeCurrentArchivePushButton->setObjectName(QString::fromUtf8("closeCurrentArchivePushButton"));
        closeCurrentArchivePushButton->setEnabled(false);

        vboxLayout->addWidget(closeCurrentArchivePushButton);


        gridLayout1->addLayout(vboxLayout, 0, 0, 1, 1);


        gridLayout->addWidget(mpqArchiveGroupBox, 0, 1, 1, 1);

        fileGroupBox = new QGroupBox(MpqEditor);
        fileGroupBox->setObjectName(QString::fromUtf8("fileGroupBox"));
        fileGroupBox->setEnabled(false);
        gridLayout2 = new QGridLayout(fileGroupBox);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        addFilesPushButton = new QPushButton(fileGroupBox);
        addFilesPushButton->setObjectName(QString::fromUtf8("addFilesPushButton"));

        vboxLayout1->addWidget(addFilesPushButton);

        extractSelectedFilesPushButton = new QPushButton(fileGroupBox);
        extractSelectedFilesPushButton->setObjectName(QString::fromUtf8("extractSelectedFilesPushButton"));

        vboxLayout1->addWidget(extractSelectedFilesPushButton);

        openSelectedFilesPushButton = new QPushButton(fileGroupBox);
        openSelectedFilesPushButton->setObjectName(QString::fromUtf8("openSelectedFilesPushButton"));

        vboxLayout1->addWidget(openSelectedFilesPushButton);

        deleteSelectedFilesPushButton = new QPushButton(fileGroupBox);
        deleteSelectedFilesPushButton->setObjectName(QString::fromUtf8("deleteSelectedFilesPushButton"));

        vboxLayout1->addWidget(deleteSelectedFilesPushButton);


        gridLayout2->addLayout(vboxLayout1, 0, 0, 1, 1);


        gridLayout->addWidget(fileGroupBox, 1, 1, 2, 1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        settingsPushButton = new QPushButton(MpqEditor);
        settingsPushButton->setObjectName(QString::fromUtf8("settingsPushButton"));

        hboxLayout->addWidget(settingsPushButton);

        closePushButton = new QPushButton(MpqEditor);
        closePushButton->setObjectName(QString::fromUtf8("closePushButton"));

        hboxLayout->addWidget(closePushButton);


        gridLayout->addLayout(hboxLayout, 2, 0, 1, 1);


        retranslateUi(MpqEditor);
        QObject::connect(closePushButton, SIGNAL(clicked()), MpqEditor, SLOT(reject()));

        QMetaObject::connectSlotsByName(MpqEditor);
    } // setupUi

    void retranslateUi(QDialog *MpqEditor)
    {
        MpqEditor->setWindowTitle(QApplication::translate("MpqEditor", "MPQ-Editor", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = archiveTreeWidget->headerItem();
        ___qtreewidgetitem->setText(6, QApplication::translate("MpqEditor", "Komprimierte Gr\303\266\303\237e", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(5, QApplication::translate("MpqEditor", "Index", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(4, QApplication::translate("MpqEditor", "Attribute", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(3, QApplication::translate("MpqEditor", "Gr\303\266\303\237e", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(2, QApplication::translate("MpqEditor", "Sprache", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("MpqEditor", "Name", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("MpqEditor", "Pfad", 0, QApplication::UnicodeUTF8));
        mpqArchiveGroupBox->setTitle(QApplication::translate("MpqEditor", "MPQ-Archiv", 0, QApplication::UnicodeUTF8));
        createNewArchivePushButton->setText(QApplication::translate("MpqEditor", "Anlegen", 0, QApplication::UnicodeUTF8));
        openArchivePushButton->setText(QApplication::translate("MpqEditor", "\303\226ffnen", 0, QApplication::UnicodeUTF8));
        closeCurrentArchivePushButton->setText(QApplication::translate("MpqEditor", "Schlie\303\237en", 0, QApplication::UnicodeUTF8));
        fileGroupBox->setTitle(QApplication::translate("MpqEditor", "Datei", 0, QApplication::UnicodeUTF8));
        addFilesPushButton->setText(QApplication::translate("MpqEditor", "Hinzuf\303\274gen", 0, QApplication::UnicodeUTF8));
        extractSelectedFilesPushButton->setText(QApplication::translate("MpqEditor", "Extrahieren", 0, QApplication::UnicodeUTF8));
        openSelectedFilesPushButton->setText(QApplication::translate("MpqEditor", "\303\226ffnen", 0, QApplication::UnicodeUTF8));
        deleteSelectedFilesPushButton->setText(QApplication::translate("MpqEditor", "L\303\266schen", 0, QApplication::UnicodeUTF8));
        settingsPushButton->setText(QApplication::translate("MpqEditor", "Einstellungen", 0, QApplication::UnicodeUTF8));
        closePushButton->setText(QApplication::translate("MpqEditor", "Schlie\303\237en", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MpqEditor);
    } // retranslateUi

};

namespace Ui {
    class MpqEditor: public Ui_MpqEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MPQEDITOR_H
