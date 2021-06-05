#include <QtTest>
#include <functions.h>

// add necessary includes here

class AppTest : public QObject
{
    Q_OBJECT

public:
    AppTest();
    ~AppTest();

private slots:

    // convertDomDocumentToTreeNode
    void test_CompleteBinaryTree();
    void test_ComplexTest();
    void test_ErrorNoCloseTag();
    void test_ErrorNoRoot();
    void test_ExceptionNoIds();
    void test_HasComments();
    void test_TwoNodeLevels();
    void test_HasNames();
    void test_IncompleteBinaryTree();
    void test_OnlyRootNode();
    void test_SomeTagsNoID();
    void test_UnbalancedTree();

    // findNodeById
    void test_NoSearchNode();
    void test_SearchNodeIsLeaf();
    void test_SearchNodeInSecondLevel();
    void test_SearchNodeIdIsEmpty();
    void test_IdNodeHasNumbers();
    void test_IdNodeHasLatin();
    void test_IdNodeHasSpecialSymbol();
    void test_SearchNodeIsRoot();
    void test_NodesHaveSubstringId();

    // countNodesFromSet
    void test_NoNodesFromSet();
    void test_AnalizedNodeInSet();
    void test_ChildNodesFirstLevelInSet();
    void test_ChildNodesDifferentLevelsInSet();
    void test_SetIsEmprty();
    void test_ParentNodesInSet();
    void test_ComplexTest2();

    // getMissingNodes
    void test_ChildNodesFirstLevelInSet2();
    void test_NoChildNodes();
    void test_UnbalancedTree2();
    void test_MissingNodesInDifferentLevels();
    void test_MissingNodeIsLeaf();
    void test_AnalizedNodeInSet2();
};

AppTest::AppTest()
{

}

AppTest::~AppTest()
{

}

// convertDomDocumentToTreeNode

void AppTest::test_CompleteBinaryTree()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/convertDomDocumentToTreeNode/CompleteBinaryTree.xml");
        TreeNode resultFunction = convertDomDocumentToTreeNode(domXml);

        // Нижний уровень
        TreeNode childNode2_1("Node2Id_1", QList<TreeNode*>());
        TreeNode childNode2_2("Node2Id_2", QList<TreeNode*>());
        TreeNode childNode2_4("Node2Id_4", QList<TreeNode*>());
        TreeNode childNode2_5("Node2Id_5", QList<TreeNode*>());

        // Первый уровень
        TreeNode childNode1_1("Node1Id_1", QList<TreeNode*>() = {&childNode2_1, &childNode2_2});
        TreeNode childNode1_2("Node1Id_2", QList<TreeNode*>() = {&childNode2_4, &childNode2_5});

        // Корень
        TreeNode rootNode("RootNodeId", QList<TreeNode*>() = {&childNode1_1, &childNode1_2});

        QVERIFY2(resultFunction == rootNode, "Деревья не идентичны");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

void AppTest::test_ComplexTest()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/convertDomDocumentToTreeNode/ComplexTest.xml");
        TreeNode resultFunction = convertDomDocumentToTreeNode(domXml);

        // Нижний уровень
        TreeNode childNode2_1("Node2Id_1", QList<TreeNode*>());
        TreeNode childNode2_2("Node2Id_2", QList<TreeNode*>());
        TreeNode childNode2_3("Node2Id_3", QList<TreeNode*>());
        TreeNode childNode2_4("Node2Id_4", QList<TreeNode*>());
        TreeNode childNode2_5("Node2Id_5", QList<TreeNode*>());
        TreeNode childNode2_6("Node2Id_6", QList<TreeNode*>());

        // Первый уровень
        TreeNode childNode1_1("Node1Id_1", QList<TreeNode*>() = {&childNode2_1, &childNode2_2, &childNode2_3});
        TreeNode childNode1_2("Node1Id_2", QList<TreeNode*>() = {&childNode2_4, &childNode2_5, &childNode2_6});

        // Корень
        TreeNode rootNode("RootNodeId", QList<TreeNode*>() = {&childNode1_1, &childNode1_2});

        QVERIFY2(resultFunction == rootNode, "Деревья не идентичны");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

