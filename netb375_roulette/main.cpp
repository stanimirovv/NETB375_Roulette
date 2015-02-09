#include "mainwindow.h"
#include "startwindow.h"
#include <QApplication>
#include <QDebug>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //srand(time(NULL));
    QApplication a(argc, argv);
    StartWindow w;
    w.show();

    return a.exec();
}
