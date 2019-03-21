#include "filemodel.h"

FileModel* FileModel::uniqueInstance = nullptr;

FileModel::FileModel()
{

}

FileModel::~FileModel()
{
    m_tmpFileList.clear();
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

void FileModel::addFileToList(QString name, QList<QString> file)
{
    m_tmpFileList.insert(name, file);
}

void FileModel::replaceFileInList(QString name, QList<QString> file)
{
    removeFileFromList(name);
    addFileToList(name, file);
}

void FileModel::removeFileFromList(QString name)
{
    m_filesList.remove(name);
}

QList<QString> FileModel::getFileFromList(QString name)
{
    return m_tmpFileList.value(name);
}
