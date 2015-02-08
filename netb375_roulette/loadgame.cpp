#include "loadgame.h"
#include "ui_loadgame.h"

/*
 * Automatically generated constructor from the Qt IDE. There are a few custom settings for the window's style.
 */

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

/*
 * This method takes no parameters.
 * Loads a game with the username typed in the text box.
 * This method returns no value.
 */
void LoadGame::on_pushButton_released()
{
    mwindow->rl.loadGame(ui->loadUser->text());
    mwindow->show();
}
