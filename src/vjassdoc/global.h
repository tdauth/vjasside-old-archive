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

#ifndef VJASSDOC_GLOBAL_H
#define VJASSDOC_GLOBAL_H

#include "object.h"

namespace vjassdoc
{

class Global : public Object
{
	public:

		class Size
		{
			public:
				Size(unsigned int size);
				Size(class Object *size);
				unsigned int toUint() const; ///* inline */
				class Object* toObject() const; ///* inline */

			private:
				unsigned int literalSize;
				class Object *objectSize;
		};

		Global(const std::string &identifier, class SourceFile *sourceFile, unsigned int line, class DocComment *docComment, class Library *library, class Scope *scope, bool isPublic, bool isConstant, const std::string &typeExpression, const std::string &valueExpression, const std::string &sizeExpression);
		Global(std::vector<const unsigned char*> &columnVector);
		virtual void init();
		virtual void pageNavigation(std::ofstream &file) const;
		virtual void page(std::ofstream &file) const;
		virtual std::string sqlStatement() const;
		virtual class Library* library() const;
		virtual class Scope* scope() const;
		bool isPublic() const;
		bool isConstant() const;
		class Object* type() const; //Type, Interface, Struct
		class Object* value() const; //Global, Member (static), Function, Method (static)
		std::string valueLiteral() const; //Literal
		class Object* size() const; //Global (constant), Member (static, constant), Function (constant), Method (static, constant)
		int sizeLiteral() const;

	private:
		std::string typeExpression;
		std::string valueExpression;
		std::string sizeExpression;

		class Library *m_library;
		class Scope *m_scope;
		bool m_isPublic;
		bool m_isConstant;
		class Object *m_type;
		class Object *m_value;
		class Object *m_size;
};

}

#endif
