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

        connect(&m_tracker, &FileTracker::fileEdited, this, &Output::onFileEdited);
        connect(&m_tracker, &FileTracker::fileCreated, this, &Output::onFileCreated);
        connect(&m_tracker, &FileTracker::fileDeleted, this, &Output::onFileDeleted);
    }
public slots:
    void onFileAdded(FileState file);
    void onFileNotAddedFeatured(FileState file);
    void onFileRemoved(FileState file);
    void onFileNotRemovedNotFeatured(FileState file);
    void onFileEdited(FileState file);
    void onFileCreated(FileState file);
    void onFileDeleted(FileState file);
};

#endif // OUTPUT_H
