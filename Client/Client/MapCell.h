//#pragma once
//#ifndef CELL_H
//#define CELL_H
//// de verificat daca aceasta descriere a unei celule este sustinuta de suportul serverului.
//#include <memory>
//#include "GameEntity.h"
//
//class MapCell
//{
//private:
//	bool m_isWall;
//	bool m_isDestructible;
//	std::shared_ptr<GameEntity> m_object;
//
//public:
//	MapCell();
//	bool IsWall() const;
//	void SetWall(bool wall);
//
//	bool IsDestructible() const;
//	void SetDestructible(bool destructible);
//
//	std::shared_ptr<GameEntity> GetObject() const;
//	void SetObject(std::shared_ptr<GameEntity> obj);
//
//	bool IsFree() const;
//};
//#endif // CELL_H


//Clasa care se va folosi cand punem si obiectele care se misca
//#pragma once
//#ifndef CELL_H
//#define CELL_H

#include <memory>
//#include "GameEntity.h"
//
//class MapCell
//{
//public:
//    enum class CellType 
//    {
//        Empty,        
//        Wall,          
//        DestructibleWall, 
//        Tank,          
//        PowerUp,
//        Bomb
//    };
//
//private:
//    CellType m_type;                           
//    std::shared_ptr<GameEntity> m_object;     
//
//public:
//    MapCell(CellType type = CellType::Empty);
//
//    // Getters and setters for the type
//    CellType GetType() const;
//    void SetType(CellType type);
//
//    // Methods to check the type of the cell
//    bool IsWall() const;
//    bool IsDestructible() const;
//    bool IsFree() const;
//
//    // Access to dynamic objects
//    std::shared_ptr<GameEntity> GetObject() const;
//    void SetObject(std::shared_ptr<GameEntity> obj);
//};
//
//#endif // CELL_H



//class MapCell {
//public:
//    enum class CellType { Empty, Wall, DestructibleWall };
//
//private:
//    CellType m_type;
//
//public:
//    MapCell(CellType type = CellType::Empty) : m_type(type) {}
//
//    CellType GetType() const { return m_type; }
//    void SetType(CellType type) { m_type = type; }
//};
