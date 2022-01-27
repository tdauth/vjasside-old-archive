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

#ifndef VJASSIDE_SESSION_H
#define VJASSIDE_SESSION_H

#include <QString>
#include <QStringList>

namespace vjasside
{

class Session
{
	public:
		Session(const QString &name);
		void rename(const QString &name);
		void addFile(const QString &path);
		void removeFile(const int &index);
		void clearFiles();
		QString name() const;
		void setFiles(const QStringList &files);
		QStringList files() const;
		int size() const;
		void writeIntoSettings();
		void readFromSettings();
		void removeFromSettings();

	private:
		QString m_name;
		QStringList m_files;
};

inline void Session::rename(const QString &name)
{
	QSettings settings;
	settings.beginGroup("session" + m_name);
	settings.remove("");
	settings.endGroup();

	m_name = name;
}

inline void Session::addFile(const QString &path)
{
	m_files << path;
}

inline void Session::removeFile(const int &index)
{
	m_files.removeAt(index);
}

inline void Session::clearFiles()
{
	m_files.clear();
}

inline QString Session::name() const
{
	return m_name;
}

inline void Session::setFiles(const QStringList &files)
{
	m_files = files;
}

inline QStringList Session::files() const
{
	return m_files;
}

inline int Session::size() const
{
	return m_files.size();
}

}

#endif
