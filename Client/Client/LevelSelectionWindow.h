#pragma once
#ifndef LEVELSELECTIONWINDOW_H
#define LEVELSELECTIONWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QString>

class LevelSelectionWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LevelSelectionWindow(QWidget* parent = nullptr);
    ~LevelSelectionWindow();

signals:
    void levelSelected(const QString& level); 

private:
    QLabel* titleLabel;        
    QPushButton* easyButton;    
    QPushButton* mediumButton;  
    QPushButton* hardButton;    

    void initializeBackground(); 
protected:
    void resizeEvent(QResizeEvent* event)override;
};

#endif // LEVELSELECTIONWINDOW_H
