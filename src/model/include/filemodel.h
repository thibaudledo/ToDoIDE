#ifndef FILEMODEL_H
#define FILEMODEL_H

#include <QMap>
#include <QFile>

#include "observableinterface.h"

class FileModel : public ObservableInterface
{
public:
    ~FileModel();
    static FileModel* getInstance();

    bool isFileExist(QString fileName);
    void addFileToList(QString fileName);
    void addFileToList(QString fileName, QString fileContent);
    void updateFileContent(QString fileName, QString fileContent);
    void renameFileInList(QString oldName, QString newName);
    void removeFileFromList(QString fileName);
    QString getFileContentFromList(QString fileName);
    QList<QString> getFileNameList();

private:
    FileModel();
    static FileModel* uniqueInstance;
    QMap<QString, QString> m_tmpFileList;
};

#endif // FILEMODEL_H
