#include <QApplication>
#include "ClientMap.h"
#include "MainWindow.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    
    MainWindow mainWindow;
    mainWindow.show();


    return app.exec();
}
