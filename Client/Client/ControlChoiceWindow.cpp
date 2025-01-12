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

//#include "ControlChoiceWindow.h"
//#include <QVBoxLayout>
//#include <QHBoxLayout>
//#include <QMessageBox>
//#include <QDebug>
//#include <QLabel>
//
//
//
//ControlChoiceWindow::ControlChoiceWindow(const QString& clientId, QWidget* parent)
//    : QWidget(parent) // Setăm parent pentru ca Qt să gestioneze memoria
//    , clientId(clientId)
//    , upInput(new QLineEdit(this))
//    , downInput(new QLineEdit(this))
//    , leftInput(new QLineEdit(this))
//    , rightInput(new QLineEdit(this))
//    , shootInput(new QLineEdit(this))
//    , saveButton(new QPushButton("Save Controls", this))
//    , resetButton(new QPushButton("Reset Controls", this)) // Adăugăm butonul Reset
//{
//    qDebug() << "ControlChoiceWindow constructor called for user:" << clientId;
//
//    setWindowTitle("Set Controls");
//    resize(600, 400);
//
//    InitializeBackground();
//
//    // Configurare stil și layout
//    QString inputStyle =
//        "font-size: 20px; "
//        "color: black; "
//        "border: 2px solid gray; "
//        "border-radius: 5px; "
//        "padding: 5px;";
//    upInput->setStyleSheet(inputStyle);
//    downInput->setStyleSheet(inputStyle);
//    leftInput->setStyleSheet(inputStyle);
//    rightInput->setStyleSheet(inputStyle);
//    shootInput->setStyleSheet(inputStyle);
//
//    upInput->setPlaceholderText("Up");
//    downInput->setPlaceholderText("Down");
//    leftInput->setPlaceholderText("Left");
//    rightInput->setPlaceholderText("Right");
//    shootInput->setPlaceholderText("Shoot");
//
//    QVBoxLayout* mainLayout = new QVBoxLayout(this);
//    QHBoxLayout* inputsLayout = new QHBoxLayout();
//
//    QVBoxLayout* leftLayout = new QVBoxLayout();
//    leftLayout->addStretch();
//    leftLayout->addWidget(leftInput);
//    leftLayout->addStretch();
//
//    QVBoxLayout* rightLayout = new QVBoxLayout();
//    rightLayout->addStretch();
//    rightLayout->addWidget(rightInput);
//    rightLayout->addStretch();
//
//    QVBoxLayout* centerLayout = new QVBoxLayout();
//    centerLayout->addWidget(upInput, 0, Qt::AlignCenter);
//    centerLayout->addWidget(new QLabel("Set Your Controls", this), 0, Qt::AlignCenter);
//    centerLayout->addWidget(downInput, 0, Qt::AlignCenter);
//
//    QVBoxLayout* shootLayout = new QVBoxLayout(); // Layout pentru ShootInput
//    shootLayout->addStretch();
//    shootLayout->addWidget(shootInput);
//    shootLayout->addStretch();
//
//    inputsLayout->addLayout(leftLayout);
//    inputsLayout->addLayout(centerLayout);
//    inputsLayout->addLayout(rightLayout);
//    inputsLayout->addLayout(shootLayout);
//
//    mainLayout->addLayout(inputsLayout);
//
//    // Layout pentru butoanele Save și Reset
//    QHBoxLayout* buttonLayout = new QHBoxLayout();
//    buttonLayout->addStretch();
//    buttonLayout->addWidget(resetButton); // Adăugăm Reset Button
//    buttonLayout->addWidget(saveButton);  // Adăugăm Save Button
//    mainLayout->addLayout(buttonLayout); // Adăugăm butoanele în layout-ul principal
//
//    setLayout(mainLayout);
//
//    connect(saveButton, &QPushButton::clicked, this, &ControlChoiceWindow::OnSaveControls);
//    connect(resetButton, &QPushButton::clicked, this, &ControlChoiceWindow::OnResetControls); // Conectăm butonul Reset
//}
//
//void ControlChoiceWindow::OnResetControls()
//{
//    // Resetăm câmpurile de input și reactivăm widget-urile
//    upInput->clear();
//    downInput->clear();
//    leftInput->clear();
//    rightInput->clear();
//    shootInput->clear();
//
//    upInput->setEnabled(true);
//    downInput->setEnabled(true);
//    leftInput->setEnabled(true);
//    rightInput->setEnabled(true);
//    shootInput->setEnabled(true);
//
//    qDebug() << "Controls have been reset.";
//}
//
////void ControlChoiceWindow::onSaveControls()
////{
////    qDebug() << "Saving controls...";
////
////    controls["Up"] = upInput->text().trimmed();
////    controls["Down"] = downInput->text().trimmed();
////    controls["Left"] = leftInput->text().trimmed();
////    controls["Right"] = rightInput->text().trimmed();
////
////    qDebug() << "Controls collected: " << controls;
////
////    QSet<QString> uniqueKeys;
////    for (const QString& value : controls.values()) {
////        uniqueKeys.insert(value);
////    }
////
////    if (uniqueKeys.contains("") || uniqueKeys.size() != controls.size()) {
////        qDebug() << "Validation failed: Controls are not unique or empty!";
////        QMessageBox::warning(this, "Invalid Controls", "Please ensure all directions have unique keys!");
////        return;
////    }
////
////    qDebug() << "Controls validated successfully!";
////    emit controlsSet(controls); // Emitere semnal pentru setarea controalelor
////    QMessageBox::information(this, "Success", "Controls have been saved!");
////    this->hide(); // Ascunde fereastra în loc să o distrugem manual
////}
//
//
//void ControlChoiceWindow::OnSaveControls()
//{
//    qDebug() << "Saving controls...";
//
//    controls["Up"] = upInput->text().trimmed();
//    controls["Down"] = downInput->text().trimmed();
//    controls["Left"] = leftInput->text().trimmed();
//    controls["Right"] = rightInput->text().trimmed();
//    controls["Shoot"] = shootInput->text().trimmed();
//
//
//    qDebug() << "Controls collected: " << controls;
//
//    //// Validare: toate tastele trebuie să fie unice și non-goale
//    //QSet<QString> uniqueKeys;
//    //for (const QString& value : controls.values()) {
//    //    uniqueKeys.insert(value);
//    //}
//
//    //if (uniqueKeys.contains("") || uniqueKeys.size() != controls.size()) {
//    //    qDebug() << "Validation failed: Controls are not unique or empty!";
//    //    QMessageBox::warning(this, "Invalid Controls", "Please ensure all directions have unique keys!");
//    //    return;
//    //}
//    emit ControlsSet(controls);
//
//}
//
//ControlChoiceWindow::~ControlChoiceWindow()
//{
//    qDebug() << "ControlChoiceWindow destructor called.";
//}
//
//void ControlChoiceWindow::InitializeBackground()
//{
//    QImage image(":/StartImage/resources/StartGame.jpg"); // Calea ta din fișierul de resurse
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
//
//void ControlChoiceWindow::keyPressEvent(QKeyEvent* event)
//{
//    QString keyText;
//
//    switch (event->key()) {
//    case Qt::Key_Up: keyText = "ArrowUp"; break;
//    case Qt::Key_Down: keyText = "ArrowDown"; break;
//    case Qt::Key_Left: keyText = "ArrowLeft"; break;
//    case Qt::Key_Right: keyText = "ArrowRight"; break;
//    case Qt::Key_Enter: keyText = "Enter"; break;
//    case Qt::Key_Alt: keyText = "Alt"; break;
//    case Qt::Key_Shift: keyText = "Shift"; break;
//    case Qt::Key_Control: keyText = "Ctrl"; break;
//    case Qt::Key_Space: keyText = "Space"; break;
//    default: keyText = QKeySequence(event->key()).toString(); break; // Pentru alte taste
//    }
//
//    qDebug() << "Key pressed:" << event->key();
//
//    if (!keyText.isEmpty()) {
//        // Verificăm dacă tasta nu este deja setată și dacă linia de editare are focus
//        if (upInput->hasFocus() && upInput->text().isEmpty()) {
//            upInput->setText(keyText);
//            upInput->setEnabled(false); // Blochează câmpul
//        }
//        else if (downInput->hasFocus() && downInput->text().isEmpty()) {
//            downInput->setText(keyText);
//            downInput->setEnabled(false); // Blochează câmpul
//        }
//        else if (leftInput->hasFocus() && leftInput->text().isEmpty()) {
//            leftInput->setText(keyText);
//            leftInput->setEnabled(false); // Blochează câmpul
//        }
//        else if (rightInput->hasFocus() && rightInput->text().isEmpty()) {
//            rightInput->setText(keyText);
//            rightInput->setEnabled(false); // Blochează câmpul
//        }
//        else if (shootInput->hasFocus() && shootInput->text().isEmpty()) {
//            shootInput->setText(keyText);
//            shootInput->setEnabled(false); // Blochează câmpul
//        }
//    }
//
//    event->accept(); // Prevenim comportamentul implicit
//}


