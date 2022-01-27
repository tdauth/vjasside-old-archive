/********************************************************************************
** Form generated from reading ui file 'editorsettingsdialog.ui'
**
** Created: Sat Apr 4 13:48:20 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_EDITORSETTINGSDIALOG_H
#define UI_EDITORSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditorSettingsDialog
{
public:
    QTabWidget *tabWidget;
    QWidget *editor;
    QGridLayout *gridLayout;
    QVBoxLayout *vboxLayout;
    QCheckBox *showLineNumbersCheckBox;
    QCheckBox *automaticIndentionCheckBox;
    QHBoxLayout *hboxLayout;
    QLabel *tabStopWidthLabel;
    QSpacerItem *spacerItem;
    QSpinBox *tabStopWidthSpinBox;
    QCheckBox *closeFilesWhenCreatingANewSessionCheckBox;
    QPushButton *selectFontPushButton;
    QWidget *scriptingLanguage;
    QGridLayout *gridLayout1;
    QGroupBox *syntaxSchemataGroupBox;
    QGridLayout *gridLayout2;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout1;
    QLabel *schemaLabel;
    QComboBox *schemaComboBox;
    QPushButton *newSchemaPushButton;
    QPushButton *deleteSchemaPushButton;
    QPushButton *renameSchemaPushButton;
    QPushButton *importSchemaPushButton;
    QPushButton *exportSchemaPushButton;
    QHBoxLayout *hboxLayout2;
    QLabel *formatLabel;
    QComboBox *formatComboBox;
    QPushButton *formatPushButton;
    QGroupBox *templateGroupBox;
    QGridLayout *gridLayout3;
    QListWidget *templateListWidget;
    QPushButton *addTemplatePushButton;
    QPushButton *removeTemplatesPushButton;
    QPushButton *editTemplatePushButton;
    QGroupBox *listGroupBox;
    QGridLayout *gridLayout4;
    QListWidget *listListWidget;
    QPushButton *editListPushButton;
    QWidget *shortcuts;
    QGroupBox *groupBox;
    QGridLayout *gridLayout5;
    QHBoxLayout *hboxLayout3;
    QRadioButton *noneRadioButton;
    QRadioButton *standardRadioButton;
    QRadioButton *userDefinedRadioButtom;
    QPushButton *shortcutPushButton;
    QSpacerItem *spacerItem1;
    QTreeWidget *shortcutTreeWidget;
    QDialogButtonBox *dialogButtonBox;

    void setupUi(QDialog *EditorSettingsDialog)
    {
        if (EditorSettingsDialog->objectName().isEmpty())
            EditorSettingsDialog->setObjectName(QString::fromUtf8("EditorSettingsDialog"));
        EditorSettingsDialog->resize(645, 366);
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8(":/images/vjasside.png")), QIcon::Normal, QIcon::Off);
        EditorSettingsDialog->setWindowIcon(icon);
        EditorSettingsDialog->setSizeGripEnabled(false);
        EditorSettingsDialog->setModal(true);
        tabWidget = new QTabWidget(EditorSettingsDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(9, 9, 627, 310));
        editor = new QWidget();
        editor->setObjectName(QString::fromUtf8("editor"));
        gridLayout = new QGridLayout(editor);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        vboxLayout = new QVBoxLayout();
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        showLineNumbersCheckBox = new QCheckBox(editor);
        showLineNumbersCheckBox->setObjectName(QString::fromUtf8("showLineNumbersCheckBox"));

        vboxLayout->addWidget(showLineNumbersCheckBox);

        automaticIndentionCheckBox = new QCheckBox(editor);
        automaticIndentionCheckBox->setObjectName(QString::fromUtf8("automaticIndentionCheckBox"));

        vboxLayout->addWidget(automaticIndentionCheckBox);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        tabStopWidthLabel = new QLabel(editor);
        tabStopWidthLabel->setObjectName(QString::fromUtf8("tabStopWidthLabel"));

        hboxLayout->addWidget(tabStopWidthLabel);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        tabStopWidthSpinBox = new QSpinBox(editor);
        tabStopWidthSpinBox->setObjectName(QString::fromUtf8("tabStopWidthSpinBox"));

        hboxLayout->addWidget(tabStopWidthSpinBox);


        vboxLayout->addLayout(hboxLayout);

        closeFilesWhenCreatingANewSessionCheckBox = new QCheckBox(editor);
        closeFilesWhenCreatingANewSessionCheckBox->setObjectName(QString::fromUtf8("closeFilesWhenCreatingANewSessionCheckBox"));

        vboxLayout->addWidget(closeFilesWhenCreatingANewSessionCheckBox);

        selectFontPushButton = new QPushButton(editor);
        selectFontPushButton->setObjectName(QString::fromUtf8("selectFontPushButton"));

        vboxLayout->addWidget(selectFontPushButton);


        gridLayout->addLayout(vboxLayout, 0, 0, 1, 1);

        tabWidget->addTab(editor, QString());
        scriptingLanguage = new QWidget();
        scriptingLanguage->setObjectName(QString::fromUtf8("scriptingLanguage"));
        gridLayout1 = new QGridLayout(scriptingLanguage);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        syntaxSchemataGroupBox = new QGroupBox(scriptingLanguage);
        syntaxSchemataGroupBox->setObjectName(QString::fromUtf8("syntaxSchemataGroupBox"));
        gridLayout2 = new QGridLayout(syntaxSchemataGroupBox);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        schemaLabel = new QLabel(syntaxSchemataGroupBox);
        schemaLabel->setObjectName(QString::fromUtf8("schemaLabel"));

        hboxLayout1->addWidget(schemaLabel);

        schemaComboBox = new QComboBox(syntaxSchemataGroupBox);
        schemaComboBox->setObjectName(QString::fromUtf8("schemaComboBox"));

        hboxLayout1->addWidget(schemaComboBox);

        newSchemaPushButton = new QPushButton(syntaxSchemataGroupBox);
        newSchemaPushButton->setObjectName(QString::fromUtf8("newSchemaPushButton"));

        hboxLayout1->addWidget(newSchemaPushButton);

        deleteSchemaPushButton = new QPushButton(syntaxSchemataGroupBox);
        deleteSchemaPushButton->setObjectName(QString::fromUtf8("deleteSchemaPushButton"));

        hboxLayout1->addWidget(deleteSchemaPushButton);

        renameSchemaPushButton = new QPushButton(syntaxSchemataGroupBox);
        renameSchemaPushButton->setObjectName(QString::fromUtf8("renameSchemaPushButton"));

        hboxLayout1->addWidget(renameSchemaPushButton);

        importSchemaPushButton = new QPushButton(syntaxSchemataGroupBox);
        importSchemaPushButton->setObjectName(QString::fromUtf8("importSchemaPushButton"));

        hboxLayout1->addWidget(importSchemaPushButton);

        exportSchemaPushButton = new QPushButton(syntaxSchemataGroupBox);
        exportSchemaPushButton->setObjectName(QString::fromUtf8("exportSchemaPushButton"));

        hboxLayout1->addWidget(exportSchemaPushButton);


        vboxLayout1->addLayout(hboxLayout1);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        formatLabel = new QLabel(syntaxSchemataGroupBox);
        formatLabel->setObjectName(QString::fromUtf8("formatLabel"));

        hboxLayout2->addWidget(formatLabel);

        formatComboBox = new QComboBox(syntaxSchemataGroupBox);
        formatComboBox->setObjectName(QString::fromUtf8("formatComboBox"));

        hboxLayout2->addWidget(formatComboBox);

        formatPushButton = new QPushButton(syntaxSchemataGroupBox);
        formatPushButton->setObjectName(QString::fromUtf8("formatPushButton"));

        hboxLayout2->addWidget(formatPushButton);


        vboxLayout1->addLayout(hboxLayout2);


        gridLayout2->addLayout(vboxLayout1, 0, 0, 1, 2);

        templateGroupBox = new QGroupBox(syntaxSchemataGroupBox);
        templateGroupBox->setObjectName(QString::fromUtf8("templateGroupBox"));
        gridLayout3 = new QGridLayout(templateGroupBox);
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        templateListWidget = new QListWidget(templateGroupBox);
        templateListWidget->setObjectName(QString::fromUtf8("templateListWidget"));
        templateListWidget->setSpacing(0);
        templateListWidget->setModelColumn(0);

        gridLayout3->addWidget(templateListWidget, 0, 0, 1, 3);

        addTemplatePushButton = new QPushButton(templateGroupBox);
        addTemplatePushButton->setObjectName(QString::fromUtf8("addTemplatePushButton"));
        QIcon icon1;
        icon1.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/list-add.png")), QIcon::Normal, QIcon::Off);
        addTemplatePushButton->setIcon(icon1);

        gridLayout3->addWidget(addTemplatePushButton, 1, 0, 1, 1);

        removeTemplatesPushButton = new QPushButton(templateGroupBox);
        removeTemplatesPushButton->setObjectName(QString::fromUtf8("removeTemplatesPushButton"));
        QIcon icon2;
        icon2.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/list-remove.png")), QIcon::Normal, QIcon::Off);
        removeTemplatesPushButton->setIcon(icon2);

        gridLayout3->addWidget(removeTemplatesPushButton, 1, 2, 1, 1);

        editTemplatePushButton = new QPushButton(templateGroupBox);
        editTemplatePushButton->setObjectName(QString::fromUtf8("editTemplatePushButton"));

        gridLayout3->addWidget(editTemplatePushButton, 1, 1, 1, 1);


        gridLayout2->addWidget(templateGroupBox, 1, 0, 1, 1);

        listGroupBox = new QGroupBox(syntaxSchemataGroupBox);
        listGroupBox->setObjectName(QString::fromUtf8("listGroupBox"));
        gridLayout4 = new QGridLayout(listGroupBox);
        gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
        listListWidget = new QListWidget(listGroupBox);
        listListWidget->setObjectName(QString::fromUtf8("listListWidget"));

        gridLayout4->addWidget(listListWidget, 0, 0, 1, 1);

        editListPushButton = new QPushButton(listGroupBox);
        editListPushButton->setObjectName(QString::fromUtf8("editListPushButton"));

        gridLayout4->addWidget(editListPushButton, 1, 0, 1, 1);


        gridLayout2->addWidget(listGroupBox, 1, 1, 1, 1);


        gridLayout1->addWidget(syntaxSchemataGroupBox, 0, 0, 1, 1);

        tabWidget->addTab(scriptingLanguage, QString());
        shortcuts = new QWidget();
        shortcuts->setObjectName(QString::fromUtf8("shortcuts"));
        groupBox = new QGroupBox(shortcuts);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(9, 206, 605, 68));
        gridLayout5 = new QGridLayout(groupBox);
        gridLayout5->setObjectName(QString::fromUtf8("gridLayout5"));
        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        noneRadioButton = new QRadioButton(groupBox);
        noneRadioButton->setObjectName(QString::fromUtf8("noneRadioButton"));

        hboxLayout3->addWidget(noneRadioButton);

        standardRadioButton = new QRadioButton(groupBox);
        standardRadioButton->setObjectName(QString::fromUtf8("standardRadioButton"));

        hboxLayout3->addWidget(standardRadioButton);

        userDefinedRadioButtom = new QRadioButton(groupBox);
        userDefinedRadioButtom->setObjectName(QString::fromUtf8("userDefinedRadioButtom"));

        hboxLayout3->addWidget(userDefinedRadioButtom);

        shortcutPushButton = new QPushButton(groupBox);
        shortcutPushButton->setObjectName(QString::fromUtf8("shortcutPushButton"));

        hboxLayout3->addWidget(shortcutPushButton);

        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout3->addItem(spacerItem1);


        gridLayout5->addLayout(hboxLayout3, 0, 0, 1, 1);

        shortcutTreeWidget = new QTreeWidget(shortcuts);
        shortcutTreeWidget->setObjectName(QString::fromUtf8("shortcutTreeWidget"));
        shortcutTreeWidget->setGeometry(QRect(10, 10, 601, 192));
        tabWidget->addTab(shortcuts, QString());
        dialogButtonBox = new QDialogButtonBox(EditorSettingsDialog);
        dialogButtonBox->setObjectName(QString::fromUtf8("dialogButtonBox"));
        dialogButtonBox->setGeometry(QRect(9, 325, 627, 32));
        dialogButtonBox->setOrientation(Qt::Horizontal);
        dialogButtonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::RestoreDefaults|QDialogButtonBox::Save);
        QWidget::setTabOrder(tabWidget, schemaComboBox);
        QWidget::setTabOrder(schemaComboBox, newSchemaPushButton);
        QWidget::setTabOrder(newSchemaPushButton, deleteSchemaPushButton);
        QWidget::setTabOrder(deleteSchemaPushButton, dialogButtonBox);

        retranslateUi(EditorSettingsDialog);
        QObject::connect(dialogButtonBox, SIGNAL(accepted()), EditorSettingsDialog, SLOT(accept()));
        QObject::connect(dialogButtonBox, SIGNAL(rejected()), EditorSettingsDialog, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(EditorSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *EditorSettingsDialog)
    {
        EditorSettingsDialog->setWindowTitle(QApplication::translate("EditorSettingsDialog", "Editor-Einstellungen", 0, QApplication::UnicodeUTF8));
        showLineNumbersCheckBox->setText(QApplication::translate("EditorSettingsDialog", "Zeige Zeilennummern", 0, QApplication::UnicodeUTF8));
        automaticIndentionCheckBox->setText(QApplication::translate("EditorSettingsDialog", "Automatisches Einr\303\274cken", 0, QApplication::UnicodeUTF8));
        tabStopWidthLabel->setText(QApplication::translate("EditorSettingsDialog", "Tabulatorenbreite:", 0, QApplication::UnicodeUTF8));
        closeFilesWhenCreatingANewSessionCheckBox->setText(QApplication::translate("EditorSettingsDialog", "Schlie\303\237e alle Dateien, wenn neue Sitzung erstellt wird", 0, QApplication::UnicodeUTF8));
        selectFontPushButton->setText(QApplication::translate("EditorSettingsDialog", "Schriftart w\303\244hlen", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(editor), QApplication::translate("EditorSettingsDialog", "Editor", 0, QApplication::UnicodeUTF8));
        syntaxSchemataGroupBox->setTitle(QApplication::translate("EditorSettingsDialog", "Syntax-Schemas", 0, QApplication::UnicodeUTF8));
        schemaLabel->setText(QApplication::translate("EditorSettingsDialog", "Schema:", 0, QApplication::UnicodeUTF8));
        newSchemaPushButton->setText(QApplication::translate("EditorSettingsDialog", "Neu", 0, QApplication::UnicodeUTF8));
        deleteSchemaPushButton->setText(QApplication::translate("EditorSettingsDialog", "L\303\266schen", 0, QApplication::UnicodeUTF8));
        renameSchemaPushButton->setText(QApplication::translate("EditorSettingsDialog", "Umbenennen", 0, QApplication::UnicodeUTF8));
        importSchemaPushButton->setText(QApplication::translate("EditorSettingsDialog", "Importieren", 0, QApplication::UnicodeUTF8));
        exportSchemaPushButton->setText(QApplication::translate("EditorSettingsDialog", "Exportieren", 0, QApplication::UnicodeUTF8));
        formatLabel->setText(QApplication::translate("EditorSettingsDialog", "Format:", 0, QApplication::UnicodeUTF8));
        formatComboBox->clear();
        formatComboBox->insertItems(0, QStringList()
         << QApplication::translate("EditorSettingsDialog", "Text", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditorSettingsDialog", "Ganzzahl", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditorSettingsDialog", "Flie\303\237kommazahl", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditorSettingsDialog", "Schriftzeichen", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditorSettingsDialog", "Zeichenkette", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditorSettingsDialog", "Kommentar", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditorSettingsDialog", "Operator", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditorSettingsDialog", "Schl\303\274sselwort", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditorSettingsDialog", "vJass-Schl\303\274sselwort", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditorSettingsDialog", "Pr\303\244prozessor", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditorSettingsDialog", "Pr\303\244prozessor-Schl\303\274sselwort", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditorSettingsDialog", "Pr\303\244prozessor-Argument", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditorSettingsDialog", "Dokumentationskommentar", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditorSettingsDialog", "Dokumentationskommentar-Schl\303\274sselwort", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditorSettingsDialog", "Dokumentationskommentar-Ausdruck", 0, QApplication::UnicodeUTF8)
        );
        formatPushButton->setText(QApplication::translate("EditorSettingsDialog", "Format", 0, QApplication::UnicodeUTF8));
        templateGroupBox->setTitle(QApplication::translate("EditorSettingsDialog", "Vorlagen", 0, QApplication::UnicodeUTF8));
        addTemplatePushButton->setText(QApplication::translate("EditorSettingsDialog", "Hinzuf\303\274gen", 0, QApplication::UnicodeUTF8));
        removeTemplatesPushButton->setText(QApplication::translate("EditorSettingsDialog", "Entfernen", 0, QApplication::UnicodeUTF8));
        editTemplatePushButton->setText(QApplication::translate("EditorSettingsDialog", "Bearbeiten", 0, QApplication::UnicodeUTF8));
        listGroupBox->setTitle(QApplication::translate("EditorSettingsDialog", "Listen", 0, QApplication::UnicodeUTF8));
        editListPushButton->setText(QApplication::translate("EditorSettingsDialog", "Bearbeiten", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(scriptingLanguage), QApplication::translate("EditorSettingsDialog", "Skriptsprache", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("EditorSettingsDialog", "Tastenkombination", 0, QApplication::UnicodeUTF8));
        noneRadioButton->setText(QApplication::translate("EditorSettingsDialog", "Kein", 0, QApplication::UnicodeUTF8));
        standardRadioButton->setText(QApplication::translate("EditorSettingsDialog", "Standard", 0, QApplication::UnicodeUTF8));
        userDefinedRadioButtom->setText(QApplication::translate("EditorSettingsDialog", "Benutzerdefiniert", 0, QApplication::UnicodeUTF8));
        shortcutPushButton->setText(QString());
        QTreeWidgetItem *___qtreewidgetitem = shortcutTreeWidget->headerItem();
        ___qtreewidgetitem->setText(2, QApplication::translate("EditorSettingsDialog", "Alternative", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("EditorSettingsDialog", "Tastenk\303\274rzel", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("EditorSettingsDialog", "Aktion", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(shortcuts), QApplication::translate("EditorSettingsDialog", "Tastenk\303\274rzel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(EditorSettingsDialog);
    } // retranslateUi

};

namespace Ui {
    class EditorSettingsDialog: public Ui_EditorSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITORSETTINGSDIALOG_H
