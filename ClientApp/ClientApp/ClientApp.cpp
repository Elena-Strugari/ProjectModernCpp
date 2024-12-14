#include "ClientApp.h"
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



    // to modify , 
    // 
    // 
    //void ClientApp::onChooseLevel(const std::string&clientId , const std::string& level) {
    //   // std::string clientId = clientIdInput->text().toStdString();
    //    /*if (clientId.empty()) {
    //        QMessageBox::warning(this, "Error", "Client ID is required!");
    //        return;
    //    }*/
    //
    //    cpr::Response r = cpr::Post(
    //        cpr::Url{ "http://localhost:8080/choose_level" },
    //        cpr::Header{ {"Client-ID", clientId} },
    //        cpr::Body{ level }
    //    );
    //
    //    if (r.status_code == 200) {
    //        outputLabel->setText("Level chosen successfully: " + QString::fromStdString(r.text));
    //    }
    //    else {
    //        outputLabel->setText("Error choosing level: " + QString::fromStdString(r.text));
    //    }
    //}
    //
    //void ClientApp::onChooseSmall() {
    //    onChooseLevel(clientId, "Easy");
    //}
    //
    //void ClientApp::onChooseMedium() {
    //    onChooseLevel("Medium");
    //}
    //
    //void ClientApp::onChooseLarge() {
    //    onChooseLevel("Hard");
    //}



    //#include "ClientApp.h"
    //#include <QMessageBox>
    //
    //ClientApp::ClientApp(QWidget* parent) : QWidget(parent) {
    //    QVBoxLayout* layout = new QVBoxLayout(this);
    //
    //    // Input pentru Client ID și Level
    //    clientIdInput = new QLineEdit(this);
    //    clientIdInput->setPlaceholderText("Enter Client ID");
    //    levelInput = new QLineEdit(this);
    //    levelInput->setPlaceholderText("Enter Level (Usor, Mediu, Greu)");
    //
    //    QPushButton* chooseLevelButton = new QPushButton("Choose Level", this);
    //    QPushButton* getMapButton = new QPushButton("Get Map", this);
    //
    //    QPushButton* moveUpButton = new QPushButton("Move Up", this);
    //    QPushButton* moveDownButton = new QPushButton("Move Down", this);
    //    QPushButton* moveLeftButton = new QPushButton("Move Left", this);
    //    QPushButton* moveRightButton = new QPushButton("Move Right", this);
    //
    //    outputLabel = new QLabel(this);
    //
    //    // Adăugăm widget-uri la layout
    //    layout->addWidget(clientIdInput);
    //    layout->addWidget(levelInput);
    //    layout->addWidget(chooseLevelButton);
    //    layout->addWidget(getMapButton);
    //    layout->addWidget(moveUpButton);
    //    layout->addWidget(moveDownButton);
    //    layout->addWidget(moveLeftButton);
    //    layout->addWidget(moveRightButton);
    //    layout->addWidget(outputLabel);
    //
    //    setLayout(layout);
    //
    //    // Conectăm butoanele la sloturi
    //    connect(chooseLevelButton, &QPushButton::clicked, this, &ClientApp::onChooseLevel);
    //    connect(getMapButton, &QPushButton::clicked, this, &ClientApp::onGetMap);
    //    connect(moveUpButton, &QPushButton::clicked, this, &ClientApp::onMoveTankUp);
    //    connect(moveDownButton, &QPushButton::clicked, this, &ClientApp::onMoveTankDown);
    //    connect(moveLeftButton, &QPushButton::clicked, this, &ClientApp::onMoveTankLeft);
    //    connect(moveRightButton, &QPushButton::clicked, this, &ClientApp::onMoveTankRight);
    //}
    //
    //void ClientApp::onChooseLevel() {
    //    std::string clientId = clientIdInput->text().toStdString();
    //    std::string level = levelInput->text().toStdString();
    //
    //    cpr::Response r = cpr::Post(
    //        cpr::Url{ "http://localhost:8080/choose_level" },
    //        cpr::Header{ {"Client-ID", clientId} },
    //        cpr::Body{ level }
    //    );
    //
    //    if (r.status_code == 200) {
    //        outputLabel->setText("Level chosen successfully: " + QString::fromStdString(r.text));
    //    }
    //    else {
    //        outputLabel->setText("Error choosing level: " + QString::fromStdString(r.text));
    //    }
    //}
    //
    //void ClientApp::onGetMap() {
    //    std::string clientId = clientIdInput->text().toStdString();
    //    std::string level = levelInput->text().toStdString();
    //
    //    cpr::Response r = cpr::Get(
    //        cpr::Url{ "http://localhost:8080/get_map" },
    //        cpr::Header{ {"Client-ID", clientId} },
    //        cpr::Body{ level }
    //    );
    //
    //    if (r.status_code == 200) {
    //        //outputLabel->setText("Map retrieved successfully! JSON:\n" + QString::fromStdString(r.text));
    //        outputLabel->setText("Map retrieved successfully! JSON:\n");
    //    }
    //    else {
    //        outputLabel->setText("Error retrieving map: " + QString::fromStdString(r.text));
    //    }
    //}
    //
    //void ClientApp::sendMoveRequest(const std::string& direction) {
    //    std::string clientId = clientIdInput->text().toStdString();
    //    std::string url = "http://localhost:8080/move_tank/" + direction + "?id=" + clientId;
    //
    //    cpr::Response r = cpr::Get(cpr::Url{ url });
    //
    //    if (r.status_code == 200) {
    //        outputLabel->setText("Move successful: " + QString::fromStdString(r.text));
    //    }
    //    else {
    //        outputLabel->setText("Move error: " + QString::fromStdString(r.text));
    //    }
    //}
    //
    //void ClientApp::onMoveTankUp() {
    //    sendMoveRequest("up");
    //}
    //
    //void ClientApp::onMoveTankDown() {
    //    sendMoveRequest("down");
    //}
    //
    //void ClientApp::onMoveTankLeft() {
    //    sendMoveRequest("left");
    //}
    //
    //void ClientApp::onMoveTankRight() {
    //    sendMoveRequest("right");
    //}
