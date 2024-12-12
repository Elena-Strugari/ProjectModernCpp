﻿#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

class ClientApp; // Forward declaration

class LoginWindow :public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget* parent = nullptr);

private slots:
    void onLogin();
    void onRegister();

private:
    QLineEdit* clientInput;
    QPushButton* loginButton;
    QPushButton* registerButton;

};

