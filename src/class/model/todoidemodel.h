#ifndef TODOIDEMODEL_H
#define TODOIDEMODEL_H

#include "../../abstract_class/observer_pattern/observableinterface.h"

#include <QFile>
#include <QMap>
#include <QTextStream>

class ToDoIDEModel : ObservableInterface
{
private:
    ToDoIDEModel();
    ~ToDoIDEModel();
    static ToDoIDEModel* uniqueInstance;
    QMap<QString, QFile*> m_files;
public:
    static ToDoIDEModel* getInstance();
    //FILE* createNewFile(std::string);
    //FILE* openFile(std::string);
    bool createNewFile(QString);
    bool openFile(QString);
    bool closeFile(QString);
    bool removeFile(QString);
    bool rename(QString oldName, QString newName);
    bool rename(QFile* file, QString newName);
    QString readAllFile(QString);
    QString readLineFromFile(QString, int);
    void writeToFile(QString name, QString str);

};

#endif // TODOIDEMODEL_H
