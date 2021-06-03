#include "TreeNode.h"

TreeNode::TreeNode()
{

}

TreeNode::TreeNode(QDomNode xmlNodeElement)
{

}


/* Посчитать число узлов поддерева, которые принадлежат множеству
 * QStringList& idsNodesFromSet - список id узлов множества
 * return число узлов поддерева
*/
uint TreeNode::countNodesFromSet(const QStringList& idsNodesFromSet)
{
    return 0;
}

/* Найти узел по его id
 * QString id - id узла
 * return указатель на искомый узел
*/
TreeNode* TreeNode::findNodeById(QString id)
{
    return nullptr;
}

/* Проверить покрывает ли заданное множество узлов данный узел
 * QStringList& idsNodesFromSet - id узлов множества
 * return краткий ответ покрывает ли заданное множество узлов данный узел
*/
bool TreeNode::checkCoverage(const QStringList& idsNodesFromSet)
{

}

/* Получить список id недостающих узлов для покрытия узла заданным множеством
 * QStringList& idsNodesFromSet - id узлов множества
 * QStringList& MissingNodes - ссылка на список недостающих узлов
*/
void TreeNode::getMissingNodes(const QStringList& idsNodesFromSet, QStringList& MissingNodes)
{

}


const QString TreeNode::getIdNode()
{
    return this->idNode;
}

const QList<TreeNode*> TreeNode::getChildren()
{
    return this->children;
}
