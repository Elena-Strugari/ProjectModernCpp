#ifndef VICTORYWINDOW_H
#define VICTORYWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QListWidget>
#include "BackgroundHelper.h"

class VictoryWindow : public QWidget
{
    Q_OBJECT

public:
    explicit VictoryWindow(int currentScore, int totalScore, const QStringList& leaderboard, QWidget* parent = nullptr);
    ~VictoryWindow();

signals:
    void returnToMainMenu(); // Semnal pentru întoarcerea la meniul principal

protected:
    void resizeEvent(QResizeEvent* event) override;

private slots:
    void onMainMenuButtonClicked(); // Slot pentru acțiunea butonului

private:
    int currentScore;
    int totalScore;
    QLabel* titleLabel;
    QLabel* currentScoreLabel;
    QLabel* totalScoreLabel;
    QLabel* leaderboardTitleLabel;
    QListWidget* leaderboardWidget;
    QPushButton* mainMenuButton;
};

#endif // VICTORYWINDOW_H
