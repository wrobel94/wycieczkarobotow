#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "formationcreator.h"
#include "mapcreator.h"
#include "obstacle.h"

void MainWindow::setRobotViews(const std::vector<RobotView *> &value)
{
    robotViews = value;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::MainWindow(Game *_game, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(windowX, windowY));
    connect(ui->graphicsView, SIGNAL(Mouse_Position()), this, SLOT(Mouse_postion()));
    connect(ui->graphicsView, SIGNAL(Mouse_Pressed()), this, SLOT(Mouse_pressed()));
    connect(ui->graphicsView, SIGNAL(Mouse_Left()), this, SLOT(Mouse_left()));
    game=_game;
    QTimer *timer = new QTimer();
    ui->graphicsView->setFixedSize((game->getMap()->getXSize()*scale)+2, (game->getMap()->getYSize()*scale)+2);
    ui->graphicsView->fitInView(0, 0, (game->getMap()->getXSize()*scale), (game->getMap()->getYSize()*scale), Qt::KeepAspectRatio); // chyba mozna wywalic
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(0, 0, game->getMap()->getXSize(), game->getMap()->getYSize());
    ui->graphicsView->scale(scale,scale);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_formationCreatorButton_clicked()
{
    for(int i = 0;i<robotViews.size();i++){
        scene->removeItem(robotViews[i]);
    }
    FormationCreator formationCreator(game->getFormation());
    formationCreator.setModal(true);
    if(formationCreator.exec() == 0 ||formationCreator.exec() == 1){
        for(int i=0;i<game->getFormation()->size();i++){
            RobotView* bot = new RobotView(game->getFormation()->getRobotsPointers()[i]);
            scene->addItem(bot);
            robotViews.push_back(bot);
        }
    }
}



void MainWindow::Mouse_postion()
{
    ui->label_mouse_position->setText(QString("X = %1, Y = %2").arg(ui->graphicsView->getX()).arg(ui->graphicsView->getY()));
    int xx = QString::number(ui->graphicsView->getX()).toInt();
    int yy = QString::number(ui->graphicsView->getY()).toInt();
    QPointF point= ui->graphicsView->mapToScene(xx,yy);
    int x_dest = point.toPoint().x();
    int y_dest = point.toPoint().y();
    ui->label_click_position_scene_2->setText(QString("X = %1, Y = %2").arg(x_dest).arg(y_dest));
    if(!(ui->checkBox->checkState())){}
    else{
        if((x_dest<this->game->getMap()->getXSize())&&(y_dest<this->game->getMap()->getYSize())){
            if((x_dest>=0)&&(y_dest>=0)){
                if(ui->graphicsView->getScribbling()){
                    if((x_dest<this->game->getMap()->getXSize())&&(y_dest<this->game->getMap()->getYSize())){ // nie mozna wywalic bo za zakres wyjdzie
                        addObstacles(game->getMap()->getPosition(x_dest,y_dest));
                    }
                }
            }
        }
    }
}

void MainWindow::Mouse_pressed()
{

    int xx = QString::number(ui->graphicsView->getX()).toInt();
    int yy = QString::number(ui->graphicsView->getY()).toInt();

    QPointF point= ui->graphicsView->mapToScene(xx,yy);
    int x_dest = point.toPoint().x();
    int y_dest = point.toPoint().y();
    if(!(ui->checkBox->checkState())){
        if(!(game->getFormation()->getRobotsPointers().size())){
            return;
        }
        if((x_dest>=0)&&(y_dest>=0)){
            if((x_dest<this->game->getMap()->getXSize())&&(y_dest<this->game->getMap()->getYSize())){ // nie mozna wywalic bo za zakres wyjdzie

                game->getFormation()->getGeneral()->setDestinationPosition(game->getMap()->getPosition(x_dest,y_dest));
                game->setTimer(15);
            }
        }
    }
}

void MainWindow::Mouse_left()
{

}



void MainWindow::on_pushButton_4_clicked()
{
    for(int i =0;i<game->getMap()->getObstacles().size();i++){
        scene->removeItem((game->getMap()->getObstacles()[i]));
    }
    game->getMap()->clearObstacles();
}



void MainWindow::addObstacles(Position *_position)
{
    if(game->getMap()->addObstacle(_position)){
        scene->addItem(game->getMap()->getLastAddedObstacle());
        game->getMap()->getLastAddedObstacle()->setPosition();
    }
}


