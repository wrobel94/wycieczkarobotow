#include "gameview.h"

int GameView::getX() const
{
    return x;
}

int GameView::getY() const
{
    return y;
}

void GameView::mouseMoveEvent(QMouseEvent *event)
{
    this->x = event->x();
    this->y = event->y();
    emit Mouse_Position();
}

void GameView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
           scribbling = true;
       }
    emit Mouse_Pressed();
}

void GameView::leaveEvent(QEvent *event)
{
    emit Mouse_Left();
}

void GameView::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && scribbling) {
            scribbling = false;
        }
    emit Mouse_Release();
}

bool GameView::getScribbling() const
{
    return scribbling;
}

GameView::GameView(QWidget *parent) : QGraphicsView(parent)
{
}

