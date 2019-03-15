#include "todoidemodel.h"

ToDoIDEModel* ToDoIDEModel::uniqueInstance = nullptr;

ToDoIDEModel::ToDoIDEModel()
{

}

ToDoIDEModel::~ToDoIDEModel()
{
    for(auto o : m_files.values())
    {
        delete o;
    }
}

ToDoIDEModel *ToDoIDEModel::getInstance()
{
    if(!uniqueInstance)
    {
        uniqueInstance = new ToDoIDEModel();
    }
    return uniqueInstance;
}

bool ToDoIDEModel::createNewFile(QString fileName)
{
    if(QFile(fileName).exists())return false;
    QFile* file = new QFile(fileName);
    if(file->open(QIODevice::ReadWrite))
    {
        m_files.insert(fileName, file);
        file->open(QIODevice::ReadWrite);
        return true;
    }
    return false;
}

bool ToDoIDEModel::openFile(QString fileName)
{
    if(QFile(fileName).exists())
    {
        QFile* file = new QFile(fileName);
        if(file->open(QIODevice::ReadWrite))
        {
            m_files.insert(fileName, file);
            return true;
        }
    }
    return false;
}

bool ToDoIDEModel::closeFile(QString fileName)
{
    if(m_files.contains(fileName))
    {
        QFile* file = m_files.value(fileName);
        file->close();
        return m_files.remove(fileName);
    }
    return false;
}

bool ToDoIDEModel::removeFile(QString fileName)
{
    if(m_files.contains(fileName))
    {
        QFile* file = m_files.value(fileName);
        bool removeFileFlag = file->remove(fileName);
        bool removeFromFilesFlag = m_files.remove(fileName);
        return removeFileFlag && removeFromFilesFlag;
    }
    return false;
}

bool ToDoIDEModel::rename(QString oldName, QString newName)
{
    if(m_files.contains(oldName))
    {
        QFile* file = m_files.value(oldName);
        bool removeFromFilesFlag = m_files.remove(oldName);
        bool renameFileFlag = file->rename(newName);
        m_files.insert(newName, file);
        return renameFileFlag && removeFromFilesFlag;
    }
    return false;
}

bool ToDoIDEModel::rename(QFile *file, QString newName)
{
    if(m_files.contains(file->fileName()))
    {
        bool removeFromFilesFlag = m_files.remove(file->fileName());
        bool renameFileFlag = file->rename(newName);
        m_files.insert(newName, file);
        return renameFileFlag && removeFromFilesFlag;
    }
    return false;
}

QString ToDoIDEModel::readAllFile(QString fileName)
{
    if(m_files.contains(fileName))
    {
        QFile* file = m_files.value(fileName);
        QTextStream in(file);
        QString returnedString = in.readAll();
        return returnedString;
    }
    return "";
}

QString ToDoIDEModel::readLineFromFile(QString fileName, int lineNumber)
{
    if(m_files.contains(fileName))
    {
        int count = 0;
        QFile* file = m_files.value(fileName);
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

void ToDoIDEModel::writeToFile(QString fileName, QString str)
{
    if(m_files.contains(fileName))
    {
        QFile* file = m_files.value(fileName);
        file->write(str.toUtf8());
    }
}
