#include "loadgame.h"
#include "ui_loadgame.h"

LoadGame::LoadGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoadGame)
{
    ui->setupUi(this);
    this->move(800, 250);//window positioning
    setStyleSheet("LoadGame {background-color:green};");
}

LoadGame::~LoadGame()
{
    delete ui;
}
