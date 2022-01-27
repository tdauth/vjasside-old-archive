/********************************************************************************
** Form generated from reading ui file 'pjassdialog.ui'
**
** Created: Sat Apr 4 13:48:20 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PJASSDIALOG_H
#define UI_PJASSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PjassDialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *selectPjassPushButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PjassDialog)
    {
        if (PjassDialog->objectName().isEmpty())
            PjassDialog->setObjectName(QString::fromUtf8("PjassDialog"));
        PjassDialog->resize(295, 64);
        PjassDialog->setModal(true);
        gridLayout = new QGridLayout(PjassDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        selectPjassPushButton = new QPushButton(PjassDialog);
        selectPjassPushButton->setObjectName(QString::fromUtf8("selectPjassPushButton"));

        gridLayout->addWidget(selectPjassPushButton, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(PjassDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok|QDialogButtonBox::RestoreDefaults);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(PjassDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PjassDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PjassDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PjassDialog);
    } // setupUi

    void retranslateUi(QDialog *PjassDialog)
    {
        PjassDialog->setWindowTitle(QApplication::translate("PjassDialog", "Jass-Syntax \303\274berpr\303\274fen", 0, QApplication::UnicodeUTF8));
        selectPjassPushButton->setText(QApplication::translate("PjassDialog", "pjass ausw\303\244hlen", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(PjassDialog);
    } // retranslateUi

};

namespace Ui {
    class PjassDialog: public Ui_PjassDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PJASSDIALOG_H
