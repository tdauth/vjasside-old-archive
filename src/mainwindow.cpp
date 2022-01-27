/***************************************************************************
 *   Copyright (C) 2008, 2009 by Tamino Dauth                              *
 *   tamino@cdauth.de                                                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <QtGui>

#include "mainwindow.h"
#include "textview.h"
#include "textedit.h"
#include "session.h"
#include "apidatabasedialog.h"
#include "mpqeditor.h"
#include "pjassdialog.h"
#include "jasshelperdialog.h"
#include "vjassdocdialog.h"
#include "editorsettingsdialog.h"
#include "syntaxhighlighter.h"
#include "syntaxschema.h"
//#include "vjassdoc/object.h"

namespace vjasside
{

MainWindow::MainWindow(QSplashScreen *splashScreen) : QMainWindow(), printer(0), printDialog(0), apiDatabaseDialog(0), mpqEditor(0), pjassDialog(0), jasshelperDialog(0), vjassdocDialog(0), editorSettingsDialog(0), m_currentSyntaxSchemaIndex(0)
{
	if (splashScreen != 0)
		splashScreen->showMessage(tr("Richte Benutzeroberfläche ein …"), Qt::AlignCenter, Qt::black);

	setupUi(this);

	if (splashScreen != 0)
		splashScreen->showMessage(tr("Richte Aktionen ein …"), Qt::AlignCenter, Qt::black);

	connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));
	connect(openAction, SIGNAL(triggered()), this, SLOT(openFile()));
	connect(openRecentMenu, SIGNAL(triggered(QAction*)), this, SLOT(openRecentFile(QAction*)));
	connect(saveAction, SIGNAL(triggered()), this, SLOT(saveFile()));
	connect(saveAsAction, SIGNAL(triggered()), this, SLOT(saveFileAs()));
	connect(saveAllAction, SIGNAL(triggered()), this, SLOT(saveAllFiles()));
	connect(reloadAction, SIGNAL(triggered()), this, SLOT(reloadFile()));
	connect(revertAllAction, SIGNAL(triggered()), this, SLOT(revertAllFiles()));
	connect(printAction, SIGNAL(triggered()), this, SLOT(printFile()));
	connect(exportAsHtmlAction, SIGNAL(triggered()), this, SLOT(exportFileAsHtml()));
	connect(closeAction, SIGNAL(triggered()), this, SLOT(closeFile()));
	connect(closeAllAction, SIGNAL(triggered()), this, SLOT(closeAllFiles()));
	connect(closeAllOtherAction, SIGNAL(triggered()), this, SLOT(closeAllOtherFiles()));
	connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

	connect(undoAction, SIGNAL(triggered()), this, SLOT(undo()));
	connect(redoAction, SIGNAL(triggered()), this, SLOT(redo()));
	connect(cutAction, SIGNAL(triggered()), this, SLOT(cut()));
	connect(copyAction, SIGNAL(triggered()), this, SLOT(copy()));
	connect(copyAsHtmlAction, SIGNAL(triggered()), this, SLOT(copyAsHtml()));
	connect(pasteAction, SIGNAL(triggered()), this, SLOT(paste()));
	connect(selectAllAction, SIGNAL(triggered()), this, SLOT(selectAll()));
	connect(deselectAction, SIGNAL(triggered()), this, SLOT(deselect()));
	connect(blockSelectionModeAction, SIGNAL(triggered()), this, SLOT(blockSelectionMode()));
	connect(overwriteModeAction, SIGNAL(triggered()), this, SLOT(overwriteMode()));
	connect(findAction, SIGNAL(triggered()), this, SLOT(find()));
	connect(findNextAction, SIGNAL(triggered()), this, SLOT(findNext()));
	connect(findPreviousAction, SIGNAL(triggered()), this, SLOT(findPrevious()));
	connect(replaceAction, SIGNAL(triggered()), this, SLOT(replace()));
	connect(goToLineAction, SIGNAL(triggered()), this, SLOT(goToLine()));
	connect(findSelectReplaceAction, SIGNAL(triggered()), this, SLOT(findSelectReplace()));
	connect(findInFilesAction, SIGNAL(triggered()), this, SLOT(findInFiles()));

	connect(backAction, SIGNAL(triggered()), this, SLOT(back()));
	connect(forwardAction, SIGNAL(triggered()), this, SLOT(forward()));
	connect(gotoLastEditPositionAction, SIGNAL(triggered()), this, SLOT(gotoLastEditPosition()));
	connect(wordWrapAction, SIGNAL(triggered(bool)), this, SLOT(wordWrap(bool)));
	connect(offAction, SIGNAL(triggered(bool)), this, SLOT(off(bool)));
	connect(followLineNumbersAction, SIGNAL(triggered(bool)), this, SLOT(followLineNumbers(bool)));
	connect(alwaysOnAction, SIGNAL(triggered(bool)), this, SLOT(alwaysOn(bool)));
	connect(showStaticWordWrapMarkerAction, SIGNAL(triggered()), this, SLOT(showStaticWordWrapMarker()));
	connect(showIconBorderAction, SIGNAL(triggered()), this, SLOT(showIconBorder()));
	connect(showLineNumbersAction, SIGNAL(triggered()), this, SLOT(showLineNumbers()));
	connect(showScrollbarMarksAction, SIGNAL(triggered()), this, SLOT(showScrollbarMarks()));
	connect(showFoldingMarkersAction, SIGNAL(triggered()), this, SLOT(showFoldingMarkers()));
	connect(collapseToplevelAction, SIGNAL(triggered()), this, SLOT(collapseToplevel()));
	connect(expandToplevelAction, SIGNAL(triggered()), this, SLOT(expandToplevel()));
	connect(collapseOneLocalLevelAction, SIGNAL(triggered()), this, SLOT(collapseOneLocalLevel()));
	connect(expandOneLocalLevelAction, SIGNAL(triggered()), this, SLOT(expandOneLocalLevel()));
	
	connect(fileListDockWidget, SIGNAL(visibilityChanged(bool)), this, SLOT(fileListChangedVisibility(bool)));
	connect(apiListDockWidget, SIGNAL(visibilityChanged(bool)), this, SLOT(apiListChangedVisibility(bool)));
	connect(outputDockWidget, SIGNAL(visibilityChanged(bool)), this, SLOT(outputChangedVisibility(bool)));
	connect(showApiDatabaseDialogAction, SIGNAL(triggered()), this, SLOT(showApiDatabaseDialog()));
	connect(showMpqEditorAction, SIGNAL(triggered()), this, SLOT(showMpqEditor()));
	connect(insertColorAction, SIGNAL(triggered()), this, SLOT(insertColor()));

	connect(newSessionAction, SIGNAL(triggered()), this, SLOT(newSession()));
	connect(openSessionMenu, SIGNAL(triggered(QAction*)), this, SLOT(openSession(QAction*)));
	connect(saveSessionAction, SIGNAL(triggered()), this, SLOT(saveSession()));
	connect(saveSessionAsAction, SIGNAL(triggered()), this, SLOT(saveSessionAs()));
	connect(deleteSessionAction, SIGNAL(triggered()), this, SLOT(deleteSession()));
	connect(closeSessionAction, SIGNAL(triggered()), this, SLOT(closeSession()));

	connect(parseJassSyntaxAction, SIGNAL(triggered()), this, SLOT(parseJassSyntax()));
	connect(parseVjassSyntaxAction, SIGNAL(triggered()), this, SLOT(parseVjassSyntax()));
	connect(buildApiDocumentationAction, SIGNAL(triggered()), this, SLOT(buildApiDocumentation()));

	connect(configureEditorAction, SIGNAL(triggered()), this, SLOT(showEditorSettings()));

	connect(aboutPjassAction, SIGNAL(triggered()), this, SLOT(aboutPjass()));
	connect(aboutJasshelperAction, SIGNAL(triggered()), this, SLOT(aboutJasshelper()));
	connect(aboutVjassdocAction, SIGNAL(triggered()), this, SLOT(aboutVjassdoc()));
	connect(aboutVjasssdkAction, SIGNAL(triggered()), this, SLOT(aboutVjasssdk()));
	connect(aboutWc3sdkAction, SIGNAL(triggered()), this, SLOT(aboutWc3sdk()));
	connect(aboutVjassideAction, SIGNAL(triggered()), this, SLOT(aboutVjasside()));
	connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

	//file menu
	QAction *closeAction = new QAction(tr("Schließen"), tabWidget);
	connect(closeAction, SIGNAL(triggered()), this, SLOT(closeFile()));
	QAction *closeAllOtherAction = new QAction(tr("Alle anderen schließen"), tabWidget);
	connect(closeAllOtherAction, SIGNAL(triggered()), this, SLOT(closeAllOtherFiles()));
	
	delete textEdit; /// @todo Remove it in Designer!
	delete tab;
	
	connect(tabWidget, SIGNAL(currentChanged(int)), this, SLOT(changedCurrentTab(int)));
	connect(fileListListWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(openFileByListWidgetItem(QListWidgetItem*)));
	
	tabWidget->addAction(closeAction);
	tabWidget->addAction(closeAllOtherAction);
	fileListListWidget->addAction(closeAction);
	fileListListWidget->addAction(closeAllOtherAction);

	setFileActionsEnabled(false);
	setSessionActionsEnabled(false);
	//open files after this method call!

	//read settings
	int i, size;
	QSettings settings;
	settings.beginGroup("MainWindow");
	//instance data
	findExpression = settings.value("findExpression", "").toString();
	line = settings.value("line", 1).toInt();
	replaceExpression = settings.value("replaceExpression", "").toString();
	insertColorColor = settings.value("insertColorColor", "").toString();
	
	if (splashScreen != 0)
		splashScreen->showMessage(tr("Lade Syntax-Schemas …"), Qt::AlignCenter, Qt::black);

	size = settings.beginReadArray("syntaxSchemata");
	
	for (i = 0; i < size; ++i)
	{
		settings.setArrayIndex(i);
		SyntaxSchema *syntaxSchema = new SyntaxSchema(settings.value("name").toString());
		syntaxSchema->readFromSettings();
		m_syntaxSchemata.push_back(syntaxSchema);
		qDebug() << "Load schema " << i << " with name " << settings.value("name").toString();
	}
	
	settings.endArray();
	
	if (size == 0)
		m_syntaxSchemata.push_back(SyntaxSchema::createStandardSchema(tr("Neues Syntax-Schema")));
	
	m_currentSyntaxSchemaIndex = settings.value("currentSyntaxSchemaIndex", 0).toInt();
	
	if (splashScreen != 0)
		splashScreen->showMessage(tr("Öffne Dateien …"), Qt::AlignCenter, Qt::black);
	
	size = settings.beginReadArray("filePaths");
	
	for (i = 0; i < size; ++i)
	{
		settings.setArrayIndex(i);
		QString filePath = settings.value("filePath").toString();
		qDebug() << "Load file path " << filePath << " with index " << i;
		openFileByPath(filePath);
	}
	
	if (size == 0)
		newFile();
	else
		tabWidget->setCurrentIndex(0);
	
	settings.endArray();
	filePath = settings.value("filePath", qApp->applicationDirPath()).toString();
	
	if (splashScreen != 0)
		splashScreen->showMessage(tr("Lade Datei-Verlauf …"), Qt::AlignCenter, Qt::black);
	
	size = settings.beginReadArray("recentFiles");
	
	for (i = 0; i < size; ++i)
	{
		settings.setArrayIndex(i);
		QString filePath = settings.value("recentFile").toString();
		
		if (QFile::exists(filePath))
		{
			qDebug() << "Load recent file path " << filePath << " with index " << i;
			addRecentFile(filePath);
		}
	}
	
	settings.endArray();
	
	if (splashScreen != 0)
		splashScreen->showMessage(tr("Lade Sitzungen …"), Qt::AlignCenter, Qt::black);
	
	newSessionName = settings.value("newSessionName", "").toString();
	openSessionName = settings.value("openSessionName", "").toString();
	saveSessionName = settings.value("saveSessionName", "").toString();
	openedSessionIndex = settings.value("openedSessionIndex", -1).toInt();
	
	if (openedSessionIndex != -1)
		setSessionActionsEnabled(true);
	
	size = settings.beginReadArray("sessions");
	
	for (i = 0; i < size; ++i)
	{
		settings.setArrayIndex(i);
		Session *session = new Session(settings.value("name").toString());
		session->readFromSettings();
		qDebug() << "Load session " << i << " with name " << session->name() << " and size " << session->size() << '.';
		sessions.push_back(session);
		addRecentSession(session);
		qDebug() << "After adding recent session";
	}
	
	settings.endArray();
	//settings
	if (splashScreen != 0)
		splashScreen->showMessage(tr("Lade Einstellungen …"), Qt::AlignCenter, Qt::black);
	
	setLineNumbersAreShown(settings.value("lineNumbersAreShown", MainWindow::lineNumbersAreShownDefaultValue()).toBool());
	setTabStopWidth(settings.value("tabStopWidth", MainWindow::tabStopWidthDefaultValue()).toInt());
	setCloseFilesWhenCreatingANewSession(settings.value("closeFilesWhenCreatingANewSession", MainWindow::closeFilesWhenCreatingANewSessionDefaultValue()).toBool());
	QFont font;
	
	if (settings.contains("fontFamily"))
	{
		font.setFamily(settings.value("fontFamily", "Courier New").toString());
		font.setBold(settings.value("fontBold", false).toBool());
		font.setItalic(settings.value("fontItalic", false).toBool());
		font.setPointSize(settings.value("fontPointSize", 12).toInt());
	}
	else
		font = MainWindow::fontDefaultValue();
	
	setFont(font);
	//ui data
	setGeometry(settings.value("geometry", QRect(QPoint(0, 0), sizeHint())).toRect());
	fileListDockWidget->setVisible(settings.value("fileListVisibility", true).toBool());
	apiListDockWidget->setVisible(settings.value("apiListVisibility", true).toBool());
	outputDockWidget->setVisible(settings.value("outputVisibility", true).toBool());
	
	/*
	FIXME
	if (settings.value("mpqEditorWasShown", false).toBool())
		showMpqEditor();
	*/
	
	settings.endGroup();
}

