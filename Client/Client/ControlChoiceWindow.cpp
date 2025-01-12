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
    , ShootInput(new QLineEdit(this))
    , saveButton(new QPushButton("Save Controls", this))
{
    qDebug() << "ControlChoiceWindow constructor called for user:" << clientId;

    setWindowTitle("Set Controls");
    resize(600, 400);

    InitializeBackground();

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
    ShootInput->setStyleSheet(inputStyle);

    upInput->setPlaceholderText("Up");
    downInput->setPlaceholderText("Down");
    leftInput->setPlaceholderText("Left");
    rightInput->setPlaceholderText("Right");
    ShootInput->setPlaceholderText("Shoot");

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

    QVBoxLayout* shootLayout = new QVBoxLayout();  // Layout pentru ShootInput
    shootLayout->addStretch();
    shootLayout->addWidget(ShootInput);
    shootLayout->addStretch();

    inputsLayout->addLayout(leftLayout);
    inputsLayout->addLayout(centerLayout);
    inputsLayout->addLayout(rightLayout);
    inputsLayout->addLayout(shootLayout);

    mainLayout->addLayout(inputsLayout);
    mainLayout->addWidget(saveButton, 0, Qt::AlignCenter);

    setLayout(mainLayout);

    connect(saveButton, &QPushButton::clicked, this, &ControlChoiceWindow::OnSaveControls);
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


void ControlChoiceWindow::OnSaveControls()
{
    qDebug() << "Saving controls...";

    controls["Up"] = upInput->text().trimmed();
    controls["Down"] = downInput->text().trimmed();
    controls["Left"] = leftInput->text().trimmed();
    controls["Right"] = rightInput->text().trimmed();
    controls["Shoot"] = ShootInput->text().trimmed();


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
    emit ControlsSet(controls);

    qDebug() << "Controls validated successfully!";
    QMessageBox::information(this, "Success", "Controls have been saved!");

    // Închide fereastra fără a emite semnal
    close();
}


ControlChoiceWindow::~ControlChoiceWindow()
{
    qDebug() << "ControlChoiceWindow destructor called.";
}

void ControlChoiceWindow::InitializeBackground()
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

void ControlChoiceWindow::keyPressEvent(QKeyEvent* event)
{
    QString keyText;

    switch (event->key()) {
    case Qt::Key_Up: keyText = "ArrowUp"; break;
    case Qt::Key_Down: keyText = "ArrowDown"; break;
    case Qt::Key_Left: keyText = "ArrowLeft"; break;
    case Qt::Key_Right: keyText = "ArrowRight"; break;

    case Qt::Key_Enter: keyText = "Enter"; break;
    case Qt::Key_Alt: keyText = "Alt"; break;
    case Qt::Key_Shift: keyText = "Shift"; break;
    case Qt::Key_Control: keyText = "Ctrl"; break;
    case Qt::Key_Space: keyText = "Space"; break;
    case Qt::Key_Tab: keyText = "Tab"; break;
    case Qt::Key_CapsLock: keyText = "Caps"; break;
    case Qt::Key_Backspace: keyText = "Backspace"; break;
    case Qt::Key_Delete:keyText = "Delete"; break;

    case Qt::Key_F1: keyText = "F1"; break;
    case Qt::Key_F2: keyText = "F2"; break;
    case Qt::Key_F3: keyText = "F3"; break;
    case Qt::Key_F4: keyText = "F4"; break;
    case Qt::Key_F5: keyText = "F5"; break;
    case Qt::Key_F6: keyText = "F6"; break;
    case Qt::Key_F7: keyText = "F7"; break;
    case Qt::Key_F8: keyText = "F8"; break;
    case Qt::Key_F9: keyText = "F9"; break;
    case Qt::Key_F10: keyText = "F10"; break;
    case Qt::Key_F11: keyText = "F11"; break;
    case Qt::Key_F12: keyText = "F12"; break;

    
    default: keyText = QKeySequence(event->key()).toString(); break;  // Pentru litere, cifre și alte taste
    }

    if (!keyText.isEmpty()) {
        // Afișăm tasta apăsată în linia de editare
        // În funcție de focus-ul pe care îl are linia de editare, setăm textul respectiv
        if (upInput->hasFocus()) {
            upInput->setText(keyText);
        }
        else if (downInput->hasFocus()) {
            downInput->setText(keyText);
        }
        else if (leftInput->hasFocus()) {
            leftInput->setText(keyText);
        }
        else if (rightInput->hasFocus()) {
            rightInput->setText(keyText);
        }
    }

    event->accept();  // Prevenim comportamentul implicit (de exemplu, setarea textului)
}

