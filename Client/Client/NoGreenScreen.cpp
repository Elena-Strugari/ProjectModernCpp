#include <QImage>
#include <QColor>

QImage removeGreenScreen(const QImage& inputImage, int threshold = 30) {
    QImage resultImage = inputImage;
    int width = resultImage.width();
    int height = resultImage.height();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            QColor pixelColor = resultImage.pixelColor(x, y);
            int red = pixelColor.red();
            int green = pixelColor.green();
            int blue = pixelColor.blue();
            if (green > red + threshold && green > blue + threshold) {
                resultImage.setPixelColor(x, y, QColor(0, 0, 0, 0));
            }
        }
    }
    return resultImage;
}