MainWindow::~MainWindow()
{
	//write settings
	QSettings settings;
	settings.beginGroup("MainWindow");
	//instance data
	settings.setValue("findExpression", findExpression);
	settings.setValue("line", line);
	settings.setValue("replaceExpression", replaceExpression);
	settings.setValue("insertColorColor", insertColorColor.name());
	settings.beginWriteArray("syntaxSchemata");
	int i = 0;
	SyntaxSchema *syntaxSchema;
	
	foreach (syntaxSchema, m_syntaxSchemata)
	{
		settings.setArrayIndex(i);
		settings.setValue("name", syntaxSchema->name());
		syntaxSchema->writeIntoSettings();
		++i;
	}
	settings.endArray();
	settings.setValue("currentSyntaxSchemaIndex", m_currentSyntaxSchemaIndex);
	settings.beginWriteArray("filePaths");
	i = 0;
	QString filePath;
	
	foreach (filePath, saveFilePaths)
	{
		if (!filePath.isEmpty())
		{
			settings.setArrayIndex(i);
			settings.setValue("filePath", filePath);
			++i;
		}
	}
	
	settings.endArray();
	settings.setValue("filePath", filePath);
	settings.beginWriteArray("recentFiles");
	i = 0;
	QString recentFile;
	
	foreach (recentFile, recentFiles)
	{
		settings.setArrayIndex(i);
		settings.setValue("recentFile", recentFile);
		++i;
	}
	
	settings.endArray();
	settings.setValue("newSessionName", newSessionName);
	settings.setValue("openSessionName", openSessionName);
	settings.setValue("saveSessionName", saveSessionName);
	settings.setValue("openedSessionIndex", openedSessionIndex);
	settings.beginWriteArray("sessions");
	i = 0;
	class Session *session;
	
	foreach (session, sessions)
	{
		settings.setArrayIndex(i);
		settings.setValue("name", session->name());
		session->writeIntoSettings();
		++i;
	}
	
	settings.endArray();
	//settings
	settings.setValue("lineNumbersAreShown", m_lineNumbersAreShown);
	settings.setValue("tabStopWidth", m_tabStopWidth);
	settings.setValue("closeFilesWhenCreatingANewSession", m_closeFilesWhenCreatingANewSession);
	settings.setValue("fontFamily", this->font().family());
	settings.setValue("fontBold", this->font().bold());
	settings.setValue("fontItalic", this->font().italic());
	settings.setValue("fontPointSize", this->font().pointSize());
	//ui data
	settings.setValue("geometry", geometry());
	settings.setValue("fileListVisibility", fileListDockWidget->isVisible());
	settings.setValue("apiListVisibility", apiListDockWidget->isVisible());
	settings.setValue("outputVisibility", outputDockWidget->isVisible());
	settings.setValue("mpqEditorWasShown", mpqEditor != 0 && mpqEditor->isVisible());
	settings.endGroup();

	//clear instances
	if (printer != 0)
		delete printer;
	
	foreach (syntaxSchema, m_syntaxSchemata)
		delete syntaxSchema;
	
	foreach (session, sessions)
		delete session;
}

