#include "output.h"
#include <iostream>

Output* Output::m_instance = nullptr;

Output* Output::getInstance(FileTracker &tracker)
{
    if (m_instance == nullptr)
    {
        m_instance = new Output(tracker);
    }
    return m_instance;
}

void Output::onFileAdded(FileState &file)
{
    std::cout << file.getFileDirectory().toStdString() << " was added to file tracker.\n";
}

void Output::onFileNotAddedFeatured(FileState &file)
{
    std::cout << file.getFileDirectory().toStdString() << " was not added because it is already featured in the list.\n";
}

void Output::onFileRemoved(FileState &file)
{
    std::cout << file.getFileDirectory().toStdString() << " was removed from file tracker.\n";
}

void Output::onFileNotRemovedNotFeatured(FileState &file)
{
    std::cout << file.getFileDirectory().toStdString() << " cannot be removed because it is not featured in the list.\n";
}

void Output::onFileEdited(FileState &file)
{
    std::cout << file.getFileDirectory().toStdString() << " was updated. Current size is "<< file.getSize() << " bytes.\n";
}

void Output::onFileCreated(FileState &file)
{
    std::cout << file.getFileDirectory().toStdString() << " was created. Current size is "<< file.getSize() << " bytes.\n";
}

void Output::onFileDeleted(FileState &file)
{
    std::cout << file.getFileDirectory().toStdString() << " was deleted.\n";
}
