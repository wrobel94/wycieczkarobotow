#include "mainwindow.h"
#include <QApplication>
#include "game.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game *game = new Game();
    MainWindow w(game);
    w.show();

    return a.exec();
}
