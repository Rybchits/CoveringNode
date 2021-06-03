#include "TreeNode.h"

TreeNode::TreeNode()
{

}

TreeNode::TreeNode(QDomNode xmlNodeElement)
{

}

TreeNode::TreeNode(QString IdNode, QList<TreeNode*> Children, uint NumberNodesFromSet){
    this->idNode = IdNode;
    this->children = Children;
    this->numberNodesFromSet = NumberNodesFromSet;
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

bool TreeNode::operator==(const TreeNode &right) const
{
    // Счиать что деревья идентичны
    bool isEqual = true;

    // Если не равны id корневых элементов или число дочерних узлов первого уровня считать что деревья не идентичны
    isEqual &= this->idNode == right.idNode &&
            this->children.length() == right.children.length() && this->numberNodesFromSet == right.numberNodesFromSet;

    // Для каждого дочернего узла первого уровня левого операнда
    for (int i = 0; i < this->children.length() && isEqual; i++)
    {
        // ...Считать что элемент с таким Id не был найден
        bool elementWasFound = false;

        // Для каждого дочернего узла первого уровня правого операнда, пока элемент с таким id не найден
        for (int j = 0; j < right.children.length() && !elementWasFound; j++)
        {
            // Если id дочерних элементов совпадают
            if (this->children[i]->idNode == right.children[j]->idNode)
            {
                // Сравнить поддеревья
                isEqual &= (*(right.children[j]) == *(this->children[i]));
                // Счиатать что элемент был найден
                elementWasFound = true;
            }
        }
        // Если элемент с таким id не был найден среди дочерних, считать что деревья не идентичны
        isEqual = elementWasFound? isEqual : false;
    }

    // Вернуть результат
    return isEqual;
}

