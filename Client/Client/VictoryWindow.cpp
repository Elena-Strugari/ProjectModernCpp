#include "VictoryWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QDebug>
#include "BackgroundHelper.h" // Ensure this is included if used

VictoryWindow::VictoryWindow(QWidget* parent)
    : QWidget(parent)
{
    setWindowTitle("Victory");
    resize(800, 600);

    // Initialize background
    BackgroundHelper::InitializeBackground(this);

    // Configure title
    titleLabel = new QLabel("Victory!", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 48px; font-weight: bold; color: green;");

    // Placeholder for scores
    scoreLabel = new QLabel("Your Score: Current: 0, Total: 0", this); // Default value
    scoreLabel->setAlignment(Qt::AlignCenter);
    scoreLabel->setStyleSheet("font-size: 24px; color: white;");

    // Configure leaderboard
    leaderboardTitleLabel = new QLabel("Leaderboard", this);
    leaderboardTitleLabel->setAlignment(Qt::AlignCenter);
    leaderboardTitleLabel->setStyleSheet("font-size: 20px; font-weight: bold; color: white;");

    // Initialize empty leaderboard labels (up to 4)
    for (int i = 0; i < 4; ++i) {
        QLabel* label = new QLabel(this);
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet("font-size: 18px; color: white; background: transparent;");
        label->hide(); // Initially hidden
        leaderboardLabels.append(label);
    }

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
    mainLayout->addSpacing(10);
    mainLayout->addWidget(leaderboardTitleLabel);
    for (auto label : leaderboardLabels) {
        mainLayout->addWidget(label, 0, Qt::AlignCenter);
    }
    mainLayout->addSpacing(20);

    // Create a horizontal layout for the buttons
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    buttonLayout->addWidget(startNewGameButton);
    buttonLayout->addSpacing(20); // Add some spacing between buttons
    buttonLayout->addWidget(exitGameButton);
    buttonLayout->addStretch();

    // Add the horizontal button layout to the main layout
    mainLayout->addLayout(buttonLayout);

    mainLayout->addStretch();

    setLayout(mainLayout);

    // Connect button signals
    connect(startNewGameButton, &QPushButton::clicked, this, &VictoryWindow::onStartNewGameClicked);
    connect(exitGameButton, &QPushButton::clicked, this, &VictoryWindow::onExitClicked);
}


VictoryWindow::~VictoryWindow() = default;

void VictoryWindow::resizeEvent(QResizeEvent* event)
{
    // Adjust the background
    QImage image(":/StartImage/resources/StartGame.jpg");

    if (!image.isNull())
    {
        QPalette palette;
        palette.setBrush(QPalette::Window, QBrush(image.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)));
        setPalette(palette);
    }
    QWidget::resizeEvent(event);
}

void VictoryWindow::onStartNewGameClicked()
{
    QMessageBox::information(this, "Start New Game", "Starting a new game...");
    emit StartNewGame();
}
void VictoryWindow::onExitClicked()
{
    QMessageBox::information(this, "Exit Game", "Closing game...");
    emit ExitGame();
}

void VictoryWindow::setPlayerScores(int currentScore, int totalScore)
{
    scoreLabel->setText(QString("Your Score: Current: %1, Total: %2").arg(currentScore).arg(totalScore));
}

void VictoryWindow::setLeaderboard(const QVector<QPair<QString, int>>& leaderboard)
{
    for (int i = 0; i < leaderboardLabels.size(); ++i) {
        if (i < leaderboard.size()) {
            const auto& [playerName, score] = leaderboard[i];
            leaderboardLabels[i]->setText(QString("%1: %2").arg(playerName).arg(score));
            leaderboardLabels[i]->show(); // Show if there's data
        }
        else {
            leaderboardLabels[i]->hide(); // Hide unused slots
        }
    }
}