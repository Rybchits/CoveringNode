#include "TreeNode.h"

TreeNode::TreeNode()
{

}

TreeNode::TreeNode(QDomNode xmlNodeElement)
{
    // Преобразуем текущий узел в класс элемента
    QDomElement element = xmlNodeElement.toElement();

    // Если не удалось преобразовать узел в элемент
    if (element.isNull())
    {
        // Вызвать исключение
        throw CustomException("The specified node is not ElementNode");
    }

    // Если у элемента отсутсвует аттрибут id
    if (!element.hasAttribute("id"))
    {
        // Вызвать исключение
        throw CustomException("The specified node hasn't attribute id");
    }

    // Указать ID текущего узла
    this->idNode = element.attribute("id");

    // Получить список дочерних узлов текущего
    QDomNodeList childsCurrentNode = xmlNodeElement.childNodes();

    // Для каждого дочернего узла текущего
    for (int i = 0; i < childsCurrentNode.count(); i++){

        // Если дочерний узел является ElementNode
        if (childsCurrentNode.item(i).nodeType() == QDomNode::ElementNode){

            // Если дочерний узел имеет аттрибут id
            if (childsCurrentNode.item(i).toElement().hasAttribute("id"))

                // Добавить узел в список дочерних узлов
                this->children.append(new TreeNode(childsCurrentNode.item(i)));
        }
    }
}

TreeNode::TreeNode(QString IdNode, QList<TreeNode*> Children, uint NumberNodesFromSet)
{
    this->idNode = IdNode;
    this->children = Children;
    this->numberNodesFromSet = NumberNodesFromSet;
}

/* Найти узел по его id
 * QString id - id узла
 * return указатель на искомый узел
*/
TreeNode* TreeNode::findNodeById(const QString searchId)
{
    // Обход дерева в ширину с поиском узла с искомым id...

    QQueue<TreeNode*> queueNodes;      // Узлы, которые осталось обойти
    queueNodes.enqueue(this);       // Поместить в очередь текущий узел

    // Пока есть не рассмотренные узлы...
    while (!queueNodes.isEmpty()) {

        // Взять первый элемент из очереди
        TreeNode* currentNode = queueNodes.dequeue();

        // Если текущий элемент имеет id искомого узла
        if (currentNode->idNode == searchId)
            // Считать текущий элемент искомым и вернуть его
            return currentNode;

        // Иначе
        else
        {
            // Добавить в очередь все дочерние узлы текущего узла
            queueNodes.append(currentNode->children);
        }
    }

    // Если узел не был найден, вернуть пустой указатель
    return nullptr;
}

/* Проверить покрывает ли заданное множество узлов данный узел
 * QStringList& idsNodesFromSet - id узлов множества
 * return краткий ответ покрывает ли заданное множество узлов данный узел
*/
bool TreeNode::checkCoverage(const QStringList& idsNodesFromSet)
{
    // ...Считать что этот узел имеет статус - покрыт
    bool isNodeCovered = true;

    // Если id текущего узла не указан во множестве
    if (!idsNodesFromSet.contains(this->idNode))
    {
        // Если у текущего узла нет дочерних
        if (this->children.count() == 0)
            // Считать что узел не покрыт
            isNodeCovered = false;

        // Иначе
        else
        {
            // Если каждый из дочерних узлов является покрытым, считать текущий узел покрытым...
            // Для каждого дочернего узла
            foreach(TreeNode* child, this->children)
            {
                // Изменить статус покрытия узла относительно, статуса покрытия этого дочернего узла
                isNodeCovered &= child->checkCoverage(idsNodesFromSet);
            }
        }
    }

    // Вернуть статус покрытия узла
    return isNodeCovered;
}

/* Получить список id недостающих узлов для покрытия узла заданным множеством
 * QStringList& idsNodesFromSet - id узлов множества
 * QStringList& MissingNodes - ссылка на список недостающих узлов
 * return
*/
uint TreeNode::getMissingNodes(const QString analizedNodeId, const QStringList& idsNodesFromSet, QStringList& MissingNodes)
{
    // Считать число узлов, которые принадлежат множеству
    uint numberNodesFromSet = 0;

    // Если текущий узел во множестве
    if (idsNodesFromSet.contains(this->idNode))
    {
        numberNodesFromSet = 1;
    }

    // Иначе
    else
    {
        // Посчитать число узлов из множества для каждого дочернего узла
        foreach(TreeNode* child, this->children)
        {
            numberNodesFromSet += child->getMissingNodes(analizedNodeId ,idsNodesFromSet, MissingNodes);
        }

        // Если число узлов, которые принадлежат множеству равно 0 и узел не является нализируемым
        if (numberNodesFromSet == 0 && this->idNode != analizedNodeId)
        {
            // Удалить все id дочерних узлов из множества недостающих узлов
            foreach(TreeNode* child, this->children)
            {
                MissingNodes.removeAll(child->idNode);
            }

            // Добавить этот узел в список недостающих
            MissingNodes.append(this->idNode);

        }
    }

    // Вернуть число узлов поддерева, которые принадлежат множеству
    return numberNodesFromSet;
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

