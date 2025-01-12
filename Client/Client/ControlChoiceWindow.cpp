//#include "ControlChoiceWindow.h"
//#include <QVBoxLayout>
//#include <QHBoxLayout>
//#include <QLabel>
//#include <QPixmap>
//#include <QMessageBox>
//#include <QPalette>
//#include <QDebug>
//#include <QResizeEvent>
//
//ControlChoiceWindow::ControlChoiceWindow(const QString& clientId, QWidget* parent)
//    : QWidget(parent), clientId(clientId), wasdButton(new QPushButton("Alege WASD", this)), arrowButton(new QPushButton("Alege Săgeți", this))
//{
//    qDebug() << "ControlChoiceWindow constructor called for user:" << clientId;
//
//    QString buttonStyle =
//        "font-size: 18px; "
//        "color: white; "
//        "background-color: rgba(0, 0, 128, 200); "
//        "border: 2px solid white; "
//        "border-radius: 10px; "
//        "padding: 5px;";
//    wasdButton->setStyleSheet(buttonStyle);
//    arrowButton->setStyleSheet(buttonStyle);
//
//    QHBoxLayout* buttonLayout = new QHBoxLayout();
//    buttonLayout->addSpacing(100);
//    buttonLayout->addWidget(wasdButton);
//    buttonLayout->addSpacing(330);
//    buttonLayout->addWidget(arrowButton);
//    buttonLayout->addSpacing(150);
//
//    QVBoxLayout* mainLayout = new QVBoxLayout(this);
//    mainLayout->addStretch();
//    mainLayout->addLayout(buttonLayout);
//    mainLayout->addSpacing(150);
//
//    setLayout(mainLayout);
//
//    connect(wasdButton, &QPushButton::clicked, this, &ControlChoiceWindow::onWasdChosen);
//    connect(arrowButton, &QPushButton::clicked, this, &ControlChoiceWindow::onArrowChosen);
//
//    setWindowTitle("Alege Control");
//    resize(800, 600);
//
//    initializeBackground();
//}
//ControlChoiceWindow::~ControlChoiceWindow()
//{
//    qDebug() << "ControlChoiceWindow destructor called.";
//}
//
//void ControlChoiceWindow::initializeBackground()
//{
//    QImage image(":/Direction/resources/directii.png");
//
//    if (image.isNull())
//    {
//        qDebug() << "Failed to load background image!";
//        return;
//    }
//
//    QPalette palette;
//    palette.setBrush(QPalette::Window, QBrush(image.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)));
//    setPalette(palette);
//    setAutoFillBackground(true);
//}
//void ControlChoiceWindow::onWasdChosen()
//{
//    qDebug() << "WASD controls chosen by user:" << clientId;
//
//    QMessageBox::information(this, "Control Selectat", "Ați ales controalele WASD!");
//    close(); 
//}
//
//void ControlChoiceWindow::onArrowChosen()
//{
//    qDebug() << "Arrow keys controls chosen by user:" << clientId;
//
//    QMessageBox::information(this, "Control Selectat", "Ați ales controalele săgeți!");
//    close();
//}

#include "ControlChoiceWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QDebug>
#include <QLabel>

