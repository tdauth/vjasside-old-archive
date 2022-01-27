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

#include "editorsettingsdialog.h"
#include "mainwindow.h"
#include "syntaxschema.h"
#include "formatdialog.h"

namespace vjasside
{

EditorSettingsDialog::EditorSettingsDialog(MainWindow *parent) : QDialog(parent), formatDialog(0)
{
	setupUi(this);
	
	//shortcuts
	qDebug() << "Rows " << parent->menuBar()->actions().count();
	
	int i = 0;
	QAction *action;
	
	foreach (action, parent->menuBar()->actions())
	{
		QTreeWidgetItem *item = new QTreeWidgetItem(shortcutTreeWidget);
		item->setText(0, action->text()); //.remove('&')
		//shortcutTreeWidget->addTopLevelItem(item);
		//no edit role
		//shortcutsModel->setData(shortcutsModel->index(i, 1), action->text().remove('&'));
		++i;
		qDebug() << "Test";

		/*
		if ((*iterator)->menu() == 0)
			qDebug("Menu is 0."); /// @todo FIX ME
		for (QList<QAction*>::iterator subIterator = (*iterator)->menu()->actions().begin(); subIterator != (*iterator)->menu()->actions().end(); ++subIterator)
		{
			qDebug() << "Second test";
			shortcutsModel->setData(shortcutsModel->index(i, 0), (*subIterator)->text());
			shortcutsModel->setData(shortcutsModel->index(i, 1), (*subIterator)->shortcut().toString());
			++i;
		}
		*/
		qDebug() << "Run with index " << i;
	}

	qDebug() << "TEST";

	connect(this, SIGNAL(accepted()), this, SLOT(save()));
	connect(this, SIGNAL(rejected()), this, SLOT(cancel()));
	connect(dialogButtonBox->button(QDialogButtonBox::RestoreDefaults), SIGNAL(clicked()), this, SLOT(restoreDefaults()));

	//editor
	connect(selectFontPushButton, SIGNAL(clicked()), this, SLOT(selectFont()));
	//syntax schemata
	connect(newSchemaPushButton, SIGNAL(clicked()), this, SLOT(newSchema()));
	connect(deleteSchemaPushButton, SIGNAL(clicked()), this, SLOT(deleteSchema()));
	connect(renameSchemaPushButton, SIGNAL(clicked()), this, SLOT(renameSchema()));
	connect(importSchemaPushButton, SIGNAL(clicked()), this, SLOT(importSchemas()));
	connect(exportSchemaPushButton, SIGNAL(clicked()), this, SLOT(exportSchema()));
	connect(schemaComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeCurrentSchema(int)));
	connect(formatPushButton, SIGNAL(clicked()), this, SLOT(selectFormat()));
	connect(addTemplatePushButton, SIGNAL(clicked()), this, SLOT(addTemplate()));
	connect(editTemplatePushButton, SIGNAL(clicked()), this, SLOT(editTemplate()));
	connect(removeTemplatesPushButton, SIGNAL(clicked()), this, SLOT(removeTemplates()));

	//read settings
	QSettings settings;
	settings.beginGroup("EditorSettingsDialog");
	
	//instance data
	const SyntaxSchema *syntaxSchema;
	
	foreach (syntaxSchema, parent->syntaxSchemata())
		schemaComboBox->addItem(syntaxSchema->name());
	
	importSchemaFilePath = settings.value("importSchemaFilePath", qApp->applicationDirPath()).toString();
	exportSchemaFilePath = settings.value("exportSchemaFilePath", qApp->applicationDirPath()).toString();
	//ui data
	//setGeometry(settings.value("geometry", QRect(QPoint(0, 0), sizeHint())).toRect()); /// @todo Saved wrong geometry
	tabWidget->setCurrentIndex(settings.value("tabWidgetIndex", 0).toInt());
	showLineNumbersCheckBox->setChecked(parent->lineNumbersAreShown());
	automaticIndentionCheckBox->setChecked(parent->automaticIndention());
	tabStopWidthSpinBox->setValue(parent->tabStopWidth());
	closeFilesWhenCreatingANewSessionCheckBox->setChecked(parent->closeFilesWhenCreatingANewSession());
	schemaComboBox->setCurrentIndex(settings.value("schemaIndex", 0).toInt());
	formatComboBox->setCurrentIndex(settings.value("formatIndex", 0).toInt());
	settings.endGroup();
}

