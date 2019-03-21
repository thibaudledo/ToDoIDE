#ifndef __MAIN_WINDOW_MODEL_H
#define __MAIN_WINDOW_MODEL_H

#include <QWidget>

#include <list>

class MainWindowModel {
    public:
        static MainWindowModel *getInstance();

        void addWidget(QWidget &widget);
        void removeWidget(QWidget &widget);

    private:
        MainWindowModel();

        static MainWindowModel *m_instance; 

        std::list<QWidget *> m_widgetList;
};

#endif
