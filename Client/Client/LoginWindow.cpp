//#pragma once 
//#include "LoginWindow.h"
//#include "ClientServer.h"
//#include "Client.h"
//#include <QMessageBox>
//#include <QPixmap>
//#include <QVBoxLayout>
//#include <QPalette>
//
//
////LoginWindow::LoginWindow(QWidget* parent)
////    : QWidget(parent), promptLabel(new QLabel("Introduceți numele dumneavoastră:", this)) {
////    // Imaginea de fundal
////    QPixmap pixmap(":/startImage/resources/StartGame.jpg");
////    if (!pixmap.isNull()) {
////        QPalette palette;
////        palette.setBrush(QPalette::Window, pixmap.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
////        setAutoFillBackground(true);
////        setPalette(palette);
////    }
////
////    // Stilizarea promptului
////    promptLabel->setAlignment(Qt::AlignCenter);
////    promptLabel->setStyleSheet(
////        "font-size: 18px; "
////        "color: white; "
////        "font-weight: bold;"
////    );
////
////    // Caseta de text pentru nume
////    clientInput = new QLineEdit(this);
////    clientInput->setPlaceholderText("Numele dvs.");
////    clientInput->setStyleSheet(
////        "font-size: 16px; "
////        "color: black; " // Textul devine negru
////        "padding: 5px; "
////        "border: 2px solid white; "
////        "border-radius: 5px; "
////        "background-color: rgba(255, 255, 255, 200);"
////    );
////
////    // Butoanele "Log In" și "Register"
////    loginButton = new QPushButton("Log In", this);
////    registerButton = new QPushButton("Register", this);
////
////    QString buttonStyle =
////        "font-size: 18px; "
////        "color: white; "
////        "background-color: rgba(0, 0, 128, 200); "
////        "border: 2px solid white; "
////        "border-radius: 10px; "
////        "padding: 5px;";
////    loginButton->setStyleSheet(buttonStyle);
////    registerButton->setStyleSheet(buttonStyle);
////
////    // Layout-ul pentru prompt, casetă de text și butoane
////    QVBoxLayout* contentLayout = new QVBoxLayout();
////    contentLayout->addWidget(promptLabel);
////    contentLayout->addWidget(clientInput);
////    contentLayout->addWidget(loginButton);
////    contentLayout->addWidget(registerButton);
////    contentLayout->setAlignment(promptLabel, Qt::AlignCenter);
////    contentLayout->setAlignment(clientInput, Qt::AlignCenter);
////    contentLayout->setAlignment(loginButton, Qt::AlignCenter);
////    contentLayout->setAlignment(registerButton, Qt::AlignCenter);
////    contentLayout->setSpacing(10); // Ajustează spațiul dintre butoane
////
////    // Layout principal
////    QVBoxLayout* mainLayout = new QVBoxLayout(this);
////    mainLayout->addLayout(contentLayout);
////    setLayout(mainLayout);
////
////    // Conectăm butoanele
////    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLogin);
////    connect(registerButton, &QPushButton::clicked, this, &LoginWindow::onRegister);
////
////    setWindowTitle("Logare");
////    resize(800, 600);
////}
//LoginWindow::LoginWindow(QWidget* parent)
//    : QWidget(parent)
//    , promptLabel(new QLabel("Introduceți numele dumneavoastră:", this)) 
//    , imageLabel(nullptr)
//    , textLabel(nullptr)
//{
//    qDebug() << "LoginWindow constructor called.";
//
//    // Stilizarea promptului
//    promptLabel->setAlignment(Qt::AlignCenter);
//    promptLabel->setStyleSheet(
//        "font-size: 18px; "
//        "color: white; "
//        "font-weight: bold;"
//    );
//
//    // Caseta de text pentru nume
//    clientInput = new QLineEdit(this);
//    clientInput->setPlaceholderText("Numele dvs.");
//    clientInput->setStyleSheet(
//        "font-size: 16px; "
//        "color: black; " // Textul devine negru
//        "padding: 5px; "
//        "border: 2px solid white; "
//        "border-radius: 5px; "
//        "background-color: rgba(255, 255, 255, 200);"
//    );
//
//    // Butoanele "Log In" și "Register"
//    loginButton = new QPushButton("Log In", this);
//    registerButton = new QPushButton("Register", this);
//
//    QString buttonStyle =
//        "font-size: 18px; "
//        "color: white; "
//        "background-color: rgba(0, 0, 128, 200); "
//        "border: 2px solid white; "
//        "border-radius: 10px; "
//        "padding: 5px;";
//    loginButton->setStyleSheet(buttonStyle);
//    registerButton->setStyleSheet(buttonStyle);
//
//    // Layout-ul pentru prompt, casetă de text și butoane
//    QVBoxLayout* contentLayout = new QVBoxLayout();
//    contentLayout->addWidget(promptLabel);
//    contentLayout->addWidget(clientInput);
//    contentLayout->addWidget(loginButton);
//    contentLayout->addWidget(registerButton);
//    contentLayout->setAlignment(promptLabel, Qt::AlignCenter);
//    contentLayout->setAlignment(clientInput, Qt::AlignCenter);
//    contentLayout->setAlignment(loginButton, Qt::AlignCenter);
//    contentLayout->setAlignment(registerButton, Qt::AlignCenter);
//    contentLayout->setSpacing(10); // Ajustează spațiul dintre butoane
//
//    // Layout principal
//    QVBoxLayout* mainLayout = new QVBoxLayout(this);
//    mainLayout->addLayout(contentLayout);
//    setLayout(mainLayout);
//
//    // Conectăm butoanele
//    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLogin);
//    connect(registerButton, &QPushButton::clicked, this, &LoginWindow::onRegister);
//
//    setWindowTitle("Logare");
//    resize(800, 600);
//}
//
////Initializarea background-ului dpa constructor
//
//void LoginWindow::initializeBackground() 
//{
//    QPixmap pixmap(":/StartImage/resources/StartGame.jpg");
//    if (!pixmap.isNull()) {
//        QPalette palette;
//        palette.setBrush(QPalette::Window, pixmap.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
//        setAutoFillBackground(true);
//        setPalette(palette);
//    }
//}
//
//void LoginWindow::resizeEvent(QResizeEvent* event) 
//{
//    QPixmap pixmap(":/StartImage/resources/StartGame.jpg");
//    if (!pixmap.isNull()) 
//    {
//        QPalette palette;
//        palette.setBrush(QPalette::Window, pixmap.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
//        setPalette(palette);
//    }
//    QWidget::resizeEvent(event);
//}
//
//void LoginWindow::onLogin() 
//{
//    QString clientId = clientInput->text().trimmed();
//
//    if (clientId.isEmpty())
//    {
//        QMessageBox::warning(this, "Eroare", "Vă rugăm să introduceți un nume!");
//        return;
//    }
//    //// Creează fereastra Client și o afișează
//    Client* client = new Client();
//    client->setWindowTitle("Game");
//    client->show();
//
//    close(); // Închidem fereastra curentă
//
//    // Apelăm funcția login din ClientServer
//    /*std::string stringId = clientId.toStdString();
//    if (ClientServer::loginClient(stringId)) {
//        Client* Client = new Client();
//        Client->setWindowTitle("Game");
//        Client->show();
//
//        close();
//    }
//    else {
//        QMessageBox::warning(this, "Login Failed", "ID-ul introdus nu este valid sau serverul nu este disponibil.");
//    }*/
//}
//
//void LoginWindow::onRegister() 
//{
//    QString clientId = clientInput->text().trimmed();
//
//    if (clientId.isEmpty())
//    {
//        QMessageBox::warning(this, "Eroare", "Vă rugăm să introduceți un nume!");
//        return;
//    }
//
//    // Creează fereastra Client și o afișează
//    Client* client = new Client();
//    client->setWindowTitle("Game");
//    client->show();
//
//    close();
//
//    //// Apelăm funcția registerClient din ClientServer
//    //if (ClientServer::registerClient(clientId.toStdString())) {
//    //    qDebug() << "Registration successful";
//
//    //    // Creează fereastra Client și o afișează
//    //    Client* Client = new Client();
//    //    Client->setWindowTitle("Game");
//    //    Client->show();
//
//    //    close(); // Închidem fereastra curentă
//    //}
//    //else {
//    //    QMessageBox::warning(this, "Registration Failed", "Înregistrarea nu a reușit. Verificați serverul.");
//    //}
//}


