
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