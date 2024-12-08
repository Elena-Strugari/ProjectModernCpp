#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ClientApp.h"

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <cpr/cpr.h>

//class ClientApp : public QMainWindow
class ClientApp : public QWidget
{
    Q_OBJECT

public:
    explicit ClientApp(QWidget* parent = nullptr);
    // ~ClientApp();

private slots:
    void onChooseLevel();
    void onGetMap();
    void onMoveTankUp();
    void onMoveTankDown();
    void onMoveTankLeft();
    void onMoveTankRight();

private:
    //Ui::ClientAppClass ui;

    QLineEdit* clientIdInput;
    QLineEdit* levelInput;
    QLabel* outputLabel;

    void sendMoveRequest(const std::string& direction);
};
