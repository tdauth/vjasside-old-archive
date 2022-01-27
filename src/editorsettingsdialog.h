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

#ifndef VJASSIDE_EDITORSETTINGSDIALOG_H
#define VJASSIDE_EDITORSETTINGSDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QDir>

#include "ui_editorsettingsdialog.h"

namespace vjasside
{

class MainWindow;
class FormatDialog;

class EditorSettingsDialog : public QDialog, public Ui::EditorSettingsDialog
{
	Q_OBJECT

	public:
		EditorSettingsDialog(class MainWindow *parent);
		~EditorSettingsDialog();

	private slots:
		void selectFont();
		void newSchema();
		void deleteSchema();
		void renameSchema();
		void importSchemas();
		void exportSchema();
		void changeCurrentSchema(const int &index);
		void selectFormat();
		void addTemplate();
		void editTemplate();
		void removeTemplates();
		void addList();
		void removeLists();
		
		void save();
		void cancel();
		void restoreDefaults();

	private:
		void createNewSyntaxSchema(const QString &name);
		int checkForSchemaName(const QString &name);

		QString newSchemaName;
		QString renameSchemaName;
		QString importSchemaFilePath;
		QString exportSchemaFilePath;
		class FormatDialog *formatDialog;
		QString templateName;
		QString templateRegularyExpression;
		
		QFont font;
};

}

#endif
