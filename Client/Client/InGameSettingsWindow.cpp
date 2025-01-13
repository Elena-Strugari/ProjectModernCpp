//#include "InGameSettingsWindow.h"
//#include <QVBoxLayout>
//#include <QHBoxLayout>
//#include <QLabel>
//#include <QMessageBox>
//#include <QImage>
//#include <QPalette>
//#include <QDebug>
//
//InGameSettingsWindow::InGameSettingsWindow(QWidget* parent)
//    : QWidget(parent),
//    musicVolumeSlider(new QSlider(Qt::Horizontal, this)),
//    backToGameButton(new QPushButton("Back to Game", this)),
//    editControlsButton(new QPushButton("Edit Controls", this)),
//    exitGameButton(new QPushButton("Exit Game", this))
//{
//    setWindowTitle("In-Game Settings");
//    resize(800, 600);
//
//    // Initializează fundalul
//    InitializeBackground();
//
//    // Configurare slider de volum
//    musicVolumeSlider->setRange(0, 100);
//    musicVolumeSlider->setValue(50);
//    musicVolumeSlider->setFixedWidth(400);
//
//    // Stil butoane
//    QString buttonStyle =
//        "font-size: 16px; "
//        "color: white; "
//        "background-color: rgba(0, 0, 128, 200); "
//        "border: 2px solid white; "
//        "border-radius: 10px; "
//        "padding: 5px;";
//    backToGameButton->setStyleSheet(buttonStyle);
//    editControlsButton->setStyleSheet(buttonStyle);
//    exitGameButton->setStyleSheet(buttonStyle);
//
//    // Setăm dimensiuni fixe pentru butoane
//    QSize buttonSize(150, 40);
//    backToGameButton->setFixedSize(buttonSize);
//    editControlsButton->setFixedSize(buttonSize);
//    exitGameButton->setFixedSize(buttonSize);
//
//    // Layout pentru slider-ul de volum
//    QVBoxLayout* slidersLayout = new QVBoxLayout();
//    QLabel* musicLabel = new QLabel("Music Volume", this);
//    musicLabel->setAlignment(Qt::AlignCenter);
//    musicLabel->setStyleSheet("font-size: 18px; color: white;");
//
//    slidersLayout->addWidget(musicLabel);
//    slidersLayout->addWidget(musicVolumeSlider);
//    slidersLayout->setAlignment(Qt::AlignCenter);
//
//    // Layout pentru butoane
//    QHBoxLayout* buttonLayout = new QHBoxLayout();
//    buttonLayout->addStretch();
//    buttonLayout->addWidget(backToGameButton);
//    buttonLayout->addSpacing(50);
//    buttonLayout->addWidget(editControlsButton);
//    buttonLayout->addSpacing(50);
//    buttonLayout->addWidget(exitGameButton);
//    buttonLayout->addStretch();
//
//    // Layout principal
//    QVBoxLayout* mainLayout = new QVBoxLayout(this);
//    QLabel* titleLabel = new QLabel("In-Game Settings", this);
//    titleLabel->setAlignment(Qt::AlignCenter);
//    titleLabel->setStyleSheet("font-size: 32px; font-weight: bold; color: white;");
//    titleLabel->setContentsMargins(0, 20, 0, 10); // Spațiu suplimentar pentru titlu
//
//    mainLayout->addWidget(titleLabel);
//    mainLayout->addStretch();
//    mainLayout->addLayout(slidersLayout);
//    mainLayout->addStretch();
//    mainLayout->addLayout(buttonLayout);
//    mainLayout->addStretch();
//
//    setLayout(mainLayout);
//
//    // Conexiuni pentru butoane
//    connect(backToGameButton, &QPushButton::clicked, this, &InGameSettingsWindow::onBackToGame);
//    connect(editControlsButton, &QPushButton::clicked, this, &InGameSettingsWindow::onEditControls);
//    connect(exitGameButton, &QPushButton::clicked, this, &InGameSettingsWindow::onExitGame);
//}
//
//InGameSettingsWindow::~InGameSettingsWindow()
//{
//}
//
//void InGameSettingsWindow::InitializeBackground()
//{
//    QImage image(":/StartImage/resources/StartGame.jpg"); // Calea către imagine
//
//    if (image.isNull()) {
//        qDebug() << "Failed to load background image!";
//        return;
//    }
//
//    QPalette palette;
//    palette.setBrush(QPalette::Window, QBrush(image.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)));
//    setPalette(palette);
//    setAutoFillBackground(true);
//}
//
//void InGameSettingsWindow::onBackToGame()
//{
//    qDebug() << "Back to Game clicked.";
//    emit backToGame(); // Emiterea semnalului
//}
//
//void InGameSettingsWindow::onEditControls()
//{
//    qDebug() << "Edit Controls clicked.";
//    emit editControls(); // Emiterea semnalului
//}
//
//void InGameSettingsWindow::onExitGame()
//{
//    qDebug() << "Exit Game clicked.";
//    emit exitGame(); // Emiterea semnalului
//}
