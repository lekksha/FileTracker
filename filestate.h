#ifndef FILESTATE_H
#define FILESTATE_H

#include <QFileInfo>
#include <QString>

class FileState : public QFileInfo
{
private:
    QString m_dir;
    quint64 m_size;
    bool m_existance;
public:
    FileState(const QString dir);
    QString getFileDirectory();
    quint64 getSize();
    bool getExistanceStatus();

    int update();
    bool operator== (const FileState& tmp) const;
        // contains() from <QList> requires to have operator== described in its argument type.
};

#endif // FILESTATE_H
