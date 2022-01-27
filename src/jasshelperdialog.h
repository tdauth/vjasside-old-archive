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

#ifndef VJASSIDE_JASSHELPERDIALOG_H
#define VJASSIDE_JASSHELPERDIALOG_H

#include <QDialog>
#include <QStringList>

#include "ui_jasshelperdialog.h"

namespace vjasside
{

class MainWindow;

class JasshelperDialog : public QDialog, public Ui::JasshelperDialog
{
	Q_OBJECT

	public:
		JasshelperDialog(class MainWindow *parent);
		~JasshelperDialog();

	private slots:
		void lookUpFolderSelectionChanged();
		void addLookUpFolder();
		void removeLookUpFolders();
		void externalToolSelectionChanged();
		void addExternalTool();
		void removeExternalTools();
		void setMapScriptFilePath();
		void setMapFilePath();
		void setInputFileFilePath();
		void setOutputFileFilePath();
		void selectJasshelper();
		void selectConfigFile();
                void selectJassCompiler();
		void selectWewarlock();
		void run();
		void restoreDefaults();

	private:
		enum EditMode
		{
			Add,
			Remove,
			Single
		};
	
		/**
		* Note that if @param add is false all items of @param entries will be removed.
		* @param section Section of the JassHelper configuration file (like [lookupfolders]).
		* @param entries Entries which should be added or removed.
		* @param add If this value is true entries will be added otherwise they will be removed.
		* @return Returns if file editting was successfully.
		*/
		bool refreshConfigSection(const QString &section, QStringList &entries, const enum EditMode &editMode);
		void readConfigSectionEntries(const QString &section, QStringList &entryList);
		void setFilePath(const QString &filter, QString &filePath, const QString &title);
		bool setToolName();
		
		QStringList lookUpFolders;
		QStringList externalTools;

		QString lookUpFolderFilePath;
		QString externalToolFilePath;
		QString m_mapScriptFilePath;
		QString m_mapFilePath;
		QString m_inputFileFilePath;
		QString m_outputFileFilePath;
		QString m_jasshelperFilePath;
		QString m_configFileFilePath;
		QString m_jassCompilerFilePath;
		QString m_wewarlockFilePath;
		QString externalToolName;
};

}

#endif
