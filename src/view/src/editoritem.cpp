#include "editoritem.h"

EditorItem::EditorItem(FileController* controller)
{
    m_fileController = controller;
    //m_fileController->registerObserverToModel(this);

    m_mainLayout = new QVBoxLayout(this);
    m_fileDisplay = new QComboBox(this);
    m_textEditor = new QPlainTextEdit(this);

    m_mainLayout->addWidget(m_fileDisplay);
    m_mainLayout->addWidget(m_textEditor);

    setLayout(m_mainLayout);

    connect(m_fileDisplay, SIGNAL(currentTextChanged(QString)), this, SLOT(slotTextChanged(QString)));
    connect(m_textEditor, SIGNAL(textChanged()), this, SLOT(slotTextChanged()));
}

EditorItem::~EditorItem()
{

}

void EditorItem::setTextEditorContent(QString fileContent)
{
    m_textEditor->setPlainText(fileContent);
}

QString EditorItem::getTextEditorContent()
{
    return m_textEditor->toPlainText();
}

void EditorItem::updateFileDisplayContent(QList<QString> listOfFile)
{
    int index = 0;
    for(QString fileName : listOfFile)
    {
        m_fileDisplay->addItem(fileName, index);
        index++;
    }
}

void EditorItem::update()
{
    QList<QString> fileNameList = m_fileController->getFileNameList();
    QString currentFileSelected = m_fileDisplay->currentText();
    m_fileDisplay->clear();
    updateFileDisplayContent(fileNameList);
    m_fileDisplay->setCurrentText(currentFileSelected);
}

void EditorItem::slotSelectedFileChanged(QString filename)
{
    setTextEditorContent(m_fileController->getFileContent(filename));
}

void EditorItem::slotTextChanged()
{
    m_fileController->setFileContent(m_fileDisplay->currentText(), getTextEditorContent());
}
