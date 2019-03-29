#include "obstacle.h"
#include <QDebug>
#include <QPen>
#include <QBrush>
Obstacle::Obstacle()
{

}

Obstacle::Obstacle(Position *_position)
{
    position =_position;
    QBrush color;
    color.setColor(Qt::black);
    QBrush col=color.color();
    QPen black(Qt::black);
    black.setWidth(0);
    this->setPen(black);
    this->setBrush(col);
    position->setIsEmpty(false);
    setRect(0,0,1,1);
    setPos(0,0);
}

Obstacle::~Obstacle()
{
    this->position->setIsEmpty(true);
}

void Obstacle::setPosition()
{
    setPos(position->getX(),position->getY());
}
