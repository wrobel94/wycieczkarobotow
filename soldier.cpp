#include "soldier.h"

Soldier::Soldier()
{

}

Soldier::Soldier(Soldier &_soldier):Robot(_soldier)
{
    sensor=_soldier.sensor;
}

Soldier::Soldier(int _grade, Position *_position, Map *_map):Robot(_grade, _position, _map)
{

}

void Soldier::setSensor()
{
    sensor= new Sensor(this);
}

void Soldier::logic()
{
    this->sensor->calculateFallowingPosition();
    if(!(this->nextPositionCalculate())){
        this->setLastPosition(this->getCurrentPosition());
    }
    if(!(nextPosition==currentPosition)){
        this->move();
    }
}
