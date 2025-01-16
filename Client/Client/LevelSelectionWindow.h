#pragma once
#ifndef LEVELSELECTIONWINDOW_H
#define LEVELSELECTIONWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include "BackgroundHelper.h"
class LevelSelectionWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LevelSelectionWindow(QWidget* parent = nullptr);
    ~LevelSelectionWindow();

signals:
    void LevelEasy(const QString& username);
    void LevelMediu(const QString& username);
    void LevelHard(const QString& username);

private:
    QLabel* titleLabel;        
    QPushButton* easyButton;    
    QPushButton* mediumButton;  
    QPushButton* hardButton;   

    QString m_username;

    //void initializeBackground(); 
protected:
    void resizeEvent(QResizeEvent* event)override;
};

#endif // LEVELSELECTIONWINDOW_H
