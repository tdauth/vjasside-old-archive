/********************************************************************************
** Form generated from reading ui file 'formatdialog.ui'
**
** Created: Sat Apr 4 13:48:20 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_FORMATDIALOG_H
#define UI_FORMATDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FormatDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *vboxLayout;
    QCheckBox *boldCheckBox;
    QCheckBox *italicCheckBox;
    QCheckBox *underlineCheckBox;
    QCheckBox *strikeOutCheckBox;
    QVBoxLayout *vboxLayout1;
    QPushButton *foregroundColorPushButton;
    QPushButton *backgroundColorPushButton;
    QTextBrowser *textBrowser;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *FormatDialog)
    {
        if (FormatDialog->objectName().isEmpty())
            FormatDialog->setObjectName(QString::fromUtf8("FormatDialog"));
        FormatDialog->resize(267, 249);
        gridLayout = new QGridLayout(FormatDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        vboxLayout = new QVBoxLayout();
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        boldCheckBox = new QCheckBox(FormatDialog);
        boldCheckBox->setObjectName(QString::fromUtf8("boldCheckBox"));

        vboxLayout->addWidget(boldCheckBox);

        italicCheckBox = new QCheckBox(FormatDialog);
        italicCheckBox->setObjectName(QString::fromUtf8("italicCheckBox"));

        vboxLayout->addWidget(italicCheckBox);

        underlineCheckBox = new QCheckBox(FormatDialog);
        underlineCheckBox->setObjectName(QString::fromUtf8("underlineCheckBox"));

        vboxLayout->addWidget(underlineCheckBox);

        strikeOutCheckBox = new QCheckBox(FormatDialog);
        strikeOutCheckBox->setObjectName(QString::fromUtf8("strikeOutCheckBox"));

        vboxLayout->addWidget(strikeOutCheckBox);


        gridLayout->addLayout(vboxLayout, 0, 0, 1, 1);

        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        foregroundColorPushButton = new QPushButton(FormatDialog);
        foregroundColorPushButton->setObjectName(QString::fromUtf8("foregroundColorPushButton"));

        vboxLayout1->addWidget(foregroundColorPushButton);

        backgroundColorPushButton = new QPushButton(FormatDialog);
        backgroundColorPushButton->setObjectName(QString::fromUtf8("backgroundColorPushButton"));

        vboxLayout1->addWidget(backgroundColorPushButton);


        gridLayout->addLayout(vboxLayout1, 0, 1, 1, 1);

        textBrowser = new QTextBrowser(FormatDialog);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout->addWidget(textBrowser, 1, 0, 1, 2);

        buttonBox = new QDialogButtonBox(FormatDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 2);


        retranslateUi(FormatDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), FormatDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FormatDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(FormatDialog);
    } // setupUi

    void retranslateUi(QDialog *FormatDialog)
    {
        FormatDialog->setWindowTitle(QApplication::translate("FormatDialog", "Format", 0, QApplication::UnicodeUTF8));
        boldCheckBox->setText(QApplication::translate("FormatDialog", "Fettgedruckt", 0, QApplication::UnicodeUTF8));
        italicCheckBox->setText(QApplication::translate("FormatDialog", "Kursiv", 0, QApplication::UnicodeUTF8));
        underlineCheckBox->setText(QApplication::translate("FormatDialog", "Unterstrichen", 0, QApplication::UnicodeUTF8));
        strikeOutCheckBox->setText(QApplication::translate("FormatDialog", "Durchgestrichen", 0, QApplication::UnicodeUTF8));
        foregroundColorPushButton->setText(QApplication::translate("FormatDialog", "Farbe", 0, QApplication::UnicodeUTF8));
        backgroundColorPushButton->setText(QApplication::translate("FormatDialog", "Hintergrundfarbe", 0, QApplication::UnicodeUTF8));
        textBrowser->setHtml(QApplication::translate("FormatDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Gr\303\274ner Mann zur sp\303\244ten Stunde, wollte nicht mal zu dem Hunde.</p></body></html>", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(FormatDialog);
    } // retranslateUi

};

namespace Ui {
    class FormatDialog: public Ui_FormatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMATDIALOG_H
