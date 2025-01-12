//#include "ClientMap.h"
//
//ClientMap::ClientMap(QWidget* parent) : QWidget(parent) 
//{
//    qDebug() << "ClientMap constructor called.";
//}
//
//void ClientMap::Initialize(int rows, int cols)
//{
//    qDebug() << "ClientMap::Initialize called with rows:" << rows << "cols:" << cols;
//    m_grid.resize(rows, std::vector<MapCell>(cols));
//}
//
//
//void ClientMap::AddObject(std::shared_ptr<GameEntity> obj, int x, int y) {
//    if (x < 0 || y < 0 || x >= m_grid[0].size() || y >= m_grid.size()) {
//        return;
//    }
//
//    obj->position = QPoint(x, y);
//    m_grid[y][x].SetObject(obj);
//    m_dynamicObjects.push_back(obj);
//    update(); 
//}
//
//void ClientMap::paintEvent(QPaintEvent* event) {
//    QPainter painter(this);
//
//    // Load the background tile
//    QPixmap backgroundTile(":/space.png");
//
//    // Iterate over the grid of MapCell instances
//    for (int y = 0; y < m_grid.size(); ++y) {
//        for (int x = 0; x < m_grid[y].size(); ++x) {
//            QRect cellRect(x * m_cellSize, y * m_cellSize, m_cellSize, m_cellSize);
//
//           
//            painter.drawPixmap(cellRect, backgroundTile, backgroundTile.rect());
//
//            // Optionally draw based on cell-specific properties
//            if (m_grid[y][x].IsWall()) { // Assuming MapCell has an IsWall method
//                painter.fillRect(cellRect, Qt::black); // Example for walls
//            }
//            else if (m_grid[y][x].IsDestructible()) { // Assuming MapCell has IsDestructible
//                painter.fillRect(cellRect, Qt::darkGray); // Example for destructible cells
//            }
//
//            // Optionally overlay grid lines
//            painter.setPen(Qt::gray);
//            painter.drawRect(cellRect);
//        }
//    }
//
//    // Draw dynamic objects (e.g., tanks, bombs)
//    for (const auto& obj : m_dynamicObjects) {
//        QRect objRect(obj->position.x() * m_cellSize, obj->position.y() * m_cellSize, m_cellSize, m_cellSize);
//        obj->draw(&painter, m_cellSize); // Assuming GameEntity has a draw method
//    }
//}
//

#include "ClientMap.h"
#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include <QImage>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QDebug>
#include <QPalette>


ClientMap::ClientMap(QWidget* parent)
    : parentWidget(parent) {}

void ClientMap::DisplayMap(const QJsonObject& mapObject) {
    int width = mapObject["width"].toInt();
    int height = mapObject["height"].toInt();
    QJsonArray cells = mapObject["cells"].toArray();


    if (parentWidget->layout()) {
        delete parentWidget->layout();
    }

    InitializeBackground();
    QGridLayout* gridLayout = new QGridLayout();
    QWidget* centralWidget = new QWidget(parentWidget);
    centralWidget->setLayout(gridLayout);
    parentWidget->layout()->addWidget(centralWidget);

    for (int y = 0; y < height; ++y) {
        QJsonArray row = cells[y].toArray();
        for (int x = 0; x < width; ++x) {
            QJsonObject cell = row[x].toObject();
            QString type = cell["type"].toString();


            QLabel* cellLabel = new QLabel(parentWidget);


            QString imagePath = GetImagePath(type);
            if (!imagePath.isEmpty()) {

                QImage processedImage = RemoveGreenScreen(imagePath);
                QPixmap pixmap = QPixmap::fromImage(processedImage);


                cellLabel->setPixmap(pixmap.scaled(32, 32, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            }


            gridLayout->addWidget(cellLabel, y, x);
        }
    }
}

QString ClientMap::GetImagePath(QString type)
{
    QString imagePath;
    /*imagePath = ":/Astronaut_1_Positions/resources/Astronaut_1_Down.png";
    imagePath = ":/Astronaut_1_Positions/resources/Astronaut_1_Left.png";
    imagePath = ":/Astronaut_1_Positions/resources/Astronaut_1_Right.png";
    imagePath = ":/Astronaut_1_Positions/resources/Astronaut_1_Up.png";
    imagePath = ":/Astronaut_2_Positions/resources/Astronaut_2_Down.png";
    imagePath = ":/Astronaut_2_Positions/resources/Astronaut_2_Left.png";
    imagePath = ":/Astronaut_2_Positions/resources/Astronaut_2_Right.png";
    imagePath = ":/Astronaut_2_Positions/resources/Astronaut_2_Up.png";
    imagePath = ":/Astronaut_3_Positions/resources/Astronaut_3_Down.png";
    imagePath = ":/Astronaut_3_Positions/resources/Astronaut_3_Left.png";
    imagePath = ":/Astronaut_3_Positions/resources/Astronaut_3_Right.png";
    imagePath = ":/Astronaut_3_Positions/resources/Astronaut_3_Up.png";
    imagePath = ":/Astronaut_4_Positions/resources/Astronaut_4_Down.png";
    imagePath = ":/Astronaut_4_Positions/resources/Astronaut_4_Left.png";
    imagePath = ":/Astronaut_4_Positions/resources/Astronaut_4_Right.png";
    imagePath = ":/Astronaut_4_Positions/resources/Astronaut_4_Up.png";*/
    if (type == "Astronaut1")
        imagePath = ":/PlayersImages/resources/Astronaut_1.png";
    else if (type == "Bomb")
        imagePath = ":/Bomb/resources/Extraterestru.png";
    else if (type == "BonusLife")
        imagePath = ":/BonusLife/resources/Oxygen.png";
    else if (type == "Border")
        imagePath = ":/Border/resources/Border.png";
    else if (type == "DestructibleWall")
        imagePath = ":/Wall/resources/Asteroid.png";
    else if (type == "IndestructibleWall")
        imagePath = ":/Wall/resources/Asteroid.png";
    else if (type == "SlowSpeedleWall")
        imagePath = ":/SlowSpeedWall/resources/praf1.png";

    return QString(imagePath);
}
void ClientMap::resizeEvent(QResizeEvent* event)
{
    QImage image(":/StartImage/resources/StartGame.jpg");

    if (!image.isNull())
    {
        QPalette palette;
        palette.setBrush(QPalette::Window, QBrush(image.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)));
        setPalette(palette);
    }
    QWidget::resizeEvent(event);
}

void ClientMap::InitializeBackground()
{
    QImage image(":/StartImage/resources/StartGame.jpg");

    if (image.isNull())
    {
        qDebug() << "Failed to load background image!";
        return;
    }

    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(image.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)));
    setPalette(palette);
    setAutoFillBackground(true);
}