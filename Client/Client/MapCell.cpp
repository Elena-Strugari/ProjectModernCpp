//#include "MapCell.h"
//
//MapCell::MapCell()
//	: m_isWall(false)
//	, m_isDestructible(false)
//	, m_object(nullptr)
//{
//	//EMPTY
//}
//
//bool MapCell::IsWall() const
//{
//	return m_isWall;
//}
//
//void MapCell::SetWall(bool wall)
//{
//	m_isWall = wall;
//}
//
//bool MapCell::IsDestructible() const
//{
//	return m_isDestructible;
//}
//
//void MapCell::SetDestructible(bool destructible)
//{
//	m_isDestructible = destructible;
//}
//
//std::shared_ptr<GameEntity> MapCell::GetObject() const
//{
//	return m_object;
//}
//
//void MapCell::SetObject(std::shared_ptr<GameEntity> obj)
//{
//	m_object = obj;
//}
//
//bool MapCell::IsFree() const
//{
//	return !m_isWall && !m_isDestructible && !m_object;
//}

//................................................................................................................................................
//#include "MapCell.h"
//
//MapCell::MapCell(CellType type)
//    : m_type(type)
//    , m_object(nullptr) 
//{
//    //EMPTY
//}
//
//MapCell::CellType MapCell::GetType() const 
//{
//    return m_type;
//}
//
//void MapCell::SetType(CellType type)
//{
//    m_type = type;
//}
//
//bool MapCell::IsWall() const 
//{
//    return m_type == CellType::Wall || m_type == CellType::DestructibleWall;
//}
//
//bool MapCell::IsDestructible() const 
//{
//    return m_type == CellType::DestructibleWall;
//}
//
//bool MapCell::IsFree() const 
//{
//    return m_type == CellType::Empty && !m_object;
//}
//
//std::shared_ptr<GameEntity> MapCell::GetObject() const 
//{
//    return m_object;
//}
//
//void MapCell::SetObject(std::shared_ptr<GameEntity> obj) 
//{
//    m_object = obj;
//}
