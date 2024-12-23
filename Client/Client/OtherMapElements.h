#pragma once
#include <QString>
#include <QLabel>
#include <QPixmap>
#include <QDebug>

class OtherMapElements
{
public:
    OtherMapElements() {};
    void DisplayBomb(int code, QLabel* imageLabel);
    void DisplayBonusLife(int code, QLabel* imageLabel);

private:
    void ShowImage(const QString& imagePath, QLabel* imageLabel);
};