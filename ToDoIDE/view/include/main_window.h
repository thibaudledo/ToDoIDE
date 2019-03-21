#include <QMainWindow>
#include <QMenuBar>
#include <QPlainTextEdit>

#include <string>

#include

class MainWindow : public QMainWindow {
    public:
        MainWindow() = default;
        MainWindow(std::string &windowName);

    private:
        std::string m_windowName;


};