QStringList MainWindow::getFilePaths() const
{
	return filePaths;
}

void MainWindow::addSyntaxSchema(class SyntaxSchema *syntaxSchema)
{
	m_syntaxSchemata << syntaxSchema;
}

void MainWindow::removeSyntaxSchema(const int &index)
{
	delete m_syntaxSchemata.value(index);
	m_syntaxSchemata.removeAt(index);
}

void MainWindow::renameSyntaxSchema(const int &index, const QString &name)
{
	m_syntaxSchemata[index]->setName(name);
}

QList<class SyntaxSchema*> MainWindow::syntaxSchemata() const
{
	return m_syntaxSchemata;
}

void MainWindow::setCurrentSyntaxSchemaIndex(int index)
{
	m_currentSyntaxSchemaIndex = index;
}

int MainWindow::currentSyntaxSchemaIndex() const
{
	return m_currentSyntaxSchemaIndex;
}

SyntaxSchema* MainWindow::currentSyntaxSchema() const
{
	return m_syntaxSchemata.value(m_currentSyntaxSchemaIndex);
}

void MainWindow::rehighlightAllFiles()
{
	if (tabWidget->currentIndex() == -1)
		return;
	
	for (int i = 0; i < tabWidget->count(); ++i)
		syntaxHighlighters[i]->rehighlight();
}

void MainWindow::showObjectInfo(const vjassdoc::Object *object)
{
	//outputTextBrowser->setHtml(QString(object->identifier().data()));
}

void MainWindow::setLineNumbersAreShown(bool lineNumbersAreShown)
{
	if (m_lineNumbersAreShown == lineNumbersAreShown)
	{
		qDebug() << "m_lineNumbersAreShown already has the set value.";
		return;
	}

	m_lineNumbersAreShown = lineNumbersAreShown;
	
	/*
	if (showLineNumbers)
		show
	else
		hide
	*/
}

bool MainWindow::lineNumbersAreShown() const
{
	return m_lineNumbersAreShown;
}

void MainWindow::setAutomaticIndention(bool enable)
{
	this->m_automaticIndention = enable;
}

bool MainWindow::automaticIndention() const
{
	return this->m_automaticIndention;
}

void MainWindow::setTabStopWidth(int tabStopWidth)
{
	if (m_tabStopWidth == tabStopWidth)
	{
		qDebug() << "m_tabStopWidth already has the set value.";
		return;
	}
	
	m_tabStopWidth = tabStopWidth;
	
	for (int i = tabWidget->count() - 1; i >= 0; --i)
		static_cast<TextView*>(tabWidget->widget(i))->textEdit->setTabStopWidth(tabStopWidth);
}

int MainWindow::tabStopWidth() const
{
	return m_tabStopWidth;
}

void MainWindow::setCloseFilesWhenCreatingANewSession(bool closeFilesWhenCreatingANewSession)
{
	m_closeFilesWhenCreatingANewSession = closeFilesWhenCreatingANewSession;
}

bool MainWindow::closeFilesWhenCreatingANewSession() const
{
	return this->m_closeFilesWhenCreatingANewSession;
}

void MainWindow::setFont(QFont font)
{
	if (font == this->m_font)
		return;

	this->m_font = font;

	emit fontChanged(font);
}

QFont MainWindow::font() const
{
	return this->m_font;
}

QString MainWindow::commonjPath()
{
	QString path(qApp->applicationDirPath() + "/scripts/common.j");
		
	if (QFile::exists(path))
		return path;
	
	QMessageBox::warning(this, tr("common.j-Datei"), tr("Die Datei \"%1\" existiert nicht.").arg(path));
	
	return QString();
}

QString MainWindow::commonaiPath()
{
	QString path(qApp->applicationDirPath() + "/scripts/common.ai");
		
	if (QFile::exists(path))
		return path;
	
	QMessageBox::warning(this, tr("common.ai-Datei"), tr("Die Datei \"%1\" existiert nicht.").arg(path));
	
	return QString();
}

QString MainWindow::blizzardjPath()
{
	QString path(qApp->applicationDirPath() + "/scripts/Blizzard.j");
		
	if (QFile::exists(path))
		return path;
	
	QMessageBox::warning(this, tr("Blizzard.j-Datei"), tr("Die Datei \"%1\" existiert nicht.").arg(path));
	
	return QString();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	qDebug("closeEvent");
	
	saveFilePaths = filePaths; //backup
	
	closeAllFiles();
	
	if (!allFilesWereClosed())
	{
		event->ignore();
		return;
	}
	
	event->accept();
}

void MainWindow::newFile()
{
	createNewFile();
	
	qDebug("Before refreshing window title.");
	tabWidget->setCurrentIndex(tabWidget->count() - 1); //change tab after inserting a new row
}

void MainWindow::openFile()
{
	QStringList files = QFileDialog::getOpenFileNames(this, tr("Datei öffnen"), this->filePath, tr("Alle Dateien (*);;Jass-Dateien (*.j *.J);;KI-Dateien (*.ai *.AI)")); /// @todo Directories, too

	if (files.isEmpty())
		return;

	this->filePath = files.first();
	int i = 0;
		
	for (QStringList::iterator iterator = files.begin(); iterator != files.end(); ++iterator)
	{
		if (!fileIsAlreadyOpened(*iterator, i == files.size() - 1))
			openFileByPath(*iterator);
		
		++i;
	}
}

