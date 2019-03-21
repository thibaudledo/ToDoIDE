#include "main_window.h"

MainWindow::MainWindow(std::string &windowName)
    : m_windowName("ToDoIDE")
{
    m_windowName = windowName;

    m_menuBar = new QMenuBar(this);

    setMenuBar(m_menuBar);
}

std::string MainWindow::getWindowName() const
{
    return m_windowName;
}

void MainWindow::setWindowName(const std::string &windowName)
{
    m_windowName = windowName;
}

