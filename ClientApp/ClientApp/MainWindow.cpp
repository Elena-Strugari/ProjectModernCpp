#include "MainWindow.h"
#include "LoginWindow.h"
#include <QPixmap>
#include <QLabel>
#include <QVBoxLayout>
#include <QGraphicsOpacityEffect>

MainWindow::MainWindow(QWidget* parent) : QWidget(parent), imageLabel(new QLabel(this)), textLabel(new QLabel("Start Game", this)) {
    // Layout principal
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);

    // Imaginea de fundal
    QPixmap pixmap(":/startImage/resources/StartGame.jpg");
    imageLabel->setPixmap(pixmap.scaled(800, 600, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
    imageLabel->setScaledContents(true);
    imageLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(imageLabel);

    // Textul "Start Game"
    textLabel->setAlignment(Qt::AlignCenter);
    textLabel->setStyleSheet(
        "font-size: 36px; "
        "color: white; "
        "font-weight: bold; "
        "background-color: rgba(0, 0, 0, 128); " // Fundal semitransparent
        "padding: 10px; "
        "border-radius: 10px;"
    );

    // Suprapunem textul peste imagine
    imageLabel->setLayout(new QVBoxLayout());
    imageLabel->layout()->addWidget(textLabel);
    imageLabel->layout()->setAlignment(textLabel, Qt::AlignCenter);

    setLayout(layout);
    setWindowTitle("Start Game");
    resize(800, 600);
}

void MainWindow::resizeEvent(QResizeEvent* event) {
    // Actualizăm imaginea de fundal la dimensiunea ferestrei
    QPixmap pixmap(":/startImage/resources/StartGame.jpg");
    if (!pixmap.isNull()) {
        imageLabel->setPixmap(pixmap.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
    }
    QWidget::resizeEvent(event);
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
        onStartGameClicked();
    }
}

void MainWindow::onStartGameClicked() {
    // Deschidem LoginWindow
    LoginWindow* loginWindow = new LoginWindow();
    loginWindow->show();

    // Închidem fereastra curentă
    close();
}
