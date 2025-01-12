#include "LoginWindow.h"
#include "ClientServer.h"
#include "ControlChoiceWindow.h"
#include "Client.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QPalette>
#include <QImage>


LoginWindow::LoginWindow(QWidget* parent)
    : QWidget(parent)
    , promptLabel(new QLabel("Introduceți numele dumneavoastră:", this))
    , clientInput(new QLineEdit(this))
    , loginButton(new QPushButton("Sign In", this))
    , registerButton(new QPushButton("Sign Up", this))
{
    qDebug() << "LoginWindow constructor called.";

    promptLabel->setAlignment(Qt::AlignCenter);
    promptLabel->setStyleSheet(
        "font-size: 30px; "
        "color: white; "
        "font-weight: bold;"
    );

    clientInput->setPlaceholderText("Numele dvs.");
    clientInput->setStyleSheet(
        "font-size: 16px; "
        "color: black; "
        "padding: 5px; "
        "border: 2px solid white; "
        "border-radius: 5px; "
        "background-color: rgba(255, 255, 255, 200);"
    );

    QString buttonStyle =
        "font-size: 18px; "
        "color: white; "
        "background-color: rgba(0, 0, 128, 200); "
        "border: 2px solid white; "
        "border-radius: 10px; "
        "padding: 5px;";
    loginButton->setStyleSheet(buttonStyle);
    registerButton->setStyleSheet(buttonStyle);

    QVBoxLayout* contentLayout = new QVBoxLayout();
    contentLayout->addWidget(promptLabel);
    contentLayout->addWidget(clientInput);
    contentLayout->addWidget(loginButton);
    contentLayout->addWidget(registerButton);
    contentLayout->setAlignment(Qt::AlignCenter);
    contentLayout->setSpacing(10);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(contentLayout);
    setLayout(mainLayout);

    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::OnLoginClicked);
    connect(registerButton, &QPushButton::clicked, this, &LoginWindow::OnRegisterClicked);

    setWindowTitle("Logare");
    resize(800, 600);

    InitializeBackground();
}

void LoginWindow::InitializeBackground()
{
    QImage image(":/StartImage/resources/StartGame.jpg"); 

    if (image.isNull()) {
        qDebug() << "Failed to load background image!";
        return;
    }

    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(image.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)));
    setPalette(palette);
    setAutoFillBackground(true);
}


void LoginWindow::resizeEvent(QResizeEvent* event)
{
    QImage image(":/StartImage/resources/StartGame.jpg"); 

    if (!image.isNull())
    {
        QPalette palette;
        palette.setBrush(QPalette::Window, QBrush(image.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)));
        setPalette(palette);
    }
    QWidget::resizeEvent(event);
}


void LoginWindow::OnLoginClicked()
{
    QString clientId = clientInput->text().trimmed();
    if (clientId.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Please enter a name!");
        return;
    }
    emit Login(clientId); // Emitem semnalul pentru succes
}


void LoginWindow::OnRegisterClicked()
{
    QString clientId = clientInput->text().trimmed();

    if (clientId.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Please enter a name!");
        return;
    }
    emit RegisterUser(clientId);
    qDebug() << "Register clicked with name:" << clientId;
    ControlChoiceWindow* controlWindow = new ControlChoiceWindow(clientId);
    controlWindow->show();
    //close();
    deleteLater();
}
