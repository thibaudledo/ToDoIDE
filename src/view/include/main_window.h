#include <QMainWindow>
#include <QMenuBar>
#include <QPlainTextEdit>

#include <string>



class MainWindow : public QMainWindow {
    public:
        MainWindow() = default;
        MainWindow(std::string &windowName);

    private:
        std::string m_windowName;


};