//.................................................................................................

//Updated code

#include "ControlChoiceWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QDebug>
#include <QLabel>
#include <QKeyEvent>
#include <QSet>


CustomLineEdit::CustomLineEdit(QWidget* parent) : QLineEdit(parent) 
{
    //EMPTY
}

void CustomLineEdit::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Up ||
        event->key() == Qt::Key_Down ||
        event->key() == Qt::Key_Left ||
        event->key() == Qt::Key_Right ||
        event->key() == Qt::Key_Space)
    {
        emit ForwardKeyEvent(event);
        return; 
    }
    QLineEdit::keyPressEvent(event); 
}


ControlChoiceWindow::ControlChoiceWindow(const QString& clientId, QWidget* parent)
    : QWidget(parent)
    , clientId(clientId)
    , upInput(new CustomLineEdit(this))
    , downInput(new CustomLineEdit(this))
    , leftInput(new CustomLineEdit(this))
    , rightInput(new CustomLineEdit(this))
    , shootInput(new CustomLineEdit(this))
    , saveButton(new QPushButton("Save Controls", this))
    , resetButton(new QPushButton("Reset Controls", this))
{
    setWindowTitle("Set Controls");
    resize(600, 400);

    InitializeBackground();

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
    shootInput->setStyleSheet(inputStyle);

    upInput->setPlaceholderText("Up");
    downInput->setPlaceholderText("Down");
    leftInput->setPlaceholderText("Left");
    rightInput->setPlaceholderText("Right");
    shootInput->setPlaceholderText("Shoot");

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

    QVBoxLayout* shootLayout = new QVBoxLayout();
    shootLayout->addStretch();
    shootLayout->addWidget(shootInput);
    shootLayout->addStretch();

    inputsLayout->addLayout(leftLayout);
    inputsLayout->addLayout(centerLayout);
    inputsLayout->addLayout(rightLayout);
    inputsLayout->addLayout(shootLayout);

    mainLayout->addLayout(inputsLayout);

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    buttonLayout->addWidget(resetButton);
    buttonLayout->addWidget(saveButton);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);

    connect(upInput, &CustomLineEdit::ForwardKeyEvent, this, &ControlChoiceWindow::HandleForwardedKeyEvent);
    connect(downInput, &CustomLineEdit::ForwardKeyEvent, this, &ControlChoiceWindow::HandleForwardedKeyEvent);
    connect(leftInput, &CustomLineEdit::ForwardKeyEvent, this, &ControlChoiceWindow::HandleForwardedKeyEvent);
    connect(rightInput, &CustomLineEdit::ForwardKeyEvent, this, &ControlChoiceWindow::HandleForwardedKeyEvent);
    connect(shootInput, &CustomLineEdit::ForwardKeyEvent, this, &ControlChoiceWindow::HandleForwardedKeyEvent);

    connect(saveButton, &QPushButton::clicked, this, &ControlChoiceWindow::OnSaveControls);
    connect(resetButton, &QPushButton::clicked, this, &ControlChoiceWindow::OnResetControls);
}