EditorSettingsDialog::~EditorSettingsDialog()
{
	//write settings
	QSettings settings;
	settings.beginGroup("EditorSettingsDialog");
	//instance data
	settings.setValue("importSchemaFilePath", importSchemaFilePath);
	settings.setValue("exportSchemaFilePath", exportSchemaFilePath);
	//ui data
	settings.setValue("geometry", geometry());
	settings.setValue("tabWidgetIndex", tabWidget->currentIndex());
	settings.setValue("schemaIndex", schemaComboBox->currentIndex());
	settings.setValue("formatIndex", formatComboBox->currentIndex());
	settings.endGroup();
}

void EditorSettingsDialog::selectFont()
{
	bool ok;
	QFont font = QFontDialog::getFont(&ok, static_cast<MainWindow*>(this->parent())->font(), this);
	
	if (!ok)
		return;
	
	this->font = font;
}

void EditorSettingsDialog::newSchema()
{
	bool ok;
	newSchemaName = QInputDialog::getText(this, tr("Neues Syntax-Schema"), tr("Name:"), QLineEdit::Normal, newSchemaName, &ok);

	if (!ok)
		return;

	if (newSchemaName.isEmpty())
	{
		QMessageBox::information(this, tr("Neues Syntax-Schema"), tr("Syntax-Schema-Name darf nicht leer sein."));
		newSchema();
		return;
	}

	createNewSyntaxSchema(newSchemaName);
}

void EditorSettingsDialog::deleteSchema()
{
	QList<class SyntaxSchema*> syntaxSchemata = static_cast<class MainWindow*>(this->parent())->syntaxSchemata();

	if (syntaxSchemata.size() == 1)
	{
		QMessageBox::information(this, tr("Syntax-Schema"), tr("Es muss mindestens ein Syntax-Schema erhalten bleiben."));
		return;
	}

	int index = this->schemaComboBox->currentIndex();
	static_cast<class MainWindow*>(this->parent())->removeSyntaxSchema(index);
	this->schemaComboBox->removeItem(index);
}

void EditorSettingsDialog::renameSchema()
{
	qDebug() << "Test";
	bool ok;
	renameSchemaName = QInputDialog::getText(this, tr("Syntax-Schema umbenennen"), tr("Neuer Name:"), QLineEdit::Normal, renameSchemaName, &ok);
	
	if (!ok)
		return;
	
	if (renameSchemaName.isEmpty())
	{
		QMessageBox::information(this, tr("Syntax-Schema umbenennen"), tr("Syntax-Schema-Name darf nicht leer sein."));
		renameSchema();
		return;
	}
	
	if (checkForSchemaName(renameSchemaName) == -1)
	{
		static_cast<class MainWindow*>(this->parent())->renameSyntaxSchema(schemaComboBox->currentIndex(), renameSchemaName);
		this->schemaComboBox->setItemText(schemaComboBox->currentIndex(), renameSchemaName);
	}
	else
	{
		QMessageBox::information(this, tr("Syntax-Schema umbenennen"), tr("Es existiert bereits ein Syntax-Schema unter diesem Namen."));
		renameSchema();
	}
}

void EditorSettingsDialog::importSchemas()
{
	QStringList importSchemaFilePaths = QFileDialog::getOpenFileNames(this, tr("Syntax-Schema importieren"), importSchemaFilePath, tr("Alle Dateien (*);;XML-Dateien (*.xml *.XML)"));

	if (importSchemaFilePaths.isEmpty())
		return;
	
	this->importSchemaFilePath = importSchemaFilePaths.first();
	QString iterator;
	
	foreach (iterator, importSchemaFilePaths)
	{
		QString name = SyntaxSchema::getNameByXmlFile(iterator);
		
		if (name.isEmpty())
		{
			QMessageBox::critical(this, tr("Syntax-Schema importieren"), tr("Fehler beim Auslesen des Schemanamens der Datei \"%1\".").arg(iterator));
			return;
		}
		
		createNewSyntaxSchema(name);
		QList<class SyntaxSchema*> syntaxSchemata = static_cast<class MainWindow*>(parent())->syntaxSchemata();
		class SyntaxSchema *syntaxSchema = syntaxSchemata.last();
		
		try
		{
			syntaxSchema->importFromXmlFile(iterator);
		}
		catch (SyntaxSchemaException syntaxSchemaException)
		{
			QMessageBox::critical(this, tr("Syntax-Schema importieren"), tr("Fehler beim Importieren des Syntax-Schemas \"%1\".<br>Fehlermeldung:<br>%2").arg(iterator).arg(syntaxSchemaException.message()));
		}
	}
}

