#ifndef FILESTATE_H
#define FILESTATE_H

#include <QFileInfo>
#include <QString>

class FileState : QFileInfo
{
private:
    QString m_dir;
    Uint64 m_size;
    Bool m_existance;
public:
    FileState(QString dir);
    Uint64 getSize();
    Int update();
};

#endif // FILESTATE_H
