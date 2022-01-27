/***************************************************************************
 *   Copyright (C) 2008 by Tamino Dauth                                    *
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

#ifndef VJASSDOC_SOURCEFILE_H
#define VJASSDOC_SOURCEFILE_H

#include "object.h"

namespace vjassdoc
{

class SourceFile : public Object
{
	public:
		SourceFile(const std::string &identifier, const std::string &path);
		SourceFile(std::vector<const unsigned char*> &columnVector);
		virtual void init();
		virtual void pageNavigation(std::ofstream &file) const;
		virtual void page(std::ofstream &file) const;
		virtual std::string sqlStatement() const;
		std::string path() const;
		std::string lineLink(const unsigned int &line, const std::string &text) const;
		
		/**
		* @param sourceFileName If this value is true, the name of source file will be shown as link. Otherwise the line will be shown.
		*/
		static std::string sourceFileLineLink(const class Object *object, const bool &sourceFileName = true, const std::string &identifier = "-");

	private:
		//Do not use
		class SourceFile* sourceFile() const;
		unsigned int line() const;
		class DocComment* docComment() const;

		std::string m_path;
};

}

#endif
