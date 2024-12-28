#include "MainWindow.h"
#include "StartGameWindow.h"
#include "LoginWindow.h"


//Reconstructia lui MainWindow

//Am inlocuit toate aparitiile lui QPixmap cu QPalette
//Avem probleme la incarcarea din fisierul qrc a imaginilor...daca dam calea absoluta functioneaza.


MainWindow::MainWindow(QWidget* parent)
: QMainWindow(parent)
{
    qDebug() << "Current working directory:" << QDir::currentPath();
    qDebug() << "MainWindow: Constructor called.";

    setWindowTitle("Main Window");
    resize(800, 600);
    firstWindow();
}

void MainWindow::initializeBackground()
{
   // QImage testImage("D:\\Facultate\\Anul_2\\Semestrul_1\\Modern_C++\\ProjectModernCpp\\Client\\Client\\resources\\StartGame.jpg");
    QString resourcePath = ":/StartImage/resources/StartGame.jpg";
   //QString resourcePath = ":/PlayersImage/resources/Astronaut_1.png";
   // qDebug() << "Attempting to load image:" << resourcePath;
    QImage testImage(resourcePath);

    if (testImage.isNull())
    {
        qDebug() << "Failed to load image from resource!";
    }
    else
    {
        qDebug() << "Image loaded successfully from resource!";
    }


    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(testImage.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)));
    setPalette(palette);
    setAutoFillBackground(true);

}

MainWindow::~MainWindow()
{
    //EMPTY
}



void MainWindow::firstWindow()
{
    qDebug() << "Initializing StartGameWindow...";
    StartGameWindow* startGameWindow = new StartGameWindow(this);
    startGameWindow->initializeBackground();
    setCentralWidget(startGameWindow);
    connect(startGameWindow, &StartGameWindow::startGame, this, &MainWindow::onStartGameClicked);

    qDebug() << "StartGameWindow set as central widget.";
}

void MainWindow::onStartGameClicked()
{
    qDebug() << "Start Game action triggered!";
    LoginWindow* loginWindow = new LoginWindow();
    loginWindow->show();
    close(); 
}



//  TEST PENTRU PLAYER

//#include "MainWindow.h"
//#include <QVBoxLayout>
//#include <QDebug>
//
//MainWindow::MainWindow(QWidget* parent)
//    : QMainWindow(parent),
//    imageLabel(new QLabel(this))
//{
//    qDebug() << "Entering MainWindow constructor";
//    QWidget* centralWidget = new QWidget(this);
//    QVBoxLayout* layout = new QVBoxLayout(centralWidget);
//
//    layout->addWidget(imageLabel);
//    imageLabel->setAlignment(Qt::AlignCenter);
//    setCentralWidget(centralWidget);
//    element.DisplayBombImage(imageLabel);
//}
//
//MainWindow::~MainWindow() = default;

