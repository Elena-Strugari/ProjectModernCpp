#include "GameMapWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QDebug>

GameMapWindow::GameMapWindow(QWidget* parent)
    : QWidget(parent),
    mapWidget(new QWidget(this)),
    settingsButton(new QPushButton("Settings", this)),
    titleLabel(new QLabel("Game Map", this))
{
    setWindowTitle("Game Map");
    resize(1000, 700);

    // Initializează fundalul
    InitializeBackground();

    // Configurare titlu
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 36px; font-weight: bold; color: white;");

    // Configurare buton Settings
    settingsButton->setStyleSheet(
        "font-size: 16px; "
        "color: white; "
        "background-color: rgba(0, 0, 128, 200); "
        "border: 2px solid white; "
        "border-radius: 10px; "
        "padding: 5px;"
    );
    settingsButton->setFixedSize(120, 40);

    // Configurare mapWidget
    mapWidget->setStyleSheet(
        "background-color: rgba(0, 0, 0, 150); "
        "border: 3px solid white; "
        "border-radius: 10px;"
    );

    // Layout pentru titlu și butonul Settings
    QHBoxLayout* topLayout = new QHBoxLayout();
    topLayout->addWidget(titleLabel, 1); // Titlul ocupă mai mult spațiu
    topLayout->addWidget(settingsButton, 0, Qt::AlignRight);

    // Layout principal
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(topLayout);
    mainLayout->addStretch();
    mainLayout->addWidget(mapWidget, 0, Qt::AlignCenter);
    mainLayout->addStretch();

    setLayout(mainLayout);

    // Conectare semnal pentru butonul Settings
    connect(settingsButton, &QPushButton::clicked, this, &GameMapWindow::onSettingsClicked);
}

GameMapWindow::~GameMapWindow() = default;

void GameMapWindow::InitializeBackground()
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

void GameMapWindow::resizeEvent(QResizeEvent* event)
{
    // Ajustăm dimensiunea mapWidget proporțional cu fereastra
    int widgetWidth = width() * 0.8;  // 80% din lățimea ferestrei
    int widgetHeight = height() * 0.6; // 60% din înălțimea ferestrei
    mapWidget->setFixedSize(widgetWidth, widgetHeight);

    QWidget::resizeEvent(event);
}

void GameMapWindow::onSettingsClicked()
{
    QMessageBox::information(this, "Settings Clicked", "The Settings button was clicked!");
}
