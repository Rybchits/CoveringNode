#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QFile>
#include <QTextStream>
#include <QtXml/QDomDocument>
#include "CustomException.h"

/*  Считать данные из файла формата txt
  * QString txtFilePath - путь к исходному файлу формата .txt
  * return массив строк текущего файла
*/
QStringList readFromTextFile(QString txtFilePath);

/*  Считать данные из xml файла
  * QString xmlFilePath - путь к исходному файлу формата .xml
  * return объект класса QDomDocument, представляющий весь XML-документ
*/
QDomDocument readFromXmlFile(QString xmlFilePath);

/*  Найти узел с искомым id
  * QDomDocument domDoc - представление XML-документа в виде дерева
  * QString idSearchNode - id искомого узла
  * return объект класса QDomNode - искомый узел
*/
QDomNode findNodeById(QDomDocument domDoc, QString idSearchNode);

/* Найти все Id дочерних узлов заданного родительского узла
 * QDomNode parentNode - родительский узел
 * return список id дочерних узлов
*/
QStringList getIdsChildNodes(QDomNode parentNode);

/* Найти список элементов в originalList, которые не были указаны в anotherList
 * QString txtFilePath - проверяемый список
 * QStringList anotherList - список в котором ищем id
 * return список не указанных элементов
*/
QStringList findMissingElements(QStringList originalList, QStringList anotherList);

/* Записать данные в файл формата .txt
 * QString txtFilePath - путь к исходному файлу формата .txt
 * QStringList listStrings - список строк данных
 * return успешность записи
*/
bool wtiteToTextFile(QString txtFilePath, QStringList listStrings);


#endif // FUNCTIONS_H
