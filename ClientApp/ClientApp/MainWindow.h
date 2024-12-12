#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QKeyEvent>

class MainWindow : public QWidget {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

protected:
    void resizeEvent(QResizeEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;

private slots:
    void onStartGameClicked();

private:
    QLabel* imageLabel; // Imaginea de fundal
    QLabel* textLabel;  // Textul "Start Game"
    QPixmap pixmap;     // Imaginea încărcată
};

#endif // MAINWINDOW_H
