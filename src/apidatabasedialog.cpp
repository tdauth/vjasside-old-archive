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

#include "apidatabasedialog.h"
#include "mainwindow.h"
#include "vjassdoc/vjassdoc.h"
#include "regexplist.h"

namespace vjasside
{

ApiDatabaseDialog::ApiDatabaseDialog(class MainWindow *parent) : QDialog(parent)
{
	setupUi(this);
	
	connect(this->listWidget, SIGNAL(itemSelectionChanged()), this, SLOT(databaseSelectionChanged()));
	connect(addDatabasesPushButton, SIGNAL(clicked()), this, SLOT(addDatabases()));
	connect(removeDatabasesPushButton, SIGNAL(clicked()), this, SLOT(removeDatabases()));
	connect(this, SIGNAL(accepted()), this, SLOT(save()));
	connect(this, SIGNAL(rejected()), this, SLOT(cancel()));
	connect(buttonBox->button(QDialogButtonBox::RestoreDefaults), SIGNAL(clicked()), this, SLOT(restoreDefaults()));

	//read settings
	QSettings settings;
	settings.beginGroup("ApiDatabaseDialog");
	//instance data
	this->filePath = settings.value("filePath", qApp->applicationDirPath()).toString();
	int size = settings.beginReadArray("databases");
	
	for (int i = 0; i < size; ++i)
	{
		settings.setArrayIndex(i);
		this->databases << settings.value("filePath").toString();
	}
	
	settings.endArray();
	//ui data
	settings.endGroup();
	QString iterator;
	int i = 0;
	
	foreach (iterator, this->databases)
	{
		qDebug() << "Load database " << iterator;
		int index = RegExpList::addApiDatabase(iterator);

		if (index == -1)
		{
			this->databases.removeAt(i);
			QMessageBox::critical(this, tr("vjassdoc-Datenbank hinzufügen"), tr("Datenbank \"%1\" konnte nicht geladen werden.").arg(iterator));
		}
		
		++i;
	}
	
	this->newDatabases = this->databases;
	this->listWidget->addItems(this->databases);
	
	
}

ApiDatabaseDialog::~ApiDatabaseDialog()
{
	//write settings
	QSettings settings;
	settings.beginGroup("ApiDatabaseDialog");
	//instance data
	settings.setValue("filePath", this->filePath);
	settings.beginWriteArray("databases");
	QString filePath;
	int i = 0;
	
	foreach (filePath, this->databases)
	{
		settings.setArrayIndex(i);
		settings.setValue("filePath", filePath);
		++i;
	}
	
	settings.endArray();
	//ui data
	settings.endGroup();
}

void ApiDatabaseDialog::databaseSelectionChanged()
{
	bool empty = this->listWidget->selectedItems().isEmpty();
	this->removeDatabasesPushButton->setDisabled(empty);
	this->objectActionsGroupBox->setDisabled(empty);
	
}

void ApiDatabaseDialog::addDatabases()
{
	QStringList newFilePaths = QFileDialog::getOpenFileNames(this, tr("API-Datenbank(en) hinzufügen"), filePath, tr("Alle Dateien (*);;API-Datenbanken (*.db *.DB)"));
	
	if (newFilePaths.isEmpty())
		return;
	
	filePath = newFilePaths.first();
	QString iterator0;
	int i = 0;
	
	foreach (iterator0, newFilePaths)
	{
		QString iterator1;
		
		foreach (iterator1, this->newDatabases)
		{
			if (iterator0 == iterator1)
			{
				newFilePaths.removeAt(i);
				qDebug() << "Eintrag " << iterator0 << " existiert bereits und wird entfernt.";
				break;
			}
		}
		
		++i;
	}
	
	if (newFilePaths.isEmpty()) //check again
		return;
	
	this->newDatabases << newFilePaths;
	this->listWidget->addItems(newFilePaths);
}

void ApiDatabaseDialog::removeDatabases()
{
	//TODO Disable remove button if nothing is selected
	QListWidgetItem *selectedItem;
	
	foreach (selectedItem, this->listWidget->selectedItems())
	{
		qDebug() << "Remove database of row " << this->listWidget->row(selectedItem);
		this->newDatabases.removeAt(this->listWidget->row(selectedItem));
		this->listWidget->takeItem(this->listWidget->row(selectedItem));
	}
}

void ApiDatabaseDialog::save()
{
	QString iterator;
	int i = 0;
	
	foreach (iterator, this->databases)
	{
		if (!this->newDatabases.contains(iterator))
			qDebug() << "Unload database " << iterator << '.'; /// @todo unload database
	}
	
	foreach (iterator, this->newDatabases)
	{
		if (!this->databases.contains(iterator))
		{
			qDebug() << "Load database " << iterator;
			int index = RegExpList::addApiDatabase(iterator);

			if (index == -1)
			{
				this->newDatabases.removeAt(i);
				QMessageBox::critical(this, tr("vjassdoc-Datenbank hinzufügen"), tr("Datenbank \"%1\" konnte nicht geladen werden.").arg(iterator));
			}
		}
		else
			qDebug() << "Database " << iterator << " has already been loaded.";
		
		++i;
	}
	
	this->databases = this->newDatabases;
}

void ApiDatabaseDialog::cancel()
{
	this->newDatabases = this->databases;
	this->listWidget->clear();
	
	if (this->databases.isEmpty())
		return;
	
	this->listWidget->addItems(this->databases);
}

/// @todo Use default API databases for the native and generic Jass objects.
void ApiDatabaseDialog::restoreDefaults()
{
}

}
