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

#ifndef VJASSIDE_SYNTAXHIGHLIGHTER_H
#define VJASSIDE_SYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>

#include "mainwindow.h"
#include "syntaxschema.h"
#include "textview.h"

namespace vjasside
{

class TextEdit;

class SyntaxHighlighter : public QSyntaxHighlighter
{
	public:
		SyntaxHighlighter(class TextEdit *parent, class MainWindow *mainWindow);
		virtual ~SyntaxHighlighter();
		
		MainWindow* mainWindow() const;
		void setFormat(const int &position, const int &length, const enum SyntaxSchema::Format &format);
		void setLineProperties(const bool &openBlock, const bool &closeBlock);
		
	protected:
		virtual void highlightBlock(const QString &text);

	private:
		//void findDocCommentKeyword(int start, const QString &text);
		//void findPreprocessorKeyword(int start, const QString &text);
		MainWindow *m_mainWindow;
};

inline MainWindow* SyntaxHighlighter::mainWindow() const
{
	return m_mainWindow;
}

inline void SyntaxHighlighter::setFormat(const int &position, const int &length, const SyntaxSchema::Format &format)
{
	QTextCharFormat textCharFormat;
	class SyntaxSchema *syntaxSchema = this->mainWindow()->currentSyntaxSchema();
	QFont font(this->mainWindow()->font());
	font.setBold(syntaxSchema->formatBold(format));
	font.setItalic(syntaxSchema->formatItalic(format));
	font.setUnderline(syntaxSchema->formatUnderline(format));
	font.setStrikeOut(syntaxSchema->formatStrikeOut(format));
	textCharFormat.setFont(font);
	textCharFormat.setForeground(syntaxSchema->formatForegroundColor(format));
	textCharFormat.setBackground(syntaxSchema->formatBackgroundColor(format));
	QSyntaxHighlighter::setFormat(position, length, textCharFormat);
}

inline void SyntaxHighlighter::setLineProperties(const bool &openBlock, const bool &closeBlock)
{
	class TextEdit *textEdit = static_cast<TextEdit*>(this->parent());
	class TextView *textView = static_cast<class TextView*>(textEdit->parent());
	textView->setLineProperties(currentBlock().blockNumber(), openBlock, closeBlock);
}

}

#endif
