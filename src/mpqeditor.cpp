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

#include "mpqeditor.h"
#include "mainwindow.h"
#include "stormlib/StormPort.h"
#include "stormlib/StormLib.h"
#include "mpqeditorsettingsdialog.h"

namespace vjasside
{

MpqEditor::MpqEditor(MainWindow *parent) : QDialog(parent), archiveCreationFileDialog(0), openArchiveFileDialog(0), addFilesFileDialog(0), extractSelectedFilesFileDialog(0), settingsDialog(0), archive(NULL), archiveWasOpened(false)
{
	setupUi(this);
	
	connect(createNewArchivePushButton, SIGNAL(clicked()), this, SLOT(createNewArchive()));
	connect(openArchivePushButton, SIGNAL(clicked()), this, SLOT(openArchive()));
	connect(closeCurrentArchivePushButton, SIGNAL(clicked()), this, SLOT(closeCurrentArchive()));
	connect(addFilesPushButton, SIGNAL(clicked()), this, SLOT(addFiles()));
	connect(extractSelectedFilesPushButton, SIGNAL(clicked()), this, SLOT(extractSelectedFiles()));
	connect(openSelectedFilesPushButton, SIGNAL(clicked()), this, SLOT(openSelectedFiles()));
	connect(deleteSelectedFilesPushButton, SIGNAL(clicked()), this, SLOT(deleteSelectedFiles()));
	connect(settingsPushButton, SIGNAL(clicked()), this, SLOT(showSettingsDialog()));
	
	QLocale locale;
	LCID localeId;
	
	switch (locale.language())
	{
		case QLocale::Chinese:
			localeId = 0x404;
			break;
		
		case QLocale::Czech:
			localeId = 0x405;
			break;
		
		case QLocale::German:
			localeId = 0x407;
			break;
		
		case QLocale::English:
			if (locale.country() == QLocale::UnitedKingdom)
				localeId = 0x809;
			else
				localeId = 0x409;
			
			break;
		
		case QLocale::Spanish:
			localeId = 0x40a;
			break;
		
		case QLocale::French:
			localeId = 0x40c;
			break;
		
		case QLocale::Italian:
			localeId = 0x410;
			break;
		
		case QLocale::Japanese:
			localeId = 0x411;
			break;
		
		case QLocale::Korean:
			localeId = 0x412;
			break;
			
		case QLocale::Polish:
			localeId = 0x415;
			break;
		
		case QLocale::Portuguese:
			localeId = 0x416;
			break;
		
		case QLocale::Russian:
			localeId = 0x419;
			break;
			
		default:
			localeId = 0;
			break;
	}
	
	qDebug() << "Locale id: " << localeId;
	SFileSetLocale(localeId);

	//read settings
	QSettings settings;
	settings.beginGroup("MpqEditor");
	//instance data
	fileDirectory = settings.value("fileDirectory", qApp->applicationDirPath()).toString();
	hashTableSize = settings.value("hashTableSize", 16).toUInt();
	listFilesDirectory = settings.value("listFilesDirectory", qApp->applicationDirPath() + "/listfiles").toString();
	//ui
	settings.endGroup();
}

MpqEditor::~MpqEditor()
{
	//write settings
	QSettings settings("Tamino Dauth", "vjasside");
	settings.beginGroup("MpqEditor");
	//instance data
	settings.setValue("fileDirectory", fileDirectory.absolutePath());
	settings.setValue("hashTableSize", hashTableSize);
	settings.setValue("listFilesDirectory", listFilesDirectory.absolutePath());
	//ui data
	settings.endGroup();

	if (archive != NULL)
	{
		qDebug("Close it!");
		SFileCloseArchive(archive);
	}

	//SFileFlushArchive(archive);
}
	
void MpqEditor::createNewArchive()
{
	if (archiveCreationFileDialog == 0)
	{
		archiveCreationFileDialog = new QFileDialog(this, tr("MPQ-Archiv anlegen"), fileDirectory.absolutePath(), tr("MPQ-Archiv (*.mpq *.MPQ)"));
		archiveCreationFileDialog->setAcceptMode(QFileDialog::AcceptSave);
		archiveCreationFileDialog->setDefaultSuffix("mpq");
	}
	else
		archiveCreationFileDialog->setDirectory(fileDirectory);
	
	archiveCreationFileDialog->show();

	if (archiveCreationFileDialog->exec() == QDialog::Accepted)
	{
		fileDirectory = archiveCreationFileDialog->directory();
		QString filePath = archiveCreationFileDialog->selectedFiles().first();
		
		if (filePath.isEmpty())
			return;
			
		qDebug() << "File path " << filePath;
		
		qDebug() << "ASCII file path " << filePath.toAscii();
		
		bool ok;
		hashTableSize = QInputDialog::getInteger(this, tr("Streuwerttabellengröße"), tr("Größe:"), hashTableSize, 16, 262144, 1, &ok);
		
		if (!ok)
			return;
		
		//newArchive = new TMPQArchive;
		//newArchive->szFileName = filePath.toAscii();
		
		HANDLE oldArchive = NULL;
		
		if (archiveWasOpened)
			oldArchive = archive;

		HANDLE file = INVALID_HANDLE_VALUE;
		file = CreateFile(filePath.toAscii(), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL);
		
		if (file == INVALID_HANDLE_VALUE)
		{
			if (GetLastError() != ERROR_SUCCESS)
			{
				showErrorMessage(tr("MPQ-Archiv-Datei konnte nicht angelegt werden."));
				return;
			}
		}
		
		if (!SFileCreateArchiveEx(filePath.toAscii(), MPQ_CREATE_ARCHIVE_V2 | OPEN_ALWAYS, hashTableSize, &archive))
		{
			if (GetLastError() != ERROR_SUCCESS)
			{
				DeleteFile(filePath.toAscii());
			
				if (archive != NULL && archive != oldArchive)
					SFileCloseArchive(archive);
				
				archive = oldArchive;
				showErrorMessage(tr("MPQ-Archiv konnte nicht erzeugt werden."));
				return;
			}
		}
		
		if (archiveWasOpened)
		{
			//close current archive.
			SFileCloseArchive(oldArchive);
		}
		else
		{
			closeCurrentArchivePushButton->setEnabled(true);
			archiveWasOpened = true;
		}
		
		//open new archive in the tree widget
		refreshTreeWidget(false);
		fileGroupBox->setEnabled(true);
	}
}

void MpqEditor::openArchive()
{
	if (openArchiveFileDialog == 0)
	{
		openArchiveFileDialog = new QFileDialog(this, tr("MPQ-Archiv öffnen"), fileDirectory.absolutePath(), tr("MPQ-Archiv (*.mpq *.MPQ *.w3x *.W3X *.w3m *.w3n *.W3N)"));
		openArchiveFileDialog->setAcceptMode(QFileDialog::AcceptOpen);
	}
	else
		openArchiveFileDialog->setDirectory(fileDirectory);
	
	openArchiveFileDialog->show();

	if (openArchiveFileDialog->exec() == QDialog::Accepted)
	{
		fileDirectory = openArchiveFileDialog->directory();
		QString filePath = openArchiveFileDialog->selectedFiles().first();

		//if (filePath.isEmpty())
			//return;

		qDebug() << "ASCII file path " << filePath.toAscii();

		HANDLE oldArchive = NULL;
		
		if (archiveWasOpened)
			oldArchive = archive;

		if (!SFileCreateArchiveEx(filePath.toAscii(), OPEN_EXISTING, 0, &archive))
		{
			if (GetLastError() != ERROR_SUCCESS)
			{
				qDebug("Error");
				if (archive != NULL && archive != oldArchive)
					SFileCloseArchive(archive);
				
				archive = oldArchive;
				showErrorMessage(tr("MPQ-Archiv konnte nicht geöffnet werden."));
				
				return;
			}
		}
		
		
		if (archiveWasOpened)
		{
			//close current archive.
			SFileCloseArchive(oldArchive);
		}
		else
		{
			closeCurrentArchivePushButton->setEnabled(true);
			archiveWasOpened = true;
			qDebug("set it true");
		}
		
		//open new archive in the tree widget
		refreshTreeWidget(true);
		fileGroupBox->setEnabled(true);
	}

}

void MpqEditor::closeCurrentArchive()
{
	qDebug("Before closing");
	SFileCloseArchive(archive);
	qDebug("After closing");
	//clear tree widget
	closeCurrentArchivePushButton->setEnabled(false);
	archiveWasOpened = false;
	refreshTreeWidget(false);
	fileGroupBox->setEnabled(false);
}

void MpqEditor::addFiles()
{
	if (addFilesFileDialog == 0)
	{
		addFilesFileDialog = new QFileDialog(this, tr("Datei(en) hinzufügen"), fileDirectory.absolutePath());
		addFilesFileDialog->setAcceptMode(QFileDialog::AcceptOpen);
	}
	else
		addFilesFileDialog->setDirectory(fileDirectory);
	
	addFilesFileDialog->show();

	if (addFilesFileDialog->exec() == QDialog::Accepted)
	{
		fileDirectory = addFilesFileDialog->directory();
		QString iterator;
		
		foreach (iterator, addFilesFileDialog->selectedFiles())
		{
			QString addFileName = iterator;
			int lastIndex = addFileName.lastIndexOf('/') + 1; //no special char :-(
	
			if (lastIndex != -1)
				addFileName.remove(0, lastIndex);
			
			qDebug() << "Add file with path " << iterator << " and name " << addFileName;
			
			if (!SFileAddFile(archive, iterator.toAscii(), addFileName.toAscii(), MPQ_FILE_ENCRYPTED)) /// @todo If the file does already exist, ask for replacement.
			{
				showErrorMessage(QString(tr("Datei \"%1\" konnte nicht hinzugefügt werden.")).arg(iterator));
				//break?
			}
		}
	}
	
	refreshTreeWidget(false);
}

void MpqEditor::extractSelectedFiles()
{

	QList<QTreeWidgetItem*> selectedItems = archiveTreeWidget->selectedItems();

	//TODO Disable button if no files are selected
	if (selectedItems.empty())
		return;

	if (extractSelectedFilesFileDialog == 0)
	{
		extractSelectedFilesFileDialog = new QFileDialog(this, tr("Ausgewählte Datei(en) extrahieren"), fileDirectory.absolutePath());
		extractSelectedFilesFileDialog->setAcceptMode(QFileDialog::AcceptSave);
	}
	else
		extractSelectedFilesFileDialog->setDirectory(fileDirectory);
	
	QTreeWidgetItem *item;
	
	foreach (item, selectedItems)
	{
		extractSelectedFilesFileDialog->show();

		if (extractSelectedFilesFileDialog->exec() == QDialog::Accepted)
		{
			fileDirectory = extractSelectedFilesFileDialog->directory();
			
			if (!SFileExtractFile(archive, item->text(0).toAscii(), item->text(0).toAscii()))
				showErrorMessage(QString(tr("Datei \"%1\" konnte nicht extrahiert werden.")).arg(item->text(0)));
		}
		else
			break;
	}
	
	refreshTreeWidget(false);
}

void MpqEditor::openSelectedFiles()
{
}

void MpqEditor::deleteSelectedFiles()
{
	QTreeWidgetItem *item;

	foreach (item, archiveTreeWidget->selectedItems())
	{
		if (!SFileRemoveFile(archive, item->text(0).toAscii()))
			showErrorMessage(QString(tr("Datei \"%1\" konnte nicht gelöscht werden.")).arg(item->text(0)));
	}

	refreshTreeWidget(false);
}

void MpqEditor::showSettingsDialog()
{
	if (settingsDialog == 0)
		settingsDialog = new MpqEditorSettingsDialog(this);
	
	settingsDialog->show();
}

void MpqEditor::showErrorMessage(const QString &message)
{
	QMessageBox::warning(this, tr("Fehler"), tr("%1<br>Fehlermeldung: \"%2\"").arg(message).arg(ErrString(GetLastError())));
}

void MpqEditor::refreshTreeWidget(bool showEmptyMessage)
{
	if (!archiveWasOpened)
	{
		setWindowTitle(tr("MPQ-Editor"));
		qDebug("Archive was not opened.");
		//clear all items
		return;
	}

	TMPQArchive *mpqArchive = (TMPQArchive*)archive;
	QString headLine = mpqArchive->szFileName;
	int lastIndex = headLine.lastIndexOf('/') + 1; //no special char :-(
	
	if (lastIndex != -1)
		headLine.remove(0, lastIndex);
	
	setWindowTitle(tr("MPQ-Editor - %1").arg(headLine));
	
	SFILE_FIND_DATA findData;
	HANDLE file = NULL;
	QStringList listFiles = listFilesDirectory.entryList(QDir::Files | QDir::Readable);
	listFiles << "(listfile)"; // TEST
	
	qDebug() << "List files dir " << listFilesDirectory.absolutePath();
	QString iterator;
	
	foreach (iterator, listFiles)
	{
		file = SFileFindFirstFile(archive, "*", &findData, iterator.toAscii());
		
		qDebug() << "Checking list file " << iterator;
		
		if (file != NULL)
			break;
	}
	
	if (file == NULL)
	{
		if (showEmptyMessage)
			showErrorMessage(tr("MPQ-Archiv ist leer."));
		
		qDebug() << "Is empty.";
		
		return;
	}
	
	QTreeWidgetItem *item = archiveTreeWidget->invisibleRootItem();
	
	do
	{
		QStringList stringList;
		stringList << findData.cFileName;
		stringList << findData.szPlainName;
		stringList << QString("%1").arg(findData.lcLocale);
		stringList << QString(tr("%1 Bytes")).arg(findData.dwFileSize);
		stringList << QString("%1").arg(findData.dwFileFlags);
		stringList << QString("%1").arg(findData.dwBlockIndex);
		stringList << QString("%1").arg(findData.dwCompSize);
		item = new QTreeWidgetItem(item, stringList);
		archiveTreeWidget->addTopLevelItem(item);		
		
		qDebug() << "Add file with name: " << findData.cFileName << "\nPlain name: " << findData.szPlainName << "\nLc locale: " << findData.lcLocale << "\nFile size: " << findData.dwFileSize << "\nFile flags: " << findData.dwFileFlags << "\nBlock index: " << findData.dwBlockIndex << "\nCompressed size: " << findData.dwCompSize;
	}
	while (SFileFindNextFile(file, &findData));

	//if (archiveTreeWidget->headerItem() == 0)
}

}
