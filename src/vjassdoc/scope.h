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

#ifndef VJASSDOC_SCOPE_H
#define VJASSDOC_SCOPE_H

#include "object.h"

namespace vjassdoc
{

class Scope : public Object
{
	public:
		Scope(const std::string &identifier, class SourceFile *sourceFile, unsigned int line, class DocComment *docComment, class Library *library, const std::string initializerExpression);
		Scope(std::vector<const unsigned char*> &columnVector);
		virtual void init();
		virtual void pageNavigation(std::ofstream &file) const;
		virtual void page(std::ofstream &file) const;
		virtual std::string sqlStatement() const;
		virtual class Library* library() const;
		virtual class Function* initializer() const; //Function, Method (static)

	private:
		std::string initializerExpression;

		class Library *m_library;
		class Function *m_initializer; //Function is the parent class of Method, so it can be a method, too.
};

}

#endif