/*

#pragma once
#include "LoginWindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QVBoxLayout>
#include <QPalette>

LoginWindow::LoginWindow(QWidget* parent)
    : QWidget(parent)
    , promptLabel(new QLabel("Introduceți numele dumneavoastră:", this))
    , imageLabel(nullptr)
    , textLabel(nullptr)
{
    qDebug() << "LoginWindow constructor called.";

    // Styling the prompt label
    promptLabel->setAlignment(Qt::AlignCenter);
    promptLabel->setStyleSheet(
        "font-size: 18px; "
        "color: white; "
        "font-weight: bold;"
    );

    // Input field for client name
    clientInput = new QLineEdit(this);
    clientInput->setPlaceholderText("Numele dvs.");
    clientInput->setStyleSheet(
        "font-size: 16px; "
        "color: black; " // Black text color
        "padding: 5px; "
        "border: 2px solid white; "
        "border-radius: 5px; "
        "background-color: rgba(255, 255, 255, 200);"
    );

    // Buttons for "Log In" and "Register"
    loginButton = new QPushButton("Log In", this);
    registerButton = new QPushButton("Register", this);

    QString buttonStyle =
        "font-size: 18px; "
        "color: white; "
        "background-color: rgba(0, 0, 128, 200); "
        "border: 2px solid white; "
        "border-radius: 10px; "
        "padding: 5px;";
    loginButton->setStyleSheet(buttonStyle);
    registerButton->setStyleSheet(buttonStyle);

    // Layout for prompt, input, and buttons
    QVBoxLayout* contentLayout = new QVBoxLayout();
    contentLayout->addWidget(promptLabel);

    contentLayout->addWidget(clientInput);
    contentLayout->addWidget(loginButton);
    contentLayout->addWidget(registerButton);
    contentLayout->setAlignment(promptLabel, Qt::AlignCenter);
    contentLayout->setAlignment(clientInput, Qt::AlignCenter);
    contentLayout->setAlignment(loginButton, Qt::AlignCenter);
    contentLayout->setAlignment(registerButton, Qt::AlignCenter);
    contentLayout->setSpacing(10); // Adjust spacing between elements

    // Main layout
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(contentLayout);
    setLayout(mainLayout);

    // Connect the buttons
    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLogin);
    connect(registerButton, &QPushButton::clicked, this, &LoginWindow::onRegister);

    setWindowTitle("Logare");
    resize(800, 600);

    // Commented out background initialization for now
    // initializeBackground();
}

void LoginWindow::initializeBackground()
{
    // Commented out for testing
    // QPixmap pixmap(":/StartImage/resources/StartGame.jpg");
    // if (!pixmap.isNull()) {
    //     QPalette palette;
    //     palette.setBrush(QPalette::Window, pixmap.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
    //     setAutoFillBackground(true);
    //     setPalette(palette);
    // }
}

void LoginWindow::resizeEvent(QResizeEvent* event)
{
    // Commented out for testing
    // QPixmap pixmap(":/StartImage/resources/StartGame.jpg");
    // if (!pixmap.isNull()) {
    //     QPalette palette;
    //     palette.setBrush(QPalette::Window, pixmap.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
    //     setPalette(palette);
    // }
    QWidget::resizeEvent(event);
}

void LoginWindow::onLogin()
{
    QString clientId = clientInput->text().trimmed();

    if (clientId.isEmpty())
    {
        QMessageBox::warning(this, "Eroare", "Vă rugăm să introduceți un nume!");
        return;
    }

    // Simplified logic for testing
    qDebug() << "Login clicked with name:" << clientId;
}

void LoginWindow::onRegister()
{
    QString clientId = clientInput->text().trimmed();

    if (clientId.isEmpty())
    {
        QMessageBox::warning(this, "Eroare", "Vă rugăm să introduceți un nume!");
        return;
    }

    // Simplified logic for testing
    qDebug() << "Register clicked with name:" << clientId;
}



*/


