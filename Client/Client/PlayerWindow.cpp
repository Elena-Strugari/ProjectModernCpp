#include "PlayerWindow.h"
#include "NoGreenScreen.h"
void PlayerWindow::DisplayPlayerImage(int code, QLabel* imageLabel)
{
    QString imagePath;
    switch (code)
    {
    case 11:
        imagePath = ":/Astronaut_1_Positions/resources/Astronaut_1_Down.png";
        break;
    case 12:
        imagePath = ":/Astronaut_1_Positions/resources/Astronaut_1_Left.png";
        break;
    case 13:
        imagePath = ":/Astronaut_1_Positions/resources/Astronaut_1_Right.png";
        break;
    case 14:
        imagePath = ":/Astronaut_1_Positions/resources/Astronaut_1_Up.png";
        break;
    case 21:
        imagePath = ":/Astronaut_2_Positions/resources/Astronaut_2_Down.png";
        break;
    case 22:
        imagePath = ":/Astronaut_2_Positions/resources/Astronaut_2_Left.png";
        break;
    case 23:
        imagePath = ":/Astronaut_2_Positions/resources/Astronaut_2_Right.png";
        break;
    case 24:
        imagePath = ":/Astronaut_2_Positions/resources/Astronaut_2_Up.png";
        break;
    case 31:
        imagePath = ":/Astronaut_3_Positions/resources/Astronaut_3_Down.png";
        break;
    case 32:
        imagePath = ":/Astronaut_3_Positions/resources/Astronaut_3_Left.png";
        break;
    case 33:
        imagePath = ":/Astronaut_3_Positions/resources/Astronaut_3_Right.png";
        break;
    case 34:
        imagePath = ":/Astronaut_3_Positions/resources/Astronaut_3_Up.png";
        break;
    case 41:
        imagePath = ":/Astronaut_4_Positions/resources/Astronaut_4_Down.png";
        break;
    case 42:
        imagePath = ":/Astronaut_4_Positions/resources/Astronaut_4_Left.png";
        break;
    case 43:
        imagePath = ":/Astronaut_4_Positions/resources/Astronaut_4_Right.png";
        break;
    case 44:
        imagePath = ":/Astronaut_4_Positions/resources/Astronaut_4_Up.png";
        break;
    default:
        qDebug() << "Cod invalid: " << code;
        imageLabel->setText("Cod invalid!");
        return;
    }

    ShowImage(imagePath, imageLabel);
}

void PlayerWindow::ShowImage(const QString& imagePath, QLabel* imageLabel)
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
