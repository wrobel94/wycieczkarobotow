#ifndef ROBOTVIEW_H
#define ROBOTVIEW_H
#include <QColor>
#include "robot.h"
#include <QObject>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
class RobotView : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    Robot *robot;
public:
    RobotView();
    RobotView(Robot *_robot);
    RobotView(Robot *_robot,QGraphicsRectItem *parent);
    ~RobotView();
    Robot *getRobot();

signals:
    void changeRobotView();
private slots:
    void refreshRobotView();
};

#endif // ROBOTVIEW_H
