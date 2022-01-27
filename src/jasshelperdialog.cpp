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

#include "jasshelperdialog.h"
#include "mainwindow.h"

namespace vjasside
{

JasshelperDialog::JasshelperDialog(MainWindow *parent) : QDialog(parent)
{
	setupUi(this);

	connect(this->lookUpFolderListWidget, SIGNAL(itemSelectionChanged()), this, SLOT(lookUpFolderSelectionChanged()));
	connect(addLookUpFolderPushButton, SIGNAL(clicked()), this, SLOT(addLookUpFolder()));
	connect(removeLookUpFolderPushButton, SIGNAL(clicked()), this, SLOT(removeLookUpFolders()));
	connect(this->externalToolListWidget, SIGNAL(itemSelectionChanged()), this, SLOT(externalToolSelectionChanged()));
	connect(addExternalToolPushButton, SIGNAL(clicked()), this, SLOT(addExternalTool()));
	connect(removeExternalToolPushButton, SIGNAL(clicked()), this, SLOT(removeExternalTools()));
	connect(selectMapScriptPushButton, SIGNAL(clicked()), this, SLOT(setMapScriptFilePath()));
	connect(selectMapPushButton, SIGNAL(clicked()), this, SLOT(setMapFilePath()));
	connect(selectInputFilePushButton, SIGNAL(clicked()), this, SLOT(setInputFileFilePath()));
	connect(selectOutputFilePushButton, SIGNAL(clicked()), this, SLOT(setOutputFileFilePath()));
	connect(selectJasshelperPushButton, SIGNAL(clicked()), this, SLOT(selectJasshelper()));
	connect(selectConfigFilePushButton, SIGNAL(clicked()), this, SLOT(selectConfigFile()));
	connect(selectWewarlockPushButton, SIGNAL(clicked()), this, SLOT(selectWewarlock()));

	connect(this, SIGNAL(accepted()), this, SLOT(run()));
	connect(this->buttonBox->button(QDialogButtonBox::RestoreDefaults), SIGNAL(clicked()), this, SLOT(restoreDefaults()));

	
	//read settings
	QSettings settings;
	settings.beginGroup("JasshelperDialog");
	//instance data
	lookUpFolderFilePath = settings.value("lookUpFolderFilePath", qApp->applicationDirPath()).toString();
	externalToolFilePath = settings.value("externalToolFilePath", qApp->applicationDirPath()).toString();
	m_mapScriptFilePath = settings.value("mapScriptFilePath", QString()).toString();
	m_mapFilePath = settings.value("mapFilePath", QString()).toString();
	m_inputFileFilePath = settings.value("inputFileFilePath", QString()).toString();
	m_outputFileFilePath = settings.value("outputFileFilePath", QString()).toString();
	m_jasshelperFilePath = settings.value("jasshelperFilePath", qApp->applicationDirPath() + "/bin/jasshelper.exe").toString();
	m_configFileFilePath = settings.value("configFileFilePath", qApp->applicationDirPath() + "/jasshelper.conf").toString();
	externalToolName = settings.value("externalToolName").toString();
	//ui data
	setGeometry(settings.value("geometry", QRect(QPoint(0, 0), sizeHint())).toRect());
	debugCheckBox->setChecked(settings.value("debug", true).toBool());
	nopreprocessorCheckBox->setChecked(settings.value("noprepocessor", false).toBool());
	nooptimizeCheckBox->setChecked(settings.value("nooptimize", false).toBool());
	scriptonlyCheckBox->setChecked(settings.value("scriptonly", false).toBool());
	warcityCheckBox->setChecked(settings.value("warcity", false).toBool());
	showerrorsCheckBox->setChecked(settings.value("showerrors", false).toBool());
	settings.endGroup();
	
	qDebug() << "Config dir " << qApp->applicationDirPath() + "/jasshelper.conf";
	
	readConfigSectionEntries("[lookupfolders]", lookUpFolders);
	lookUpFolderListWidget->addItems(lookUpFolders);
	readConfigSectionEntries("[externaltools]", externalTools);
	externalToolListWidget->addItems(externalTools);
	
	QStringList entries0;
	readConfigSectionEntries("[jasscompiler]", entries0);

	if (!entries0.isEmpty())
		m_jassCompilerFilePath = entries0.first();

	QStringList entries1;
	readConfigSectionEntries("[wewarlock]", entries1);
	
	if (!entries1.isEmpty())
		m_wewarlockFilePath = entries1.first();
}

JasshelperDialog::~JasshelperDialog()
{
	//write settings
	QSettings settings;
	settings.beginGroup("JasshelperDialog");
	//instance data
	settings.setValue("lookUpFolderFilePath", lookUpFolderFilePath);
	settings.setValue("externalToolFilePath", externalToolFilePath);
	settings.setValue("mapScriptFilePath", m_mapScriptFilePath);
	settings.setValue("mapFilePath", m_mapFilePath);
	settings.setValue("inputFileFilePath", m_inputFileFilePath);
	settings.setValue("outputFileFilePath", m_outputFileFilePath);
	settings.setValue("jasshelperFilePath", m_jasshelperFilePath);
	settings.setValue("configFileFilePath", m_configFileFilePath);
	settings.setValue("externalToolName", externalToolName);;
	//ui data
	settings.setValue("geometry", geometry());
	settings.setValue("debug", debugCheckBox->isChecked());
	settings.setValue("noprepocessor", nopreprocessorCheckBox->isChecked());
	settings.setValue("nooptimize", nooptimizeCheckBox->isChecked());
	settings.setValue("scriptonly", scriptonlyCheckBox->isChecked());
	settings.setValue("warcity", warcityCheckBox->isChecked());
	settings.setValue("showerrors", showerrorsCheckBox->isChecked());
	settings.endGroup();
}

void JasshelperDialog::lookUpFolderSelectionChanged()
{
	this->removeLookUpFolderPushButton->setDisabled(this->lookUpFolderListWidget->selectedItems().isEmpty());
}

void JasshelperDialog::addLookUpFolder()
{
	QString newLookUpFolderFilePath = QFileDialog::getExistingDirectory(this, tr("Nachschlagordner hinzufügen"), lookUpFolderFilePath);
	
	if (newLookUpFolderFilePath.isEmpty())
		return;
	
	lookUpFolderFilePath = newLookUpFolderFilePath;
	newLookUpFolderFilePath = '\"' + newLookUpFolderFilePath + '\"';
	QString iterator;
	
	foreach (iterator, this->lookUpFolders)
	{
		qDebug() << "Comparing entry " << newLookUpFolderFilePath<< " with " << iterator;
	
		if (newLookUpFolderFilePath == iterator)
		{
			qDebug() << "Eintrag " << newLookUpFolderFilePath<< " existiert bereits und wird entfernt.";
			return;
		}
	}
	
	this->lookUpFolders << newLookUpFolderFilePath;
	QStringList list;
	list << newLookUpFolderFilePath;
	
	if (!refreshConfigSection("[lookupfolders]", list, Add))
		return;
	
	lookUpFolderListWidget->addItem(newLookUpFolderFilePath);
}

void JasshelperDialog::removeLookUpFolders()
{
	//TODO Disable remove button if nothing is selected
	QStringList entries;
	QListWidgetItem *selectedItem;
	
	foreach (selectedItem, lookUpFolderListWidget->selectedItems())
		entries << selectedItem->text();
	
	if (!refreshConfigSection("[lookupfolders]", entries, Remove))
		return;
	
	foreach (selectedItem, lookUpFolderListWidget->selectedItems())
	{
		lookUpFolders.removeAt(lookUpFolderListWidget->row(selectedItem));
		lookUpFolderListWidget->takeItem(lookUpFolderListWidget->row(selectedItem));
	}
	
}

void JasshelperDialog::externalToolSelectionChanged()
{
	this->removeExternalToolPushButton->setDisabled(this->externalToolListWidget->selectedItems().isEmpty());
}

void JasshelperDialog::addExternalTool()
{
	QString newExternalToolFilePath = QFileDialog::getOpenFileName(this, tr("Externes Werkzeug hinzufügen"), this->externalToolFilePath);

	if (newExternalToolFilePath.isEmpty())
		return;

	this->externalToolFilePath = newExternalToolFilePath;
	bool ok;
		
	do
	{
		this->externalToolName = QInputDialog::getText(this, tr("Externes Werkzeug hinzufügen"), tr("Name:"), QLineEdit::Normal, this->externalToolName, &ok);
	
		if (!ok)
			return;
	}
	while (this->externalToolName.isEmpty());
	
	newExternalToolFilePath = '\"' + newExternalToolFilePath + '\"';
	QStringList entries;
	entries << '\"' + externalToolName + "\"," + newExternalToolFilePath;
	
	if (!refreshConfigSection("[externaltools]", entries, Add))
		return;
	
	externalTools << entries.first();
	externalToolListWidget->addItems(externalTools);
}

void JasshelperDialog::removeExternalTools()
{
	//TODO Disable remove button if nothing is selected
	QStringList entries;
	QListWidgetItem *selectedItem;
	
	foreach (selectedItem, externalToolListWidget->selectedItems())
		entries << selectedItem->text();
	
	if (!refreshConfigSection("[externaltools]", entries, Remove))
		return;
	
	foreach (selectedItem, externalToolListWidget->selectedItems())
	{
		externalTools.removeAt(externalToolListWidget->row(selectedItem));
		externalToolListWidget->takeItem(externalToolListWidget->row(selectedItem));
	}
}

void JasshelperDialog::setMapScriptFilePath()
{
	setFilePath(tr("Alle Dateien (*);;Jass-Dateien (*.j *.J)"), m_mapScriptFilePath, tr("Karten-Skript auswählen"));
}

void JasshelperDialog::setMapFilePath()
{
	setFilePath(tr("Alle Dateien (*);;Kartendateien (*.w3x *.W3X *.w3m *.W3M)"), m_mapFilePath, tr("Karte auswählen"));
}

void JasshelperDialog::setInputFileFilePath()
{
	setFilePath(tr("Alle Dateien (*);;Jass-Dateien (*.j *.J)"), m_inputFileFilePath, tr("Eingabedatei auswählen"));
}

void JasshelperDialog::setOutputFileFilePath()
{
	setFilePath(tr("Alle Dateien (*);;Jass-Dateien (*.j *.J)"), m_outputFileFilePath, tr("Ausgabedatei auswählen"));
}

void JasshelperDialog::selectJasshelper()
{
	setFilePath(tr("Alle Dateien (*);;DOS/Windows-Programme (*.exe *.EXE)"), m_jasshelperFilePath, tr("JassHelper auswählen"));
}

void JasshelperDialog::selectConfigFile()
{
	QString oldPath = m_configFileFilePath;

	forever
	{
		setFilePath(tr("Alle Dateien (*);;Konfigurationsdateien (*.conf *.CONF)"), m_configFileFilePath, tr("Konfigurationsdatei auswählen"));
	
		if (m_configFileFilePath.isEmpty())
			QMessageBox::critical(this, tr("Konfigurationsdatei auswählen"), tr("Sie keine passende Datei ausgewählt."));
		else
			break;
	}
	
	if (m_configFileFilePath == oldPath)
		return;
	
	//refresh everything
	readConfigSectionEntries("[lookupfolders]", lookUpFolders);
	lookUpFolderListWidget->clear();
	lookUpFolderListWidget->addItems(this->lookUpFolders);
	readConfigSectionEntries("[externaltools]", externalTools);
	externalToolListWidget->clear();
	externalToolListWidget->addItems(this->externalTools);
	
	QStringList entries;
	readConfigSectionEntries("[wewarlock]", entries);
	m_wewarlockFilePath = entries.first();
}

void JasshelperDialog::selectJassCompiler()
{
	QString oldPath = this->m_jassCompilerFilePath;
	setFilePath(tr("Alle Dateien (*);;DOS/Windows-Programme (*.exe *.EXE)"), this->m_jassCompilerFilePath, tr("Jass-Compiler auswählen"));

	if (this->m_jassCompilerFilePath != oldPath.mid(1, oldPath.length() - 2)) //without quote characters
	{
		if (!this->m_jassCompilerFilePath.isEmpty())
		{
			QStringList entries('\"' + this->m_jassCompilerFilePath + '\"');
			refreshConfigSection("[jasscompiler]", entries, Single);
		}
		else
		{
			QStringList entries(oldPath);
			refreshConfigSection("[jasscompiler]", entries, Remove);
		}
	}
}

void JasshelperDialog::selectWewarlock()
{
	QString oldPath = m_wewarlockFilePath;
	setFilePath(tr("Alle Dateien (*);;DOS/Windows-Programme (*.exe *.EXE)"), m_wewarlockFilePath, tr("WEWarlock auswählen"));
	
	if (m_wewarlockFilePath != oldPath.mid(1, oldPath.length() - 2)) //without quote characters
	{
		if (!m_wewarlockFilePath.isEmpty())
		{
			QStringList entries('\"' + m_wewarlockFilePath + '\"');
			refreshConfigSection("[wewarlock]", entries, Single);
		}
		else
		{
			QStringList entries(oldPath);
			refreshConfigSection("[wewarlock]", entries, Remove);
		}
	}
}

void JasshelperDialog::run()
{
	if (!scriptonlyCheckBox->isChecked())
	{
		if (m_mapScriptFilePath.isEmpty())
		{
			QMessageBox::information(this, tr("Karten-Skript"), tr("Es wurde kein Karte-Skript ausgewählt."));
			setMapScriptFilePath();
			return;
		}
		else if (!QFile::exists(m_mapScriptFilePath)) //if settings were read and file does not exist anymore.
		{
			QMessageBox::information(this, tr("Karten-Skript"), tr("Das ausgewählte Karten-Skript existiert nicht."));
			setMapScriptFilePath();
			return;
		}
		else if (m_mapFilePath.isEmpty())
		{
			QMessageBox::information(this, tr("Karte"), tr("Es wurde keine Karte ausgewählt."));
			setMapFilePath();
			return;
		}
		else if (!QFile::exists(m_mapScriptFilePath)) //if settings were read and file does not exist anymore.
		{
			QMessageBox::information(this, tr("Karte"), tr("Die ausgewählte Karte existiert nicht."));
			setMapFilePath();
			return;
		}
	}
	else
	{
		if (m_inputFileFilePath.isEmpty())
		{
			QMessageBox::information(this, tr("Eingabedatei"), tr("Es wurde keine Eingabedatei ausgewählt."));
			setInputFileFilePath();
			return;
		}
		else if (!QFile::exists(m_inputFileFilePath)) //if settings were read and file does not exist anymore.
		{
			QMessageBox::information(this, tr("Eingabedatei"), tr("Die ausgewählte Eingabedatei existiert nicht."));
			setInputFileFilePath();
			return;
		}
		else if (m_outputFileFilePath.isEmpty())
		{
			QMessageBox::information(this, tr("Ausgabedatei"), tr("Es wurde keine Ausgabedatei ausgewählt."));
			setOutputFileFilePath();
			return;
		}
		else if (!QFile::exists(m_outputFileFilePath)) //if settings were read and file does not exist anymore.
		{
			QMessageBox::information(this, tr("Ausgabedatei"), tr("Die ausgewählte Ausgabedatei existiert nicht"));
			setOutputFileFilePath();
			return;
		}
	}

	if (!QFile::exists(this->m_jasshelperFilePath))
	{
		QMessageBox::critical(this, tr("JassHelper"), tr("Die ausführbare Datei %1 existiert nicht.<br>Bitte wählen Sie die entsprechende Datei aus.").arg(this->m_jasshelperFilePath));
		selectJasshelper();
		return;
	}

	QStringList args;

#ifndef Q_OS_WIN32
	args << this->m_jasshelperFilePath;
#endif

	if (debugCheckBox->isChecked())
		args << "--debug";

	if (nopreprocessorCheckBox->isChecked())
		args << "--nopreprocessor";

	if (nooptimizeCheckBox->isChecked())
		args << "--nooptimize";

	bool scriptonly = scriptonlyCheckBox->isChecked();
	
	if (scriptonly)
	{
		if (warcityCheckBox->isChecked())
			args << "--warcity";
		else
			args << "--scriptonly";
	}
	
	if (showerrorsCheckBox->isChecked())
		args << "--showerrors";

	QString path0(static_cast<class MainWindow*>(this->parent())->commonjPath());
		
	if (!path0.isEmpty())
		args << path0;
	
	QString path1 = static_cast<class MainWindow*>(this->parent())->blizzardjPath();
		
	if (!path1.isEmpty())
		args << path1;

	if (scriptonly)
		args << this->m_inputFileFilePath << this->m_outputFileFilePath;
	else
		args << this->m_mapScriptFilePath << this->m_mapFilePath;

	QProcess process;
	process.setWorkingDirectory(qApp->applicationDirPath());
	//process.setReadChannel(QProcess::StandardOutput);
	
#ifdef Q_OS_WIN32
	process.start(jasshelperFilePath(), args);
#else
	process.start("wine", args);
	
	if (process.error() == QProcess::FailedToStart)
	{
		QMessageBox::critical(this, tr("Wine"), tr("Der Prozess \"wine\" konnte nicht gestartet werden. Vergewissern Sie sich, ob das Programm \"wine\" auf ihrem Betriebssystem installiert ist.<br>\"wine\" wird für eine Windows-Emulation auf Nicht-Windows-Betriebssystemen benötigt, da sich das Programm \"JassHelper\" nicht unter solchen kompilieren lässt."));
		return;
	}
#endif
	
	if (process.waitForFinished())
		qDebug("Process has finished.");

	static_cast<class MainWindow*>(parent())->outputTextBrowser->setPlainText(process.readAllStandardError() + process.readAllStandardOutput());
}

void JasshelperDialog::restoreDefaults()
{
}

bool JasshelperDialog::refreshConfigSection(const QString &section, QStringList &entries, const enum EditMode &editMode)
{

	QFile file(m_configFileFilePath);
	
	if (!file.exists())
	{
		QMessageBox::critical(this, tr("Konfigurationsdatei"), tr("Die JassHelper-Konfigurationsdatei \"%1\" existiert nicht.").arg(m_configFileFilePath));
		return false;
	}
	
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::critical(this, tr("Konfigurationsdatei"), tr("Die JassHelper-Konfigurationsdatei \"%1\" konnte nicht geöffnet werden.").arg(m_configFileFilePath));
		return false;
	}
	
