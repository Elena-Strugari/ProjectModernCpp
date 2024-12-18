#include "ClientApp.h"
#include "ClientServer.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPalette>
#include <QPixmap>




ClientApp::ClientApp(QWidget* parent) : QWidget(parent) {
    // Imaginea de fundal
    QPixmap pixmap(":/startImage/resources/StartGame.jpg");
    if (!pixmap.isNull()) {
        QPalette palette;
        palette.setBrush(QPalette::Window, pixmap.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
        setAutoFillBackground(true);
        setPalette(palette);
    }  
   // ClientServer::connectServer();

    // Layout principal stratificat (pentru navigare între "ecrane")
    stackedLayout = new QStackedLayout(this);

    // === Ecranul 1: Bun venit ===
    QWidget* welcomeScreen = new QWidget(this);
    QVBoxLayout* welcomeLayout = new QVBoxLayout(welcomeScreen);

    QLabel* welcomeLabel = new QLabel("Welcome to the Game!", this);
    welcomeLabel->setAlignment(Qt::AlignCenter);
    welcomeLabel->setStyleSheet(
        "font-size: 32px; "
        "color: white; "
        "font-weight: bold; "
        "margin-bottom: 20px;"
    );

    QPushButton* startButton = new QPushButton("Start Game", this);
    startButton->setStyleSheet(
        "font-size: 20px; "
        "color: white; "
        "background-color: rgba(0, 128, 255, 200); "
        "border: 2px solid white; "
        "border-radius: 15px; "
        "padding: 10px; "
        "min-width: 200px;"
    );

    welcomeLayout->addWidget(welcomeLabel);
    welcomeLayout->addWidget(startButton);
    welcomeLayout->setAlignment(welcomeLabel, Qt::AlignCenter);
    welcomeLayout->setAlignment(startButton, Qt::AlignCenter);
    welcomeScreen->setLayout(welcomeLayout);

    // === Ecranul 2: Selectare nivel ===
    QWidget* levelSelectionScreen = new QWidget(this);
    QVBoxLayout* levelLayout = new QVBoxLayout(levelSelectionScreen);

    QLabel* levelLabel = new QLabel("Choose your difficulty level:", this);
    levelLabel->setAlignment(Qt::AlignCenter);
    levelLabel->setStyleSheet(
        "font-size: 28px; "
        "color: white; "
        "font-weight: bold; "
        "margin-bottom: 20px;"
    );

    QPushButton* easyButton = new QPushButton("Easy", this);
    QPushButton* mediumButton = new QPushButton("Medium", this);
    QPushButton* hardButton = new QPushButton("Hard", this);

    // Stil albastru pentru butoane
    QString buttonStyle =
        "font-size: 18px; "
        "color: white; "
        "background-color: rgba(0, 128, 255, 200); " // Albastru
        "border: 2px solid white; "
        "border-radius: 15px; "
        "padding: 10px; "
        "min-width: 150px;";

    easyButton->setStyleSheet(buttonStyle);
    mediumButton->setStyleSheet(buttonStyle);
    hardButton->setStyleSheet(buttonStyle);

    levelLayout->addWidget(levelLabel);
    levelLayout->addWidget(easyButton);
    levelLayout->addWidget(mediumButton);
    levelLayout->addWidget(hardButton);
    levelLayout->setAlignment(levelLabel, Qt::AlignCenter);
    levelLayout->setAlignment(easyButton, Qt::AlignCenter);
    levelLayout->setAlignment(mediumButton, Qt::AlignCenter);
    levelLayout->setAlignment(hardButton, Qt::AlignCenter);
    levelLayout->setSpacing(15); // Spațiu între butoane
    levelSelectionScreen->setLayout(levelLayout);

    // Adăugăm cele două "ecrane" la layout-ul stratificat
    stackedLayout->addWidget(welcomeScreen);
    stackedLayout->addWidget(levelSelectionScreen);

    // Setăm layout-ul principal
    setLayout(stackedLayout);

    resize(800, 600);

    // Conectări
    connect(startButton, &QPushButton::clicked, [this]() {
        stackedLayout->setCurrentIndex(1); // Trecem la al doilea ecran
        });

    connect(easyButton, &QPushButton::clicked, [this]() { onLevelChosen("Easy"); });
    connect(mediumButton, &QPushButton::clicked, [this]() { onLevelChosen("Medium"); });
    connect(hardButton, &QPushButton::clicked, [this]() { onLevelChosen("Hard"); });
}

void ClientApp::onLevelChosen(const QString& level) {
    QMessageBox::information(this, "Level Selected", "You selected: " + level);
}

