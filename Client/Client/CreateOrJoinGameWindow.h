#ifndef CREATEORJOINGAMEWINDOW_H
#define CREATEORJOINGAMEWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>

class CreateOrJoinGameWindow : public QWidget {
    Q_OBJECT

public:
    explicit CreateOrJoinGameWindow(QWidget* parent = nullptr);
    ~CreateOrJoinGameWindow();

signals:
    void Generate();
    void CheckCode(); 

private:
    void InitializeBackground();

    QLabel* titleLabel;
    QPushButton* generateCodeButton;
    QPushButton* checkCodeButton;
    QLineEdit* typeCode;
};

#endif // CREATEORJOINGAMEWINDOW_H
