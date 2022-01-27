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

#ifndef VJASSIDE_TEXTTOKEN_H
#define VJASSIDE_TEXTTOKEN_H

#include <QString>
#include <QColor>
#include <QTextCharFormat>

namespace vjasside
{

class TextToken
{
	public:
		TextToken(const QString& string, const QColor& color, QTextCharFormat *textCharFormat);
		QString string() const;
		QFont font() const;
		QColor color() const;

	private:
		const QString m_string;
		const QColor m_color;
		const QTextCharFormat *m_textCharFormat;
};

}

#endif
