#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <QString>
#include "roulettegame.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    RouletteGame new_game = RouletteGame(1, 1, "nykal", "localhost", "nykal", "123");
    return a.exec();
}


