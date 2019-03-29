#include "map.h"

Obstacle *Map::getLastAddedObstacle()
{
    return obstacles.back();
}


bool Map::addObstacle(Position *_position)
{
    if(_position->getIsEmpty()){
        obstacles.push_back(new Obstacle(_position));
        return true;
    }
    return false;
}


std::vector<Obstacle *> Map::getObstacles() const
{
    return obstacles;
}

void Map::clearObstacles()
{
    for(int i=0;i<obstacles.size();i++){
        delete obstacles[i];
    }
    obstacles.clear();
}

int Map::getXSize() const
{
    return xSize;
}



int Map::getYSize() const
{
    return ySize;
}

Map::Map()
{
    std::vector<Position> tmp;
    for(int i = 0; i < this->xSize+1; i++){
        for(int j = 0; j < this->ySize+1; j++){
            tmp.push_back(Position(i,j));
        }
        positions.push_back(tmp);
        tmp.clear();
    }
}

Map::~Map()
{

}

void Map::print()
{
    for(int i = 0; i < 800; i++){
        for(int j = 0; j < 600; j++){
            this->getPosition(i,j)->print();
        }
    }
}

Position *Map::getPosition(int _x, int _y)
{
    return (&positions[_x][_y]);
}



//czy wspolrzedne znajduja sie na mapie
bool Map::isAvalibe(int _x, int _y)
{
        if((_x>=0)&&(_y>=0)){
            if((_x<this->xSize)&&(_y<this->ySize))
            if(this->getPosition(_x,_y)->getIsEmpty() == true){
                return true;
            }
        }
    return false;
}
