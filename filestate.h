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
    FileState(const QString dir);
    Uint64 getSize();
    /// Bool exists();
    Int update();
    Bool operator== (const StateFile& tmp) const;
        // contains() from <QList> requires to have operator== described in its argument type.
};

#endif // FILESTATE_H
