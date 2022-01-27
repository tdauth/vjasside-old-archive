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

#include <QtCore>

#include "regexplist.h"
#include "vjassdoc/object.h"
#include "syntaxhighlighter.h"
#include "mainwindow.h"

namespace vjasside
{

RegExpList::Entry::Entry()
{
}

RegExpList::Entry::Entry(const QString &regularyExpression, const QString &expression, Behaviour behaviour, vjassdoc::Object *object) : m_behaviour(behaviour), m_object(object)
{
	if (expression.isEmpty())
	{
		m_regExp = QRegExp(regularyExpression);
		m_length = 1;
	}
	else
	{
		m_regExp = QRegExp(regularyExpression.arg(expression));
		m_length = expression.length(); // TODO Isn't correct everytime (\*)
	}

}

void RegExpList::Entry::writeIntoSettings(QSettings &settings)
{
	settings.setValue("pattern", this->regExp().pattern());
	settings.setValue("length", this->length());
	settings.setValue("behaviour", this->behaviour());
	//settings.setValue("objectId", this->object == 0 ? -1 : this->object->id());
}

void RegExpList::Entry::readFromSettings(QSettings &settings)
{
	m_regExp.setPattern(settings.value("pattern").toString());
	m_length = settings.value("length").toInt();
	m_behaviour = Behaviour(settings.value("behaviour").toInt());
	//m_object = settings.value("objectId").toInt();
}

int RegExpList::addApiDatabase(const QString &filePath)
{
	//return vjassdoc::Vjassdoc::getParser()->addDatabase(filePath.toAscii());
	//parser.loadDatabase(filePath.toAscii());
	return -1;
}

void RegExpList::removeApiDatabase(const int &index)
{
	//vjassdoc::Vjassdoc::getParser()->removeDatabase(index);
	//parser.removeDatabase(index);
}

RegExpList::RegExpList() : m_entries(QList<Entry>()), m_format(SyntaxSchema::Text), m_minimumRequiredSpace(1)
{
}

RegExpList::RegExpList(QList<Entry> entries, SyntaxSchema::Format format) : m_entries(entries), m_format(format)
{
	if (!entries.isEmpty())
	{
		int length = 999999; // TODO set maximum value which can be hold by an integer value.
		Entry iterator;
	
		foreach (iterator, entries)
		{
			if (iterator.length() < length)
				length = iterator.length();
		}
		
		m_minimumRequiredSpace = length;
	}
	else
		m_minimumRequiredSpace = 1;
}

void RegExpList::find(const QString &text, int start, int &freeSpace, SyntaxHighlighter *syntaxHighlighter)
{
	if (freeSpace < minimumRequiredSpace() || start >= text.length())
		return;

	Entry iterator;
	
	foreach (iterator, entries())
	{
		if (iterator.length() > freeSpace)
			continue;
	
		int localStart = 0;
		QRegExp regExp = iterator.regExp();
		
		for (int position = regExp.indexIn(text, start); position != -1; position = regExp.indexIn(text, start + localStart))
		{
			QString capturedText = regExp.capturedTexts()[0];
			position += text.mid(position).indexOf(capturedText);
			localStart = position + capturedText.length();
			freeSpace -= capturedText.length();
			syntaxHighlighter->setFormat(position, capturedText.length(), format());
			syntaxHighlighter->setLineProperties(iterator.behaviour() == Entry::OpenBlock, iterator.behaviour() == Entry::CloseBlock);
			
			if (iterator.behaviour() == Entry::InfoObject)
			{
				if (iterator.object() != 0)
					syntaxHighlighter->mainWindow()->showObjectInfo(iterator.object());

			}

			if (minimumRequiredSpace() > freeSpace || start + localStart >= text.length())
				break;
		}
	}
}

void RegExpList::writeIntoSettings(QSettings &settings)
{
	settings.beginWriteArray("entries");
	int i = 0;
	class Entry iterator;

	foreach (iterator, entries())
	{
		settings.setArrayIndex(i);
		iterator.writeIntoSettings(settings);
		++i;
	}
	
	settings.endArray();
	settings.setValue("format", this->format());
	settings.setValue("minimumRequiredSpace", this->minimumRequiredSpace());
}

void RegExpList::readFromSettings(QSettings &settings)
{
	int size = settings.beginReadArray("entries");

	for (int i = 0; i < size; ++i)
	{
		settings.setArrayIndex(i);
		class Entry entry = Entry();
		entry.readFromSettings(settings);
		m_entries << entry;
	}
	
	settings.endArray();
	m_format = SyntaxSchema::Format(settings.value("format").toInt());
	m_minimumRequiredSpace = settings.value("minimumRequiredSpace").toInt();
}

}
