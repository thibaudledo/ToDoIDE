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
    connect(m_textEditor, &QPlainTextEdit::textChanged, this, &EditorItem::slotTextChanged);

    updateFileDisplayContent();
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

void EditorItem::updateFileDisplayContent()
{
    QList<QString> fileNameList = m_fileController->getFileNameList();
    QString currentFileSelected = m_fileDisplay->currentText();
    m_fileDisplay->clear();

    int index = 0;
    for(QString fileNameWithPath : fileNameList)
    {
        QString fileName;
        m_fileDisplay->addItem(fileNameWithPath, index);
        index++;
    }
    m_fileDisplay->setCurrentText(currentFileSelected);
}

QString EditorItem::getCurrentFileSelected()
{
    return m_fileDisplay->currentText();
}

void EditorItem::updateData()
{
    qDebug() << "6";
    updateFileDisplayContent();
}

void EditorItem::slotSelectedFileChanged(QString filename)
{
    setTextEditorContent(m_fileController->getFileContent(filename));
}

void EditorItem::slotTextChanged()
{
    qDebug() << m_fileDisplay->currentText();
    m_fileController->setFileContent(m_fileDisplay->currentText(), getTextEditorContent());
}
