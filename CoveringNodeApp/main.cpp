#include <QCoreApplication>
#include <functions.h>


int main(int argc, char *argv[])
{

#ifdef TESTING_MODE
    runTests(argc, argv);
#else
    //Основное поведение программы

    QTextStream cout(stdout);

    cout << "Hello world" << endl;

    //int res = sum(1, 1);
#endif

    return 0;
}
