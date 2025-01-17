#include "GameOverWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QDebug>
#include "BackgroundHelper.h" // Ensure this is included if used

GameOverWindow::GameOverWindow(QWidget* parent)
    : QWidget(parent)
{
    setWindowTitle("Game Over");
    resize(800, 600);

    // Initialize background
    BackgroundHelper::InitializeBackground(this);

    // Configure title
    titleLabel = new QLabel("Game Over", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 48px; font-weight: bold; color: red;");

    // Placeholder for score (updated dynamically)
    scoreLabel = new QLabel("Your Score: 0", this); // Default value
    scoreLabel->setAlignment(Qt::AlignCenter);
    scoreLabel->setStyleSheet("font-size: 24px; color: white;");

    // Placeholder for message (updated dynamically)
    messageLabel = new QLabel("Better luck next time!", this); // Default value
    messageLabel->setAlignment(Qt::AlignCenter);
    messageLabel->setStyleSheet("font-size: 20px; color: white;");

    // Configure buttons
    startNewGameButton = new QPushButton("Start New Game", this);
    exitGameButton = new QPushButton("Exit", this);
    QString style =
        "font-size: 16px; "
        "color: white; "
        "background-color: rgba(0, 0, 128, 200); "
        "border: 2px solid white; "
        "border-radius: 10px; "
        "padding: 5px;";
    startNewGameButton->setStyleSheet(style);
    exitGameButton->setStyleSheet(style);
    startNewGameButton->setFixedSize(200, 40);
    exitGameButton->setFixedSize(200, 40);

    // Create main layout
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addStretch();
    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(scoreLabel);
    mainLayout->addWidget(messageLabel);
    mainLayout->addSpacing(20);

    // Create a horizontal layout for the buttons
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    buttonLayout->addWidget(startNewGameButton);
    buttonLayout->addSpacing(20); // Add spacing between buttons
    buttonLayout->addWidget(exitGameButton);
    buttonLayout->addStretch();

    // Add the horizontal button layout to the main layout
    mainLayout->addLayout(buttonLayout);
    mainLayout->addStretch();

    setLayout(mainLayout);

    // Connect button signals
    connect(startNewGameButton, &QPushButton::clicked, this, &GameOverWindow::onStartNewGameClicked);
    connect(exitGameButton, &QPushButton::clicked, this, &GameOverWindow::onExitClicked);
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

void GameOverWindow::onStartNewGameClicked()
{
    QMessageBox::information(this, "Start New Game", "Starting a new game...");
    emit StartNewGame();
}
void GameOverWindow::onExitClicked()
{
    QMessageBox::information(this, "Exit Game", "Closing game...");
    emit ExitGame();
}

void GameOverWindow::setScore(int score)
{
    scoreLabel->setText(QString("Your Score: %1").arg(score));
}

void GameOverWindow::setMessage(const QString& message)
{
    messageLabel->setText(message);
}