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

#ifndef VJASSIDE_MPQEDITOR_H
#define VJASSIDE_MPQEDITOR_H

#include <QDialog>
#include <QDir>
#include <QFileDialog>

#include "ui_mpqeditor.h"
#include "stormlib/StormPort.h"
#include "stormlib/StormLib.h"

namespace vjasside
{

class MainWindow;
class MpqEditorSettingsDialog;

/// @todo Revise please.
class MpqEditor : public QDialog, public Ui::MpqEditor
{
	Q_OBJECT

	public:
		MpqEditor(MainWindow *parent);
		~MpqEditor();
	
	private slots:
		void createNewArchive();
		void openArchive();
		void closeCurrentArchive();
		void addFiles();
		void extractSelectedFiles();
		void openSelectedFiles();
		void deleteSelectedFiles();
		void showSettingsDialog();
	
	private:
		void showErrorMessage(const QString &message);
		void refreshTreeWidget(bool showEmptyMessage);
		
		QDir fileDirectory;
		DWORD hashTableSize;
		QDir listFilesDirectory;
		QFileDialog *archiveCreationFileDialog;
		QFileDialog *openArchiveFileDialog;
		QFileDialog *addFilesFileDialog;
		QFileDialog *extractSelectedFilesFileDialog;
		MpqEditorSettingsDialog *settingsDialog;
		HANDLE archive;
		bool archiveWasOpened;
};

}

#endif