void MainWindow::openRecentFile(QAction *action)
{
	QString filePath = action->data().toString();
	
	if (!fileIsAlreadyOpened(filePath, true))
		openFileByPath(filePath);
}

void MainWindow::saveFile()
{
	if (filesWereSaved[tabWidget->currentIndex()])
	{
		qDebug("File was already saved.");
		
		return;
	}
	
	saveFileByIndex(tabWidget->currentIndex());
}

void MainWindow::saveFileAs()
{
	saveFileAsByIndex(tabWidget->currentIndex());
}

void MainWindow::saveAllFiles()
{
	if (allFilesWereClosed())
		return; //could be called by save session. Even the session has 0 files.
	
	for (int i = tabWidget->count() - 1; i >= 0; --i)
	{
		if (!filesWereSaved[i])
			saveFileByIndex(i);
		
		qDebug() << "Save file " << i;
		//saveFile();
		
		if (!filesWereSaved[i])
			break;
	}
}

void MainWindow::reloadFile()
{
}

void MainWindow::revertAllFiles()
{
}

void MainWindow::printFile()
{
	if (printer == 0)
	{
		printer = new QPrinter(QPrinter::ScreenResolution);
		printDialog = new QPrintDialog(printer, this);
	}
	
	printDialog->show();
	
	if (printDialog->exec() == QDialog::Accepted)
	{
		int start = printer->fromPage();
		int end = printer->toPage();
		
		qDebug() << "start " << start << " end " << end;
		
		if (start == 0 && end == 0)
		{
			start = 0;
			end = tabWidget->count();
			qDebug() << "Print all.\n start " << start << " end " << end;
		}
		else
			start -= 1;
		
		
		qDebug() << "start " << start << " end " << end;
		
		for ( ; start < end; ++start)
		{
			qDebug() << "Print " << start;
			static_cast<TextView*>(tabWidget->widget(start))->textEdit->print(printer);
		}
	}
}

void MainWindow::exportFileAsHtml()
{
	this->filePath = QFileDialog::getSaveFileName(this, tr("Als HTML exportieren"), this->filePath, tr("Alle Dateien (*);;HTML-Dateien (*.html *.HTML)"));

	if (this->filePath.isEmpty())
		return;
		
	QFile file(filePath);
	qDebug() << "File path: " << filePath;
	
	if (!file.open(QIODevice::WriteOnly)) // | QIODevice::Text
		qDebug("Couldn't open the file.");

	QTextStream textStream(&file);
	class TextEdit *textEdit = static_cast<class TextView*>(tabWidget->widget(tabWidget->currentIndex()))->textEdit;
	textStream << textEdit->toHtml();
}

void MainWindow::closeFile()
{
	closeFileByIndex(tabWidget->currentIndex());
}

void MainWindow::closeAllFiles()
{
	for (int i = tabWidget->count() - 1; i >= 0; --i)
	{
		closeFileByIndex(i);
		
		if (tabWidget->count() != i)
			break;
	}
}

void MainWindow::closeAllOtherFiles()
{
	int index = tabWidget->currentIndex();

	for (int i = tabWidget->count() - 1; i >= 0; --i)
	{
		if (i != index)
			closeFileByIndex(i);
	}
}

void MainWindow::undo()
{
	static_cast<TextView*>(tabWidget->widget(tabWidget->currentIndex()))->textEdit->undo();
}

void MainWindow::redo()
{
	static_cast<TextView*>(tabWidget->widget(tabWidget->currentIndex()))->textEdit->redo();
}

void MainWindow::cut()
{
	static_cast<TextView*>(tabWidget->widget(tabWidget->currentIndex()))->textEdit->cut();
}

void MainWindow::copy()
{
	static_cast<TextView*>(tabWidget->widget(tabWidget->currentIndex()))->textEdit->copy();
}

void MainWindow::copyAsHtml()
{
	//static_cast<TextView*>(tabWidget->widget(tabWidget->currentIndex()))->textEdit->textCursor()
	/// @todo FIX PLS
}

void MainWindow::paste()
{
	static_cast<TextView*>(tabWidget->widget(tabWidget->currentIndex()))->textEdit->paste();
}

void MainWindow::selectAll()
{
	static_cast<TextView*>(tabWidget->widget(tabWidget->currentIndex()))->textEdit->selectAll();
}

//Since there is no pointer available you have to create a new cursor.
void MainWindow::deselect()
{
	TextEdit *textEdit = static_cast<TextView*>(tabWidget->widget(tabWidget->currentIndex()))->textEdit;
	QTextCursor textCursor = textEdit->textCursor();
	textCursor.clearSelection();
	textEdit->setTextCursor(textCursor);
	
}

/// @todo FIX PLS
void MainWindow::blockSelectionMode()
{
}

void MainWindow::overwriteMode()
{
	TextEdit *textEdit = static_cast<TextView*>(tabWidget->widget(tabWidget->currentIndex()))->textEdit;
	textEdit->setOverwriteMode(!textEdit->overwriteMode());
}

/// @todo Create a custom find dialog with case sensitivity options etc.
void MainWindow::find()
{
	bool ok;
	findExpression = QInputDialog::getText(this, tr("Suchen"), tr("Ausdruck:"), QLineEdit::Normal, findExpression, &ok);

	if (ok)
		searchForExpression(true);
}

void MainWindow::findNext()
{
	searchForExpression(true);
}

void MainWindow::findPrevious()
{
	searchForExpression(false);
}

void MainWindow::replace()
{
	bool ok;
	replaceExpression = QInputDialog::getText(this, tr("Ersetzen"), tr("Ausdruck:"), QLineEdit::Normal, replaceExpression, &ok);

	/// @todo FIX PLS
}

/// @todo FIX PLS
void MainWindow::goToLine()
{
	TextEdit *textEdit = static_cast<TextView*>(tabWidget->widget(tabWidget->currentIndex()))->textEdit;
	bool ok;
	line = QInputDialog::getInteger(this, tr("Gehe zu Zeile"), tr("Gehe zu Zeile:"), line, 0, textEdit->document()->blockCount(), 1, &ok);

	if (ok)
	{
		QTextCursor textCursor = textEdit->textCursor();
		//textCursor.setPosition(textEdit->document()->findBlockByNumber(line).position()); //not working
		//qDebug() << "Position " << textEdit->document()->findBlockByNumber(line).position() << " for line " << line; //UNCOMMENT
		textEdit->setTextCursor(textCursor);
	}
}

/// @todo FIX ME
void MainWindow::findSelectReplace()
{
}

/// @todo FIX ME
void MainWindow::findInFiles()
{
}

void MainWindow::back()
{
	if (tabWidget->currentIndex() == 0)
	{
		tabWidget->setCurrentIndex(tabWidget->count() - 1);
		return;
	}

	tabWidget->setCurrentIndex(tabWidget->currentIndex() - 1);
}

void MainWindow::forward()
{
	if (tabWidget->currentIndex() == tabWidget->count() - 1)
	{
		tabWidget->setCurrentIndex(0);
		return;
	}

	tabWidget->setCurrentIndex(tabWidget->currentIndex() + 1);
}

/// @todo FIX ME
void MainWindow::gotoLastEditPosition()
{
}

/// @todo FIX ME
void MainWindow::wordWrap(bool checked)
{
	
}

/// @todo FIX ME
void MainWindow::off(bool checked)
{
}

/// @todo FIX ME
void MainWindow::followLineNumbers(bool checked)
{
	if (dynamicWordWrapIndicatorsMenu->activeAction() != followLineNumbersAction)
	{
		dynamicWordWrapIndicatorsMenu->setActiveAction(followLineNumbersAction);
	}

}

