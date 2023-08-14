#include "output.h"
#include <iostream>

void Output::onFileAdded(FileState file)
{
    std::cout << file.getFileDirectory().toStdString() << " was added to file tracker.\n";
}

void Output::onFileRemoved(FileState file)
{
    std::cout << file.getFileDirectory().toStdString() << " was removed from file tracker.\n";
}

//onFileChanged(FileState file)
//{

//}

//onFileCreated(FileState file)
//{

//}

//onFileDeleted(FileState file)
//{

//}
