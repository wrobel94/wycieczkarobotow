#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#include <QGraphicsView>
#include "game.h"
#include <QtWidgets>
#include <QWidget>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>
#include "robotview.h"
#include <QGraphicsScene>
#include <QPointF>

class GameView : public QGraphicsView
{
     Q_OBJECT
private:
    int x, y;
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void leaveEvent(QEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    QGraphicsScene* scene;
    std::vector<RobotView*> robotsViews;
    /*!
     * \brief scribbling zmienna ktora wskazuje na to czy w aktyualnym momencie wcisniety jest lewy przycisk myszy
     */
    bool scribbling = false;
public:
    explicit GameView(QWidget* parent = 0);
    explicit GameView(QGraphicsScene *_scene, QWidget* parent = 0);

    bool getScribbling() const;

    int getX() const;

    int getY() const;

signals:
    void Mouse_Position();
    void Mouse_Pressed();
    void Mouse_Left();
    void Mouse_Release();

};

#endif // GAMEVIEW_H
