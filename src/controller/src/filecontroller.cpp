#include "filecontroller.h"

FileController::FileController()
{
    m_fileModel = FileModel::getInstance();
}

bool FileController::createNewFile(QString fileName)
{
    if(m_fileModel->isFileExist(fileName)) return false;
    QFile* file = new QFile(fileName);
    if(file->open(QIODevice::ReadWrite))
    {
        m_fileModel->addFileToList(fileName, file);
        file->open(QIODevice::ReadWrite);
        return true;
    }
    return false;
}

bool FileController::openFile(QString fileName)
{
    if(QFile(fileName).exists())
    {
        QFile* file = new QFile(fileName);
        if(file->open(QIODevice::ReadWrite))
        {
            m_fileModel->addFileToList(fileName, file);
            return true;
        }
    }
    return false;
}

bool FileController::closeFile(QString fileName)
{
    if(m_fileModel->isFileExist(fileName))
    {
        QFile* file = m_fileModel->getFileFromList(fileName);
        file->close();
        m_fileModel->removeFileFromList(fileName);
        return true;
    }
    return false;
}

bool FileController::removeFile(QString fileName)
{
    if(m_fileModel->isFileExist(fileName))
    {
        QFile* file = m_fileModel->getFileFromList(fileName);
        bool removeFileFlag = file->remove(fileName);
        m_fileModel->removeFileFromList(fileName);
        return removeFileFlag;
    }
    return false;
}

bool FileController::rename(QString oldName, QString newName)
{
    if(m_fileModel->isFileExist(oldName))
    {
        QFile* file = m_fileModel->getFileFromList(oldName);
        m_fileModel->removeFileFromList(oldName);
        bool renameFileFlag = file->rename(newName);
        m_fileModel->addFileToList(newName, file);
        return renameFileFlag;
    }
    return false;
}

bool FileController::rename(QFile *file, QString newName)
{
    if(m_fileModel->isFileExist(file->fileName()))
    {
        QFile* newfile = m_fileModel->getFileFromList(file->fileName());
        m_fileModel->removeFileFromList(file->fileName());
        bool renameFileFlag = newfile->rename(newName);
        m_fileModel->addFileToList(newName, newfile);
        return renameFileFlag;
    }
    return false;
}

QString FileController::readAllFile(QString fileName)
{
    if(m_fileModel->isFileExist(fileName))
    {
        QFile* file = m_fileModel->getFileFromList(fileName);
        QTextStream in(file);
        QString returnedString = in.readAll();
        return returnedString;
    }
    return "";
}

QString FileController::readLineFromFile(QString fileName, int lineNumber)
{
    if(m_fileModel->isFileExist(fileName))
    {
        int count = 0;
        QFile* file = m_fileModel->getFileFromList(fileName);
        QTextStream in(file);
        QString returnedString = "";
        while((!in.atEnd())&&(count<=lineNumber))
        {
            count+=1;
            returnedString = in.readLine();
        }
        return returnedString;
    }
    return "";
}

void FileController::writeToFile(QString fileName, QString str)
{
    if(m_fileModel->isFileExist(fileName))
    {
        QFile* file = m_fileModel->getFileFromList(fileName);
        file->write(str.toUtf8());
    }
}

void FileController::writeToFile(QString fileName, QString str, int line)
{
    if(m_fileModel->isFileExist(fileName))
    {
        QFile* file = m_fileModel->getFileFromList(fileName);
        QTextStream in(file);
        QList<QString> fileLines;
        while(in.atEnd())
        {
            fileLines.append(in.readLine());
        }
        fileLines.insert(line, str);
        QString name = file->fileName();
        removeFile(file->fileName());
        QFile* newFile = new QFile(name);
        for(int count=0; count<fileLines.size(); count++)
        {
            newFile->write(fileLines.takeFirst().toUtf8());
        }
        m_fileModel->replaceFileInList(name, newFile);
    }
}

