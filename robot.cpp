#include "robot.h"
#include <QTimer>
void Robot::print()
{

}

Position *Robot::getCurrentPosition() const
{
    return currentPosition;
}

void Robot::setCurrentPosition(Position *value)
{
    currentPosition = value;
    emit change_position();
}

Position *Robot::getDestinationPosition() const
{
    return destinationPosition;
}

void Robot::setDestinationPosition(Position *value)
{
    destinationPosition = value;
}

std::vector<Robot *> Robot::getFollowedRobots() const
{
    return followedRobots;
}

void Robot::setFollowedRobots(const std::vector<Robot *> &value)
{
    followedRobots = value;
}

int Robot::getGrade() const
{
    return grade;
}

void Robot::setGrade(int value)
{
    grade = value;
}

bool Robot::nextPositionCalculate()
{
    int next_x = -1;
    int next_y = -1;
    if(currentPosition->getX()>destinationPosition->getX()){
        if(currentPosition->getY()>destinationPosition->getY()){
            if(map->isAvalibe(currentPosition->getX()-1,currentPosition->getY()-1)){
                next_x = currentPosition->getX()-1;
                next_y = currentPosition->getY()-1;
                setNextPosition(map->getPosition(next_x,next_y));
                return true;
            }else if(map->isAvalibe(currentPosition->getX()-1,currentPosition->getY())){
                next_x = currentPosition->getX()-1;
                next_y = currentPosition->getY();
                setNextPosition(map->getPosition(next_x,next_y));
                return true;
            }else if(map->isAvalibe(currentPosition->getX(),currentPosition->getY()-1)){
                next_x = currentPosition->getX();
                next_y = currentPosition->getY()-1;
                setNextPosition(map->getPosition(next_x,next_y));
                return true;
            }
        }else if(currentPosition->getY()==destinationPosition->getY()){
            if(map->isAvalibe(currentPosition->getX()-1,currentPosition->getY())){
                next_x = currentPosition->getX()-1;
                next_y = currentPosition->getY();
                setNextPosition(map->getPosition(next_x,next_y));
                return true;
            }else if(map->isAvalibe(currentPosition->getX()-1,currentPosition->getY()-1)){
                next_x = currentPosition->getX()-1;
                next_y = currentPosition->getY()-1;
                setNextPosition(map->getPosition(next_x,next_y));
                return true;
            }else if(map->isAvalibe(currentPosition->getX()-1,currentPosition->getY()+1)){
                next_x = currentPosition->getX()-1;
                next_y = currentPosition->getY()+1;
                setNextPosition(map->getPosition(next_x,next_y));
                return true;
            }
        }else{
            if(map->isAvalibe(currentPosition->getX()-1,currentPosition->getY()+1)){
                next_x = currentPosition->getX()-1;
                next_y = currentPosition->getY()+1;
                setNextPosition(map->getPosition(next_x,next_y));
                return true;
            }else if(map->isAvalibe(currentPosition->getX()-1,currentPosition->getY())){
                next_x = currentPosition->getX()-1;
                next_y = currentPosition->getY();
                setNextPosition(map->getPosition(next_x,next_y));
                return true;
            }else if(map->isAvalibe(currentPosition->getX(),currentPosition->getY()+1)){
                next_x = currentPosition->getX();
                next_y = currentPosition->getY()+1;
                setNextPosition(map->getPosition(next_x,next_y));
                return true;
            }
        }
    }else if(currentPosition->getX()==destinationPosition->getX()){
        if(currentPosition->getY()>destinationPosition->getY()){
            if(map->isAvalibe(currentPosition->getX(),currentPosition->getY()-1)){
                next_x = currentPosition->getX();
                next_y = currentPosition->getY()-1;
                setNextPosition(map->getPosition(next_x,next_y));
                return true;
            }else if(map->isAvalibe(currentPosition->getX()-1,currentPosition->getY()-1)){
                next_x = currentPosition->getX()-1;
                next_y = currentPosition->getY()-1;
                setNextPosition(map->getPosition(next_x,next_y));
                return true;
            }else if(map->isAvalibe(currentPosition->getX()+1,currentPosition->getY()-1)){
                next_x = currentPosition->getX()+1;
                next_y = currentPosition->getY()-1;
                setNextPosition(map->getPosition(next_x,next_y));
                return true;
            }
        }else if(currentPosition->getY()==destinationPosition->getY()){
            if(map->isAvalibe(currentPosition->getX(),currentPosition->getY())){
                next_x = currentPosition->getX();
                next_y = currentPosition->getY();
                setNextPosition(map->getPosition(next_x,next_y));
                return true;
            }
        }else{
            if(map->isAvalibe(currentPosition->getX(),currentPosition->getY()+1)){
                next_x = currentPosition->getX();
                next_y = currentPosition->getY()+1;
                setNextPosition(map->getPosition(next_x,next_y));
                return true;
            }else if(map->isAvalibe(currentPosition->getX()-1,currentPosition->getY()+1)){
                next_x = currentPosition->getX()-1;
                next_y = currentPosition->getY()+1;
                setNextPosition(map->getPosition(next_x,next_y));
                return true;
            }else if(map->isAvalibe(currentPosition->getX()+1,currentPosition->getY()+1)){
                next_x = currentPosition->getX()+1;
                next_y = currentPosition->getY()+1;
                setNextPosition(map->getPosition(next_x,next_y));
                return true;
            }
        }
    }else if(currentPosition->getX()<destinationPosition->getX()){
        if(currentPosition->getY()>destinationPosition->getY()){
            if(map->isAvalibe(currentPosition->getX()+1,currentPosition->getY()-1)){
                next_x = currentPosition->getX()+1;
                next_y = currentPosition->getY()-1;
                setNextPosition(map->getPosition(next_x,next_y));
                return true;
            }else if(map->isAvalibe(currentPosition->getX(),currentPosition->getY()-1)){
                next_x = currentPosition->getX();
                next_y = currentPosition->getY()-1;
                setNextPosition(map->getPosition(next_x,next_y));
                return true;
            }else if(map->isAvalibe(currentPosition->getX()+1,currentPosition->getY())){
                next_x = currentPosition->getX()+1;
                next_y = currentPosition->getY();
                setNextPosition(map->getPosition(next_x,next_y));
                return true;
            }
        }else if(currentPosition->getY()==destinationPosition->getY()){
            if(map->isAvalibe(currentPosition->getX()+1,currentPosition->getY())){
                next_x = currentPosition->getX()+1;
                next_y = currentPosition->getY();
                setNextPosition(map->getPosition(next_x,next_y));
                return true;
            }else if(map->isAvalibe(currentPosition->getX()+1,currentPosition->getY()-1)){
                next_x = currentPosition->getX()+1;
                next_y = currentPosition->getY()-1;
                setNextPosition(map->getPosition(next_x,next_y));
                return true;
            }else if(map->isAvalibe(currentPosition->getX()+1,currentPosition->getY()+1)){
                next_x = currentPosition->getX()+1;
                next_y = currentPosition->getY()+1;
                setNextPosition(map->getPosition(next_x,next_y));
                return true;
            }
        }else{
            if(map->isAvalibe(currentPosition->getX()+1,currentPosition->getY()+1)){
                next_x = currentPosition->getX()+1;
                next_y = currentPosition->getY()+1;
                setNextPosition(map->getPosition(next_x,next_y));
                return true;
            }else if(map->isAvalibe(currentPosition->getX()+1,currentPosition->getY())){
                next_x = currentPosition->getX()+1;
                next_y = currentPosition->getY();
                setNextPosition(map->getPosition(next_x,next_y));
                return true;
            }else if(map->isAvalibe(currentPosition->getX(),currentPosition->getY()+1)){
                next_x = currentPosition->getX();
                next_y = currentPosition->getY()+1;
                setNextPosition(map->getPosition(next_x,next_y));
                return true;
            }
        }
    }
    this->setNextPosition(this->getCurrentPosition());
    return false;
}

