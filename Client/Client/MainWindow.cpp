//MainWindow pentru ferestrele principale.

#include "MainWindow.h"
#include "StartGameWindow.h"
#include "ControlChoiceWindow.h"
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
    //QImage testImage("D:\\Facultate\\Anul_2\\Semestrul_1\\Modern_C++\\ProjectModernCpp\\Client\\Client\\resources\\StartGame.jpg");
    QString resourcePath = ":/StartImage/resources/StartGame.jpg";
    //QString resourcePath = ":/PlayersImage/resources/Astronaut_1.png";
    //qDebug() << "Attempting to load image:" << resourcePath;
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

//................................................................................................................................................

////  TEST PENTRU PLAYER
//
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
//    imageLabel->resize(150, 150);
//    imageLabel->setAlignment(Qt::AlignCenter);
//    layout->addWidget(imageLabel);
//    setCentralWidget(centralWidget);
//   //element.DisplayBonusLifeImage(imageLabel);
//   element.DisplayBombImage(imageLabel);
//   //element.DisplayBorderImage(imageLabel);
//   //element.DisplayWallImage(2, imageLabel);
//   //element.DisplayPlayerImage(44, imageLabel);
//}
//
//MainWindow::~MainWindow() = default;
//

//...............................................................................................................................................

//MainWindow test pentru afisarea hartii.
//#include "MainWindow.h"
//
//MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) 
//{
//    centralWidget = new QWidget(this);
//    gridLayout = new QGridLayout(centralWidget);
//    centralWidget->setLayout(gridLayout);
//    setCentralWidget(centralWidget);
//}
//
//void MainWindow::DisplayMap(const ClientMap& clientMap) 
//{
//    // Clear existing layout
//    while (QLayoutItem* item = gridLayout->takeAt(0)) 
//    {
//        delete item->widget(); 
//        delete item;           // Delete the layout item
//    }
//
//    // Iterate through the map and add widgets
//    for (int row = 0; row < clientMap.GetRows(); ++row) 
//    {
//        for (int col = 0; col < clientMap.GetColumns(); ++col) 
//        {
//            const MapCell& cell = clientMap.GetCell(row, col);
//            QWidget* cellWidget = new QWidget(this);
//
//            
//            switch (cell.GetType()) 
//            {
//            case MapCell::CellType::Wall:
//                SetCellBackground(cellWidget, ":/resources/Asteroid.png");
//                break;
//            case MapCell::CellType::DestructibleWall:
//                SetCellBackground(cellWidget, ":/resources/praf1.png");
//                break;
//            case MapCell::CellType::Tank:
//                SetCellBackground(cellWidget, ":/resources/Astronaut_4_Right.png");
//                break;
//            case MapCell::CellType::Empty:
//                SetCellBackground(cellWidget, ":/resources/StartGame.jpg");
//                break;
//            default:
//                SetCellBackground(cellWidget, ":/resources/StartGame.jpg");
//                break;
//            }
//
//            gridLayout->addWidget(cellWidget, row, col);
//        }
//    }
//}
//
//void MainWindow::SetCellBackground(QWidget* cellWidget, const QString& imagePath) 
//{
//    QPalette palette;
//    QImage image(imagePath);
//    palette.setBrush(QPalette::Window, QBrush(image));
//    cellWidget->setAutoFillBackground(true);
//    cellWidget->setPalette(palette);
//}