#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void onStartGameClicked();
    void HandleLogin(const QString& username);
    void HandleRegister(const QString& username);
    void HandleControlsSet(const QMap<QString, QString>& controls, const QString& username);
    void HandleCreateCode();
    void HandleCheckCode(const QString& gameCode, const QString& username);
    void HandleLevel1();
    void HandleLevel2();
    void HandleLevel3();
    void DisplayMap();
    void HandleInGameSettings();
    void HandleGeneralSettings();

private:
    Ui::MainWindow* ui;

    void connectServer();
    void StartGameWindoww();
    void LogUserWindow();
    void CreateJoinWindow();
    void GameWindow();

};


#endif
