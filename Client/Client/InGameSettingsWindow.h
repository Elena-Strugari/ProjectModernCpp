#ifndef INGAMESETTINGSWINDOW_H
#define INGAMESETTINGSWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QSlider>
#include "BackgroundHelper.h"
class InGameSettingsWindow : public QWidget
{
    Q_OBJECT // Macro-ul necesar pentru semnale și sloturi

public:
    explicit InGameSettingsWindow(QWidget* parent = nullptr);
    ~InGameSettingsWindow();
    void positionInTopRight(QWidget* parent);

signals:
    void backToGame();   // Semnal pentru întoarcerea la joc
    void editControls(); // Semnal pentru schimbarea controalelor
    void exitGame();     // Semnal pentru ieșirea din joc

private slots:
    void onBackToGame();   // Slot pentru butonul "Back to Game"
    void onEditControls(); // Slot pentru butonul "Edit Controls"
    void onExitGame();     // Slot pentru butonul "Exit Game"

protected:
    void resizeEvent(QResizeEvent* event) override;
private:
    //void InitializeBackground(); // Metodă pentru setarea fundalului

    QSlider* musicVolumeSlider;
    QPushButton* backToGameButton;
    QPushButton* editControlsButton;
    QPushButton* exitGameButton;
};

#endif // INGAMESETTINGSWINDOW_H
