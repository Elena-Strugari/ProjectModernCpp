#pragma once
#ifndef STARTGAMEWINDOW_H
#define STARTGAMEWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QKeyEvent>

class StartGame : public QWidget {
    Q_OBJECT

public:
    explicit StartGame(QWidget* parent = nullptr);
    ~StartGame();

signals:
    void startGame();

protected:
    void resizeEvent(QResizeEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;

private:
    QLabel* imageLabel;
    QLabel* textLabel;
};

#endif // STARTGAMEWINDOW_H