/// @todo FIX ME
void MainWindow::alwaysOn(bool checked)
{
}

/// @todo FIX ME
void MainWindow::showStaticWordWrapMarker()
{
}

/// @todo FIX ME
void MainWindow::showIconBorder()
{
}

void MainWindow::showLineNumbers()
{
	m_lineNumbersAreShown = !m_lineNumbersAreShown;
	
	if (!m_lineNumbersAreShown)
		showLineNumbersAction->setText(tr("Ze&ilennummern anzeigen"));
	else
		showLineNumbersAction->setText(tr("Ze&ilennummern ausblenden"));
}

/// @todo FIX ME
void MainWindow::showScrollbarMarks()
{
}

/// @todo FIX ME
void MainWindow::showFoldingMarkers()
{
}

/// @todo FIX ME
void MainWindow::collapseToplevel()
{
}

/// @todo FIX ME
void MainWindow::expandToplevel()
{
}

/// @todo FIX ME
void MainWindow::collapseOneLocalLevel()
{
}

/// @todo FIX ME
void MainWindow::expandOneLocalLevel()
{
}

void MainWindow::showApiDatabaseDialog()
{
	if (apiDatabaseDialog == 0)
	{
		apiDatabaseDialog = new ApiDatabaseDialog(this);
		connect(apiDatabaseDialog, SIGNAL(accepted()), this, SLOT(apiDatabaseDialogWasHidden()));
		connect(apiDatabaseDialog, SIGNAL(rejected()), this, SLOT(apiDatabaseDialogWasHidden()));
	}
	
	showApiDatabaseDialogAction->setEnabled(false);
	apiDatabaseDialog->show();
}

void MainWindow::showMpqEditor()
{
	if (mpqEditor == 0)
	{
		mpqEditor = new MpqEditor(this);
		connect(mpqEditor, SIGNAL(rejected()), this, SLOT(mpqEditorWasRejected()));
	}
	
	showMpqEditorAction->setEnabled(false);
	mpqEditor->show();
}

void MainWindow::insertColor()
{
	insertColorColor = QColorDialog::getColor(insertColorColor, this);
	
	if (!insertColorColor.isValid())
		return;
	
	TextEdit *textEdit = static_cast<TextView*>(tabWidget->currentWidget())->textEdit;
	textEdit->textCursor().insertText("|c00" + insertColorColor.name().remove("#") + "|r");
}

void MainWindow::newSession()
{
	if (openedSessionIndex != -1)
	{
		QMessageBox::StandardButton result = showSessionMessageBox();
		
		if (result == QMessageBox::Save)
		{
			saveSessionByIndex(openedSessionIndex);
		
			if (!allFilesWereSaved()) //canceled
				return;
		}
		else if (result == QMessageBox::Cancel)
			return;
	}

	bool ok;
	QString name = QInputDialog::getText(this, tr("Neue Sitzung"), tr("Sitzungsname:"), QLineEdit::Normal, newSessionName, &ok);

	if (!ok)
		return;

	if (name.isEmpty())
	{
		QMessageBox::warning(this, tr("Neue Sitzung"), tr("Sitzungsname darf nicht leer sein."));
		newSession();
		return;
	}
	
	if (m_closeFilesWhenCreatingANewSession)
	{
		closeAllFiles();
	
		if (!allFilesWereClosed())
			return;
	}

	Session *session = new Session(name);
	sessions << session;
	session->writeIntoSettings();
	openedSessionIndex = addRecentSession(session);
	setSessionActionsEnabled(true);
}

void MainWindow::openSession(QAction *action)
{
	int index = action->data().toInt();
	
	if (index == openedSessionIndex)
	{
		qDebug() << "Session is already opened.";
		return;
	}
	
	openSessionByIndex(index);
}

void MainWindow::saveSession()
{
	saveSessionByIndex(openedSessionIndex);
}

void MainWindow::saveSessionAs()
{
	bool ok;
	QString name = QInputDialog::getText(this, tr("Sitzung speichern unter"), tr("Sitzungsname:"), QLineEdit::Normal, saveSessionName, &ok);
	
	if (!ok)
		return;
	
	int i = 0;
	const class Session *session;
	
	foreach (session, sessions)
	{
		if (session->name() == name)
		{
			if (i != openedSessionIndex)
				QMessageBox::warning(this, tr("Sitzung speichern unter"), tr("Es existiert bereits eine Sitzung unter diesem Namen."));
			else
				QMessageBox::warning(this, tr("Sitzung speichern unter"), tr("Die geöffnete Sitzung trägt bereits diesen Namen."));
			
			return;
		}
		
		++i;
	}
	
	sessions[openedSessionIndex]->rename(name);
	saveSession();
}

void MainWindow::deleteSession()
{
	if (QMessageBox::question(this, tr("Sitzung löschen"), tr("Möchten Sie die geöffnete Sitzung wirklich löschen?"), QMessageBox::Ok | QMessageBox::Cancel) == QMessageBox::Cancel)
		return;

	this->deleteSessionByIndex(this->openedSessionIndex);
}

void MainWindow::closeSession()
{
	saveAllFiles();

	if (!allFilesWereSaved())
		return;
	
	QMessageBox::StandardButton result = showSessionMessageBox();
	
	if (result == QMessageBox::Discard)
	{
		closeOpenedSession();
		return;
	}
	else if (result == QMessageBox::Cancel)
		return;
	
	saveSession();
	closeOpenedSession();
}

void MainWindow::parseJassSyntax()
{	
	saveAllFiles();

	if (!allFilesWereSaved())
		return;

	if (pjassDialog == 0)
		pjassDialog = new PjassDialog(this);

	pjassDialog->show();
}

void MainWindow::parseVjassSyntax()
{
/*
	NOTE Files aren't used.
	saveAllFiles();

	if (!allFilesWereSaved())
		return;
*/

	if (jasshelperDialog == 0)
		jasshelperDialog = new JasshelperDialog(this);

	jasshelperDialog->show();
}

void MainWindow::buildApiDocumentation()
{
	saveAllFiles();

	if (!allFilesWereSaved())
		return;

	if (vjassdocDialog == 0)
		vjassdocDialog = new VjassdocDialog(this);

	vjassdocDialog->show();
}

void MainWindow::showEditorSettings()
{
	if (editorSettingsDialog == 0)
		editorSettingsDialog = new EditorSettingsDialog(this);

	editorSettingsDialog->show();
}

void MainWindow::aboutPjass()
{
	QMessageBox::information(this, tr("About PJass"), tr(
	"pjass 11052005<br>"
	"A lightweight and fast Jass2 parser for bison/yacc<br>"
	"by Rudi Cilibrasi<br>"
	"Sun Jun  8 00:51:53 CEST 2003<br>"
	"thanks to Jeff Pang for the handy documentation that this was based<br>"
	"on at http://jass.sourceforge.net/<br>"
	"Released under the BSD license<br>"
	"<br>"
	"To use this program, list the files you would like to parse in order.<br>"
	"If you would like to parse from standard input (the keyboard), then<br>"
	"use - as an argument.  If you supply no arguments to pjass, it will<br>"
	"parse the console standard input by default.<br>"
	"<br>"
	"To test this program:<br>"
	"pjass common.j common.ai Blizzard.j<br>"
	"<br>"
	"You can find news about this program and updates at<br>"
	"http://jass.sourceforge.net/<br>"
	"<br>"
	"Please send comments to<br>"
	"Rudi Cilibrasi<br>"
	"cilibrar@ofb.net<br>"
	));
}

