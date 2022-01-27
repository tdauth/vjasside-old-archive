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

#include "syntaxhighlighter.h"
#include "textedit.h"
#include "syntaxschema.h"
#include "regexplist.h"

namespace vjasside
{

SyntaxHighlighter::SyntaxHighlighter(TextEdit *parent, MainWindow *mainWindow) : QSyntaxHighlighter(parent), m_mainWindow(mainWindow)
{
}

SyntaxHighlighter::~SyntaxHighlighter()
{
}

void SyntaxHighlighter::highlightBlock(const QString &text)
{
	if (text.isEmpty())
		return;

	int start = 0;
	/*
	for ( ; start < text.length(); ++start)
	{
		if (text[start] == ' ' || text[start] == '\t')
			continue;
		//else if (text[start] == '\n') //FIXME There are no \n characters?!
			//return;
		else
			break;
	}
	*/
	
	setFormat(start, text.length(), SyntaxSchema::Text);
	int freeSpace = text.length() - start;
	
	/*
	int position = QRegExp("//").indexIn(text, start);
	int freeSpace = text.length() - start;
	
	if (position != -1)
	{
		if (position < text.length() - 2 && text[position + 2] == '/')
		{
			setFormat(position, text.length(), SyntaxSchema::DocComment);
			RegExpList::regExpList(SyntaxSchema::DocCommentKeyword).find(text, position + 3, freeSpace, this);
			
			//findDocCommentKeyword(position + 3, text);
		}
		else
		{
			if (position == text.length() - 2 || text[position + 2] != '!')
				setFormat(position, text.length(), SyntaxSchema::Comment);
			else
			{
				setFormat(position, text.length(), SyntaxSchema::Preprocessor);
				RegExpList::regExpList(SyntaxSchema::PreprocessorKeyword).find(text, position + 3, freeSpace, this);
				
				//findPreprocessorKeyword(position + 3, text); //start at position x //! x
				//search comment or doc comment!
			}
		}
	}
	
	//start = position - start;
	if (freeSpace == 0)
		return;
	
	QString subString;
	
	if (position != -1)
		subString = text.mid(start, position - start);
	else
		subString = text;
	*/

	SyntaxSchema *syntaxSchema = mainWindow()->currentSyntaxSchema();
	
	for (int i = 0; i < syntaxSchema->regularyExpressionLists(); ++i)
		syntaxSchema->regularyExpressionList(SyntaxSchema::Format(i)).find(text, start, freeSpace, this);
	
	/*
	SyntaxSchema *syntaxSchema = mainWindow()->currentSyntaxSchema();
	syntaxSchema->regularyExpressionList(SyntaxSchema::Integer).find(text, start, freeSpace, this);
	syntaxSchema->regularyExpressionList(SyntaxSchema::Real).find(text, start, freeSpace, this);
	syntaxSchema->regularyExpressionList(SyntaxSchema::Character).find(text, start, freeSpace, this);
	syntaxSchema->regularyExpressionList(SyntaxSchema::String).find(text, start, freeSpace, this);
	syntaxSchema->regularyExpressionList(SyntaxSchema::Operator).find(text, start, freeSpace, this);
	syntaxSchema->regularyExpressionList(SyntaxSchema::Keyword).find(text, start, freeSpace, this);
	syntaxSchema->regularyExpressionList(SyntaxSchema::VjassKeyword).find(text, start, freeSpace, this);
	syntaxSchema->regularyExpressionList(SyntaxSchema::PreprocessorArgument).find(text, start, freeSpace, this);
	*/

	// TODO Search for vjassdoc database expressions.
}

/*
void SyntaxHighlighter::findDocCommentKeyword(int start, const QString &text)
{
	if (start >= text.length() - 1)
		return;
	
	for (int position = QRegExp("@[A-Za-z0-9]").indexIn(text, start); position != -1; position = QRegExp("@[A-Za-z0-9]").indexIn(text, start))
	{
		start = position + 1;
		QString expression;
		
		foreach (expression, RegExpList::regExpList(SyntaxSchema::DocCommentKeyword).expressions())
		{
			if (text.mid(position + 1, expression.length()) == expression)
			{
				setFormat(position, expression.length() + 1, mainWindow->currentSyntaxSchema()->format(SyntaxSchema::DocCommentKeyword));
				start += expression.length();
				
				//if (text.mid(start).length() - start >= docCommentKeywordListMinimumSpace)
					//findDocCommentKeyword(start, text);
			}
		}
		
		if (text.length() - start < RegExpList::regExpList(SyntaxSchema::DocCommentKeyword).minimumRequiredSpace())
			break;
	}
}
*/

/*
void SyntaxHighlighter::findPreprocessorKeyword(int start, const QString &text)
{
	if (start >= text.length() - 1)
		return;
	
	QString expression;
	
	for ( ; start < text.length(); ++start)
	{
		foreach (expression, preprocessorKeywordList)
		{
			if (text.mid(start, expression.length()) == expression)
			{
				setFormat(start, expression.length(), mainWindow->currentSyntaxSchema()->format(SyntaxSchema::PreprocessorKeyword));
				return;
			}
		}
	}
}
*/

}
