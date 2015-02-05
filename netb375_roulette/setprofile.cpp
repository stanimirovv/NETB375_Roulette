#include "setprofile.h"
#include "ui_setprofile.h"
#include "mainwindow.h"
#include "startwindow.h"

SetProfile::SetProfile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetProfile)
{
    ui->setupUi(this);
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
    mwindow->show();
}