void AppTest::test_ErrorNoCloseTag()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/convertDomDocumentToTreeNode/ErrorNoCloseTag.xml");
        TreeNode resultFunction = convertDomDocumentToTreeNode(domXml);

        QVERIFY2(false, "Xml испорчен");
    }
    catch (CustomException e)
    {
        QVERIFY2(true, e.what());
    }
}

void AppTest::test_ErrorNoRoot()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/convertDomDocumentToTreeNode/ErrorNoRoot.xml");
        TreeNode resultFunction = convertDomDocumentToTreeNode(domXml);

        QVERIFY2(false, "Xml испорчен");
    }
    catch (CustomException e)
    {
        QVERIFY2(true, e.what());
    }
}

void AppTest::test_ExceptionNoIds()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/convertDomDocumentToTreeNode/ExceptionNoIds.xml");
        TreeNode resultFunction = convertDomDocumentToTreeNode(domXml);

        QVERIFY2(false, "У узлов Xml нет Id");
    }
    catch (CustomException e)
    {
        QVERIFY2(true, e.what());
    }
}

void AppTest::test_HasComments()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/convertDomDocumentToTreeNode/HasComments.xml");
        TreeNode resultFunction = convertDomDocumentToTreeNode(domXml);

        // Создание дерева
        TreeNode childNode1("1", QList<TreeNode*>());
        TreeNode childNode2("2", QList<TreeNode*>());
        TreeNode rootNode("RootNodeId", QList<TreeNode*>() = {&childNode1, &childNode2});

        QVERIFY2(resultFunction == rootNode, "Деревья не идентичны");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

void AppTest::test_TwoNodeLevels()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/convertDomDocumentToTreeNode/TwoNodeLevels.xml");
        TreeNode resultFunction = convertDomDocumentToTreeNode(domXml);

        // Создание дерева
        TreeNode childNode1("Node1Id_1", QList<TreeNode*>());
        TreeNode childNode2("Node1Id_2", QList<TreeNode*>());
        TreeNode rootNode("RootNodeId", QList<TreeNode*>() = {&childNode1, &childNode2});

        QVERIFY2(resultFunction == rootNode, "Деревья не идентичны");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

void AppTest::test_HasNames()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/convertDomDocumentToTreeNode/HasNames.xml");
        TreeNode resultFunction = convertDomDocumentToTreeNode(domXml);

        // Создание дерева
        TreeNode childNode1("Node1Id_1", QList<TreeNode*>());
        TreeNode childNode2("Node1Id_2", QList<TreeNode*>());
        TreeNode rootNode("RootNodeId", QList<TreeNode*>() = {&childNode1, &childNode2});

        QVERIFY2(resultFunction == rootNode, "Деревья не идентичны");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

void AppTest::test_IncompleteBinaryTree()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/convertDomDocumentToTreeNode/IncompleteBinaryTree.xml");
        TreeNode resultFunction = convertDomDocumentToTreeNode(domXml);

        // Нижний уровень
        TreeNode childNode2_1("Node2Id_1", QList<TreeNode*>());
        TreeNode childNode2_4("Node2Id_4", QList<TreeNode*>());
        TreeNode childNode2_5("Node2Id_5", QList<TreeNode*>());

        // Первый уровень
        TreeNode childNode1_1("Node1Id_1", QList<TreeNode*>() = {&childNode2_1});
        TreeNode childNode1_2("Node1Id_2", QList<TreeNode*>() = {&childNode2_4, &childNode2_5});

        // Корень
        TreeNode rootNode("RootNodeId", QList<TreeNode*>() = {&childNode1_1, &childNode1_2});

        QVERIFY2(resultFunction == rootNode, "Деревья не идентичны");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

void AppTest::test_OnlyRootNode()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/convertDomDocumentToTreeNode/OnlyRootNode.xml");
        TreeNode resultFunction = convertDomDocumentToTreeNode(domXml);

        // Создание дерева
        TreeNode rootNode("Root", QList<TreeNode*>());

        QVERIFY2(resultFunction == rootNode, "Деревья не идентичны");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

