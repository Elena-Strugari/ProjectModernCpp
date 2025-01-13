#include "GameOverWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QDebug>

GameOverWindow::GameOverWindow(int score, QWidget* parent)
    : QWidget(parent), playerScore(score)
{
    setWindowTitle("Game Over");
    resize(800, 600);

    // Initializează fundalul
    BackgroundHelper::InitializeBackground(this);

    // Configurare titlu
    titleLabel = new QLabel("Game Over", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 48px; font-weight: bold; color: red;");

    // Configurare scor
    scoreLabel = new QLabel(QString("Your Score: %1").arg(playerScore), this);
    scoreLabel->setAlignment(Qt::AlignCenter);
    scoreLabel->setStyleSheet("font-size: 24px; color: white;");

    // Configurare mesaj
    messageLabel = new QLabel("Better luck next time!", this);
    messageLabel->setAlignment(Qt::AlignCenter);
    messageLabel->setStyleSheet("font-size: 20px; color: white;");

    // Configurare buton
    mainMenuButton = new QPushButton("Return to Main Menu", this);
    mainMenuButton->setStyleSheet(
        "font-size: 16px; "
        "color: white; "
        "background-color: rgba(0, 0, 128, 200); "
        "border: 2px solid white; "
        "border-radius: 10px; "
        "padding: 5px;"
    );
    mainMenuButton->setFixedSize(200, 40);

    // Layout principal
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addStretch();
    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(scoreLabel);
    mainLayout->addWidget(messageLabel);
    mainLayout->addSpacing(20);
    mainLayout->addWidget(mainMenuButton, 0, Qt::AlignCenter);
    mainLayout->addStretch();

    setLayout(mainLayout);

    // Conectare semnal pentru buton
    connect(mainMenuButton, &QPushButton::clicked, this, &GameOverWindow::onMainMenuButtonClicked);
}

GameOverWindow::~GameOverWindow() = default;

void GameOverWindow::resizeEvent(QResizeEvent* event)
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

void GameOverWindow::onMainMenuButtonClicked()
{
    QMessageBox::information(this, "Returning to Main Menu", "The Settings button was clicked! Returning to the main menu.");
    emit returnToMainMenu();
}
