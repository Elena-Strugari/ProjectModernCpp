#pragma once

#include <QString>
#include <QLabel>
#include <QImage>
#include <QDebug>
#include <QPixMap>
class DisplayElements
{
public:
    DisplayElements() {};
    void DisplayPlayerImage(int code, QLabel* imageLabel);
    void DisplayBombImage(QLabel* imageLabel);
    void DisplayBonusLifeImage( QLabel* imageLabel);
    void DisplayBorderImage(QLabel* imageLabel);
    void DisplayWallImage(int code, QLabel* imageLabel);

private:
    void ShowImage(const QString& imagePath, QLabel* imageLabel);
};
