#include "formationcreator.h"
#include "ui_formationcreator.h"

#include <QGraphicsRectItem>

void FormationCreator::addGeneral(QPointF point)
{
    int x_dest = point.toPoint().x();
    int y_dest = point.toPoint().y();
    General *robot = new General(formation->getMap()->getPosition(x_dest,y_dest),formation->getMap());
    formation->addRobotToFormation(robot);
    RobotView* bot = new RobotView(robot);
    scene->addItem(bot);
}

void FormationCreator::clearRobots()
{
    formation->clear();
    scene->clear();
}

FormationCreator::FormationCreator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormationCreator)
{
    ui->setupUi(this);
    connect(ui->graphicsView, SIGNAL(Mouse_Position()), this, SLOT(Mouse_postion()));
    connect(ui->graphicsView, SIGNAL(Mouse_Pressed()), this, SLOT(Mouse_pressed()));
    //connect(ui->graphicsView, SIGNAL(Mouse_Left()), this, SLOT(Mouse_left()));
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);



}

FormationCreator::FormationCreator(Formation *_formation, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormationCreator)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(windowX, windowY));
    connect(ui->graphicsView, SIGNAL(Mouse_Position()), this, SLOT(Mouse_postion()));
    connect(ui->graphicsView, SIGNAL(Mouse_Pressed()), this, SLOT(Mouse_pressed()));
    //connect(ui->graphicsView, SIGNAL(Mouse_Left()), this, SLOT(Mouse_left()));
    ui->graphicsView->setFixedSize((scale*sceneX)+2, (scale*sceneY)+2);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(0, 0, sceneX, sceneY);
    ui->graphicsView->scale(scale,scale);
    formation = _formation;
    for(int i = 0; i< formation->getRobotsPointers().size();i++){
        RobotView *robotView = new RobotView(formation->getRobotsPointers()[i]);
        robotViews.push_back(robotView);
        scene->addItem(robotView);
    }
    //zrob z tego private funkcje
    on_clearRobotsButton_clicked();
    //combobox
    QImage img(22,15,QImage::Format_RGB32);
    QPainter p(&img);
    p.fillRect(img.rect(), Qt::black);
    ui->comboBox->addItem("Pan i Wladca");
    ui->comboBox->addItem("Major");
    ui->comboBox->addItem("Kapral");
    ui->comboBox->addItem("Szeregowy");
    QRect rect = img.rect().adjusted(1,1,-1,-1);
    p.fillRect(rect, Qt::red);
    ui->comboBox->setItemData(0, QPixmap::fromImage(img), Qt::DecorationRole);
    p.fillRect(rect, Qt::yellow);
    ui->comboBox->setItemData(1, QPixmap::fromImage(img), Qt::DecorationRole);
    p.fillRect(rect, Qt::green);
    ui->comboBox->setItemData(2, QPixmap::fromImage(img), Qt::DecorationRole);
    p.fillRect(rect, Qt::blue);
    ui->comboBox->setItemData(3, QPixmap::fromImage(img), Qt::DecorationRole);
    //cobobox end
}


FormationCreator::~FormationCreator()
{
    formation->setFollowedRobots();
    for(int i=1;i<formation->size();i++){
        Soldier *soldier=  dynamic_cast<Soldier*>(formation->getRobotsPointers()[i]);
        soldier->setSensor();
    }


    delete ui;
}

void FormationCreator::addRobot(QPointF point)
{
    int current = ui->comboBox->currentIndex();

    ui->label_mouse_position_point->setText(QString("X = %1, Y = %2").arg(point.x()).arg(point.y()));
    if(formation->size()==0){
            addGeneral(point);
    }else{
        int x_dest = point.toPoint().x();
        int y_dest = point.toPoint().y();
        int highestgrade = 0;
        for(int i=0; i<formation->size();i++){
            if((highestgrade+1)== formation->getRobotsPointers()[i]->getGrade()){
                highestgrade = formation->getRobotsPointers()[i]->getGrade();

            }
        }
        if(current!=0){
            if(highestgrade>=(current-1)){
                if(formation->getMap()->getPosition(x_dest,y_dest)->getIsEmpty()==1){
                    Soldier *robot = new Soldier(current,formation->getMap()->getPosition(x_dest,y_dest),formation->getMap());
                    RobotView* bot = new RobotView(robot);
                    robotViews.push_back(bot);
                    formation->addRobotToFormation(robot);
                    ui->msg->setText("Udalo sie postawic robota");
                    scene->addItem(bot);

                }else{

                    ui->msg->setText("To pole jest zajete");
                }
            }else{
                ui->msg->setText("Za niska ranga");
                ui->comboBox->setCurrentIndex(1);
            }
        }else{

            ui->msg->setText("Niemozna tam wstawic robota!");
            ui->comboBox->setCurrentIndex(1);
        }
    }
}




void FormationCreator::on_addRobotButton_clicked()
{
    QString xx = ui->textEdit->toPlainText();
    QString xx1 = xx.split(",")[0];
    QString xx2 = xx.split(".")[0];
    int xxi1 = xx1.toInt();
    int xxi2 = xx2.toInt();
    if(xxi1>xxi2){
        xx=xx1;
    }else{
        xx=xx2;
    }
    QString yy = ui->textEdit_2->toPlainText();
    QString yy1 = yy.split(",")[0];
    QString yy2 = yy.split(".")[0];
    int yyi1 = yy1.toInt();
    int yyi2 = yy2.toInt();
    if(yyi1>yyi2){
        yy=yy1;
    }else{
        yy=yy2;
    }
    int x = xx.toInt();
    int y = yy.toInt();
    if((x >=0)&&(x<=sceneX)){
        if((y >=0)&&(x<=sceneY)){
            QPointF point(x,y);
            ui->textEdit->clear();
            ui->textEdit_2->clear();
            addRobot(point);
        }
    }
    else{
        ui->msg->setText("Zle koordynaty");
    }
}

void FormationCreator::on_clearRobotsButton_clicked()
{
    ui->graphicsView->clear();
    scene->clear();
    formation->clear();
    ui->graphicsView->setScene(scene);
}

void FormationCreator::Mouse_postion()
{
    ui->label_mouse_position->setText(QString("X = %1, Y = %2").arg(ui->graphicsView->getX()).arg(ui->graphicsView->getY()));
    int x = QString::number(ui->graphicsView->getX()).toInt();
    int y = QString::number(ui->graphicsView->getY()).toInt();
    QPointF point= ui->graphicsView->mapToScene(x,y);
    ui->label_mouse_position_point_2->setText(QString("X = %1, Y = %2").arg(point.x()).arg(point.y()));
}


void FormationCreator::Mouse_pressed()
{
    ui->label_click_position->setText(QString("X = %1, Y = %2").arg(ui->graphicsView->getX_clicked()).arg(ui->graphicsView->getY_clicked()));
    int x = QString::number(ui->graphicsView->getX_clicked()).toInt();
    int y = QString::number(ui->graphicsView->getY_clicked()).toInt();
    QPointF point= ui->graphicsView->mapToScene(x,y);
    addRobot(point);
}

void FormationCreator::on_pushButton_clicked()
{
    qDebug() << "showrobots";
    qDebug() << formation->getRobotsPointers().size();
}