void MainWindow::aboutJasshelper()
{
	QMessageBox::information(this, tr("About JassHelper"), tr(
	"[This is a ZLib/PNG license - OSI approved]<br>"
	"<br>"
	"Copyright (c) 2006 V�ctor Hugo Sol�z K�ncar<br>"
	"<br>"
	"This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for<br>"
	"any damages arising from the use of this software.<br>"
	"<br>"
	"Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and<br>"
	"redistribute it freely, subject to the following restrictions:<br>"
	"<br>"
	"\t1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software.<br>"
	"If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not<br>"
	"required.<br>"
	"<br>"
	"\t2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.<br>"
	"<br>"
	"\t3. This notice may not be removed or altered from any source distribution.<br>"
	"<br>"
	"<br>"
	"--<br>"
	"For this project, the Gold parsing system was used which is also licensed with a Zlib/PNG-like license<br>"
	"http://www.devincook.com/goldparser/<br>"
	"<br>"
	"See source\\gold\\License.txt for more information.<br>"
	));
}

void MainWindow::aboutVjassdoc()
{
	QMessageBox::information(this, tr("Über vjassdoc"), tr(
	"vjassdoc ist ein Programm zur Generierung einer API-<br>"
	"Dokumentation aus Jass- oder vJass-Code. Ebenso ist es<br>"
	"möglich mit vjassdoc API-Datenbanken zu erstellen, welche<br>"
	"unter anderem von vjasside zur Code-Vervollständigung genutzt<br>"
	"werden.<br>"
	"Es wurde von Tamino Dauth entwickelt."
	));
}

void MainWindow::aboutVjasssdk()
{
	QMessageBox::information(this, tr("Über vjasssdk"), tr(
	"vjasssdk beschreibt das SDK (Software Development Kit –<br>"
	"Software-Entwicklungskasten) zur Arbeit mit den Skriptsprachen<br>"
	"Jass und vJass. Es besteht aus den Programmen PJass, JassHelper,<br>"
	"vjassdoc und vjasside.<br>"
	"Das Programm PJass wurde von Rudi Cilibrasi entwickelt.<br>"
	"Das Programm JassHelper wurde von V�ctor Hugo Sol�z K�ncar entwickelt.<br>"
	"Die Programme vjassdoc und vjasside wurden von Tamino Dauth entwickelt."
	));
}

void MainWindow::aboutWc3sdk()
{
	QMessageBox::information(this, tr("Über wc3sdk"), tr(
	"wc3sdk ist ein SDK (Software Development Kit –<br>"
	"Software-Entwicklungskasten) für das Spiel Warcraft<br>"
	"3 – The Frozen Throne von Blizzard Entertainment.<br>"
	"Es besteht aus der ASL (Advanced Script Library – erweiterte<br>"
	"Skript-Bibliothek) und einigen MPQ-Archiven mit nützlichen Dateien.<br>"
	"Die ASL wurde von Tamino Dauth entwickelt. Die restlichen<br>"
	"Dateien stammen von einer Vielzahl unterschiedlicher Entwickler<br>"
	"und wurden ebenfalls von Tamino Dauth zusammengetragen."
	));
}

void MainWindow::aboutVjasside()
{
	QMessageBox::information(this, tr("Über vjasside"), tr(
	"vjasside ist eine IDE (Integrated Development Environment<br>"
	"– integrierte Entwicklungsumgebung) für die Skriptsprachen Jass<br>"
	"und vJass.<br>"
	"Sie wurde von Tamino Dauth entwickelt."
	));
}

void MainWindow::setFileListRow(int row)
{
	fileListListWidget->setCurrentRow(row);
}

void MainWindow::openFileByListWidgetItem(QListWidgetItem *item)
{
	tabWidget->setCurrentIndex(fileListListWidget->row(item));
}


void MainWindow::fileListChangedVisibility(bool visible)
{
	fileListAction->setChecked(visible);
}

void MainWindow::apiListChangedVisibility(bool visible)
{
	apiListAction->setChecked(visible);
}

void MainWindow::outputChangedVisibility(bool visible)
{
	outputAction->setChecked(visible);
}

void MainWindow::fileWasChanged(int index)
{
	qDebug() << "File " << index << " was changed.";

	if (filesWereSaved[index])
	{
		filesWereSaved[index] = false;
		showFileSavedIcon(index, false);
		setWindowTitleForFile(index);
		//setFileTextDataByIndex(index);
	}
}

void MainWindow::undoAvailable(int index, bool available)
{
	qDebug("undoAvailable");

	if (!available)
	{
		qDebug() << "Undo is not available for index " << index;
		filesWereSaved[index] = true;
		showFileSavedIcon(index, true);
		//setFileTextDataByIndex(index);
	}
}

void MainWindow::refreshWindowTitle()
{
	int index = tabWidget->currentIndex();
	
	/*
	new file was created - window title will be refreshed by the newFile() method.
	This time this method was called by the signal of changing the current tab.
	*/
	//if (index >= filePaths.size())
		//return;
	
	qDebug() << "Index " << index << " file paths " << filePaths.size();
	
	if (index == -1)
	{
		setWindowTitle(tr("vjasside"));
		return;
	}
	else if (index >= filePaths.size())
		return;

	//refresh window title
	setWindowTitleForFile(index);
}

void MainWindow::changedCurrentTab(int index)
{
	static int lastIndex = -1;

	qDebug() << "Last index " << lastIndex << " and index " << index;

	if (lastIndex != -1 && tabWidget->widget(lastIndex) != 0)
	{
		qDebug() << "changed to index " << index << " with last index " << lastIndex;
		TextEdit *textEdit = static_cast<TextView*>(tabWidget->widget(lastIndex))->textEdit;
		disconnect(textEdit, SIGNAL(undoAvailable(bool)), undoAction, SLOT(setEnabled(bool)));
		disconnect(textEdit, SIGNAL(redoAvailable(bool)), redoAction, SLOT(setEnabled(bool)));
		disconnect(textEdit, SIGNAL(copyAvailable(bool)), cutAction, SLOT(setEnabled(bool)));
		disconnect(textEdit, SIGNAL(copyAvailable(bool)), copyAction, SLOT(setEnabled(bool)));
		disconnect(textEdit, SIGNAL(copyAvailable(bool)), copyAsHtmlAction, SLOT(setEnabled(bool)));
		disconnect(textEdit, SIGNAL(copyAvailable(bool)), deselectAction, SLOT(setEnabled(bool)));
	}

	if (index != -1)
	{
		TextEdit *textEdit = static_cast<TextView*>(tabWidget->widget(index))->textEdit;
		undoAction->setEnabled(textEdit->canUndo());
		redoAction->setEnabled(textEdit->canRedo());
		copyAction->setEnabled(textEdit->canCopy());
		connect(textEdit, SIGNAL(undoAvailable(bool)), undoAction, SLOT(setEnabled(bool)));
		connect(textEdit, SIGNAL(redoAvailable(bool)), redoAction, SLOT(setEnabled(bool)));
		connect(textEdit, SIGNAL(copyAvailable(bool)), cutAction, SLOT(setEnabled(bool)));
		connect(textEdit, SIGNAL(copyAvailable(bool)), copyAction, SLOT(setEnabled(bool)));
		connect(textEdit, SIGNAL(copyAvailable(bool)), copyAsHtmlAction, SLOT(setEnabled(bool)));
		connect(textEdit, SIGNAL(copyAvailable(bool)), deselectAction, SLOT(setEnabled(bool)));
		setFileListRow(index);
	}
	
	refreshWindowTitle();
	lastIndex = index;
}

