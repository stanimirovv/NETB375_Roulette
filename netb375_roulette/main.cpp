#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//dashov comment
    //QSqlDatabase db = QSqlDatabase::addDatabase(“QPSQL”);
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("nykal");
    db.setUserName("nykal");
    db.setPassword("123");
    db.open(); //  return a.exec();
    QSqlQuery query(db);
    query.prepare("SELECT now() as tt1;");
    query.exec();
    int index = query.record().indexOf("tt1");
    while (query.next())
    {
        QString time = query.value(index).toString();
        qDebug() << "Qdebug:r" << time;
    }

    db.close();
    return a.exec();
}
