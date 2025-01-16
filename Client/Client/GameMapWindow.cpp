﻿#include "GameMapWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QDebug>

GameMapWindow::GameMapWindow(QWidget* parent)
    : QWidget(parent),
    mapWidget(new MapWidget(this)),
    settingsButton(new QPushButton("Settings", this)),
    titleLabel(new QLabel("Game Map", this))
{
    setWindowTitle("Game Map");
    resize(1000, 700);

    // Initializează fundalul
    BackgroundHelper::InitializeBackground(this);

    // Configurare titlu
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 36px; font-weight: bold; color: white;");

    // Configurare buton Settings
    settingsButton->setStyleSheet(
        "font-size: 16px; "
        "color: white; "
        "background-color: rgba(0, 0, 128, 200); "
        "border: 2px solid white; "
        "border-radius: 10px; "
        "padding: 5px;"
    );
    settingsButton->setFixedSize(120, 40);
    settingsButton->setFocusPolicy(Qt::NoFocus);
    // Configurare mapWidget
    mapWidget->setStyleSheet(
        "background-color: rgba(0, 0, 0, 150); "
        "border: 3px solid white; "
        "border-radius: 10px;"
    );

    // Layout pentru titlu și butonul Settings
    QHBoxLayout* topLayout = new QHBoxLayout();
    topLayout->addWidget(titleLabel, 1); // Titlul ocupă mai mult spațiu
    topLayout->addWidget(settingsButton, 0, Qt::AlignRight);

    // Layout principal
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(topLayout); // Adaugă rândul de sus
    mainLayout->addWidget(mapWidget, 2, Qt::AlignCenter); // Centralizează mapWidget
    //mainLayout->addWidget(mapWidget);
    mainLayout->setContentsMargins(10, 10, 10, 10); // Margini opționale pentru estetică

    setLayout(mainLayout);

    // Conectare semnal pentru butonul Settings
    connect(settingsButton, &QPushButton::clicked, this, &GameMapWindow::onSettingsClicked);
}

GameMapWindow::~GameMapWindow() = default;

void GameMapWindow::resizeEvent(QResizeEvent* event)
{
    //// Ajustează fundalul
    //QImage image(":/StartImage/resources/StartGame.jpg");

    //if (!image.isNull())
    //{
    //    QPalette palette;
    //    palette.setBrush(QPalette::Window, QBrush(image.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)));
    //    setPalette(palette);
    //}

    // Ajustează dimensiunea widget-ului map
    adjustMapWidgetSize(event);

    QWidget::resizeEvent(event);
}

void GameMapWindow::displayMap(const QJsonArray& mapData)
{
    if (mapData.isEmpty() || !mapWidget) {
        qDebug() << "Eroare: mapData este gol sau mapWidget nu este inițializat!";
        return;
    }

    mapWidget->setMapData(mapData); // Transmite datele către mapWidget
    mapWidget->update(); // Reîmprospătează widget-ul
}

void GameMapWindow::adjustMapWidgetSize(QResizeEvent* event)
{
    if (mapWidget) {
        int widgetWidth = width() * 0.9;  // 80% din lățimea ferestrei
        int widgetHeight = height() * 0.9; // 60% din înălțimea ferestrei
        mapWidget->setFixedSize(widgetWidth, widgetHeight);
        //mapWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    }
}

void GameMapWindow::onSettingsClicked()
{
    //QMessageBox::information(this, "Settings Clicked", "The Settings button was clicked!");
    emit SettingsClicked();
}

void GameMapWindow::keyPressEvent(QKeyEvent* event)
{
    if (event->isAutoRepeat()) {
        return;
    }

    qDebug() << "Key pressed:" << event->key();

    // Emit semnal pentru tasta apăsată
    emit KeyPressed(event->key());

    QWidget::keyPressEvent(event);
}