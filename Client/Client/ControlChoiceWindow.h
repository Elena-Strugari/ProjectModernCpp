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
#include <QKeyEvent>

class ControlChoiceWindow : public QWidget {
    Q_OBJECT

public:
    explicit ControlChoiceWindow(const QString& clientId, QWidget* parent = nullptr);
    ~ControlChoiceWindow();

signals:
    void ControlsSet(const QMap<QString, QString>& controls);

private slots:
    void OnSaveControls();

protected:
    void keyPressEvent(QKeyEvent* event) override;

private:
    void InitializeBackground();

    QString clientId; // Salvează clientId pentru referință
    QLineEdit* upInput;
    QLineEdit* downInput;
    QLineEdit* leftInput;
    QLineEdit* rightInput;
    QLineEdit* ShootInput;
    QPushButton* saveButton;
    QMap<QString, QString> controls;
};

#endif // CONTROLCHOICEWINDOW_H
