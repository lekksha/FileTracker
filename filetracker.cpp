#include "filetracker.h"


FileTracker* FileTracker::m_instance = nullptr;

FileTracker* FileTracker::getInstance()
{
    if (m_instance == nullptr)
    {
        m_instance = new FileTracker;
    }
    return m_instance;
}

void FileTracker::addFile(const QString& dir)
{
    FileState file_tmp = FileState(dir);

    if (!m_files.contains(file_tmp))
    {
        m_files.append(file_tmp);
        emit fileAdded(file_tmp);
    }
    else
    {
        emit fileNotAddedFeatured(file_tmp);
    }
}

void FileTracker::removeFile(const QString& dir)
{
    FileState file_tmp = FileState(dir);
    if (m_files.contains(file_tmp))
    {
        m_files.removeOne(file_tmp);
        emit fileRemoved(file_tmp);
    }
    else
    {
        emit fileNotRemovedNotFeatured(file_tmp);
    }
}

void FileTracker::update()
{
    for (int i = 0; i < m_files.length(); i++)
    {
        switch(m_files[i].update())
        {
        case 1:
            emit fileDeleted(m_files[i]);
//            cout << m_files[i].getFileDirectory().toStdString() << " was deleted or renamed.\n";
            continue;
        case 2:
            emit fileCreated(m_files[i]);
//            cout << m_files[i].getFileDirectory().toStdString() << " was created.\n";
            continue;
        case 3:
            emit fileEdited(m_files[i]);
//                cout << m_files[i].getFileDirectory().toStdString() << " was changed. Current size is " << m_files[i].getSize() << " bytes.\n";    // TODO: fix - outputs incorrect info about size
            continue;
        default:
            continue;
        }
    }
}

