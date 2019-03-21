#ifndef FILECONTROLLER_H
#define FILECONTROLLER_H

#include <QString>
#include <QFile>
#include <QTextStream>

#include "../model/filemodel.h"

class FileController
{
public:
    FileController();
    bool createNewFile(QString);
    bool openFile(QString);
    bool closeFile(QString);
    bool removeFile(QString);
    bool rename(QString oldName, QString newName);
    bool rename(QFile* file, QString newName);
    QString readAllFile(QString);
    QString readLineFromFile(QString, int);
    void writeToFile(QString name, QString str);
    void writeToFile(QString name, QString str, int line);
private:
    FileModel* m_fileModel;
};

#endif // FILECONTROLLER_H
