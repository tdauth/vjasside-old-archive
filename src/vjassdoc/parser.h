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

#ifndef VJASSDOC_PARSER_H
#define VJASSDOC_PARSER_H

#include <functional>
#include <list>
#include <string>
#include <sstream>
#include <vector>

namespace vjassdoc
{

class Object;
class Comment;
class Keyword;
class TextMacro;
class TextMacroInstance;
class Type;
class Global;
class Member;
class FunctionInterface;
class Function;
class Method;
class Interface;
class Struct;
class Scope;
class Library;
class SourceFile;
class DocComment;

/**
* Provides methods for parsing Jass and vJass files. The Parser class has the ability to create a simple HTML
* API documentation and/or a SQLite3 database.
* It contains a list for each Object child class.
*/
class Parser
{
	public:
		struct Comparator : public std::binary_function<const class Object*, const class Object*, bool>
		{
			virtual bool operator()(const class Object *thisObject, const class Object *otherObject) const;
		};
	
		enum List
		{
			Comments,
			Keywords,
			TextMacros,
			TextMacroInstances,
			Types,
			Globals,
			Members,
			FunctionInterfaces,
			Functions,
			Methods,
			Interfaces,
			Structs,
			Scopes,
			Libraries,
			SourceFiles,
			DocComments,
			MaxLists
		};
		
		enum SearchMode
		{
			Unspecified = 0, /// No specific search mode.
			CheckContainer = 0x02, /// Container has to be the same.
			CheckScope = 0x04,
			CheckLibrary = 0x06
		};

		Parser();
		~Parser();
		void parse();
		int addDatabase(const char *filePath);
		void removeDatabase(const int &index);
		void add(class Comment *comment);
		void add(class Keyword *keyword);
		void add(class TextMacro *textMacro);
		void add(class TextMacroInstance *textMacroInstance);
		void add(class Type *type);
		void add(class Global *global);
		void add(class Member *member);
		void add(class FunctionInterface *functionInterface);
		void add(class Function *function);
		void add(class Method *method);
		void add(class Interface *interface);
		void add(class Struct *usedStruct);
		void add(class Scope *scope);
		void add(class Library *library);
		void add(class SourceFile *sourceFile);
		void add(class DocComment *docComment);

		/**
		* Searchs for an object with the identifier @param identifier in the list @param list by the seach mode @param searchMode. If the search mode is unequal to @enum SearchMode::Unspecified the three members container, scope and library will be compared with the instance @param object.
		*/
		class Object* searchObjectInList(const class Object *object, const std::string &identifier, const enum Parser::List &list, const enum Parser::SearchMode &searchMode);
		
		std::list<class Object*> getSpecificList(const class Object *object, const enum List &list, const struct Comparator &comparator);
		
		/// Finds the nearest object in the same line or ABOVE the line.
		//Object* searchObjectByLine(const Object *object, List list);
		
		class Type* integerType() const;
		class Type* realType() const;
		class Type* stringType() const;
		class Type* booleanType() const;
		class Type* handleType() const;
		class Type* codeType() const;
		class SourceFile* currentSourceFile() const;

	private:
		struct Database
		{
			std::list<enum List> listList;
			std::list<class Object*> objectList;
		};
	
		static const char *title[Parser::MaxLists];
		static const unsigned short int columns[Parser::MaxLists];
		static const char *tableName[Parser::MaxLists];
	
		std::list<class Object*>& getList(const enum List &list);
		
		//HTML
		std::stringstream& addObjectList(std::stringstream &output, const enum Parser::List &list);
		
		//SQLite
		std::string getTableCreationStatement(const enum Parser::List &list);
		class Object* addObjectByColumnVector(const enum Parser::List &list, std::vector<const unsigned char*> &columnVector);
		
		class Type *m_integerType;
		class Type *m_realType;
		class Type *m_stringType;
		class Type *m_booleanType;
		class Type *m_handleType;
		class Type *m_codeType;
		std::list<class Comment*> commentList;
		std::list<class Keyword*> keywordList;
		std::list<class TextMacro*> textMacroList;
		std::list<class TextMacroInstance*> textMacroInstanceList;
		std::list<class Type*> typeList;
		std::list<class Global*> globalList;
		std::list<class Member*> memberList;
		std::list<class FunctionInterface*> functionInterfaceList;
		std::list<class Function*> functionList;
		std::list<class Method*> methodList;
		std::list<class Interface*> interfaceList;
		std::list<class Struct*> structList;
		std::list<class Scope*> scopeList;
		std::list<class Library*> libraryList;
		std::list<class SourceFile*> sourceFileList;
		std::list<class DocComment*> docCommentList;
		class SourceFile *m_currentSourceFile;
		std::vector<struct Database*> databaseVector;
};

}

#endif