ControlChoiceWindow::~ControlChoiceWindow()
{
    qDebug() << "ControlChoiceWindow destructor called.";

    disconnect(upInput, nullptr, this, nullptr);
    disconnect(downInput, nullptr, this, nullptr);
    disconnect(leftInput, nullptr, this, nullptr);
    disconnect(rightInput, nullptr, this, nullptr);
    disconnect(shootInput, nullptr, this, nullptr);
}

void ControlChoiceWindow::HandleForwardedKeyEvent(QKeyEvent* event)
{
    QString keyText;
    switch (event->key())
    {
        case Qt::Key_Up: keyText = "ArrowUp"; break;
        case Qt::Key_Down: keyText = "ArrowDown"; break;
        case Qt::Key_Left: keyText = "ArrowLeft"; break;
        case Qt::Key_Right: keyText = "ArrowRight"; break;
        case Qt::Key_Space: keyText = "Space"; break;
        default: keyText = QKeySequence(event->key()).toString(); break;
    }
    HandleKeyEvent(keyText);
}

void ControlChoiceWindow::HandleKeyEvent(const QString& keyText)
{
    if (!keyText.isEmpty()) 
    {
        if (upInput->hasFocus() && upInput->text().isEmpty())
        {
            upInput->setText(keyText);
            upInput->setEnabled(false);
        }
        else if (downInput->hasFocus() && downInput->text().isEmpty()) 
        {
            downInput->setText(keyText);
            downInput->setEnabled(false);
        }
        else if (leftInput->hasFocus() && leftInput->text().isEmpty()) 
        {
            leftInput->setText(keyText);
            leftInput->setEnabled(false);
        }
        else if (rightInput->hasFocus() && rightInput->text().isEmpty()) 
        {
            rightInput->setText(keyText);
            rightInput->setEnabled(false);
        }
        else if (shootInput->hasFocus() && shootInput->text().isEmpty())
        {
            shootInput->setText(keyText);
            shootInput->setEnabled(false);
        }
    }
}

