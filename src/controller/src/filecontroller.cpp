#include "filecontroller.h"

FileController::FileController()
{
    m_fileModel = FileModel::getInstance();
}

int FileController::createNewFile(QString fileName)
{
    if(m_fileModel->isFileExist(fileName)) return false;
    m_fileModel->addFileToList(fileName, "");
    return true;
}

int FileController::openFile(QString fileName)
{
    if(QFile(fileName).exists())
    {
        QFile* file = new QFile(fileName);
        if(file->open(QIODevice::ReadWrite))
        {
            m_fileModel->addFileToList(fileName, file->readAll());
            return true;
        }
    }
    return false;
}

void FileController::saveFile(QString fileName)
{
    QString fileContent = m_fileModel->getFileContentFromList(fileName);
    QFile* file = new QFile(fileName);
    if(QFile(fileName).exists())file->remove();
    file->open(QIODevice::ReadWrite);
    file->write(fileContent.toUtf8());
    file->close();


}

void FileController::saveFile(QString fileName, QString fileContent)
{
    QFile* file = new QFile(fileName);
    if(QFile(fileName).exists())file->remove();
    file->open(QIODevice::ReadWrite);
    file->write(fileContent.toUtf8());
    file->close();
}

void FileController::saveFileAndRemoveFromList(QString fileName)
{
    saveFile(fileName);
    m_fileModel->removeFileFromList(fileName);
}

QString FileController::getFileContent(QString fileName)
{
    return m_fileModel->getFileContentFromList(fileName);
}

void FileController::setFileContent(QString fileName, QString fileContent)
{
    m_fileModel->updateFileContent(fileName, fileContent);
}

void FileController::registerObserverToModel(ObserverInterface *observer)
{
    if(observer!=nullptr)
    {
            m_fileModel->registerObserver(observer);
    }
}

void FileController::removeObserverFromModel(ObserverInterface *observer)
{
    m_fileModel->removeObserver(observer);
}

QList<QString> FileController::getFileNameList()
{
    return m_fileModel->getFileNameList();
}


