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

#ifndef VJASSDOC_OBJECT_H
#define VJASSDOC_OBJECT_H

#include <string>
#include <vector>
#include <fstream>
#include <functional>

#include "parser.h"

namespace vjassdoc
{

class SourceFile;
class DocComment;
class Scope;
class Library;
class Type;

class Object
{
	public:
		static std::string objectPageLink(const class Object *object, const std::string &identifier = "-");
		static std::string objectLink(const class Object *object, const std::string &identifier = "-"); //should use the id
		static int objectId(const class Object *object);
		
		static void setMaxIds(int maxIds); //only used by loading objects from database
		static std::string sqlFilteredString(const std::string &usedString);
	
		Object(const std::string &identifier, class SourceFile *sourceFile, unsigned int line, class DocComment *docComment);
		Object(std::vector<const unsigned char*> &columnVector);
		virtual ~Object();

		virtual void init() = 0; //Some Objects has to be initialized after finding all objects of all files.
		virtual void pageNavigation(std::ofstream &file) const = 0;
		virtual void page(std::ofstream &file) const = 0;
		std::string pageLink() const;
		virtual std::string sqlStatement() const;
		unsigned int id() const;
		void addIdentifier(const std::string &identifier); //required by doc comments
		std::string identifier() const;
		class SourceFile* sourceFile() const;
		unsigned int line() const;
		class DocComment* docComment() const;
		
		//empty condition methods, used by the search algorithm's comparison
		virtual class Object* container() const;
		virtual class Scope* scope() const;
		virtual class Library* library() const;
		
		struct AlphabeticalComparator : public std::binary_function<const class Object*, const class Object*, bool>
		{
			bool operator()(const class Object *first, const class Object *second) const;
		};
		
		struct IsInContainer : public Parser::Comparator
		{
			virtual bool operator()(const class Object *thisObject, const class Object *library) const;
		};
		
		struct IsInScope : public Parser::Comparator
		{
			virtual bool operator()(const class Object *thisObject, const class Object *library) const;
		};
		
		struct IsInLibrary : public Parser::Comparator
		{
			virtual bool operator()(const class Object *thisObject, const class Object *library) const;
		};

	protected:
		static bool hasToSearchValueObject(const class Type *type, const std::string &expression);
		static std::string showBooleanProperty(const bool &property);
	
		std::string anchor() const;
		class Object* searchObjectInList(const std::string &identifier, const enum Parser::List &list, enum Parser::SearchMode searchMode = Parser::Unspecified);
		/**
		* Checks if @param valueExpression is a literal or an object. If it's an object (like a global or function call) it will be searched in parser lists.
		*/
		class Object* findValue(const class Object *type, std::string &valueExpression);
		
		class Object *m_container;
		class Scope *m_scope;
		class Library *m_library;

	private:
		//static std::string getAnotherLink(const Object *object);
		static int maxIds;

		//Object(Object&);

		unsigned int m_id;
		/* std::string */std::string m_identifier;
		class SourceFile *m_sourceFile;
		unsigned int m_line;
		class DocComment *m_docComment;
};

}

#endif
