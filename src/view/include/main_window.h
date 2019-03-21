#include <QMainWindow>
#include <QMenuBar>
#include <QPlainTextEdit>

#include <string>

#include <QPlainTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QTreeView>
#include <QAction>

class MainWindow : public QMainWindow {
public:
    MainWindow() = default;
    MainWindow(std::string &windowName);

    std::string getWindowName() const;
    void setWindowName(const std::string &windowName);

private:
    std::string m_windowName;

    QMenuBar* m_menuBar;

    QMenu* m_fileMenu;
    QMenu* editMenu;




    QTreeView* m_treeView;
    QPlainTextEdit* m_textEditor;



};
