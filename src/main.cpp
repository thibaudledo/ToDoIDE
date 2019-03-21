#include <QApplication>

#include "main_window.h"
#include "filecontroller.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    FileController* controller = new FileController();

    MainWindow mW(controller);

    mW.show();

    return a.exec();
}
