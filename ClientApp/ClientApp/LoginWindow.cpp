#include "LoginWindow.h"
#include "ClientApp.h"

LoginWindow::LoginWindow(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);

    clientInput = new QLineEdit(this);
    clientInput->setPlaceholderText("Enter your name");

    loginButton = new QPushButton("Log In", this);

    layout->addWidget(clientInput);
    layout->addWidget(loginButton);

    setLayout(layout);

    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLogin);
}

void LoginWindow::onLogin() {
    std::string clientId = clientInput->text().toStdString();
    //if (clientId) {
    //    return; // Or show an error message
    //}
    //create route for login in server and client 


    // Open the main window
    ClientApp* clientApp = new ClientApp();
    clientApp->show();

    // Close the login window
    close();
}
