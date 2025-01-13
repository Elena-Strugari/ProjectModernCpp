#ifndef GAMEMAPWINDOW_H
#define GAMEMAPWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class GameMapWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameMapWindow(QWidget* parent = nullptr);
    ~GameMapWindow();

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    void InitializeBackground();

private slots:
    void onSettingsClicked();

private:
    QWidget* mapWidget;
    QPushButton* settingsButton;
    QLabel* titleLabel;
};

#endif // GAMEMAPWINDOW_H