void AppTest::test_SomeTagsNoID()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/convertDomDocumentToTreeNode/SomeTagsNoID.xml");
        TreeNode resultFunction = convertDomDocumentToTreeNode(domXml);

        // Нижний уровень
        TreeNode childNode2_1("Node2Id_1", QList<TreeNode*>());
        TreeNode childNode2_2("Node2Id_2", QList<TreeNode*>());
        TreeNode childNode2_3("Node2Id_3", QList<TreeNode*>());

        // Первый уровень
        TreeNode childNode1_1("Node1Id_1", QList<TreeNode*>() = {&childNode2_1, &childNode2_2, &childNode2_3});

        // Корень
        TreeNode rootNode("RootNodeId", QList<TreeNode*>() = {&childNode1_1});

        QVERIFY2(resultFunction == rootNode, "Деревья не идентичны");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

void AppTest::test_UnbalancedTree()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/convertDomDocumentToTreeNode/UnbalancedTree.xml");
        TreeNode resultFunction = convertDomDocumentToTreeNode(domXml);

        // Создание дерева
        TreeNode childNode4("4", QList<TreeNode*>());
        TreeNode childNode3("3", QList<TreeNode*>() = {&childNode4});
        TreeNode childNode2("2", QList<TreeNode*>() = {&childNode3});
        TreeNode childNode1("1", QList<TreeNode*>() = {&childNode2});
        TreeNode rootNode("0", QList<TreeNode*>() = {&childNode1});

        QVERIFY2(resultFunction == rootNode, "Деревья не идентичны");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

// findNodeById

void AppTest::test_NoSearchNode()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/findNodeById/TypicalXml.xml");
        TreeNode tree = convertDomDocumentToTreeNode(domXml);

        QString idSearchNode = "RootNodeId2";

        // Поиск узла
        TreeNode* resultFunction = tree.findNodeById(idSearchNode);

        QVERIFY2(resultFunction == nullptr, "Узла с таким id нет");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

void AppTest::test_SearchNodeIsLeaf()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/findNodeById/TypicalXml.xml");
        TreeNode tree = convertDomDocumentToTreeNode(domXml);

        QString idSearchNode = "Node2Id_6";

        // Поиск узла
        TreeNode* resultFunction = tree.findNodeById(idSearchNode);

        QVERIFY2(resultFunction->getIdNode() == idSearchNode, "Найденный узел имеет другой ID");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

void AppTest::test_SearchNodeInSecondLevel()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/findNodeById/TypicalXml.xml");
        TreeNode tree = convertDomDocumentToTreeNode(domXml);

        QString idSearchNode = "Node1Id_1";

        // Поиск узла
        TreeNode* resultFunction = tree.findNodeById(idSearchNode);

        QVERIFY2(resultFunction->getIdNode() == idSearchNode, "Найденный узел имеет другой ID");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

void AppTest::test_SearchNodeIdIsEmpty()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/findNodeById/TypicalXml.xml");
        TreeNode tree = convertDomDocumentToTreeNode(domXml);

        QString idSearchNode = "";

        // Поиск узла
        TreeNode* resultFunction = tree.findNodeById(idSearchNode);

        QVERIFY2(resultFunction == nullptr, "Узла с таким Id нет");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

void AppTest::test_IdNodeHasNumbers()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/findNodeById/NodeHasNumbers.xml");
        TreeNode tree = convertDomDocumentToTreeNode(domXml);

        QString idSearchNode = "1234";

        // Поиск узла
        TreeNode* resultFunction = tree.findNodeById(idSearchNode);

        QVERIFY2(resultFunction->getIdNode() == idSearchNode, "Найденный узел имеет другой ID");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

void AppTest::test_IdNodeHasLatin()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/findNodeById/NodeHasLatin.xml");
        TreeNode tree = convertDomDocumentToTreeNode(domXml);

        QString idSearchNode = "SearchNode";

        // Поиск узла
        TreeNode* resultFunction = tree.findNodeById(idSearchNode);

        QVERIFY2(resultFunction->getIdNode() == idSearchNode, "Найденный узел имеет другой ID");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

