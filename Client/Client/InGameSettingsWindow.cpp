#include "InGameSettingsWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QImage>
#include <QPalette>
#include <QDebug>

InGameSettingsWindow::InGameSettingsWindow(QWidget* parent)
    : QWidget(parent),
    musicVolumeSlider(new QSlider(Qt::Horizontal, this)),
    backToGameButton(new QPushButton("Back to Game", this)),
    //editControlsButton(new QPushButton("Edit Controls", this)),
    exitGameButton(new QPushButton("Exit Game", this)),
    saveSettingsButton(new QPushButton("Save Settings", this))
{
    setWindowTitle("In-Game Settings");
    resize(300, 200);

    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setStyleSheet("background-color: rgba(0, 0, 50, 180); border-radius: 20px;");
    //setAttribute(Qt::WA_TranslucentBackground);
    setAutoFillBackground("background_color: rgba(0,0,0,155); border-radius: 20px;");

    musicVolumeSlider->setRange(0, 100);
    musicVolumeSlider->setValue(50);
    musicVolumeSlider->setFixedWidth(400);

    // Stil butoane
    QString buttonStyle =
        "font-size: 16px; "
        "color: white; "
        "background-color: rgba(0, 0, 128, 200); "
        "border: 2px solid white; "
        "border-radius: 10px; "
        "padding: 5px;";
    backToGameButton->setStyleSheet(buttonStyle);
    //editControlsButton->setStyleSheet(buttonStyle);
    exitGameButton->setStyleSheet(buttonStyle);
    saveSettingsButton->setStyleSheet(buttonStyle);

    // Setăm dimensiuni fixe pentru butoane
    QSize buttonSize(150, 40);
    backToGameButton->setFixedSize(buttonSize);
    //editControlsButton->setFixedSize(buttonSize);
    exitGameButton->setFixedSize(buttonSize);
    saveSettingsButton->setFixedSize(buttonSize);

    // Layout pentru slider-ul de volum
    QVBoxLayout* slidersLayout = new QVBoxLayout();
    QLabel* musicLabel = new QLabel("Music Volume", this);
    musicLabel->setAlignment(Qt::AlignCenter);
    musicLabel->setStyleSheet("font-size: 18px; color: white;");

    slidersLayout->addWidget(musicLabel);
    slidersLayout->addWidget(musicVolumeSlider);
    slidersLayout->setAlignment(Qt::AlignCenter);

    // Layout pentru butoane
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    buttonLayout->addWidget(backToGameButton);
    buttonLayout->addSpacing(50);
   // buttonLayout->addWidget(editControlsButton);
   // buttonLayout->addSpacing(50);
    buttonLayout->addWidget(exitGameButton);
    buttonLayout->addSpacing(50);
    buttonLayout->addWidget(saveSettingsButton);
    buttonLayout->addStretch();

    // Layout principal
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QLabel* titleLabel = new QLabel("In-Game Settings", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 32px; font-weight: bold; color: white;");
    titleLabel->setContentsMargins(0, 20, 0, 10); // Spațiu suplimentar pentru titlu

    mainLayout->addWidget(titleLabel);
    mainLayout->addStretch();
    mainLayout->addLayout(slidersLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(buttonLayout);
    mainLayout->addStretch();

    setLayout(mainLayout);

    // Conexiuni pentru butoane
    connect(backToGameButton, &QPushButton::clicked, this, &InGameSettingsWindow::onBackToGame);
    connect(exitGameButton, &QPushButton::clicked, this, &InGameSettingsWindow::onExitGame);
    connect(saveSettingsButton, &QPushButton::clicked, this, &InGameSettingsWindow::onSaveSettings);
}

InGameSettingsWindow::~InGameSettingsWindow()
{
}

void InGameSettingsWindow::onBackToGame()
{
    qDebug() << "Back to Game clicked.";
    emit backToGame(); // Emiterea semnalului
    this->close();
}


void InGameSettingsWindow::onExitGame()
{
    qDebug() << "Exit Game clicked.";
    QMessageBox::information(this, "Exit", "Exit button clicked.");
    emit exitGame(); // Emiterea semnalului
}
void InGameSettingsWindow::onSaveSettings()
{
    qDebug() << "Save settings clicked.";
    QMessageBox::information(this, "Save", "Save Settings clicked.");
    emit SaveSettings(musicVolumeSlider->value()); // Emiterea semnalului
}
//void InGameSettingsWindow::resizeEvent(QResizeEvent* event)
//{
//    // Setează fundalul semi-transparent
//  //  QImage image(":/StartImage/resources/StartGame.jpg");
//        QPalette palette;
//
//        // Setăm culoarea semi-transparentă pentru fundal
//        QColor semiTransparentColor(0, 0, 0, 200); // Negru semi-transparent
//        QBrush brush(semiTransparentColor);
//        palette.setBrush(QPalette::Window, brush);
//        // Aplicăm fundalul
//        setPalette(palette);
//    QWidget::resizeEvent(event);
//}

void InGameSettingsWindow::positionInTopRight(QWidget* parent) {
    if (parent) {
        int x = parent->x() + parent->width() - width() - 300;
        int y = parent->y() + 50;
        move(x, y);
    }
}