#ifndef GENERALSETTINGSWINDOW_H
#define GENERALSETTINGSWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QSlider>
#include "BackgroundHelper.h"
class GeneralSettingsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GeneralSettingsWindow(QWidget* parent = nullptr);
signals:
    void SaveSettings(int volume);
    void EditControls();
    void Logout();
    void Delete();
    void backToGame();
private slots:
    void onSaveSettings();
    void onEditControls();
    void onBackToGame();
    void onLogout();
    void onDelete();
protected:
    void resizeEvent(QResizeEvent* event) override;
private:
    //void InitializeBackground();

    QSlider* musicVolumeSlider;
    QPushButton* controlSettingsButton;
    QPushButton* logoutButton;
    QPushButton* saveButton;
    QPushButton* deleteButton;
    QPushButton* backToGameButton;
};

#endif // GENERALSETTINGSWINDOW_H
