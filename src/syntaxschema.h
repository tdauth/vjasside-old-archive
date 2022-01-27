/***************************************************************************
 *   Copyright (C) 2008, 2009 by Tamino Dauth                              *
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

#ifndef VJASSIDE_SYNTAXSCHEMA_H
#define VJASSIDE_SYNTAXSCHEMA_H

#include <QTextCharFormat>
#include <QSettings>
#include <QMap>
#include <QVector>

#include "syntaxschemaexception.h"

namespace vjasside
{

class RegExpList;

class SyntaxSchema
{
	public:
		enum Format
		{
			Text,
			Integer,
			Real,
			Character,
			String,
			Comment,
			Operator,
			Keyword,
			VjassKeyword,
			Preprocessor,
			PreprocessorKeyword,
			PreprocessorArgument,
			DocComment,
			DocCommentKeyword, //@author, @todo, @param, @return
			DocCommentWord, //@param ThisExpression

			MaxFormats
		};
		
		static class SyntaxSchema* createStandardSchema(const QString &name);
		static QString getNameByXmlFile(const QString &filePath);

		SyntaxSchema(const QString &name);
		~SyntaxSchema();
		void setName(const QString &name);
		QString name() const;
		
		void setFormat(Format format, bool bold, bool italic, bool underline, bool strikeOut, QColor foregroundColor, QColor backgroundColor);
		void setFormatBold(Format format, bool bold);
		bool formatBold(Format format) const;
		void setFormatItalic(Format format, bool italic);
		bool formatItalic(Format format) const;
		void setFormatUnderline(Format format, bool underline);
		bool formatUnderline(Format format) const;
		void setFormatStrikeOut(Format format, bool strikeOut);
		bool formatStrikeOut(Format format) const;
		void setFormatForegroundColor(Format format, QColor foregroundColor);
		QColor formatForegroundColor(Format format) const;
		void setFormatBackgroundColor(Format format, QColor backgroundColor);
		QColor formatBackgroundColor(Format format) const;
		
		QMap<QString, QString> regularyExpressionTemplates() const;
		void setRegularyExpressionTemplate(const QString &name, const QString &templateString);
		QString regularyExpressionTemplate(const QString &name) const;
		bool regularyExpressionTemplateExists(const QString &name) const;
		void setRegularyExpressionList(Format format, RegExpList regExpList);
		class RegExpList regularyExpressionList(Format format) const;
		int regularyExpressionLists() const;
		
		void writeIntoSettings();
		void readFromSettings();
		
		void exportIntoXmlFile(const QString &filePath) throw (SyntaxSchemaException);
		void importFromXmlFile(const QString &filePath) throw (SyntaxSchemaException);
	//public slots:
		//void setFormat(Expression expression, QTextCharFormat *format);

	private:
		QString m_name;
		bool m_formatBold[MaxFormats];
		bool m_formatItalic[MaxFormats];
		bool m_formatUnderline[MaxFormats];
		bool m_formatStrikeOut[MaxFormats];
		QColor m_formatForegroundColor[MaxFormats];
		QColor m_formatBackgroundColor[MaxFormats];
		QMap<QString, QString> m_regularyExpressionTemplates;
		QVector<RegExpList> m_regularyExpressionLists;
};

inline void SyntaxSchema::setFormat(Format format, bool bold, bool italic, bool underline, bool strikeOut, QColor foregroundColor, QColor backgroundColor)
{
	m_formatBold[format] = bold;
	m_formatItalic[format] = italic;
	m_formatUnderline[format] = underline;
	m_formatStrikeOut[format] = strikeOut;
	m_formatForegroundColor[format] = foregroundColor;
	m_formatBackgroundColor[format] = backgroundColor;
}

inline void SyntaxSchema::setFormatBold(Format format, bool bold)
{
	this->m_formatBold[format] = bold;
}

inline bool SyntaxSchema::formatBold(Format format) const
{
	return m_formatBold[format];
}

inline void SyntaxSchema::setFormatItalic(Format format, bool italic)
{
	this->m_formatItalic[format] = italic;
}

inline bool SyntaxSchema::formatItalic(Format format) const
{
	return m_formatItalic[format];
}

inline void SyntaxSchema::setFormatUnderline(Format format, bool underline)
{
	this->m_formatUnderline[format] = underline;
}

inline bool SyntaxSchema::formatUnderline(Format format) const
{
	return m_formatUnderline[format];
}

inline void SyntaxSchema::setFormatStrikeOut(Format format, bool strikeOut)
{
	this->m_formatStrikeOut[format] = strikeOut;
}

inline bool SyntaxSchema::formatStrikeOut(Format format) const
{
	return m_formatStrikeOut[format];
}

inline void SyntaxSchema::setFormatForegroundColor(Format format, QColor foregroundColor)
{
	this->m_formatForegroundColor[format] = foregroundColor;
}

inline QColor SyntaxSchema::formatForegroundColor(Format format) const
{
	return m_formatForegroundColor[format];
}

inline void SyntaxSchema::setFormatBackgroundColor(Format format, QColor backgroundColor)
{
	this->m_formatBackgroundColor[format] = backgroundColor;
}

inline QColor SyntaxSchema::formatBackgroundColor(Format format) const
{
	return m_formatBackgroundColor[format];
}

}

#endif
