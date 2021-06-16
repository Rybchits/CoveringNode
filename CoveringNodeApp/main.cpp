#include <QCoreApplication>
#include <functions.h>

/*!
    \brief Программа предназначена для определения, покрывает ли данный набор узлов дерева вышележащий узел.
    \version 1.0.0
    \warning Xml файл должен содержать единственный коревой элемент и пролог.
    \warning Каждый узел дерева, который участвует в рассмотрении должен иметь уникальный атрибут id.
    \warning Все узлы от корневого до анализируемого также должны иметь уникальный атрибут id.

    \param[in] arс - число аргументов
    \param[in] arg[0] - путь к исполняемому файлу
    \param[in] arg[1] - путь к входному xml файлу
    \param[in] arg[2] - путь к входному txt файлу
    \param[out] arg[3] - путь к выходному txt файлу

    \return 0 - программа успешно завершена
*/

int main(int argc, char *argv[])
{

#ifdef TESTING_MODE
    runTests(argc, argv);
#else


    QCoreApplication a(argc, argv);
    QTextStream cout(stdout);

    /// ****    Алгоритм работы программы   ****
    try {

        // Если число аргументов соответствует ожидаемому
        if (argc == 4)
        {
            /// Получаем дерево в виде xml файла
            QDomDocument domXml = readFromXmlFile(QString(argv[1]));

            /// Получаем id родительского и дочерних узлов из текстового файла
            QStringList listLines = readFromTextFile(QString(argv[2]));

            /// Преобразовать полученный xml в дерево класса TreeNode
            TreeNode rootNode = convertDomDocumentToTreeNode(domXml);

            /// Найти узел с id анализируемого узла
            TreeNode* analizedNode = rootNode.findNodeById(listLines.first());

            // Если анализируемый узел не был найден
            if (analizedNode == nullptr)
                // Вызвать исключение
                throw CustomException("Analized Node was not found");

            /// Получить недостающие для покрытия узлы
            QStringList missingNodes;
            analizedNode->getMissingNodes(analizedNode->getIdNode(), listLines.mid(1), missingNodes);

            /// Записать результат в файл
            wtiteToTextFile(argv[3], missingNodes);
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
    cout << endl << "Complete!" << endl;

#endif

    return 0;
}
