#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QVBoxLayout>
#include <QKeyEvent>
#include <QMainWindow>
//#include "ClientMap.h"
#include <QFile>

#include "StartGameWindow.h"
#include "Client.h"
#include "ClientServer.h"

class MainWindow : public QMainWindow //QWidget 
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();    
   
private slots:
    void firstWindow();            //start game
    void onStartGameClicked();     // log 

private:
    void initializeBackground();
    QLabel* imageLabel = nullptr; // Imaginea de fundal
    QLabel* textLabel = nullptr;  // Textul "Start Game"
    //QPixmap backgroundPixmap;     // Imaginea încãrcatã
   // ClientMap* map;
};

#endif // MAINWINDOW_H


//MainWindow pentru harta

//#pragma once
//#ifndef MAINWINDOW_H
//#define MAINWINDOW_H
//
//#include <QMainWindow>
//#include "ClientMap.h"
//
//class MainWindow : public QMainWindow {
//    Q_OBJECT
//
//public:
//    explicit MainWindow(QWidget* parent = nullptr);
//    ~MainWindow();
//
//private:
//    ClientMap* map; // Pointer to your map widget
//};
//
//#endif // MAINWINDOW_H


//   TEST PLENTRU PLAYER 
//#ifndef MAINWINDOW_H
//#define MAINWINDOW_H
//
//#include <QMainWindow>
//#include <QLabel>
//#include "DisplayElements.h" // Include clasa Element dacă este necesar
//
//class MainWindow : public QMainWindow
//{
//    Q_OBJECT
//
//public:
//    explicit MainWindow(QWidget* parent = nullptr);
//    ~MainWindow();
//
//private:
//    QLabel* imageLabel;
//    DisplayElements element; // Instanța clasei care gestionează imaginile
//};
//
//#endif // MAINWINDOW_H
