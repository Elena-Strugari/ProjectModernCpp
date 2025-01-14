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
    void GeneralSettings();
protected:
    void resizeEvent(QResizeEvent* event) override;
private:

    QLabel* titleLabel;
    QPushButton* generateCodeButton;
    QPushButton* checkCodeButton;
    QLineEdit* typeCode;
    QPushButton* generalSettingsButton;
};

#endif // CREATEORJOINGAMEWINDOW_H
