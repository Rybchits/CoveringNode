#ifndef TREENODE_H
#define TREENODE_H
#include <QDomDocument>
#include <QList>

class TreeNode
{
    private:
        QString idNode;                                          // Id узла
        uint numberNodesFromSet = 0;                             // Число узлов поддерева, которые принадлежат множеству
        QList<TreeNode*> children;                               // Список дочерних узлов


        // Посчитать число узлов поддерева, которые принадлежат множеству
        uint countNodesFromSet(const QStringList& idsNodesFromSet);

     public:
         // Конструктор по умолчанию
         TreeNode();

         // Конструктор узла по документу с древовидной структурой
         TreeNode(QDomNode xmlNodeElement);

         // Найти узел по его id
         TreeNode* findNodeById(QString id);

         // Проверить покрывает ли заданное множество текущий узел
         bool checkCoverage(const QStringList& idsNodesFromSet);

         // Получить список id недостающих узлов
         void getMissingNodes(const QStringList& idsNodesFromSet, QStringList& MissingNodes);

         // Получить id узла
         const QString getIdNode();

         // Получить указатели на дочерние узлы
         const QList<TreeNode*> getChildren();
};

#endif // TREENODE_H
