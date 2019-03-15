#include <QMainWindow>
#include <QMenuBar>
#include <QPlainTextEdit>

#include <string>

#include "component_interface/component_interface.h"

class MainWindow : public QMainWindow, public ComponentInterface {
    public:
        MainWindow() = default;
        MainWindow(std::string &windowName);

        void update();

    private:
        std::string m_windowName;
};
