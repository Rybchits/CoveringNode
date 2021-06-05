#include "functions.h"

QDomDocument readFromXmlFile(QString xmlFilePath)
{

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


QStringList readFromTextFile(QString txtFilePath)
{

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


TreeNode convertDomDocumentToTreeNode(QDomDocument xmlDoc)
{
    TreeNode rootNode;

    // Получить первый узел документа, являющийся ElementNode
    QDomNode firstElementNode = getFirstElementNode(xmlDoc);

    // Если первый узел документа, являющийся ElementNode найден
    if (!firstElementNode.isNull()){

        // Преобразуем текущий узел в класс элемента
        QDomElement element = firstElementNode.toElement();

        // Если есть атрибут типа id
        if (element.hasAttribute("id"))
            // Запустить конструктор объекта TreeNode из узла древовидной структуры
            rootNode = TreeNode(firstElementNode);

        // Иначе
        else
            // Вызвать исключение
            throw CustomException("Root Node hasn't Id");
    }

    // Вернуть корневой узел
    return rootNode;
}


QDomNode getFirstElementNode(QDomDocument xmlDoc)
{
    QDomNode firstNodeElement;

    // Получить все дочерние узлы DocumentNode
    QDomNodeList childsCurrentNode = xmlDoc.childNodes();

    // Для каждого дочернего узла DocumentNode
    for (int i = 0; i < childsCurrentNode.length(); i++){

        // Если тип текущего узла является ElementNode, вернуть его
        if (childsCurrentNode.item(i).nodeType() == QDomNode::ElementNode)
            return childsCurrentNode.item(i);
    }

    return firstNodeElement;
}


bool wtiteToTextFile(QString txtFilePath, QStringList listStrings)
{
    QFile file(txtFilePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);

    if (listStrings.empty())
        out << "The set covers the current node" << endl;
    else
        out << "The set don't covers the current node" << endl << "Missing Nodes: " << endl;

    foreach(QString line, listStrings)
    {
         out << line << endl;
    }

    return true;
}
