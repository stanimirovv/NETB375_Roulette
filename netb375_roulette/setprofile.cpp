#include "setprofile.h"
#include "ui_setprofile.h"
#include "mainwindow.h"
#include "startwindow.h"

SetProfile::SetProfile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetProfile)
{
    ui->setupUi(this);
    this->setWindowTitle("New Game");
    this->move(800, 250);//window positioning
    setStyleSheet("SetProfile {background-color:green};");
}

SetProfile::~SetProfile()
{
    delete ui;
}

void SetProfile::on_pushButton_play_clicked()
{
    mwindow = new MainWindow(this); //creating a MainWindow obj->the board
    player new_player;
    new_player.name = ui->accountName->text();
    new_player.current_money_cents = ui->accountMoney->text().toInt();
    mwindow->rl.setPlayer(new_player);
    qDebug() << "Account money:  "  << ui->accountMoney->text() << "  Account name: " << ui->accountName->text() << endl;
    mwindow->show();
}
