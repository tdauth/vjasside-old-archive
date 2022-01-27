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

#include "vjassdocdialog.h"
#include "mainwindow.h"

namespace vjasside
{

VjassdocDialog::VjassdocDialog(MainWindow *mainWindow) : QDialog(mainWindow)
{
	setupUi(this);

	connect(chooseDirPushButton, SIGNAL(clicked()), this, SLOT(chooseDir()));
	connect(addImportDirPushButton, SIGNAL(clicked()), this, SLOT(addImportDir()));
	connect(removeImportDirsPushButton, SIGNAL(clicked()), this, SLOT(removeImportDirs()));
	connect(selectVjassdocPushButton, SIGNAL(clicked()), this, SLOT(selectVjassdoc()));
	connect(this, SIGNAL(accepted()), this, SLOT(run()));
	connect(this->buttonBox->button(QDialogButtonBox::RestoreDefaults), SIGNAL(clicked()), this, SLOT(restoreDefaults()));
	
	//read settings
	QSettings settings;
	settings.beginGroup("VjassdocDialog");
	//instance data
	chooseDirPath = settings.value("chooseDirPath", qApp->applicationDirPath()).toString();
	importDirPath = settings.value("importDirPath", qApp->applicationDirPath()).toString();
	
#ifdef Q_OS_WIN32
	vjassdocFilePath = settings.value("vjassdocFilePath", qApp->applicationDirPath() + "/bin/vjassdoc.exe").toString();
#else
	vjassdocFilePath = settings.value("vjassdocFilePath", qApp->applicationDirPath() + "/bin/vjassdoc").toString();
#endif
	
	int count = settings.beginReadArray("importDirs");
	
	for (int i = 0; i < count; ++i)
	{
		settings.setArrayIndex(i);
		importDirs << settings.value("path").toString();
		importDirListWidget->addItem(importDirs.last());
	}
	
	settings.endArray();

	//ui data
	titleLineEdit->setText(settings.value("title", tr("vJass-API-Dokumentation")).toString());
	jassCheckBox->setChecked(settings.value("jass", true).toBool());
	debugCheckBox->setChecked(settings.value("debug", true).toBool());
	privateCheckBox->setChecked(settings.value("private", false).toBool());
	textmacrosCheckBox->setChecked(settings.value("textmacros", true).toBool());
	htmlCheckBox->setChecked(settings.value("html", true).toBool());
	pagesCheckBox->setChecked(settings.value("pages", true).toBool());
	databaseCheckBox->setChecked(settings.value("database", false).toBool());
	verboseCheckBox->setChecked(settings.value("verbose", false).toBool());
	timeCheckBox->setChecked(settings.value("time", false).toBool());
	alphabeticalCheckBox->setChecked(settings.value("alphabetical", true).toBool());
	useCommonjCheckBox->setChecked(settings.value("useCommonj", true).toBool());
	useCommonaiCheckBox->setChecked(settings.value("useCommonai", true).toBool());
	useBlizzardjCheckBox->setChecked(settings.value("useBlizzardj", true).toBool());
	commentCheckBox->setChecked(settings.value("parseComments", true).toBool());
	keywordCheckBox->setChecked(settings.value("parseKeywords", true).toBool());
	textMacroCheckBox->setChecked(settings.value("parseTextMacros", true).toBool());
	textMacroInstanceCheckBox->setChecked(settings.value("parseTextMacroInstances", true).toBool());
	typeCheckBox->setChecked(settings.value("parseTypes", true).toBool());
	globalCheckBox->setChecked(settings.value("parseGlobals", true).toBool());
	memberCheckBox->setChecked(settings.value("parseMembers", true).toBool());
	functionInterfaceCheckBox->setChecked(settings.value("parseFunctionInterfaces", true).toBool());
	functionCheckBox->setChecked(settings.value("parseFunctions", true).toBool());
	methodCheckBox->setChecked(settings.value("parseMethods", true).toBool());
	interfaceCheckBox->setChecked(settings.value("parseInterfaces", true).toBool());
	structCheckBox->setChecked(settings.value("parseStructs", true).toBool());
	scopeCheckBox->setChecked(settings.value("parseScopes", true).toBool());
	libraryCheckBox->setChecked(settings.value("parseLibraries", true).toBool());
	sourceFileCheckBox->setChecked(settings.value("parseSourceFiles", true).toBool());
	docCommentCheckBox->setChecked(settings.value("parseDocComments", true).toBool());
	allCheckBox->setChecked(settings.value("parseAll", true).toBool());
	setGeometry(settings.value("geometry", QRect(QPoint(0, 0), sizeHint())).toRect());
	settings.endGroup();
	qDebug("!!! 5");
}

VjassdocDialog::~VjassdocDialog()
{
	//write settings
	QSettings settings;
	settings.beginGroup("VjassdocDialog");
	//instance data
	settings.setValue("chooseDirPath", chooseDirPath);
	settings.setValue("importDirPath", importDirPath);
	settings.setValue("vjassdocFilePath", vjassdocFilePath);
	settings.beginWriteArray("importDirs");
	int i = 0;
	QString iterator;
	
	foreach (iterator, importDirs)
	{
		settings.setArrayIndex(i);
		settings.setValue("path", iterator);
		++i;
	}
	
	settings.endArray();
	//ui data
	settings.setValue("title", titleLineEdit->text());
	settings.setValue("jass", jassCheckBox->isChecked());
	settings.setValue("debug", debugCheckBox->isChecked());
	settings.setValue("private", privateCheckBox->isChecked());
	settings.setValue("textmacros", textmacrosCheckBox->isChecked());
	settings.setValue("html", htmlCheckBox->isChecked());
	settings.setValue("pages", pagesCheckBox->isChecked());
	settings.setValue("database", databaseCheckBox->isChecked());
	settings.setValue("verbose", verboseCheckBox->isChecked());
	settings.setValue("time", timeCheckBox->isChecked());
	settings.setValue("alphabetical", alphabeticalCheckBox->isChecked());
	settings.setValue("useCommonj", useCommonjCheckBox->isChecked());
	settings.setValue("useCommonai", useCommonaiCheckBox->isChecked());
	settings.setValue("useBlizzardj", useBlizzardjCheckBox->isChecked());
	settings.setValue("parseComments", commentCheckBox->isChecked());
	settings.setValue("parseKeywords", keywordCheckBox->isChecked());
	settings.setValue("parseTextMacros", textMacroCheckBox->isChecked());
	settings.setValue("parseTextMacroInstances", textMacroInstanceCheckBox->isChecked());
	settings.setValue("parseTypes", typeCheckBox->isChecked());
	settings.setValue("parseGlobals", globalCheckBox->isChecked());
	settings.setValue("parseMembers", memberCheckBox->isChecked());
	settings.setValue("parseFunctionInterfaces", functionInterfaceCheckBox->isChecked());
	settings.setValue("parseFunctions", functionCheckBox->isChecked());
	settings.setValue("parseMethods", methodCheckBox->isChecked());
	settings.setValue("parseInterfaces", interfaceCheckBox->isChecked());
	settings.setValue("parseStructs", structCheckBox->isChecked());
	settings.setValue("parseScopes", scopeCheckBox->isChecked());
	settings.setValue("parseLibraries", libraryCheckBox->isChecked());
	settings.setValue("parseSourceFiles", sourceFileCheckBox->isChecked());
	settings.setValue("parseDocComments", docCommentCheckBox->isChecked());
	settings.setValue("parseAll", allCheckBox->isChecked());
	settings.setValue("geometry", geometry());
	settings.endGroup();
}

void VjassdocDialog::chooseDir()
{
	QString dirPath = QFileDialog::getExistingDirectory(this, tr("Ausgabeverzeichnis wählen"), this->chooseDirPath);
	
	if (dirPath.isEmpty())
		return;
	
	this->chooseDirPath = dirPath;
}

void VjassdocDialog::addImportDir()
{
	QString dirPath = QFileDialog::getExistingDirectory(this, tr("Import-Verzeichnis hinzufügen"), this->importDirPath);
	
	if (dirPath.isEmpty())
		return;
	
	this->importDirPath = dirPath;
	
	/*
	Instead of comparing list entries manually you could use the QList::removeOne() method
	for searching and removing list entries.
	As it might be faster I prefer this method.
	*/
	QString iterator;
	
	foreach (iterator, importDirs)
	{
		if (dirPath == iterator)
		{
			qDebug() << "Eintrag " << iterator << " existiert bereits und wird entfernt.";
			return;
		}
	}
	
	qDebug() << "Add import dirs " << dirPath;
	importDirs << dirPath;
	importDirListWidget->addItem(dirPath);
}

void VjassdocDialog::removeImportDirs()
{
	//TODO Disable remove button if nothing is selected
	QListWidgetItem *selectedItem;
	
	foreach (selectedItem, importDirListWidget->selectedItems())
	{
		importDirs.removeAt(importDirListWidget->row(selectedItem));
		importDirListWidget->takeItem(importDirListWidget->row(selectedItem));
	}
}

void VjassdocDialog::selectVjassdoc()
{
#ifdef Q_OS_WIN32
	static QString filter = tr("DOS/Windows-Programme (*.exe *.EXE)");
#else
	static QString filter = tr("Ausführbare Datei (*)");
#endif

	QString filePath = QFileDialog::getOpenFileName(this, tr("vjassdoc auswählen"), vjassdocFilePath, filter);

	if (filePath.isEmpty())
		return;
	
	vjassdocFilePath = filePath;
}

void VjassdocDialog::run()
{
	if (!QFile::exists(vjassdocFilePath))
	{
		QMessageBox::critical(this, tr("vjassdoc"), tr("Der Prozess vjassdoc konnte nicht gestartet werden,<br>da die ausführbare Datei \"%1\" nicht existiert.<br>Bitte wählen Sie eine andere Datei aus.").arg(vjassdocFilePath));
		selectVjassdoc();
		return;
	}
	
	//if the directory was deleted during the progress
	if (!QFile::exists(chooseDirPath))
	{
		QMessageBox::warning(this, tr("Ausgabeverzeichnis"), tr("Das gewählte Ausgabeverzeichnis \"%1\" existiert nicht.<br>Bitte wählen Sie ein anderes Verzeichnis.").arg(chooseDirPath));
		chooseDir();
		return;
	}

	QStringList args;
	
	args
	<< "--title" << titleLineEdit->text()
	<< "--dir" << chooseDirPath;
	
	qDebug() << "Dir path: " << QString(chooseDirPath);
	
	if (jassCheckBox->isChecked())
		args << "--jass";
	
	if (debugCheckBox->isChecked())
		args << "--debug";
	
	if (privateCheckBox->isChecked())
		args << "--private";
	
	if (textmacrosCheckBox->isChecked())
		args << "--textmacros";
	
	if (htmlCheckBox->isChecked())
	{
		args << "--html";
	
		if (pagesCheckBox->isChecked())
			args << "--pages";
	}
	
	if (databaseCheckBox->isChecked())
		args << "--database";
	
	if (verboseCheckBox->isChecked())
		args << "--verbose";
	
	if (timeCheckBox->isChecked())
		args << "--time";
	
	if (alphabeticalCheckBox->isChecked())
		args << "--alphabetical";
	
	if (!commentCheckBox->isChecked())
		args << "--nocomments";
	
	if (!keywordCheckBox->isChecked())
		args << "--nokeywords";
	
	if (!textMacroCheckBox->isChecked())
		args << "--notextmacros";
	
	if (!textMacroInstanceCheckBox->isChecked())
		args << "--notextmacroinstances";
	
	if (!typeCheckBox->isChecked())
		args << "--notypes";
	
	if (!globalCheckBox->isChecked())
		args << "--noglobals";
	
	if (!memberCheckBox->isChecked())
		args << "--nomembers";
	
	if (!functionInterfaceCheckBox->isChecked())
		args << "--nofunctioninterfaces";
	
	if (!functionCheckBox->isChecked())
		args << "--nofunctions";
	
	if (!methodCheckBox->isChecked())
		args << "--nomethods";
	
	if (!interfaceCheckBox->isChecked())
		args << "--nointerfaces";
	
	if (!structCheckBox->isChecked())
		args << "--nostructs";
	
	if (!scopeCheckBox->isChecked())
		args << "--noscopes";
	
	if (!libraryCheckBox->isChecked())
		args << "--nolibraries";
	
	if (!sourceFileCheckBox->isChecked())
		args << "--nosourcefiles";
	
	if (!docCommentCheckBox->isChecked())
		args << "--nodoccomments";
	
	if (!importDirs.isEmpty())
	{
		args << "--importdirs" << importDirs;
		qDebug() << "Import dirs:\n" << importDirs;
	}
	
	args << "--files";
	
	if (useCommonjCheckBox->isChecked())
	{
		QString path(static_cast<class MainWindow*>(parent())->commonjPath());
		
		if (!path.isEmpty())
			args << path;
	}
	
	if (useCommonaiCheckBox->isChecked())
	{
		QString path(static_cast<class MainWindow*>(parent())->commonaiPath());
		
		if (!path.isEmpty())
			args << path;
	}
	
	if (useBlizzardjCheckBox->isChecked())
	{
		QString path(static_cast<class MainWindow*>(parent())->blizzardjPath());
		
		if (!path.isEmpty())
			args << path;
	}
	
	args << static_cast<class MainWindow*>(parent())->getFilePaths();

	QProcess process;
	process.setWorkingDirectory(qApp->applicationDirPath());
	//process.setReadChannel(QProcess::StandardOutput);
	process.start(vjassdocFilePath, args);

	if (process.waitForFinished())
		qDebug("Process has finished.");

	static_cast<class MainWindow*>(this->parent())->outputTextBrowser->setPlainText(process.readAllStandardError() + process.readAllStandardOutput());
}

void VjassdocDialog::restoreDefaults()
{
	
}

}
