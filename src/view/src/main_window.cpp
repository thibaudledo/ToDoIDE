#include "main_window.h"

MainWindow::MainWindow(FileController* controller)
{
    m_fileController = controller;

    m_mainLayout = new QVBoxLayout(this);

    m_editorItem = new EditorItem(m_fileController);

    // m_textEditor = new QPlainTextEdit(this);
    //m_mainLayout->addWidget(m_textEditor);

    setCentralWidget(m_editorItem);

    m_menuBar = new QMenuBar(this);

    setMenuBar(m_menuBar);

    createAction();
    createMenu();

    //setLayout(m_mainLayout);

    connect(m_newAct, &QAction::triggered, this, &MainWindow::slotNewFile);
    connect(m_openAct, &QAction::triggered, this, &MainWindow::slotOpenFile);
    connect(m_saveAct, &QAction::triggered, this, &MainWindow::slotSaveFile);
    connect(m_exitAct, &QAction::triggered, this, &MainWindow::slotExit);
    connect(m_undoAct, &QAction::triggered, this, &MainWindow::slotUndo);
    connect(m_redoAct, &QAction::triggered, this, &MainWindow::slotRedo);
    connect(m_cutAct, &QAction::triggered, this, &MainWindow::slotCut);
    connect(m_copyAct, &QAction::triggered, this, &MainWindow::slotCopy);
    connect(m_pasteAct, &QAction::triggered, this, &MainWindow::slotPaste);
    connect(m_aboutAct, &QAction::triggered, this, &MainWindow::slotAbout);
}

MainWindow::~MainWindow()
{

}

std::string MainWindow::getWindowName() const
{
    return m_windowName;
}

void MainWindow::setWindowName(const std::string &windowName)
{
    m_windowName = windowName;
}

void MainWindow::createAction()
{
    m_newAct = new QAction("New", this);
    m_newAct->setShortcut(QKeySequence::New);
    m_newAct->setStatusTip("Create a new file");
    //connect()

    m_openAct = new QAction("Open", this);
    m_openAct->setShortcut(QKeySequence::Open);
    m_openAct->setStatusTip("Open a file");

    m_saveAct = new QAction("Save", this);
    m_saveAct->setShortcut(QKeySequence::Save);
    m_saveAct->setStatusTip("Save a file");

    m_closeAct = new QAction("Close", this);
    m_closeAct->setShortcut(QKeySequence::Close);
    m_closeAct->setStatusTip("Close current document");

    m_exitAct = new QAction("Exit", this);
    m_exitAct->setShortcut(QKeySequence::Quit);
    m_exitAct->setStatusTip("Exit the program");

    m_undoAct = new QAction("Undo", this);
    m_undoAct->setShortcut(QKeySequence::Undo);
    m_undoAct->setStatusTip("Undo last action");

    m_redoAct = new QAction("Redo", this);
    m_redoAct->setShortcut(QKeySequence::Redo);
    m_redoAct->setStatusTip("Redo last undo action");

    m_cutAct = new QAction("Cut", this);
    m_cutAct->setShortcut(QKeySequence::Cut);
    m_cutAct->setStatusTip("Cut selected text");

    m_copyAct = new QAction("Copy", this);
    m_copyAct->setShortcut(QKeySequence::Copy);
    m_copyAct->setStatusTip("Copy selected text");

    m_pasteAct = new QAction("Paste", this);
    m_pasteAct->setShortcut(QKeySequence::Paste);
    m_pasteAct->setStatusTip("Paste a text");

    m_aboutAct = new QAction("About", this);
    m_aboutAct->setStatusTip("About this program");
}

void MainWindow::createMenu()
{

    m_fileMenu = menuBar()->addMenu(tr("&File"));
    m_fileMenu->addAction(m_newAct);
    m_fileMenu->addAction(m_openAct);
    m_fileMenu->addAction(m_saveAct);
    m_fileMenu->addAction(m_closeAct);
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_exitAct);

    m_editMenu = menuBar()->addMenu(tr("&Edit"));
    m_editMenu->addAction(m_undoAct);
    m_editMenu->addAction(m_redoAct);
    m_editMenu->addSeparator();
    m_editMenu->addAction(m_cutAct);
    m_editMenu->addAction(m_copyAct);
    m_editMenu->addAction(m_pasteAct);

    m_helpMenu = menuBar()->addMenu(tr("&Help"));
    m_helpMenu->addAction(m_aboutAct);
}

void MainWindow::slotNewFile()
{

}

void MainWindow::slotOpenFile()
{

}

void MainWindow::slotSaveFile()
{

}

void MainWindow::slotCloseFile()
{

}

void MainWindow::slotExit()
{

}

void MainWindow::slotUndo()
{

}

void MainWindow::slotRedo()
{

}

void MainWindow::slotCut()
{

}

void MainWindow::slotCopy()
{

}

void MainWindow::slotPaste()
{

}

void MainWindow::slotAbout()
{

}

