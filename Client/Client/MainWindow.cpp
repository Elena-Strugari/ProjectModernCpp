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

//void MainWindow::firstWindow()
//{
//    /*qDebug() << "Initializing StartGameWindow...";
//    StartGameWindow* startGameWindow = new StartGameWindow(this);
//    qDebug() << "StartGameWindow initialized.";
//    connect(startGameWindow, &StartGameWindow::startGame, this, &MainWindow::onStartGameClicked);
//    qDebug() << "Connected StartGameWindow signals.";
//
//
//    setCentralWidget(startGameWindow);
//    qDebug() << "Set StartGameWindow as central widget.";
//
//    setWindowTitle("Start Window");
//
//    resize(800, 600);
//    qDebug() << "Connecting to server...";
//    ClientServer::connectServer();
//    qDebug() << "Connected to server.";*/
//    //......................................................................................
//    qDebug() << "Initializing first window...";
//    initializeBackground();
//    QWidget* centralWidget = new QWidget(this);
//    QVBoxLayout* layout = new QVBoxLayout(centralWidget);
//
//    QPushButton* signInButton = new QPushButton("Sign In", this);
//    QPushButton* signUpButton = new QPushButton("Sign Up", this);
//
//    QString buttonStyle =
//        "font-size: 18px; "
//        "color: white; "
//        "background-color: rgba(0, 0, 128, 200); "
//        "border: 2px solid white; "
//        "border-radius: 10px; "
//        "padding: 10px;";
//    signInButton->setStyleSheet(buttonStyle);
//    signUpButton->setStyleSheet(buttonStyle);
//
//    layout->addWidget(signInButton);
//    layout->addWidget(signUpButton);
//    layout->setAlignment(Qt::AlignCenter);
//    layout->setSpacing(20);
//
//    centralWidget->setLayout(layout);
//    setCentralWidget(centralWidget);
//
//    connect(signInButton, &QPushButton::clicked, this, &MainWindow::onSignInClicked);
//    connect(signUpButton, &QPushButton::clicked, this, &MainWindow::onSignUpClicked);
//
//    qDebug() << "First window initialized.";
//
//
//
//    //qDebug() << "Initializing StartGameWindow...";
//
//    //// Create and initialize StartGameWindow
//    //StartGameWindow* startGameWindow = new StartGameWindow(this);
//    //setCentralWidget(startGameWindow);
//
//    //// Connect the startGame signal to open LoginWindow
//    //connect(startGameWindow, &StartGameWindow::startGame, this, &MainWindow::onStartGameClicked);
//
//    //qDebug() << "StartGameWindow set as central widget.";
//}

//void MainWindow::onSignInClicked()
//{
//    //qDebug() << "Sign In button clicked!";
//    //LoginWindow* loginWindow = new LoginWindow(this); // Create LoginWindow
//    //loginWindow->show();
//    //this->close(); // Close the MainWindow
//    qDebug() << "Sign In button clicked!";
//    LoginWindow* loginWindow = new LoginWindow(); // Create LoginWindow (no parent to avoid closure issues)
//    loginWindow->show(); // Show the LoginWindow
//    this->hide();        // Hide the MainWindow temporarily
//
//    // Optional: Connect a signal to restore MainWindow when LoginWindow closes
//    connect(loginWindow, &QWidget::destroyed, this, &MainWindow::show);
//}

// Slot for "Sign Up" button
//void MainWindow::onSignUpClicked()
//{
//    //qDebug() << "Sign Up button clicked!";
//    //// Redirect to LoginWindow or other functionality for registration
//    //LoginWindow* loginWindow = new LoginWindow(this); // Can be changed to RegisterWindow
//    //loginWindow->show();
//    //this->close(); // Close the MainWindow
//    qDebug() << "Sign Up button clicked!";
//    LoginWindow* loginWindow = new LoginWindow(); // Create LoginWindow (no parent to avoid closure issues)
//    loginWindow->show(); // Show the LoginWindow
//    this->hide();        // Hide the MainWindow temporarily
//
//    // Optional: Connect a signal to restore MainWindow when LoginWindow closes
//    connect(loginWindow, &QWidget::destroyed, this, &MainWindow::show);
//}

//void MainWindow::onStartGameClicked() 
//{
//    qDebug() << "Start Game button pressed!";
//    LoginWindow* loginWindow = new LoginWindow();
//    loginWindow->show();
//    close();
//}

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