Position *Robot::getNextPosition() const
{
    return nextPosition;
}

void Robot::setNextPosition(Position *value)
{
    nextPosition = value;
}

void Robot::logic()
{

}

void Robot::move()
{
        this->nextPosition->setIsEmpty(false);
        this->setLastPosition(currentPosition);
        this->setCurrentPosition(nextPosition);
        this->setNextPosition(nullptr);
        this->lastPosition->setIsEmpty(true);
}


Position *Robot::getLastPosition() const
{
    return lastPosition;
}

void Robot::setLastPosition(Position *value)
{
    lastPosition = value;
}

bool Robot::finished()
{
    bool end = 0;
    if(this->currentPosition == this->destinationPosition){
        end =1;
    }else if((this->destinationPosition->getX() <0)&&(this->destinationPosition->getY() <0)){
        end =1;
    }
    if(this->currentPosition == this->lastPosition){
        end=1;
    }
    //qDebug() <<"gradr " << grade << " current pos " << currentPosition->getX() << " " << currentPosition->getY() << "last pos" << lastPosition->getX() << " " << lastPosition->getY();
    return end;
}


Map *Robot::getMap() const
{
    return map;
}

Robot::Robot()
{

}

Robot::Robot(Robot &_robot)
{
    grade=_robot.grade;
    map=_robot.map;
    nextPosition=_robot.nextPosition;
    currentPosition=_robot.currentPosition;
    lastPosition=_robot.lastPosition;
    destinationPosition=_robot.destinationPosition;
    followedRobots=_robot.followedRobots;
}

Robot::Robot(int _grade, Position *_position, Map *_map)
{
    grade = _grade;
    //formation=_formation;
    currentPosition = _position;
    destinationPosition = _position;
    nextPosition = nullptr;
    lastPosition = nullptr;
    //timer = new QTimer();
    map =_map;
    currentPosition->setIsEmpty(false);

}



Robot::~Robot()
{

}


