//////#include "StartGameWindow.h"
//////#include <QPixmap>
//////#include <QLabel>
//////#include <QVBoxLayout>
//////
////////StartGameWindow::StartGameWindow(QWidget* parent)
////////    : QWidget(parent)
////////    , imageLabel(new QLabel(this))
////////    , textLabel(new QLabel("Start Game", this))
////////{
////////    setFocusPolicy(Qt::StrongFocus); // Ensure widget accepts focus
////////
////////    QPixmap pixmap(":/startImage/resources/StartGame.jpg");
////////    if (!pixmap.isNull()) {
////////        imageLabel->setPixmap(pixmap.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
////////    }
////////    imageLabel->setAlignment(Qt::AlignCenter);
////////    imageLabel->setScaledContents(false);
////////
////////    textLabel->setAlignment(Qt::AlignCenter);
////////    textLabel->setStyleSheet(
////////        "font-size: 36px; "
////////        "color: white; "
////////        "font-weight: bold;"
////////    );
////////
////////    QVBoxLayout* labelLayout = new QVBoxLayout(imageLabel);
////////    labelLayout->addWidget(textLabel);
////////    labelLayout->setAlignment(textLabel, Qt::AlignCenter);
////////
////////    QVBoxLayout* mainLayout = new QVBoxLayout(this);
////////    mainLayout->addWidget(imageLabel);
////////    setLayout(mainLayout);
////////
////////    setWindowTitle("Start Game");
////////    resize(800, 600); // Fixed window size
////////}
//////
//////
//////StartGameWindow::StartGameWindow(QWidget* parent)
//////    : QWidget(parent)
//////    , imageLabel(new QLabel(this))
//////    , textLabel(new QLabel("Start Game", this))
//////{
//////    //qDebug() << "StartGameWindow constructor called.";
//////    //setFocusPolicy(Qt::StrongFocus); // Ensure widget accepts focus
//////
//////    //imageLabel->setAlignment(Qt::AlignCenter);
//////    //imageLabel->setScaledContents(false);
//////
//////    //textLabel->setAlignment(Qt::AlignCenter);
//////    //textLabel->setStyleSheet(
//////    //    "font-size: 36px; "
//////    //    "color: white; "
//////    //    "font-weight: bold;"
//////    //);
//////
//////    //QVBoxLayout* labelLayout = new QVBoxLayout(imageLabel);
//////    //labelLayout->addWidget(textLabel);
//////    //labelLayout->setAlignment(textLabel, Qt::AlignCenter);
//////
//////    //QVBoxLayout* mainLayout = new QVBoxLayout(this);
//////    //mainLayout->addWidget(imageLabel);
//////    //setLayout(mainLayout);
//////
//////    //setWindowTitle("Start Game");
//////    //resize(800, 600); // Fixed window size
//////}
//////
////////Adaug o noua metoda pentru a initializa imaginea de fundal inafara constructorului, astfel incat sa nu se declanseze QPixmap inainte de QAplication
////////void StartGameWindow::initializeBackground()
////////{
////////    QPixmap pixmap(":/StartImage/resources/StartGame.jpg");
////////    if (pixmap.isNull())
////////    {
////////        textLabel->setText("Failed to load background image");
////////    }
////////    else 
////////    {
////////        imageLabel->setPixmap(pixmap.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
////////    }
////////}
//////void StartGameWindow::initializeBackground()
//////{
//////    /*QPixmap pixmap(":/StartImage/resources/StartGame.jpg");
//////    qDebug() << "Loading background image in initializeBackground";
//////    if (pixmap.isNull())
//////    {
//////        qDebug() << "Failed to load background image.";
//////        textLabel->setText("Failed to load background image");
//////    }
//////    else
//////    {
//////        imageLabel->setPixmap(pixmap.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
//////    }*/
//////}
//////
//////
//////StartGameWindow::~StartGameWindow() 
//////{
//////    //EMPTY
//////}
//////
//////void StartGameWindow::resizeEvent(QResizeEvent* event) 
//////{
//////    /*QPixmap pixmap(":/StartImage/resources/StartGame.jpg");
//////    if (pixmap.isNull()) 
//////      {
//////        textLabel->setText("Failed to load background image");
//////      }
//////    else
//////    {
//////        imageLabel->setPixmap(pixmap.scaled(event->size().boundedTo(QSize(800, 600)), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
//////    }
//////    QWidget::resizeEvent(event);*/
//////}
//////
//////void StartGameWindow::keyPressEvent(QKeyEvent* event) 
//////{
//////    //if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
//////    //{
//////    //    emit startGame(); // Emit the signal
//////    //    qDebug() << "startGame signal emitted"; // Debug log
//////    //}
//////    //else 
//////    //{
//////    //    QWidget::keyPressEvent(event);
//////    //}
//////}
////#include "StartGameWindow.h"
////#include <QLabel>
////#include <QVBoxLayout>
////
////// Constructor
////StartGameWindow::StartGameWindow(QWidget* parent)
////    : QWidget(parent)
////    , imageLabel(new QLabel(this))
////    , textLabel(new QLabel("Start Game", this))
////{
////    qDebug() << "StartGameWindow constructor called.";
////
////    // Styling the image label
////    imageLabel->setAlignment(Qt::AlignCenter);
////    imageLabel->setScaledContents(false);
////
////    // Styling the text label
////    textLabel->setAlignment(Qt::AlignCenter);
////    textLabel->setStyleSheet(
////        "font-size: 36px; "
////        "color: white; "
////        "font-weight: bold;"
////    );
////
////    // Layout for labels
////    QVBoxLayout* labelLayout = new QVBoxLayout(imageLabel);
////    labelLayout->addWidget(textLabel);
////    labelLayout->setAlignment(textLabel, Qt::AlignCenter);
////
////    // Main layout
////    QVBoxLayout* mainLayout = new QVBoxLayout(this);
////    mainLayout->addWidget(imageLabel);
////    setLayout(mainLayout);
////
////    setWindowTitle("Start Game");
////    resize(800, 600);
////
////    // Commented out background initialization for debugging
////    // QPixmap pixmap(":/StartImage/resources/StartGame.jpg");
////    // if (!pixmap.isNull()) {
////    //     imageLabel->setPixmap(pixmap.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
////    // }
////}
////
////// Resize event
////void StartGameWindow::resizeEvent(QResizeEvent* event)
////{
////    // Commented out QPixmap initialization for debugging
////    // QPixmap pixmap(":/StartImage/resources/StartGame.jpg");
////    // if (!pixmap.isNull()) {
////    //     imageLabel->setPixmap(pixmap.scaled(event->size().boundedTo(QSize(800, 600)), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
////    // }
////    QWidget::resizeEvent(event);
////}
////
////// Key press event
////void StartGameWindow::keyPressEvent(QKeyEvent* event) {
////    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
////        emit startGame(); // Emit the signal
////        qDebug() << "startGame signal emitted"; // Debug log
////    }
////    else {
////        QWidget::keyPressEvent(event);
////    }
////}
////StartGameWindow::~StartGameWindow() 
////{
////    // EMPTY
////}
////...................................................................................
//#include "StartGameWindow.h"
//#include <QLabel>
//#include <QVBoxLayout>
//#include <QPalette>
//#include <QImage>
//#include <QDebug>
//
//// Constructor
//StartGameWindow::StartGameWindow(QWidget* parent)
//    : QWidget(parent)
//    , imageLabel(new QLabel(this))
//    , textLabel(new QLabel("Start Game", this))
//{
//    qDebug() << "StartGameWindow constructor called.";
//
//    // Styling the text label
//    textLabel->setAlignment(Qt::AlignCenter);
//    textLabel->setStyleSheet(
//        "font-size: 36px; "
//        "color: white; "
//        "font-weight: bold;"
//    );
//
//    // Layout for labels
//    QVBoxLayout* mainLayout = new QVBoxLayout(this);
//    mainLayout->addWidget(textLabel);
//    mainLayout->setAlignment(Qt::AlignCenter);
//    setLayout(mainLayout);
//
//    // Initialize background
//    initializeBackground();
//
//    setWindowTitle("Start Game");
//    resize(800, 600);
//}
//
//// Method to initialize the background
//void StartGameWindow::initializeBackground()
//{
//    QImage image(":/StartImage/resources/StartGame.jpg"); // Replace with your actual image path
//    if (image.isNull()) {
//        qDebug() << "Failed to load background image!";
//        return;
//    }
//
//    QPalette palette;
//    palette.setBrush(QPalette::Window, QBrush(image.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)));
//    setPalette(palette);
//    setAutoFillBackground(true);
//}
//
//// Resize event
//void StartGameWindow::resizeEvent(QResizeEvent* event)
//{
//    QImage image(":/StartImage/resources/StartGame.jpg"); // Replace with your actual image path
//    if (!image.isNull()) {
//        QPalette palette;
//        palette.setBrush(QPalette::Window, QBrush(image.scaled(event->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)));
//        setPalette(palette);
//    }
//    QWidget::resizeEvent(event);
//}
//
//// Key press event
//void StartGameWindow::keyPressEvent(QKeyEvent* event)
//{
//    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
//        emit startGame(); // Emit the signal
//        qDebug() << "startGame signal emitted"; // Debug log
//    }
//    else {
//        QWidget::keyPressEvent(event);
//    }
//}
//
//StartGameWindow::~StartGameWindow()
//{
//    // EMPTY
//}


