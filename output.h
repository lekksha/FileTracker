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
        connect(&m_tracker, &FileTracker::fileNotAddedFeatured, this, &Output::onFileNotAddedFeatured);
        connect(&m_tracker, &FileTracker::fileRemoved, this, &Output::onFileRemoved);
        connect(&m_tracker, &FileTracker::fileNotRemovedNotFeatured, this, &Output::onFileNotRemovedNotFeatured);

        connect(&m_tracker, &FileTracker::fileChanged, this, &Output::onFileChanged);
        connect(&m_tracker, &FileTracker::fileCreated, this, &Output::onFileCreated);
    }
public slots:
    void onFileAdded(FileState file);
    void onFileNotAddedFeatured(FileState file);
    void onFileRemoved(FileState file);
    void onFileNotRemovedNotFeatured(FileState file);
    void onFileChanged(FileState file);    // Потом лучше заменить с Changed на Updated
    void onFileCreated(FileState file);
    //onFileDeleted(FileState file);
};

#endif // OUTPUT_H
