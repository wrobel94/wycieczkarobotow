#include "formationview.h"

int FormationView::getX() const
{
    return x;
}

int FormationView::getY() const
{
    return y;
}

int FormationView::getX_clicked() const
{
    return x_clicked;
}

int FormationView::getY_clicked() const
{
    return y_clicked;
}

FormationView::FormationView(QWidget *parent) : QGraphicsView(parent)
{

}

FormationView::FormationView(QGraphicsScene *_scene, QWidget *parent) : QGraphicsView(parent)
{
    scene =_scene;
}

void FormationView::mouseMoveEvent(QMouseEvent *event)
{
    this->x = event->x();
    this->y = event->y();
    emit Mouse_Position();
}

void FormationView::mousePressEvent(QMouseEvent *event)
{
    this->x_clicked = event->x();
    this->y_clicked = event->y();
    emit Mouse_Pressed();
}

void FormationView::clear()
{
    robotsViews.clear();
}

FormationView::~FormationView()
{

}

