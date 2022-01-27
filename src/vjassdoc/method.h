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

#ifndef VJASSDOC_METHOD_H
#define VJASSDOC_METHOD_H

#include "function.h"

namespace vjassdoc
{

class Method : public Function
{
	public:
		/// isNative always is false.
		Method(const std::string &identifier, class SourceFile *sourceFile, unsigned int line, class DocComment *docComment, class Library *library, class Scope *scope, std::list<std::string> *parameterTypeExpressions, std::list<std::string> *parameters, const std::string &returnTypeExpression, bool isConstant, Object *container, bool isStatic, bool isStub, const std::string &defaultReturnValueExpression);
		Method(std::vector<const unsigned char*> &columnVector);
		virtual void init();
		virtual void pageNavigation(std::ofstream &file) const;
		virtual void page(std::ofstream &file) const;
		virtual std::string sqlStatement() const;
		virtual class Object* container() const; //Interface, Struct
		bool isStatic() const;
		bool isStub() const;
		class Object* defaultReturnValue() const; //Type, Function Interface, Interface, Struct, Literal
		std::string defaultReturnValueExpression() const;

	private:
		bool isNative() const; //do not use

		class Object *m_container;
		bool m_isStatic;
		bool m_isStub;
		class Object *m_defaultReturnValue;
		std::string m_defaultReturnValueExpression;
};

}

#endif
