#include "main_window_model.h"


MainWindowModel *MainWindowModel::m_instance = nullptr; 


MainWindowModel::MainWindowModel() {
    m_widgetList.clear();
}


MainWindowModel *MainWindowModel::getInstance() {
    if (!m_instance) {
        m_instance = new MainWindowModel();
    } 
      
    return m_instance;
}


void MainWindowModel::addWidget(QWidget &widget) {
    m_widgetList.push_back(&widget);
}


void MainWindowModel::removeWidget(QWidget &widget) {
    m_widgetList.remove(&widget);
}
