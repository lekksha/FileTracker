#include <QCoreApplication>
//#include <iostream>
#include "filetracker.h"
#include "filestate.h"

//using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileTracker test_tracker = FileTracker();
    test_tracker.addFile("C:/Users/lekks/Desktop/Labs3_2/TRPO/FileTracker_testfiles/1.txt");
    test_tracker.addFile("C:/Users/lekks/Desktop/Labs3_2/TRPO/FileTracker_testfiles/1.txt");

    test_tracker.removeFile("C:/Users/lekks/Desktop/Labs3_2/TRPO/FileTracker_testfiles/1.txt");
    test_tracker.removeFile("C:/Users/lekks/Desktop/Labs3_2/TRPO/FileTracker_testfiles/1.txt");

    //QTimer *timer = new QTimer(this);
    //connect(timer, &QTimer::timeout, this, &Foo::processOneThing);
с

    return a.exec();
}
