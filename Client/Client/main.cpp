//#include <QtWidgets/QApplication>
//#include "Client.h"
//#include "LoginWindow.h"
//#include "MainWindow.h"
//
//int main(int argc, char *argv[])
//{
//    qDebug() << "Sunt in main!!!";
//    QApplication a(argc, argv);
//    qDebug() << "Sunt imediat dupa instantierea lui QAplication!!!!!";
//
//    //Programul crapa imediat ce insearca sa instantieze MainWindow. Nici nu intra in constructor! 
//
//    MainWindow mainWindow;
//    qDebug() << "Sunt dupa instantierea lui mainwindow";
//    mainWindow.show();
//    //qDebug() << "S-a incercat afisarea lui mainwindow";
//    return a.exec();
//}
//
#include <QApplication>
#include "MainWindow.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv); // QApplication must be the first GUI object
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
