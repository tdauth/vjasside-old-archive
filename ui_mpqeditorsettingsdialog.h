/********************************************************************************
** Form generated from reading ui file 'mpqeditorsettingsdialog.ui'
**
** Created: Sat Apr 4 13:48:20 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MPQEDITORSETTINGSDIALOG_H
#define UI_MPQEDITORSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_MpqEditorSettingsDialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MpqEditorSettingsDialog)
    {
        if (MpqEditorSettingsDialog->objectName().isEmpty())
            MpqEditorSettingsDialog->setObjectName(QString::fromUtf8("MpqEditorSettingsDialog"));
        MpqEditorSettingsDialog->setWindowModality(Qt::NonModal);
        MpqEditorSettingsDialog->resize(400, 300);
        const QIcon icon = QIcon(QString::fromUtf8(":/images/vjasside.png"));
        MpqEditorSettingsDialog->setWindowIcon(icon);
        MpqEditorSettingsDialog->setModal(true);
        buttonBox = new QDialogButtonBox(MpqEditorSettingsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(20, 260, 349, 28));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::RestoreDefaults|QDialogButtonBox::Save);

        retranslateUi(MpqEditorSettingsDialog);

        QMetaObject::connectSlotsByName(MpqEditorSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *MpqEditorSettingsDialog)
    {
        MpqEditorSettingsDialog->setWindowTitle(QApplication::translate("MpqEditorSettingsDialog", "Einstellungen", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MpqEditorSettingsDialog);
    } // retranslateUi

};

namespace Ui {
    class MpqEditorSettingsDialog: public Ui_MpqEditorSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MPQEDITORSETTINGSDIALOG_H
