#pragma once

#include <QString>
#include <QLabel>
#include <QPixmap>
#include <QDebug>

class PlayerWindow
{
public:
    void DisplayPlayerImage(int code, QLabel* imageLabel);

private:
    void ShowImage(const QString& imagePath, QLabel* imageLabel);
};
