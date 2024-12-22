#pragma once

#include <QtWidgets/QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QStackedLayout>
#include <QLabel>
#include <cpr/cpr.h>
#include "ui_Client.h"

class Client : public QWidget
{
    Q_OBJECT

public:
   explicit Client(QWidget *parent = nullptr);
    ~Client();

private:
    Ui::ClientClass ui;

    QStackedLayout* stackedLayout; // Layout stratificat pentru navigare
    void onLevelChosen(const QString& level);

};


