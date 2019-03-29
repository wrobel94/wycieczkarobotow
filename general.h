#ifndef GENERAL_H
#define GENERAL_H
#include "robot.h"
/*!
 * \brief The General class General dowodca robotów
 */
class General: public Robot
{
public:
    General();
    General(General& _general);
    General(Position *_position,Map *_map);
    void logic();
};

#endif // GENERAL_H
