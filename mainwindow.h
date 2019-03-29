#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <game.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QtGui>
#include <vector>
#include "memory"
#include "formationcreator.h"
#include "mapcreator.h"
#include "robotview.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    int scale=5;
    int windowX=1020, windowY=650;
    Game *game;
    QGraphicsScene *scene;
    Ui::MainWindow *ui;
    std::vector<RobotView *> robotViews;
    FormationCreator formationCreator;

public:
    explicit MainWindow(QWidget *parent = 0);
    explicit MainWindow(Game *_game, QWidget *parent = 0);
    ~MainWindow();
    /*!
     * \brief addObstacles funkcja dodajaca przeszkode na okreslonym polu
     * \param _position
     */
    void addObstacles(Position *_position);
    void setRobotViews(const std::vector<RobotView *> &value);

private slots:
    void on_formationCreatorButton_clicked();
    void Mouse_postion();
    void Mouse_pressed();
    void Mouse_left();
    void on_pushButton_4_clicked();

};

#endif // MAINWINDOW_H