	bool removeLine = false;
	bool foundSection = false;
	bool insertedSingle = false;
	QStringList lines;
	QTextStream stream(&file);
		
	while (!stream.atEnd())
	{
		lines << stream.readLine();
		qDebug() << "Stream line " << lines.last();
		QString trimmedLine = lines.last().trimmed();
		
		if (trimmedLine.isEmpty() || trimmedLine.indexOf("//") == 0) //ignore comments and empty lines
		{
			qDebug() << "Ignore comment or empty line.";
			continue;
		}
		
		if (editMode == Single && !insertedSingle && foundSection)
		{
			qDebug("Set single line.");
			stream.seek(stream.pos() - lines.last().length());
			lines.removeLast();
			bool readLine = true;
			QString iterator;
			
			foreach (iterator, entries)
			{
				QString line;
				QString trimmedReadLine;
				
				if (readLine)
				{
					line = stream.readLine();
					trimmedReadLine = line.trimmed();
					
					if (trimmedReadLine[0] == '[') //new section
						readLine = false;
					else if (trimmedLine.indexOf("//") == 0)
					{
						lines << line;
						continue;
					}
				}
				
				lines << iterator;
				entries.removeFirst();
			}
		}
		
		if (removeLine)
		{
			qDebug("Remove line.");
			
			if (trimmedLine[0] == '[') //next section
			{
				qDebug() << "Found next section";
				removeLine = false;
			}
			else
			{
				int i = 0;
				QString iterator;
			
				foreach (iterator, entries)
				{
					qDebug() << "Comparing " << iterator << " with " << trimmedLine;
					
					if (iterator == trimmedLine)
					{
						qDebug() << "Remove entry " << i;
						lines.removeLast();
						entries.removeAt(i);
						qDebug("FOUND IT!!!!");
						break;
					}
					
					++i;
				}
			}
		}
		
		if (!foundSection && trimmedLine == section)
		{
			qDebug() << "Found section " << section;
			foundSection = true;
		
			if (editMode == Add)
				lines << entries;
			else if (editMode == Remove)
				removeLine = true;
		}
	}
	
