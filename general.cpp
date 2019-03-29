#include "general.h"

General::General()
{

}

General::General(General &_general):Robot(_general)
{
    grade=_general.grade;
    map=_general.map;
    nextPosition=_general.nextPosition;
    currentPosition=_general.currentPosition;
    lastPosition=_general.lastPosition;
    destinationPosition=_general.destinationPosition;
    followedRobots=_general.followedRobots;
}

General::General(Position *_position, Map *_map):Robot(0,_position,_map)
{

}


void General::logic()
{
    if(!(this->nextPositionCalculate())){
        this->setLastPosition(this->getCurrentPosition());
    }
    if(!(currentPosition==destinationPosition)){
        this->nextPositionCalculate();
        if(!(nextPosition==currentPosition)){
            this->move();
        }
    }
}