//Incercarea 201...

//#include "LoginWindow.h"
//#include "ClientServer.h"
//#include "Client.h"
//#include <QMessageBox>
//#include <QVBoxLayout>
//#include <QPalette>
//
//// Constructor
//LoginWindow::LoginWindow(QWidget* parent)
//    : QWidget(parent)
//    , promptLabel(new QLabel("Introduceți numele dumneavoastră:", this))
//    , clientInput(new QLineEdit(this))
//    , loginButton(new QPushButton("Log In", this))
//    , registerButton(new QPushButton("Register", this))
//{
//    qDebug() << "LoginWindow constructor called.";
//
//    // Styling the prompt label
//    promptLabel->setAlignment(Qt::AlignCenter);
//    promptLabel->setStyleSheet(
//        "font-size: 18px; "
//        "color: white; "
//        "font-weight: bold;"
//    );
//
//    // Styling the client input
//    clientInput->setPlaceholderText("Numele dvs.");
//    clientInput->setStyleSheet(
//        "font-size: 16px; "
//        "color: black; "
//        "padding: 5px; "
//        "border: 2px solid white; "
//        "border-radius: 5px; "
//        "background-color: rgba(255, 255, 255, 200);"
//    );
//
//    // Styling the buttons
//    QString buttonStyle =
//        "font-size: 18px; "
//        "color: white; "
//        "background-color: rgba(0, 0, 128, 200); "
//        "border: 2px solid white; "
//        "border-radius: 10px; "
//        "padding: 5px;";
//    loginButton->setStyleSheet(buttonStyle);
//    registerButton->setStyleSheet(buttonStyle);
//
//    // Layout for content
//    QVBoxLayout* contentLayout = new QVBoxLayout();
//    contentLayout->addWidget(promptLabel);
//    contentLayout->addWidget(clientInput);
//    contentLayout->addWidget(loginButton);
//    contentLayout->addWidget(registerButton);
//    contentLayout->setAlignment(Qt::AlignCenter);
//    contentLayout->setSpacing(10);
//
//    // Main layout
//    QVBoxLayout* mainLayout = new QVBoxLayout(this);
//    mainLayout->addLayout(contentLayout);
//    setLayout(mainLayout);
//
//    // Connect signals
//    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLogin);
//    connect(registerButton, &QPushButton::clicked, this, &LoginWindow::onRegister);
//
//    setWindowTitle("Logare");
//    resize(800, 600);
//
//    // Commented out background initialization for debugging
//    // initializeBackground();
//}
//
//// Method to initialize background
//void LoginWindow::initializeBackground()
//{
//    // Commented out QPixmap initialization for debugging
//    // QPixmap pixmap(":/StartImage/resources/StartGame.jpg");
//    // if (!pixmap.isNull()) {
//    //     QPalette palette;
//    //     palette.setBrush(QPalette::Window, pixmap.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
//    //     setAutoFillBackground(true);
//    //     setPalette(palette);
//    // }
//}
//
//// Resize event
//void LoginWindow::resizeEvent(QResizeEvent* event)
//{
//    // Commented out QPixmap initialization for debugging
//    // QPixmap pixmap(":/StartImage/resources/StartGame.jpg");
//    // if (!pixmap.isNull()) {
//    //     QPalette palette;
//    //     palette.setBrush(QPalette::Window, pixmap.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
//    //     setPalette(palette);
//    // }
//    QWidget::resizeEvent(event);
//}
//
//// Slot for login button
//void LoginWindow::onLogin()
//{
//    QString clientId = clientInput->text().trimmed();
//
//    if (clientId.isEmpty())
//    {
//        QMessageBox::warning(this, "Eroare", "Vă rugăm să introduceți un nume!");
//        return;
//    }
//
//    // Debugging login action
//    qDebug() << "Login clicked with name:" << clientId;
//}
//
//// Slot for register button
//void LoginWindow::onRegister()
//{
//    QString clientId = clientInput->text().trimmed();
//
//    if (clientId.isEmpty())
//    {
//        QMessageBox::warning(this, "Eroare", "Vă rugăm să introduceți un nume!");
//        return;
//    }
//
//    // Debugging register action
//    qDebug() << "Register clicked with name:" << clientId;
//}


