#include "filestate.h"

FileState::FileState(const QString dir)
{
    m_dir = dir;
    QFileInfo file(dir);
    m_size = file.size();
    m_existance = file.exists();
}

quint64 FileState::getSize()
{
    return m_size;
}



int FileState::update()
{
    QFileInfo updated_file = QFileInfo(m_dir);
    if ( this->m_existance && !updated_file.exists() ) // file was deleted - code 1
    {
        m_size = updated_file.size();
        m_existance = updated_file.exists();
        return 1;
    }
    else if ( !m_existance && updated_file.exists() )    // file was created - code 2
    {
        m_size = updated_file.size();
        m_existance = updated_file.exists();
        return 2;
    }
    else if ( (m_existance && updated_file.exists()) && (m_size != updated_file.size()) )    // file was changed - code 3
    {
        m_size = updated_file.size();
        return 3;
    }
    else    // file was not changed - code 0
    {
        return 0;
    }
}

bool FileState::operator==(const FileState &tmp) const
{
    if
    (m_dir == tmp.m_dir &&     // TODO: decide whether directory comparison is enough
    m_size == tmp.m_size &&
    m_existance == tmp.m_existance)
        return true;
    else
        return false;
}
