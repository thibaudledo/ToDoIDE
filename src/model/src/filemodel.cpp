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

bool FileModel::isFileExist(QString fileName)
{
    return m_tmpFileList.contains(fileName);
}

void FileModel::addFileToList(QString fileName, QString fileContent)
{
    m_tmpFileList.insert(fileName, fileContent);
    updateAllObserver();
}

void FileModel::updateFileContent(QString fileName, QString fileContent)
{
    m_tmpFileList.remove(fileName);
    m_tmpFileList.insert(fileName, fileContent);
}

void FileModel::renameFileInList(QString oldName, QString newName)
{
    QString fileContent = getFileContentFromList(oldName);
    removeFileFromList(oldName);
    addFileToList(newName, fileContent);
    updateAllObserver();
}

void FileModel::removeFileFromList(QString fileName)
{
    m_tmpFileList.remove(fileName);
    updateAllObserver();
}

QString FileModel::getFileContentFromList(QString fileName)
{
    return m_tmpFileList.value(fileName);
}

QList<QString> FileModel::getFileNameList()
{
    return m_tmpFileList.keys();
}
