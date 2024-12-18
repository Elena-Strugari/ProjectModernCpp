#pragma once
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QStackedLayout>
#include <QLabel>
#include <cpr/cpr.h>

class ClientApp : public QWidget {
    Q_OBJECT

public:
    explicit ClientApp(QWidget* parent = nullptr);

private:
    QStackedLayout* stackedLayout; // Layout stratificat pentru navigare

private slots:
    void onLevelChosen(const QString& level);
};



