#include "position.h"

int Position::getX() const
{
    return x;
}

int Position::getY() const
{
    return y;
}

bool Position::getIsEmpty() const
{
    return isEmpty;
}

void Position::setIsEmpty(bool value)
{
    isEmpty = value;
}

bool Position::operator==(Position *_position)
{
    if(this->getX()==_position->getX()){
        if(this->getY() == _position->getY()){
            return true;
        }
    }
    return false;
}

Position::Position()
{

}



Position::Position(int _x, int _y)
{
    this->x = _x;
    this->y = _y;
    this->isEmpty = true;
}

void Position::print()
{
    qDebug() << "position class x=" << x << " ; y=" << y << " is empty :" << isEmpty;
}


