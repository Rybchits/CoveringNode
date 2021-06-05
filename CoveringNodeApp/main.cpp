#include <QCoreApplication>
#include <functions.h>


int main(int argc, char *argv[])
{

#ifdef TESTING_MODE
    runTests(argc, argv);
#else
    //Основное поведение программы

    QCoreApplication a(argc, argv);
    QTextStream cout(stdout);

    try {

        // Если число аргументов соответствует ожидаемому
        if (argc == 3)
        {
            // Получаем дерево в виде xml файла
            QDomDocument domXml = readFromXmlFile(QString(argv[0]));

            // Получаем id родительского и дочерних узлов из текстового файла
            QStringList listLines = readFromTextFile(QString(argv[1]));


            // Преобразовать полученный xml в дерево
            TreeNode rootNode = convertDomDocumentToTreeNode(domXml);

            // Найти узел с id анализируемого узла
            TreeNode* analizedNode = rootNode.findNodeById(listLines.first());

            // Если анализируемый узел не был найден
            if (analizedNode == nullptr)
                // Вызвать исключение
                throw CustomException("Analized Node was not found");

            // Подсчитать число узлов из множества для каждого поддерева
            analizedNode->countNodesFromSet(listLines.mid(1));

            // Получить недостающие для покрытия узлы
            QStringList missingNodes = analizedNode->getMissingNodes(listLines.mid(1));

            // Вывести недостающие узлы множества
            foreach(QString misNode, missingNodes){
                cout << misNode << endl;
            }
        }
        // Иначе
        else
        {
            // Вызвать исключение

            throw CustomException("Check the correctness of the entered data");
        }

    }
    catch (CustomException ex) {
        cout << ex.what() << endl;
    }

    // Все пройдено Ок
    cout << "OK" << endl;

    return 0;

#endif

    return 0;
}
