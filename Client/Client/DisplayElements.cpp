#include "DisplayElements.h"
#include "NoGreenScreen.h"
void DisplayElements::DisplayPlayerImage(int code, QLabel* imageLabel)
{
    QString imagePath;
    switch (code)
    {
    case 11:
    {
        imagePath = ":/Astronaut_1_Positions/resources/Astronaut_1_Down.png";
        break;
    }
    case 12:
    {
        imagePath = ":/Astronaut_1_Positions/resources/Astronaut_1_Left.png";
        break;
    }
    case 13:
    {
        imagePath = ":/Astronaut_1_Positions/resources/Astronaut_1_Right.png";
        break;
    }
    case 14:
    {
        imagePath = ":/Astronaut_1_Positions/resources/Astronaut_1_Up.png";
        break;
    }
    case 21:
    {
        imagePath = ":/Astronaut_2_Positions/resources/Astronaut_2_Down.png";
        break;
    }
    case 22:
    {
        imagePath = ":/Astronaut_2_Positions/resources/Astronaut_2_Left.png";
        break;
    }
    case 23:
    {
        imagePath = ":/Astronaut_2_Positions/resources/Astronaut_2_Right.png";
        break;
    }
    case 24:
    {
        imagePath = ":/Astronaut_2_Positions/resources/Astronaut_2_Up.png";
        break;
    }
    case 31:
    {
        imagePath = ":/Astronaut_3_Positions/resources/Astronaut_3_Down.png";
        break;
    }
    case 32:
    {
        imagePath = ":/Astronaut_3_Positions/resources/Astronaut_3_Left.png";
        break;
    }
    case 33:
    {
        imagePath = ":/Astronaut_3_Positions/resources/Astronaut_3_Right.png";
        break;
    }
    case 34:
    {
        imagePath = ":/Astronaut_3_Positions/resources/Astronaut_3_Up.png";
        break;
    }
    case 41:
    {
        imagePath = ":/Astronaut_4_Positions/resources/Astronaut_4_Down.png";
        break;
    }
    case 42:
    {
        imagePath = ":/Astronaut_4_Positions/resources/Astronaut_4_Left.png";
        break;
    }
    case 43:
    {
        imagePath = ":/Astronaut_4_Positions/resources/Astronaut_4_Right.png";
        break;
    }
    case 44:
    {
        imagePath = ":/Astronaut_4_Positions/resources/Astronaut_4_Up.png";
        break;
    }
    default:
    {
        qDebug() << "Cod invalid: " << code;
        imageLabel->setText("Cod invalid!");
        return;
    }
    }

    ShowImage(imagePath, imageLabel);
}

void DisplayElements::DisplayBombImage(QLabel* imageLabel)
{
    QString imagePath = " :/ Bomb / resources / Extraterestru.png";
    ShowImage(imagePath, imageLabel);
}

void DisplayElements::DisplayBonusLifeImage(QLabel* imageLabel)
{
    QString imagePath = " / BonusLife / resources / Oxygen.png";
    ShowImage(imagePath, imageLabel);
}

void DisplayElements::DisplayBorderImage(QLabel* imageLabel)
{
    QString imagePath = " :/Border/resources/Border.png";
    ShowImage(imagePath, imageLabel);
}

void DisplayElements::DisplayWallImage(int code, QLabel* imageLabel)
{
    QString imagePath;
    switch (code)
    {
    case 1:
        {
            imagePath = " :/Wall/resources/Asteroid.png";
            break;
        }
    case 2:
    {
        imagePath = " :/Wall/resources/Asteroid.png";
        break;
    }
    case 3:
    {
        imagePath = " :/SlowSpeedWall/resources/praf1.png";
        break;
    }
    default:
    {
        qDebug() << "Cod invalid: " << code;
        imageLabel->setText("Cod invalid!");
        return;
    }
    }
    ShowImage(imagePath, imageLabel);
}

void DisplayElements::ShowImage(const QString& imagePath, QLabel* imageLabel)
{
    QPixmap pixmap(imagePath);

    if (pixmap.isNull())
    {
        qDebug() << "Imaginea nu a putut fi încărcată: " << imagePath;
        imageLabel->setText("Imaginea nu poate fi afișată!");
        return;
    }
    QImage image = pixmap.toImage();

    // Aplicăm eliminarea green screen-ului
    QImage processedImage = removeGreenScreen(image);

    // Convertim înapoi în QPixmap și afișăm imaginea procesată
    QPixmap processedPixmap = QPixmap::fromImage(processedImage);
    imageLabel->setPixmap(pixmap.scaled(imageLabel->size(), Qt::KeepAspectRatio));
}
