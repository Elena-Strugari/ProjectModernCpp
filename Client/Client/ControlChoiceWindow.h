#ifndef CONTROLCHOICEWINDOW_H
#define CONTROLCHOICEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QString>

class ControlChoiceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ControlChoiceWindow(const QString& clientId, QWidget* parent = nullptr);
    ~ControlChoiceWindow();

private:
    QString clientId;
    QPushButton* wasdButton;
    QPushButton* arrowButton;

    void initializeBackground();

private slots:
    void onWasdChosen();
    void onArrowChosen();
};

#endif // CONTROLCHOICEWINDOW_H