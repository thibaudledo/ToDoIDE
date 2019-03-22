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
#include <QDockWidget>
#include <QFileSystemModel>

class MainWindow : public QMainWindow
{
public:
    MainWindow();

    ~MainWindow();

    std::string getWindowName() const;
    void setWindowName(const std::string &windowName);

private:
    void createAction();
    void createMenu();
    int createTreeView();

    std::string m_windowName;

    QVBoxLayout* m_mainLayout;

    QMenuBar* m_menuBar;

    QMenu* m_fileMenu;
    QMenu* m_editMenu;
    QMenu* m_helpMenu;

    QAction* m_newAct;
    QAction* m_openAct;
    QAction* m_saveAct;
    QAction* m_exitAct;
    QAction* m_undoAct;
    QAction* m_redoAct;
    QAction* m_cutAct;
    QAction* m_copyAct;
    QAction* m_pasteAct;
    QAction* m_aboutAct;


    QDockWidget *m_dockWidget;
    QFileSystemModel *m_fileSystemModel;
    QTreeView *m_treeView;
    QPlainTextEdit* m_textEditor;



};
