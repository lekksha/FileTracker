#include "filetracker.h"
#include <iostream> // TODO: remove when signal-slot stuff with output is added

using namespace std;

FileTracker::FileTracker()
{   
}

void FileTracker::addFile(const QString& dir)
{
    FileState file_tmp = FileState(dir);
    if (!m_files.contains(file_tmp))  // does not contain argument file
    {
        m_files.append(file_tmp);
        cout << file_tmp.fileName().toStdString() << " was added to file tracker.";
            // TODO: move this to output.cpp
    }
    else
    {
        cout << file_tmp.fileName().toStdString() << " was not added because it is already featured in the list.";
            // TODO: move this to output.cpp
    }
}

void FileTracker::removeFile(const QString& dir)
{
    FileState file_tmp = FileState(dir);
    if (m_files.contains(file_tmp))
    {
        m_files.removeOne(file_tmp);
        cout << file_tmp.fileName().toStdString() << " was removed from file tracker.";
    }
    else
    {
        cout << file_tmp.fileName().toStdString() << " cannot be removed because it is not featured in the list.";
    }
}

/*
FileTracker::fileChanged(FileState file)
{

}

FileTracker::fileCreated(FileState file)
{

}

FileTracker::fileDeleted(FileState file)
{

}
*/

void FileTracker::update()
{
    for (int i = 0; i < m_files.length(); i++)
    {
        switch(m_files[i].update())
        {
        case 1:
            cout << m_files[i].fileName().toStdString() << " was deleted.";  // TODO: change to fileChanged signal
            break;
        case 2:
            cout << m_files[i].fileName().toStdString() << " was created.";
            break;
        case 3:
            cout << m_files[i].fileName().toStdString() << " was changed. Current size is " << m_files[i].size() << " bytes.";
            break;
        default:
            break;
        }
    }
}

