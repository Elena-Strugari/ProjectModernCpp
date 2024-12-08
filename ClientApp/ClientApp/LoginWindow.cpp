#include "LoginWindow.h"
#include "ClientApp.h"

LoginWindow::LoginWindow(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);

    nameInput = new QLineEdit(this);
    nameInput->setPlaceholderText("Enter your name");

    loginButton = new QPushButton("Log In", this);

    layout->addWidget(nameInput);
    layout->addWidget(loginButton);

    setLayout(layout);

    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLogin);
}

void LoginWindow::onLogin() {
    QString name = nameInput->text();
    if (name.isEmpty()) {
        return; // Or show an error message
    }

    // Open the main window
    ClientApp* clientApp = new ClientApp();
    clientApp->show();

    // Close the login window
    close();
}
