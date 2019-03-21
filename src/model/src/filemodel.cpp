#include "filemodel.h"

FileModel* FileModel::uniqueInstance = nullptr;

FileModel::FileModel()
{

}

FileModel::~FileModel()
{
    for(auto o : m_filesList.values())
    {
        delete o;
    }
}

FileModel *FileModel::getInstance()
{
    if(!uniqueInstance)
    {
        uniqueInstance = new FileModel();
    }
    return uniqueInstance;
}

bool FileModel::isFileExist(QString name)
{
    return m_filesList.contains(name);
}

void FileModel::addFileToList(QFile *file)
{
    m_filesList.insert(file->fileName(), file);
}

void FileModel::addFileToList(QString name, QFile *file)
{
    m_filesList.insert(name, file);
}

void FileModel::replaceFileInList(QString name, QFile *file)
{
    deleteFileFromList(name);
    addFileToList(name, file);
}

void FileModel::removeFileFromList(QString name)
{
    m_filesList.remove(name);
}

void FileModel::deleteFileFromList(QString name)
{
    QFile* file = m_filesList.take(name);
    delete  file;
}

QFile *FileModel::getFileFromList(QString name)
{
    return m_filesList.value(name);
}
