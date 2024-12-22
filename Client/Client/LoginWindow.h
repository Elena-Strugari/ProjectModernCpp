#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

//biblioteci de test
//#include <QVBoxLayout>
//#include <QPushButton>
//#include <QLineEdit>
//#include <QLabel>
#include <QPalette>
#include <QResizeEvent>


class Client; // Forward declaration

class LoginWindow :public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget* parent = nullptr);

protected:
    void resizeEvent(QResizeEvent* event) override;

private slots:
    void onLogin();
    void onRegister();

private:
    QLabel* textLabel;
    QLineEdit* clientInput;
    QPushButton* loginButton;
    QPushButton* registerButton;
    QLabel* imageLabel;
    QLabel* promptLabel;

};

