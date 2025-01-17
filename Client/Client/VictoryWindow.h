#ifndef VICTORYWINDOW_H
#define VICTORYWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class VictoryWindow : public QWidget
{
    Q_OBJECT

public:
    explicit VictoryWindow(QWidget* parent = nullptr);
    ~VictoryWindow();

    void setPlayerScores(int currentScore, int totalScore); // Update current and total scores
    void setLeaderboard(const QVector<QPair<QString, int>>& leaderboard); // Update leaderboard with player names and scores

signals:
    void StartNewGame();
    void ExitGame();

protected:
    void resizeEvent(QResizeEvent* event) override;

private slots:
    void onStartNewGameClicked();
    void onExitClicked();

private:
    QLabel* titleLabel;
    QLabel* scoreLabel; // Displays current and total score
    QLabel* leaderboardTitleLabel;
    QList<QLabel*> leaderboardLabels; // Leaderboard labels
    QPushButton* startNewGameButton;
    QPushButton* exitGameButton;
};

#endif // VICTORYWINDOW_H