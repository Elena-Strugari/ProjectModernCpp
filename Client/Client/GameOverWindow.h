#ifndef GAMEOVERWINDOW_H
#define GAMEOVERWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "BackgroundHelper.h"

class GameOverWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameOverWindow(int score, QWidget* parent = nullptr);
    ~GameOverWindow();

signals:
    void returnToMainMenu(); // Semnal pentru întoarcerea la meniul principal

protected:
    void resizeEvent(QResizeEvent* event) override;

private slots:
    void onMainMenuButtonClicked(); // Slot pentru acțiunea butonului

private:
    int playerScore;
    QLabel* titleLabel;
    QLabel* scoreLabel;
    QLabel* messageLabel;
    QPushButton* mainMenuButton;
};

#endif // GAMEOVERWINDOW_H
