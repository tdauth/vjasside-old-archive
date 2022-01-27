/********************************************************************************
** Form generated from reading ui file 'expressiondialog.ui'
**
** Created: Sat Dec 27 20:22:40 2008
**      by: Qt User Interface Compiler version 4.3.4
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_EXPRESSIONDIALOG_H
#define UI_EXPRESSIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>

class Ui_ExpressionDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QLabel *label;
    QLineEdit *expressionLineEdit;
    QComboBox *typeComboBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ExpressionDialog)
    {
    if (ExpressionDialog->objectName().isEmpty())
        ExpressionDialog->setObjectName(QString::fromUtf8("ExpressionDialog"));
    ExpressionDialog->setWindowModality(Qt::NonModal);
    ExpressionDialog->resize(185, 112);
    ExpressionDialog->setWindowIcon(QIcon(QString::fromUtf8(":/images/vjasside.png")));
    ExpressionDialog->setModal(true);
    gridLayout = new QGridLayout(ExpressionDialog);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    vboxLayout = new QVBoxLayout();
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    hboxLayout = new QHBoxLayout();
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    label = new QLabel(ExpressionDialog);
    label->setObjectName(QString::fromUtf8("label"));

    hboxLayout->addWidget(label);

    expressionLineEdit = new QLineEdit(ExpressionDialog);
    expressionLineEdit->setObjectName(QString::fromUtf8("expressionLineEdit"));

    hboxLayout->addWidget(expressionLineEdit);


    vboxLayout->addLayout(hboxLayout);

    typeComboBox = new QComboBox(ExpressionDialog);
    typeComboBox->setObjectName(QString::fromUtf8("typeComboBox"));

    vboxLayout->addWidget(typeComboBox);

    buttonBox = new QDialogButtonBox(ExpressionDialog);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

    vboxLayout->addWidget(buttonBox);


    gridLayout->addLayout(vboxLayout, 0, 0, 1, 1);


    retranslateUi(ExpressionDialog);
    QObject::connect(buttonBox, SIGNAL(accepted()), ExpressionDialog, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), ExpressionDialog, SLOT(reject()));

    QMetaObject::connectSlotsByName(ExpressionDialog);
    } // setupUi

    void retranslateUi(QDialog *ExpressionDialog)
    {
    ExpressionDialog->setWindowTitle(QApplication::translate("ExpressionDialog", "Ausdruck hinzuf\303\274gen", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("ExpressionDialog", "Ausdruck:", 0, QApplication::UnicodeUTF8));
    typeComboBox->clear();
    typeComboBox->insertItems(0, QStringList()
     << QApplication::translate("ExpressionDialog", "Normal", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("ExpressionDialog", "Einzeilig", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("ExpressionDialog", "Block", 0, QApplication::UnicodeUTF8)
    );
    Q_UNUSED(ExpressionDialog);
    } // retranslateUi

};

namespace Ui {
    class ExpressionDialog: public Ui_ExpressionDialog {};
} // namespace Ui

#endif // UI_EXPRESSIONDIALOG_H
