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

#ifndef VJASSDOC_LIBRARY_H
#define VJASSDOC_LIBRARY_H

#include "object.h"

namespace vjassdoc
{

class Library : public Object
{
	public:
		Library(const std::string &identifier, class SourceFile *sourceFile, unsigned int line, class DocComment *docComment, bool isOnce, const std::string &initializerExpression, std::list<std::string> *requirementExpressions);
		Library(std::vector<const unsigned char*> &columnVector);
		virtual ~Library();
		virtual void init();
		virtual void pageNavigation(std::ofstream &file) const;
		virtual void page(std::ofstream &file) const;
		virtual std::string sqlStatement() const;
		bool isOnce() const;
		class Function* initializer() const; //Function, Method (static)
		std::list<class Library*>* requirement() const;
	
	private:
		bool m_isOnce;
		std::string initializerExpression;
		std::list<std::string> *requirementExpressions;

		class Function *m_initializer; //Function is the parent class of Method, so it can be a method, too.
		std::list<class Library*> *m_requirement;
};

}

#endif
