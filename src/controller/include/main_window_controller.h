#ifndef __MAIN_WINDOW_CONTROLLER_H
#define __MAIN_WINDOW_CONTROLLER_H


class MainWindowModel;


class MainWindowController {
    public:
        MainWindowController();
        MainWindowController(MainWindowModel &model);

        void setMainWindowModel(MainWindowModel &model);

    private:
        MainWindowModel *m_model;
};


#endif
