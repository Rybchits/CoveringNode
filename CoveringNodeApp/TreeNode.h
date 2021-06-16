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
        QList<TreeNode*> children;                               // Список дочерних узлов

     public:
         //! Конструктор по умолчанию
         TreeNode();

         //! Конструктор узла по документу с древовидной структурой
         TreeNode(QDomNode xmlNodeElement);

         //! Конструктор для тестирования
         TreeNode(QString IdNode, QList<TreeNode*> Children);

         //! Найти узел по его id
         /*!
           \param[in] QString id - id узла
           \return указатель на искомый узел
        */
         TreeNode* findNodeById(const QString id);

         //! Проверить покрывает ли заданное множество текущий узел
         /*!
            \param[in] QStringList& idsNodesFromSet - id узлов множества
            \return краткий ответ покрывает ли заданное множество узлов данный узел
         */
         bool checkCoverage(const QStringList& idsNodesFromSet);

         //! Получить список id недостающих узлов для покрытия узла заданным множеством
         /*!
            \param[in] QString analizedNodeId - id анализируемого узла
            \param[in] QStringList& idsNodesFromSet - id узлов множества
            \param[out] QStringList& MissingNodes - ссылка на список недостающих узлов
            \return число узлов принадлежащих множеству для данного поддерева
         */
         uint getMissingNodes(const QString& analizedNodeId,const QStringList& idsNodesFromSet, QStringList& MissingNodes);

         //! Получить id узла
         const QString getIdNode();

         //! Получить указатели на дочерние узлы
         const QList<TreeNode*> getChildren();

         //! Сравнение деревьев от корневого узла
         bool operator == (const TreeNode& right) const;
};

#endif // TREENODE_H
