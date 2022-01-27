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

#include <QDialog>
#include <QString>

#include "ui_pjassdialog.h"

namespace vjasside
{

class MainWindow;

class PjassDialog : public QDialog, public Ui::PjassDialog
{
	Q_OBJECT

	public:
		PjassDialog(class MainWindow *parent);
		~PjassDialog();
	
	public slots:
		void selectPjass();
		void run();
		void restoreDefaults();
	
	private:
		static QString defaultPjassFilePath;
		QString pjassFilePath;
};

}
