
//Va fi nevoie de schimbarea acestei clase astfel incat harta sa ramana doar o matrice de celule, iar doar celulele sa difere intre ele,
//aceste celule reprezentand ziduri, jucatori, spatii goale.

//#pragma once
//#ifndef MAP_H
//#define MAP_H
//
//#include <QWidget>
//#include <vector>
//#include <memory>
//#include "GameEntity.h"
//#include "MapCell.h"
//
//class ClientMap:public QWidget
//{
//	Q_OBJECT
//private:
//	int m_cellSize = 32; // px
//	std::vector<std::vector<MapCell>> m_grid; 
//	std::vector<std::shared_ptr<GameEntity>> m_dynamicObjects;
//public:
//	explicit ClientMap(QWidget* parent = nullptr);
//
//	void Initialize(int rows, int cols);
//	void AddObject(std::shared_ptr<GameEntity> obj, int x, int y);
//
//protected:
//	void paintEvent(QPaintEvent* event) override;
//};
//
//#endif // MAP_H

//...........................................................................................................................
//#pragma once
//#ifndef CLIENTMAP_H
//#define CLIENTMAP_H
//
//#include <vector>
////#include "GameEntity.h"
//#include "MapCell.h"
//
//class ClientMap
//{
//private:
//    std::vector<std::vector<MapCell>> m_map; 
//    int m_rows;                              
//    int m_columns;                          
//
//public:
//    ClientMap(int rows, int columns);
//
//    // Getters
//    int GetRows() const;
//    int GetColumns() const;
//
//    MapCell& GetCell(int row, int col);
//    const MapCell& GetCell(int row, int col) const;
//
//    //Setters
//    void SetCellType(int row, int col, MapCell::CellType type);
//    void SetCellObject(int row, int col, std::shared_ptr<GameEntity> object);
//
//    
//    void LoadMap(const std::vector<std::vector<MapCell::CellType>>& mapData);
//
//    bool IsValidCell(int row, int col) const;
//
//    void InitializeTestMap();
//};
//
//#endif // CLIENTMAP_H
//class ClientMap {
//private:
//    std::vector<std::vector<MapCell>> m_map;
//    int m_rows, m_columns;
//
//public:
//    ClientMap(int rows, int columns)
//        : m_rows(rows), m_columns(columns), m_map(rows, std::vector<MapCell>(columns)) {
//    }
//
//    int GetRows() const { return m_rows; }
//    int GetColumns() const { return m_columns; }
//    MapCell& GetCell(int row, int col) { return m_map[row][col]; }
//};

#ifndef CLIENTMAP_H
#define CLIENTMAP_H

#include <QWidget>
#include <QPixmap>
#include <QJsonObject>
#include "NoGreenScreen.h"

class ClientMap : public QWidget
{
    Q_OBJECT

public:
    //explicit ClientMap(QWidget* parent);
    explicit ClientMap(QWidget* parent = nullptr);

    void DisplayMap(const QJsonObject& mapObject);
protected:
    void resizeEvent(QResizeEvent* event)override;
private:
    QWidget* parentWidget;
    QString GetImagePath(QString type);
    void InitializeBackground();
};

#endif // CLIENTMAP_H
