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

#include "textedit.h"
#include "textview.h"
#include "mainwindow.h"

namespace vjasside
{

TextEdit::TextEdit(QWidget *parent) : QTextEdit(parent), m_textView(0), lineMenu(0), selectedMenu(0), insertColorAction(0), m_canUndo(false), m_canRedo(false), m_canCopy(false)
{
	//setAcceptRichText(false);
	//setLineWrapMode(QTextEdit::FixedPixelWidth);
	//setLineWrapColumnOrWidth(65535); //copied from qdevelop source code
	
	connect(this, SIGNAL(undoAvailable(bool)), this, SLOT(setUndoAvailable(bool)));
	connect(this, SIGNAL(redoAvailable(bool)), this, SLOT(setRedoAvailable(bool)));
	connect(this, SIGNAL(copyAvailable(bool)), this, SLOT(setCopyAvailable(bool)));
}

TextEdit::~TextEdit()
{
}

void TextEdit::openFile(const QString &filePath)
{
	QFile file(filePath);
	
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) // | QIODevice::Text
		QMessageBox::critical(m_textView->mainWindow(), tr("Datei öffnen"), tr("Datei \"%1\" konnte nicht geöffnet werden.").arg(filePath));

	QTextStream textStream(&file);
	QString entry;
	
	while (!textStream.atEnd())
		entry += textStream.readLine() + '\n';

	setPlainText(entry);
}

void TextEdit::refreshFont(const QFont &font)
{
	QTextCharFormat textCharFormat = this->currentCharFormat();
	textCharFormat.setFont(font);
	QTextCursor textCursor = this->textCursor();
	textCursor.select(QTextCursor::Document);
	textCursor.setCharFormat(textCharFormat);
}

void TextEdit::scrollContentsBy(int dx, int dy)
{
	//if (mainWindow->lineNumbersAreEnabled())
	//qDebug() << "Scroll to " << dx << " and " << dy;
	QTextEdit::scrollContentsBy(dx, dy);
}

void TextEdit::contextMenuEvent(QContextMenuEvent *event)
{
	if (selectedMenu == 0)
	{
		lineMenu = new QMenu(tr("Zeile"), this);
		connect(lineMenu->addAction(tr("Kommentar")), SIGNAL(triggered()), this, SLOT(commentFormat()));
		connect(lineMenu->addAction(tr("Dokumentationskommentar")), SIGNAL(triggered()), this, SLOT(docCommentFormat()));
		connect(lineMenu->addAction(tr("Präprozessor")), SIGNAL(triggered()), this, SLOT(preprocessorFormat()));
	
		selectedMenu = new QMenu(tr("Ausgewählter Text"), this);
		connect(selectedMenu->addAction(tr("Zeichenkette")), SIGNAL(triggered()), this, SLOT(stringFormat()));
		connect(selectedMenu->addAction(tr("Zeichen")), SIGNAL(triggered()), this, SLOT(charFormat()));
		connect(selectedMenu->addAction(tr("Klammern")), SIGNAL(triggered()), this, SLOT(bracketsFormat()));
		connect(selectedMenu->addAction(tr("Eckige Klammern")), SIGNAL(triggered()), this, SLOT(squaredBracketsFormat()));
		connect(selectedMenu->addAction(tr("Nichts")), SIGNAL(triggered()), this, SLOT(nothingFormat()));
		
		insertColorAction = new QAction(tr("Farbe einfügen"), this);
		connect(insertColorAction, SIGNAL(triggered()), m_textView->mainWindow()->insertColorAction, SLOT(trigger()));
	}

	selectedMenu->setEnabled(textCursor().hasSelection());

	//QTextEdit::contextMenuEvent(event);
	QMenu *contextMenu = createStandardContextMenu();
	contextMenu->addSeparator();
	contextMenu->addMenu(lineMenu);
	contextMenu->addMenu(selectedMenu);
	contextMenu->addAction(insertColorAction);
	contextMenu->exec(event->globalPos());
	delete contextMenu;
}

