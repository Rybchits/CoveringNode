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
    void test_sum();

};

AppTest::AppTest()
{

}

AppTest::~AppTest()
{

}

void AppTest::test_sum()
{
    //QVERIFY2(sum(1, 1) == 2, "Проверка суммы не удалась");
}

#include "tst_apptest.moc"

int runTests(int argc, char* argv[]){

    AppTest test;

    return QTest::qExec(&test, argc, argv);
}

#define TESTING_MODE
#include "../CoveringNodeApp/main.cpp"
