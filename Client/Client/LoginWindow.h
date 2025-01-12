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
    void InitializeBackground();
signals:
    void Login(const QString& username); 
   // void RegisterUser(const QString& username); 

private slots:
    void OnLoginClicked();
    void OnRegisterClicked();

protected:
    void resizeEvent(QResizeEvent* event)override;


private:
    //QLabel* textLabel;
    //QLineEdit* usernameInput;
    QLineEdit* clientInput;
    QPushButton* loginButton;
    QPushButton* registerButton;
    QLabel* imageLabel;
    QLabel* promptLabel;

};

