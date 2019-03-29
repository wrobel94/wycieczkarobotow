#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <QColor>
#include "position.h"
#include <QObject>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <thread>

class Obstacle: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    Position* position;
public:
    Obstacle();
    Obstacle(Position* _position);
    ~Obstacle();
    void setPosition();
};


#endif // OBSTACLE_H
