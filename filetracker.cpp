#include "filetracker.h"

using namespace std;


FileTracker::FileTracker()
{   
}

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

    if (!m_files.contains(file_tmp))  // if does not contain argument file
    {
        m_files.append(file_tmp);
        emit fileAdded(file_tmp);   // TODO: I dont need to give whole FileState object like I do now. Directory and size is enough. Room for optimization?
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
        m_files.removeOne(file_tmp);    // TODO: I dont need to give whole FileState object like I do now. Directory and size is enough. Room for optimization?
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
            break;
        case 2:
            emit fileCreated(m_files[i]);
//            cout << m_files[i].getFileDirectory().toStdString() << " was created.\n";
            break;
        case 3:
            emit fileEdited(m_files[i]);
//                cout << m_files[i].getFileDirectory().toStdString() << " was changed. Current size is " << m_files[i].getSize() << " bytes.\n";    // TODO: fix - outputs incorrect info about size
            break;
        default:
            break;
        }
    }
}

