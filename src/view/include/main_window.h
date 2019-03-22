#include <QMainWindow>
#include <QMenuBar>
#include <QPlainTextEdit>

#include <string>

#include <QObject>
#include <QPlainTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QTreeView>
#include <QAction>
#include <QVBoxLayout>

#include <QFileDialog>
#include <QInputDialog>
#include <QDir>

#include "filecontroller.h"
#include "editoritem.h"

#include <QDebug>

class MainWindow : public QMainWindow
{
public:
    MainWindow(FileController* controller);

    ~MainWindow();

    std::string getWindowName() const;
    void setWindowName(const std::string &windowName);

private:
    void createAction();
    void createMenu();

    std::string m_windowName;

    FileController* m_fileController;

    QVBoxLayout* m_mainLayout;

    QMenuBar* m_menuBar;

    QMenu* m_fileMenu;
    QMenu* m_editMenu;
    QMenu* m_helpMenu;

    QAction* m_newAct;
    QAction* m_openAct;
    QAction* m_saveAct;
    QAction* m_closeAct;
    QAction* m_exitAct;
    QAction* m_undoAct;
    QAction* m_redoAct;
    QAction* m_cutAct;
    QAction* m_copyAct;
    QAction* m_pasteAct;
    QAction* m_aboutAct;


    QTreeView* m_treeView;

    EditorItem* m_editorItem;
    QPlainTextEdit* m_textEditor;

private slots:
    void slotNewFile();
    void slotOpenFile();
    void slotSaveFile();
    void slotCloseFile();
    void slotExit();
    void slotUndo();
    void slotRedo();
    void slotCut();
    void slotCopy();
    void slotPaste();
    void slotAbout();

};