ControlChoiceWindow::ControlChoiceWindow(const QString& clientId, QWidget* parent)
    : QWidget(parent) // Setăm parent pentru ca Qt să gestioneze memoria
    , clientId(clientId)
    , upInput(new QLineEdit(this))
    , downInput(new QLineEdit(this))
    , leftInput(new QLineEdit(this))
    , rightInput(new QLineEdit(this))
    , saveButton(new QPushButton("Save Controls", this))
{
    qDebug() << "ControlChoiceWindow constructor called for user:" << clientId;

    setWindowTitle("Set Controls");
    resize(600, 400);

    initializeBackground();

    // Configurare stil și layout
    QString inputStyle =
        "font-size: 20px; "
        "color: black; "
        "border: 2px solid gray; "
        "border-radius: 5px; "
        "padding: 5px;";
    upInput->setStyleSheet(inputStyle);
    downInput->setStyleSheet(inputStyle);
    leftInput->setStyleSheet(inputStyle);
    rightInput->setStyleSheet(inputStyle);

    upInput->setPlaceholderText("Up");
    downInput->setPlaceholderText("Down");
    leftInput->setPlaceholderText("Left");
    rightInput->setPlaceholderText("Right");

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QHBoxLayout* inputsLayout = new QHBoxLayout();

    QVBoxLayout* leftLayout = new QVBoxLayout();
    leftLayout->addStretch();
    leftLayout->addWidget(leftInput);
    leftLayout->addStretch();

    QVBoxLayout* rightLayout = new QVBoxLayout();
    rightLayout->addStretch();
    rightLayout->addWidget(rightInput);
    rightLayout->addStretch();

    QVBoxLayout* centerLayout = new QVBoxLayout();
    centerLayout->addWidget(upInput, 0, Qt::AlignCenter);
    centerLayout->addWidget(new QLabel("Set Your Controls", this), 0, Qt::AlignCenter);
    centerLayout->addWidget(downInput, 0, Qt::AlignCenter);

    inputsLayout->addLayout(leftLayout);
    inputsLayout->addLayout(centerLayout);
    inputsLayout->addLayout(rightLayout);

    mainLayout->addLayout(inputsLayout);
    mainLayout->addWidget(saveButton, 0, Qt::AlignCenter);

    setLayout(mainLayout);

    connect(saveButton, &QPushButton::clicked, this, &ControlChoiceWindow::onSaveControls);
}

//void ControlChoiceWindow::onSaveControls()
//{
//    qDebug() << "Saving controls...";
//
//    controls["Up"] = upInput->text().trimmed();
//    controls["Down"] = downInput->text().trimmed();
//    controls["Left"] = leftInput->text().trimmed();
//    controls["Right"] = rightInput->text().trimmed();
//
//    qDebug() << "Controls collected: " << controls;
//
//    QSet<QString> uniqueKeys;
//    for (const QString& value : controls.values()) {
//        uniqueKeys.insert(value);
//    }
//
//    if (uniqueKeys.contains("") || uniqueKeys.size() != controls.size()) {
//        qDebug() << "Validation failed: Controls are not unique or empty!";
//        QMessageBox::warning(this, "Invalid Controls", "Please ensure all directions have unique keys!");
//        return;
//    }
//
//    qDebug() << "Controls validated successfully!";
//    emit controlsSet(controls); // Emitere semnal pentru setarea controalelor
//    QMessageBox::information(this, "Success", "Controls have been saved!");
//    this->hide(); // Ascunde fereastra în loc să o distrugem manual
//}


void ControlChoiceWindow::onSaveControls()
{
    qDebug() << "Saving controls...";

    controls["Up"] = upInput->text().trimmed();
    controls["Down"] = downInput->text().trimmed();
    controls["Left"] = leftInput->text().trimmed();
    controls["Right"] = rightInput->text().trimmed();

    qDebug() << "Controls collected: " << controls;

    //// Validare: toate tastele trebuie să fie unice și non-goale
    //QSet<QString> uniqueKeys;
    //for (const QString& value : controls.values()) {
    //    uniqueKeys.insert(value);
    //}

    //if (uniqueKeys.contains("") || uniqueKeys.size() != controls.size()) {
    //    qDebug() << "Validation failed: Controls are not unique or empty!";
    //    QMessageBox::warning(this, "Invalid Controls", "Please ensure all directions have unique keys!");
    //    return;
    //}

    qDebug() << "Controls validated successfully!";
    QMessageBox::information(this, "Success", "Controls have been saved!");

    // Închide fereastra fără a emite semnal
    close();
}


ControlChoiceWindow::~ControlChoiceWindow()
{
    qDebug() << "ControlChoiceWindow destructor called.";
}

void ControlChoiceWindow::initializeBackground()
{
    QImage image(":/StartImage/resources/StartGame.jpg"); // Calea ta din fișierul de resurse

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