void ControlChoiceWindow::OnSaveControls()
{
    controls["Up"] = upInput->text().trimmed();
    controls["Down"] = downInput->text().trimmed();
    controls["Left"] = leftInput->text().trimmed();
    controls["Right"] = rightInput->text().trimmed();
    controls["Shoot"] = shootInput->text().trimmed();

    qDebug() << "Controls collected:" << controls;

    // Validate keys
    /*QSet<QString> uniqueKeys;
    for (const QString& value : controls.values()) {
        uniqueKeys.insert(value);
    }

    if (uniqueKeys.contains("") || uniqueKeys.size() != controls.size()) {
        QMessageBox::warning(this, "Invalid Controls", "Ensure all controls are unique and non-empty!");
        return;
    }*/

    emit ControlsSet(controls);
    QMessageBox::information(this, "Success", "Controls have been saved!");
    this->close();
}


void ControlChoiceWindow::OnResetControls()
{
    upInput->clear();
    downInput->clear();
    leftInput->clear();
    rightInput->clear();
    shootInput->clear();

    upInput->setEnabled(true);
    downInput->setEnabled(true);
    leftInput->setEnabled(true);
    rightInput->setEnabled(true);
    shootInput->setEnabled(true);

    qDebug() << "Controls have been reset.";
}

void ControlChoiceWindow::InitializeBackground()
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
