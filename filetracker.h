#ifndef FILETRACKER_H
#define FILETRACKER_H

#include <QList>
#include "filestate.h"

class FileTracker
{
    Q_OBJECT
public:
    QList m_files;

    FileTracker();
    void addFile(FileState file);   // TODO: поменять аргумент на QString с директорией файла?
    void removeFile(FileState file);
    void update();
signals:
    fileChanged(FileState file);
    fileCreated(FileState file);
    fileDeleted(FileState file);
};

#endif // FILETRACKER_H