	if (!foundSection)
	{
		QMessageBox::critical(this, tr("JassHelper-Konfigurationsdatei"), tr("Sektion \"%1\" konnte nicht gefunden werden.").arg(section));
		return false;
	}
	else if (editMode == Single && !entries.isEmpty())
	{
		QString iterator;
		
		foreach (iterator, entries)
		{
			lines << iterator;
			entries.removeFirst();
		}
	}
	
	if (editMode != Add && !entries.isEmpty())
	{
		if (editMode == Remove)
			QMessageBox::critical(this, tr("JassHelper-Konfigurationsdatei"), tr("Es konnten nicht alle Einträge entfernt werden."));
		else if (editMode == Single)
			QMessageBox::critical(this, tr("JassHelper-Konfigurationsdatei"), tr("Es konnten nicht alle Einträge aktualisiert werden."));
		
		return false;
	}
	
	file.close();
	
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		QMessageBox::critical(this, tr("Konfigurationsdatei"), tr("Die JassHelper-Konfigurationsdatei \"%1\" konnte nicht überschrieben werden").arg(qApp->applicationDirPath() + "/jasshelper.conf"));
		return false;
	}
	
	stream.setDevice(&file);
	QString iterator;
	
	foreach (iterator, lines)
		stream << iterator << '\n';
	
	return true;
}

