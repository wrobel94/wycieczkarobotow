#include "mapcreator.h"
#include "ui_mapcreator.h"
#include "scribblearea.h"

MapCreator::MapCreator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MapCreator)
{
    ui->setupUi(this);
}

MapCreator::~MapCreator()
{
    delete ui;
}
