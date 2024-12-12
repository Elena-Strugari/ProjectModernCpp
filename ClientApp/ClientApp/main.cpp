#include <QApplication>
#include "LoginWindow.h"
#include "MainWindow.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    //LoginWindow loginWindow;
    //loginWindow.show();
    MainWindow mainWindow;
    mainWindow.show();


    return app.exec();
}