void EditorSettingsDialog::exportSchema()
{
	QString newExportSchemaFilePath = QFileDialog::getSaveFileName(this, tr("Syntax-Schema exportieren"), exportSchemaFilePath, tr("Alle Dateien (*);;XML-Dateien (*.xml *.XML)"));
	
	if (newExportSchemaFilePath.isEmpty())
		return;
	
	exportSchemaFilePath = newExportSchemaFilePath;

	QList<class SyntaxSchema*> syntaxSchemata = static_cast<class MainWindow*>(parent())->syntaxSchemata();
	qDebug() << "Index " << schemaComboBox->currentIndex();
	
	if (syntaxSchemata.value(schemaComboBox->currentIndex()) == 0)
		qDebug() << "Is 0";
	
	try
	{
		syntaxSchemata.value(schemaComboBox->currentIndex())->exportIntoXmlFile(newExportSchemaFilePath);
	}
	catch (SyntaxSchemaException syntaxSchemaException)
	{
		QMessageBox::critical(this, tr("Syntax-Schema exportieren"), tr("Fehler beim Exportieren des Syntax-Schemas \"%1\".<br>Fehlermeldung:<br>%2").arg(newExportSchemaFilePath).arg(syntaxSchemaException.message()));
	}
}

void EditorSettingsDialog::changeCurrentSchema(const int &index)
{
	qDebug() << "Change to index " << index;
	this->templateListWidget->clear();
	class SyntaxSchema *syntaxSchema = static_cast<class MainWindow*>(this->parent())->syntaxSchemata()[index];
	
	for (QMap<QString, QString>::const_iterator iterator = syntaxSchema->regularyExpressionTemplates().constBegin(); iterator != syntaxSchema->regularyExpressionTemplates().constEnd(); ++iterator)
		templateListWidget->addItem(iterator.key());

	qDebug() << "Change current schema to " << index;
	static_cast<class MainWindow*>(this->parent())->setCurrentSyntaxSchemaIndex(schemaComboBox->currentIndex());
}

void EditorSettingsDialog::selectFormat()
{
	if (this->formatDialog == 0)
		formatDialog = new FormatDialog(this, static_cast<class MainWindow*>(this->parent()));
	
	class SyntaxSchema *syntaxSchema = static_cast<class MainWindow*>(parent())->syntaxSchemata().value(schemaComboBox->currentIndex());
	SyntaxSchema::Format format = SyntaxSchema::Format(formatComboBox->currentIndex());
	formatDialog->setSyntaxSchemaFormat(syntaxSchema, format);
	formatDialog->show();
	
	if (formatDialog->exec() == QDialog::Accepted)
	{
		syntaxSchema->setFormat(format, formatDialog->bold(), formatDialog->italic(), formatDialog->underline(), formatDialog->strikeOut(), formatDialog->foregroundColor(), formatDialog->backgroundColor());
	}
}

void EditorSettingsDialog::addTemplate()
{
	bool ok;
	templateName = QInputDialog::getText(this, tr("Vorlage hinzufügen"), tr("Name:"), QLineEdit::Normal, templateName, &ok);
	
	if (!ok)
		return;

	if (static_cast<class MainWindow*>(parent())->currentSyntaxSchema()->regularyExpressionTemplateExists(templateName))
	{
		QMessageBox::warning(this, tr("Vorlage hinzufügen"), tr("Es existiert bereits eine Vorlage mit diesem Namen.<br>Bitte wählen Sie einen neuen Namen."));
		this->addTemplate();
		return;
	}
	
	templateRegularyExpression = QInputDialog::getText(this, tr("Vorlage hinzufügen"), tr("Regulärer Ausdruck:"), QLineEdit::Normal, templateRegularyExpression, &ok);
	
	if (!ok)
		return;
	
	static_cast<class MainWindow*>(parent())->currentSyntaxSchema()->setRegularyExpressionTemplate(templateName, templateRegularyExpression);
	//QListWidgetItem *item = new QListWidgetItem(iterator.key(), templateListWidget);
	templateListWidget->addItem(templateName);
}

