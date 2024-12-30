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

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addSpacing(100);
    buttonLayout->addWidget(wasdButton);
    buttonLayout->addSpacing(330);
    buttonLayout->addWidget(arrowButton);
    buttonLayout->addSpacing(150);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addStretch();
    mainLayout->addLayout(buttonLayout);
    mainLayout->addSpacing(150);

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
    QImage image(":/Direction/resources/directii.png");

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