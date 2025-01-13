﻿#include "GeneralSettingsWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QDebug>

GeneralSettingsWindow::GeneralSettingsWindow(QWidget* parent)
    : QWidget(parent),
    musicVolumeSlider(new QSlider(Qt::Horizontal, this)),
    controlSettingsButton(new QPushButton("Edit Controls", this)),
    logoutButton(new QPushButton("Delete Account", this)),
    saveButton(new QPushButton("Save Settings", this))
{
    setWindowTitle("General Settings");
    resize(800, 600);

    // Initializează fundalul
    InitializeBackground();

    // Configurare slider de volum
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
    controlSettingsButton->setStyleSheet(buttonStyle);
    logoutButton->setStyleSheet(buttonStyle);
    saveButton->setStyleSheet(buttonStyle);

    // Setăm dimensiuni fixe pentru butoane
    QSize buttonSize(150, 40);
    controlSettingsButton->setFixedSize(buttonSize);
    logoutButton->setFixedSize(buttonSize);
    saveButton->setFixedSize(buttonSize);

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
    buttonLayout->addWidget(controlSettingsButton);
    buttonLayout->addSpacing(50);
    buttonLayout->addWidget(logoutButton);
    buttonLayout->addSpacing(50);
    buttonLayout->addWidget(saveButton);
    buttonLayout->addStretch();

    // Layout principal
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QLabel* titleLabel = new QLabel("General Settings", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 32px; font-weight: bold; color: white;");
    titleLabel->setContentsMargins(0, 20, 0, 10);

    mainLayout->addWidget(titleLabel);
    mainLayout->addStretch();
    mainLayout->addLayout(slidersLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(buttonLayout);
    mainLayout->addStretch();

    setLayout(mainLayout);

    // Conexiuni
    connect(saveButton, &QPushButton::clicked, this, &GeneralSettingsWindow::onSaveSettings);
    connect(controlSettingsButton, &QPushButton::clicked, this, &GeneralSettingsWindow::onEditControls);
    connect(logoutButton, &QPushButton::clicked, this, &GeneralSettingsWindow::onLogout);
}

void GeneralSettingsWindow::InitializeBackground()
{
    QImage image(":/StartImage/resources/StartGame.jpg");

    if (image.isNull()) {
        qDebug() << "Failed to load background image!";
        return;
    }

    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(image.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)));
    setPalette(palette);
    setAutoFillBackground(true);
}

void GeneralSettingsWindow::onSaveSettings()
{
    QMessageBox::information(this, "Save Settings", "Settings saved successfully!");
}

void GeneralSettingsWindow::onEditControls()
{
    QMessageBox::information(this, "Edit Controls", "Edit Controls button clicked.");
}

void GeneralSettingsWindow::onLogout()
{
    QMessageBox::information(this, "Delete Account", "Delete Account button clicked.");
}
