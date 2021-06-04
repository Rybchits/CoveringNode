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
         TreeNode* findNodeById(QString id);

         // Проверить покрывает ли заданное множество текущий узел
         bool checkCoverage(const QStringList& idsNodesFromSet);

         // Посчитать число узлов поддерева, которые принадлежат множеству
         uint countNodesFromSet(const QStringList& idsNodesFromSet);

         // Получить список id недостающих узлов
         QStringList getMissingNodes(const QStringList& idsNodesFromSet);

         // Получить id узла
         const QString getIdNode();

         // Получить указатели на дочерние узлы
         const QList<TreeNode*> getChildren();

         // Сравнение деревьев от корневого узла
         bool operator == (const TreeNode& right) const;
};

#endif // TREENODE_H
