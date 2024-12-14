#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class ClientApp; // Forward declaration

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

