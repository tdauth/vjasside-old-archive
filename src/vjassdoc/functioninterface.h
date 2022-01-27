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

#ifndef VJASSDOC_FUNCTIONINTERFACE_H
#define VJASSDOC_FUNCTIONINTERFACE_H

#include "object.h"

namespace vjassdoc
{

class FunctionInterface : public Object
{
	public:
		FunctionInterface(const std::string &identifier, class SourceFile *sourceFile, unsigned int line, class DocComment *docComment, class Library *library, class Scope *scope, std::list<std::string> *parameterTypeExpressions, std::list<std::string> *parameters, const std::string &returnTypeExpression);
		FunctionInterface(std::vector<const unsigned char*> &columnVector);
		virtual ~FunctionInterface();
		virtual void init();
		virtual void pageNavigation(std::ofstream &file) const;
		virtual void page(std::ofstream &file) const;
		virtual std::string sqlStatement() const;
		virtual class Library* library() const;
		virtual class Scope* scope() const;
		std::list<class Object*>* parameterTypes() const; //Type, Function Interface, Interface, Struct
		std::list<std::string>* parameterTypeExpressions() const;
		std::list<std::string>* parameters() const;
		class Object* returnType() const; //Type, Function Interface, Interface, Struct
		std::string returnTypeExpression() const;

	private:
		class Library *m_library;
		class Scope *m_scope;
		std::list<Object*> *m_parameterTypes;
		std::list<std::string> *m_parameterTypeExpressions;
		std::list<std::string> *m_parameters;
		class Object *m_returnType;
		std::string m_returnTypeExpression;
};

}

#endif
