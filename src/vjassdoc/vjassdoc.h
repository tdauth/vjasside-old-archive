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

#ifndef VJASSDOC_VJASSDOC_H
#define VJASSDOC_VJASSDOC_H

#include <string>
#include <list>

#include "parser.h"

namespace vjassdoc
{

class Parser;

class Vjassdoc
{
	public:
		static const char *version;
		static const char *dirSeparator;

		static void run(bool jass, bool debug, bool html, bool pages, bool specialPages, bool database, bool verbose, bool time, bool alphabetical, bool parseObjectsOfList[Parser::MaxLists], const std::string &title, const std::string &dir, std::list<std::string> *importDirs, std::list<std::string> *filePaths);
		static class Parser* getParser();
		static bool jassOnly();
		static bool useDebugMode();
		static bool saveAsHtml();
		static bool createPages();
		static bool createSpecialPages();
		static bool createDatabase();
		static bool showVerbose();
		static bool sortAlphabetically();
		static bool shouldParseObjectsOfList(const enum Parser::List &list);
		static std::string getTitle();
		static std::string getDir();
		static std::list<std::string>* getImportDirs();
		static std::list<std::string>* getFilePaths();
		
		static void addLines(const unsigned int &addedLines);
		static void addFile();
		static unsigned int getFiles();
	private:
		Vjassdoc();
		Vjassdoc(Vjassdoc&);
		~Vjassdoc();

		static class Parser *parser;
		static bool jass;
		static bool debug;
		static bool html;
		static bool pages;
		static bool specialPages;
		static bool database;
		static bool verbose;
		static bool time;
		static bool alphabetical;
		static bool parseObjectsOfList[Parser::MaxLists];
		static std::string title;
		static std::string dir;
		static std::list<std::string> *importDirs;
		static std::list<std::string> *filePaths;
		
		static unsigned int lines;
		static unsigned int files;
};

}

#endif