void AppTest::test_IdNodeHasSpecialSymbol()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/findNodeById/NodeHasSpecialSymbol.xml");
        TreeNode tree = convertDomDocumentToTreeNode(domXml);

        QString idSearchNode = "#$%|*";

        // Поиск узла
        TreeNode* resultFunction = tree.findNodeById(idSearchNode);

        QVERIFY2(resultFunction->getIdNode() == idSearchNode, "Найденный узел имеет другой ID");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

void AppTest::test_SearchNodeIsRoot()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/convertDomDocumentToTreeNode/OnlyRootNode.xml");
        TreeNode tree = convertDomDocumentToTreeNode(domXml);

        QString idSearchNode = "Root";

        // Поиск узла
        TreeNode* resultFunction = tree.findNodeById(idSearchNode);

        QVERIFY2(resultFunction->getIdNode() == idSearchNode, "Найденный узел имеет другой ID");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

void AppTest::test_NodesHaveSubstringId()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/findNodeById/NodesHaveSubstring.xml");
        TreeNode tree = convertDomDocumentToTreeNode(domXml);

        QString idSearchNode = "Node";

        // Поиск узла
        TreeNode* resultFunction = tree.findNodeById(idSearchNode);

        QVERIFY2(resultFunction->getIdNode() == idSearchNode, "Найденный узел имеет другой ID");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

// countNodesFromSet

void AppTest::test_NoNodesFromSet()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/countNodesFromSet/TypicalXml.xml");
        TreeNode testTree = convertDomDocumentToTreeNode(domXml);

        QString idAnalizedNode = "Node1Id_1";
        QStringList set = {"Node1Id_2"};

        TreeNode* searchNode = testTree.findNodeById(idAnalizedNode);
        searchNode->countNodesFromSet(set);

        // Третий уровень
        TreeNode childNode3_1("Node3Id_1", QList<TreeNode*>());
        TreeNode childNode3_2("Node3Id_2", QList<TreeNode*>());

        // Второй уровень
        TreeNode childNode2_1("Node2Id_1", QList<TreeNode*>());
        TreeNode childNode2_2("Node2Id_2", QList<TreeNode*>() = {&childNode3_1, &childNode3_2});
        TreeNode childNode2_3("Node2Id_3", QList<TreeNode*>());

        // Первый уровень
        TreeNode childNode1_1("Node1Id_1", QList<TreeNode*>() = {&childNode2_1, &childNode2_2});
        TreeNode childNode1_2("Node1Id_2", QList<TreeNode*>() = {&childNode2_3});

        // Корень
        TreeNode rootNode("RootNodeId", QList<TreeNode*>() = {&childNode1_1, &childNode1_2});

        QVERIFY2(testTree == rootNode, "Деревья не идентичны");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

void AppTest::test_AnalizedNodeInSet()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/countNodesFromSet/TypicalXml.xml");
        TreeNode testTree = convertDomDocumentToTreeNode(domXml);

        QString idAnalizedNode = "Node1Id_1";
        QStringList set = {"Node1Id_1"};

        TreeNode* searchNode = testTree.findNodeById(idAnalizedNode);
        searchNode->countNodesFromSet(set);

        // Третий уровень
        TreeNode childNode3_1("Node3Id_1", QList<TreeNode*>());
        TreeNode childNode3_2("Node3Id_2", QList<TreeNode*>());

        // Второй уровень
        TreeNode childNode2_1("Node2Id_1", QList<TreeNode*>());
        TreeNode childNode2_2("Node2Id_2", QList<TreeNode*>() = {&childNode3_1, &childNode3_2});
        TreeNode childNode2_3("Node2Id_3", QList<TreeNode*>());

        // Первый уровень
        TreeNode childNode1_1("Node1Id_1", QList<TreeNode*>() = {&childNode2_1, &childNode2_2}, 1);
        TreeNode childNode1_2("Node1Id_2", QList<TreeNode*>() = {&childNode2_3});

        // Корень
        TreeNode rootNode("RootNodeId", QList<TreeNode*>() = {&childNode1_1, &childNode1_2});

        QVERIFY2(testTree == rootNode, "Деревья не идентичны");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

