#ifndef FORMATIONCREATOR_H
#define FORMATIONCREATOR_H

#include <QDialog>

//wyswietlanie
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QtGui>
#include <formation.h>
#include <game.h>
#include "sensor.h"
#include "general.h"
#include "soldier.h"
#include "thread"
#include "robotview.h"
namespace Ui {
class FormationCreator;
}
/*!
 * \brief The FormationCreator class
 */
class FormationCreator : public QDialog
{
    Q_OBJECT

private:
    int scale=5;
    int windowX=590, windowY=220;
    int sceneX=60,sceneY=40;
    void addGeneral(QPointF point);
    void clearRobots();
    Ui::FormationCreator *ui;
    Formation *formation;
    QGraphicsScene *scene;
    std::vector<RobotView *> robotViews;

public:
    explicit FormationCreator(QWidget *parent = 0);
    explicit FormationCreator(Formation *_formation, QWidget *parent = 0);
    ~FormationCreator();
    void addRobot(QPointF point);

private slots:

    void on_addRobotButton_clicked();
    void on_clearRobotsButton_clicked();
    void Mouse_postion();
    void Mouse_pressed();
    void on_pushButton_clicked();
};

#endif // FORMATIONCREATOR_H
