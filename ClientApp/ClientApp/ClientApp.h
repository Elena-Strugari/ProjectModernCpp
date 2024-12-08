#pragma once
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class ClientApp : public QWidget {
    Q_OBJECT

public:
    explicit ClientApp(QWidget* parent = nullptr);

private slots:
    void onChooseSmall();
    void onChooseMedium();
    void onChooseLarge();
};
