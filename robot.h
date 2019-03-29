#ifndef ROBOT_H
#define ROBOT_H

#include "position.h"
//#include "vector"
//#include "memory"
#include "formation.h"
//#include "map.h"
#include <QDebug>
#include <QTimer>
#include "sensor.h"

#include <QObject>

class Formation;
class Map;
//template<>
class Sensor;
class Robot: public QObject
{
    Q_OBJECT
protected:
    /*!
     * \brief grade stopień robota
     */
    int grade;
    Map *map;
    /*!
     * \brief nextPosition nastepne pole na ktore robot zamierza się przemiścić
     */
    Position *nextPosition;
    /*!
     * \brief currentPosition pole na którym aktualnie przebywa robot
     */
    Position *currentPosition;
    /*!
     * \brief lastPosition poprzednia pozycja robota
     */
    Position *lastPosition;
    /*!
     * \brief destinationPosition pozycja docelowa w aktualnej chwili
     */
    Position *destinationPosition;
    std::vector<Robot *> followedRobots;

    void move();
public:
    Robot();
    Robot(Robot &_robot);
    Robot(int _grade, Position* _position, Map *_map);
    ~Robot();
    void print();
    Position *getCurrentPosition() const;
    void setCurrentPosition(Position *value);
    Position *getDestinationPosition() const;
    void setDestinationPosition(Position *value);
    std::vector<Robot *> getFollowedRobots() const;
    void setFollowedRobots(const std::vector<Robot *> &value);
    int getGrade() const;
    void setGrade(int value);
    bool nextPositionCalculate();
    Position *getNextPosition() const;
    void setNextPosition(Position *value);
    virtual void logic();
    Position *getLastPosition() const;
    void setLastPosition(Position *value);
    /*!
     * \brief finished funkcja sprawdzająca czy robot znalazł się u celu albo czy nadal się przemieszcza
     * \return
     */
    bool finished();
    Map *getMap() const;
signals:
     void change_position();
};

#endif // ROBOT_H