//Incercarea 502

#include "LoginWindow.h"
#include "ClientServer.h"
#include "Client.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QPalette>
#include <QImage>

// Constructor
LoginWindow::LoginWindow(QWidget* parent)
    : QWidget(parent)
    , promptLabel(new QLabel("Introduceți numele dumneavoastră:", this))
    , clientInput(new QLineEdit(this))
    , loginButton(new QPushButton("Log In", this))
    , registerButton(new QPushButton("Register", this))
{
    qDebug() << "LoginWindow constructor called.";

    // Styling the prompt label
    promptLabel->setAlignment(Qt::AlignCenter);
    promptLabel->setStyleSheet(
        "font-size: 18px; "
        "color: white; "
        "font-weight: bold;"
    );

    // Styling the client input
    clientInput->setPlaceholderText("Numele dvs.");
    clientInput->setStyleSheet(
        "font-size: 16px; "
        "color: black; "
        "padding: 5px; "
        "border: 2px solid white; "
        "border-radius: 5px; "
        "background-color: rgba(255, 255, 255, 200);"
    );

    // Styling the buttons
    QString buttonStyle =
        "font-size: 18px; "
        "color: white; "
        "background-color: rgba(0, 0, 128, 200); "
        "border: 2px solid white; "
        "border-radius: 10px; "
        "padding: 5px;";
    loginButton->setStyleSheet(buttonStyle);
    registerButton->setStyleSheet(buttonStyle);

    // Layout for content
    QVBoxLayout* contentLayout = new QVBoxLayout();
    contentLayout->addWidget(promptLabel);
    contentLayout->addWidget(clientInput);
    contentLayout->addWidget(loginButton);
    contentLayout->addWidget(registerButton);
    contentLayout->setAlignment(Qt::AlignCenter);
    contentLayout->setSpacing(10);

    // Main layout
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(contentLayout);
    setLayout(mainLayout);

    // Connect signals
    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLogin);
    connect(registerButton, &QPushButton::clicked, this, &LoginWindow::onRegister);

    setWindowTitle("Logare");
    resize(800, 600);

    // Initialize background using QPalette
    initializeBackground();
}

