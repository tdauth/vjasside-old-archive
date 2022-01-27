/********************************************************************************
** Form generated from reading ui file 'vjassdocdialog.ui'
**
** Created: Sat Apr 4 13:48:20 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_VJASSDOCDIALOG_H
#define UI_VJASSDOCDIALOG_H

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
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_VjassdocDialog
{
public:
    QGridLayout *gridLayout;
    QGroupBox *titleGroupBox;
    QGridLayout *gridLayout1;
    QVBoxLayout *vboxLayout;
    QLabel *titleLabel;
    QLineEdit *titleLineEdit;
    QPushButton *chooseDirPushButton;
    QGroupBox *optionsGroupBox;
    QGridLayout *gridLayout2;
    QVBoxLayout *vboxLayout1;
    QPushButton *selectVjassdocPushButton;
    QCheckBox *jassCheckBox;
    QCheckBox *debugCheckBox;
    QCheckBox *privateCheckBox;
    QCheckBox *textmacrosCheckBox;
    QCheckBox *htmlCheckBox;
    QCheckBox *pagesCheckBox;
    QCheckBox *databaseCheckBox;
    QCheckBox *verboseCheckBox;
    QCheckBox *timeCheckBox;
    QCheckBox *alphabeticalCheckBox;
    QCheckBox *useCommonjCheckBox;
    QCheckBox *useCommonaiCheckBox;
    QCheckBox *useBlizzardjCheckBox;
    QGroupBox *objectGroupBox;
    QGridLayout *gridLayout3;
    QVBoxLayout *vboxLayout2;
    QCheckBox *commentCheckBox;
    QCheckBox *keywordCheckBox;
    QCheckBox *textMacroCheckBox;
    QCheckBox *textMacroInstanceCheckBox;
    QCheckBox *typeCheckBox;
    QCheckBox *globalCheckBox;
    QCheckBox *memberCheckBox;
    QCheckBox *functionInterfaceCheckBox;
    QCheckBox *functionCheckBox;
    QCheckBox *methodCheckBox;
    QCheckBox *interfaceCheckBox;
    QCheckBox *structCheckBox;
    QCheckBox *scopeCheckBox;
    QCheckBox *libraryCheckBox;
    QCheckBox *sourceFileCheckBox;
    QCheckBox *docCommentCheckBox;
    QCheckBox *allCheckBox;
    QGroupBox *importDirsGroupBox;
    QGridLayout *gridLayout4;
    QListWidget *importDirListWidget;
    QHBoxLayout *hboxLayout;
    QPushButton *addImportDirPushButton;
    QPushButton *removeImportDirsPushButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *VjassdocDialog)
    {
        if (VjassdocDialog->objectName().isEmpty())
            VjassdocDialog->setObjectName(QString::fromUtf8("VjassdocDialog"));
        VjassdocDialog->setWindowModality(Qt::NonModal);
        VjassdocDialog->resize(719, 538);
        const QIcon icon = QIcon(QString::fromUtf8(":/images/vjasside.png"));
        VjassdocDialog->setWindowIcon(icon);
        VjassdocDialog->setModal(true);
        gridLayout = new QGridLayout(VjassdocDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        titleGroupBox = new QGroupBox(VjassdocDialog);
        titleGroupBox->setObjectName(QString::fromUtf8("titleGroupBox"));
        gridLayout1 = new QGridLayout(titleGroupBox);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        vboxLayout = new QVBoxLayout();
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        titleLabel = new QLabel(titleGroupBox);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setAlignment(Qt::AlignCenter);

        vboxLayout->addWidget(titleLabel);

        titleLineEdit = new QLineEdit(titleGroupBox);
        titleLineEdit->setObjectName(QString::fromUtf8("titleLineEdit"));

        vboxLayout->addWidget(titleLineEdit);

        chooseDirPushButton = new QPushButton(titleGroupBox);
        chooseDirPushButton->setObjectName(QString::fromUtf8("chooseDirPushButton"));

        vboxLayout->addWidget(chooseDirPushButton);


        gridLayout1->addLayout(vboxLayout, 0, 0, 1, 1);


        gridLayout->addWidget(titleGroupBox, 0, 0, 1, 1);

        optionsGroupBox = new QGroupBox(VjassdocDialog);
        optionsGroupBox->setObjectName(QString::fromUtf8("optionsGroupBox"));
        gridLayout2 = new QGridLayout(optionsGroupBox);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        selectVjassdocPushButton = new QPushButton(optionsGroupBox);
        selectVjassdocPushButton->setObjectName(QString::fromUtf8("selectVjassdocPushButton"));

        vboxLayout1->addWidget(selectVjassdocPushButton);

        jassCheckBox = new QCheckBox(optionsGroupBox);
        jassCheckBox->setObjectName(QString::fromUtf8("jassCheckBox"));
        jassCheckBox->setChecked(false);
        jassCheckBox->setTristate(false);

        vboxLayout1->addWidget(jassCheckBox);

        debugCheckBox = new QCheckBox(optionsGroupBox);
        debugCheckBox->setObjectName(QString::fromUtf8("debugCheckBox"));

        vboxLayout1->addWidget(debugCheckBox);

        privateCheckBox = new QCheckBox(optionsGroupBox);
        privateCheckBox->setObjectName(QString::fromUtf8("privateCheckBox"));

        vboxLayout1->addWidget(privateCheckBox);

        textmacrosCheckBox = new QCheckBox(optionsGroupBox);
        textmacrosCheckBox->setObjectName(QString::fromUtf8("textmacrosCheckBox"));
        textmacrosCheckBox->setChecked(false);

        vboxLayout1->addWidget(textmacrosCheckBox);

        htmlCheckBox = new QCheckBox(optionsGroupBox);
        htmlCheckBox->setObjectName(QString::fromUtf8("htmlCheckBox"));
        htmlCheckBox->setChecked(false);

        vboxLayout1->addWidget(htmlCheckBox);

        pagesCheckBox = new QCheckBox(optionsGroupBox);
        pagesCheckBox->setObjectName(QString::fromUtf8("pagesCheckBox"));
        pagesCheckBox->setChecked(false);

        vboxLayout1->addWidget(pagesCheckBox);

        databaseCheckBox = new QCheckBox(optionsGroupBox);
        databaseCheckBox->setObjectName(QString::fromUtf8("databaseCheckBox"));

        vboxLayout1->addWidget(databaseCheckBox);

        verboseCheckBox = new QCheckBox(optionsGroupBox);
        verboseCheckBox->setObjectName(QString::fromUtf8("verboseCheckBox"));

        vboxLayout1->addWidget(verboseCheckBox);

        timeCheckBox = new QCheckBox(optionsGroupBox);
        timeCheckBox->setObjectName(QString::fromUtf8("timeCheckBox"));

        vboxLayout1->addWidget(timeCheckBox);

        alphabeticalCheckBox = new QCheckBox(optionsGroupBox);
        alphabeticalCheckBox->setObjectName(QString::fromUtf8("alphabeticalCheckBox"));
        alphabeticalCheckBox->setChecked(false);

        vboxLayout1->addWidget(alphabeticalCheckBox);

        useCommonjCheckBox = new QCheckBox(optionsGroupBox);
        useCommonjCheckBox->setObjectName(QString::fromUtf8("useCommonjCheckBox"));

        vboxLayout1->addWidget(useCommonjCheckBox);

        useCommonaiCheckBox = new QCheckBox(optionsGroupBox);
        useCommonaiCheckBox->setObjectName(QString::fromUtf8("useCommonaiCheckBox"));

        vboxLayout1->addWidget(useCommonaiCheckBox);

        useBlizzardjCheckBox = new QCheckBox(optionsGroupBox);
        useBlizzardjCheckBox->setObjectName(QString::fromUtf8("useBlizzardjCheckBox"));

        vboxLayout1->addWidget(useBlizzardjCheckBox);


        gridLayout2->addLayout(vboxLayout1, 0, 0, 1, 1);


        gridLayout->addWidget(optionsGroupBox, 0, 1, 2, 1);

        objectGroupBox = new QGroupBox(VjassdocDialog);
        objectGroupBox->setObjectName(QString::fromUtf8("objectGroupBox"));
        gridLayout3 = new QGridLayout(objectGroupBox);
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        commentCheckBox = new QCheckBox(objectGroupBox);
        commentCheckBox->setObjectName(QString::fromUtf8("commentCheckBox"));

        vboxLayout2->addWidget(commentCheckBox);

        keywordCheckBox = new QCheckBox(objectGroupBox);
        keywordCheckBox->setObjectName(QString::fromUtf8("keywordCheckBox"));

        vboxLayout2->addWidget(keywordCheckBox);

        textMacroCheckBox = new QCheckBox(objectGroupBox);
        textMacroCheckBox->setObjectName(QString::fromUtf8("textMacroCheckBox"));

        vboxLayout2->addWidget(textMacroCheckBox);

        textMacroInstanceCheckBox = new QCheckBox(objectGroupBox);
        textMacroInstanceCheckBox->setObjectName(QString::fromUtf8("textMacroInstanceCheckBox"));

        vboxLayout2->addWidget(textMacroInstanceCheckBox);

        typeCheckBox = new QCheckBox(objectGroupBox);
        typeCheckBox->setObjectName(QString::fromUtf8("typeCheckBox"));

        vboxLayout2->addWidget(typeCheckBox);

        globalCheckBox = new QCheckBox(objectGroupBox);
        globalCheckBox->setObjectName(QString::fromUtf8("globalCheckBox"));

        vboxLayout2->addWidget(globalCheckBox);

        memberCheckBox = new QCheckBox(objectGroupBox);
        memberCheckBox->setObjectName(QString::fromUtf8("memberCheckBox"));

        vboxLayout2->addWidget(memberCheckBox);

        functionInterfaceCheckBox = new QCheckBox(objectGroupBox);
        functionInterfaceCheckBox->setObjectName(QString::fromUtf8("functionInterfaceCheckBox"));

        vboxLayout2->addWidget(functionInterfaceCheckBox);

        functionCheckBox = new QCheckBox(objectGroupBox);
        functionCheckBox->setObjectName(QString::fromUtf8("functionCheckBox"));

        vboxLayout2->addWidget(functionCheckBox);

        methodCheckBox = new QCheckBox(objectGroupBox);
        methodCheckBox->setObjectName(QString::fromUtf8("methodCheckBox"));

        vboxLayout2->addWidget(methodCheckBox);

        interfaceCheckBox = new QCheckBox(objectGroupBox);
        interfaceCheckBox->setObjectName(QString::fromUtf8("interfaceCheckBox"));

        vboxLayout2->addWidget(interfaceCheckBox);

        structCheckBox = new QCheckBox(objectGroupBox);
        structCheckBox->setObjectName(QString::fromUtf8("structCheckBox"));

        vboxLayout2->addWidget(structCheckBox);

        scopeCheckBox = new QCheckBox(objectGroupBox);
        scopeCheckBox->setObjectName(QString::fromUtf8("scopeCheckBox"));

        vboxLayout2->addWidget(scopeCheckBox);

        libraryCheckBox = new QCheckBox(objectGroupBox);
        libraryCheckBox->setObjectName(QString::fromUtf8("libraryCheckBox"));

        vboxLayout2->addWidget(libraryCheckBox);

        sourceFileCheckBox = new QCheckBox(objectGroupBox);
        sourceFileCheckBox->setObjectName(QString::fromUtf8("sourceFileCheckBox"));

        vboxLayout2->addWidget(sourceFileCheckBox);

        docCommentCheckBox = new QCheckBox(objectGroupBox);
        docCommentCheckBox->setObjectName(QString::fromUtf8("docCommentCheckBox"));

        vboxLayout2->addWidget(docCommentCheckBox);

        allCheckBox = new QCheckBox(objectGroupBox);
        allCheckBox->setObjectName(QString::fromUtf8("allCheckBox"));

        vboxLayout2->addWidget(allCheckBox);


        gridLayout3->addLayout(vboxLayout2, 0, 0, 1, 1);


        gridLayout->addWidget(objectGroupBox, 0, 2, 2, 1);

        importDirsGroupBox = new QGroupBox(VjassdocDialog);
        importDirsGroupBox->setObjectName(QString::fromUtf8("importDirsGroupBox"));
        gridLayout4 = new QGridLayout(importDirsGroupBox);
        gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
        importDirListWidget = new QListWidget(importDirsGroupBox);
        importDirListWidget->setObjectName(QString::fromUtf8("importDirListWidget"));
        importDirListWidget->setSelectionMode(QAbstractItemView::MultiSelection);

        gridLayout4->addWidget(importDirListWidget, 0, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        addImportDirPushButton = new QPushButton(importDirsGroupBox);
        addImportDirPushButton->setObjectName(QString::fromUtf8("addImportDirPushButton"));
        addImportDirPushButton->setMaximumSize(QSize(16777215, 16777215));
        const QIcon icon1 = QIcon(QString::fromUtf8(":/images/actions/list-add.png"));
        addImportDirPushButton->setIcon(icon1);

        hboxLayout->addWidget(addImportDirPushButton);

        removeImportDirsPushButton = new QPushButton(importDirsGroupBox);
        removeImportDirsPushButton->setObjectName(QString::fromUtf8("removeImportDirsPushButton"));
        removeImportDirsPushButton->setMaximumSize(QSize(16777215, 16777215));
        const QIcon icon2 = QIcon(QString::fromUtf8(":/images/actions/list-remove.png"));
        removeImportDirsPushButton->setIcon(icon2);

        hboxLayout->addWidget(removeImportDirsPushButton);


        gridLayout4->addLayout(hboxLayout, 1, 0, 1, 1);


        gridLayout->addWidget(importDirsGroupBox, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(VjassdocDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok|QDialogButtonBox::RestoreDefaults);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 3);


        retranslateUi(VjassdocDialog);
        QObject::connect(htmlCheckBox, SIGNAL(clicked(bool)), pagesCheckBox, SLOT(setEnabled(bool)));
        QObject::connect(buttonBox, SIGNAL(accepted()), VjassdocDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), VjassdocDialog, SLOT(reject()));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), docCommentCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), sourceFileCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), libraryCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), scopeCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), structCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), interfaceCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), methodCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), functionCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), functionInterfaceCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), memberCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), globalCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), typeCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), textMacroInstanceCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), textMacroCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), keywordCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), commentCheckBox, SLOT(setChecked(bool)));

        QMetaObject::connectSlotsByName(VjassdocDialog);
    } // setupUi

    void retranslateUi(QDialog *VjassdocDialog)
    {
        VjassdocDialog->setWindowTitle(QApplication::translate("VjassdocDialog", "API-Dokumentation erstellen", 0, QApplication::UnicodeUTF8));
        titleGroupBox->setTitle(QApplication::translate("VjassdocDialog", "Ausgabe", 0, QApplication::UnicodeUTF8));
        titleLabel->setText(QApplication::translate("VjassdocDialog", "Titel", 0, QApplication::UnicodeUTF8));
        titleLineEdit->setText(QApplication::translate("VjassdocDialog", "vJass-API", 0, QApplication::UnicodeUTF8));
        chooseDirPushButton->setText(QApplication::translate("VjassdocDialog", "Ausgabeverzeichnis w\303\244hlen", 0, QApplication::UnicodeUTF8));
        optionsGroupBox->setTitle(QApplication::translate("VjassdocDialog", "Optionen", 0, QApplication::UnicodeUTF8));
        selectVjassdocPushButton->setText(QApplication::translate("VjassdocDialog", "vjassdoc ausw\303\244hlen", 0, QApplication::UnicodeUTF8));
        jassCheckBox->setText(QApplication::translate("VjassdocDialog", "Nur Jass", 0, QApplication::UnicodeUTF8));
        debugCheckBox->setText(QApplication::translate("VjassdocDialog", "Debug-Modus", 0, QApplication::UnicodeUTF8));
        privateCheckBox->setText(QApplication::translate("VjassdocDialog", "Private Objekte erfassen", 0, QApplication::UnicodeUTF8));
        textmacrosCheckBox->setText(QApplication::translate("VjassdocDialog", "Textmakro-Bereiche erfassen", 0, QApplication::UnicodeUTF8));
        htmlCheckBox->setText(QApplication::translate("VjassdocDialog", "HTML-Datei anlegen", 0, QApplication::UnicodeUTF8));
        pagesCheckBox->setText(QApplication::translate("VjassdocDialog", "HTML-Seiten anlegen", 0, QApplication::UnicodeUTF8));
        databaseCheckBox->setText(QApplication::translate("VjassdocDialog", "Datenbank anlegen", 0, QApplication::UnicodeUTF8));
        verboseCheckBox->setText(QApplication::translate("VjassdocDialog", "Textreiche Ausgabe", 0, QApplication::UnicodeUTF8));
        timeCheckBox->setText(QApplication::translate("VjassdocDialog", "Zeit-Ausgabe", 0, QApplication::UnicodeUTF8));
        alphabeticalCheckBox->setText(QApplication::translate("VjassdocDialog", "Alphabetisch sortieren", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        useCommonjCheckBox->setToolTip(QApplication::translate("VjassdocDialog", "Die common.j-Datei enth\303\244lt die Deklarationen aller nativen Grundfunktionen der Skriptsprache Jass.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        useCommonjCheckBox->setText(QApplication::translate("VjassdocDialog", "common.j verwenden", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        useCommonaiCheckBox->setToolTip(QApplication::translate("VjassdocDialog", "Die common.ai-Datei enth\303\244lt alle standardm\303\244\303\237igen Funktionen bez\303\274glich der k\303\274nstlichen Intelligenz in Warcraft 3.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        useCommonaiCheckBox->setText(QApplication::translate("VjassdocDialog", "common.ai verwenden", 0, QApplication::UnicodeUTF8));
        useBlizzardjCheckBox->setText(QApplication::translate("VjassdocDialog", "Blizzard.j verwenden", 0, QApplication::UnicodeUTF8));
        objectGroupBox->setTitle(QApplication::translate("VjassdocDialog", "Objekte", 0, QApplication::UnicodeUTF8));
        commentCheckBox->setText(QApplication::translate("VjassdocDialog", "Kommentare", 0, QApplication::UnicodeUTF8));
        keywordCheckBox->setText(QApplication::translate("VjassdocDialog", "Schl\303\274sselw\303\266rter", 0, QApplication::UnicodeUTF8));
        textMacroCheckBox->setText(QApplication::translate("VjassdocDialog", "Textmakros", 0, QApplication::UnicodeUTF8));
        textMacroInstanceCheckBox->setText(QApplication::translate("VjassdocDialog", "Textmakro-Instanzen", 0, QApplication::UnicodeUTF8));
        typeCheckBox->setText(QApplication::translate("VjassdocDialog", "Typen", 0, QApplication::UnicodeUTF8));
        globalCheckBox->setText(QApplication::translate("VjassdocDialog", "Globale", 0, QApplication::UnicodeUTF8));
        memberCheckBox->setText(QApplication::translate("VjassdocDialog", "Elemente", 0, QApplication::UnicodeUTF8));
        functionInterfaceCheckBox->setText(QApplication::translate("VjassdocDialog", "Funktionsschnittstellen", 0, QApplication::UnicodeUTF8));
        functionCheckBox->setText(QApplication::translate("VjassdocDialog", "Funktionen", 0, QApplication::UnicodeUTF8));
        methodCheckBox->setText(QApplication::translate("VjassdocDialog", "Methoden", 0, QApplication::UnicodeUTF8));
        interfaceCheckBox->setText(QApplication::translate("VjassdocDialog", "Schnittstellen", 0, QApplication::UnicodeUTF8));
        structCheckBox->setText(QApplication::translate("VjassdocDialog", "Strukturen", 0, QApplication::UnicodeUTF8));
        scopeCheckBox->setText(QApplication::translate("VjassdocDialog", "Bezugsrahmen", 0, QApplication::UnicodeUTF8));
        libraryCheckBox->setText(QApplication::translate("VjassdocDialog", "Bibliotheken", 0, QApplication::UnicodeUTF8));
        sourceFileCheckBox->setText(QApplication::translate("VjassdocDialog", "Quell-Dateien", 0, QApplication::UnicodeUTF8));
        docCommentCheckBox->setText(QApplication::translate("VjassdocDialog", "Dokumentationskommentare", 0, QApplication::UnicodeUTF8));
        allCheckBox->setText(QApplication::translate("VjassdocDialog", "Alle", 0, QApplication::UnicodeUTF8));
        importDirsGroupBox->setTitle(QApplication::translate("VjassdocDialog", "Import-Verzeichnisse", 0, QApplication::UnicodeUTF8));
        addImportDirPushButton->setText(QApplication::translate("VjassdocDialog", "Hinzuf\303\274gen", 0, QApplication::UnicodeUTF8));
        removeImportDirsPushButton->setText(QApplication::translate("VjassdocDialog", "Entfernen", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(VjassdocDialog);
    } // retranslateUi

};

namespace Ui {
    class VjassdocDialog: public Ui_VjassdocDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VJASSDOCDIALOG_H
