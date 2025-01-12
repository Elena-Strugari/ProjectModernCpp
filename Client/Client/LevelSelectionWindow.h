#pragma once
#ifndef LEVELSELECTIONWINDOW_H
#define LEVELSELECTIONWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QString>

class LevelSelectionWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LevelSelectionWindow(QWidget* parent = nullptr);
    ~LevelSelectionWindow();

signals:
    void levelSelected(const QString& level); // Semnal pentru nivelul selectat

private:
    QLabel* titleLabel;         // Titlul ferestrei
    QPushButton* easyButton;    // Buton pentru nivel "Easy"
    QPushButton* mediumButton;  // Buton pentru nivel "Medium"
    QPushButton* hardButton;    // Buton pentru nivel "Hard"

    void initializeBackground(); // Funcție pentru a seta fundalul
};

#endif // LEVELSELECTIONWINDOW_H
