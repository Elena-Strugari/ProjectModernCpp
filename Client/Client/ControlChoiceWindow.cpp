#include "ControlChoiceWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QMessageBox>
#include <QPalette>
#include <QDebug>
#include <QResizeEvent>

ControlChoiceWindow::ControlChoiceWindow(const QString& clientId, QWidget* parent)
    : QWidget(parent), clientId(clientId), wasdButton(new QPushButton("Alege WASD", this)), arrowButton(new QPushButton("Alege Săgeți", this))
{
    qDebug() << "ControlChoiceWindow constructor called for user:" << clientId;

    QString buttonStyle =
        "font-size: 18px; "
        "color: white; "
        "background-color: rgba(0, 0, 128, 200); "
        "border: 2px solid white; "
        "border-radius: 10px; "
        "padding: 5px;";
    wasdButton->setStyleSheet(buttonStyle);
    arrowButton->setStyleSheet(buttonStyle);

    QLabel* mainImage = new QLabel(this);
    mainImage->setPixmap(QPixmap(":/images/directii.png").scaled(600, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    mainImage->setAlignment(Qt::AlignCenter);

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(wasdButton);
    buttonLayout->addSpacing(50);
    buttonLayout->addWidget(arrowButton);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(mainImage); 
    mainLayout->addLayout(buttonLayout);
    mainLayout->setAlignment(Qt::AlignCenter);

    setLayout(mainLayout);

    connect(wasdButton, &QPushButton::clicked, this, &ControlChoiceWindow::onWasdChosen);
    connect(arrowButton, &QPushButton::clicked, this, &ControlChoiceWindow::onArrowChosen);

    setWindowTitle("Alege Control");
    resize(800, 600);

    initializeBackground();
}
ControlChoiceWindow::~ControlChoiceWindow()
{
    qDebug() << "ControlChoiceWindow destructor called.";
}

void ControlChoiceWindow::initializeBackground()
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
void ControlChoiceWindow::onWasdChosen()
{
    qDebug() << "WASD controls chosen by user:" << clientId;

    QMessageBox::information(this, "Control Selectat", "Ați ales controalele WASD!");
    close(); 
}

void ControlChoiceWindow::onArrowChosen()
{
    qDebug() << "Arrow keys controls chosen by user:" << clientId;

    QMessageBox::information(this, "Control Selectat", "Ați ales controalele săgeți!");
    close();
}