#include "ClientMap.h"

ClientMap::ClientMap(QWidget* parent) : QWidget(parent) 
{
    qDebug() << "ClientMap constructor called.";
}

void ClientMap::Initialize(int rows, int cols)
{
    qDebug() << "ClientMap::Initialize called with rows:" << rows << "cols:" << cols;
    m_grid.resize(rows, std::vector<MapCell>(cols));
}


void ClientMap::AddObject(std::shared_ptr<GameEntity> obj, int x, int y) {
    if (x < 0 || y < 0 || x >= m_grid[0].size() || y >= m_grid.size()) {
        return;
    }

    obj->position = QPoint(x, y);
    m_grid[y][x].SetObject(obj);
    m_dynamicObjects.push_back(obj);
    update(); 
}
void ClientMap::paintEvent(QPaintEvent* event) {
    QPainter painter(this);

    for (int y = 0; y < m_grid.size(); ++y) {
        for (int x = 0; x < m_grid[y].size(); ++x) {
            QRect cellRect(x * m_cellSize, y * m_cellSize, m_cellSize, m_cellSize);

            if (m_grid[y][x].IsWall()) {
                painter.fillRect(cellRect, Qt::black);
            }
            else {
                painter.fillRect(cellRect, Qt::white); 
            }
             
            painter.setPen(Qt::gray);
            painter.drawRect(cellRect);
        }
    }
}
