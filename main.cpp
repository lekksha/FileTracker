#include <QCoreApplication>
#include <QTimer>
#include <iostream>
#include "filetracker.h"
#include "output.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileTracker* test_tracker = FileTracker::getInstance();
    Output* test_output = Output::getInstance(*test_tracker);


    // The files need to be added below
    test_tracker->addFile("C:/Users/lekks/TSU/semester 6/TRPO/FileTracker_testfiles/1.txt");
    test_tracker->addFile("C:/Users/lekks/TSU/semester 6/TRPO/FileTracker_testfiles/1.txt");
    test_tracker->removeFile("C:/Users/lekks/TSU/semester 6/TRPO/FileTracker_testfiles/1.txt");
    test_tracker->removeFile("C:/Users/lekks/TSU/semester 6/TRPO/FileTracker_testfiles/1.txt");

    test_tracker->addFile("C:/Users/lekks/TSU/semester 6/TRPO/FileTracker_testfiles/1.txt");
    //


    QTimer timer;
    timer.setInterval(500);
    QObject::connect(&timer, &QTimer::timeout, test_tracker, &FileTracker::update);
    timer.start();

    return a.exec();

}
