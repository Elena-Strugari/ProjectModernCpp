//#ifndef MAINWINDOW_H
//#define MAINWINDOW_H
//#include <QVBoxLayout>
//#include <QKeyEvent>
//#include <QMainWindow>
////#include "ClientMap.h"
//#include <QFile>
//
//#include "StartGameWindow.h"
//#include "Client.h"
//#include "ClientServer.h"
//#include <QDir>
//
//class MainWindow : public QMainWindow //QWidget 
//{
//    Q_OBJECT
//
//public:
//    explicit MainWindow(QWidget* parent = nullptr);
//    ~MainWindow();    
//   
//private slots:
//    void firstWindow();            //start game
//    void onStartGameClicked();     // log 
//   // void onSignInClicked();
//  //  void onSignUpClicked();
//
//private:
//    void initializeBackground();
//    QLabel* imageLabel = nullptr; // Imaginea de fundal
//    QLabel* textLabel = nullptr;  // Textul "Start Game"
//    //QPixmap backgroundPixmap;     // Imaginea încãrcatã
//   // ClientMap* map;
//};
//
//#endif // MAINWINDOW_H
//................................................................................................................................................

//MAinWindow pentru harta

//#include <QPalette>
//#include <QImage>
//#include "ClientMap.h"
//#include <QGridLayout>
//#include <QMainWindow>
//
//class MainWindow : public QMainWindow 
//{
//    Q_OBJECT
//
//public:
//    explicit MainWindow(QWidget* parent = nullptr);
//    void DisplayMap(const ClientMap& clientMap);
//
//private:
//    QWidget* centralWidget;
//    QGridLayout* gridLayout;
//
//    void SetCellBackground(QWidget* cellWidget, const QString& imagePath);
//};


//...................................................................................................................................................

////   TEST PLENTRU PLAYER 
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

//.....................................................................................
//MainWinodw pt final
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void onStartGameClicked();
    void HandleLogin(const QString& username);
    void HandleRegister(const QString& username);
    void HandleControlsSet(const QMap<QString, QString>& controls);// , const QString& username);


    void HandleCreateCode();
    void HandleCheckCode();

    void DisplayMap();

private:
    Ui::MainWindow* ui;

    // Funcția pentru conectarea la server
    void connectServer();
    void StartGameWindoww();
    void LogUserWindow();
    void CreateJoinWindow();

};


#endif