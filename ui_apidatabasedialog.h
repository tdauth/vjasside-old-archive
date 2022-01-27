/********************************************************************************
** Form generated from reading ui file 'apidatabasedialog.ui'
**
** Created: Sat Apr 4 13:48:19 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_APIDATABASEDIALOG_H
#define UI_APIDATABASEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
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

class Ui_ApiDatabaseDialog
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout1;
    QVBoxLayout *vboxLayout;
    QListWidget *listWidget;
    QHBoxLayout *hboxLayout;
    QPushButton *addDatabasesPushButton;
    QPushButton *removeDatabasesPushButton;
    QGroupBox *objectActionsGroupBox;
    QGridLayout *gridLayout2;
    QVBoxLayout *vboxLayout1;
    QPushButton *addObjectPushButton;
    QPushButton *removeObjectPushButton;
    QPushButton *editObjectPushButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ApiDatabaseDialog)
    {
        if (ApiDatabaseDialog->objectName().isEmpty())
            ApiDatabaseDialog->setObjectName(QString::fromUtf8("ApiDatabaseDialog"));
        ApiDatabaseDialog->resize(409, 311);
        gridLayout = new QGridLayout(ApiDatabaseDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(ApiDatabaseDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout1 = new QGridLayout(groupBox);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        vboxLayout = new QVBoxLayout();
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        listWidget = new QListWidget(groupBox);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setSelectionMode(QAbstractItemView::MultiSelection);

        vboxLayout->addWidget(listWidget);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        addDatabasesPushButton = new QPushButton(groupBox);
        addDatabasesPushButton->setObjectName(QString::fromUtf8("addDatabasesPushButton"));
        const QIcon icon = QIcon(QString::fromUtf8(":/images/actions/list-add.png"));
        addDatabasesPushButton->setIcon(icon);

        hboxLayout->addWidget(addDatabasesPushButton);

        removeDatabasesPushButton = new QPushButton(groupBox);
        removeDatabasesPushButton->setObjectName(QString::fromUtf8("removeDatabasesPushButton"));
        removeDatabasesPushButton->setEnabled(false);
        const QIcon icon1 = QIcon(QString::fromUtf8(":/images/actions/list-remove.png"));
        removeDatabasesPushButton->setIcon(icon1);

        hboxLayout->addWidget(removeDatabasesPushButton);


        vboxLayout->addLayout(hboxLayout);


        gridLayout1->addLayout(vboxLayout, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        objectActionsGroupBox = new QGroupBox(ApiDatabaseDialog);
        objectActionsGroupBox->setObjectName(QString::fromUtf8("objectActionsGroupBox"));
        objectActionsGroupBox->setEnabled(false);
        gridLayout2 = new QGridLayout(objectActionsGroupBox);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        addObjectPushButton = new QPushButton(objectActionsGroupBox);
        addObjectPushButton->setObjectName(QString::fromUtf8("addObjectPushButton"));
        addObjectPushButton->setIcon(icon);

        vboxLayout1->addWidget(addObjectPushButton);

        removeObjectPushButton = new QPushButton(objectActionsGroupBox);
        removeObjectPushButton->setObjectName(QString::fromUtf8("removeObjectPushButton"));
        removeObjectPushButton->setIcon(icon1);

        vboxLayout1->addWidget(removeObjectPushButton);

        editObjectPushButton = new QPushButton(objectActionsGroupBox);
        editObjectPushButton->setObjectName(QString::fromUtf8("editObjectPushButton"));

        vboxLayout1->addWidget(editObjectPushButton);


        gridLayout2->addLayout(vboxLayout1, 0, 0, 1, 1);


        gridLayout->addWidget(objectActionsGroupBox, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(ApiDatabaseDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::RestoreDefaults|QDialogButtonBox::Save);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 2);


        retranslateUi(ApiDatabaseDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ApiDatabaseDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ApiDatabaseDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ApiDatabaseDialog);
    } // setupUi

    void retranslateUi(QDialog *ApiDatabaseDialog)
    {
        ApiDatabaseDialog->setWindowTitle(QApplication::translate("ApiDatabaseDialog", "API-Datenbanken", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ApiDatabaseDialog", "API-Datenbanken", 0, QApplication::UnicodeUTF8));
        addDatabasesPushButton->setText(QApplication::translate("ApiDatabaseDialog", "Hinzuf\303\274gen", 0, QApplication::UnicodeUTF8));
        removeDatabasesPushButton->setText(QApplication::translate("ApiDatabaseDialog", "Entfernen", 0, QApplication::UnicodeUTF8));
        objectActionsGroupBox->setTitle(QApplication::translate("ApiDatabaseDialog", "Objekt-Aktionen", 0, QApplication::UnicodeUTF8));
        addObjectPushButton->setText(QApplication::translate("ApiDatabaseDialog", "Hinzuf\303\274gen", 0, QApplication::UnicodeUTF8));
        removeObjectPushButton->setText(QApplication::translate("ApiDatabaseDialog", "Entfernen", 0, QApplication::UnicodeUTF8));
        editObjectPushButton->setText(QApplication::translate("ApiDatabaseDialog", "Bearbeiten", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(ApiDatabaseDialog);
    } // retranslateUi

};

namespace Ui {
    class ApiDatabaseDialog: public Ui_ApiDatabaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APIDATABASEDIALOG_H
