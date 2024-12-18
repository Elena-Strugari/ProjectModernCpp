#include "MainWindow.h"
#include "StartGame.h"
#include "LoginWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent) {
   
    firstWindow();
}

MainWindow::~MainWindow() {}

void MainWindow::firstWindow() {
    StartGame* startGameWindow = new StartGame(this);

    connect(startGameWindow, &StartGame::startGame, this, &MainWindow::onStartGameClicked);

    setCentralWidget(startGameWindow);
    setWindowTitle("Start Window");
    resize(800, 600);

    ClientServer::connectServer();
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
