#include "filetracker.h"

FileTracker::FileTracker()
{   
}

FileTracker::addFile(const QString dir)
{
    FileState file_tmp = FileState(dir);
    if (!this->contains(file_tmp))  // does not contain argument file
    {
        m_files.append(file_tmp);
        std::cout << file_tmp.fileName << " was added to file tracker.";
            // TODO: move this to output.cpp
    }
    else
    {
        std::cout << file_tmp.fileName << " was not added because it is already featured in the list.";
            // TODO: move this to output.cpp
    }
}

FileTracker::removeFile(const QString dir)
{
    FileState file_tmp = FileState(dir);
    if (this->contains(file_tmp))
    {
        m_files.removeOne(file_tmp);
        std::cout << file_tmp.fileName << " was removed from file tracker.";
    }
    else
    {
        std::cout << file_tmp.fileName << " cannot be removed because it is not featured in the list.";
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

FileTracker::update()
{
    for (int i = 0; i < length; i++)
    {
        switch(m_files[i].update())
        {
        case 1: std::cout << m_files[i].name() << " was deleted.";  // TODO: change to fileChanged signal
        case 2: std::cout << m_files[i].name() << " was created.";
        case 3: std::cout << m_files[i].name() << " was changed. Current size is " << m_files[i].size() << " bytes.";
        }
    }
}

