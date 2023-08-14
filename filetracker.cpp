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
        emit fileAdded(file_tmp);   // TODO: I dont need to give whole FileState object like I do now. Directory and size is enough. Room for optimization.
    }
    else
    {
        cout << file_tmp.getFileDirectory().toStdString() << " was not added because it is already featured in the list.\n";
            // TODO: move this to output.cpp
    }
}

void FileTracker::removeFile(const QString& dir)
{
    FileState file_tmp = FileState(dir);
    if (m_files.contains(file_tmp))
    {
        m_files.removeOne(file_tmp);    // TODO: I dont need to give whole FileState object like I do now. Directory and size is enough. Room for optimization.
        emit fileRemoved(file_tmp);
    }
    else
    {
        cout << file_tmp.getFileDirectory().toStdString() << " cannot be removed because it is not featured in the list.\n";
    }
}


//FileTracker::fileChanged(FileState file)
//{

//}

//FileTracker::fileCreated(FileState file)
//{

//}

//FileTracker::fileDeleted(FileState file)
//{

//}


void FileTracker::update()
{
    for (int i = 0; i < m_files.length(); i++)
    {
        switch(m_files[i].update())
        {
        case 1:
            cout << m_files[i].getFileDirectory().toStdString() << " was deleted.\n";  // TODO: change to fileChanged signal
            break;
        case 2:
            cout << m_files[i].getFileDirectory().toStdString() << " was created.\n";
            break;
        case 3:
            cout << m_files[i].getFileDirectory().toStdString() << " was changed. Current size is " << m_files[i].getSize() << " bytes.\n";    // TODO: fix - outputs incorrect info about size
            break;
        default:
            break;
        }
    }
}