void TextEdit::keyPressEvent(QKeyEvent *event)
{
	if (event->text().isEmpty()) /// @todo Should be empty when user presses Ctrl + C or Ctrl + Z etc.
	{
		qDebug() << "Empty!";
		QTextEdit::keyPressEvent(event);
		return;
	}
	else
		qDebug() << "NOT EMPTY: " << event->text();
	
	if (!textCursor().hasSelection())
	{
		QTextEdit::keyPressEvent(event);
		return;
	}
	
	if (event->text() == "\"")
		encloseByCharacters('"', '"');
	else if (event->text() == "'")
		encloseByCharacters('\'', '\'');
	else if (event->text() == "(" || event->text() == ")")
		encloseByCharacters('(', ')');
	else if (event->text() == "[" || event->text() == "]")
		encloseByCharacters('[', ']');
	else
		QTextEdit::keyPressEvent(event);
}

void TextEdit::commentFormat()
{
	QTextCursor textCursor = this->textCursor();
	textCursor.clearSelection();
	textCursor.movePosition(QTextCursor::StartOfLine, QTextCursor::MoveAnchor);
	textCursor.insertText("//");
}

void TextEdit::docCommentFormat()
{
	QTextCursor textCursor = this->textCursor();
	textCursor.clearSelection();
	textCursor.movePosition(QTextCursor::StartOfLine, QTextCursor::MoveAnchor);
	textCursor.insertText("///");
}

void TextEdit::preprocessorFormat()
{
	QTextCursor textCursor = this->textCursor();
	textCursor.clearSelection();
	textCursor.movePosition(QTextCursor::StartOfLine, QTextCursor::MoveAnchor);
	textCursor.insertText("//!");
}

void TextEdit::stringFormat()
{
	encloseByCharacters('"', '"');
}

void TextEdit::charFormat()
{
	encloseByCharacters('\'', '\'');
}

void TextEdit::bracketsFormat()
{
	encloseByCharacters('(', ')');
}

void TextEdit::squaredBracketsFormat()
{
	encloseByCharacters('[', ']');
}

void TextEdit::nothingFormat()
{
}

void TextEdit::setUndoAvailable(bool available)
{
	m_canUndo = available;
}

void TextEdit::setRedoAvailable(bool available)
{
	m_canRedo = available;
}

void TextEdit::setCopyAvailable(bool available)
{
	m_canCopy = available;
}

void TextEdit::encloseByCharacters(QChar first, QChar second)
{
	QTextCursor textCursor = this->textCursor();
	QTextCursor::MoveOperation moveOperation0;
	QTextCursor::MoveOperation moveOperation1;
	QString firstString;
	QString secondString;
	int firstLength = textCursor.selectedText().length();
	int secondLength = textCursor.selectedText().length() + 2;
	bool moveOneStep;
	
	if (textCursor.position() >= textCursor.selectionEnd())
	{
		moveOperation0 = QTextCursor::Left;
		moveOperation1 = QTextCursor::Right;
		firstString = second;
		secondString = first;
		++firstLength;
		moveOneStep = true;
	}
	else
	{
		moveOperation0 = QTextCursor::Right;
		moveOperation1 = QTextCursor::Left;
		firstString = first;
		secondString = second;
		moveOneStep = false;
	}
	
	textCursor.clearSelection();
	textCursor.insertText(firstString);
	textCursor.movePosition(moveOperation0, QTextCursor::MoveAnchor, firstLength);
	textCursor.insertText(secondString);
	
	if (moveOneStep)
		textCursor.movePosition(moveOperation0, QTextCursor::MoveAnchor, 1);
	
	textCursor.movePosition(moveOperation1, QTextCursor::KeepAnchor, secondLength);
	setTextCursor(textCursor);
}

}
