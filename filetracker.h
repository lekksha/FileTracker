#ifndef FILETRACKER_H
#define FILETRACKER_H

#include <QList>
#include "filestate.h"

class FileTracker : public QObject
{
    Q_OBJECT
    static FileTracker* m_instance;
public:
    QList<FileState> m_files;

    static FileTracker* getInstance();
    void addFile(const QString& dir);
    void removeFile(const QString& dir);
    void update();
signals:
    void fileAdded(FileState file);
    void fileNotAddedFeatured(FileState file);
    void fileRemoved(FileState file);
    void fileNotRemovedNotFeatured(FileState file);
    void fileEdited(FileState file);
    void fileCreated(FileState file);
    void fileDeleted(FileState file);
};

#endif // FILETRACKER_H
