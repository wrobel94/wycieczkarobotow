#ifndef POSITION_H
#define POSITION_H

#include <QDebug>

class Position
{
private:
    int x,y;
    bool isEmpty;
public:
    Position();
    Position(int _x, int _y);

    void print();
    int getX() const;
    int getY() const;
    /*!
     * \brief getIsEmpty funkcja pozwalająca sprawdzić czy dane pole jest zajęte przez innego robota albo znajdującą się na nim przeszkodę
     * \return
     */
    bool getIsEmpty() const;
    void setIsEmpty(bool value);
    bool operator==(Position  *_position);
};

#endif // POSITION_H
