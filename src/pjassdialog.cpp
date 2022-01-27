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

#include "pjassdialog.h"
#include "mainwindow.h"

namespace vjasside
{

#ifdef Q_OS_WIN32
QString PjassDialog::defaultPjassFilePath = qApp->applicationDirPath() + "/bin/pjass.exe";
#else
QString PjassDialog::defaultPjassFilePath = qApp->applicationDirPath() + "/bin/pjass";
#endif

PjassDialog::PjassDialog(class MainWindow *parent) : QDialog(parent)
{
	setupUi(this);
	
	connect(this->selectPjassPushButton, SIGNAL(clicked()), this, SLOT(selectPjass()));
	connect(this, SIGNAL(accepted()), this, SLOT(run()));
	connect(this->buttonBox->button(QDialogButtonBox::RestoreDefaults), SIGNAL(clicked()), this, SLOT(restoreDefaults()));
	
	QSettings settings;
	settings.beginGroup("PjassDialog");
	//instance data
	this->pjassFilePath = settings.value("pjassFilePath", PjassDialog::defaultPjassFilePath).toString();
	//ui data
	setGeometry(settings.value("geometry", QRect(QPoint(0, 0), this->sizeHint())).toRect());
	settings.endGroup();
}

PjassDialog::~PjassDialog()
{
	QSettings settings;
	settings.beginGroup("PjassDialog");
	//instance data
	settings.setValue("pjassFilePath", this->pjassFilePath);
	//ui data
	settings.setValue("geometry", this->geometry());
	settings.endGroup();
}

void PjassDialog::selectPjass()
{
	QString newFilePath;
	QFileDialog::getOpenFileName(this, tr("pjass auswählen"), newFilePath);

	if (newFilePath.isEmpty())
		return;

	this->pjassFilePath = newFilePath;
}

void PjassDialog::run()
{
	if (!QFile::exists(this->pjassFilePath))
	{
		QMessageBox::critical(this, tr("pjass"), tr("Der Prozess pjass konnte nicht gestartet werden,<br>da die ausführbare Datei \"%1\" nicht existiert.<br>Bitte wählen Sie eine andere Datei aus.").arg(this->pjassFilePath));
		this->selectPjass();
		return;
	}

	QStringList args;
	QString path0(static_cast<class MainWindow*>(this->parent())->commonjPath());

	if (!path0.isEmpty())
		args << path0;
	
	QString path1(static_cast<class MainWindow*>(this->parent())->commonaiPath());

	if (!path1.isEmpty())
		args << path1;
	
	QString path2(static_cast<class MainWindow*>(this->parent())->blizzardjPath());

	if (!path2.isEmpty())
		args << path2;
	
	args << static_cast<class MainWindow*>(this->parent())->getFilePaths();

	QProcess process;
	process.setWorkingDirectory(qApp->applicationDirPath());
	//process.setReadChannel(QProcess::StandardOutput);
	process.start(this->pjassFilePath, args);

	if (process.waitForFinished())
		qDebug("Process has finished.");


	static_cast<class MainWindow*>(this->parent())->outputTextBrowser->setPlainText(process.readAllStandardError() + process.readAllStandardOutput());
}

void PjassDialog::restoreDefaults()
{
	this->pjassFilePath = PjassDialog::defaultPjassFilePath;
}

}
