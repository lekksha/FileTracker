#include "filestate.h"

FileState::FileState(QString dir)
{
    m_dir = dir;
    QFileInfo file(dir);
    m_size = file.size();
    m_exists = file.exists();
}

FileState::getSize()
{
    return m_size;
}


FileState::update()
{
    QFileInfo updated_file(m_dir);
    if ( m_exists && !updated_file.exists() ) // file was deleted - code 1
    {
        m_size = updated_file.size();
        m_exists = updated_file.exists();
        return 1;
    }
    else if ( !m_exists && updated_file.exists() )    // file was created - code 2
    {
        m_size = updated_file.size();
        m_exists = updated_file.exists();
        return 2;
    }
    else if ( (m_exists && updated_file.exists) && (m_size != updated_file.size()) )    // file was changed - code 3
    {
        m_size = updated_file.size();
        return 3;
    }
    else    // file was not changed - code 0
    {
        return 0;
    }
}
