#include "OtherMapElements.h"
#include "NoGreenScreen.cpp"
void OtherMapElements::DisplayBomb(int code, QLabel* imageLabel)
{
}

void OtherMapElements::DisplayBonusLife(int code, QLabel* imageLabel)
{
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
