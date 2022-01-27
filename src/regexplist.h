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

#ifndef VJASSIDE_REGEXPLIST_H
#define VJASSIDE_REGEXPLIST_H

#include <QList>
#include <QRegExp>

#include "syntaxschema.h"

namespace vjassdoc
{

class Object;

}

namespace vjasside
{

class SyntaxHighlighter;

class RegExpList
{
	public:
		class Entry
		{
			public:
				enum Behaviour
				{
					None,
					OpenBlock,
					CloseBlock,
					InfoObject,
					AutoObject
				};
		
				Entry();
				Entry(const QString &regularyExpression, const QString &expression = QString(), Behaviour behaviour = None, vjassdoc::Object *object = 0);
				QRegExp regExp() const;
				int length() const;
				Behaviour behaviour() const;
				vjassdoc::Object* object() const;
				
				void writeIntoSettings(QSettings &settings);
				void readFromSettings(QSettings &settings);
		
			private:
				QRegExp m_regExp;
				int m_length;
				Behaviour m_behaviour;
				vjassdoc::Object *m_object;
			
		};
	
		static int addApiDatabase(const QString &filePath);
		static void removeApiDatabase(const int &index);
		
		RegExpList();
		RegExpList(QList<Entry> entries, SyntaxSchema::Format format);
		void addEntries(QList<Entry> entries);
		void removeEntries(int start, const int &length);
		QList<Entry> entries() const;
		SyntaxSchema::Format format() const;
		int minimumRequiredSpace() const;
		
		void find(const QString &text, int start, int &freeSpace, SyntaxHighlighter *syntaxHighlighter);
		
		void writeIntoSettings(QSettings &settings);
		void readFromSettings(QSettings &settings);
	
	private:
		QList<Entry> m_entries;
		SyntaxSchema::Format m_format;
		int m_minimumRequiredSpace;
};

inline QRegExp RegExpList::Entry::regExp() const
{
	return m_regExp;
}

inline int RegExpList::Entry::length() const
{
	return m_length;
}

inline RegExpList::Entry::Behaviour RegExpList::Entry::behaviour() const
{
	return m_behaviour;
}

inline vjassdoc::Object* RegExpList::Entry::object() const
{
	return m_object;
}

inline void RegExpList::addEntries(QList<Entry> entries)
{
	m_entries << entries;
}

inline void RegExpList::removeEntries(int start, const int &length)
{
#ifndef QT_NO_DEBUG_OUTPUT
	if (start >= m_entries.size() || start + length > m_entries.size())
	{
		qDebug() << "removeEntries() error: Wrong start or length value.\nstart = " << start << "\nlength = " << length;
		return;
	}
#endif

	int exitValue = start + length;
	
	while (start < exitValue)
	{
		m_entries.removeAt(start);
		++start;
	}
}

inline QList<RegExpList::Entry> RegExpList::entries() const
{
	return m_entries;
}

inline SyntaxSchema::Format RegExpList::format() const
{
	return m_format;
}

inline int RegExpList::minimumRequiredSpace() const
{
	return m_minimumRequiredSpace;
}

}

#endif
