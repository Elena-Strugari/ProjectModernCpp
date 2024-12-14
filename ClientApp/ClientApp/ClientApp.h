#pragma once
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QStackedLayout>
#include <QLabel>
#include <cpr/cpr.h>

class ClientApp : public QWidget {
    Q_OBJECT

public:
    explicit ClientApp(QWidget* parent = nullptr);

private:
    QStackedLayout* stackedLayout; // Layout stratificat pentru navigare

private slots:
    void onLevelChosen(const QString& level);
};



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
