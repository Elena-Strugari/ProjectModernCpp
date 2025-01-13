export module BackgroundManager;

import <QWidget>;
import <QImage>;
import <QPalette>;
import <QBrush>;
import <QResizeEvent>;
import <QDebug>;

export class BackgroundManager
{
public:
    static void SetBackground(QWidget* widget)
    {
        QImage image(":/StartImage/resources/StartGame.jpg");

        if (image.isNull())
        {
            qDebug() << "Failed to load background image!";
            return;
        }

        QPalette palette;
        palette.setBrush(QPalette::Window, QBrush(image.scaled(widget->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)));
        widget->setPalette(palette);
        widget->setAutoFillBackground(true);
    }

    static void HandleResizeEvent(QWidget* widget, QResizeEvent* event)
    {
        QImage image(":/StartImage/resources/StartGame.jpg");

        if (!image.isNull())
        {
            QPalette palette;
            palette.setBrush(QPalette::Window, QBrush(image.scaled(widget->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)));
            widget->setPalette(palette);
        }

        QWidget::resizeEvent(event);
    }
};
