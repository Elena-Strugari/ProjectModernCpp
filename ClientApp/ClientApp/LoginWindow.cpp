#include "LoginWindow.h"
#include "ClientApp.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);

    clientInput = new QLineEdit(this);
    clientInput->setPlaceholderText("Enter your name");

    loginButton = new QPushButton("Log In", this);
    registerButton = new QPushButton("Register", this);

    layout->addWidget(clientInput);
    layout->addWidget(loginButton);
    layout->addWidget(registerButton);

    setLayout(layout);

    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLogin);
    connect(registerButton, &QPushButton::clicked, this, &LoginWindow::onRegister);
}

void LoginWindow::onLogin() {
    std::string clientId = clientInput->text().toStdString();

    if (clientId.empty()) {
        QMessageBox::warning(this, "Error", "Please enter your name!");
        return;
    }

    ClientApp* clientApp = new ClientApp();
    clientApp->show();

    close();
}

void LoginWindow::onRegister() {
    std::string clientId = clientInput->text().toStdString();

    if (clientId.empty()) {
        QMessageBox::warning(this, "Error", "Please enter your name!");
        return;
    }

    QMessageBox::information(this, "Register", "Register functionality not implemented yet!");

    ClientApp* clientApp = new ClientApp();
    clientApp->show();

    close();
}
