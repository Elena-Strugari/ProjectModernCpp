#include <QtWidgets/QApplication>
#include "Client.h"
#include "LoginWindow.h"
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    qDebug() << "Sunt in main!!!";
    QApplication a(argc, argv);
    qDebug() << "Sunt imediat dupa instantierea lui QAplication!!!!!";

    //Programul crapa imediat ce insearca sa instantieze MainWindow. Nici nu intra in constructor! 

    /*MainWindow mainWindow;
    qDebug() << "Sunt dupa instantierea mui mainwindow";
    mainWindow.show();
    qDebug() << "S-a incercat afisarea lui mainwindow";*/
    return a.exec();
}

