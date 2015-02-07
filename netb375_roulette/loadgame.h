#ifndef LOADGAME_H
#define LOADGAME_H

#include <QWidget>
#include "mainwindow.h"


namespace Ui {
class LoadGame;
}

class LoadGame : public QWidget
{
    Q_OBJECT

public:
    explicit LoadGame(QWidget *parent = 0);
    ~LoadGame();

private slots:
    void on_pushButton_released();

private:
    Ui::LoadGame *ui;
    MainWindow *mwindow;
};

#endif // LOADGAME_H
