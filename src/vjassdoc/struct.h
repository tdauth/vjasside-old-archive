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

#ifndef VJASSDOC_STRUCT_H
#define VJASSDOC_STRUCT_H

#include "interface.h"

namespace vjassdoc
{

class Struct : public Interface
{
	public:
		struct HasExtension : public Parser::Comparator
		{
			virtual bool operator()(const class Object *thisObject, const class Object *extension) const;
		};
	
		Struct(const std::string &identifier, class SourceFile *sourceFile, unsigned int line, class DocComment *docComment, class Library *library, Scope *scope, const std::string &extensionExpression);
		Struct(std::vector<const unsigned char*> &columnVector);
		virtual void init();
		virtual void pageNavigation(std::ofstream &file) const;
		virtual void page(std::ofstream &file) const;
		virtual std::string sqlStatement() const;
		class Interface* extension() const;
		class Method* constructor() const;
		class Method* destructor() const;
		class Method *initializer() const;
		
	private:
		std::string extensionExpression;

		class Interface *m_extension; //Interface, Struct
		class Method *m_constructor;
		class Method *m_destructor;
		class Method *m_initializer;
};

}

#endif
