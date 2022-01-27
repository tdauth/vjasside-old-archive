/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Fri Apr 10 21:06:07 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDockWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *saveAllAction;
    QAction *reloadAction;
    QAction *revertAllAction;
    QAction *printAction;
    QAction *exportAsHtmlAction;
    QAction *closeAction;
    QAction *closeAllAction;
    QAction *closeAllOtherAction;
    QAction *quitAction;
    QAction *undoAction;
    QAction *redoAction;
    QAction *cutAction;
    QAction *copyAction;
    QAction *copyAsHtmlAction;
    QAction *pasteAction;
    QAction *selectAllAction;
    QAction *deselectAction;
    QAction *blockSelectionModeAction;
    QAction *overwriteModeAction;
    QAction *findAction;
    QAction *findNextAction;
    QAction *findPreviousAction;
    QAction *replaceAction;
    QAction *goToLineAction;
    QAction *findInFilesAction;
    QAction *findSelectReplaceAction;
    QAction *expandTextAction;
    QAction *expandAbbreviationAction;
    QAction *backAction;
    QAction *forwardAction;
    QAction *gotoLastEditPositionAction;
    QAction *raiseEditorAction;
    QAction *nextErrorAction;
    QAction *previousErrorAction;
    QAction *wordWrapAction;
    QAction *showStaticWordWrapMarkerAction;
    QAction *showIconBorderAction;
    QAction *showLineNumbersAction;
    QAction *showScrollbarMarksAction;
    QAction *showFoldingMarkersAction;
    QAction *newSessionAction;
    QAction *quickOpenerAction;
    QAction *saveSessionAction;
    QAction *saveSessionAsAction;
    QAction *parseJassSyntaxAction;
    QAction *parseVjassSyntaxAction;
    QAction *buildApiDocumentationAction;
    QAction *aboutVjassideAction;
    QAction *aboutPjassAction;
    QAction *aboutJasshelperAction;
    QAction *aboutVjassdocAction;
    QAction *configureEditorAction;
    QAction *aboutVjasssdkAction;
    QAction *aboutWc3sdkAction;
    QAction *aboutQtAction;
    QAction *offAction;
    QAction *followLineNumbersAction;
    QAction *alwaysOnAction;
    QAction *collapseToplevelAction;
    QAction *expandToplevelAction;
    QAction *collapseOneLocalLevelAction;
    QAction *expandOneLocalLevelAction;
    QAction *closeSessionAction;
    QAction *apiListAction;
    QAction *outputAction;
    QAction *fileListAction;
    QAction *showMpqEditorAction;
    QAction *showApiDatabaseDialogAction;
    QAction *insertColorAction;
    QAction *createTalkAction;
    QAction *createQuestAction;
    QAction *deleteSessionAction;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout1;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *fileMenu;
    QMenu *openRecentMenu;
    QMenu *editMenu;
    QMenu *viewMenu;
    QMenu *codeFoldingMenu;
    QMenu *dynamicWordWrapIndicatorsMenu;
    QMenu *sessionsMenu;
    QMenu *openSessionMenu;
    QMenu *buildMenu;
    QMenu *settingsMenu;
    QMenu *helpMenu;
    QMenu *toolsMenu;
    QMenu *extensionsMenu;
    QMenu *advancedScriptLibraryMenu;
    QStatusBar *statusbar;
    QDockWidget *apiListDockWidget;
    QWidget *apiListDockWidgetContents;
    QGridLayout *gridLayout2;
    QVBoxLayout *vboxLayout;
    QLabel *label;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout1;
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
    QCheckBox *documentationCommentCheckBox;
    QCheckBox *allCheckBox;
    QVBoxLayout *vboxLayout2;
    QLineEdit *lineEdit;
    QListWidget *listWidget;
    QDockWidget *outputDockWidget;
    QWidget *outputDockWidgetContents;
    QGridLayout *gridLayout3;
    QTextBrowser *outputTextBrowser;
    QDockWidget *fileListDockWidget;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout4;
    QLabel *fileListLabel;
    QListWidget *fileListListWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(833, 755);
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8(":/images/vjasside.png")), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->setDockNestingEnabled(true);
        MainWindow->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        newAction = new QAction(MainWindow);
        newAction->setObjectName(QString::fromUtf8("newAction"));
        QIcon icon1;
        icon1.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/document-new.png")), QIcon::Normal, QIcon::Off);
        newAction->setIcon(icon1);
        openAction = new QAction(MainWindow);
        openAction->setObjectName(QString::fromUtf8("openAction"));
        QIcon icon2;
        icon2.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/document-open.png")), QIcon::Normal, QIcon::Off);
        openAction->setIcon(icon2);
        saveAction = new QAction(MainWindow);
        saveAction->setObjectName(QString::fromUtf8("saveAction"));
        QIcon icon3;
        icon3.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/document-save.png")), QIcon::Normal, QIcon::Off);
        saveAction->setIcon(icon3);
        saveAsAction = new QAction(MainWindow);
        saveAsAction->setObjectName(QString::fromUtf8("saveAsAction"));
        QIcon icon4;
        icon4.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/document-save-as.png")), QIcon::Normal, QIcon::Off);
        saveAsAction->setIcon(icon4);
        saveAllAction = new QAction(MainWindow);
        saveAllAction->setObjectName(QString::fromUtf8("saveAllAction"));
        QIcon icon5;
        icon5.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/document-save-all.png")), QIcon::Normal, QIcon::Off);
        saveAllAction->setIcon(icon5);
        reloadAction = new QAction(MainWindow);
        reloadAction->setObjectName(QString::fromUtf8("reloadAction"));
        QIcon icon6;
        icon6.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/view-refresh.png")), QIcon::Normal, QIcon::Off);
        reloadAction->setIcon(icon6);
        revertAllAction = new QAction(MainWindow);
        revertAllAction->setObjectName(QString::fromUtf8("revertAllAction"));
        QIcon icon7;
        icon7.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/document-revert.png")), QIcon::Normal, QIcon::Off);
        revertAllAction->setIcon(icon7);
        printAction = new QAction(MainWindow);
        printAction->setObjectName(QString::fromUtf8("printAction"));
        QIcon icon8;
        icon8.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/document-print.png")), QIcon::Normal, QIcon::Off);
        printAction->setIcon(icon8);
        exportAsHtmlAction = new QAction(MainWindow);
        exportAsHtmlAction->setObjectName(QString::fromUtf8("exportAsHtmlAction"));
        QIcon icon9;
        icon9.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/document-export.png")), QIcon::Normal, QIcon::Off);
        exportAsHtmlAction->setIcon(icon9);
        closeAction = new QAction(MainWindow);
        closeAction->setObjectName(QString::fromUtf8("closeAction"));
        QIcon icon10;
        icon10.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/dialog-close.png")), QIcon::Normal, QIcon::Off);
        closeAction->setIcon(icon10);
        closeAllAction = new QAction(MainWindow);
        closeAllAction->setObjectName(QString::fromUtf8("closeAllAction"));
        closeAllOtherAction = new QAction(MainWindow);
        closeAllOtherAction->setObjectName(QString::fromUtf8("closeAllOtherAction"));
        quitAction = new QAction(MainWindow);
        quitAction->setObjectName(QString::fromUtf8("quitAction"));
        QIcon icon11;
        icon11.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/application-exit.png")), QIcon::Normal, QIcon::Off);
        quitAction->setIcon(icon11);
        quitAction->setMenuRole(QAction::QuitRole);
        undoAction = new QAction(MainWindow);
        undoAction->setObjectName(QString::fromUtf8("undoAction"));
        undoAction->setEnabled(false);
        QIcon icon12;
        icon12.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/edit-undo.png")), QIcon::Normal, QIcon::Off);
        undoAction->setIcon(icon12);
        redoAction = new QAction(MainWindow);
        redoAction->setObjectName(QString::fromUtf8("redoAction"));
        redoAction->setEnabled(false);
        QIcon icon13;
        icon13.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/edit-redo.png")), QIcon::Normal, QIcon::Off);
        redoAction->setIcon(icon13);
        cutAction = new QAction(MainWindow);
        cutAction->setObjectName(QString::fromUtf8("cutAction"));
        cutAction->setEnabled(false);
        QIcon icon14;
        icon14.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/edit-cut.png")), QIcon::Normal, QIcon::Off);
        cutAction->setIcon(icon14);
        copyAction = new QAction(MainWindow);
        copyAction->setObjectName(QString::fromUtf8("copyAction"));
        copyAction->setEnabled(false);
        QIcon icon15;
        icon15.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/edit-copy.png")), QIcon::Normal, QIcon::Off);
        copyAction->setIcon(icon15);
        copyAsHtmlAction = new QAction(MainWindow);
        copyAsHtmlAction->setObjectName(QString::fromUtf8("copyAsHtmlAction"));
        copyAsHtmlAction->setEnabled(false);
        copyAsHtmlAction->setIcon(icon15);
        pasteAction = new QAction(MainWindow);
        pasteAction->setObjectName(QString::fromUtf8("pasteAction"));
        pasteAction->setEnabled(true);
        QIcon icon16;
        icon16.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/edit-paste.png")), QIcon::Normal, QIcon::Off);
        pasteAction->setIcon(icon16);
        selectAllAction = new QAction(MainWindow);
        selectAllAction->setObjectName(QString::fromUtf8("selectAllAction"));
        selectAllAction->setEnabled(true);
        QIcon icon17;
        icon17.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/edit-select-all.png")), QIcon::Normal, QIcon::Off);
        selectAllAction->setIcon(icon17);
        deselectAction = new QAction(MainWindow);
        deselectAction->setObjectName(QString::fromUtf8("deselectAction"));
        deselectAction->setEnabled(false);
        blockSelectionModeAction = new QAction(MainWindow);
        blockSelectionModeAction->setObjectName(QString::fromUtf8("blockSelectionModeAction"));
        overwriteModeAction = new QAction(MainWindow);
        overwriteModeAction->setObjectName(QString::fromUtf8("overwriteModeAction"));
        findAction = new QAction(MainWindow);
        findAction->setObjectName(QString::fromUtf8("findAction"));
        QIcon icon18;
        icon18.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/edit-find.png")), QIcon::Normal, QIcon::Off);
        findAction->setIcon(icon18);
        findNextAction = new QAction(MainWindow);
        findNextAction->setObjectName(QString::fromUtf8("findNextAction"));
        QIcon icon19;
        icon19.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/go-next.png")), QIcon::Normal, QIcon::Off);
        findNextAction->setIcon(icon19);
        findPreviousAction = new QAction(MainWindow);
        findPreviousAction->setObjectName(QString::fromUtf8("findPreviousAction"));
        QIcon icon20;
        icon20.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/go-previous.png")), QIcon::Normal, QIcon::Off);
        findPreviousAction->setIcon(icon20);
        replaceAction = new QAction(MainWindow);
        replaceAction->setObjectName(QString::fromUtf8("replaceAction"));
        goToLineAction = new QAction(MainWindow);
        goToLineAction->setObjectName(QString::fromUtf8("goToLineAction"));
        QIcon icon21;
        icon21.addPixmap(QPixmap(QString::fromUtf8("../../../../../../../../../:/images/actions/goto.png")), QIcon::Normal, QIcon::Off);
        goToLineAction->setIcon(icon21);
        findInFilesAction = new QAction(MainWindow);
        findInFilesAction->setObjectName(QString::fromUtf8("findInFilesAction"));
        findSelectReplaceAction = new QAction(MainWindow);
        findSelectReplaceAction->setObjectName(QString::fromUtf8("findSelectReplaceAction"));
        expandTextAction = new QAction(MainWindow);
        expandTextAction->setObjectName(QString::fromUtf8("expandTextAction"));
        expandAbbreviationAction = new QAction(MainWindow);
        expandAbbreviationAction->setObjectName(QString::fromUtf8("expandAbbreviationAction"));
        backAction = new QAction(MainWindow);
        backAction->setObjectName(QString::fromUtf8("backAction"));
        backAction->setIcon(icon20);
        forwardAction = new QAction(MainWindow);
        forwardAction->setObjectName(QString::fromUtf8("forwardAction"));
        forwardAction->setIcon(icon19);
        gotoLastEditPositionAction = new QAction(MainWindow);
        gotoLastEditPositionAction->setObjectName(QString::fromUtf8("gotoLastEditPositionAction"));
        QIcon icon22;
        icon22.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/go-bottom.png")), QIcon::Normal, QIcon::Off);
        gotoLastEditPositionAction->setIcon(icon22);
        raiseEditorAction = new QAction(MainWindow);
        raiseEditorAction->setObjectName(QString::fromUtf8("raiseEditorAction"));
        nextErrorAction = new QAction(MainWindow);
        nextErrorAction->setObjectName(QString::fromUtf8("nextErrorAction"));
        previousErrorAction = new QAction(MainWindow);
        previousErrorAction->setObjectName(QString::fromUtf8("previousErrorAction"));
        wordWrapAction = new QAction(MainWindow);
        wordWrapAction->setObjectName(QString::fromUtf8("wordWrapAction"));
        wordWrapAction->setCheckable(true);
        showStaticWordWrapMarkerAction = new QAction(MainWindow);
        showStaticWordWrapMarkerAction->setObjectName(QString::fromUtf8("showStaticWordWrapMarkerAction"));
        showIconBorderAction = new QAction(MainWindow);
        showIconBorderAction->setObjectName(QString::fromUtf8("showIconBorderAction"));
        showLineNumbersAction = new QAction(MainWindow);
        showLineNumbersAction->setObjectName(QString::fromUtf8("showLineNumbersAction"));
        showScrollbarMarksAction = new QAction(MainWindow);
        showScrollbarMarksAction->setObjectName(QString::fromUtf8("showScrollbarMarksAction"));
        showFoldingMarkersAction = new QAction(MainWindow);
        showFoldingMarkersAction->setObjectName(QString::fromUtf8("showFoldingMarkersAction"));
        newSessionAction = new QAction(MainWindow);
        newSessionAction->setObjectName(QString::fromUtf8("newSessionAction"));
        newSessionAction->setIcon(icon1);
        quickOpenerAction = new QAction(MainWindow);
        quickOpenerAction->setObjectName(QString::fromUtf8("quickOpenerAction"));
        saveSessionAction = new QAction(MainWindow);
        saveSessionAction->setObjectName(QString::fromUtf8("saveSessionAction"));
        saveSessionAction->setIcon(icon4);
        saveSessionAsAction = new QAction(MainWindow);
        saveSessionAsAction->setObjectName(QString::fromUtf8("saveSessionAsAction"));
        saveSessionAsAction->setIcon(icon3);
        parseJassSyntaxAction = new QAction(MainWindow);
        parseJassSyntaxAction->setObjectName(QString::fromUtf8("parseJassSyntaxAction"));
        parseVjassSyntaxAction = new QAction(MainWindow);
        parseVjassSyntaxAction->setObjectName(QString::fromUtf8("parseVjassSyntaxAction"));
        QIcon icon23;
        icon23.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/jasshelper.png")), QIcon::Normal, QIcon::Off);
        parseVjassSyntaxAction->setIcon(icon23);
        buildApiDocumentationAction = new QAction(MainWindow);
        buildApiDocumentationAction->setObjectName(QString::fromUtf8("buildApiDocumentationAction"));
        QIcon icon24;
        icon24.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/bookmarks-organize.png")), QIcon::Normal, QIcon::Off);
        buildApiDocumentationAction->setIcon(icon24);
        aboutVjassideAction = new QAction(MainWindow);
        aboutVjassideAction->setObjectName(QString::fromUtf8("aboutVjassideAction"));
        QIcon icon25;
        icon25.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/help-about.png")), QIcon::Normal, QIcon::Off);
        aboutVjassideAction->setIcon(icon25);
        aboutVjassideAction->setMenuRole(QAction::AboutRole);
        aboutPjassAction = new QAction(MainWindow);
        aboutPjassAction->setObjectName(QString::fromUtf8("aboutPjassAction"));
        aboutPjassAction->setMenuRole(QAction::AboutQtRole);
        aboutJasshelperAction = new QAction(MainWindow);
        aboutJasshelperAction->setObjectName(QString::fromUtf8("aboutJasshelperAction"));
        aboutJasshelperAction->setIcon(icon23);
        aboutJasshelperAction->setMenuRole(QAction::AboutRole);
        aboutVjassdocAction = new QAction(MainWindow);
        aboutVjassdocAction->setObjectName(QString::fromUtf8("aboutVjassdocAction"));
        aboutVjassdocAction->setIcon(icon24);
        aboutVjassdocAction->setMenuRole(QAction::AboutRole);
        configureEditorAction = new QAction(MainWindow);
        configureEditorAction->setObjectName(QString::fromUtf8("configureEditorAction"));
        QIcon icon26;
        icon26.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/configure.png")), QIcon::Normal, QIcon::Off);
        configureEditorAction->setIcon(icon26);
        configureEditorAction->setShortcutContext(Qt::WindowShortcut);
        configureEditorAction->setMenuRole(QAction::PreferencesRole);
        aboutVjasssdkAction = new QAction(MainWindow);
        aboutVjasssdkAction->setObjectName(QString::fromUtf8("aboutVjasssdkAction"));
        aboutVjasssdkAction->setMenuRole(QAction::AboutRole);
        aboutWc3sdkAction = new QAction(MainWindow);
        aboutWc3sdkAction->setObjectName(QString::fromUtf8("aboutWc3sdkAction"));
        aboutWc3sdkAction->setMenuRole(QAction::AboutRole);
        aboutQtAction = new QAction(MainWindow);
        aboutQtAction->setObjectName(QString::fromUtf8("aboutQtAction"));
        QIcon icon27;
        icon27.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/qt.png")), QIcon::Normal, QIcon::Off);
        aboutQtAction->setIcon(icon27);
        aboutQtAction->setMenuRole(QAction::AboutQtRole);
        offAction = new QAction(MainWindow);
        offAction->setObjectName(QString::fromUtf8("offAction"));
        offAction->setCheckable(true);
        offAction->setChecked(false);
        followLineNumbersAction = new QAction(MainWindow);
        followLineNumbersAction->setObjectName(QString::fromUtf8("followLineNumbersAction"));
        followLineNumbersAction->setCheckable(true);
        alwaysOnAction = new QAction(MainWindow);
        alwaysOnAction->setObjectName(QString::fromUtf8("alwaysOnAction"));
        alwaysOnAction->setCheckable(true);
        collapseToplevelAction = new QAction(MainWindow);
        collapseToplevelAction->setObjectName(QString::fromUtf8("collapseToplevelAction"));
        collapseToplevelAction->setCheckable(false);
        expandToplevelAction = new QAction(MainWindow);
        expandToplevelAction->setObjectName(QString::fromUtf8("expandToplevelAction"));
        expandToplevelAction->setCheckable(false);
        collapseOneLocalLevelAction = new QAction(MainWindow);
        collapseOneLocalLevelAction->setObjectName(QString::fromUtf8("collapseOneLocalLevelAction"));
        collapseOneLocalLevelAction->setCheckable(false);
        expandOneLocalLevelAction = new QAction(MainWindow);
        expandOneLocalLevelAction->setObjectName(QString::fromUtf8("expandOneLocalLevelAction"));
        expandOneLocalLevelAction->setCheckable(false);
        closeSessionAction = new QAction(MainWindow);
        closeSessionAction->setObjectName(QString::fromUtf8("closeSessionAction"));
        closeSessionAction->setIcon(icon10);
        apiListAction = new QAction(MainWindow);
        apiListAction->setObjectName(QString::fromUtf8("apiListAction"));
        apiListAction->setCheckable(true);
        apiListAction->setChecked(true);
        outputAction = new QAction(MainWindow);
        outputAction->setObjectName(QString::fromUtf8("outputAction"));
        outputAction->setCheckable(true);
        outputAction->setChecked(true);
        fileListAction = new QAction(MainWindow);
        fileListAction->setObjectName(QString::fromUtf8("fileListAction"));
        fileListAction->setCheckable(true);
        fileListAction->setChecked(true);
        showMpqEditorAction = new QAction(MainWindow);
        showMpqEditorAction->setObjectName(QString::fromUtf8("showMpqEditorAction"));
        showMpqEditorAction->setCheckable(false);
        showApiDatabaseDialogAction = new QAction(MainWindow);
        showApiDatabaseDialogAction->setObjectName(QString::fromUtf8("showApiDatabaseDialogAction"));
        insertColorAction = new QAction(MainWindow);
        insertColorAction->setObjectName(QString::fromUtf8("insertColorAction"));
        QIcon icon28;
        icon28.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/fill-color.png")), QIcon::Normal, QIcon::Off);
        insertColorAction->setIcon(icon28);
        createTalkAction = new QAction(MainWindow);
        createTalkAction->setObjectName(QString::fromUtf8("createTalkAction"));
        createQuestAction = new QAction(MainWindow);
        createQuestAction->setObjectName(QString::fromUtf8("createQuestAction"));
        deleteSessionAction = new QAction(MainWindow);
        deleteSessionAction->setObjectName(QString::fromUtf8("deleteSessionAction"));
        deleteSessionAction->setIcon(icon10);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setContextMenuPolicy(Qt::ActionsContextMenu);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tab->setContextMenuPolicy(Qt::DefaultContextMenu);
        gridLayout1 = new QGridLayout(tab);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setContextMenuPolicy(Qt::DefaultContextMenu);
        textEdit->setLineWidth(1);
        textEdit->setAutoFormatting(QTextEdit::AutoNone);
        textEdit->setLineWrapMode(QTextEdit::WidgetWidth);

        gridLayout1->addWidget(textEdit, 0, 0, 1, 1);

        QIcon icon29;
        icon29.addPixmap(QPixmap(QString::fromUtf8(":/images/mimetypes/jasssource.png")), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab, icon29, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 833, 25));
        fileMenu = new QMenu(menubar);
        fileMenu->setObjectName(QString::fromUtf8("fileMenu"));
        fileMenu->setTearOffEnabled(true);
        openRecentMenu = new QMenu(fileMenu);
        openRecentMenu->setObjectName(QString::fromUtf8("openRecentMenu"));
        openRecentMenu->setTearOffEnabled(true);
        QIcon icon30;
        icon30.addPixmap(QPixmap(QString::fromUtf8(":/images/actions/document-open-recent.png")), QIcon::Normal, QIcon::Off);
        openRecentMenu->setIcon(icon30);
        editMenu = new QMenu(menubar);
        editMenu->setObjectName(QString::fromUtf8("editMenu"));
        editMenu->setTearOffEnabled(true);
        viewMenu = new QMenu(menubar);
        viewMenu->setObjectName(QString::fromUtf8("viewMenu"));
        viewMenu->setTearOffEnabled(true);
        codeFoldingMenu = new QMenu(viewMenu);
        codeFoldingMenu->setObjectName(QString::fromUtf8("codeFoldingMenu"));
        codeFoldingMenu->setTearOffEnabled(true);
        dynamicWordWrapIndicatorsMenu = new QMenu(viewMenu);
        dynamicWordWrapIndicatorsMenu->setObjectName(QString::fromUtf8("dynamicWordWrapIndicatorsMenu"));
        dynamicWordWrapIndicatorsMenu->setTearOffEnabled(true);
        sessionsMenu = new QMenu(menubar);
        sessionsMenu->setObjectName(QString::fromUtf8("sessionsMenu"));
        sessionsMenu->setTearOffEnabled(true);
        openSessionMenu = new QMenu(sessionsMenu);
        openSessionMenu->setObjectName(QString::fromUtf8("openSessionMenu"));
        openSessionMenu->setTearOffEnabled(true);
        openSessionMenu->setIcon(icon2);
        buildMenu = new QMenu(menubar);
        buildMenu->setObjectName(QString::fromUtf8("buildMenu"));
        buildMenu->setTearOffEnabled(true);
        settingsMenu = new QMenu(menubar);
        settingsMenu->setObjectName(QString::fromUtf8("settingsMenu"));
        settingsMenu->setTearOffEnabled(true);
        helpMenu = new QMenu(menubar);
        helpMenu->setObjectName(QString::fromUtf8("helpMenu"));
        helpMenu->setTearOffEnabled(true);
        toolsMenu = new QMenu(menubar);
        toolsMenu->setObjectName(QString::fromUtf8("toolsMenu"));
        toolsMenu->setTearOffEnabled(true);
        extensionsMenu = new QMenu(menubar);
        extensionsMenu->setObjectName(QString::fromUtf8("extensionsMenu"));
        advancedScriptLibraryMenu = new QMenu(extensionsMenu);
        advancedScriptLibraryMenu->setObjectName(QString::fromUtf8("advancedScriptLibraryMenu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        apiListDockWidget = new QDockWidget(MainWindow);
        apiListDockWidget->setObjectName(QString::fromUtf8("apiListDockWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(apiListDockWidget->sizePolicy().hasHeightForWidth());
        apiListDockWidget->setSizePolicy(sizePolicy);
        apiListDockWidget->setMaximumSize(QSize(524287, 524287));
        apiListDockWidget->setBaseSize(QSize(0, 0));
        apiListDockWidget->setFloating(false);
        apiListDockWidget->setAllowedAreas(Qt::RightDockWidgetArea);
        apiListDockWidgetContents = new QWidget();
        apiListDockWidgetContents->setObjectName(QString::fromUtf8("apiListDockWidgetContents"));
        apiListDockWidgetContents->setMinimumSize(QSize(0, 0));
        apiListDockWidgetContents->setMaximumSize(QSize(16777215, 16777215));
        apiListDockWidgetContents->setBaseSize(QSize(0, 0));
        gridLayout2 = new QGridLayout(apiListDockWidgetContents);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        vboxLayout = new QVBoxLayout();
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        label = new QLabel(apiListDockWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        vboxLayout->addWidget(label);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        commentCheckBox = new QCheckBox(apiListDockWidgetContents);
        commentCheckBox->setObjectName(QString::fromUtf8("commentCheckBox"));

        vboxLayout1->addWidget(commentCheckBox);

        keywordCheckBox = new QCheckBox(apiListDockWidgetContents);
        keywordCheckBox->setObjectName(QString::fromUtf8("keywordCheckBox"));

        vboxLayout1->addWidget(keywordCheckBox);

        textMacroCheckBox = new QCheckBox(apiListDockWidgetContents);
        textMacroCheckBox->setObjectName(QString::fromUtf8("textMacroCheckBox"));

        vboxLayout1->addWidget(textMacroCheckBox);

        textMacroInstanceCheckBox = new QCheckBox(apiListDockWidgetContents);
        textMacroInstanceCheckBox->setObjectName(QString::fromUtf8("textMacroInstanceCheckBox"));

        vboxLayout1->addWidget(textMacroInstanceCheckBox);

        typeCheckBox = new QCheckBox(apiListDockWidgetContents);
        typeCheckBox->setObjectName(QString::fromUtf8("typeCheckBox"));

        vboxLayout1->addWidget(typeCheckBox);

        globalCheckBox = new QCheckBox(apiListDockWidgetContents);
        globalCheckBox->setObjectName(QString::fromUtf8("globalCheckBox"));

        vboxLayout1->addWidget(globalCheckBox);

        memberCheckBox = new QCheckBox(apiListDockWidgetContents);
        memberCheckBox->setObjectName(QString::fromUtf8("memberCheckBox"));

        vboxLayout1->addWidget(memberCheckBox);

        functionInterfaceCheckBox = new QCheckBox(apiListDockWidgetContents);
        functionInterfaceCheckBox->setObjectName(QString::fromUtf8("functionInterfaceCheckBox"));

        vboxLayout1->addWidget(functionInterfaceCheckBox);

        functionCheckBox = new QCheckBox(apiListDockWidgetContents);
        functionCheckBox->setObjectName(QString::fromUtf8("functionCheckBox"));

        vboxLayout1->addWidget(functionCheckBox);

        methodCheckBox = new QCheckBox(apiListDockWidgetContents);
        methodCheckBox->setObjectName(QString::fromUtf8("methodCheckBox"));

        vboxLayout1->addWidget(methodCheckBox);

        interfaceCheckBox = new QCheckBox(apiListDockWidgetContents);
        interfaceCheckBox->setObjectName(QString::fromUtf8("interfaceCheckBox"));

        vboxLayout1->addWidget(interfaceCheckBox);

        structCheckBox = new QCheckBox(apiListDockWidgetContents);
        structCheckBox->setObjectName(QString::fromUtf8("structCheckBox"));

        vboxLayout1->addWidget(structCheckBox);

        scopeCheckBox = new QCheckBox(apiListDockWidgetContents);
        scopeCheckBox->setObjectName(QString::fromUtf8("scopeCheckBox"));

        vboxLayout1->addWidget(scopeCheckBox);

        libraryCheckBox = new QCheckBox(apiListDockWidgetContents);
        libraryCheckBox->setObjectName(QString::fromUtf8("libraryCheckBox"));

        vboxLayout1->addWidget(libraryCheckBox);

        sourceFileCheckBox = new QCheckBox(apiListDockWidgetContents);
        sourceFileCheckBox->setObjectName(QString::fromUtf8("sourceFileCheckBox"));

        vboxLayout1->addWidget(sourceFileCheckBox);

        documentationCommentCheckBox = new QCheckBox(apiListDockWidgetContents);
        documentationCommentCheckBox->setObjectName(QString::fromUtf8("documentationCommentCheckBox"));

        vboxLayout1->addWidget(documentationCommentCheckBox);

        allCheckBox = new QCheckBox(apiListDockWidgetContents);
        allCheckBox->setObjectName(QString::fromUtf8("allCheckBox"));

        vboxLayout1->addWidget(allCheckBox);


        hboxLayout->addLayout(vboxLayout1);

        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        lineEdit = new QLineEdit(apiListDockWidgetContents);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        vboxLayout2->addWidget(lineEdit);

        listWidget = new QListWidget(apiListDockWidgetContents);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        vboxLayout2->addWidget(listWidget);


        hboxLayout->addLayout(vboxLayout2);


        vboxLayout->addLayout(hboxLayout);


        gridLayout2->addLayout(vboxLayout, 0, 0, 1, 1);

        apiListDockWidget->setWidget(apiListDockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), apiListDockWidget);
        outputDockWidget = new QDockWidget(MainWindow);
        outputDockWidget->setObjectName(QString::fromUtf8("outputDockWidget"));
        outputDockWidget->setMinimumSize(QSize(142, 147));
        outputDockWidget->setMaximumSize(QSize(524287, 524287));
        outputDockWidget->setFloating(false);
        outputDockWidget->setAllowedAreas(Qt::BottomDockWidgetArea);
        outputDockWidgetContents = new QWidget();
        outputDockWidgetContents->setObjectName(QString::fromUtf8("outputDockWidgetContents"));
        outputDockWidgetContents->setMinimumSize(QSize(0, 0));
        outputDockWidgetContents->setMaximumSize(QSize(16777215, 16777215));
        gridLayout3 = new QGridLayout(outputDockWidgetContents);
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        outputTextBrowser = new QTextBrowser(outputDockWidgetContents);
        outputTextBrowser->setObjectName(QString::fromUtf8("outputTextBrowser"));

        gridLayout3->addWidget(outputTextBrowser, 0, 0, 1, 1);

        outputDockWidget->setWidget(outputDockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), outputDockWidget);
        fileListDockWidget = new QDockWidget(MainWindow);
        fileListDockWidget->setObjectName(QString::fromUtf8("fileListDockWidget"));
        fileListDockWidget->setEnabled(true);
        fileListDockWidget->setMinimumSize(QSize(168, 182));
        fileListDockWidget->setMaximumSize(QSize(524287, 524287));
        fileListDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        dockWidgetContents->setMinimumSize(QSize(0, 0));
        dockWidgetContents->setMaximumSize(QSize(16777215, 16777215));
        gridLayout4 = new QGridLayout(dockWidgetContents);
        gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
        fileListLabel = new QLabel(dockWidgetContents);
        fileListLabel->setObjectName(QString::fromUtf8("fileListLabel"));
        fileListLabel->setAlignment(Qt::AlignCenter);

        gridLayout4->addWidget(fileListLabel, 0, 0, 1, 1);

        fileListListWidget = new QListWidget(dockWidgetContents);
        fileListListWidget->setObjectName(QString::fromUtf8("fileListListWidget"));

        gridLayout4->addWidget(fileListListWidget, 1, 0, 1, 1);

        fileListDockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), fileListDockWidget);

        menubar->addAction(fileMenu->menuAction());
        menubar->addAction(editMenu->menuAction());
        menubar->addAction(viewMenu->menuAction());
        menubar->addAction(toolsMenu->menuAction());
        menubar->addAction(sessionsMenu->menuAction());
        menubar->addAction(buildMenu->menuAction());
        menubar->addAction(extensionsMenu->menuAction());
        menubar->addAction(settingsMenu->menuAction());
        menubar->addAction(helpMenu->menuAction());
        fileMenu->addAction(newAction);
        fileMenu->addAction(openAction);
        fileMenu->addAction(openRecentMenu->menuAction());
        fileMenu->addSeparator();
        fileMenu->addAction(saveAction);
        fileMenu->addAction(saveAsAction);
        fileMenu->addAction(saveAllAction);
        fileMenu->addSeparator();
        fileMenu->addAction(reloadAction);
        fileMenu->addAction(revertAllAction);
        fileMenu->addSeparator();
        fileMenu->addAction(printAction);
        fileMenu->addSeparator();
        fileMenu->addAction(exportAsHtmlAction);
        fileMenu->addAction(closeAction);
        fileMenu->addAction(closeAllAction);
        fileMenu->addAction(closeAllOtherAction);
        fileMenu->addSeparator();
        fileMenu->addAction(quitAction);
        editMenu->addAction(undoAction);
        editMenu->addAction(redoAction);
        editMenu->addSeparator();
        editMenu->addAction(cutAction);
        editMenu->addAction(copyAction);
        editMenu->addAction(copyAsHtmlAction);
        editMenu->addAction(pasteAction);
        editMenu->addSeparator();
        editMenu->addAction(selectAllAction);
        editMenu->addAction(deselectAction);
        editMenu->addAction(blockSelectionModeAction);
        editMenu->addSeparator();
        editMenu->addAction(overwriteModeAction);
        editMenu->addSeparator();
        editMenu->addAction(findAction);
        editMenu->addAction(findNextAction);
        editMenu->addAction(findPreviousAction);
        editMenu->addAction(replaceAction);
        editMenu->addSeparator();
        editMenu->addAction(goToLineAction);
        editMenu->addAction(findSelectReplaceAction);
        editMenu->addAction(findInFilesAction);
        viewMenu->addAction(backAction);
        viewMenu->addAction(forwardAction);
        viewMenu->addAction(gotoLastEditPositionAction);
        viewMenu->addSeparator();
        viewMenu->addAction(wordWrapAction);
        viewMenu->addAction(dynamicWordWrapIndicatorsMenu->menuAction());
        viewMenu->addAction(showStaticWordWrapMarkerAction);
        viewMenu->addSeparator();
        viewMenu->addAction(showIconBorderAction);
        viewMenu->addAction(showLineNumbersAction);
        viewMenu->addAction(showScrollbarMarksAction);
        viewMenu->addSeparator();
        viewMenu->addAction(showFoldingMarkersAction);
        viewMenu->addAction(codeFoldingMenu->menuAction());
        codeFoldingMenu->addAction(collapseToplevelAction);
        codeFoldingMenu->addAction(expandToplevelAction);
        codeFoldingMenu->addAction(collapseOneLocalLevelAction);
        codeFoldingMenu->addAction(expandOneLocalLevelAction);
        dynamicWordWrapIndicatorsMenu->addAction(offAction);
        dynamicWordWrapIndicatorsMenu->addAction(followLineNumbersAction);
        dynamicWordWrapIndicatorsMenu->addAction(alwaysOnAction);
        sessionsMenu->addAction(newSessionAction);
        sessionsMenu->addAction(openSessionMenu->menuAction());
        sessionsMenu->addSeparator();
        sessionsMenu->addAction(saveSessionAction);
        sessionsMenu->addAction(saveSessionAsAction);
        sessionsMenu->addSeparator();
        sessionsMenu->addAction(deleteSessionAction);
        sessionsMenu->addSeparator();
        sessionsMenu->addAction(closeSessionAction);
        buildMenu->addAction(parseJassSyntaxAction);
        buildMenu->addAction(parseVjassSyntaxAction);
        buildMenu->addSeparator();
        buildMenu->addAction(buildApiDocumentationAction);
        settingsMenu->addAction(configureEditorAction);
        helpMenu->addAction(aboutPjassAction);
        helpMenu->addAction(aboutJasshelperAction);
        helpMenu->addAction(aboutVjassdocAction);
        helpMenu->addSeparator();
        helpMenu->addAction(aboutVjasssdkAction);
        helpMenu->addAction(aboutWc3sdkAction);
        helpMenu->addSeparator();
        helpMenu->addAction(aboutVjassideAction);
        helpMenu->addAction(aboutQtAction);
        toolsMenu->addAction(fileListAction);
        toolsMenu->addAction(apiListAction);
        toolsMenu->addAction(outputAction);
        toolsMenu->addAction(showApiDatabaseDialogAction);
        toolsMenu->addAction(showMpqEditorAction);
        toolsMenu->addAction(insertColorAction);
        extensionsMenu->addAction(advancedScriptLibraryMenu->menuAction());
        advancedScriptLibraryMenu->addAction(createTalkAction);
        advancedScriptLibraryMenu->addAction(createQuestAction);

        retranslateUi(MainWindow);
        QObject::connect(apiListAction, SIGNAL(triggered(bool)), apiListDockWidget, SLOT(setVisible(bool)));
        QObject::connect(outputAction, SIGNAL(triggered(bool)), outputDockWidget, SLOT(setVisible(bool)));
        QObject::connect(fileListAction, SIGNAL(triggered(bool)), fileListDockWidget, SLOT(setVisible(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), commentCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), keywordCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), textMacroCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), typeCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), globalCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), memberCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), functionInterfaceCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), functionCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), methodCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), interfaceCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), structCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), scopeCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), libraryCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), sourceFileCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), documentationCommentCheckBox, SLOT(setChecked(bool)));
        QObject::connect(allCheckBox, SIGNAL(clicked(bool)), textMacroInstanceCheckBox, SLOT(setChecked(bool)));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "vjasside", 0, QApplication::UnicodeUTF8));
        newAction->setText(QApplication::translate("MainWindow", "&Neu", 0, QApplication::UnicodeUTF8));
        newAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        openAction->setText(QApplication::translate("MainWindow", "\303\226&ffnen \342\200\246", 0, QApplication::UnicodeUTF8));
        openAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        saveAction->setText(QApplication::translate("MainWindow", "S&peichern", 0, QApplication::UnicodeUTF8));
        saveAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        saveAsAction->setText(QApplication::translate("MainWindow", "Speichern &unter \342\200\246", 0, QApplication::UnicodeUTF8));
        saveAllAction->setText(QApplication::translate("MainWindow", "&Alles speichern", 0, QApplication::UnicodeUTF8));
        reloadAction->setText(QApplication::translate("MainWindow", "E&rneut laden", 0, QApplication::UnicodeUTF8));
        reloadAction->setShortcut(QApplication::translate("MainWindow", "F5", 0, QApplication::UnicodeUTF8));
        revertAllAction->setText(QApplication::translate("MainWindow", "Alle \303\204nderungen zur\303\274cknehmen", 0, QApplication::UnicodeUTF8));
        printAction->setText(QApplication::translate("MainWindow", "&Drucken \342\200\246", 0, QApplication::UnicodeUTF8));
        printAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        exportAsHtmlAction->setText(QApplication::translate("MainWindow", "Als &HTML exportieren \342\200\246", 0, QApplication::UnicodeUTF8));
        closeAction->setText(QApplication::translate("MainWindow", "Schl&ie\303\237en", 0, QApplication::UnicodeUTF8));
        closeAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", 0, QApplication::UnicodeUTF8));
        closeAllAction->setText(QApplication::translate("MainWindow", "Alle &schlie\303\237en", 0, QApplication::UnicodeUTF8));
        closeAllOtherAction->setText(QApplication::translate("MainWindow", "Alle anderen schlie&\303\237en", 0, QApplication::UnicodeUTF8));
        quitAction->setText(QApplication::translate("MainWindow", "Be&enden", 0, QApplication::UnicodeUTF8));
        quitAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        undoAction->setText(QApplication::translate("MainWindow", "&R\303\274ckg\303\244ngig", 0, QApplication::UnicodeUTF8));
        undoAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        redoAction->setText(QApplication::translate("MainWindow", "Wie&derherstellen", 0, QApplication::UnicodeUTF8));
        redoAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+Z", 0, QApplication::UnicodeUTF8));
        cutAction->setText(QApplication::translate("MainWindow", "&Ausschneiden", 0, QApplication::UnicodeUTF8));
        cutAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0, QApplication::UnicodeUTF8));
        copyAction->setText(QApplication::translate("MainWindow", "&Kopieren", 0, QApplication::UnicodeUTF8));
        copyAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        copyAsHtmlAction->setText(QApplication::translate("MainWindow", "Als &HTML kopieren", 0, QApplication::UnicodeUTF8));
        pasteAction->setText(QApplication::translate("MainWindow", "&Einf\303\274gen", 0, QApplication::UnicodeUTF8));
        pasteAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0, QApplication::UnicodeUTF8));
        selectAllAction->setText(QApplication::translate("MainWindow", "A&lles ausw\303\244hlen", 0, QApplication::UnicodeUTF8));
        selectAllAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", 0, QApplication::UnicodeUTF8));
        deselectAction->setText(QApplication::translate("MainWindow", "A&uswahl aufheben", 0, QApplication::UnicodeUTF8));
        deselectAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+A", 0, QApplication::UnicodeUTF8));
        blockSelectionModeAction->setText(QApplication::translate("MainWindow", "&Blockauswahlmodus", 0, QApplication::UnicodeUTF8));
        blockSelectionModeAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+B", 0, QApplication::UnicodeUTF8));
        overwriteModeAction->setText(QApplication::translate("MainWindow", "&\303\234berschreibmodus", 0, QApplication::UnicodeUTF8));
        overwriteModeAction->setShortcut(QApplication::translate("MainWindow", "Ins", 0, QApplication::UnicodeUTF8));
        findAction->setText(QApplication::translate("MainWindow", "&Suchen \342\200\246", 0, QApplication::UnicodeUTF8));
        findAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", 0, QApplication::UnicodeUTF8));
        findNextAction->setText(QApplication::translate("MainWindow", "&Weitersuchen", 0, QApplication::UnicodeUTF8));
        findNextAction->setShortcut(QApplication::translate("MainWindow", "F3", 0, QApplication::UnicodeUTF8));
        findPreviousAction->setText(QApplication::translate("MainWindow", "&Fr\303\274here suchen", 0, QApplication::UnicodeUTF8));
        findPreviousAction->setShortcut(QApplication::translate("MainWindow", "Shift+F3", 0, QApplication::UnicodeUTF8));
        replaceAction->setText(QApplication::translate("MainWindow", "Ersetze&n \342\200\246", 0, QApplication::UnicodeUTF8));
        replaceAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", 0, QApplication::UnicodeUTF8));
        goToLineAction->setText(QApplication::translate("MainWindow", "Gehe zu &Zeile \342\200\246", 0, QApplication::UnicodeUTF8));
        goToLineAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+G", 0, QApplication::UnicodeUTF8));
        findInFilesAction->setText(QApplication::translate("MainWindow", "Suche &in Dateien \342\200\246", 0, QApplication::UnicodeUTF8));
        findInFilesAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+F", 0, QApplication::UnicodeUTF8));
        findSelectReplaceAction->setText(QApplication::translate("MainWindow", "Su&che-Auswahl-Ersetzen \342\200\246", 0, QApplication::UnicodeUTF8));
        findSelectReplaceAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+R", 0, QApplication::UnicodeUTF8));
        expandTextAction->setText(QApplication::translate("MainWindow", "Expand Text", 0, QApplication::UnicodeUTF8));
        expandAbbreviationAction->setText(QApplication::translate("MainWindow", "Expand Abbreviation", 0, QApplication::UnicodeUTF8));
        backAction->setText(QApplication::translate("MainWindow", "&Zur\303\274ck", 0, QApplication::UnicodeUTF8));
        backAction->setShortcut(QApplication::translate("MainWindow", "Alt+Left", 0, QApplication::UnicodeUTF8));
        forwardAction->setText(QApplication::translate("MainWindow", "V&orw\303\244rts", 0, QApplication::UnicodeUTF8));
        forwardAction->setShortcut(QApplication::translate("MainWindow", "Alt+Right", 0, QApplication::UnicodeUTF8));
        gotoLastEditPositionAction->setText(QApplication::translate("MainWindow", "Springe zur &letzten Bearbeitungsposition", 0, QApplication::UnicodeUTF8));
        raiseEditorAction->setText(QApplication::translate("MainWindow", "Raise Editor", 0, QApplication::UnicodeUTF8));
        nextErrorAction->setText(QApplication::translate("MainWindow", "Next Error", 0, QApplication::UnicodeUTF8));
        previousErrorAction->setText(QApplication::translate("MainWindow", "Previous Error", 0, QApplication::UnicodeUTF8));
        wordWrapAction->setText(QApplication::translate("MainWindow", "Z&eilenumbruch", 0, QApplication::UnicodeUTF8));
        showStaticWordWrapMarkerAction->setText(QApplication::translate("MainWindow", "Markierung f\303\274r s&tatischen Zeilenumbruch anzeigen", 0, QApplication::UnicodeUTF8));
        showIconBorderAction->setText(QApplication::translate("MainWindow", "Symbols&palte anzeigen", 0, QApplication::UnicodeUTF8));
        showIconBorderAction->setShortcut(QApplication::translate("MainWindow", "F6", 0, QApplication::UnicodeUTF8));
        showLineNumbersAction->setText(QApplication::translate("MainWindow", "Ze&ilennummern anzeigen", 0, QApplication::UnicodeUTF8));
        showScrollbarMarksAction->setText(QApplication::translate("MainWindow", "&Markierung f\303\274r Bildlaufleiste anzeigen", 0, QApplication::UnicodeUTF8));
        showFoldingMarkersAction->setText(QApplication::translate("MainWindow", "Markierungen &f\303\274r Code-Ausblendungen anzeigen", 0, QApplication::UnicodeUTF8));
        newSessionAction->setText(QApplication::translate("MainWindow", "&Neu", 0, QApplication::UnicodeUTF8));
        quickOpenerAction->setText(QApplication::translate("MainWindow", "Quick opener", 0, QApplication::UnicodeUTF8));
        saveSessionAction->setText(QApplication::translate("MainWindow", "S&peichern", 0, QApplication::UnicodeUTF8));
        saveSessionAsAction->setText(QApplication::translate("MainWindow", "Speichern &unter \342\200\246", 0, QApplication::UnicodeUTF8));
        parseJassSyntaxAction->setText(QApplication::translate("MainWindow", "&Jass Syntax \303\274berpr\303\274fen", 0, QApplication::UnicodeUTF8));
        parseJassSyntaxAction->setShortcut(QApplication::translate("MainWindow", "F8", 0, QApplication::UnicodeUTF8));
        parseVjassSyntaxAction->setText(QApplication::translate("MainWindow", "&vJass Syntax \303\274berpr\303\274fen", 0, QApplication::UnicodeUTF8));
        parseVjassSyntaxAction->setShortcut(QApplication::translate("MainWindow", "F9", 0, QApplication::UnicodeUTF8));
        buildApiDocumentationAction->setText(QApplication::translate("MainWindow", "API-D&okumentation erstellen", 0, QApplication::UnicodeUTF8));
        buildApiDocumentationAction->setShortcut(QApplication::translate("MainWindow", "F10", 0, QApplication::UnicodeUTF8));
        aboutVjassideAction->setText(QApplication::translate("MainWindow", "\303\234&ber vjasside", 0, QApplication::UnicodeUTF8));
        aboutPjassAction->setText(QApplication::translate("MainWindow", "\303\234ber &PJass", 0, QApplication::UnicodeUTF8));
        aboutJasshelperAction->setText(QApplication::translate("MainWindow", "\303\234ber &JassHelper", 0, QApplication::UnicodeUTF8));
        aboutVjassdocAction->setText(QApplication::translate("MainWindow", "\303\234ber vjass&doc", 0, QApplication::UnicodeUTF8));
        configureEditorAction->setText(QApplication::translate("MainWindow", "&Editor einrichten \342\200\246", 0, QApplication::UnicodeUTF8));
        aboutVjasssdkAction->setText(QApplication::translate("MainWindow", "\303\234ber vjass&sdk", 0, QApplication::UnicodeUTF8));
        aboutWc3sdkAction->setText(QApplication::translate("MainWindow", "\303\234ber &wc3sdk", 0, QApplication::UnicodeUTF8));
        aboutQtAction->setText(QApplication::translate("MainWindow", "\303\234ber &Qt", 0, QApplication::UnicodeUTF8));
        offAction->setText(QApplication::translate("MainWindow", "Off", 0, QApplication::UnicodeUTF8));
        followLineNumbersAction->setText(QApplication::translate("MainWindow", "Follow Line Numbers", 0, QApplication::UnicodeUTF8));
        alwaysOnAction->setText(QApplication::translate("MainWindow", "Always On", 0, QApplication::UnicodeUTF8));
        collapseToplevelAction->setText(QApplication::translate("MainWindow", "&Oberste Ebene einklappen", 0, QApplication::UnicodeUTF8));
        collapseToplevelAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+-", 0, QApplication::UnicodeUTF8));
        expandToplevelAction->setText(QApplication::translate("MainWindow", "Oberste Ebene &ausklappen", 0, QApplication::UnicodeUTF8));
        expandToplevelAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift++", 0, QApplication::UnicodeUTF8));
        collapseOneLocalLevelAction->setText(QApplication::translate("MainWindow", "&Eine lokale Ebene einklappen", 0, QApplication::UnicodeUTF8));
        collapseOneLocalLevelAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+-", 0, QApplication::UnicodeUTF8));
        expandOneLocalLevelAction->setText(QApplication::translate("MainWindow", "Eine &lokale Ebene ausklappen", 0, QApplication::UnicodeUTF8));
        expandOneLocalLevelAction->setShortcut(QApplication::translate("MainWindow", "Ctrl++", 0, QApplication::UnicodeUTF8));
        closeSessionAction->setText(QApplication::translate("MainWindow", "Schl&ie\303\237en", 0, QApplication::UnicodeUTF8));
        apiListAction->setText(QApplication::translate("MainWindow", "API-Liste", 0, QApplication::UnicodeUTF8));
        outputAction->setText(QApplication::translate("MainWindow", "Ausgabe", 0, QApplication::UnicodeUTF8));
        fileListAction->setText(QApplication::translate("MainWindow", "&Dateiliste", 0, QApplication::UnicodeUTF8));
        showMpqEditorAction->setText(QApplication::translate("MainWindow", "MPQ-Editor", 0, QApplication::UnicodeUTF8));
        showApiDatabaseDialogAction->setText(QApplication::translate("MainWindow", "API-Datenbanken", 0, QApplication::UnicodeUTF8));
        insertColorAction->setText(QApplication::translate("MainWindow", "Farbe einf\303\274gen", 0, QApplication::UnicodeUTF8));
        createTalkAction->setText(QApplication::translate("MainWindow", "Gespr\303\244ch erstellen", 0, QApplication::UnicodeUTF8));
        createQuestAction->setText(QApplication::translate("MainWindow", "Auftrag erstellen", 0, QApplication::UnicodeUTF8));
        deleteSessionAction->setText(QApplication::translate("MainWindow", "&L\303\266schen", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Neue Quell-Datei", 0, QApplication::UnicodeUTF8));
        fileMenu->setTitle(QApplication::translate("MainWindow", "&Datei", 0, QApplication::UnicodeUTF8));
        openRecentMenu->setTitle(QApplication::translate("MainWindow", "Zu&letzt ge\303\266ffnete Dateien", 0, QApplication::UnicodeUTF8));
        editMenu->setTitle(QApplication::translate("MainWindow", "&Bearbeiten", 0, QApplication::UnicodeUTF8));
        viewMenu->setTitle(QApplication::translate("MainWindow", "&Ansicht", 0, QApplication::UnicodeUTF8));
        codeFoldingMenu->setTitle(QApplication::translate("MainWindow", "&Code-Ausblendung", 0, QApplication::UnicodeUTF8));
        dynamicWordWrapIndicatorsMenu->setTitle(QApplication::translate("MainWindow", "Anzeigen f\303\274r d&ynamischen Zeilenumbruch", 0, QApplication::UnicodeUTF8));
        sessionsMenu->setTitle(QApplication::translate("MainWindow", "&Sitzungen", 0, QApplication::UnicodeUTF8));
        openSessionMenu->setTitle(QApplication::translate("MainWindow", "\303\226&ffnen \342\200\246", 0, QApplication::UnicodeUTF8));
        buildMenu->setTitle(QApplication::translate("MainWindow", "&Erstellen", 0, QApplication::UnicodeUTF8));
        settingsMenu->setTitle(QApplication::translate("MainWindow", "E&instellungen", 0, QApplication::UnicodeUTF8));
        helpMenu->setTitle(QApplication::translate("MainWindow", "&Hilfe", 0, QApplication::UnicodeUTF8));
        toolsMenu->setTitle(QApplication::translate("MainWindow", "&Werkzeuge", 0, QApplication::UnicodeUTF8));
        extensionsMenu->setTitle(QApplication::translate("MainWindow", "E&rweiterungen", 0, QApplication::UnicodeUTF8));
        advancedScriptLibraryMenu->setTitle(QApplication::translate("MainWindow", "Advanced Script Library", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "API-Liste", 0, QApplication::UnicodeUTF8));
        commentCheckBox->setText(QApplication::translate("MainWindow", "Kommentare", 0, QApplication::UnicodeUTF8));
        keywordCheckBox->setText(QApplication::translate("MainWindow", "Schl\303\274sselw\303\266rter", 0, QApplication::UnicodeUTF8));
        textMacroCheckBox->setText(QApplication::translate("MainWindow", "Textmakros", 0, QApplication::UnicodeUTF8));
        textMacroInstanceCheckBox->setText(QApplication::translate("MainWindow", "Textmakro-Instanzen", 0, QApplication::UnicodeUTF8));
        typeCheckBox->setText(QApplication::translate("MainWindow", "Typen", 0, QApplication::UnicodeUTF8));
        globalCheckBox->setText(QApplication::translate("MainWindow", "Globale", 0, QApplication::UnicodeUTF8));
        memberCheckBox->setText(QApplication::translate("MainWindow", "Eigenschaften", 0, QApplication::UnicodeUTF8));
        functionInterfaceCheckBox->setText(QApplication::translate("MainWindow", "Funktionsschnittstellen", 0, QApplication::UnicodeUTF8));
        functionCheckBox->setText(QApplication::translate("MainWindow", "Funktionen", 0, QApplication::UnicodeUTF8));
        methodCheckBox->setText(QApplication::translate("MainWindow", "Methoden", 0, QApplication::UnicodeUTF8));
        interfaceCheckBox->setText(QApplication::translate("MainWindow", "Schnittstellen", 0, QApplication::UnicodeUTF8));
        structCheckBox->setText(QApplication::translate("MainWindow", "Strukturen", 0, QApplication::UnicodeUTF8));
        scopeCheckBox->setText(QApplication::translate("MainWindow", "Bezugsrahmen", 0, QApplication::UnicodeUTF8));
        libraryCheckBox->setText(QApplication::translate("MainWindow", "Bibliotheken", 0, QApplication::UnicodeUTF8));
        sourceFileCheckBox->setText(QApplication::translate("MainWindow", "Quell-Dateien", 0, QApplication::UnicodeUTF8));
        documentationCommentCheckBox->setText(QApplication::translate("MainWindow", "Dokumentationskommentare", 0, QApplication::UnicodeUTF8));
        allCheckBox->setText(QApplication::translate("MainWindow", "Alle", 0, QApplication::UnicodeUTF8));
        fileListLabel->setText(QApplication::translate("MainWindow", "Dateiliste", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