// Method to initialize background
void LoginWindow::initializeBackground()
{
    QImage image(":/StartImage/resources/StartGame.jpg"); // Replace with your actual image path
    if (image.isNull()) {
        qDebug() << "Failed to load background image!";
        return;
    }

    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(image.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)));
    setPalette(palette);
    setAutoFillBackground(true);
}

// Resize event
void LoginWindow::resizeEvent(QResizeEvent* event)
{
    QImage image(":/StartImage/resources/StartGame.jpg"); // Replace with your actual image path
    if (!image.isNull()) {
        QPalette palette;
        palette.setBrush(QPalette::Window, QBrush(image.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)));
        setPalette(palette);
    }
    QWidget::resizeEvent(event);
}

// Slot for login button
void LoginWindow::onLogin()
{
    QString clientId = clientInput->text().trimmed();

    if (clientId.isEmpty())
    {
        QMessageBox::warning(this, "Eroare", "Vă rugăm să introduceți un nume!");
        return;
    }

    // Debugging login action
    qDebug() << "Login clicked with name:" << clientId;
}

// Slot for register button
void LoginWindow::onRegister()
{
    QString clientId = clientInput->text().trimmed();

    if (clientId.isEmpty())
    {
        QMessageBox::warning(this, "Eroare", "Vă rugăm să introduceți un nume!");
        return;
    }

    // Debugging register action
    qDebug() << "Register clicked with name:" << clientId;
}
