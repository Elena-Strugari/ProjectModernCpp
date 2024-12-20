﻿//#include "MainWindow.h"
//#include "StartGame.h"
//#include "LoginWindow.h"
//
//MainWindow::MainWindow(QWidget* parent)
//    : QMainWindow(parent) {
//   
//    firstWindow();
//}
//
//MainWindow::~MainWindow() {}
//
//void MainWindow::firstWindow() {
//    StartGame* startGameWindow = new StartGame(this);
//
//    connect(startGameWindow, &StartGame::startGame, this, &MainWindow::onStartGameClicked);
//
//    setCentralWidget(startGameWindow);
//    setWindowTitle("Start Window");
//    resize(800, 600);
//
//    ClientServer::connectServer();
//}
//
//void MainWindow::onStartGameClicked() {
//    LoginWindow* loginWindow = new LoginWindow();
//    loginWindow->show();
//
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

//  TEST PENTRU PLAYER

#include "MainWindow.h"
#include <QVBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
    codeInput(new QLineEdit(this)),
    displayButton(new QPushButton("Afișează Imagine", this)),
    imageLabel(new QLabel(this))
{
    // Set up layout
    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);

    layout->addWidget(new QLabel("Introduceți codul imaginii:", this));
    layout->addWidget(codeInput);
    layout->addWidget(displayButton);
    layout->addWidget(imageLabel);

    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setText("Imaginea va apărea aici...");
    setCentralWidget(centralWidget);

    // Connect button to slot
    connect(displayButton, &QPushButton::clicked, this, &MainWindow::OnDisplayButtonClicked);
}

MainWindow::~MainWindow() = default;

void MainWindow::OnDisplayButtonClicked()
{
    bool ok;
    int code = codeInput->text().toInt(&ok);

    if (!ok)
    {
        qDebug() << "Cod invalid introdus.";
        imageLabel->setText("Cod invalid!");
        return;
    }

    playerWindow.DisplayPlayerImage(code, imageLabel);
}

