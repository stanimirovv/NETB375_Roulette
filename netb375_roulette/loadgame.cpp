#include "loadgame.h"
#include "ui_loadgame.h"

LoadGame::LoadGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoadGame)
{
    ui->setupUi(this);
    this->setWindowTitle("Load Game");
    this->move(800, 250);//window positioning
    setStyleSheet("LoadGame {background-color:green};");
    mwindow = new MainWindow(this); //creating a MainWindow obj->the board

}

LoadGame::~LoadGame()
{
    delete ui;
}

void LoadGame::on_pushButton_released()
{
    mwindow->rl.loadGame(ui->loadUser->text());
    mwindow->show();
}