void AppTest::test_ChildNodesFirstLevelInSet()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/countNodesFromSet/TypicalXml.xml");
        TreeNode testTree = convertDomDocumentToTreeNode(domXml);

        QString idAnalizedNode = "Node1Id_1";
        QStringList set = {"Node2Id_1", "Node2Id_2"};

        TreeNode* searchNode = testTree.findNodeById(idAnalizedNode);
        searchNode->countNodesFromSet(set);

        // Третий уровень
        TreeNode childNode3_1("Node3Id_1", QList<TreeNode*>());
        TreeNode childNode3_2("Node3Id_2", QList<TreeNode*>());

        // Второй уровень
        TreeNode childNode2_1("Node2Id_1", QList<TreeNode*>(), 1);
        TreeNode childNode2_2("Node2Id_2", QList<TreeNode*>() = {&childNode3_1, &childNode3_2}, 1);
        TreeNode childNode2_3("Node2Id_3", QList<TreeNode*>());

        // Первый уровень
        TreeNode childNode1_1("Node1Id_1", QList<TreeNode*>() = {&childNode2_1, &childNode2_2}, 2);
        TreeNode childNode1_2("Node1Id_2", QList<TreeNode*>() = {&childNode2_3});

        // Корень
        TreeNode rootNode("RootNodeId", QList<TreeNode*>() = {&childNode1_1, &childNode1_2});

        QVERIFY2(testTree == rootNode, "Деревья не идентичны");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

void AppTest::test_ChildNodesDifferentLevelsInSet()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/countNodesFromSet/TypicalXml.xml");
        TreeNode testTree = convertDomDocumentToTreeNode(domXml);

        QString idAnalizedNode = "Node1Id_1";
        QStringList set = {"Node2Id_1", "Node3Id_2"};

        TreeNode* searchNode = testTree.findNodeById(idAnalizedNode);
        searchNode->countNodesFromSet(set);

        // Третий уровень
        TreeNode childNode3_1("Node3Id_1", QList<TreeNode*>());
        TreeNode childNode3_2("Node3Id_2", QList<TreeNode*>(), 1);

        // Второй уровень
        TreeNode childNode2_1("Node2Id_1", QList<TreeNode*>(), 1);
        TreeNode childNode2_2("Node2Id_2", QList<TreeNode*>() = {&childNode3_1, &childNode3_2}, 1);
        TreeNode childNode2_3("Node2Id_3", QList<TreeNode*>());

        // Первый уровень
        TreeNode childNode1_1("Node1Id_1", QList<TreeNode*>() = {&childNode2_1, &childNode2_2}, 2);
        TreeNode childNode1_2("Node1Id_2", QList<TreeNode*>() = {&childNode2_3});

        // Корень
        TreeNode rootNode("RootNodeId", QList<TreeNode*>() = {&childNode1_1, &childNode1_2});

        QVERIFY2(testTree == rootNode, "Деревья не идентичны");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

void AppTest::test_SetIsEmprty()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/countNodesFromSet/TypicalXml.xml");
        TreeNode testTree = convertDomDocumentToTreeNode(domXml);

        QString idAnalizedNode = "Node1Id_1";
        QStringList set = {};

        TreeNode* searchNode = testTree.findNodeById(idAnalizedNode);
        searchNode->countNodesFromSet(set);

        // Третий уровень
        TreeNode childNode3_1("Node3Id_1", QList<TreeNode*>());
        TreeNode childNode3_2("Node3Id_2", QList<TreeNode*>());

        // Второй уровень
        TreeNode childNode2_1("Node2Id_1", QList<TreeNode*>());
        TreeNode childNode2_2("Node2Id_2", QList<TreeNode*>() = {&childNode3_1, &childNode3_2});
        TreeNode childNode2_3("Node2Id_3", QList<TreeNode*>());

        // Первый уровень
        TreeNode childNode1_1("Node1Id_1", QList<TreeNode*>() = {&childNode2_1, &childNode2_2});
        TreeNode childNode1_2("Node1Id_2", QList<TreeNode*>() = {&childNode2_3});

        // Корень
        TreeNode rootNode("RootNodeId", QList<TreeNode*>() = {&childNode1_1, &childNode1_2});

        QVERIFY2(testTree == rootNode, "Деревья не идентичны");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

