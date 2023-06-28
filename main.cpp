#include <QCoreApplication>
#include <QTimer>
#include <iostream>
#include "filetracker.h"
#include "filestate.h"

using namespace std;

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

    /*
    QTimer timer;
    timer.setInterval(500);
    QObject::connect(&timer, &QTimer::timeout, &test_tracker, &FileTracker::update);
    timer.start();
    */

    return a.exec();

}