void MainWindow::apiDatabaseDialogWasHidden()
{
	showApiDatabaseDialogAction->setEnabled(true);
}

void MainWindow::mpqEditorWasRejected()
{
	showMpqEditorAction->setEnabled(true);
}

void MainWindow::setFileActionsEnabled(bool enabled)
{
	saveAction->setEnabled(enabled);
	saveAsAction->setEnabled(enabled);
	saveAllAction->setEnabled(enabled);
	reloadAction->setEnabled(enabled);
	revertAllAction->setEnabled(enabled);
	printAction->setEnabled(enabled);
	exportAsHtmlAction->setEnabled(enabled);
	closeAction->setEnabled(enabled);
	closeAllAction->setEnabled(enabled);
	closeAllOtherAction->setEnabled(enabled);
	editMenu->menuAction()->setEnabled(enabled);
	viewMenu->menuAction()->setEnabled(enabled);
	insertColorAction->setEnabled(enabled);
	buildMenu->menuAction()->setEnabled(enabled);

	if (enabled)
	{
		tabWidget->setContextMenuPolicy(Qt::ActionsContextMenu);
		fileListListWidget->setContextMenuPolicy(Qt::ActionsContextMenu);
	}
	else
	{
		tabWidget->setContextMenuPolicy(Qt::DefaultContextMenu);
		fileListListWidget->setContextMenuPolicy(Qt::DefaultContextMenu);
	}
}

void MainWindow::addRecentFile(const QString &filePath)
{
	if (recentFiles.contains(filePath))
		return;

	if (recentFiles.size() == maxRecentFiles)
		recentFiles.removeLast();

	recentFiles.prepend(filePath);
	
	if (recentFiles.size() < maxRecentFiles)
		openRecentMenu->addAction(QString());
	
	int index = 0;
	QStringList::const_iterator path = recentFiles.constBegin();
	QAction *action;
	
	foreach (action, openRecentMenu->actions())
	{
		action->setData(*path);
		action->setText(tr("&%1 – %2").arg(index).arg(*path));
		++index;
		++path;
	}
}

void MainWindow::renameRecentFileAction(const int &index, const QString &filePath)
{
	openRecentMenu->actions()[index]->setText(QString(tr("&%1 – %2")).arg(recentFiles.size()).arg(filePath));
	openRecentMenu->actions()[index]->setData(filePath);
	recentFiles[index] = filePath;
}

//Mustn't change the current tab!
void MainWindow::createNewFile()
{	
	//static cast doesn't work for the first tab	
	class TextView *textView = new TextView(tabWidget, this, tabWidget->count());
	class TextEdit *textEdit = textView->textEdit;
	syntaxHighlighters << new SyntaxHighlighter(textEdit, this);
	tabWidget->addTab(textView, QIcon(":/images/mimetypes/jasssource.png"), tr("Neue Quell-Datei")); //don't move this into the method call below!
	QListWidgetItem *item = new QListWidgetItem(tr("Neue Quell-Datei"), fileListListWidget);
	item->setData(Qt::DecorationRole, QIcon(":/images/mimetypes/jasssource.png"));
	fileListListWidget->addItem(item);
	filesWereSaved << true;
	filePaths << QString("");
	connect(textView, SIGNAL(contentChanged(int)), this, SLOT(fileWasChanged(int)));
	connect(textView, SIGNAL(undoAvailable(int, bool)), this, SLOT(undoAvailable(int, bool)));

	if (tabWidget->count() == 1)
		setFileActionsEnabled(true);
}

