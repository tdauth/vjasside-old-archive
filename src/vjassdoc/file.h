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

#ifndef VJASSDOC_FILE_H
#define VJASSDOC_FILE_H

#include <list>
#include <string>
#include <fstream>

namespace vjassdoc
{

class Parser;
class SourceFile;
class DocComment;
class Library;
class Scope;
class Interface;
class Struct;

class File
{
	public:
		enum Expression
		{
			DocCommentExpression, //This tool
			CommentExpression,
			TypeExpression,
			ConstantExpression,
			ExtendsExpression,
			NativeExpression,
			NothingExpression,
			FunctionExpression,
			EndfunctionExpression,
			TakesExpression,
			ReturnsExpression,
			GlobalsExpression,
			EndglobalsExpression,
			PreprocessorExpression,
			ImportExpression,
			DovjassinitExpression,
			InjectExpression,
			EndinjectExpression,
			NovjassExpression,
			EndnovjassExpression,
			LoaddataExpression,
			ExternalExpression,
			TextmacroExpression,
			EndtextmacroExpression,
			RuntextmacroExpression, //An instance of the macro
			RequiresExpression,
			NeedsExpression,
			UsesExpression,
			InitializerExpression,
			DefaultsExpression,
			MethodExpression, //Operator is not required because the syntax is "method operator..."
			EndmethodExpression, //Required for function blocks, there can not be custom types
			PrivateExpression,
			PublicExpression,
			StaticExpression,
			DebugExpression,
			KeywordExpression,
			LibraryExpression,
			Library_onceExpression,
			EndlibraryExpression,
			ScopeExpression,
			EndscopeExpression,
			StructExpression,
			EndstructExpression,
			InterfaceExpression,
			EndinterfaceExpression,
			DelegateExpression, //new
			StubExpression, //new
			ArrayExpression, //could not be the first expression in line (Not required in Jass code)
			MaxExpressions
		};

		enum DocExpression
		{
			Author,
			ToDo,
			Parameter,
			Return,
			State,
			Source,
			MaxDocExpressions
		};
		
		static const char *expressionText[File::MaxExpressions];
		static const char *docExpressionText[File::MaxDocExpressions];
		
		File(const std::string &filePath);
		
	private:
		/// @return Returns true if a documentation comment was found.
		void truncateComments(std::string &line, unsigned int index);
		void getDocComment(const std::string &line, unsigned int index);
		void clearDocComment();
		bool getGlobal(const std::string &line, unsigned int &index, bool isPublic, bool isConstant, bool isStatic, bool isDelegate);
		bool getFunction(const std::string  &line, unsigned int &index, bool isPublic, bool isConstant, bool isNative, bool isStatic, bool isStub);
		void getLibrary(const std::string &line, unsigned int &index, bool isOnce);
		std::string removeFirstSpace(const std::string &line, unsigned int index) const;
		std::string getToken(const std::string &line, unsigned int &index, bool endOfLine = false) const;
		std::string getTextMacroArguments(const std::string &line, unsigned int &index) const;
		std::list<std::string>* getLibraryRequirement(const std::string &line, unsigned int &index) const;
		bool isInVjassBlock() const;

		const std::string filePath;

		Expression notRequiredSpace;
		bool isInGlobals;
		bool isInLibrary;
		bool isInScope;
		bool isInInterface;
		bool isInStruct;

		unsigned int currentLine;
		DocComment *currentDocComment;
		Library *currentLibrary;
		Scope *currentScope;
		Interface *currentInterface;
		Struct *currentStruct;

		bool gotDocComment;

		std::ifstream fin;
};

}

#endif
