/********************************************************************************
** Form generated from reading ui file 'mpqdialog.ui'
**
** Created: Thu Jan 1 20:55:12 2009
**      by: Qt User Interface Compiler version 4.3.4
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MPQDIALOG_H
#define UI_MPQDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QPushButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

class Ui_MpqDialog
{
public:
    QTreeWidget *archiveTreeWidget;
    QWidget *verticalLayout_3;
    QVBoxLayout *vboxLayout;
    QGroupBox *groupBox;
    QWidget *verticalLayout;
    QVBoxLayout *vboxLayout1;
    QPushButton *createNewArchivePushButton;
    QPushButton *openArchivePushButton;
    QPushButton *closeCurrentArchivePushButton;
    QGroupBox *groupBox_2;
    QWidget *verticalLayout_2;
    QVBoxLayout *vboxLayout2;
    QPushButton *addFilePushButton;
    QPushButton *extractFilePushButton;
    QPushButton *openFilePushButton;
    QPushButton *closeFilePushButton;
    QPushButton *closePushButton;

    void setupUi(QWidget *MpqDialog)
    {
    if (MpqDialog->objectName().isEmpty())
        MpqDialog->setObjectName(QString::fromUtf8("MpqDialog"));
    MpqDialog->resize(472, 381);
    MpqDialog->setWindowIcon(QIcon(QString::fromUtf8(":/images/vjasside.png")));
    archiveTreeWidget = new QTreeWidget(MpqDialog);
    archiveTreeWidget->setObjectName(QString::fromUtf8("archiveTreeWidget"));
    archiveTreeWidget->setGeometry(QRect(4, 4, 318, 351));
    archiveTreeWidget->setColumnCount(0);
    verticalLayout_3 = new QWidget(MpqDialog);
    verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
    verticalLayout_3->setGeometry(QRect(330, 0, 131, 351));
    vboxLayout = new QVBoxLayout(verticalLayout_3);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    vboxLayout->setContentsMargins(0, 0, 0, 0);
    groupBox = new QGroupBox(verticalLayout_3);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    verticalLayout = new QWidget(groupBox);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->setGeometry(QRect(10, 30, 111, 94));
    vboxLayout1 = new QVBoxLayout(verticalLayout);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    vboxLayout1->setContentsMargins(0, 0, 0, 0);
    createNewArchivePushButton = new QPushButton(verticalLayout);
    createNewArchivePushButton->setObjectName(QString::fromUtf8("createNewArchivePushButton"));

    vboxLayout1->addWidget(createNewArchivePushButton);

    openArchivePushButton = new QPushButton(verticalLayout);
    openArchivePushButton->setObjectName(QString::fromUtf8("openArchivePushButton"));

    vboxLayout1->addWidget(openArchivePushButton);

    closeCurrentArchivePushButton = new QPushButton(verticalLayout);
    closeCurrentArchivePushButton->setObjectName(QString::fromUtf8("closeCurrentArchivePushButton"));

    vboxLayout1->addWidget(closeCurrentArchivePushButton);


    vboxLayout->addWidget(groupBox);

    groupBox_2 = new QGroupBox(verticalLayout_3);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    verticalLayout_2 = new QWidget(groupBox_2);
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    verticalLayout_2->setGeometry(QRect(10, 30, 110, 126));
    vboxLayout2 = new QVBoxLayout(verticalLayout_2);
    vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
    vboxLayout2->setContentsMargins(0, 0, 0, 0);
    addFilePushButton = new QPushButton(verticalLayout_2);
    addFilePushButton->setObjectName(QString::fromUtf8("addFilePushButton"));

    vboxLayout2->addWidget(addFilePushButton);

    extractFilePushButton = new QPushButton(verticalLayout_2);
    extractFilePushButton->setObjectName(QString::fromUtf8("extractFilePushButton"));

    vboxLayout2->addWidget(extractFilePushButton);

    openFilePushButton = new QPushButton(verticalLayout_2);
    openFilePushButton->setObjectName(QString::fromUtf8("openFilePushButton"));

    vboxLayout2->addWidget(openFilePushButton);

    closeFilePushButton = new QPushButton(verticalLayout_2);
    closeFilePushButton->setObjectName(QString::fromUtf8("closeFilePushButton"));

    vboxLayout2->addWidget(closeFilePushButton);


    vboxLayout->addWidget(groupBox_2);

    closePushButton = new QPushButton(verticalLayout_3);
    closePushButton->setObjectName(QString::fromUtf8("closePushButton"));

    vboxLayout->addWidget(closePushButton);


    retranslateUi(MpqDialog);

    QMetaObject::connectSlotsByName(MpqDialog);
    } // setupUi

    void retranslateUi(QWidget *MpqDialog)
    {
    MpqDialog->setWindowTitle(QApplication::translate("MpqDialog", "MPQ-Archivierer", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("MpqDialog", "MPQ-Archiv", 0, QApplication::UnicodeUTF8));
    createNewArchivePushButton->setText(QApplication::translate("MpqDialog", "Anlegen", 0, QApplication::UnicodeUTF8));
    openArchivePushButton->setText(QApplication::translate("MpqDialog", "\303\226ffnen", 0, QApplication::UnicodeUTF8));
    closeCurrentArchivePushButton->setText(QApplication::translate("MpqDialog", "Schlie\303\237en", 0, QApplication::UnicodeUTF8));
    groupBox_2->setTitle(QApplication::translate("MpqDialog", "Datei", 0, QApplication::UnicodeUTF8));
    addFilePushButton->setText(QApplication::translate("MpqDialog", "Hinzuf\303\274gen", 0, QApplication::UnicodeUTF8));
    extractFilePushButton->setText(QApplication::translate("MpqDialog", "Extrahieren", 0, QApplication::UnicodeUTF8));
    openFilePushButton->setText(QApplication::translate("MpqDialog", "\303\226ffnen", 0, QApplication::UnicodeUTF8));
    closeFilePushButton->setText(QApplication::translate("MpqDialog", "Entfernen", 0, QApplication::UnicodeUTF8));
    closePushButton->setText(QApplication::translate("MpqDialog", "Schlie\303\237en", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(MpqDialog);
    } // retranslateUi

};

namespace Ui {
    class MpqDialog: public Ui_MpqDialog {};
} // namespace Ui

#endif // UI_MPQDIALOG_H