void JasshelperDialog::readConfigSectionEntries(const QString &section, QStringList &entryList)
{
	QFile file(m_configFileFilePath);
	
	if (!file.exists())
	{
		QMessageBox::critical(this, tr("Konfigurationsdatei"), tr("Die JassHelper-Konfigurationsdatei \"%1\" existiert nicht.").arg(m_configFileFilePath));
		return;
	}
	
	if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
	{
		QMessageBox::critical(this, tr("Konfigurationsdatei"), tr("Die JassHelper-Konfigurationsdatei \"%1\" konnte nicht geöffnet werden").arg(m_configFileFilePath));
		return;
	}
	
	bool foundSection = false;
	QTextStream stream(&file);
		
	while (!stream.atEnd())
	{
		QString trimmedLine = stream.readLine().trimmed();
		
		if (trimmedLine.isEmpty() || trimmedLine.indexOf("//") == 0)
			continue;
		
		if (foundSection && trimmedLine[0] == '[')
			break;
		
		if (foundSection)
		{
			entryList << trimmedLine;
			continue;
		}
		
		if (trimmedLine == section)
			foundSection = true;
	}
	
	if (!foundSection)
		QMessageBox::critical(this, tr("JassHelper-Konfigurationsdatei"), tr("Sektion \"%1\" konnte nicht gefunden werden.").arg(section));
}

void JasshelperDialog::setFilePath(const QString &filter, QString &filePath, const QString &title)
{
	QString newFilePath = QFileDialog::getOpenFileName(this, title, filePath, filter);
	
	if (newFilePath.isEmpty())
		return;
	
	filePath = newFilePath;
}

}
