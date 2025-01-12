#ifndef STARTGAMEWINDOW_H
#define STARTGAMEWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QKeyEvent>
#include <QDir>
class StartGameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StartGameWindow(QWidget* parent = nullptr);
    ~StartGameWindow();

    void initializeBackground();

signals:
    void startGame(); // Signal emitted to transition to the next window

private slots:
    void triggerStartGame(); // Shared action for button and Enter key

protected:
    void keyPressEvent(QKeyEvent* event) override;

private:
    QLabel* textLabel;
    QPushButton* startGameButton;
};

#endif // STARTGAMEWINDOW_H
