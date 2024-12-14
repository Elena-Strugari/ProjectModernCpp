﻿#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QKeyEvent>
#include <QMainWindow>
#include "ClientMap.h"

class MainWindow : public QMainWindow //QWidget 
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
protected:
    /*void resizeEvent(QResizeEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;*/

//private slots:
   // void onStartGameClicked();

private:

    //QLabel* imageLabel; // Imaginea de fundal
    //QLabel* textLabel;  // Textul "Start Game"
    //QPixmap pixmap;     // Imaginea încărcată
    ClientMap* map;
};

#endif // MAINWINDOW_H
