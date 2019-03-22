#ifndef EDITORITEM_H
#define EDITORITEM_H

#include <QWidget>
#include <QPlainTextEdit>
#include <QComboBox>
#include <QVBoxLayout>

#include "filecontroller.h"
#include "observerinterface.h"

#include <QDebug>

class EditorItem : public QWidget, public ObserverInterface
{
public:
    EditorItem(FileController* controller);
    ~EditorItem();

    void setTextEditorContent(QString fileContent);
    QString getTextEditorContent();
    void updateFileDisplayContent();
    void updateFileEditorContent();
    QString getCurrentFileSelected();
    void displayNextFileOrClear();
    void updateData();
private:
    QVBoxLayout* m_mainLayout;
    QPlainTextEdit* m_textEditor;
    QComboBox* m_fileDisplay;

    QString m_currentFileSelected;

    FileController* m_fileController;
private slots:
    void slotSelectedFileChanged(QString filename);
    void slotTextChanged();
};

#endif // EDITORITEM_H
