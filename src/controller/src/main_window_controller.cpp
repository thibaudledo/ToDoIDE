#include "main_window_controller.h"

#include "main_window_model.h"


MainWindowController::MainWindowController() {
    m_model = MainWindowModel::getInstance();
}


MainWindowController::MainWindowController(MainWindowModel &model)
  : m_model(&model) {

}


void MainWindowController::setMainWindowModel(MainWindowModel &model) {
    m_model = &model;
}
