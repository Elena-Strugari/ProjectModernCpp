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

signals:
    void startGame(); 

private slots:
    void triggerStartGame(); 

protected:
    void keyPressEvent(QKeyEvent* event) override;
    void resizeEvent(QResizeEvent* event)override;

private:
    QLabel* textLabel;
    QPushButton* startGameButton;
    void InitializeBackground();
};

#endif // STARTGAMEWINDOW_H
