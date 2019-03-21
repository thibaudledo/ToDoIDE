#ifndef FILECONTROLLER_H
#define FILECONTROLLER_H

#include <QString>
#include <QFile>
#include <QTextStream>

#include "filemodel.h"
#include "observerinterface.h"

class FileController
{
public:
    FileController();
    int createNewFile(QString fileName);
    int openFile(QString fileName);
    void saveFile(QString fileName);
    void saveFile(QString fileName, QString fileContent);
    void saveFileAndRemoveFromList(QString fileName);
    QString getFileContent(QString fileName);
    void setFileContent(QString fileName, QString fileContent);

    void registerObserverToModel(ObserverInterface* observer);
    void removeObserverFromModel(ObserverInterface* observer);
    QList<QString> getFileNameList();
private:
    FileModel* m_fileModel;
};

#endif // FILECONTROLLER_H