void MainWindow::openFileByPath(const QString &filePath)
{
	QFileInfo fileInfo(filePath);

	if (!fileInfo.exists())
	{
		QMessageBox::critical(this, tr("Datei öffnen"), tr("Die Datei \"%1\" existiert nicht.").arg(filePath));
		return;
	}
	else if (!fileInfo.isReadable())
	{
		QMessageBox::critical(this, tr("Datei öffnen"), tr("Die Datei \"%1\" ist nicht lesbar.").arg(filePath));
		return;
	}
	else if (!fileInfo.isWritable())
	{
		if (QMessageBox::question(this, tr("Datei öffnen"), tr("Die Datei \"%1\" ist nicht schreibbar.<br>Trotzdem öffnen?").arg(filePath), QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
			return;
	}
	
	if (fileInfo.isDir())
	{
		QString pathIterator;
		
		foreach (pathIterator, fileInfo.dir().entryList(QDir::Files, QDir::Name)) /// @todo Open sub directories?
			this->openFileByPath(pathIterator);
		
		return;
	}

	addRecentFile(filePath);
	createNewFile(); //without changing the current tab
	int index = tabWidget->count() - 1;
	filePaths.replace(index, filePath);
	class TextView *textView = static_cast<class TextView*>(tabWidget->widget(index));
	textView->openFile(filePath);
	setFileTextDataByIndex(index);
}

bool MainWindow::fileIsAlreadyOpened(const QString &filePath, bool refresh)
{
	int i = 0;
	QString iterator;
	
	foreach (iterator, filePaths)
	{
		if (filePath == iterator)
		{
			if (refresh)
				tabWidget->setCurrentIndex(i);
			
			return true; //file is already opened
		}
		
		++i;
	}
	
	return false;
}

void MainWindow::saveFileByIndex(const int &index)
{
	QString filePath = filePaths[index];
	
	if (filePath.isEmpty())
	{
		saveFileAsByIndex(index);
		return;
	}

	//addRecentFile(*iterator); //add recent if the file was never saved before

	QFile file(filePath);
	
	if (!file.open(QIODevice::WriteOnly)) // | QIODevice::Text
	{
		QMessageBox::critical(this, tr("Datei speichern"), tr("Datei konnte nicht gespeichert werden."));
		return;
	}

	QTextStream textStream(&file);
	class TextEdit *textEdit = static_cast<TextView*>(tabWidget->widget(index))->textEdit;
	textStream << textEdit->toPlainText();
	setFileTextDataByIndex(index);
	filesWereSaved[index] = true;
	
	if (index == tabWidget->currentIndex())
		setWindowTitleForFile(index);
	else
		showFileSavedIcon(index, true);
/*
	if (checkFileOverwritting())
	{
		//Use indexOf?
		int i = 0;
		QString iterator;
		
		foreach (iterator, filePaths)
		{
			qDebug() << "Comparing with file path " << iterator << " and index " << i;
			
			if (iterator == filePaths[index] && i != index)
			{
				qDebug() << "Has overwritten file of tab " << i;
				filesWereSaved[i] = false; //has overwritten a file of an opened file
				filePaths[i] = QString(); //save it new
				QMessageBox::warning(this, tr("Achtung"), tr("Sie haben eine andere geöffnete Datei überschrieben."));
				tabWidget->setCurrentIndex(i);
				saveFile();
			}
			
			++i;
		}
	}
*/
}

void MainWindow::saveFileAsByIndex(const int &index)
{
	QString newFilePath = QFileDialog::getSaveFileName(this, tr("Datei speichern"), this->filePath, tr("Alle Dateien (*);;Jass-Dateien (*.j *.J);;KI-Dateien (*.ai *.AI)"));
	
	if (newFilePath.isEmpty())
		return;
	else if (newFilePath == filePaths[index] && filesWereSaved[index])
	{
		qDebug("File was already saved.");
		return;
	}

	this->filePath = newFilePath;
	//Use indexOf?
	int i = 0;
	QString iterator;

	foreach (iterator, filePaths)
	{
		qDebug() << "Comparing with file path " << iterator << " and index " << i;
		
		if (i != index && iterator == this->filePath)
		{
			qDebug() << "Has overwritten file tab " << index;
			QMessageBox::warning(this, tr("Datei speichern unter"), tr("Eine andere geöffnete Datei verwendet bereits diesen Pfad."));
			saveFileAsByIndex(index);
			return;
		}
		++i;
	}

	//was saved first time	
	if (filePaths[index].isEmpty())
		addRecentFile(this->filePath);
	else
		renameRecentFileAction(index, this->filePath);
	
	filePaths[index] = this->filePath;
	saveFileByIndex(index);
	qDebug() << "after saving file with path " << filePaths[index] << " in tab " << index;
}

void MainWindow::closeFileByIndex(const int &index)
{
	
	if (!filesWereSaved[index])
	{
		int result = QMessageBox::question(this, tr("Dokument schließen"), tr("Dokument \"%1\" wurde geändert.<br>Möchten Sie die Änderungen speichern oder verwerfen?").arg(tabWidget->tabText(index)), QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
		
		if (result == QMessageBox::Save)
			saveFile();
		else if (result == QMessageBox::Cancel)
			return;
	}

/*
	if (index != tabWidget->count() - 1)
	{
		for (int i = index + 1; i != filesWereSaved.size(); ++i)
			filesWereSaved[i - 1] = filesWereSaved[i];

		for (int i = index + 1; i != filePaths.size(); ++i)
			filePaths[i - 1] = filePaths[i];
	}
*/

	tabWidget->removeTab(index);
	fileListListWidget->takeItem(index);
	filesWereSaved.removeAt(index); //test!
	filePaths.removeAt(index);
	syntaxHighlighters.remove(index);


	/// DO NOT DELET AND REMOVE THE TEXT EDIT!
	/// There is a documentation error which says that the page itself is not remove, I think.

	if (allFilesWereClosed())
		setFileActionsEnabled(false);
}

inline bool MainWindow::allFilesWereSaved()
{
	bool iterator;

	foreach (iterator, filesWereSaved)
	{
		if (!iterator)
			return false;
	}
	
	return true;
}

inline bool MainWindow::allFilesWereClosed()
{
	return tabWidget->count() == 0;
}

void MainWindow::showFileSavedIcon(int index, bool saved)
{
	if (saved)
	{
		tabWidget->setTabIcon(index, QIcon(":/images/mimetypes/jasssource.png"));
		fileListListWidget->item(index)->setData(Qt::DecorationRole, QIcon(":/images/mimetypes/jasssource.png"));
	}
	else
	{
		tabWidget->setTabIcon(index, QIcon(":/images/actions/document-save.png"));
		fileListListWidget->item(index)->setData(Qt::DecorationRole, QIcon(":/images/actions/document-save.png"));
	}
}

void MainWindow::setWindowTitleForFile(int index)
{
	QString name = !filePaths[index].isEmpty() ? filePaths[index] : tabWidget->tabText(index);
	
	if (filesWereSaved[index])
	{
		setWindowTitle(tr("%1 - %2").arg(name).arg(tr("vjasside")));
		showFileSavedIcon(index, true);
	}
	else
	{
		setWindowTitle(tr("%1 [Geändert] - %2").arg(name).arg(tr("vjasside")));
		showFileSavedIcon(index, false);
	}
}

void MainWindow::setFileTextDataByIndex(int index)
{
	QString tabName = filePaths[index];
	int lastIndex = tabName.lastIndexOf('/') + 1; //no special char :-(
	
	if (lastIndex != -1)
		tabName.remove(0, lastIndex);
	
	tabWidget->setTabText(index, tabName);
	tabWidget->setTabToolTip(index, filePaths[index]);
	fileListListWidget->item(index)->setData(Qt::DisplayRole, tabName);
	fileListListWidget->item(index)->setData(Qt::ToolTipRole, filePaths[index]);
}

void MainWindow::searchForExpression(bool forward)
{
	class TextEdit *textEdit = static_cast<class TextView*>(tabWidget->widget(tabWidget->currentIndex()))->textEdit;
	
	if (!textEdit->find(findExpression)) //&& was not the first line
	{
		QString message;
		
		if (forward)
			message = tr("Ende des Dokuments ist erreicht.<br>Am Anfang fortsetzen?");
		else
			message = tr("Anfang des Dokuments ist erreicht.<br>Am Ende forsetzen?");
		
		if (QMessageBox::question(this, tr("Suchen"), message, QMessageBox::Ok | QMessageBox::Cancel) == QMessageBox::Cancel)
			return;
		
		bool result;
		
		//move to first line
		if (forward)
		{
			textEdit->moveCursor(QTextCursor::Start);
			result = textEdit->find(findExpression); /// @todo Don't search the whole text!
		}
		else
		{
			textEdit->moveCursor(QTextCursor::End);
			result = textEdit->find(findExpression, QTextDocument::FindBackward); /// @todo Don't search the whole text!
		}
		
		if (!result)
			QMessageBox::warning(this, tr("Suchen"), tr("Suchbegriff \"%1\" nicht gefunden.").arg(findExpression));
		
	}
}

void MainWindow::setSessionActionsEnabled(bool enabled)
{
	saveSessionAction->setEnabled(enabled);
	saveSessionAsAction->setEnabled(enabled);
	deleteSessionAction->setEnabled(enabled);
	closeSessionAction->setEnabled(enabled);
}

int MainWindow::addRecentSession(Session *session)
{
	int index = openSessionMenu->actions().size();
	QAction *action = openSessionMenu->addAction(tr("%1 - %2").arg(session->name()).arg(session->size()));
	action->setData(index);
	
	return index;
}

void MainWindow::openSessionByIndex(const int &index)
{
	closeAllFiles();

	if (!allFilesWereClosed())
		return;

	class Session *session = sessions[index]; /// @todo Error
	QString iterator;
	
	foreach (iterator, session->files())
		openFileByPath(iterator);

	if (openedSessionIndex == -1)
		setSessionActionsEnabled(true);

	openedSessionIndex = index;
}

void MainWindow::saveSessionByIndex(const int &index)
{
	saveAllFiles();

	if (!allFilesWereSaved())
		return;

	sessions[index]->setFiles(filePaths);
	/// @todo Write everything into settings? Send signal to other processes.
	sessions[index]->writeIntoSettings();
	QSettings settings;
	settings.beginGroup("MainWindow");
	settings.beginWriteArray("sessions");
	settings.setArrayIndex(index);
	settings.setValue("name", sessions[index]->name());
	settings.endArray();
	settings.endGroup();
	
	QAction *action = openSessionMenu->actions()[index];
	action->setText(tr("%1 - %2").arg(sessions[index]->name()).arg(filePaths.size()));
}

void MainWindow::deleteSessionByIndex(const int &index)
{
	if (index == this->openedSessionIndex)
		closeOpenedSession();

	if (this->openedSessionIndex != -1)
		return;

	sessions[index]->removeFromSettings();
	sessions.removeAt(index);
	QAction *action = openSessionMenu->actions()[index];
	openSessionMenu->removeAction(action);
}

void MainWindow::closeOpenedSession()
{
	setSessionActionsEnabled(false);
	closeAllFiles();
	openedSessionIndex = -1;
}

QMessageBox::StandardButton MainWindow::showSessionMessageBox()
{
	if (filePaths.size() != sessions[openedSessionIndex]->size())
	{
		return QMessageBox::question(this, tr("Sitzung schließen"), tr("Die Anzahl der geöffneten Dateien unterscheidet<br>sich von der Anzahl der Sitzungsdateien.<br>Möchten Sie die Sitzung speichern, bevor sie geschlossen wird?"), QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
	}
	
	return QMessageBox::Discard;
}

}
