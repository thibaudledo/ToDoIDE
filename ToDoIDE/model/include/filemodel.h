#ifndef FILEMODEL_H
#define FILEMODEL_H

#include <QMap>
#include <QFile>

#include "../../abstract_class/observer_pattern/observableinterface.h"

class FileModel : public ObservableInterface
{
public:
    ~FileModel();
    static FileModel* getInstance();

    bool isFileExist(QString);
    void addFileToList(QFile*);
    void addFileToList(QString, QFile*);
    void replaceFileInList(QString, QFile*);
    void removeFileFromList(QString);
    void deleteFileFromList(QString);
    QFile* getFileFromList(QString);

private:
    FileModel();
    static FileModel* uniqueInstance;
    QMap<QString, QFile*> m_filesList;
};

#endif // FILEMODEL_H