void AppTest::test_ParentNodesInSet()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/countNodesFromSet/TypicalXml.xml");
        TreeNode testTree = convertDomDocumentToTreeNode(domXml);

        QString idAnalizedNode = "Node1Id_1";
        QStringList set = {"Node2Id_2", "RootNodeId"};

        TreeNode* searchNode = testTree.findNodeById(idAnalizedNode);
        searchNode->countNodesFromSet(set);

        // Третий уровень
        TreeNode childNode3_1("Node3Id_1", QList<TreeNode*>());
        TreeNode childNode3_2("Node3Id_2", QList<TreeNode*>());

        // Второй уровень
        TreeNode childNode2_1("Node2Id_1", QList<TreeNode*>());
        TreeNode childNode2_2("Node2Id_2", QList<TreeNode*>() = {&childNode3_1, &childNode3_2}, 1);
        TreeNode childNode2_3("Node2Id_3", QList<TreeNode*>());

        // Первый уровень
        TreeNode childNode1_1("Node1Id_1", QList<TreeNode*>() = {&childNode2_1, &childNode2_2}, 1);
        TreeNode childNode1_2("Node1Id_2", QList<TreeNode*>() = {&childNode2_3});

        // Корень
        TreeNode rootNode("RootNodeId", QList<TreeNode*>() = {&childNode1_1, &childNode1_2});

        QVERIFY2(testTree == rootNode, "Деревья не идентичны");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

void AppTest::test_ComplexTest2()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/countNodesFromSet/TypicalXml.xml");
        TreeNode testTree = convertDomDocumentToTreeNode(domXml);

        QString idAnalizedNode = "RootNodeId";
        QStringList set = {"Node1Id_1", "Node2Id_3", "Node3Id_2", "Node2Id_1"};

        TreeNode* searchNode = testTree.findNodeById(idAnalizedNode);
        searchNode->countNodesFromSet(set);

        // Третий уровень
        TreeNode childNode3_1("Node3Id_1", QList<TreeNode*>());
        TreeNode childNode3_2("Node3Id_2", QList<TreeNode*>(), 1);

        // Второй уровень
        TreeNode childNode2_1("Node2Id_1", QList<TreeNode*>(), 1);
        TreeNode childNode2_2("Node2Id_2", QList<TreeNode*>() = {&childNode3_1, &childNode3_2}, 1);
        TreeNode childNode2_3("Node2Id_3", QList<TreeNode*>(), 1);

        // Первый уровень
        TreeNode childNode1_1("Node1Id_1", QList<TreeNode*>() = {&childNode2_1, &childNode2_2}, 3);
        TreeNode childNode1_2("Node1Id_2", QList<TreeNode*>() = {&childNode2_3}, 1);

        // Корень
        TreeNode rootNode("RootNodeId", QList<TreeNode*>() = {&childNode1_1, &childNode1_2}, 4);

        QVERIFY2(testTree == rootNode, "Деревья не идентичны");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

// getMissingNodes

void AppTest::test_ChildNodesFirstLevelInSet2()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/getMissingNodes/TypicalXml.xml");
        TreeNode testTree = convertDomDocumentToTreeNode(domXml);

        QString idAnalizedNode = "Node1Id_1";
        QStringList set = {"Node2Id_1", "Node2Id_2", "Node2Id_3"};
        QSet<QString> expectedMissingNodes = {};

        TreeNode* searchNode = testTree.findNodeById(idAnalizedNode);
        searchNode->countNodesFromSet(set);
        QStringList MissingNodes = searchNode->getMissingNodes(set);

        QVERIFY2(MissingNodes.toSet() == expectedMissingNodes, "Неверно выделены пропущенные узлы");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

