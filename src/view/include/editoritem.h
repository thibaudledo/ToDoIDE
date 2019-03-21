#ifndef EDITORITEM_H
#define EDITORITEM_H

#include <QWidget>
#include <QPlainTextEdit>
#include <QComboBox>
#include <QVBoxLayout>

#include "filecontroller.h"
#include "observerinterface.h"

class EditorItem : public QWidget, public ObserverInterface
{
public:
    EditorItem(FileController* controller);
    ~EditorItem();

    void setTextEditorContent(QString fileContent);
    QString getTextEditorContent();
    void updateFileDisplayContent(QList<QString> listOfFile);
    void update();
private:
    QVBoxLayout* m_mainLayout;
    QPlainTextEdit* m_textEditor;
    QComboBox* m_fileDisplay;

    FileController* m_fileController;
private slots:
    void slotSelectedFileChanged(QString filename);
    void slotTextChanged();
};

#endif // EDITORITEM_H
