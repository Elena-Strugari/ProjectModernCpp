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

//Main program
 


//#include <QApplication>
//#include "MainWindow.h"
//
//int main(int argc, char* argv[]) 
//{
//    qDebug() << "Sunt in main!";
//
//    QApplication app(argc, argv); 
//
//    MainWindow mainWindow;
//    qDebug() << "Sunt imediat dupa initializarea lui MainWindow!";
//    qDebug() << "Afisez mainWindow!";
//    mainWindow.show();
//
//    return app.exec();
//}


//Main pentru testarea imaginilor

//Conform experimentului, imaginile locale sunt incarcate corect de catre program, pe cand imaginile din fisierul cu resurse nu sunt recunoscute.
//Am incercat sa verific daca fisierul qrc a fost integrat in resursele QT, dar nu am ajuns inca la o concluzie.        Semnat Ale.


//#include <QApplication>
//#include <QLabel>
//#include <QImage>
//#include <QDebug>
//
//int main(int argc, char* argv[])
//{
//    QApplication app(argc, argv);
//
//    //QString resourcePath = ":/StartImage/resources/StartGame.jpg";
//    QString resourcePath = ":/StartImage/StartGame.jpg";
//    QImage image(resourcePath);
//
//    //Testare imagine locala
//    //QImage image("D:\\Facultate\\Anul_2\\Semestrul_1\\Modern_C++\\ProjectModernCpp\\Client\\Client\\resources\\StartGame.jpg");
//    if (image.isNull()) 
//    {
//        qDebug() << "Failed to load image!";
//        return -1;
//    }
//
//    QWidget window;
//    window.resize(800, 600);
//    QPalette palette;
//    palette.setBrush(QPalette::Window, QBrush(image.scaled(window.size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)));
//    window.setPalette(palette);
//    window.setAutoFillBackground(true);
//
//    window.show();
//
//    return app.exec();
//}

//Main pentru testarea hartii

//#include "MainWindow.h"
//#include "ClientMap.h"
//#include <QApplication>
//
//int main(int argc, char* argv[])
//{
//    QApplication app(argc, argv);
//
//    MainWindow mainWindow;
//    ClientMap clientMap(10, 10);
//
//    clientMap.InitializeTestMap();
//
//    mainWindow.DisplayMap(clientMap);
//    mainWindow.show();
//
//    return app.exec();
//}



//Server

//#include "ClientServer.h"
//#include <iostream>
//
//int main() {
//
//	ClientServer::connectServer();
//
//	return 0;
//}

//#include "MainWindow.h"
//#include <QApplication>
//
//
//int main(int argc, char* argv[])
//{
//    QApplication app(argc, argv);
//
//    MainWindow mainWindow;
//    mainWindow.show();
//
//    return app.exec();
//}
// 
// 
//#include <QApplication>
//#include "ControlChoiceWindow.h"
//#include <QDebug>
//
//int main(int argc, char* argv[])
//{
//    QApplication app(argc, argv);
//
//    QString clientId = "TestUser";
//
//    // Creăm fereastra ControlChoiceWindow
//    ControlChoiceWindow* controlWindow = new ControlChoiceWindow(clientId);
//
//    // Conectăm semnalul controlsSet pentru a verifica dacă controalele sunt salvate corect
//    QObject::connect(controlWindow, &ControlChoiceWindow::ControlsSet, [](const QMap<QString, QString>& controls) {
//        qDebug() << "Controls saved:" << controls;
//        });
//
//    controlWindow->show();
//
//    return app.exec();
//}
#include <QApplication>
#include <QDebug>
#include "CreateOrJoinGameWindow.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // Creează instanța ferestrei CreateOrJoinGameWindow
    CreateOrJoinGameWindow* window = new CreateOrJoinGameWindow();

    // Conectează semnalele pentru a testa acțiunile butoanelor
    QObject::connect(window, &CreateOrJoinGameWindow::Generate, []() {
        qDebug() << "Generate Code button clicked.";
        });

    QObject::connect(window, &CreateOrJoinGameWindow::CheckCode, []() {
        qDebug() << "Check Code button clicked.";
        });

    // Afișează fereastra
    window->show();

    return app.exec();
}




