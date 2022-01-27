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

#ifndef VJASSIDE_VJASSDOCDIALOG_H
#define VJASSIDE_VJASSDOCDIALOG_H

#include <QDialog>
#include <QStringList>

#include "ui_vjassdocdialog.h"

namespace vjasside
{

class MainWindow;

class VjassdocDialog : public QDialog, public Ui::VjassdocDialog
{
	Q_OBJECT

	public:
		VjassdocDialog(class MainWindow *mainWindow);
		~VjassdocDialog();

	private slots:
		void chooseDir();
		void addImportDir();
		void removeImportDirs();
		void selectVjassdoc();
		void run();
		void restoreDefaults();
	
	private:
		QString chooseDirPath;
		QString importDirPath;
		QString vjassdocFilePath;
		QStringList importDirs;
};

}

#endif
