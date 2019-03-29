#ifndef SOLDIER_H
#define SOLDIER_H
#include "robot.h"

class Soldier: public Robot
{
     Sensor *sensor;
public:
    Soldier();
    Soldier(Soldier& _soldier);
    Soldier(int _grade,Position *_position,Map *_map);
    /*!
     * \brief setSensor inicjalizuje sensor robota
     */
    void setSensor();
    void logic();
};

#endif // SOLDIER_H
