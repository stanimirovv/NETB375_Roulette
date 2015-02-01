#include "setprofile.h"
#include "ui_setprofile.h"
#include "mainwindow.h"
#include "startwindow.h"

SetProfile::SetProfile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetProfile)
{
    ui->setupUi(this);
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
