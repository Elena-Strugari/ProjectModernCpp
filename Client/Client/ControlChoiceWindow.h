﻿//#ifndef CONTROLCHOICEWINDOW_H
//#define CONTROLCHOICEWINDOW_H
//
//#include <QWidget>
//#include <QPushButton>
//#include <QString>
//
//class ControlChoiceWindow : public QWidget
//{
//    Q_OBJECT
//
//public:
//    explicit ControlChoiceWindow(const QString& clientId, QWidget* parent = nullptr);
//    ~ControlChoiceWindow();
//
//private:
//    QString clientId;
//    QPushButton* wasdButton;
//    QPushButton* arrowButton;
//
//    void initializeBackground();
//
//private slots:
//    void onWasdChosen();
//    void onArrowChosen();
//};
//
//#endif // CONTROLCHOICEWINDOW_H

#ifndef CONTROLCHOICEWINDOW_H
#define CONTROLCHOICEWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QMap>

class ControlChoiceWindow : public QWidget {
    Q_OBJECT

public:
    explicit ControlChoiceWindow(const QString& clientId, QWidget* parent = nullptr);
    ~ControlChoiceWindow();

signals:
    void ControlsSet(const QMap<QString, QString>& controls);

private slots:
    void OnSaveControls();

private:
    void InitializeBackground();

    QString clientId; // Salvează clientId pentru referință
    QLineEdit* upInput;
    QLineEdit* downInput;
    QLineEdit* leftInput;
    QLineEdit* rightInput;
    QPushButton* saveButton;
    QMap<QString, QString> controls;
};

#endif // CONTROLCHOICEWINDOW_H
