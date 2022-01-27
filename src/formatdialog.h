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
#include <QColor>
#include <QTextCharFormat>

#include "ui_formatdialog.h"
#include "syntaxschema.h"

namespace vjasside
{

class MainWindow;

class FormatDialog : public QDialog, public Ui::FormatDialog
{
	Q_OBJECT

	public slots:
		void setBold(bool bold);
		void setItalic(bool italic);
		void setUnderline(bool underline);
		void setStrikeOut(bool strikeOut);

	public:
		FormatDialog(QWidget *parent, const class MainWindow *mainWindow);
		
		void setSyntaxSchemaFormat(const class SyntaxSchema *syntaxSchema, const enum SyntaxSchema::Format &format);
		bool bold() const;
		bool italic() const;
		bool underline() const;
		bool strikeOut() const;
		void setForegroundColor(QColor color);
		QColor foregroundColor() const;
		void setBackgroundColor(QColor color);
		QColor backgroundColor() const;
	
	private slots:
		void selectForegroundColor();
		void selectBackgroundColor();
		void refreshFont(const QFont &font);
	
	private:
		void refreshTextExample();
	
		QTextCharFormat format;
};

inline void FormatDialog::setSyntaxSchemaFormat(const class SyntaxSchema *syntaxSchema, const enum SyntaxSchema::Format &format)
{
	this->setBold(syntaxSchema->formatBold(format));
	this->setItalic(syntaxSchema->formatItalic(format));
	this->setUnderline(syntaxSchema->formatUnderline(format));
	this->setStrikeOut(syntaxSchema->formatStrikeOut(format));
	this->setForegroundColor(syntaxSchema->formatForegroundColor(format));
	this->setBackgroundColor(syntaxSchema->formatBackgroundColor(format));
}

/// @todo Missing setFontBold() method of class QTextCharFormat.
inline void FormatDialog::setBold(bool bold)
{
	QFont font = this->format.font();
	font.setBold(bold);
	this->format.setFont(font);
	this->refreshTextExample();
	this->boldCheckBox->setChecked(bold);
}

inline bool FormatDialog::bold() const
{
	return this->format.font().bold();
}

inline void FormatDialog::setItalic(bool italic)
{
	this->format.setFontItalic(italic);
	this->refreshTextExample();
	this->italicCheckBox->setChecked(italic);
}

inline bool FormatDialog::italic() const
{
	return this->format.fontItalic();
}

inline void FormatDialog::setUnderline(bool underline)
{
	this->format.setFontUnderline(underline);
	this->refreshTextExample();
	this->underlineCheckBox->setChecked(underline);
}

inline bool FormatDialog::underline() const
{
	return this->format.fontUnderline();
}

inline void FormatDialog::setStrikeOut(bool strikeOut)
{
	this->format.setFontStrikeOut(strikeOut);
	this->refreshTextExample();
	this->strikeOutCheckBox->setChecked(strikeOut);
}

inline bool FormatDialog::strikeOut() const
{
	return this->format.fontStrikeOut();
}

inline void FormatDialog::setForegroundColor(QColor color)
{
	this->format.setForeground(color);
	this->refreshTextExample();
}

inline QColor FormatDialog::foregroundColor() const
{
	return this->format.foreground().color();
}

inline void FormatDialog::setBackgroundColor(QColor color)
{
	this->format.setBackground(color);
	this->refreshTextExample();
}

inline QColor FormatDialog::backgroundColor() const
{
	return this->format.background().color();
}

}
