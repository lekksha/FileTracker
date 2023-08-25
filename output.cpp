#include "output.h"
#include <iostream>

void Output::onFileAdded(FileState file)
{
    std::cout << file.getFileDirectory().toStdString() << " was added to file tracker.\n";
}

void Output::onFileNotAddedFeatured(FileState file)
{
    std::cout << file.getFileDirectory().toStdString() << " was not added because it is already featured in the list.\n";
}

void Output::onFileRemoved(FileState file)
{
    std::cout << file.getFileDirectory().toStdString() << " was removed from file tracker.\n";
}

void Output::onFileNotRemovedNotFeatured(FileState file)
{
    std::cout << file.getFileDirectory().toStdString() << " cannot be removed because it is not featured in the list.\n";
}

void Output::onFileChanged(FileState file)  // TODO: change to onFileUpdated
{
    std::cout << file.getFileDirectory().toStdString() << " was updated. Current size is "<< file.getSize() << " bytes.\n";
}

//onFileCreated(FileState file)
//{

//}

//onFileDeleted(FileState file)
//{

//}
