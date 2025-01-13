#include "VictoryWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QDebug>

VictoryWindow::VictoryWindow(int currentScore, int totalScore, const QStringList& leaderboard, QWidget* parent)
    : QWidget(parent), currentScore(currentScore), totalScore(totalScore)
{
    setWindowTitle("Victory");
    resize(800, 600);

    // Initializează fundalul
    BackgroundHelper::InitializeBackground(this);

    // Configurare titlu
    titleLabel = new QLabel("Victory!", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 48px; font-weight: bold; color: green;");

    // Scor curent
    currentScoreLabel = new QLabel(QString("Your Score: %1").arg(currentScore), this);
    currentScoreLabel->setAlignment(Qt::AlignCenter);
    currentScoreLabel->setStyleSheet("font-size: 24px; color: white;");

    // Scor total
    totalScoreLabel = new QLabel(QString("Total Score: %1").arg(totalScore), this);
    totalScoreLabel->setAlignment(Qt::AlignCenter);
    totalScoreLabel->setStyleSheet("font-size: 24px; color: white;");

    // Clasament
   /* leaderboardTitleLabel = new QLabel("Leaderboard", this);
    leaderboardTitleLabel->setAlignment(Qt::AlignCenter);
    leaderboardTitleLabel->setStyleSheet("font-size: 20px; font-weight: bold; color: white;");

    leaderboardWidget = new QListWidget(this);
    leaderboardWidget->addItems(leaderboard);
    leaderboardWidget->setStyleSheet(
        "background-color: transparent; "
        "border: none; "
        "color: white; "
        "font-size: 18px;");
    leaderboardWidget->setFixedHeight(150);*/

    // Buton pentru întoarcere
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
    mainLayout->addWidget(currentScoreLabel);
    mainLayout->addWidget(totalScoreLabel);
    mainLayout->addSpacing(10);
   /* mainLayout->addWidget(leaderboardTitleLabel);
    mainLayout->addWidget(leaderboardWidget, 0, Qt::AlignCenter);*/
    mainLayout->addSpacing(20);
    mainLayout->addWidget(mainMenuButton, 0, Qt::AlignCenter);
    mainLayout->addStretch();

    setLayout(mainLayout);

    // Conectare semnal pentru buton
    connect(mainMenuButton, &QPushButton::clicked, this, &VictoryWindow::onMainMenuButtonClicked);
}

VictoryWindow::~VictoryWindow() = default;

void VictoryWindow::resizeEvent(QResizeEvent* event)
{
    // Ajustează fundalul
    QImage image(":/StartImage/resources/StartGame.jpg");

    if (!image.isNull())
    {
        QPalette palette;
        palette.setBrush(QPalette::Window, QBrush(image.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)));
        setPalette(palette);
    }
    QWidget::resizeEvent(event);
}

void VictoryWindow::onMainMenuButtonClicked()
{
    QMessageBox::information(this, "Return to Main Menu", "Returning to Main Menu...");
    emit returnToMainMenu();
}
