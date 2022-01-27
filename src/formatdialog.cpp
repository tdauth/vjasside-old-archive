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

#include "formatdialog.h"
#include "mainwindow.h"

namespace vjasside
{

FormatDialog::FormatDialog(QWidget *parent, const class MainWindow *mainWindow) : QDialog(parent)
{
	setupUi(this);

	connect(boldCheckBox, SIGNAL(clicked(bool)), this, SLOT(setBold(bool)));
	connect(italicCheckBox, SIGNAL(clicked(bool)), this, SLOT(setItalic(bool)));
	connect(underlineCheckBox, SIGNAL(clicked(bool)), this, SLOT(setUnderline(bool)));
	connect(strikeOutCheckBox, SIGNAL(clicked(bool)), this, SLOT(setStrikeOut(bool)));
	connect(foregroundColorPushButton, SIGNAL(clicked()), this, SLOT(selectForegroundColor()));
	connect(backgroundColorPushButton, SIGNAL(clicked()), this, SLOT(selectBackgroundColor()));
	connect(mainWindow, SIGNAL(fontChanged(const QFont&)), this, SLOT(refreshFont(const QFont&)));
	
	this->format.setFont(mainWindow->font());
	
	/// @todo Load ui settings.
	//settings
	//ui settings
}

void FormatDialog::selectForegroundColor()
{
	QColor color = QColorDialog::getColor(this->format.foreground().color(), this);
	
	if (!color.isValid())
		return;
	
	this->setForegroundColor(color);
}

void FormatDialog::selectBackgroundColor()
{
	QColor color = QColorDialog::getColor(this->format.background().color(), this);
	
	if (!color.isValid())
		return;
	
	this->setBackgroundColor(color);
}

void FormatDialog::refreshFont(const QFont &font)
{
	this->format.setFont(font);
	this->refreshTextExample();
}

void FormatDialog::refreshTextExample()
{
	QTextCursor textCursor = this->textBrowser->textCursor();
	textCursor.select(QTextCursor::Document);
	textCursor.setCharFormat(this->format);
}

}
