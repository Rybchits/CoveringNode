#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QFile>
#include <QTextStream>
#include <QtXml/QDomDocument>
#include "CustomException.h"
#include "TreeNode.h"

/*! Считать данные из файла формата txt
  \param[in] QString txtFilePath - путь к исходному файлу формата .txt
  \return массив строк текущего файла
*/
QStringList readFromTextFile(QString txtFilePath);

/*! Считать данные из xml файла
   \param[in] QString xmlFilePath - путь к исходному файлу формата .xml
   \return объект класса QDomDocument, представляющий весь XML-документ
*/
QDomDocument readFromXmlFile(QString xmlFilePath);

/*! Записать данные в файл формата .txt
   \param[in] QString txtFilePath - путь к исходному файлу формата .txt
   \param[in] QStringList listStrings - список строк данных
   \return успешность записи
*/
bool wtiteToTextFile(QString txtFilePath, QStringList listStrings);

/*! Получить первый узел документа, являющийся ElementNode
   \param[in] QDomDocument xmlDoc - документ с древовидной структурой
   \return первый узел документа, являющийся ElementNode
*/
QDomNode getFirstElementNode(const QDomDocument xmlDoc);

/*! Конвертировать QDomDocument в структуру дерева
   \param[in] QDomDocument xmlDoc - документ с древовидной структурой
   \return корневой узел дерева
*/
TreeNode convertDomDocumentToTreeNode(const QDomDocument xmlDoc);

#endif // FUNCTIONS_H
