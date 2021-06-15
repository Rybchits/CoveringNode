#ifndef TREENODE_H
#define TREENODE_H
#include <QDomDocument>
#include <QList>
#include "CustomException.h"
#include <QQueue>

class TreeNode
{
    private:
        QString idNode;                                          // Id узла
        uint numberNodesFromSet = 0;                             // Число узлов поддерева, которые принадлежат множеству
        QList<TreeNode*> children;                               // Список дочерних узлов

     public:
         // Конструктор по умолчанию
         TreeNode();

         // Конструктор узла по документу с древовидной структурой
         TreeNode(QDomNode xmlNodeElement);

         // Конструктор для тестирования
         TreeNode(QString IdNode, QList<TreeNode*> Children, uint NumberNodesFromSet=0);

         // Найти узел по его id
         TreeNode* findNodeById(const QString id);

         // Проверить покрывает ли заданное множество текущий узел
         bool checkCoverage(const QStringList& idsNodesFromSet);

         // Получить список id недостающих узлов
         uint getMissingNodes(const QString analizedNodeId,const QStringList& idsNodesFromSet, QStringList& MissingNodes);

         // Получить id узла
         const QString getIdNode();

         // Получить указатели на дочерние узлы
         const QList<TreeNode*> getChildren();

         // Сравнение деревьев от корневого узла
         bool operator == (const TreeNode& right) const;
};

#endif // TREENODE_H
