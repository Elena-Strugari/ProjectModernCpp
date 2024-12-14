#include "MainWindow.h"
#include "LoginWindow.h"
#include <QPixmap>
#include <QLabel>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), imageLabel(new QLabel(this)), textLabel(new QLabel("Start Game", this)) {
    QPixmap pixmap(":/startImage/resources/StartGame.jpg");
    if (!pixmap.isNull()) {
        imageLabel->setPixmap(pixmap.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setScaledContents(false); 

    textLabel->setAlignment(Qt::AlignCenter);
    textLabel->setStyleSheet(
        "font-size: 36px; "
        "color: white; "  
        "font-weight: bold;" 
    );

    QVBoxLayout* labelLayout = new QVBoxLayout(imageLabel);
    labelLayout->addWidget(textLabel);
    labelLayout->setAlignment(textLabel, Qt::AlignCenter);

    setCentralWidget(imageLabel);
    setWindowTitle("Start Game");
    resize(800, 600);
}

MainWindow::~MainWindow() {}

void MainWindow::resizeEvent(QResizeEvent* event) {
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
    LoginWindow* loginWindow = new LoginWindow();
    loginWindow->show();

    close();
}
