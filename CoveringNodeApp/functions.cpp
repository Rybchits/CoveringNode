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


QStringList readFromTextFile(QString txtFilePath){

    QStringList listLinesFile;      // Список строк файла
    QFile file(txtFilePath);        // Файл

    // Если файл удалось открыть
    if (file.open(QIODevice::ReadOnly))
    {
       QTextStream in(&file);       // Текстовый поток

       // Пока не конец файла
       while (!in.atEnd())
           // Добавить строку в список
           listLinesFile << in.readLine();

       // Закрыть файл
       file.close();
    }
    // Если файл не был открыт
    else {
        // Вызвать исключение
        throw CustomException("Failed to read .txt file");
    }

    // Вернуть список строк
    return listLinesFile;
}

