//Am comentat pentru a testa afisarea hartii

#include "MainWindow.h"
#include "LoginWindow.h"
#include <QPixmap>
#include <QLabel>
#include <QVBoxLayout>
#include <QGraphicsOpacityEffect>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), imageLabel(new QLabel(this)), textLabel(new QLabel("Start Game", this)) {
    QPixmap pixmap(":/startImage/resources/StartGame.jpg");
    if (!pixmap.isNull()) {
        imageLabel->setPixmap(pixmap.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setScaledContents(false); // Nu forțăm scalarea completă

    textLabel->setAlignment(Qt::AlignCenter);
    textLabel->setStyleSheet(
        "font-size: 36px; "
        "color: white; "
        "font-weight: bold; "
        "background-color: rgba(0, 0, 0, 128); "
        "padding: 10px; "
        "border-radius: 10px;"
    );

    // Adăugăm textul peste imagine
    QVBoxLayout* labelLayout = new QVBoxLayout(imageLabel);
    labelLayout->addWidget(textLabel);
    labelLayout->setAlignment(textLabel, Qt::AlignCenter);

    setCentralWidget(imageLabel); // Setăm imaginea ca widget central
    setWindowTitle("Start Game");
    resize(800, 600);
}

MainWindow::~MainWindow() {

}

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


//#include "MainWindow.h"
//
//MainWindow::MainWindow(QWidget* parent)
//    : QMainWindow(parent), map(new ClientMap(this)) 
//{
//    qDebug() << "Initializing MainWindow...";
//    // Create and initialize the map
//    map->Initialize(10, 10); // Example: 10x10 grid
//    qDebug() << "Map initialized.";
//    // Set the map as the central widget
//    setCentralWidget(map);
//    qDebug() << "Map set as central widget.";
//}
//
//MainWindow::~MainWindow() {
//    // No need to delete map because it has MainWindow as a parent
//}
//
