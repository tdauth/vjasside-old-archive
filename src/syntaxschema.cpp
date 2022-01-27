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

#include <QtCore>

#include "syntaxschema.h"
#include "regexplist.h"

namespace vjasside
{

SyntaxSchema* SyntaxSchema::createStandardSchema(const QString &name)
{
	static const char *integerTemplate = "(^|[-\\s+=,(*\\\\])(\\d+)($|[-\\s+,)*\\\\])";
	static const char *realTemplate = "(^|[-\\s+=,(*\\\\])(\\d+\\.\\d+)($|[-\\s+,)*\\\\])";
	static const char *characterTemplate = "(^|[\\s=(,])('[^']*')($|[\\s),])";
	static const char *stringTemplate = "(^|\\W)(\"[^\"]*\")($|\\W)";
	static const char *commentTemplate = "()(//.*)($)";
	static const char *operatorTemplate = "(^|[\\s\\d.])(%1)($|[\\d\\s])";
	static const char *keywordTemplate = "(^|[\\s])%1($|[\\s])";
	static const char *valueKeywordTemplate = "(^|[\\s=(,])%1($|[\\s),])";
	static const char *preprocessorTemplate = "()(//!.*)($)";
	static const char *preprocessorKeywordTemplate = "(^|[\\s]//!)%1($|[\\s])";
	static const char *preprocessorArgumentTemplate = "(^|[\\s])$*$($|[\\s])";
	static const char *docCommentTemplate = "(^|[\\s\\d\\w])///*($)";
	static const char *docCommentKeywordTemplate = "(^|[\\s]///)%1($|[\\s])";
	static const char *docCommentWordTemplate = "(^|[\\s]///[\\s]@\\w)\\w($|[\\s])"; /// @todo FIXME
	
	SyntaxSchema *syntaxSchema = new SyntaxSchema(name);
	
	for (int i = 0; i < SyntaxSchema::MaxFormats; ++i)
		syntaxSchema->setFormat(SyntaxSchema::Format(i), false, false, false, false, Qt::black, Qt::white);

	syntaxSchema->setRegularyExpressionTemplate(QObject::tr("Ganzzahlen-Vorlage"), integerTemplate);
	syntaxSchema->setRegularyExpressionTemplate(QObject::tr("Fließkommazahlen-Vorlage"), realTemplate);
	syntaxSchema->setRegularyExpressionTemplate(QObject::tr("Zeichen-Vorlage"), characterTemplate);
	syntaxSchema->setRegularyExpressionTemplate(QObject::tr("Zeichenketten-Vorlage"), stringTemplate);
	syntaxSchema->setRegularyExpressionTemplate(QObject::tr("Kommentar-Vorlage"), commentTemplate);
	syntaxSchema->setRegularyExpressionTemplate(QObject::tr("Operatoren-Vorlage"), operatorTemplate);
	syntaxSchema->setRegularyExpressionTemplate(QObject::tr("Schlüsselwörter-Vorlage"), keywordTemplate);
	syntaxSchema->setRegularyExpressionTemplate(QObject::tr("Schlüsselwörterwerte-Vorlage"), valueKeywordTemplate);
	syntaxSchema->setRegularyExpressionTemplate(QObject::tr("Präprozessoren-Vorlage"), preprocessorTemplate);
	syntaxSchema->setRegularyExpressionTemplate(QObject::tr("Präprozessorschlüsselwörter-Vorlage"), preprocessorKeywordTemplate);
	syntaxSchema->setRegularyExpressionTemplate(QObject::tr("Präprozessorenargument-Vorlage"), preprocessorArgumentTemplate);
	syntaxSchema->setRegularyExpressionTemplate(QObject::tr("Dokumentationskommentar-Vorlage"), docCommentTemplate);
	syntaxSchema->setRegularyExpressionTemplate(QObject::tr("Dokumentationskommentarschlüsselwörter-Vorlage"), docCommentKeywordTemplate);
	syntaxSchema->setRegularyExpressionTemplate(QObject::tr("Dokumentationskommentarwort-Vorlage"), docCommentWordTemplate);
	
	syntaxSchema->setRegularyExpressionList(SyntaxSchema::Integer,
	RegExpList(QList<RegExpList::Entry>()
	<<
		RegExpList::Entry(
		integerTemplate
		)
	, SyntaxSchema::Integer));
	syntaxSchema->setFormatForegroundColor(SyntaxSchema::Integer, Qt::yellow);
	
	syntaxSchema->setRegularyExpressionList(SyntaxSchema::Real,
	RegExpList(QList<RegExpList::Entry>()
	<<
		RegExpList::Entry(
		realTemplate
		)
	, SyntaxSchema::Real));
	syntaxSchema->setFormatForegroundColor(SyntaxSchema::Real, Qt::red);

	syntaxSchema->setRegularyExpressionList(SyntaxSchema::Character,
	RegExpList(QList<RegExpList::Entry>()
	<<
		RegExpList::Entry(
		characterTemplate
		)
	, SyntaxSchema::Character));
	syntaxSchema->setFormatForegroundColor(SyntaxSchema::Character, Qt::magenta);
	
	syntaxSchema->setRegularyExpressionList(SyntaxSchema::String,
	RegExpList(QList<RegExpList::Entry>()
	<<
		RegExpList::Entry(
		stringTemplate
		)
	, SyntaxSchema::String));
	syntaxSchema->setFormatForegroundColor(SyntaxSchema::String, Qt::blue);
	
	syntaxSchema->setRegularyExpressionList(SyntaxSchema::Comment,
	RegExpList(QList<RegExpList::Entry>()
	<<
		RegExpList::Entry(
		commentTemplate
		)
	, SyntaxSchema::Comment));
	syntaxSchema->setFormatItalic(SyntaxSchema::Comment, true);
	syntaxSchema->setFormatForegroundColor(SyntaxSchema::Comment, Qt::green);

	syntaxSchema->setRegularyExpressionList(SyntaxSchema::Operator,
	RegExpList(QList<RegExpList::Entry>()
	<<
		RegExpList::Entry(
		operatorTemplate,
		"\\+"
		)
	<<
		RegExpList::Entry(
		operatorTemplate,
		"\\-"
		)
	<<
		RegExpList::Entry(
		operatorTemplate,
		"\\*"
		)
	<<
		RegExpList::Entry(
		operatorTemplate,
		"\\/"
		)
	, SyntaxSchema::Operator));
	syntaxSchema->setFormatForegroundColor(SyntaxSchema::Operator, Qt::gray);
	
	syntaxSchema->setRegularyExpressionList(SyntaxSchema::Keyword,
	RegExpList(QList<RegExpList::Entry>()
	<<
		RegExpList::Entry(
		keywordTemplate,
		"type"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"extends"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"native"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"nothing"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"constant"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"function",
		RegExpList::Entry::OpenBlock
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"takes"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"returns"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"return"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"endfunction",
		RegExpList::Entry::CloseBlock
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"local"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"globals",
		RegExpList::Entry::OpenBlock
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"endglobals",
		RegExpList::Entry::CloseBlock
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"if",
		RegExpList::Entry::OpenBlock
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"then"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"else"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"elseif"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"endif",
		RegExpList::Entry::CloseBlock
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"or"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"and"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"not"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"loop",
		RegExpList::Entry::OpenBlock
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"endloop",
		RegExpList::Entry::CloseBlock
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"exitwhen"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"set"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"call"
		)
	<<
		RegExpList::Entry(
		valueKeywordTemplate,
		"null"
		)
	<<
		RegExpList::Entry(
		valueKeywordTemplate,
		"true"
		)
	<<
		RegExpList::Entry(
		valueKeywordTemplate,
		"false"
		)
	, SyntaxSchema::Keyword));
	syntaxSchema->setFormatBold(SyntaxSchema::Keyword, true);
	syntaxSchema->setFormatForegroundColor(SyntaxSchema::Keyword, Qt::black);

	syntaxSchema->setRegularyExpressionList(SyntaxSchema::VjassKeyword,
	RegExpList(QList<RegExpList::Entry>()
	<<
		RegExpList::Entry(
		keywordTemplate,
		"operator"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"library",
		RegExpList::Entry::OpenBlock
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"library_once",
		RegExpList::Entry::OpenBlock
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"endlibrary",
		RegExpList::Entry::CloseBlock
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"requires"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"needs"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"uses"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"initializer"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"scope",
		RegExpList::Entry::OpenBlock
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"endscope",
		RegExpList::Entry::CloseBlock
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"interface",
		RegExpList::Entry::OpenBlock
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"endinterface",
		RegExpList::Entry::CloseBlock
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"defaults"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"struct",
		RegExpList::Entry::OpenBlock
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"endstruct",
		RegExpList::Entry::OpenBlock
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"method",
		RegExpList::Entry::OpenBlock
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"endmethod",
		RegExpList::Entry::CloseBlock
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"private"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"public"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"static"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"this"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"debug"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"keyword"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"delegate"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"stub"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"super"
		)
	<<
		RegExpList::Entry(
		keywordTemplate, /// @todo Use another template.
		"SCOPE_PREFIX"
		)
	<<
		RegExpList::Entry(
		keywordTemplate, /// @todo Use another template.
		"SCOPE_PRIVATE"
		)
	<<
		RegExpList::Entry(
		keywordTemplate, /// @todo Use another template for the create method call.
		"create"
		)
	<<
		RegExpList::Entry(
		keywordTemplate, /// @todo Use another template.
		"destroy"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"onInit"
		)
	<<
		RegExpList::Entry(
		keywordTemplate,
		"onDestroy"
		)
	<<
		RegExpList::Entry(
		keywordTemplate, /// @todo Use another template.
		"evaluate"
		)
	<<
		RegExpList::Entry(
		keywordTemplate, /// @todo Use another template.
		"execute"
		)
	<<
		RegExpList::Entry(
		keywordTemplate, /// @todo Use another template.
		"getType"
		)
	<<
		RegExpList::Entry(
		keywordTemplate, /// @todo Use another template.
		"typeid"
		)
	<<
		RegExpList::Entry(
		keywordTemplate, /// @todo Use another template.
		"size"
		)
	<<
		RegExpList::Entry(
		keywordTemplate, /// @todo Use another template.
		"allocate"
		)
	<<
		RegExpList::Entry(
		keywordTemplate, /// @todo Use another template.
		"exists"
		)
	, SyntaxSchema::VjassKeyword));
	syntaxSchema->setFormatBold(SyntaxSchema::VjassKeyword, true);
	syntaxSchema->setFormatForegroundColor(SyntaxSchema::VjassKeyword, Qt::black);
	
	syntaxSchema->setRegularyExpressionList(SyntaxSchema::Integer,
	RegExpList(QList<RegExpList::Entry>()
	<<
		RegExpList::Entry(
		preprocessorTemplate
		)
	, SyntaxSchema::Preprocessor));
	syntaxSchema->setFormatItalic(SyntaxSchema::Preprocessor, true);
	syntaxSchema->setFormatForegroundColor(SyntaxSchema::Preprocessor, Qt::gray);

	syntaxSchema->setRegularyExpressionList(SyntaxSchema::PreprocessorKeyword,
	RegExpList(QList<RegExpList::Entry>()
	<<
		RegExpList::Entry(
		preprocessorKeywordTemplate,
		"textmacro",
		RegExpList::Entry::OpenBlock
		)
	<<
		RegExpList::Entry(
		preprocessorKeywordTemplate,
		"takes"
		)
	<<
		RegExpList::Entry(
		preprocessorKeywordTemplate,
		"endtextmacro",
		RegExpList::Entry::CloseBlock
		)
	<<
		RegExpList::Entry(
		preprocessorKeywordTemplate,
		"runtextmacro"
		)
	<<
		RegExpList::Entry(
		preprocessorKeywordTemplate,
		"import"
		)
	<<
		RegExpList::Entry(
		preprocessorKeywordTemplate,
		"inject",
		RegExpList::Entry::OpenBlock
		)
	<<
		RegExpList::Entry(
		preprocessorKeywordTemplate,
		"endinject",
		RegExpList::Entry::CloseBlock
		)
	<<
		RegExpList::Entry(
		preprocessorKeywordTemplate,
		"dovjassinit"
		)
	, SyntaxSchema::PreprocessorKeyword));
	syntaxSchema->setFormatBold(SyntaxSchema::PreprocessorKeyword, true);
	syntaxSchema->setFormatForegroundColor(SyntaxSchema::PreprocessorKeyword, Qt::darkGray);
	
	syntaxSchema->setRegularyExpressionList(SyntaxSchema::PreprocessorArgument,
	RegExpList(QList<RegExpList::Entry>()
	<<
		RegExpList::Entry(
		preprocessorArgumentTemplate
		)
	, SyntaxSchema::PreprocessorArgument));
	syntaxSchema->setFormatBold(SyntaxSchema::PreprocessorArgument, true);
	syntaxSchema->setFormatForegroundColor(SyntaxSchema::PreprocessorArgument, QColor(255, 106, 0));
	
	syntaxSchema->setRegularyExpressionList(SyntaxSchema::DocComment,
	RegExpList(QList<RegExpList::Entry>()
	<<
		RegExpList::Entry(
		docCommentTemplate
		)
	, SyntaxSchema::DocComment));
	syntaxSchema->setFormatItalic(SyntaxSchema::DocComment, true);
	syntaxSchema->setFormatForegroundColor(SyntaxSchema::DocComment, Qt::blue);
	
	syntaxSchema->setRegularyExpressionList(SyntaxSchema::DocCommentKeyword,
	RegExpList(QList<RegExpList::Entry>()
	<<
		RegExpList::Entry(
		docCommentKeywordTemplate,
		"@author"
		)
	<<
		RegExpList::Entry(
		docCommentKeywordTemplate,
		"@todo"
		)
	<<
		RegExpList::Entry(
		docCommentKeywordTemplate,
		"@param"
		)
	<<
		RegExpList::Entry(
		docCommentKeywordTemplate,
		"@return"
		)
	<<
		RegExpList::Entry(
		docCommentKeywordTemplate,
		"@state"
		)
	<<
		RegExpList::Entry(
		docCommentKeywordTemplate,
		"@source"
		)
	, SyntaxSchema::DocCommentKeyword));
	syntaxSchema->setFormatBold(SyntaxSchema::DocCommentKeyword, true);
	syntaxSchema->setFormatForegroundColor(SyntaxSchema::DocCommentKeyword, Qt::magenta);
	
	syntaxSchema->setRegularyExpressionList(SyntaxSchema::DocCommentWord,
	RegExpList(QList<RegExpList::Entry>()
	<<
		RegExpList::Entry(
		docCommentWordTemplate
		)
	, SyntaxSchema::DocCommentWord));
	syntaxSchema->setFormatBold(SyntaxSchema::DocCommentWord, true);
	syntaxSchema->setFormatForegroundColor(SyntaxSchema::DocCommentWord, Qt::cyan);
	
	return syntaxSchema;
}

QString SyntaxSchema::getNameByXmlFile(const QString &filePath)
{
	QFile file(filePath);
	
	if (!file.exists())
		return QString();
	
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QXmlStreamReader streamReader(&file);
	streamReader.readNext();
	
	if (!streamReader.isStartDocument())
		return QString();
	
	streamReader.readNext();
	
	if (!streamReader.isStartElement() || streamReader.qualifiedName() != "name")
		return QString();
	
	return streamReader.text().toString();
}

SyntaxSchema::SyntaxSchema(const QString &name) : m_name(name)
{
/*
	for (int i = 0; i < MaxExpressions; ++i)
		m_format[i] = new QTextCharFormat;
*/
}

SyntaxSchema::~SyntaxSchema()
{
/*
	for (int i = 0; i < MaxExpressions; ++i)
		delete m_format[i];
*/
}

/* inline */ void SyntaxSchema::setName(const QString &name)
{
	m_name = name;
}

/* inline */ QString SyntaxSchema::name() const
{
	return m_name;
}

/* inline */ QMap<QString, QString> SyntaxSchema::regularyExpressionTemplates() const
{
	return m_regularyExpressionTemplates;
}

/* inline */ void SyntaxSchema::setRegularyExpressionTemplate(const QString &name, const QString &templateString)
{
	m_regularyExpressionTemplates[name] = templateString;
}

/* inline */ QString SyntaxSchema::regularyExpressionTemplate(const QString &name) const
{
	return m_regularyExpressionTemplates[name];
}

/* inline */ bool SyntaxSchema::regularyExpressionTemplateExists(const QString &name) const
{
	return m_regularyExpressionTemplates.contains(name);
}

/* inline */ void SyntaxSchema::setRegularyExpressionList(Format format, RegExpList regExpList)
{
	if (format >= m_regularyExpressionLists.size())
		m_regularyExpressionLists.resize(format + 1);

	m_regularyExpressionLists[format] = regExpList;
}

/* inline */ class RegExpList SyntaxSchema::regularyExpressionList(Format format) const
{
	return m_regularyExpressionLists[format];
}

/* inline */ int SyntaxSchema::regularyExpressionLists() const
{
	return m_regularyExpressionLists.size();
}

void SyntaxSchema::writeIntoSettings()
{
	QSettings settings;
	settings.beginGroup("syntaxSchema" + name());
	settings.beginWriteArray("formats");
	
	for (int i = 0; i < MaxFormats; ++i)
	{
		settings.setArrayIndex(i);
		settings.setValue("bold", formatBold(SyntaxSchema::Format(i)));
		settings.setValue("italic", formatItalic(SyntaxSchema::Format(i)));
		settings.setValue("underline", formatUnderline(SyntaxSchema::Format(i)));
		settings.setValue("strikeOut", formatStrikeOut(SyntaxSchema::Format(i)));
		settings.setValue("foregroundRed", formatForegroundColor(SyntaxSchema::Format(i)).red());
		settings.setValue("foregroundGreen", formatForegroundColor(SyntaxSchema::Format(i)).green());
		settings.setValue("foregroundBlue", formatForegroundColor(SyntaxSchema::Format(i)).blue());
		settings.setValue("foregroundAlpha", formatForegroundColor(SyntaxSchema::Format(i)).alpha());
		settings.setValue("backgroundRed", formatBackgroundColor(SyntaxSchema::Format(i)).red());
		settings.setValue("backgroundGreen", formatBackgroundColor(SyntaxSchema::Format(i)).green());
		settings.setValue("backgroundBlue", formatBackgroundColor(SyntaxSchema::Format(i)).blue());
		settings.setValue("backgroundAlpha", formatBackgroundColor(SyntaxSchema::Format(i)).alpha());
	}
	
	settings.endArray();
	settings.beginWriteArray("regularyExpressionTemplates");
	QMap<QString, QString>::const_iterator iterator;
	int i = 0;

	for (iterator = regularyExpressionTemplates().constBegin(); iterator != regularyExpressionTemplates().constEnd(); ++iterator)
	{
		settings.setArrayIndex(i);
		settings.setValue("key", iterator.key());
		settings.setValue("value", iterator.value());
		++i;
	}
	
	settings.endArray();
	settings.beginWriteArray("regularyExpressionLists");
	
	for (i = 0; i < regularyExpressionLists(); ++i)
	{
		settings.setArrayIndex(i);
		this->m_regularyExpressionLists[i].writeIntoSettings(settings);
	}
	
	settings.endArray();
	settings.endGroup();
}

void SyntaxSchema::readFromSettings()
{
	QSettings settings;
	settings.beginGroup("syntaxSchema" + name());
	settings.beginReadArray("formats");
	
	for (int i = 0; i < MaxFormats; ++i)
	{
		settings.setArrayIndex(i);
		
		QColor foregroundColor, backgroundColor;
		foregroundColor.setRed(settings.value("foregroundRed", 0).toInt());
		foregroundColor.setGreen(settings.value("foregroundGreen", 0).toInt());
		foregroundColor.setBlue(settings.value("foregroundBlue", 0).toInt());
		foregroundColor.setAlpha(settings.value("foregroundAlpha", 255).toInt());
		backgroundColor.setRed(settings.value("backgroundRed", 255).toInt());
		backgroundColor.setGreen(settings.value("backgroundGreen", 255).toInt());
		backgroundColor.setBlue(settings.value("backgroundBlue", 255).toInt());
		backgroundColor.setAlpha(settings.value("backgroundAlpha", 255).toInt());
		
		setFormat(Format(i), settings.value("bold", false).toBool(), settings.value("italic", false).toBool(), settings.value("underline", false).toBool(), settings.value("strikeOut", false).toBool(), foregroundColor, backgroundColor);
	}
	
	settings.endArray();
	int size = settings.beginReadArray("regularyExpressionTemplates");

	for (int i = 0; i < size; ++i)
	{
		settings.setArrayIndex(i);
		m_regularyExpressionTemplates[settings.value("key").toString()] = settings.value("value").toString();
	}
	
	settings.endArray();
	size = settings.beginReadArray("regularyExpressionLists");
	
	for (int i = 0; i < size; ++i)
	{
		settings.setArrayIndex(i);
		class RegExpList regExpList;
		regExpList.readFromSettings(settings);
		setRegularyExpressionList(regExpList.format(), regExpList);
	}
	
	settings.endArray();
	settings.endGroup();
}

void SyntaxSchema::exportIntoXmlFile(const QString &filePath) throw (SyntaxSchemaException)
{
	QFile file(filePath);
	file.open(QIODevice::WriteOnly | QIODevice::Text);
	
	if (file.error() != QFile::NoError)
	{
		QString message;
	
		switch (file.error())
		{
			case QFile::ReadError:
				message = QObject::tr("Lesefehler");
				break;
			
			case QFile::WriteError:
				message = QObject::tr("Schreibfehler");
				break;
			
			case QFile::FatalError:
				message = QObject::tr("Schwerer Fehler");
				break;
			
			case QFile::ResourceError:
				message = QObject::tr("Ressourcenfehler");
				break;
			
			/// @todo Insert missing cases.
			
			case QFile::PermissionsError:
				message = QObject::tr("Zugriffsfehler");
		}
		
		throw SyntaxSchemaException(message + QObject::tr(".<br>Fehlernummer: %2.").arg(file.error()));
	}
	
	QXmlStreamWriter streamWriter(&file);
	streamWriter.writeStartDocument();
	streamWriter.writeTextElement("name", name());
	
	for (int i = 0; i < MaxFormats; ++i)
	{
		streamWriter.writeStartElement(QString("format%1").arg(i));
		streamWriter.writeStartElement("font");
		streamWriter.writeTextElement("bold", QString("%1").arg(this->formatBold(SyntaxSchema::Format(i))));
		streamWriter.writeTextElement("italic", QString("%1").arg(this->formatItalic(SyntaxSchema::Format(i))));
		streamWriter.writeTextElement("underline", QString("%1").arg(this->formatUnderline(SyntaxSchema::Format(i))));
		streamWriter.writeTextElement("strikeOut", QString("%1").arg(this->formatStrikeOut(SyntaxSchema::Format(i))));
		streamWriter.writeEndElement();
		streamWriter.writeStartElement("foreground");
		streamWriter.writeTextElement("red", QString("%1").arg(this->formatForegroundColor(SyntaxSchema::Format(i)).red()));
		streamWriter.writeTextElement("green", QString("%1").arg(this->formatForegroundColor(SyntaxSchema::Format(i)).green()));
		streamWriter.writeTextElement("blue", QString("%1").arg(this->formatForegroundColor(SyntaxSchema::Format(i)).blue()));
		streamWriter.writeTextElement("alpha", QString("%1").arg(this->formatForegroundColor(SyntaxSchema::Format(i)).alpha()));
		streamWriter.writeEndElement();
		streamWriter.writeStartElement("background");
		streamWriter.writeTextElement("red", QString("%1").arg(this->formatBackgroundColor(SyntaxSchema::Format(i)).red()));
		streamWriter.writeTextElement("green", QString("%1").arg(this->formatBackgroundColor(SyntaxSchema::Format(i)).green()));
		streamWriter.writeTextElement("blue", QString("%1").arg(this->formatBackgroundColor(SyntaxSchema::Format(i)).blue()));
		streamWriter.writeTextElement("alpha", QString("%1").arg(this->formatForegroundColor(SyntaxSchema::Format(i)).alpha()));
		streamWriter.writeEndElement();
		streamWriter.writeEndElement();
	}
	
	streamWriter.writeEndDocument();
}

void SyntaxSchema::importFromXmlFile(const QString &filePath) throw (SyntaxSchemaException)
{
	QFile file(filePath);
	
	if (file.error() != QFile::NoError)
		throw SyntaxSchemaException(QObject::tr("Fehler beim Öffnen der Datei \"%1\".<br>Fehlernummer: %2.").arg(filePath).arg(file.error()));
	
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	QXmlStreamReader streamReader(&file);
	streamReader.readNext();
	
	if (!streamReader.isStartDocument())
		throw SyntaxSchemaException(QObject::tr("Fehler beim Lesen der Datei \"%1\".<br>Dokumentanfang fehlt.").arg(filePath));
	
	streamReader.readNext();
	
	if (!streamReader.isStartElement() || streamReader.qualifiedName() != "name")
		throw SyntaxSchemaException(QObject::tr("Fehler beim Lesen der Datei \"%1\".<br>Element \"name\" fehlt.").arg(filePath));
	
	m_name = streamReader.text().toString();
	
	for (int i = 0; i < MaxFormats; ++i)
	{
		streamReader.readNext();
	
		if (!streamReader.isStartElement() || streamReader.qualifiedName() != QString("format%1").arg(i))
			throw SyntaxSchemaException(QObject::tr("Fehler beim Lesen der Datei \"%1\".<br>Element \"format%1\" fehlt.").arg(filePath).arg(i));
	
		streamReader.readNext();
		
		if (streamReader.qualifiedName() != "font")
			throw SyntaxSchemaException(QObject::tr("Fehler beim Lesen der Datei \"%1\".<br>Element \"font\" fehlt.").arg(filePath));

		this->setFormatBold(SyntaxSchema::Format(i), streamReader.readElementText().toInt());
		this->setFormatItalic(SyntaxSchema::Format(i), streamReader.readElementText().toInt());
		this->setFormatUnderline(SyntaxSchema::Format(i), streamReader.readElementText().toInt());
		this->setFormatStrikeOut(SyntaxSchema::Format(i), streamReader.readElementText().toInt());
		
		streamReader.readNext();
		streamReader.readNext();
		
		if (streamReader.qualifiedName() != "foreground")
			throw SyntaxSchemaException(QObject::tr("Fehler beim Lesen der Datei \"%1\".<br>Element \"foreground\" fehlt.").arg(filePath));
		
		QColor foreground;
		foreground.setRed(streamReader.readElementText().toInt());
		foreground.setGreen(streamReader.readElementText().toInt());
		foreground.setBlue(streamReader.readElementText().toInt());
		foreground.setAlpha(streamReader.readElementText().toInt());
		this->setFormatForegroundColor(SyntaxSchema::Format(i), foreground);
		
		streamReader.readNext();
		
		if (streamReader.qualifiedName() != "background")
			throw SyntaxSchemaException(QObject::tr("Fehler beim Lesen der Datei \"%1\".<br>Element \"background\" fehlt.").arg(filePath));
		
		QColor background;
		background.setRed(streamReader.readElementText().toInt());
		background.setGreen(streamReader.readElementText().toInt());
		background.setBlue(streamReader.readElementText().toInt());
		background.setAlpha(streamReader.readElementText().toInt());
		this->setFormatForegroundColor(SyntaxSchema::Format(i), background);
		streamReader.readNext();
		streamReader.readNext();
	}
	
	streamReader.readNext();
}

}
