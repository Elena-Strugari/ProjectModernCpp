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
//void ClientMap::paintEvent(QPaintEvent* event) {
//    QPainter painter(this);
//
//    for (int y = 0; y < m_grid.size(); ++y) {
//        for (int x = 0; x < m_grid[y].size(); ++x) {
//            QRect cellRect(x * m_cellSize, y * m_cellSize, m_cellSize, m_cellSize);
//
//            if (m_grid[y][x].IsWall()) {
//                painter.fillRect(cellRect, Qt::black);
//            }
//            else {
//                painter.fillRect(cellRect, Qt::white); 
//            }
//             
//            painter.setPen(Qt::gray);
//            painter.drawRect(cellRect);
//        }
//    }
//}
//void ClientMap::paintEvent(QPaintEvent* event) {
//    QPainter painter(this);
//
//    // Load the background tile
//    QPixmap backgroundTile(":/space_tile");
//
//    // Iterate over each cell (randomized layout example)
//    for (const auto& cell : m_cells) { // Assuming m_cells is a list of cell properties
//        QRect cellRect(cell.x, cell.y, cell.width, cell.height); // Irregular cell dimensions
//        painter.drawPixmap(cellRect, backgroundTile, backgroundTile.rect());
//    }
//
//    // Optionally overlay grid lines for clarity
//    painter.setPen(Qt::gray);
//    for (const auto& cell : m_cells) {
//        painter.drawRect(cell.x, cell.y, cell.width, cell.height); // Draw grid lines
//    }
//}
void ClientMap::paintEvent(QPaintEvent* event) {
    QPainter painter(this);

    // Load the background tile
    QPixmap backgroundTile(":/space.png");

    // Iterate over the grid of MapCell instances
    for (int y = 0; y < m_grid.size(); ++y) {
        for (int x = 0; x < m_grid[y].size(); ++x) {
            QRect cellRect(x * m_cellSize, y * m_cellSize, m_cellSize, m_cellSize);

           
            painter.drawPixmap(cellRect, backgroundTile, backgroundTile.rect());

            // Optionally draw based on cell-specific properties
            if (m_grid[y][x].IsWall()) { // Assuming MapCell has an IsWall method
                painter.fillRect(cellRect, Qt::black); // Example for walls
            }
            else if (m_grid[y][x].IsDestructible()) { // Assuming MapCell has IsDestructible
                painter.fillRect(cellRect, Qt::darkGray); // Example for destructible cells
            }

            // Optionally overlay grid lines
            painter.setPen(Qt::gray);
            painter.drawRect(cellRect);
        }
    }

    // Draw dynamic objects (e.g., tanks, bombs)
    for (const auto& obj : m_dynamicObjects) {
        QRect objRect(obj->position.x() * m_cellSize, obj->position.y() * m_cellSize, m_cellSize, m_cellSize);
        obj->draw(&painter, m_cellSize); // Assuming GameEntity has a draw method
    }
}

