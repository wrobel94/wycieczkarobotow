#ifndef SENSOR_H
#define SENSOR_H
#include "robot.h"
class Robot;
/*!
 * \brief The Sensor class sensor pozwala na wyznaczenie pozycji docelowej na podstawie położenia przełożonych
 */
class Sensor
{
private:
    /*!
     * \brief x_x odległość na osi poziomej w jakiej powien znajdować się robot od wyznaczonego miejsca aby zachować szyk
     */
    int x_x=0; // tylko dla soldiers
    /*!
     * \brief y_y odległość na osi pionowej w jakiej powien znajdować się robot od wyznaczonego miejsca aby zachować szyk
     */
    int y_y=0;
    Robot* robot;
    /*!
     * \brief funkcja incjalizujaca parametry sensora
     */
    void Initialize();
    void setX_x();
    void setY_y();
public:
    Sensor();
    Sensor(Robot *_robot);
    /*!
     * \brief calculateFallowingPosition funkcja wyznaczajaca pozycje docelową w oparciu o aktualne współrzędne śledzonych robotów
     */
    void calculateFallowingPosition();

};
#endif // SENSOR_H