#include "StartGameWindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QPalette>
#include <QImage>
#include <QKeyEvent>

StartGameWindow::StartGameWindow(QWidget* parent)
    : QWidget(parent)
    , textLabel(new QLabel("Una Nueva Galaxia - Beyond the Stars", this))
    , startGameButton(new QPushButton("Start Game", this))
{
    qDebug() << "StartGameWindow constructor called.";
    qDebug() << "Current working directory:" << QDir::currentPath();

    InitializeBackground();

    setAutoFillBackground(true);
    textLabel->setAlignment(Qt::AlignCenter);
    textLabel->setStyleSheet(
        "font-size: 36px; "
        "color: white; "
        "font-weight: bold;"
    );

    QString buttonStyle =
        "font-size: 18px; "
        "color: white; "
        "background-color: rgba(0, 0, 128, 200); "
        "border: 2px solid white; "
        "border-radius: 10px; "
        "padding: 10px;";
    startGameButton->setStyleSheet(buttonStyle);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(textLabel);
    mainLayout->addWidget(startGameButton);
    mainLayout->setAlignment(Qt::AlignCenter);
    mainLayout->setSpacing(20);
    setLayout(mainLayout);
    setWindowTitle("Start Game");
    resize(800, 600);
    connect(startGameButton, &QPushButton::clicked, this, &StartGameWindow::triggerStartGame);
}


void StartGameWindow::InitializeBackground()
{
    QImage image(":/StartImage/resources/StartGame.jpg"); 

    if (image.isNull()) 
    {
        qDebug() << "Failed to load background image!";
        return;
    }

    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(image.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)));
    setPalette(palette);
    setAutoFillBackground(true);
}


void StartGameWindow::triggerStartGame()
{
    qDebug() << "Start Game triggered!";
    emit startGame(); 
}


void StartGameWindow::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) 
    {
        triggerStartGame(); 
    }
    else 
    {
        QWidget::keyPressEvent(event);
    }
}

void StartGameWindow::resizeEvent(QResizeEvent* event)
{
    QImage image(":/StartImage/resources/StartGame.jpg");

    if (!image.isNull())
    {
        QPalette palette;
        palette.setBrush(QPalette::Window, QBrush(image.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)));
        setPalette(palette);
    }
    QWidget::resizeEvent(event);
}

StartGameWindow::~StartGameWindow() = default;
