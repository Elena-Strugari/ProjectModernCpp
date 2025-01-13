#ifndef GENERALSETTINGSWINDOW_H
#define GENERALSETTINGSWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QSlider>

class GeneralSettingsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GeneralSettingsWindow(QWidget* parent = nullptr);

private slots:
    void onSaveSettings();
    void onEditControls();
    void onLogout();

private:
    void InitializeBackground();

    QSlider* musicVolumeSlider;
    QPushButton* controlSettingsButton;
    QPushButton* logoutButton;
    QPushButton* saveButton;
};

#endif // GENERALSETTINGSWINDOW_H
