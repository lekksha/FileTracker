#ifndef OUTPUT_H
#define OUTPUT_H

#include <QObject>

#include "filetracker.h"

class Output : public QObject
{
    Q_OBJECT
public:
    Output(FileTracker &m_tracker){
        connect(&m_tracker, &FileTracker::fileAdded, this, &Output::onFileAdded);
        connect(&m_tracker, &FileTracker::fileRemoved, this, &Output::onFileRemoved);
    }
public slots:
    void onFileAdded(FileState file);
    void onFileRemoved(FileState file);
    //onFileChanged(FileState file);    // Потом лучше заменить с Changed на Updated
    //onFileCreated(FileState file);
    //onFileDeleted(FileState file);
};

#endif // OUTPUT_H
