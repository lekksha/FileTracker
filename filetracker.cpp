#include "filetracker.h"

FileTracker::FileTracker()
{   
}

FileTracker::addFile(const QString dir)
{
    FileState file_tmp = FileState(dir);
    if (!this->contains(file_tmp))  // does not cointan argument file
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

FileTracker::update()
{

}

FileTracker::fileChanged(FileState file)
{

}

FileTracker::fileCreated(FileState file)
{

}

FileTracker::fileDeleted(FileState file)
{

}