/// @todo Fix me
void EditorSettingsDialog::editTemplate()
{
/*
	QListWidgetItem *listWidgetItem = templateListWidget->selectedItems().first();
	
	templateRegularyExpression = QInputDialog::getText(this, tr("Vorlage hinzufügen"), tr("Regulärer Ausdruck:"), QLineEdit::Normal, templateRegularyExpression, &ok);
*/
}

/// @todo Fix me
void EditorSettingsDialog::removeTemplates()
{
}

void EditorSettingsDialog::addList()
{
}

void EditorSettingsDialog::removeLists()
{
}

/// @todo Set new syntax schemata.
void EditorSettingsDialog::save()
{
	class MainWindow *parent = static_cast<class MainWindow*>(this->parent());
	parent->setLineNumbersAreShown(showLineNumbersCheckBox->isChecked());
	parent->setAutomaticIndention(automaticIndentionCheckBox->isChecked());
	parent->setTabStopWidth(tabStopWidthSpinBox->value());
	parent->setCloseFilesWhenCreatingANewSession(closeFilesWhenCreatingANewSessionCheckBox->isChecked());
	parent->setFont(this->font);
	hide();
	parent->rehighlightAllFiles();
}

/// @todo Reset syntax schemata.
void EditorSettingsDialog::cancel()
{
	class MainWindow *parent = static_cast<class MainWindow*>(this->parent());
	showLineNumbersCheckBox->setChecked(parent->lineNumbersAreShown());
	automaticIndentionCheckBox->setChecked(parent->automaticIndention());
	tabStopWidthSpinBox->setValue(parent->tabStopWidth());
	closeFilesWhenCreatingANewSessionCheckBox->setChecked(parent->closeFilesWhenCreatingANewSession());
	this->font = parent->font();
	hide();
}

/// @todo Set default syntax schemata.
void EditorSettingsDialog::restoreDefaults()
{
	showLineNumbersCheckBox->setChecked(MainWindow::lineNumbersAreShownDefaultValue());
	tabStopWidthSpinBox->setValue(MainWindow::tabStopWidthDefaultValue());
	closeFilesWhenCreatingANewSessionCheckBox->setChecked(MainWindow::closeFilesWhenCreatingANewSessionDefaultValue());
	this->font = MainWindow::fontDefaultValue();
}

void EditorSettingsDialog::createNewSyntaxSchema(const QString &name)
{
	int index = checkForSchemaName(name);
	QList<class SyntaxSchema*> syntaxSchemata = static_cast<class MainWindow*>(parent())->syntaxSchemata();
	
	if (index != -1)
	{
		if (QMessageBox::question(this, tr("Neues Syntax-Schema"), tr("Es existiert bereits ein Syntax-Schema unter diesem Namen.<br>Möchten Sie es ersetzen?"), QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
			return;
		
		delete syntaxSchemata.value(index); //delete old schema
	}
	else
		index = syntaxSchemata.size();
	
	qDebug("TEST 1");
	SyntaxSchema *syntaxSchema = SyntaxSchema::createStandardSchema(name);
	qDebug("TEST 2");

	if (index != syntaxSchemata.size()) //replace
	{
		qDebug("INSERT");
		syntaxSchemata.insert(index, syntaxSchema);
	}
	else //create new
	{
		qDebug() << "PUSH BACK " << "Index: " << index;
		static_cast<class MainWindow*>(this->parent())->addSyntaxSchema(syntaxSchema);
		schemaComboBox->addItem(name);
	}

	//changeCurrentSchema(index);
	qDebug() << "And another test";
	schemaComboBox->setCurrentIndex(index);
	qDebug() << "And just another test";
}

int EditorSettingsDialog::checkForSchemaName(const QString &name)
{
	int index = 0;
	QList<class SyntaxSchema*> syntaxSchemata = static_cast<class MainWindow*>(parent())->syntaxSchemata();
	const SyntaxSchema *syntaxSchema;
	
	foreach (syntaxSchema, syntaxSchemata)
	{
		if (syntaxSchema->name() == name)
			return index;

		++index;
	}

	return -1;
}

}
