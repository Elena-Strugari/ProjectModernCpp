//#pragma once
//#ifndef STARTGAMEWINDOW_H
//#define STARTGAMEWINDOW_H
//
//#include <QWidget>
//#include <QLabel>
//#include <QKeyEvent>
//
//class StartGameWindow : public QWidget {
//    Q_OBJECT
//
//public:
//    explicit StartGameWindow(QWidget* parent = nullptr);
//    void initializeBackground();
//    ~StartGameWindow();
//
//signals:
//    void startGame();
//
//protected:
//    void resizeEvent(QResizeEvent* event) override;
//    void keyPressEvent(QKeyEvent* event) override;
//
//private:
//    QLabel* imageLabel;
//    QLabel* textLabel;
//};
//
//#endif // STARTGAMEWINDOW_H
//
//....................................................................
#ifndef STARTGAMEWINDOW_H
#define STARTGAMEWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QKeyEvent>

class StartGameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StartGameWindow(QWidget* parent = nullptr);
    ~StartGameWindow();

    void initializeBackground();

signals:
    void startGame(); // Signal emitted when Enter is pressed

protected:
    void resizeEvent(QResizeEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;

private:
    QLabel* imageLabel;
    QLabel* textLabel;
};

#endif // STARTGAMEWINDOW_H
