#include "formation.h"

std::vector<Robot* > Formation::getRobotsPointers()
{
    return robots;
}

void Formation::setFollowedRobots()
{
    for(int i=0;i<robots.size();i++){
        if((robots[i]->getGrade())>0){

            std::vector<Robot *> followedRobots;
            for(int j=0;j<robots.size();j++){

                if((robots[i]->getGrade()-1)==robots[j]->getGrade()){
                    followedRobots.push_back(robots[j]);
                }
            }
            if(followedRobots.size()>0){
            robots[i]->setFollowedRobots(followedRobots);
            }
        }
    }

}

Map *Formation::getMap()
{
    return map;
}

void Formation::setRobots(std::vector<Robot* > value)
{
    robots.clear();
    for(int i=0; i<value.size();i++){
        robots.push_back(value[i]);
    }
}

Formation::Formation()
{
    
}

Formation::Formation(Map *_map)
{
    map = _map;
}

Formation::~Formation()
{

}

void Formation::addRobotToFormation(Robot* _robot)
{
    this->robots.push_back(_robot);
}



Robot *Formation::getGeneral()
{
    return robots.front();
}

int Formation::size()
{
    return robots.size();
}

void Formation::clear()
{
    robots.clear();
}


void Formation::print()
{
    qDebug() << "formation class";
    for(auto s:robots){
        s->print();
    }
}

void Formation::printByRobots()
{
    for(int i=0; i<robots.size(); i++){
        robots[i]->print();
    }
}
