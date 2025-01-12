//#ifndef CONTROLCHOICEWINDOW_H
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
#include <QString>
#include <QKeyEvent>

class CustomLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    explicit CustomLineEdit(QWidget* parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent* event) override;

signals:
    void ForwardKeyEvent(QKeyEvent* event);
};

class ControlChoiceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ControlChoiceWindow(const QString& clientId, QWidget* parent = nullptr);
    ~ControlChoiceWindow();

signals:
    void ControlsSet(const QMap<QString, QString>& controls);

private slots:
    void OnSaveControls();
    void OnResetControls();
    void HandleForwardedKeyEvent(QKeyEvent* event);

private:
    void InitializeBackground();
    void HandleKeyEvent(const QString& keyText);

    QString clientId;
    CustomLineEdit* upInput;
    CustomLineEdit* downInput;
    CustomLineEdit* leftInput;
    CustomLineEdit* rightInput;
    CustomLineEdit* shootInput;
    QPushButton* saveButton;
    QPushButton* resetButton;
    QMap<QString, QString> controls;
};

#endif // CONTROLCHOICEWINDOW_H
