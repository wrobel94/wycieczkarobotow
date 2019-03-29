#ifndef MAPCREATOR_H
#define MAPCREATOR_H

#include <QDialog>
#include <QList>    //

namespace Ui {
class MapCreator;
}

class MapCreator : public QDialog
{
    Q_OBJECT

public:
    explicit MapCreator(QWidget *parent = 0);
    ~MapCreator();
protected:


private slots:


private:
    Ui::MapCreator *ui;
};

#endif // MAPCREATOR_H
