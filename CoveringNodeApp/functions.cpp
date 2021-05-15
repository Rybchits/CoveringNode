#include "functions.h"

QDomDocument readFromXmlFile(QString xmlFilePath){

    QDomDocument domDoc;

    // Открыть файл по указанному пути
    QFile* file = new QFile(xmlFilePath);

    // Если удалось открыть xml файл
    if (file->open(QIODevice::ReadOnly))
    {
        // Если возникает ошибка синтаксического анализа
        if (!domDoc.setContent(file)){

            // Вызвать исключение с соответствующим сообщением
            throw CustomException("Xml file contains syntax errors");
        }
        // Закрыть файл
        file->close();
    }

    // Иначе, если не удалось открыть xml файл
    else
    {
        // Вызвать исключение с соответствующим сообщением
        throw CustomException("Failed to read .xml file");
    }

    // Вернуть документ с древовидной структурой
    return domDoc;
}
