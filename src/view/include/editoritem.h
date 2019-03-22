#ifndef EDITORITEM_H
#define EDITORITEM_H

#include <QWidget>
#include <QPlainTextEdit>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QToolButton>

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
    void updateData();
private:
    QVBoxLayout* m_mainLayout;
    QHBoxLayout* m_horizontalLayout;
    QPlainTextEdit* m_textEditor;
    QComboBox* m_fileDisplay;
    QToolButton* m_closeButton;

    QString m_currentFileSelected;

    QString m_currentFileSelected;

    FileController* m_fileController;
private slots:
    void slotSelectedFileChanged(QString filename);
    void slotTextChanged();
    void slotCloseButtonPressed();
};

#endif // EDITORITEM_H
