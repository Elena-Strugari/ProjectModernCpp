#include "OtherMapElements.h"
#include "NoGreenScreen.h"
void OtherMapElements::DisplayBomb(int code, QLabel* imageLabel)
{
    if (code == 50)
    {
        QString imagePath;
        imagePath = ":/Bomb/resources/Extraterestru.png";
        ShowImage(imagePath, imageLabel);
    }
}

void OtherMapElements::DisplayBonusLife(int code, QLabel* imageLabel)
{
    if (code == 60)
    {
        QString imagePath;
        imagePath = ":/BonusLife/resources/Oxygen.png";
        ShowImage(imagePath, imageLabel);
    }
}

void OtherMapElements::ShowImage(const QString& imagePath, QLabel* imageLabel)
{
    QPixmap pixmap(imagePath);

    if (pixmap.isNull())
    {
        qDebug() << "Imaginea nu a putut fi încărcată: " << imagePath;
        imageLabel->setText("Imaginea nu poate fi afișată!");
        return;
    }
    QImage image = pixmap.toImage();
    QImage processedImage = removeGreenScreen(image);

    QPixmap processedPixmap = QPixmap::fromImage(processedImage);
    imageLabel->setPixmap(pixmap.scaled(imageLabel->size(), Qt::KeepAspectRatio));
}