void AppTest::test_NoChildNodes()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/getMissingNodes/TypicalXml.xml");
        TreeNode testTree = convertDomDocumentToTreeNode(domXml);

        QString idAnalizedNode = "Node3Id_2";
        QStringList set = {"Node3Id_2"};
        QSet<QString> expectedMissingNodes = {};

        TreeNode* searchNode = testTree.findNodeById(idAnalizedNode);
        searchNode->countNodesFromSet(set);
        QStringList MissingNodes = searchNode->getMissingNodes(set);

        QVERIFY2(MissingNodes.toSet() == expectedMissingNodes, "Неверно выделены пропущенные узлы");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

void AppTest::test_UnbalancedTree2()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/getMissingNodes/UnbalancedTree.xml");
        TreeNode testTree = convertDomDocumentToTreeNode(domXml);

        QString idAnalizedNode = "RootNodeId";
        QStringList set = {};
        QSet<QString> expectedMissingNodes = {"1"};

        TreeNode* searchNode = testTree.findNodeById(idAnalizedNode);
        searchNode->countNodesFromSet(set);
        QStringList MissingNodes = searchNode->getMissingNodes(set);

        QVERIFY2(MissingNodes.toSet() == expectedMissingNodes, "Неверно выделены пропущенные узлы");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

void AppTest::test_MissingNodesInDifferentLevels()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/getMissingNodes/TypicalXml.xml");
        TreeNode testTree = convertDomDocumentToTreeNode(domXml);

        QString idAnalizedNode = "RootNodeId";
        QStringList set = {"Node2Id_1", "Node2Id_3"};
        QSet<QString> expectedMissingNodes = {"Node2Id_2", "Node1Id_2"};

        TreeNode* searchNode = testTree.findNodeById(idAnalizedNode);
        searchNode->countNodesFromSet(set);
        QStringList MissingNodes = searchNode->getMissingNodes(set);

        QVERIFY2(MissingNodes.toSet() == expectedMissingNodes, "Неверно выделены пропущенные узлы");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

void AppTest::test_MissingNodeIsLeaf()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/getMissingNodes/TypicalXml.xml");
        TreeNode testTree = convertDomDocumentToTreeNode(domXml);

        QString idAnalizedNode = "Node1Id_1";
        QStringList set = {"Node2Id_1", "Node3Id_2", "Node2Id_3"};
        QSet<QString> expectedMissingNodes = {"Node3Id_1"};

        TreeNode* searchNode = testTree.findNodeById(idAnalizedNode);
        searchNode->countNodesFromSet(set);
        QStringList MissingNodes = searchNode->getMissingNodes(set);

        QVERIFY2(MissingNodes.toSet() == expectedMissingNodes, "Неверно выделены пропущенные узлы");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

void AppTest::test_AnalizedNodeInSet2()
{
    try
    {
        // Конвертация дерева
        QDomDocument domXml = readFromXmlFile(":/Resources/XmlTrees/getMissingNodes/TypicalXml.xml");
        TreeNode testTree = convertDomDocumentToTreeNode(domXml);

        QString idAnalizedNode = "RootNodeId";
        QStringList set = {"Node2Id_1", "Node2Id_3", "RootNodeId"};
        QSet<QString> expectedMissingNodes = {};

        TreeNode* searchNode = testTree.findNodeById(idAnalizedNode);
        searchNode->countNodesFromSet(set);
        QStringList MissingNodes = searchNode->getMissingNodes(set);

        QVERIFY2(MissingNodes.toSet() == expectedMissingNodes, "Неверно выделены пропущенные узлы");
    }
    catch (CustomException e)
    {
        QVERIFY2(false, e.what());
    }
}

#include "tst_apptest.moc"

int runTests(int argc, char* argv[]){

    AppTest test;

    return QTest::qExec(&test, argc, argv);
}

#define TESTING_MODE
#include "../CoveringNodeApp/main.cpp"
