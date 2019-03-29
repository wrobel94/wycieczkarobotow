#ifndef FORMATION_H
#define FORMATION_H

#include "robot.h"
#include "vector"
#include "memory"
#include <QDebug>
#include <QTimer>
#include "map.h"
#include "thread"
class Robot;

/*!
 * \brief The Formation class
 */
class Formation
{
private:
    std::vector<Robot*> robots;
    Map* map;
public:
    Formation();
    Formation(Map *map);
    ~Formation();
    /*!
     * \brief addRobotToFormation dodaje robota do formacji
     * \param _robot
     */
    void addRobotToFormation(Robot* _robot);
    //void addRobotToFormation(Robot *_robot);
    /*!
     * \brief getGeneral zwraca generala
     * \return
     */
    Robot *getGeneral();
    /*!
     * \brief size zwraca wielkosc formacji - ilosc robotow
     * \return
     */
    int size();
    /*!
     * \brief clear czysci formacje
     */
    void clear();
    void print();
    void printByRobots();
    /*!
     * \brief getRobotsPointers zwraca wskazniki na roboty znajdujace sie w formacji
     * \return
     */
    std::vector<Robot*> getRobotsPointers();
    /*!
     * \brief setFollowedRobots funkcja odpowiedzialna za wkazanie robotom ich przełożonych
     */
    void setFollowedRobots();
    Map *getMap();
    void setRobots(std::vector<Robot* > value);
};

#endif // FORMATION_H
