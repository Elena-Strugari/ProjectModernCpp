#include "LoginWindow.h"
#include "ClientApp.h"
#include <QMessageBox>
#include <QPixmap>
#include <QVBoxLayout>
#include <QPalette>

LoginWindow::LoginWindow(QWidget* parent)
    : QWidget(parent), promptLabel(new QLabel("Introduceți numele dumneavoastră:", this)) {
    // Imaginea de fundal
    QPixmap pixmap(":/startImage/resources/StartGame.jpg");
    if (!pixmap.isNull()) {
        QPalette palette;
        palette.setBrush(QPalette::Window, pixmap.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
        setAutoFillBackground(true);
        setPalette(palette);
    }

    // Stilizarea promptului
    promptLabel->setAlignment(Qt::AlignCenter);
    promptLabel->setStyleSheet(
        "font-size: 18px; "
        "color: white; "
        "font-weight: bold;"
    );

    // Caseta de text pentru nume
    clientInput = new QLineEdit(this);
    clientInput->setPlaceholderText("Numele dvs.");
    clientInput->setStyleSheet(
        "font-size: 16px; "
        "color: black; " // Textul devine negru
        "padding: 5px; "
        "border: 2px solid white; "
        "border-radius: 5px; "
        "background-color: rgba(255, 255, 255, 200);"
    );

    // Butoanele "Log In" și "Register"
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

    // Layout-ul pentru prompt, casetă de text și butoane
    QVBoxLayout* contentLayout = new QVBoxLayout();
    contentLayout->addWidget(promptLabel);
    contentLayout->addWidget(clientInput);
    contentLayout->addWidget(loginButton);
    contentLayout->addWidget(registerButton);
    contentLayout->setAlignment(promptLabel, Qt::AlignCenter);
    contentLayout->setAlignment(clientInput, Qt::AlignCenter);
    contentLayout->setAlignment(loginButton, Qt::AlignCenter);
    contentLayout->setAlignment(registerButton, Qt::AlignCenter);
    contentLayout->setSpacing(10); // Ajustează spațiul dintre butoane

    // Layout principal
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(contentLayout);
    setLayout(mainLayout);

    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLogin);
    connect(registerButton, &QPushButton::clicked, this, &LoginWindow::onRegister);

    setWindowTitle("Logare");
    resize(800, 600);
}

void LoginWindow::resizeEvent(QResizeEvent* event) {
    QPixmap pixmap(":/startImage/resources/StartGame.jpg");
    if (!pixmap.isNull()) {
        QPalette palette;
        palette.setBrush(QPalette::Window, pixmap.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
        setPalette(palette);
    }
    QWidget::resizeEvent(event);
}

void LoginWindow::onLogin() {
    std::string clientId = clientInput->text().toStdString();

    if (clientId.empty()) {
        QMessageBox::warning(this, "Eroare", "Vă rugăm să introduceți un nume!");
        return;
    }

    ClientApp* clientApp = new ClientApp();
    clientApp->show();

    close();
}

void LoginWindow::onRegister() {
    std::string clientId = clientInput->text().toStdString();

    if (clientId.empty()) {
        QMessageBox::warning(this, "Eroare", "Vă rugăm să introduceți un nume!");
        return;
    }

    QMessageBox::information(this, "Înregistrare", "Funcționalitatea de înregistrare nu este încă implementată!");

    ClientApp* clientApp = new ClientApp();
    clientApp->show();

    close();
}
