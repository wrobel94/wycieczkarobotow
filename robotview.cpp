#include "robotview.h"
#include <QDebug>
#include <QPen>
#include <QBrush>
Robot *RobotView::getRobot()
{
    return robot;
}

RobotView::RobotView()
{

}
RobotView::RobotView(Robot *_robot)
{
    robot=_robot;
    QBrush color;
    if(robot->getGrade()==0){
         color.setColor(Qt::red);
    }else if(robot->getGrade()==1){
        color.setColor(Qt::yellow);
    }else if(robot->getGrade()==2){
        color.setColor(Qt::green);
    }else if(robot->getGrade()==3){
        color.setColor(Qt::blue);
    }
    QPen black(Qt::black);
    QBrush col=color.color();
    black.setWidth(0);
    this->setPen(black);
    this->setBrush(col);
    setRect(0,0,1,1);
    setPos(robot->getCurrentPosition()->getX(),robot->getCurrentPosition()->getY());
    connect(robot,SIGNAL(change_position()),this,SLOT(refreshRobotView()));
}

RobotView::RobotView(Robot *_robot, QGraphicsRectItem *parent): QGraphicsRectItem(parent)
{
    robot=_robot;
    connect(robot,SIGNAL(change_position()),this,SLOT(refreshRobotView()));

}

RobotView::~RobotView()
{

}

void RobotView::refreshRobotView()
{
    setPos(robot->getCurrentPosition()->getX(),robot->getCurrentPosition()->getY());
}
