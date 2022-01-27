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

#ifndef VJASSIDE_TEXTEDIT_H
#define VJASSIDE_TEXTEDIT_H

#include <QTextEdit>
#include <QMenu>

namespace vjasside
{

class TextView;

class TextEdit : public QTextEdit
{
	Q_OBJECT

	public:
		TextEdit(QWidget *parent);
		virtual ~TextEdit();
		void setTextView(TextView *textView);
		bool canUndo() const;
		bool canRedo() const;
		bool canCopy() const;
		
		void openFile(const QString &filePath);
		void refreshFont(const QFont &font);
	
	protected:
		virtual void scrollContentsBy(int dx, int dy);
		virtual void contextMenuEvent(QContextMenuEvent *event);
		virtual void keyPressEvent(QKeyEvent *event);
	
	private slots:
		void commentFormat();
		void docCommentFormat();
		void preprocessorFormat();
		void stringFormat();
		void charFormat();
		void bracketsFormat();
		void squaredBracketsFormat();
		void nothingFormat();
		
		void setUndoAvailable(bool available);
		void setRedoAvailable(bool available);
		void setCopyAvailable(bool available);
	
	private:
		void encloseByCharacters(QChar first, QChar second);
		
		TextView *m_textView;
		QMenu *lineMenu;
		QMenu *selectedMenu;
		QAction *insertColorAction;
		
		bool m_canUndo;
		bool m_canRedo;
		bool m_canCopy;
};

inline void TextEdit::setTextView(TextView *textView)
{
	m_textView = textView;
}

inline bool TextEdit::canUndo() const
{
	return m_canUndo;
}

inline bool TextEdit::canRedo() const
{
	return m_canRedo;
}

inline bool TextEdit::canCopy() const
{
	return m_canCopy;
}

}

#endif
