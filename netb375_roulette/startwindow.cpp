#include "startwindow.h"
#include "ui_startwindow.h"
#include "setprofile.h"

StartWindow::StartWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    setStyleSheet("StartWindow {background-color:green};");
}

StartWindow::~StartWindow()
{
    delete ui;
}


void StartWindow::on_pushButton_new_clicked()
{
    setprof = new SetProfile();
    setprof->show();
}

void StartWindow::on_pushButton_quit_clicked()
{
    QApplication::quit();
}
