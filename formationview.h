#ifndef FORMATIONVIEW_H
#define FORMATIONVIEW_H

#include <QGraphicsView>
#include <QtWidgets>
#include <QWidget>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>
#include "robotview.h"
#include <QGraphicsScene>
#include <QPointF>

class FormationView : public QGraphicsView
{
    Q_OBJECT
    //zmien czesc naprivaty i gettery zrob
private:
    QGraphicsScene *scene;
    std::vector<RobotView*> robotsViews;
    int x,y;
    int x_clicked, y_clicked;
public:
    explicit FormationView(QWidget* parent = 0);
    explicit FormationView(QGraphicsScene *_scene, QWidget* parent = 0);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void clear();
    ~FormationView();
    int getX() const;

    int getY() const;
    /*!
     * \brief getX_clicked zwraca współrzędną x miejsca w którym został kilknięty przycisk myszki
     * \return
     */
    int getX_clicked() const;
    /*!
     * \brief getY_clicked zwraca współrzędną y miejsca w którym został kilknięty przycisk myszki
     * \return
     */
    int getY_clicked() const;

signals:
    void Mouse_Position();
    void Mouse_Pressed();
};

#endif // FORMATIONVIEW_H
