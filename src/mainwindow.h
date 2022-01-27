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

#ifndef VJASSIDE_MAINWINDOW_H
#define VJASSIDE_MAINWINDOW_H

#include <QMainWindow>
#include <QSplashScreen>
#include <QSize>
#include <QStringList>
#include <QList>
#include <QPoint>
#include <QModelIndex>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QDir>

#include "ui_mainwindow.h"

namespace vjassdoc
{

class Object;

}

namespace vjasside
{

class SyntaxSchema;
class ApiDatabaseDialog;
class MpqEditor;
class PjassDialog;
class JasshelperDialog;
class VjassdocDialog;
class EditorSettingsDialog;
class SyntaxHighlighter;
class Session;

class MainWindow : public QMainWindow, public Ui::MainWindow
{
	Q_OBJECT

	signals:
		void fontChanged(const QFont &font);

	public:
		static bool lineNumbersAreShownDefaultValue();
		static int tabStopWidthDefaultValue();
		static bool closeFilesWhenCreatingANewSessionDefaultValue();
		static QFont fontDefaultValue();
	
		MainWindow(QSplashScreen *splashScreen = 0);
		virtual ~MainWindow();
		QStringList getFilePaths() const;

		void addSyntaxSchema(class SyntaxSchema *syntaxSchema); //inline
		void removeSyntaxSchema(const int &index); //inline
		void renameSyntaxSchema(const int &index, const QString &name); //inline
		QList<class SyntaxSchema*> syntaxSchemata() const; //inline
		void setCurrentSyntaxSchemaIndex(int index); //inline
		int currentSyntaxSchemaIndex() const; //inline
		class SyntaxSchema* currentSyntaxSchema() const; //inline
		void rehighlightAllFiles();
		
		void showObjectInfo(const class vjassdoc::Object *object);
		
		//settings
		void setLineNumbersAreShown(bool lineNumbersAreShown);
		bool lineNumbersAreShown() const; //inline
		void setAutomaticIndention(bool enable); //inline
		bool automaticIndention() const; //inline
		void setTabStopWidth(int tabStopWidth);
		int tabStopWidth() const; //inline
		void setCloseFilesWhenCreatingANewSession(bool closeFilesWhenCreatingANewSession); //inline
		bool closeFilesWhenCreatingANewSession() const; //inline
		void setFont(QFont font); //inline
		QFont font() const; //inline


		QString commonjPath();
		QString commonaiPath();
		QString blizzardjPath();
	
	protected:
		virtual void closeEvent(QCloseEvent *event);

	private slots:
		void newFile();
		void openFile();
		void openRecentFile(QAction *action);
		void saveFile();
		void saveFileAs();
		void saveAllFiles();
		void reloadFile();
		void revertAllFiles();
		void printFile();
		void exportFileAsHtml();
		void closeFile();
		void closeAllFiles();
		void closeAllOtherFiles();

		void undo();
		void redo();
		void cut();
		void copy();
		void copyAsHtml();
		void paste();
		void selectAll();
		void deselect();
		void blockSelectionMode();
		void overwriteMode();
		void find();
		void findNext();
		void findPrevious();
		void replace();
		void goToLine();
		void findSelectReplace();
		void findInFiles();

		void back();
		void forward();
		void gotoLastEditPosition();
		void wordWrap(bool checked);
		void off(bool checked);
		void followLineNumbers(bool checked);
		void alwaysOn(bool checked);
		void showStaticWordWrapMarker();
		void showIconBorder();
		void showLineNumbers();
		void showScrollbarMarks();
		void showFoldingMarkers();
		void collapseToplevel();
		void expandToplevel();
		void collapseOneLocalLevel();
		void expandOneLocalLevel();
		
		void showApiDatabaseDialog();
		void showMpqEditor();
		void insertColor();

		void newSession();
		void openSession(QAction *action);
		void saveSession();
		void saveSessionAs();
		void deleteSession();
		void closeSession();

		void parseJassSyntax();
		void parseVjassSyntax();
		void buildApiDocumentation();

		void showEditorSettings();

		void aboutPjass();
		void aboutJasshelper();
		void aboutVjassdoc();
		void aboutVjasssdk();
		void aboutWc3sdk();
		void aboutVjasside();

		void setFileListRow(int row);
		void openFileByListWidgetItem(QListWidgetItem *item);

		void fileListChangedVisibility(bool visible);
		void apiListChangedVisibility(bool visible);
		void outputChangedVisibility(bool visible);

		void fileWasChanged(int index);
		void undoAvailable(int index, bool available);
		void refreshWindowTitle();
		void changedCurrentTab(int index);
		
		void apiDatabaseDialogWasHidden();
		void mpqEditorWasRejected();
		
	private:
		static const int maxRecentFiles = 5;
		
		void setFileActionsEnabled(bool enabled);
		
		void addRecentFile(const QString &filePath);
		void renameRecentFileAction(const int &index, const QString &filePath);
		
		void createNewFile();
		void openFileByPath(const QString &filePath);
		bool fileIsAlreadyOpened(const QString &filePath, bool refresh);
		void saveFileByIndex(const int &index);
		void saveFileAsByIndex(const int &index);
		void closeFileByIndex(const int &index);
		bool allFilesWereSaved();
		bool allFilesWereClosed();
		void showFileSavedIcon(int index, bool saved);
		void setWindowTitleForFile(int index);
		void setFileTextDataByIndex(int index);
		
		void searchForExpression(bool forward);
		
		void setSessionActionsEnabled(bool enabled);
		int addRecentSession(Session *session);
		void openSessionByIndex(const int &index);
		void saveSessionByIndex(const int &index);
		void renameSessionByIndex(const int &index, const QString &newName);
		void deleteSessionByIndex(const int &index);
		void closeOpenedSession();
		QMessageBox::StandardButton showSessionMessageBox();

		//file actions
		QString findExpression;
		int line;
		QString replaceExpression;

		//file handling objects
		QPrinter *printer;
		QPrintDialog *printDialog;

		//custom dialogs
		ApiDatabaseDialog *apiDatabaseDialog;
		MpqEditor *mpqEditor;
		QColor insertColorColor;
		class PjassDialog *pjassDialog;
		JasshelperDialog *jasshelperDialog;
		VjassdocDialog *vjassdocDialog;
		EditorSettingsDialog *editorSettingsDialog;

		//syntax highlighting
		QList<SyntaxSchema*> m_syntaxSchemata;
		int m_currentSyntaxSchemaIndex;

		//file data
		QList<bool> filesWereSaved;
		QStringList filePaths;
		QStringList saveFilePaths;
		QString filePath;
		QStringList recentFiles;
		QVector<SyntaxHighlighter*> syntaxHighlighters;

		//session data
		QString newSessionName;
		QString openSessionName;
		QString saveSessionName;
		int openedSessionIndex;
		QList<Session*> sessions;

		//settings
		bool m_lineNumbersAreShown;
		bool m_automaticIndention;
		int m_tabStopWidth;
		bool m_closeFilesWhenCreatingANewSession;
		QFont m_font;
};

inline bool MainWindow::lineNumbersAreShownDefaultValue()
{
	return true;
}

inline int MainWindow::tabStopWidthDefaultValue()
{
	return 80;
}

inline bool MainWindow::closeFilesWhenCreatingANewSessionDefaultValue()
{
	return false;
}

inline QFont MainWindow::fontDefaultValue()
{
	return QFont("Courier New", 12);
}

}

#endif
