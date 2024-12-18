#pragma once
#include "StartGame.h"
#include <QPixmap>
#include <QLabel>
#include <QVBoxLayout>

StartGame::StartGame(QWidget* parent)
    : QWidget(parent), imageLabel(new QLabel(this)), textLabel(new QLabel("Start Game", this)) {
    setFocusPolicy(Qt::StrongFocus); // Ensure widget accepts focus
    QPixmap pixmap(":/startImage/resources/StartGame.jpg");
    if (!pixmap.isNull()) {
        imageLabel->setPixmap(pixmap.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setScaledContents(false);

    textLabel->setAlignment(Qt::AlignCenter);
    textLabel->setStyleSheet(
        "font-size: 36px; "
        "color: white; "
        "font-weight: bold;"
    );

    QVBoxLayout* labelLayout = new QVBoxLayout(imageLabel);
    labelLayout->addWidget(textLabel);
    labelLayout->setAlignment(textLabel, Qt::AlignCenter);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(imageLabel);
    setLayout(mainLayout);

    setWindowTitle("Start Game");
    resize(800, 600); // Fixed window size
}

StartGame::~StartGame() {}

void StartGame::resizeEvent(QResizeEvent* event) {
    QPixmap pixmap(":/startImage/resources/StartGame.jpg");
    if (!pixmap.isNull()) {
        imageLabel->setPixmap(pixmap.scaled(event->size().boundedTo(QSize(800, 600)), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
    }
    QWidget::resizeEvent(event);
}

void StartGame::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
        emit startGame(); // Emit the signal
        qDebug() << "startGame signal emitted"; // Debug log
    }
    else {
        QWidget::keyPressEvent(event);
    }
}
