#include "LevelSelectionWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPalette>
#include <QImage>
#include <QDebug>

LevelSelectionWindow::LevelSelectionWindow(QWidget* parent)
    : QWidget(parent)
    , titleLabel(new QLabel("Choose Difficulty", this))
    , easyButton(new QPushButton("Easy", this))
    , mediumButton(new QPushButton("Medium", this))
    , hardButton(new QPushButton("Hard", this))
{
    setWindowTitle("Select Level");
    resize(600, 400);

    // Inițializează fundalul
    initializeBackground();

    // Configurare stil pentru titlu
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet(
        "font-size: 24px; "
        "color: white; "
        "font-weight: bold; "
        "margin-bottom: 20px;"
    );

    // Stilizare butoane
    QString buttonStyle =
        "font-size: 18px; "
        "color: white; "
        "background-color: rgba(0, 0, 128, 200); "
        "border: 2px solid white; "
        "border-radius: 10px; "
        "padding: 10px;";
    easyButton->setStyleSheet(buttonStyle);
    mediumButton->setStyleSheet(buttonStyle);
    hardButton->setStyleSheet(buttonStyle);

    // Dimensiuni fixe pentru butoane
    easyButton->setFixedSize(100, 50);
    mediumButton->setFixedSize(100, 50);
    hardButton->setFixedSize(100, 50);

    // Layout pentru butoane în linie, cu spațiere
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->setSpacing(20); // Spațiere între butoane
    buttonLayout->addStretch();
    buttonLayout->addWidget(easyButton);
    buttonLayout->addWidget(mediumButton);
    buttonLayout->addWidget(hardButton);
    buttonLayout->addStretch();

    // Layout principal
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addStretch();
    mainLayout->addWidget(titleLabel);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addStretch();
    setLayout(mainLayout);

    // Conectează semnalele butoanelor la semnalul `levelSelected`
    connect(easyButton, &QPushButton::clicked, this, [this]() {
        emit levelSelected("Easy");
        this->close(); // Închidem complet fereastra
        });

    connect(mediumButton, &QPushButton::clicked, this, [this]() {
        emit levelSelected("Medium");
        this->close(); // Închidem complet fereastra
        });

    connect(hardButton, &QPushButton::clicked, this, [this]() {
        emit levelSelected("Hard");
        this->close(); // Închidem complet fereastra
        });
}

LevelSelectionWindow::~LevelSelectionWindow() = default;

void LevelSelectionWindow::initializeBackground()
{
    QImage image(":/StartImage/resources/StartGame.jpg"); // Calea ta pentru fundal

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
