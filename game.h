#ifndef GAME_H
#define GAME_H

#include "map.h"
#include "formation.h"
#include "robot.h"
#include "vector"
#include <QDebug>
#include <string>
#include <iostream>
#include <QObject>
#include "obstacle.h"
#include <thread>
class Game : public QObject
{
    Q_OBJECT
private:
    Map map;
    Formation formation;
    QTimer *timer;
public:
    Game();
    ~Game();
    /*!
     * \brief setTimer funkcja ustalajaca szybkosc odswieżania logiki programu
     * \param _time
     */
    void setTimer(int _time);
    Map *getMap();
    Formation *getFormation();
    void setFormation(const Formation &value);

public slots:
    void run();
};

#endif // GAME_H
