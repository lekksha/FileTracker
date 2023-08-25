#ifndef FILETRACKER_H
#define FILETRACKER_H

#include <QList>
#include "filestate.h"

class FileTracker : public QObject
{
    Q_OBJECT
public:
    QList<FileState> m_files;

    FileTracker();
    void addFile(const QString& dir);
    void removeFile(const QString& dir);
    void update();
signals:
    fileAdded(FileState file);
    fileNotAddedFeatured(FileState file);
    fileRemoved(FileState file);
    fileNotRemovedNotFeatured(FileState file);
//    fileChanged(FileState file);
//    fileCreated(FileState file);
//    fileDeleted(FileState file);
};

#endif // FILETRACKER_H
