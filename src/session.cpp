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

#include <QSettings>

#include "session.h"

namespace vjasside
{

Session::Session(const QString &name) : m_name(name)
{
}

void Session::writeIntoSettings()
{
	QSettings settings;
	settings.beginGroup("session" + m_name);
	//settings.setValue("name", m_name);
	settings.beginWriteArray("files");
	int i = 0;
	
	for (QStringList::const_iterator iterator = m_files.begin(); iterator != m_files.end(); ++iterator)
	{
		settings.setArrayIndex(i);
		settings.setValue("path", *iterator);
		++i;
	}
	
	settings.endArray();
	settings.endGroup();
}

void Session::readFromSettings()
{
	QSettings settings;
	settings.beginGroup("session" + m_name);
	//m_name = settings.value("name").toString();
	int size = settings.beginReadArray("files");
	
	for (int i = 0; i < size; ++i)
	{
		settings.setArrayIndex(i);
		m_files.push_back(settings.value("path").toString());
	}
	
	settings.endArray();
	settings.endGroup();
}

void Session::removeFromSettings()
{
	QSettings settings;
	settings.beginGroup("session" + m_name);
	settings.remove("");
	settings.endGroup();
}

}
