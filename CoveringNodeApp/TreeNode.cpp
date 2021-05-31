#include "TreeNode.h"

TreeNode::TreeNode()
{

}

TreeNode::TreeNode(QDomNode xmlNodeElement)
{

}

uint TreeNode::countNodesFromSet(const QStringList& idsNodesFromSet)
{
    return 0;
}

TreeNode* TreeNode::findNodeById(QString id)
{
    return nullptr;
}

bool TreeNode::checkCoverage(const QStringList& idsNodesFromSet)
{

}

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
