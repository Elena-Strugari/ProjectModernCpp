//#pragma once
#pragma once
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <cpr/cpr.h>

class ClientApp : public QWidget {
    Q_OBJECT

public:
    explicit ClientApp(QWidget* parent = nullptr);

private slots:
    /* void onChooseLevel(const std::string& clientId , const std::string& level);

    void onChooseSmall();
    void onChooseMedium();
    void onChooseLarge();*/
};


//
//#include <QtWidgets/QMainWindow>
//#include "ui_ClientApp.h"
//
//#include <QWidget>
//#include <QPushButton>
//#include <QLineEdit>
//#include <QLabel>
//#include <QVBoxLayout>
//#include <cpr/cpr.h>
//
////class ClientApp : public QMainWindow
//class ClientApp : public QWidget
//{
//    Q_OBJECT
//
//public:
//
//    explicit ClientApp(QWidget* parent = nullptr);
//    // ~ClientApp();
//
//private slots:
//    void onChooseLevel();
//    void onGetMap();
//    void onMoveTankUp();
//    void onMoveTankDown();
//    void onMoveTankLeft();
//    void onMoveTankRight();
//
//private:
//    //Ui::ClientAppClass ui;
//
//    QLineEdit* clientIdInput;
//    QLineEdit* levelInput;
//    QLabel* outputLabel;
//
//    void sendMoveRequest(const std::string& direction);
//};
