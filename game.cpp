#include "game.h"

void Game::run()
{
    bool end = 1;
    for(int i=0;i<formation.getRobotsPointers().size();i++){
        formation.getRobotsPointers()[i]->logic();
    }
    for(int i = 0;i<formation.getRobotsPointers().size();i++){
        if(formation.getRobotsPointers()[i]->finished()){
        }else{
            end=0;
        }
    }
    if(end){
        timer->stop();
    }
}




void Game::setFormation(const Formation &value)
{
    formation = value;
}

Game::Game()
{
    map = Map();
    formation =Formation(&map);
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(run()));
}

Game::~Game()
{

}

void Game::setTimer(int _time)
{
    timer->start(_time);
}

Map *Game::getMap()
{
    return &map;
}

Formation *Game::getFormation()
{
    return &formation;
}
