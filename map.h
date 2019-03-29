#ifndef MAP_H
#define MAP_H

#include "position.h"
#include "vector"
#include "obstacle.h"
#include <QDebug>

class Map
{
private:
    int xSize = 160;
    int ySize = 120;
    std::vector<std::vector<Position> > positions;
    std::vector<Obstacle *> obstacles;
public:
    Map();
    ~Map();
    void print();
    Position *getPosition(int _x, int _y);
    /*!
     * \brief isAvalibe funkcja sprawdzajaca czy pole o wskazanych wspolrzędnych znajduje się na mapie
     * \param _x
     * \param _y
     * \return
     */
    bool isAvalibe(int _x, int _y);
    bool addObstacle(Position *_position);
    /*!
     * \brief getLastAddedObstacle daje możliwość dostępu do ostatniej przeszkody która została dodana
     * \return
     */
    Obstacle *getLastAddedObstacle();
    std::vector<Obstacle *> getObstacles() const;
    void clearObstacles();
    int getXSize() const;
    int getYSize() const;
};

#endif // MAP_H
