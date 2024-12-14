#pragma once
#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <QPainter>
#include <QPoint>
class GameEntity
{
	//Aceasta clasa va trebui sa fie mostenita de toate obiectele.
	//Este varianta pentru ClientApp a clasei GameObject din solutia Server.
	virtual ~GameEntity() = default;
	virtual void draw(QPainter* painter, int tileSize) const = 0;
	virtual void update() = 0;

	QPoint position;


};

#endif // GAMEENTITY_H