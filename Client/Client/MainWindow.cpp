#include "MainWindow.h"
#include "StartGameWindow.h"
#include "LoginWindow.h"

//MainWindow::MainWindow(QWidget* parent)
//    : QMainWindow(parent)
//{
//   /* qDebug() << "Initializing MainWindow...";
//    firstWindow();*/
//    setWindowTitle("Main Window");
//    resize(800, 600); // Set an initial window size
//    qDebug() << "MainWindow initialized.";
//}


//MainWindow::MainWindow(QWidget* parent)
//    : QMainWindow(parent)
//{
//    qDebug() << "MainWindow: Constructor called.";
//
//    QWidget* centralWidget = new QWidget(this);
//    QVBoxLayout* layout = new QVBoxLayout(centralWidget);
//
//    QLabel* placeholderLabel = new QLabel("Welcome to Main Window", centralWidget);
//    placeholderLabel->setAlignment(Qt::AlignCenter);
//    layout->addWidget(placeholderLabel);
//
//    centralWidget->setLayout(layout);
//    setCentralWidget(centralWidget);
//
//    setWindowTitle("Main Window");
//    resize(800, 600);
//    qDebug() << "MainWindow: Central widget added.";
//}
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    qDebug() << "MainWindow: Constructor called.";

    setWindowTitle("Main Window");
    resize(800, 600); // Set an initial window size
    initializeBackground(); // Set the background image

    // Add central widget (for testing purposes)
    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);

    QLabel* placeholderLabel = new QLabel("Welcome to Main Window", centralWidget);
    placeholderLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(placeholderLabel);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    qDebug() << "MainWindow: Central widget added.";
}

void MainWindow::initializeBackground() 
{
    // Load the background image
    //QPixmap pixmap(":/StartImage/resources/StartGame.jpg");
//    if (pixmap.isNull()) 
//    {
//        qDebug() << "Failed to load image!";
//    }
//    else {
//        qDebug() << "Image loaded successfully!";
//    }
//    if (!pixmap.isNull())
//    {
//        QPalette palette;
//        palette.setBrush(QPalette::Window, pixmap.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
//        setAutoFillBackground(true);
//        setPalette(palette);
//        //backgroundPixmap = pixmap; 
//    }
//    else 
//    {
//        qDebug() << "Failed to load background image.";
//    }
}

MainWindow::~MainWindow()
{
    //EMPTY
}

void MainWindow::firstWindow()
{
    qDebug() << "Initializing StartGameWindow...";
    StartGameWindow* startGameWindow = new StartGameWindow(this);
    qDebug() << "StartGameWindow initialized.";
    connect(startGameWindow, &StartGameWindow::startGame, this, &MainWindow::onStartGameClicked);
    qDebug() << "Connected StartGameWindow signals.";


    setCentralWidget(startGameWindow);
    qDebug() << "Set StartGameWindow as central widget.";

    setWindowTitle("Start Window");

    resize(800, 600);
    qDebug() << "Connecting to server...";
    ClientServer::connectServer();
    qDebug() << "Connected to server.";
}

void MainWindow::onStartGameClicked() {
    LoginWindow* loginWindow = new LoginWindow();
    loginWindow->show();

    close();
}



//#include "MainWindow.h"
//#include <QDebug>
//
//MainWindow::MainWindow(QWidget* parent)
//    : QMainWindow(parent), map(new ClientMap(this)) {
//    qDebug() << "Initializing MainWindow...";
//    // Create and initialize the map
//    map->Initialize(10, 10); // Example: 10x10 grid
//    qDebug() << "Map initialized.";
//
//    // Set the map as the central widget
//    setCentralWidget(map);
//    qDebug() << "Map set as central widget.";
//}
//
//MainWindow::~MainWindow() {
//    qDebug() << "Destroying MainWindow...";
//    // No need to delete map because it has MainWindow as a parent
//}






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

