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

    bool isFileExist(QString);
    void addFileToList(QString, QList<QString>);
    void replaceFileInList(QString, QList<QString>);
    void removeFileFromList(QString);
    QList<QString> getFileFromList(QString);

private:
    FileModel();
    static FileModel* uniqueInstance;
    QMap<QString, QFile*> m_filesList;
    QMap<QString, QList<QString>> m_tmpFileList;
};

#endif // FILEMODEL_H
