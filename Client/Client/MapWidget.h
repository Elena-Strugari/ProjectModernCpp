#pragma once

#include <QWidget>
#include <QJsonArray>
#include <QImage>


class MapWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MapWidget(QWidget* parent = nullptr);
    void setMapData(const QJsonArray& data); // Setează datele hărții
    //void UpdateMapCell(int x, int y, const QString& type);
    //QImage GetImageForValue(int value);

    //void resizeEvent(QResizeEvent* event);
signals:
    //void cellUpdated(int x, int y);
protected:
    void paintEvent(QPaintEvent* event) override;
private slots:
    //void onCellUpdated(int x, int y);

private:
     QJsonArray mapData; // Datele pentru hartă
};
