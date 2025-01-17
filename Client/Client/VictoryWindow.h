#ifndef VICTORYWINDOW_H
#define VICTORYWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>

class VictoryWindow : public QWidget
{
    Q_OBJECT

public:
    explicit VictoryWindow(QWidget* parent = nullptr);
    ~VictoryWindow();

    void setPlayerScores(int currentScore, int totalScore); // Update current and total scores
    void setLeaderboard(const std::vector<QPair<QString, int>>& leaderboard); // Update leaderboard

signals:
    void StartNewGame();
    void ExitGame();

private slots:
    void onStartNewGameClicked();
    void onExitClicked();

private:
    QLabel* titleLabel;
    QLabel* scoreLabel;
    QLabel* leaderboardTitleLabel;
    QListWidget* leaderboardWidget; // Use QListWidget for leaderboard
    QPushButton* startNewGameButton;
    QPushButton* exitGameButton;
};

#endif // VICTORYWINDOW_H