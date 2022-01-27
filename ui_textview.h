/********************************************************************************
** Form generated from reading ui file 'textview.ui'
**
** Created: Sat Apr 4 13:48:20 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_TEXTVIEW_H
#define UI_TEXTVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QWidget>
#include "src/textedit.h"

QT_BEGIN_NAMESPACE

class Ui_TextView
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *hboxLayout;
    QListWidget *listWidget;
    vjasside::TextEdit *textEdit;

    void setupUi(QWidget *TextView)
    {
        if (TextView->objectName().isEmpty())
            TextView->setObjectName(QString::fromUtf8("TextView"));
        TextView->resize(522, 342);
        gridLayout = new QGridLayout(TextView);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        listWidget = new QListWidget(TextView);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMaximumSize(QSize(80, 16777215));
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        hboxLayout->addWidget(listWidget);

        textEdit = new vjasside::TextEdit(TextView);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setLineWrapMode(QTextEdit::FixedPixelWidth);
        textEdit->setLineWrapColumnOrWidth(65535);
        textEdit->setAcceptRichText(false);
        textEdit->setTextInteractionFlags(Qt::TextEditorInteraction);

        hboxLayout->addWidget(textEdit);


        gridLayout->addLayout(hboxLayout, 0, 0, 1, 1);


        retranslateUi(TextView);

        QMetaObject::connectSlotsByName(TextView);
    } // setupUi

    void retranslateUi(QWidget *TextView)
    {
        TextView->setWindowTitle(QApplication::translate("TextView", "Form", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(TextView);
    } // retranslateUi

};

namespace Ui {
    class TextView: public Ui_TextView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTVIEW_H
