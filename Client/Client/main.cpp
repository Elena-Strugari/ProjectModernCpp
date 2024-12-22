#include <QtWidgets/QApplication>
#include "Client.h"
#include "LoginWindow.h"
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return a.exec();
}

