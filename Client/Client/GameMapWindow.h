#ifndef GAMEMAPWINDOW_H
#define GAMEMAPWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "BackgroundHelper.h"
class GameMapWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameMapWindow(QWidget* parent = nullptr);
    ~GameMapWindow();

protected:
    void resizeEvent(QResizeEvent* event) override;
private:
    void adjustMapWidgetSize(QResizeEvent* event);

private:
    //void InitializeBackground();

signals:
void SettingsClicked();
public slots:
    void onSettingsClicked();

private:
    QWidget* mapWidget;
    QPushButton* settingsButton;
    QLabel* titleLabel;
};

#endif // GAMEMAPWINDOW_H
