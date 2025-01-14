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
    : QWidget(parent), m_username(clientId)
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

    BackgroundHelper::InitializeBackground(this);

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

    emit ControlsSet(controls, m_username);
    //this->close();
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

void ControlChoiceWindow::resizeEvent(QResizeEvent* event)
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
