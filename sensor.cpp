#include "sensor.h"
void Sensor::calculateFallowingPosition()
{
    int x_followed=0, y_followed =0;
    for(int i=0;i<robot->getFollowedRobots().size();i++){
            x_followed+=(robot->getFollowedRobots()[i]->getCurrentPosition()->getX());
            y_followed+=(robot->getFollowedRobots()[i]->getCurrentPosition()->getY());

    }
    x_followed=x_followed/(robot->getFollowedRobots().size());
    y_followed=y_followed/(robot->getFollowedRobots().size());

    x_followed+=(this->x_x);
    y_followed+=(this->y_y);

    if(x_followed<0){
        x_followed=0;
    }
    if(y_followed<0){
        y_followed=0;
    }
    if(x_followed>this->robot->getMap()->getXSize()){
        x_followed=this->robot->getMap()->getXSize()-1;
    }
    if(y_followed>this->robot->getMap()->getYSize()){
        y_followed=this->robot->getMap()->getYSize()-1;
    }
    robot->setDestinationPosition(robot->getMap()->getPosition(x_followed,y_followed));
}

void Sensor::setX_x()
{
    int x_followed=0;
    for(int i=0;i<robot->getFollowedRobots().size();i++){
            x_followed+=(robot->getFollowedRobots()[i]->getCurrentPosition()->getX());
    }
    x_followed=x_followed/(robot->getFollowedRobots().size());
    x_followed = -(x_followed - robot->getCurrentPosition()->getX());
    x_x = x_followed;
}

void Sensor::setY_y()
{
    int y_followed=0;
    for(int i=0;i<robot->getFollowedRobots().size();i++){
            y_followed+=(robot->getFollowedRobots()[i]->getCurrentPosition()->getY());
    }
    y_followed=y_followed/(robot->getFollowedRobots().size());
    y_followed = -(y_followed - robot->getCurrentPosition()->getY());
    y_y = y_followed;
}


Sensor::Sensor(Robot *_robot)
{
    robot=_robot;
    this->Initialize();
}

void Sensor::Initialize()
{
    this->setX_x();
    this->setY_y();
    this->calculateFallowingPosition();
}
