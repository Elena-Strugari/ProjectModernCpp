#ifndef CREATEORJOINGAMEWINDOW_H
#define CREATEORJOINGAMEWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "BackgroundHelper.h"
class CreateOrJoinGameWindow : public QWidget {
    Q_OBJECT

public:
    explicit CreateOrJoinGameWindow(QWidget* parent = nullptr);
    ~CreateOrJoinGameWindow();

signals:
    void Generate();
    void CheckCode(); 
protected:
    void resizeEvent(QResizeEvent* event);
private:
    //void InitializeBackground();

    QLabel* titleLabel;
    QPushButton* generateCodeButton;
    QPushButton* checkCodeButton;
    QLineEdit* typeCode;
};

#endif // CREATEORJOINGAMEWINDOW_H
