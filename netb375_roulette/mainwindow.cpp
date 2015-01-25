#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setStyleSheet("MainWindow {background-color:green};"); //setting background color only to MainWindow
    QPixmap pixmap("/home/aleksandar/Desktop/roulette working/NETB375_Roulette-master/netb375_roulette/img/roulette3.gif");
    ui->label_gif->setPixmap(pixmap); //setting an image for the spin button
}

MainWindow::~MainWindow()
{
    delete ui;
}
/* should remove spinner and slider
 * should add a second window
 * should add a resorse file and pictures for the chips
 * should add animation
 * should add Zlatin and Stoyan's work to this */

/* definisions for all the button functions
 * if a button is clicked it becomes flat
 * and in the coresponding position sets in the array a "1"
 * if a button is clicked again it set a "0" and is no longer flat
 * same for buttons from 0 to 36(starting from 1 the 0 is after 36)
 * (further gonna add chips on the bet buttons so when clicked and after that click on a number it will display the chip and the reverse)
 * (need to add funtions for bets,colors and clear)*/

int n;// random generated number
char color1,color2; //player chosen color

int arr_rulette[37];//defines array for bets
char arr_rulettec[37]={'G','R','B','R','B','R','B','R','B','R','B','B','R','B','R','B','R','B','R','R','B','R','B','R','B','R','B','R','B','B','R','B','R','B','R','B','R'};
//defines arrays of colors

bool check_num(int n)//checks for 1 in the array of bets on the random generated number's position
{
    if(1==arr_rulette[n])
    {
        QString str;
        str.setNum(n);
        QMessageBox message;
        message.setText("you win the random number is "+str);
        message.exec();
    }
    else
    {
        QString str;
        str.setNum(n);
        QMessageBox message1;
        message1.setText("you lose the random number is "+str);
        message1.exec();
    }
    return false;
}

bool check_color(int n)//checks for the color of the random generated number
{
    if(arr_rulettec[n]==color1 || arr_rulettec[n]==color2)
    {
        QString str;
        str.setNum(n);
        QMessageBox message;
        message.setText("you win the random number is "+str);
        message.exec();
    }
    else
    {
        QString str;
        str.setNum(n);
        QMessageBox message1;
        message1.setText("you lose the random number is "+str);
        message1.exec();
    }
    return false;
}



void MainWindow::on_pushButton_1_clicked()
{
    if(ui->pushButton_1->isFlat())
    {
        arr_rulette[1] = 0;
        ui->pushButton_1->setFlat(false);
    }
    else
    {
        arr_rulette[1] = 1;
        ui->pushButton_1->setFlat(true);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->pushButton_2->isFlat())
    {
        arr_rulette[2] = 0;
        ui->pushButton_2->setFlat(false);
    }
    else
    {
        arr_rulette[2] = 1;
        ui->pushButton_2->setFlat(true);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(ui->pushButton_3->isFlat())
    {
        arr_rulette[3] = 0;
        ui->pushButton_3->setFlat(false);
    }
    else
    {
        arr_rulette[3] = 1;
        ui->pushButton_3->setFlat(true);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if(ui->pushButton_4->isFlat())
    {
        arr_rulette[4] = 0;
        ui->pushButton_4->setFlat(false);
    }
    else
    {
        arr_rulette[4] = 1;
        ui->pushButton_4->setFlat(true);
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    if(ui->pushButton_5->isFlat())
    {
        arr_rulette[5] = 0;
        ui->pushButton_5->setFlat(false);
    }
    else
    {
        arr_rulette[5] = 1;
        ui->pushButton_5->setFlat(true);
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    if(ui->pushButton_6->isFlat())
    {
        arr_rulette[6] = 0;
        ui->pushButton_6->setFlat(false);
    }
    else
    {
        arr_rulette[6] = 1;
        ui->pushButton_6->setFlat(true);
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    if(ui->pushButton_7->isFlat())
    {
        arr_rulette[7] = 0;
        ui->pushButton_7->setFlat(false);
    }
    else
    {
        arr_rulette[7] = 1;
        ui->pushButton_7->setFlat(true);
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    if(ui->pushButton_8->isFlat())
    {
        arr_rulette[8] = 0;
        ui->pushButton_8->setFlat(false);
    }
    else
    {
        arr_rulette[8] = 1;
        ui->pushButton_8->setFlat(true);
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    if(ui->pushButton_9->isFlat())
    {
        arr_rulette[9] = 0;
        ui->pushButton_9->setFlat(false);
    }
    else
    {
        arr_rulette[9] = 1;
        ui->pushButton_9->setFlat(true);
    }
}

void MainWindow::on_pushButton_10_clicked()
{
    if(ui->pushButton_10->isFlat())
    {
        arr_rulette[10] = 0;
        ui->pushButton_10->setFlat(false);
    }
    else
    {
        arr_rulette[10] = 1;
        ui->pushButton_10->setFlat(true);
    }
}

void MainWindow::on_pushButton_11_clicked()
{
    if(ui->pushButton_11->isFlat())
    {
        arr_rulette[11] = 0;
        ui->pushButton_11->setFlat(false);
    }
    else
    {
        arr_rulette[11] = 1;
        ui->pushButton_11->setFlat(true);
    }
}

void MainWindow::on_pushButton_12_clicked()
{
    if(ui->pushButton_12->isFlat())
    {
        arr_rulette[12] = 0;
        ui->pushButton_12->setFlat(false);
    }
    else
    {
        arr_rulette[12] = 1;
        ui->pushButton_12->setFlat(true);
    }
}

void MainWindow::on_pushButton_13_clicked()
{
    if(ui->pushButton_13->isFlat())
    {
        arr_rulette[13] = 0;
        ui->pushButton_13->setFlat(false);
    }
    else
    {
        arr_rulette[13] = 1;
        ui->pushButton_13->setFlat(true);
    }
}

void MainWindow::on_pushButton_14_clicked()
{
    if(ui->pushButton_14->isFlat())
    {
        arr_rulette[14] = 0;
        ui->pushButton_14->setFlat(false);
    }
    else
    {
        arr_rulette[14] = 1;
        ui->pushButton_14->setFlat(true);
    }
}

void MainWindow::on_pushButton_15_clicked()
{
    if(ui->pushButton_15->isFlat())
    {
        arr_rulette[15] = 0;
        ui->pushButton_15->setFlat(false);
    }
    else
    {
        arr_rulette[15] = 1;
        ui->pushButton_15->setFlat(true);
    }
}

void MainWindow::on_pushButton_16_clicked()
{
    if(ui->pushButton_16->isFlat())
    {
        arr_rulette[16] = 0;
        ui->pushButton_16->setFlat(false);
    }
    else
    {
        arr_rulette[16] = 1;
        ui->pushButton_16->setFlat(true);
    }
}

void MainWindow::on_pushButton_17_clicked()
{
    if(ui->pushButton_17->isFlat())
    {
        arr_rulette[17] = 0;
        ui->pushButton_17->setFlat(false);
    }
    else
    {
        arr_rulette[17] = 1;
        ui->pushButton_17->setFlat(true);
    }
}

void MainWindow::on_pushButton_18_clicked()
{
    if(ui->pushButton_18->isFlat())
    {
        arr_rulette[18] = 0;
        ui->pushButton_18->setFlat(false);
    }
    else
    {
        arr_rulette[18] = 1;
        ui->pushButton_18->setFlat(true);
    }
}

void MainWindow::on_pushButton_19_clicked()
{
    if(ui->pushButton_19->isFlat())
    {
        arr_rulette[19] = 0;
        ui->pushButton_19->setFlat(false);
    }
    else
    {
        arr_rulette[19] = 1;
        ui->pushButton_19->setFlat(true);
    }
}

void MainWindow::on_pushButton_20_clicked()
{
    if(ui->pushButton_20->isFlat())
    {
        arr_rulette[20] = 0;
        ui->pushButton_20->setFlat(false);
    }
    else
    {
        arr_rulette[20] = 1;
        ui->pushButton_20->setFlat(true);
    }
}

void MainWindow::on_pushButton_21_clicked()
{
    if(ui->pushButton_21->isFlat())
    {
        arr_rulette[21] = 0;
        ui->pushButton_21->setFlat(false);
    }
    else
    {
        arr_rulette[21] = 1;
        ui->pushButton_21->setFlat(true);
    }
}

void MainWindow::on_pushButton_22_clicked()
{
    if(ui->pushButton_22->isFlat())
    {
        arr_rulette[22] = 0;
        ui->pushButton_22->setFlat(false);
    }
    else
    {
        arr_rulette[22] = 1;
        ui->pushButton_22->setFlat(true);
    }
}

void MainWindow::on_pushButton_23_clicked()
{
    if(ui->pushButton_23->isFlat())
    {
        arr_rulette[23] = 0;
        ui->pushButton_23->setFlat(false);
    }
    else
    {
        arr_rulette[23] = 1;
        ui->pushButton_23->setFlat(true);
    }
}

void MainWindow::on_pushButton_24_clicked()
{
    if(ui->pushButton_24->isFlat())
    {
        arr_rulette[24] = 0;
        ui->pushButton_24->setFlat(false);
    }
    else
    {
        arr_rulette[24] = 1;
        ui->pushButton_24->setFlat(true);
    }
}

void MainWindow::on_pushButton_25_clicked()
{
    if(ui->pushButton_25->isFlat())
    {
        arr_rulette[25] = 0;
        ui->pushButton_25->setFlat(false);
    }
    else
    {
        arr_rulette[25] = 1;
        ui->pushButton_25->setFlat(true);
    }
}

void MainWindow::on_pushButton_26_clicked()
{
    if(ui->pushButton_26->isFlat())
    {
        arr_rulette[26] = 0;
        ui->pushButton_26->setFlat(false);
    }
    else
    {
        arr_rulette[26] = 1;
        ui->pushButton_26->setFlat(true);
    }
}

void MainWindow::on_pushButton_27_clicked()
{
    if(ui->pushButton_27->isFlat())
    {
        arr_rulette[27] = 0;
        ui->pushButton_27->setFlat(false);
    }
    else
    {
        arr_rulette[27] = 1;
        ui->pushButton_27->setFlat(true);
    }
}

void MainWindow::on_pushButton_28_clicked()
{
    if(ui->pushButton_28->isFlat())
    {
        arr_rulette[28] = 0;
        ui->pushButton_28->setFlat(false);
    }
    else
    {
        arr_rulette[28] = 1;
        ui->pushButton_28->setFlat(true);
    }
}

void MainWindow::on_pushButton_29_clicked()
{
    if(ui->pushButton_29->isFlat())
    {
        arr_rulette[29] = 0;
        ui->pushButton_29->setFlat(false);
    }
    else
    {
        arr_rulette[29] = 1;
        ui->pushButton_29->setFlat(true);
    }
}

void MainWindow::on_pushButton_30_clicked()
{
    if(ui->pushButton_30->isFlat())
    {
        arr_rulette[30] = 0;
        ui->pushButton_30->setFlat(false);
    }
    else
    {
        arr_rulette[30] = 1;
        ui->pushButton_30->setFlat(true);
    }
}

void MainWindow::on_pushButton_31_clicked()
{
    if(ui->pushButton_31->isFlat())
    {
        arr_rulette[31] = 0;
        ui->pushButton_31->setFlat(false);
    }
    else
    {
        arr_rulette[31] = 1;
        ui->pushButton_31->setFlat(true);
    }
}

void MainWindow::on_pushButton_32_clicked()
{
    if(ui->pushButton_32->isFlat())
    {
        arr_rulette[32] = 0;
        ui->pushButton_32->setFlat(false);
    }
    else
    {
        arr_rulette[32] = 1;
        ui->pushButton_32->setFlat(true);
    }
}

void MainWindow::on_pushButton_33_clicked()
{
    if(ui->pushButton_33->isFlat())
    {
        arr_rulette[33] = 0;
        ui->pushButton_33->setFlat(false);
    }
    else
    {
        arr_rulette[33] = 1;
        ui->pushButton_33->setFlat(true);
    }
}

void MainWindow::on_pushButton_34_clicked()
{
    if(ui->pushButton_34->isFlat())
    {
        arr_rulette[34] = 0;
        ui->pushButton_34->setFlat(false);
    }
    else
    {
        arr_rulette[34] = 1;
        ui->pushButton_34->setFlat(true);
    }
}

void MainWindow::on_pushButton_35_clicked()
{
    if(ui->pushButton_35->isFlat())
    {
        arr_rulette[35] = 0;
        ui->pushButton_35->setFlat(false);
    }
    else
    {
        arr_rulette[35] = 1;
        ui->pushButton_35->setFlat(true);
    }
}

void MainWindow::on_pushButton_36_clicked()
{
    if(ui->pushButton_36->isFlat())
    {
        arr_rulette[36] = 0;
        ui->pushButton_36->setFlat(false);
    }
    else
    {
        arr_rulette[36] = 1;
        ui->pushButton_36->setFlat(true);
    }
}

void MainWindow::on_pushButton_0_clicked()
{
    if(ui->pushButton_0->isFlat())
    {
        arr_rulette[0] = 0;
        ui->pushButton_0->setFlat(false);
    }
    else
    {
        arr_rulette[0] = 1;
        ui->pushButton_0->setFlat(true);
    }
}
// works the same but on multiple buttons without changeing them
// checks if the button is flat if not set's it to 0 when removing bets if yes does nothing
// same for all the fallowing buttons
void MainWindow::on_pushButton_1_18_clicked()
{
    if(ui->pushButton_1_18->isFlat())
    {
        if(ui->pushButton_1->isFlat()){}
        else{arr_rulette[1] = 0;}
        if(ui->pushButton_2->isFlat()){}
        else{arr_rulette[2] = 0;}
        if(ui->pushButton_3->isFlat()){}
        else{arr_rulette[3] = 0;}
        if(ui->pushButton_4->isFlat()){}
        else{arr_rulette[4] = 0;}
        if(ui->pushButton_5->isFlat()){}
        else{arr_rulette[5] = 0;}
        if(ui->pushButton_6->isFlat()){}
        else{arr_rulette[6] = 0;}
        if(ui->pushButton_7->isFlat()){}
        else{arr_rulette[7] = 0;}
        if(ui->pushButton_8->isFlat()){}
        else{arr_rulette[8] = 0;}
        if(ui->pushButton_9->isFlat()){}
        else{arr_rulette[9] = 0;}
        if(ui->pushButton_10->isFlat()){}
        else{arr_rulette[10] = 0;}
        if(ui->pushButton_11->isFlat()){}
        else{arr_rulette[11] = 0;}
        if(ui->pushButton_12->isFlat()){}
        else{arr_rulette[12] = 0;}
        if(ui->pushButton_13->isFlat()){}
        else{arr_rulette[13] = 0;}
        if(ui->pushButton_14->isFlat()){}
        else{arr_rulette[14] = 0;}
        if(ui->pushButton_15->isFlat()){}
        else{arr_rulette[15] = 0;}
        if(ui->pushButton_16->isFlat()){}
        else{arr_rulette[16] = 0;}
        if(ui->pushButton_17->isFlat()){}
        else{arr_rulette[17] = 0;}
        if(ui->pushButton_18->isFlat()){}
        else{arr_rulette[18] = 0;}

        ui->pushButton_1_18->setFlat(false);
    }
    else
    {
        if(ui->pushButton_1->isFlat()){}
        else{arr_rulette[1] = 1;}
        if(ui->pushButton_2->isFlat()){}
        else{arr_rulette[2] = 1;}
        if(ui->pushButton_3->isFlat()){}
        else{arr_rulette[3] = 1;}
        if(ui->pushButton_4->isFlat()){}
        else{arr_rulette[4] = 1;}
        if(ui->pushButton_5->isFlat()){}
        else{arr_rulette[5] = 1;}
        if(ui->pushButton_6->isFlat()){}
        else{arr_rulette[6] = 1;}
        if(ui->pushButton_7->isFlat()){}
        else{arr_rulette[7] = 1;}
        if(ui->pushButton_8->isFlat()){}
        else{arr_rulette[8] = 1;}
        if(ui->pushButton_9->isFlat()){}
        else{arr_rulette[9] = 1;}
        if(ui->pushButton_10->isFlat()){}
        else{arr_rulette[10] = 1;}
        if(ui->pushButton_11->isFlat()){}
        else{arr_rulette[11] = 1;}
        if(ui->pushButton_12->isFlat()){}
        else{arr_rulette[12] = 1;}
        if(ui->pushButton_13->isFlat()){}
        else{arr_rulette[13] = 1;}
        if(ui->pushButton_14->isFlat()){}
        else{arr_rulette[14] = 1;}
        if(ui->pushButton_15->isFlat()){}
        else{arr_rulette[15] = 1;}
        if(ui->pushButton_16->isFlat()){}
        else{arr_rulette[16] = 1;}
        if(ui->pushButton_17->isFlat()){}
        else{arr_rulette[17] = 1;}
        if(ui->pushButton_18->isFlat()){}
        else{arr_rulette[18] = 1;}

        ui->pushButton_1_18->setFlat(true);
    }
}

void MainWindow::on_pushButton_19_36_clicked()
{
    if(ui->pushButton_19_36->isFlat())
    {
        if(ui->pushButton_19->isFlat()){}
        else{arr_rulette[19] = 0;}
        if(ui->pushButton_20->isFlat()){}
        else{arr_rulette[20] = 0;}
        if(ui->pushButton_21->isFlat()){}
        else{arr_rulette[21] = 0;}
        if(ui->pushButton_22->isFlat()){}
        else{arr_rulette[22] = 0;}
        if(ui->pushButton_23->isFlat()){}
        else{arr_rulette[23] = 0;}
        if(ui->pushButton_24->isFlat()){}
        else{arr_rulette[24] = 0;}
        if(ui->pushButton_25->isFlat()){}
        else{arr_rulette[25] = 0;}
        if(ui->pushButton_26->isFlat()){}
        else{arr_rulette[26] = 0;}
        if(ui->pushButton_27->isFlat()){}
        else{arr_rulette[27] = 0;}
        if(ui->pushButton_28->isFlat()){}
        else{arr_rulette[28] = 0;}
        if(ui->pushButton_29->isFlat()){}
        else{arr_rulette[29] = 0;}
        if(ui->pushButton_30->isFlat()){}
        else{arr_rulette[30] = 0;}
        if(ui->pushButton_31->isFlat()){}
        else{arr_rulette[31] = 0;}
        if(ui->pushButton_32->isFlat()){}
        else{arr_rulette[32] = 0;}
        if(ui->pushButton_33->isFlat()){}
        else{arr_rulette[33] = 0;}
        if(ui->pushButton_34->isFlat()){}
        else{arr_rulette[34] = 0;}
        if(ui->pushButton_35->isFlat()){}
        else{arr_rulette[35] = 0;}
        if(ui->pushButton_36->isFlat()){}
        else{arr_rulette[36] = 0;}

        ui->pushButton_19_36->setFlat(false);
    }
    else
    {
        if(ui->pushButton_19->isFlat()){}
        else{arr_rulette[19] = 1;}
        if(ui->pushButton_20->isFlat()){}
        else{arr_rulette[20] = 1;}
        if(ui->pushButton_21->isFlat()){}
        else{arr_rulette[21] = 1;}
        if(ui->pushButton_22->isFlat()){}
        else{arr_rulette[22] = 1;}
        if(ui->pushButton_23->isFlat()){}
        else{arr_rulette[23] = 1;}
        if(ui->pushButton_24->isFlat()){}
        else{arr_rulette[24] = 1;}
        if(ui->pushButton_25->isFlat()){}
        else{arr_rulette[25] = 1;}
        if(ui->pushButton_26->isFlat()){}
        else{arr_rulette[26] = 1;}
        if(ui->pushButton_27->isFlat()){}
        else{arr_rulette[27] = 1;}
        if(ui->pushButton_28->isFlat()){}
        else{arr_rulette[28] = 1;}
        if(ui->pushButton_29->isFlat()){}
        else{arr_rulette[29] = 1;}
        if(ui->pushButton_30->isFlat()){}
        else{arr_rulette[30] = 1;}
        if(ui->pushButton_31->isFlat()){}
        else{arr_rulette[31] = 1;}
        if(ui->pushButton_32->isFlat()){}
        else{arr_rulette[32] = 1;}
        if(ui->pushButton_33->isFlat()){}
        else{arr_rulette[33] = 1;}
        if(ui->pushButton_34->isFlat()){}
        else{arr_rulette[34] = 1;}
        if(ui->pushButton_35->isFlat()){}
        else{arr_rulette[35] = 1;}
        if(ui->pushButton_36->isFlat()){}
        else{arr_rulette[36] = 1;}

        ui->pushButton_19_36->setFlat(true);
    }
}

void MainWindow::on_pushButton_1st_clicked()
{
    if(ui->pushButton_1st->isFlat())
    {
        if(ui->pushButton_1->isFlat()){}
        else{arr_rulette[1] = 0;}
        if(ui->pushButton_2->isFlat()){}
        else{arr_rulette[2] = 0;}
        if(ui->pushButton_3->isFlat()){}
        else{arr_rulette[3] = 0;}
        if(ui->pushButton_4->isFlat()){}
        else{arr_rulette[4] = 0;}
        if(ui->pushButton_5->isFlat()){}
        else{arr_rulette[5] = 0;}
        if(ui->pushButton_6->isFlat()){}
        else{arr_rulette[6] = 0;}
        if(ui->pushButton_7->isFlat()){}
        else{arr_rulette[7] = 0;}
        if(ui->pushButton_8->isFlat()){}
        else{arr_rulette[8] = 0;}
        if(ui->pushButton_9->isFlat()){}
        else{arr_rulette[9] = 0;}
        if(ui->pushButton_10->isFlat()){}
        else{arr_rulette[10] = 0;}
        if(ui->pushButton_11->isFlat()){}
        else{arr_rulette[11] = 0;}
        if(ui->pushButton_12->isFlat()){}
        else{arr_rulette[12] = 0;}

        ui->pushButton_1st->setFlat(false);
    }
    else
    {
        if(ui->pushButton_1->isFlat()){}
        else{arr_rulette[1] = 1;}
        if(ui->pushButton_2->isFlat()){}
        else{arr_rulette[2] = 1;}
        if(ui->pushButton_3->isFlat()){}
        else{arr_rulette[3] = 1;}
        if(ui->pushButton_4->isFlat()){}
        else{arr_rulette[4] = 1;}
        if(ui->pushButton_5->isFlat()){}
        else{arr_rulette[5] = 1;}
        if(ui->pushButton_6->isFlat()){}
        else{arr_rulette[6] = 1;}
        if(ui->pushButton_7->isFlat()){}
        else{arr_rulette[7] = 1;}
        if(ui->pushButton_8->isFlat()){}
        else{arr_rulette[8] = 1;}
        if(ui->pushButton_9->isFlat()){}
        else{arr_rulette[9] = 1;}
        if(ui->pushButton_10->isFlat()){}
        else{arr_rulette[10] = 1;}
        if(ui->pushButton_11->isFlat()){}
        else{arr_rulette[11] = 1;}
        if(ui->pushButton_12->isFlat()){}
        else{arr_rulette[12] = 1;}

        ui->pushButton_1st->setFlat(true);
    }
}
void MainWindow::on_pushButton_2nd_clicked()
{
    if(ui->pushButton_2nd->isFlat())
    {
        if(ui->pushButton_13->isFlat()){}
        else{arr_rulette[13] = 0;}
        if(ui->pushButton_14->isFlat()){}
        else{arr_rulette[14] = 0;}
        if(ui->pushButton_15->isFlat()){}
        else{arr_rulette[15] = 0;}
        if(ui->pushButton_16->isFlat()){}
        else{arr_rulette[16] = 0;}
        if(ui->pushButton_17->isFlat()){}
        else{arr_rulette[17] = 0;}
        if(ui->pushButton_18->isFlat()){}
        else{arr_rulette[18] = 0;}
        if(ui->pushButton_19->isFlat()){}
        else{arr_rulette[19] = 0;}
        if(ui->pushButton_20->isFlat()){}
        else{arr_rulette[20] = 0;}
        if(ui->pushButton_21->isFlat()){}
        else{arr_rulette[21] = 0;}
        if(ui->pushButton_22->isFlat()){}
        else{arr_rulette[22] = 0;}
        if(ui->pushButton_23->isFlat()){}
        else{arr_rulette[23] = 0;}
        if(ui->pushButton_24->isFlat()){}
        else{arr_rulette[24] = 0;}

        ui->pushButton_2nd->setFlat(false);
    }
    else
    {
        if(ui->pushButton_13->isFlat()){}
        else{arr_rulette[13] = 1;}
        if(ui->pushButton_14->isFlat()){}
        else{arr_rulette[14] = 1;}
        if(ui->pushButton_15->isFlat()){}
        else{arr_rulette[15] = 1;}
        if(ui->pushButton_16->isFlat()){}
        else{arr_rulette[16] = 1;}
        if(ui->pushButton_17->isFlat()){}
        else{arr_rulette[17] = 1;}
        if(ui->pushButton_18->isFlat()){}
        else{arr_rulette[18] = 1;}
        if(ui->pushButton_19->isFlat()){}
        else{arr_rulette[19] = 1;}
        if(ui->pushButton_20->isFlat()){}
        else{arr_rulette[20] = 1;}
        if(ui->pushButton_21->isFlat()){}
        else{arr_rulette[21] = 1;}
        if(ui->pushButton_22->isFlat()){}
        else{arr_rulette[22] = 1;}
        if(ui->pushButton_23->isFlat()){}
        else{arr_rulette[23] = 1;}
        if(ui->pushButton_24->isFlat()){}
        else{arr_rulette[24] = 1;}

        ui->pushButton_2nd->setFlat(true);
    }
}

void MainWindow::on_pushButton_3rd_clicked()
{
    if(ui->pushButton_3rd->isFlat())
    {
        if(ui->pushButton_25->isFlat()){}
        else{arr_rulette[25] = 0;}
        if(ui->pushButton_26->isFlat()){}
        else{arr_rulette[26] = 0;}
        if(ui->pushButton_27->isFlat()){}
        else{arr_rulette[27] = 0;}
        if(ui->pushButton_28->isFlat()){}
        else{arr_rulette[28] = 0;}
        if(ui->pushButton_29->isFlat()){}
        else{arr_rulette[29] = 0;}
        if(ui->pushButton_30->isFlat()){}
        else{arr_rulette[30] = 0;}
        if(ui->pushButton_31->isFlat()){}
        else{arr_rulette[31] = 0;}
        if(ui->pushButton_32->isFlat()){}
        else{arr_rulette[32] = 0;}
        if(ui->pushButton_33->isFlat()){}
        else{arr_rulette[33] = 0;}
        if(ui->pushButton_34->isFlat()){}
        else{arr_rulette[34] = 0;}
        if(ui->pushButton_35->isFlat()){}
        else{arr_rulette[35] = 0;}
        if(ui->pushButton_36->isFlat()){}
        else{arr_rulette[36] = 0;}

        ui->pushButton_3rd->setFlat(false);
    }
    else
    {
        if(ui->pushButton_25->isFlat()){}
        else{arr_rulette[25] = 1;}
        if(ui->pushButton_26->isFlat()){}
        else{arr_rulette[26] = 1;}
        if(ui->pushButton_27->isFlat()){}
        else{arr_rulette[27] = 1;}
        if(ui->pushButton_28->isFlat()){}
        else{arr_rulette[28] = 1;}
        if(ui->pushButton_29->isFlat()){}
        else{arr_rulette[29] = 1;}
        if(ui->pushButton_30->isFlat()){}
        else{arr_rulette[30] = 1;}
        if(ui->pushButton_31->isFlat()){}
        else{arr_rulette[31] = 1;}
        if(ui->pushButton_32->isFlat()){}
        else{arr_rulette[32] = 1;}
        if(ui->pushButton_33->isFlat()){}
        else{arr_rulette[33] = 1;}
        if(ui->pushButton_34->isFlat()){}
        else{arr_rulette[34] = 1;}
        if(ui->pushButton_35->isFlat()){}
        else{arr_rulette[35] = 1;}
        if(ui->pushButton_36->isFlat()){}
        else{arr_rulette[36] = 1;}

        ui->pushButton_3rd->setFlat(true);
    }
}

void MainWindow::on_pushButton_even_clicked()
{
    if(ui->pushButton_even->isFlat())
    {
        if(ui->pushButton_2->isFlat()){}
        else{arr_rulette[2] = 0;}
        if(ui->pushButton_4->isFlat()){}
        else{arr_rulette[4] = 0;}
        if(ui->pushButton_6->isFlat()){}
        else{arr_rulette[6] = 0;}
        if(ui->pushButton_8->isFlat()){}
        else{arr_rulette[8] = 0;}
        if(ui->pushButton_10->isFlat()){}
        else{arr_rulette[10] = 0;}
        if(ui->pushButton_12->isFlat()){}
        else{arr_rulette[12] = 0;}
        if(ui->pushButton_14->isFlat()){}
        else{arr_rulette[14] = 0;}
        if(ui->pushButton_16->isFlat()){}
        else{arr_rulette[16] = 0;}
        if(ui->pushButton_18->isFlat()){}
        else{arr_rulette[18] = 0;}
        if(ui->pushButton_20->isFlat()){}
        else{arr_rulette[20] = 0;}
        if(ui->pushButton_22->isFlat()){}
        else{arr_rulette[22] = 0;}
        if(ui->pushButton_24->isFlat()){}
        else{arr_rulette[24] = 0;}
        if(ui->pushButton_26->isFlat()){}
        else{arr_rulette[26] = 0;}
        if(ui->pushButton_28->isFlat()){}
        else{arr_rulette[28] = 0;}
        if(ui->pushButton_30->isFlat()){}
        else{arr_rulette[30] = 0;}
        if(ui->pushButton_32->isFlat()){}
        else{arr_rulette[32] = 0;}
        if(ui->pushButton_34->isFlat()){}
        else{arr_rulette[34] = 0;}
        if(ui->pushButton_36->isFlat()){}
        else{arr_rulette[36] = 0;}

        ui->pushButton_even->setFlat(false);
    }
    else
    {
        if(ui->pushButton_2->isFlat()){}
        else{arr_rulette[2] = 1;}
        if(ui->pushButton_4->isFlat()){}
        else{arr_rulette[4] = 1;}
        if(ui->pushButton_6->isFlat()){}
        else{arr_rulette[6] = 1;}
        if(ui->pushButton_8->isFlat()){}
        else{arr_rulette[8] = 1;}
        if(ui->pushButton_10->isFlat()){}
        else{arr_rulette[10] = 1;}
        if(ui->pushButton_12->isFlat()){}
        else{arr_rulette[12] = 1;}
        if(ui->pushButton_14->isFlat()){}
        else{arr_rulette[14] = 1;}
        if(ui->pushButton_16->isFlat()){}
        else{arr_rulette[16] = 1;}
        if(ui->pushButton_18->isFlat()){}
        else{arr_rulette[18] = 1;}
        if(ui->pushButton_20->isFlat()){}
        else{arr_rulette[20] = 1;}
        if(ui->pushButton_22->isFlat()){}
        else{arr_rulette[22] = 1;}
        if(ui->pushButton_24->isFlat()){}
        else{arr_rulette[24] = 1;}
        if(ui->pushButton_26->isFlat()){}
        else{arr_rulette[26] = 1;}
        if(ui->pushButton_28->isFlat()){}
        else{arr_rulette[28] = 1;}
        if(ui->pushButton_30->isFlat()){}
        else{arr_rulette[30] = 1;}
        if(ui->pushButton_32->isFlat()){}
        else{arr_rulette[32] = 1;}
        if(ui->pushButton_34->isFlat()){}
        else{arr_rulette[34] = 1;}
        if(ui->pushButton_36->isFlat()){}
        else{arr_rulette[36] = 1;}

        ui->pushButton_even->setFlat(true);
    }
}

void MainWindow::on_pushButton_odd_clicked()
{
    if(ui->pushButton_odd->isFlat())
    {
        if(ui->pushButton_1->isFlat()){}
        else{arr_rulette[1] = 0;}
        if(ui->pushButton_3->isFlat()){}
        else{arr_rulette[3] = 0;}
        if(ui->pushButton_5->isFlat()){}
        else{arr_rulette[5] = 0;}
        if(ui->pushButton_7->isFlat()){}
        else{arr_rulette[7] = 0;}
        if(ui->pushButton_9->isFlat()){}
        else{arr_rulette[9] = 0;}
        if(ui->pushButton_11->isFlat()){}
        else{arr_rulette[11] = 0;}
        if(ui->pushButton_13->isFlat()){}
        else{arr_rulette[13] = 0;}
        if(ui->pushButton_15->isFlat()){}
        else{arr_rulette[15] = 0;}
        if(ui->pushButton_17->isFlat()){}
        else{arr_rulette[17] = 0;}
        if(ui->pushButton_19->isFlat()){}
        else{arr_rulette[19] = 0;}
        if(ui->pushButton_21->isFlat()){}
        else{arr_rulette[21] = 0;}
        if(ui->pushButton_23->isFlat()){}
        else{arr_rulette[23] = 0;}
        if(ui->pushButton_25->isFlat()){}
        else{arr_rulette[25] = 0;}
        if(ui->pushButton_27->isFlat()){}
        else{arr_rulette[27] = 0;}
        if(ui->pushButton_29->isFlat()){}
        else{arr_rulette[29] = 0;}
        if(ui->pushButton_31->isFlat()){}
        else{arr_rulette[31] = 0;}
        if(ui->pushButton_33->isFlat()){}
        else{arr_rulette[33] = 0;}
        if(ui->pushButton_35->isFlat()){}
        else{arr_rulette[35] = 0;}

        ui->pushButton_odd->setFlat(false);
    }
    else
    {
        if(ui->pushButton_1->isFlat()){}
        else{arr_rulette[1] = 1;}
        if(ui->pushButton_3->isFlat()){}
        else{arr_rulette[3] = 1;}
        if(ui->pushButton_5->isFlat()){}
        else{arr_rulette[5] = 1;}
        if(ui->pushButton_7->isFlat()){}
        else{arr_rulette[7] = 1;}
        if(ui->pushButton_9->isFlat()){}
        else{arr_rulette[9] = 1;}
        if(ui->pushButton_11->isFlat()){}
        else{arr_rulette[11] = 1;}
        if(ui->pushButton_13->isFlat()){}
        else{arr_rulette[13] = 1;}
        if(ui->pushButton_15->isFlat()){}
        else{arr_rulette[15] = 1;}
        if(ui->pushButton_17->isFlat()){}
        else{arr_rulette[17] = 1;}
        if(ui->pushButton_19->isFlat()){}
        else{arr_rulette[19] = 1;}
        if(ui->pushButton_21->isFlat()){}
        else{arr_rulette[21] = 1;}
        if(ui->pushButton_23->isFlat()){}
        else{arr_rulette[23] = 1;}
        if(ui->pushButton_25->isFlat()){}
        else{arr_rulette[25] = 1;}
        if(ui->pushButton_27->isFlat()){}
        else{arr_rulette[27] = 1;}
        if(ui->pushButton_29->isFlat()){}
        else{arr_rulette[29] = 1;}
        if(ui->pushButton_31->isFlat()){}
        else{arr_rulette[31] = 1;}
        if(ui->pushButton_33->isFlat()){}
        else{arr_rulette[33] = 1;}
        if(ui->pushButton_35->isFlat()){}
        else{arr_rulette[35] = 1;}

        ui->pushButton_odd->setFlat(true);
    }
}

void MainWindow::on_pushButton_1_plus_2_clicked()
{
    if(ui->pushButton_1_plus_2->isFlat())
    {
        if(ui->pushButton_1->isFlat()){}
        else{arr_rulette[1] = 0;}
        if(ui->pushButton_2->isFlat()){}
        else{arr_rulette[2] = 0;}

        ui->pushButton_1_plus_2->setFlat(false);
    }
    else
    {
        if(ui->pushButton_1->isFlat()){}
        else{arr_rulette[1] = 1;}
        if(ui->pushButton_2->isFlat()){}
        else{arr_rulette[2] = 1;}

        ui->pushButton_1_plus_2->setFlat(true);
    }

}

void MainWindow::on_pushButton_2_plus_3_clicked()
{
    if(ui->pushButton_2_plus_3->isFlat())
    {
        if(ui->pushButton_2->isFlat()){}
        else{arr_rulette[2] = 0;}
        if(ui->pushButton_3->isFlat()){}
        else{arr_rulette[3] = 0;}

        ui->pushButton_2_plus_3->setFlat(false);
    }
    else
    {
        if(ui->pushButton_2->isFlat()){}
        else{arr_rulette[2] = 1;}
        if(ui->pushButton_3->isFlat()){}
        else{arr_rulette[3] = 1;}

        ui->pushButton_2_plus_3->setFlat(true);
    }
}

void MainWindow::on_pushButton_4_plus_5_clicked()
{
    if(ui->pushButton_4_plus_5->isFlat())
    {
        if(ui->pushButton_4->isFlat()){}
        else{arr_rulette[4] = 0;}
        if(ui->pushButton_5->isFlat()){}
        else{arr_rulette[5] = 0;}

        ui->pushButton_4_plus_5->setFlat(false);
    }
    else
    {
        if(ui->pushButton_4->isFlat()){}
        else{arr_rulette[4] = 1;}
        if(ui->pushButton_5->isFlat()){}
        else{arr_rulette[5] = 1;}

        ui->pushButton_4_plus_5->setFlat(true);
    }
}

void MainWindow::on_pushButton_5_plus_6_clicked()
{
    if(ui->pushButton_5_plus_6->isFlat())
    {
        if(ui->pushButton_5->isFlat()){}
        else{arr_rulette[5] = 0;}
        if(ui->pushButton_6->isFlat()){}
        else{arr_rulette[6] = 0;}

        ui->pushButton_5_plus_6->setFlat(false);
    }
    else
    {
        if(ui->pushButton_5->isFlat()){}
        else{arr_rulette[5] = 1;}
        if(ui->pushButton_6->isFlat()){}
        else{arr_rulette[6] = 1;}

        ui->pushButton_5_plus_6->setFlat(true);
    }
}

void MainWindow::on_pushButton_7_plus_8_clicked()
{
    if(ui->pushButton_7_plus_8->isFlat())
    {
        if(ui->pushButton_7->isFlat()){}
        else{arr_rulette[7] = 0;}
        if(ui->pushButton_8->isFlat()){}
        else{arr_rulette[8] = 0;}

        ui->pushButton_7_plus_8->setFlat(false);
    }
    else
    {
        if(ui->pushButton_7->isFlat()){}
        else{arr_rulette[7] = 1;}
        if(ui->pushButton_8->isFlat()){}
        else{arr_rulette[8] = 1;}

        ui->pushButton_7_plus_8->setFlat(true);
    }
}

void MainWindow::on_pushButton_8_plus_9_clicked()
{
    if(ui->pushButton_8_plus_9->isFlat())
    {
        if(ui->pushButton_8->isFlat()){}
        else{arr_rulette[8] = 0;}
        if(ui->pushButton_9->isFlat()){}
        else{arr_rulette[9] = 0;}

        ui->pushButton_8_plus_9->setFlat(false);
    }
    else
    {
        if(ui->pushButton_8->isFlat()){}
        else{arr_rulette[8] = 1;}
        if(ui->pushButton_9->isFlat()){}
        else{arr_rulette[9] = 1;}

        ui->pushButton_8_plus_9->setFlat(true);
    }
}

void MainWindow::on_pushButton_10_plus_11_clicked()
{
    if(ui->pushButton_10_plus_11->isFlat())
    {
        if(ui->pushButton_10->isFlat()){}
        else{arr_rulette[10] = 0;}
        if(ui->pushButton_11->isFlat()){}
        else{arr_rulette[11] = 0;}

        ui->pushButton_10_plus_11->setFlat(false);
    }
    else
    {
        if(ui->pushButton_10->isFlat()){}
        else{arr_rulette[10] = 1;}
        if(ui->pushButton_11->isFlat()){}
        else{arr_rulette[11] = 1;}

        ui->pushButton_10_plus_11->setFlat(true);
    }
}

void MainWindow::on_pushButton_11_plus_12_clicked()
{
    if(ui->pushButton_11_plus_12->isFlat())
    {
        if(ui->pushButton_11->isFlat()){}
        else{arr_rulette[11] = 0;}
        if(ui->pushButton_12->isFlat()){}
        else{arr_rulette[12] = 0;}

        ui->pushButton_11_plus_12->setFlat(false);
    }
    else
    {
        if(ui->pushButton_11->isFlat()){}
        else{arr_rulette[11] = 1;}
        if(ui->pushButton_12->isFlat()){}
        else{arr_rulette[12] = 1;}

        ui->pushButton_11_plus_12->setFlat(true);
    }
}

void MainWindow::on_pushButton_13_plus_14_clicked()
{
    if(ui->pushButton_13_plus_14->isFlat())
    {
        if(ui->pushButton_13->isFlat()){}
        else{arr_rulette[13] = 0;}
        if(ui->pushButton_14->isFlat()){}
        else{arr_rulette[14] = 0;}

        ui->pushButton_13_plus_14->setFlat(false);
    }
    else
    {
        if(ui->pushButton_13->isFlat()){}
        else{arr_rulette[13] = 1;}
        if(ui->pushButton_14->isFlat()){}
        else{arr_rulette[14] = 1;}

        ui->pushButton_13_plus_14->setFlat(true);
    }
}

void MainWindow::on_pushButton_14_plus_15_clicked()
{
    if(ui->pushButton_14_plus_15->isFlat())
    {
        if(ui->pushButton_14->isFlat()){}
        else{arr_rulette[14] = 0;}
        if(ui->pushButton_15->isFlat()){}
        else{arr_rulette[15] = 0;}

        ui->pushButton_14_plus_15->setFlat(false);
    }
    else
    {
        if(ui->pushButton_14->isFlat()){}
        else{arr_rulette[14] = 1;}
        if(ui->pushButton_15->isFlat()){}
        else{arr_rulette[15] = 1;}

        ui->pushButton_14_plus_15->setFlat(true);
    }
}

void MainWindow::on_pushButton_16_plus_17_clicked()
{
    if(ui->pushButton_16_plus_17->isFlat())
    {
        if(ui->pushButton_16->isFlat()){}
        else{arr_rulette[16] = 0;}
        if(ui->pushButton_17->isFlat()){}
        else{arr_rulette[17] = 0;}

        ui->pushButton_16_plus_17->setFlat(false);
    }
    else
    {
        if(ui->pushButton_16->isFlat()){}
        else{arr_rulette[16] = 1;}
        if(ui->pushButton_17->isFlat()){}
        else{arr_rulette[17] = 1;}

        ui->pushButton_16_plus_17->setFlat(true);
    }
}

void MainWindow::on_pushButton_17_plus_18_clicked()
{
    if(ui->pushButton_17_plus_18->isFlat())
    {
        if(ui->pushButton_17->isFlat()){}
        else{arr_rulette[17] = 0;}
        if(ui->pushButton_18->isFlat()){}
        else{arr_rulette[18] = 0;}

        ui->pushButton_17_plus_18->setFlat(false);
    }
    else
    {
        if(ui->pushButton_17->isFlat()){}
        else{arr_rulette[17] = 1;}
        if(ui->pushButton_18->isFlat()){}
        else{arr_rulette[18] = 1;}

        ui->pushButton_17_plus_18->setFlat(true);
    }
}

void MainWindow::on_pushButton_19_plus_20_clicked()
{
    if(ui->pushButton_19_plus_20->isFlat())
    {
        if(ui->pushButton_19->isFlat()){}
        else{arr_rulette[19] = 0;}
        if(ui->pushButton_20->isFlat()){}
        else{arr_rulette[20] = 0;}

        ui->pushButton_19_plus_20->setFlat(false);
    }
    else
    {
        if(ui->pushButton_19->isFlat()){}
        else{arr_rulette[19] = 1;}
        if(ui->pushButton_20->isFlat()){}
        else{arr_rulette[20] = 1;}

        ui->pushButton_19_plus_20->setFlat(true);
    }
}

void MainWindow::on_pushButton_20_plus_21_clicked()
{
    if(ui->pushButton_20_plus_21->isFlat())
    {
        if(ui->pushButton_20->isFlat()){}
        else{arr_rulette[20] = 0;}
        if(ui->pushButton_21->isFlat()){}
        else{arr_rulette[21] = 0;}

        ui->pushButton_20_plus_21->setFlat(false);
    }
    else
    {
        if(ui->pushButton_20->isFlat()){}
        else{arr_rulette[20] = 1;}
        if(ui->pushButton_21->isFlat()){}
        else{arr_rulette[21] = 1;}

        ui->pushButton_20_plus_21->setFlat(true);
    }
}

void MainWindow::on_pushButton_22_plus_23_clicked()
{
    if(ui->pushButton_22_plus_23->isFlat())
    {
        if(ui->pushButton_22->isFlat()){}
        else{arr_rulette[22] = 0;}
        if(ui->pushButton_23->isFlat()){}
        else{arr_rulette[23] = 0;}

        ui->pushButton_22_plus_23->setFlat(false);
    }
    else
    {
        if(ui->pushButton_22->isFlat()){}
        else{arr_rulette[22] = 1;}
        if(ui->pushButton_23->isFlat()){}
        else{arr_rulette[23] = 1;}

        ui->pushButton_22_plus_23->setFlat(true);
    }
}

void MainWindow::on_pushButton_23_plus_24_clicked()
{
    if(ui->pushButton_23_plus_24->isFlat())
    {
        if(ui->pushButton_23->isFlat()){}
        else{arr_rulette[23] = 0;}
        if(ui->pushButton_24->isFlat()){}
        else{arr_rulette[24] = 0;}

        ui->pushButton_23_plus_24->setFlat(false);
    }
    else
    {
        if(ui->pushButton_23->isFlat()){}
        else{arr_rulette[23] = 1;}
        if(ui->pushButton_24->isFlat()){}
        else{arr_rulette[24] = 1;}

        ui->pushButton_23_plus_24->setFlat(true);
    }
}

void MainWindow::on_pushButton_25_plus_26_clicked()
{
    if(ui->pushButton_25_plus_26->isFlat())
    {
        if(ui->pushButton_25->isFlat()){}
        else{arr_rulette[25] = 0;}
        if(ui->pushButton_26->isFlat()){}
        else{arr_rulette[26] = 0;}

        ui->pushButton_25_plus_26->setFlat(false);
    }
    else
    {
        if(ui->pushButton_25->isFlat()){}
        else{arr_rulette[25] = 1;}
        if(ui->pushButton_26->isFlat()){}
        else{arr_rulette[26] = 1;}

        ui->pushButton_25_plus_26->setFlat(true);
    }
}

void MainWindow::on_pushButton_26_plus_27_clicked()
{
    if(ui->pushButton_26_plus_27->isFlat())
    {
        if(ui->pushButton_26->isFlat()){}
        else{arr_rulette[26] = 0;}
        if(ui->pushButton_27->isFlat()){}
        else{arr_rulette[27] = 0;}

        ui->pushButton_26_plus_27->setFlat(false);
    }
    else
    {
        if(ui->pushButton_26->isFlat()){}
        else{arr_rulette[26] = 1;}
        if(ui->pushButton_27->isFlat()){}
        else{arr_rulette[27] = 1;}

        ui->pushButton_26_plus_27->setFlat(true);
    }
}

void MainWindow::on_pushButton_28_plus_29_clicked()
{
    if(ui->pushButton_28_plus_29->isFlat())
    {
        if(ui->pushButton_28->isFlat()){}
        else{arr_rulette[28] = 0;}
        if(ui->pushButton_29->isFlat()){}
        else{arr_rulette[29] = 0;}

        ui->pushButton_28_plus_29->setFlat(false);
    }
    else
    {
        if(ui->pushButton_28->isFlat()){}
        else{arr_rulette[28] = 1;}
        if(ui->pushButton_29->isFlat()){}
        else{arr_rulette[29] = 1;}

        ui->pushButton_28_plus_29->setFlat(true);
    }
}

void MainWindow::on_pushButton_29_plus_30_clicked()
{
    if(ui->pushButton_29_plus_30->isFlat())
    {
        if(ui->pushButton_29->isFlat()){}
        else{arr_rulette[29] = 0;}
        if(ui->pushButton_30->isFlat()){}
        else{arr_rulette[30] = 0;}

        ui->pushButton_29_plus_30->setFlat(false);
    }
    else
    {
        if(ui->pushButton_29->isFlat()){}
        else{arr_rulette[29] = 1;}
        if(ui->pushButton_30->isFlat()){}
        else{arr_rulette[30] = 1;}

        ui->pushButton_29_plus_30->setFlat(true);
    }
}

void MainWindow::on_pushButton_31_plus_32_clicked()
{
    if(ui->pushButton_31_plus_32->isFlat())
    {
        if(ui->pushButton_31->isFlat()){}
        else{arr_rulette[31] = 0;}
        if(ui->pushButton_32->isFlat()){}
        else{arr_rulette[32] = 0;}

        ui->pushButton_31_plus_32->setFlat(false);
    }
    else
    {
        if(ui->pushButton_31->isFlat()){}
        else{arr_rulette[31] = 1;}
        if(ui->pushButton_32->isFlat()){}
        else{arr_rulette[32] = 1;}

        ui->pushButton_31_plus_32->setFlat(true);
    }
}

void MainWindow::on_pushButton_32_plus_33_clicked()
{
    if(ui->pushButton_32_plus_33->isFlat())
    {
        if(ui->pushButton_32->isFlat()){}
        else{arr_rulette[32] = 0;}
        if(ui->pushButton_33->isFlat()){}
        else{arr_rulette[33] = 0;}

        ui->pushButton_32_plus_33->setFlat(false);
    }
    else
    {
        if(ui->pushButton_32->isFlat()){}
        else{arr_rulette[32] = 1;}
        if(ui->pushButton_33->isFlat()){}
        else{arr_rulette[33] = 1;}

        ui->pushButton_32_plus_33->setFlat(true);
    }
}

void MainWindow::on_pushButton_34_plus_35_clicked()
{
    if(ui->pushButton_34_plus_35->isFlat())
    {
        if(ui->pushButton_34->isFlat()){}
        else{arr_rulette[34] = 0;}
        if(ui->pushButton_35->isFlat()){}
        else{arr_rulette[35] = 0;}

        ui->pushButton_34_plus_35->setFlat(false);
    }
    else
    {
        if(ui->pushButton_34->isFlat()){}
        else{arr_rulette[34] = 1;}
        if(ui->pushButton_35->isFlat()){}
        else{arr_rulette[35] = 1;}

        ui->pushButton_34_plus_35->setFlat(true);
    }
}

void MainWindow::on_pushButton_35_plus_36_clicked()
{
    if(ui->pushButton_35_plus_36->isFlat())
    {
        if(ui->pushButton_35->isFlat()){}
        else{arr_rulette[35] = 0;}
        if(ui->pushButton_36->isFlat()){}
        else{arr_rulette[36] = 0;}

        ui->pushButton_35_plus_36->setFlat(false);
    }
    else
    {
        if(ui->pushButton_35->isFlat()){}
        else{arr_rulette[35] = 1;}
        if(ui->pushButton_36->isFlat()){}
        else{arr_rulette[36] = 1;}

        ui->pushButton_35_plus_36->setFlat(true);
    }
}

void MainWindow::on_pushButton_1_plus_4_clicked()
{
    if(ui->pushButton_1_plus_4->isFlat())
    {
        if(ui->pushButton_1->isFlat()){}
        else{arr_rulette[1] = 0;}
        if(ui->pushButton_4->isFlat()){}
        else{arr_rulette[4] = 0;}

        ui->pushButton_1_plus_4->setFlat(false);
    }
    else
    {
        if(ui->pushButton_1->isFlat()){}
        else{arr_rulette[1] = 1;}
        if(ui->pushButton_4->isFlat()){}
        else{arr_rulette[4] = 1;}

        ui->pushButton_1_plus_4->setFlat(true);
    }
}

void MainWindow::on_pushButton_4_plus_7_clicked()
{
    if(ui->pushButton_4_plus_7->isFlat())
    {
        if(ui->pushButton_4->isFlat()){}
        else{arr_rulette[4] = 0;}
        if(ui->pushButton_7->isFlat()){}
        else{arr_rulette[7] = 0;}

        ui->pushButton_4_plus_7->setFlat(false);
    }
    else
    {
        if(ui->pushButton_4->isFlat()){}
        else{arr_rulette[4] = 1;}
        if(ui->pushButton_7->isFlat()){}
        else{arr_rulette[7] = 1;}

        ui->pushButton_4_plus_7->setFlat(true);
    }
}

void MainWindow::on_pushButton_7_plus_10_clicked()
{
    if(ui->pushButton_7_plus_10->isFlat())
    {
        if(ui->pushButton_7->isFlat()){}
        else{arr_rulette[7] = 0;}
        if(ui->pushButton_10->isFlat()){}
        else{arr_rulette[10] = 0;}

        ui->pushButton_7_plus_10->setFlat(false);
    }
    else
    {
        if(ui->pushButton_7->isFlat()){}
        else{arr_rulette[7] = 1;}
        if(ui->pushButton_10->isFlat()){}
        else{arr_rulette[10] = 1;}

        ui->pushButton_7_plus_10->setFlat(true);
    }
}

void MainWindow::on_pushButton_10_plus_13_clicked()
{
    if(ui->pushButton_10_plus_13->isFlat())
    {
        if(ui->pushButton_10->isFlat()){}
        else{arr_rulette[10] = 0;}
        if(ui->pushButton_13->isFlat()){}
        else{arr_rulette[13] = 0;}

        ui->pushButton_10_plus_13->setFlat(false);
    }
    else
    {
        if(ui->pushButton_10->isFlat()){}
        else{arr_rulette[10] = 1;}
        if(ui->pushButton_13->isFlat()){}
        else{arr_rulette[13] = 1;}

        ui->pushButton_10_plus_13->setFlat(true);
    }
}

void MainWindow::on_pushButton_13_plus_16_clicked()
{
    if(ui->pushButton_13_plus_16->isFlat())
    {
        if(ui->pushButton_13->isFlat()){}
        else{arr_rulette[13] = 0;}
        if(ui->pushButton_16->isFlat()){}
        else{arr_rulette[16] = 0;}

        ui->pushButton_13_plus_16->setFlat(false);
    }
    else
    {
        if(ui->pushButton_13->isFlat()){}
        else{arr_rulette[13] = 1;}
        if(ui->pushButton_16->isFlat()){}
        else{arr_rulette[16] = 1;}

        ui->pushButton_13_plus_16->setFlat(true);
    }
}

void MainWindow::on_pushButton_16_plus_19_clicked()
{
    if(ui->pushButton_16_plus_19->isFlat())
    {
        if(ui->pushButton_16->isFlat()){}
        else{arr_rulette[16] = 0;}
        if(ui->pushButton_19->isFlat()){}
        else{arr_rulette[19] = 0;}

        ui->pushButton_16_plus_19->setFlat(false);
    }
    else
    {
        if(ui->pushButton_16->isFlat()){}
        else{arr_rulette[16] = 1;}
        if(ui->pushButton_19->isFlat()){}
        else{arr_rulette[19] = 1;}

        ui->pushButton_16_plus_19->setFlat(true);
    }
}

void MainWindow::on_pushButton_19_plus_22_clicked()
{
    if(ui->pushButton_19_plus_22->isFlat())
    {
        if(ui->pushButton_19->isFlat()){}
        else{arr_rulette[19] = 0;}
        if(ui->pushButton_22->isFlat()){}
        else{arr_rulette[22] = 0;}

        ui->pushButton_19_plus_22->setFlat(false);
    }
    else
    {
        if(ui->pushButton_19->isFlat()){}
        else{arr_rulette[19] = 1;}
        if(ui->pushButton_22->isFlat()){}
        else{arr_rulette[22] = 1;}

        ui->pushButton_19_plus_22->setFlat(true);
    }
}

void MainWindow::on_pushButton_22_Plus_25_clicked()
{
    if(ui->pushButton_22_Plus_25->isFlat())
    {
        if(ui->pushButton_22->isFlat()){}
        else{arr_rulette[22] = 0;}
        if(ui->pushButton_25->isFlat()){}
        else{arr_rulette[25] = 0;}

        ui->pushButton_22_Plus_25->setFlat(false);
    }
    else
    {
        if(ui->pushButton_22->isFlat()){}
        else{arr_rulette[22] = 1;}
        if(ui->pushButton_25->isFlat()){}
        else{arr_rulette[25] = 1;}

        ui->pushButton_22_Plus_25->setFlat(true);
    }
}

void MainWindow::on_pushButton_25_plus_28_clicked()
{
    if(ui->pushButton_25_plus_28->isFlat())
    {
        if(ui->pushButton_25->isFlat()){}
        else{arr_rulette[25] = 0;}
        if(ui->pushButton_28->isFlat()){}
        else{arr_rulette[28] = 0;}

        ui->pushButton_25_plus_28->setFlat(false);
    }
    else
    {
        if(ui->pushButton_25->isFlat()){}
        else{arr_rulette[25] = 1;}
        if(ui->pushButton_28->isFlat()){}
        else{arr_rulette[28] = 1;}

        ui->pushButton_25_plus_28->setFlat(true);
    }
}

void MainWindow::on_pushButton_28_Plus_31_clicked()
{
    if(ui->pushButton_28_Plus_31->isFlat())
    {
        if(ui->pushButton_28->isFlat()){}
        else{arr_rulette[28] = 0;}
        if(ui->pushButton_31->isFlat()){}
        else{arr_rulette[31] = 0;}

        ui->pushButton_28_Plus_31->setFlat(false);
    }
    else
    {
        if(ui->pushButton_28->isFlat()){}
        else{arr_rulette[28] = 1;}
        if(ui->pushButton_31->isFlat()){}
        else{arr_rulette[31] = 1;}

        ui->pushButton_28_Plus_31->setFlat(true);
    }
}

void MainWindow::on_pushButton_31_plus_34_clicked()
{
    if(ui->pushButton_31_plus_34->isFlat())
    {
        if(ui->pushButton_31->isFlat()){}
        else{arr_rulette[31] = 0;}
        if(ui->pushButton_34->isFlat()){}
        else{arr_rulette[34] = 0;}

        ui->pushButton_31_plus_34->setFlat(false);
    }
    else
    {
        if(ui->pushButton_31->isFlat()){}
        else{arr_rulette[31] = 1;}
        if(ui->pushButton_34->isFlat()){}
        else{arr_rulette[34] = 1;}

        ui->pushButton_31_plus_34->setFlat(true);
    }
}

void MainWindow::on_pushButton_2_plus_5_clicked()
{
    if(ui->pushButton_2_plus_5->isFlat())
    {
        if(ui->pushButton_2->isFlat()){}
        else{arr_rulette[2] = 0;}
        if(ui->pushButton_5->isFlat()){}
        else{arr_rulette[5] = 0;}

        ui->pushButton_2_plus_5->setFlat(false);
    }
    else
    {
        if(ui->pushButton_2->isFlat()){}
        else{arr_rulette[2] = 1;}
        if(ui->pushButton_5->isFlat()){}
        else{arr_rulette[5] = 1;}

        ui->pushButton_2_plus_5->setFlat(true);
    }
}

void MainWindow::on_pushButton_5_plus_8_clicked()
{
    if(ui->pushButton_5_plus_8->isFlat())
    {
        if(ui->pushButton_5->isFlat()){}
        else{arr_rulette[5] = 0;}
        if(ui->pushButton_8->isFlat()){}
        else{arr_rulette[8] = 0;}

        ui->pushButton_5_plus_8->setFlat(false);
    }
    else
    {
        if(ui->pushButton_5->isFlat()){}
        else{arr_rulette[5] = 1;}
        if(ui->pushButton_8->isFlat()){}
        else{arr_rulette[8] = 1;}

        ui->pushButton_5_plus_8->setFlat(true);
    }
}

void MainWindow::on_pushButton_8_plus_11_clicked()
{
    if(ui->pushButton_8_plus_11->isFlat())
    {
        if(ui->pushButton_8->isFlat()){}
        else{arr_rulette[8] = 0;}
        if(ui->pushButton_11->isFlat()){}
        else{arr_rulette[11] = 0;}

        ui->pushButton_8_plus_11->setFlat(false);
    }
    else
    {
        if(ui->pushButton_8->isFlat()){}
        else{arr_rulette[8] = 1;}
        if(ui->pushButton_11->isFlat()){}
        else{arr_rulette[11] = 1;}

        ui->pushButton_8_plus_11->setFlat(true);
    }
}

void MainWindow::on_pushButton_11_plus_14_clicked()
{
    if(ui->pushButton_11_plus_14->isFlat())
    {
        if(ui->pushButton_11->isFlat()){}
        else{arr_rulette[11] = 0;}
        if(ui->pushButton_14->isFlat()){}
        else{arr_rulette[14] = 0;}

        ui->pushButton_11_plus_14->setFlat(false);
    }
    else
    {
        if(ui->pushButton_11->isFlat()){}
        else{arr_rulette[14] = 1;}
        if(ui->pushButton_14->isFlat()){}
        else{arr_rulette[14] = 1;}

        ui->pushButton_11_plus_14->setFlat(true);
    }
}

void MainWindow::on_pushButton_14_plus_17_clicked()
{
    if(ui->pushButton_14_plus_17->isFlat())
    {
        if(ui->pushButton_14->isFlat()){}
        else{arr_rulette[14] = 0;}
        if(ui->pushButton_17->isFlat()){}
        else{arr_rulette[17] = 0;}

        ui->pushButton_14_plus_17->setFlat(false);
    }
    else
    {
        if(ui->pushButton_14->isFlat()){}
        else{arr_rulette[14] = 1;}
        if(ui->pushButton_17->isFlat()){}
        else{arr_rulette[17] = 1;}

        ui->pushButton_14_plus_17->setFlat(true);
    }
}

void MainWindow::on_pushButton_17_plus_20_clicked()
{
    if(ui->pushButton_17_plus_20->isFlat())
    {
        if(ui->pushButton_17->isFlat()){}
        else{arr_rulette[17] = 0;}
        if(ui->pushButton_20->isFlat()){}
        else{arr_rulette[20] = 0;}

        ui->pushButton_17_plus_20->setFlat(false);
    }
    else
    {
        if(ui->pushButton_17->isFlat()){}
        else{arr_rulette[17] = 1;}
        if(ui->pushButton_20->isFlat()){}
        else{arr_rulette[20] = 1;}

        ui->pushButton_17_plus_20->setFlat(true);
    }
}

void MainWindow::on_pushButton_20_plus_23_clicked()
{
    if(ui->pushButton_20_plus_23->isFlat())
    {
        if(ui->pushButton_20->isFlat()){}
        else{arr_rulette[20] = 0;}
        if(ui->pushButton_23->isFlat()){}
        else{arr_rulette[23] = 0;}

        ui->pushButton_20_plus_23->setFlat(false);
    }
    else
    {
        if(ui->pushButton_20->isFlat()){}
        else{arr_rulette[20] = 1;}
        if(ui->pushButton_23->isFlat()){}
        else{arr_rulette[23] = 1;}

        ui->pushButton_20_plus_23->setFlat(true);
    }
}

void MainWindow::on_pushButton_23_plus_26_clicked()
{
    if(ui->pushButton_23_plus_26->isFlat())
    {
        if(ui->pushButton_23->isFlat()){}
        else{arr_rulette[23] = 0;}
        if(ui->pushButton_26->isFlat()){}
        else{arr_rulette[26] = 0;}

        ui->pushButton_23_plus_26->setFlat(false);
    }
    else
    {
        if(ui->pushButton_23->isFlat()){}
        else{arr_rulette[23] = 1;}
        if(ui->pushButton_26->isFlat()){}
        else{arr_rulette[26] = 1;}

        ui->pushButton_23_plus_26->setFlat(true);
    }
}

void MainWindow::on_pushButton_26_plus_29_clicked()
{
    if(ui->pushButton_26_plus_29->isFlat())
    {
        if(ui->pushButton_26->isFlat()){}
        else{arr_rulette[26] = 0;}
        if(ui->pushButton_29->isFlat()){}
        else{arr_rulette[29] = 0;}

        ui->pushButton_26_plus_29->setFlat(false);
    }
    else
    {
        if(ui->pushButton_26->isFlat()){}
        else{arr_rulette[26] = 1;}
        if(ui->pushButton_29->isFlat()){}
        else{arr_rulette[29] = 1;}

        ui->pushButton_26_plus_29->setFlat(true);
    }
}

void MainWindow::on_pushButton_29_plus_32_clicked()
{
    if(ui->pushButton_29_plus_32->isFlat())
    {
        if(ui->pushButton_29->isFlat()){}
        else{arr_rulette[29] = 0;}
        if(ui->pushButton_32->isFlat()){}
        else{arr_rulette[32] = 0;}

        ui->pushButton_29_plus_32->setFlat(false);
    }
    else
    {
        if(ui->pushButton_29->isFlat()){}
        else{arr_rulette[29] = 1;}
        if(ui->pushButton_32->isFlat()){}
        else{arr_rulette[32] = 1;}

        ui->pushButton_29_plus_32->setFlat(true);
    }
}

void MainWindow::on_pushButton_32_plus_35_clicked()
{
    if(ui->pushButton_32_plus_35->isFlat())
    {
        if(ui->pushButton_32->isFlat()){}
        else{arr_rulette[32] = 0;}
        if(ui->pushButton_35->isFlat()){}
        else{arr_rulette[35] = 0;}

        ui->pushButton_32_plus_35->setFlat(false);
    }
    else
    {
        if(ui->pushButton_32->isFlat()){}
        else{arr_rulette[32] = 1;}
        if(ui->pushButton_35->isFlat()){}
        else{arr_rulette[35] = 1;}

        ui->pushButton_32_plus_35->setFlat(true);
    }
}

void MainWindow::on_pushButton_3_plus_6_clicked()
{
    if(ui->pushButton_3_plus_6->isFlat())
    {
        if(ui->pushButton_3->isFlat()){}
        else{arr_rulette[3] = 0;}
        if(ui->pushButton_6->isFlat()){}
        else{arr_rulette[6] = 0;}

        ui->pushButton_3_plus_6->setFlat(false);
    }
    else
    {
        if(ui->pushButton_3->isFlat()){}
        else{arr_rulette[3] = 1;}
        if(ui->pushButton_6->isFlat()){}
        else{arr_rulette[6] = 1;}

        ui->pushButton_3_plus_6->setFlat(true);
    }
}

void MainWindow::on_pushButton_6_plus_9_clicked()
{
    if(ui->pushButton_6_plus_9->isFlat())
    {
        if(ui->pushButton_6->isFlat()){}
        else{arr_rulette[6] = 0;}
        if(ui->pushButton_9->isFlat()){}
        else{arr_rulette[9] = 0;}

        ui->pushButton_6_plus_9->setFlat(false);
    }
    else
    {
        if(ui->pushButton_6->isFlat()){}
        else{arr_rulette[6] = 1;}
        if(ui->pushButton_9->isFlat()){}
        else{arr_rulette[9] = 1;}

        ui->pushButton_6_plus_9->setFlat(true);
    }
}

void MainWindow::on_pushButton_9_plus_12_clicked()
{
    if(ui->pushButton_9_plus_12->isFlat())
    {
        if(ui->pushButton_9->isFlat()){}
        else{arr_rulette[9] = 0;}
        if(ui->pushButton_12->isFlat()){}
        else{arr_rulette[12] = 0;}

        ui->pushButton_9_plus_12->setFlat(false);
    }
    else
    {
        if(ui->pushButton_9->isFlat()){}
        else{arr_rulette[9] = 1;}
        if(ui->pushButton_12->isFlat()){}
        else{arr_rulette[12] = 1;}

        ui->pushButton_9_plus_12->setFlat(true);
    }
}

void MainWindow::on_pushButton_12_plus_15_clicked()
{
    if(ui->pushButton_12_plus_15->isFlat())
    {
        if(ui->pushButton_12->isFlat()){}
        else{arr_rulette[12] = 0;}
        if(ui->pushButton_15->isFlat()){}
        else{arr_rulette[15] = 0;}

        ui->pushButton_12_plus_15->setFlat(false);
    }
    else
    {
        if(ui->pushButton_12->isFlat()){}
        else{arr_rulette[12] = 1;}
        if(ui->pushButton_15->isFlat()){}
        else{arr_rulette[15] = 1;}

        ui->pushButton_12_plus_15->setFlat(true);
    }
}

void MainWindow::on_pushButton_15_plus_18_clicked()
{
    if(ui->pushButton_15_plus_18->isFlat())
    {
        if(ui->pushButton_15->isFlat()){}
        else{arr_rulette[15] = 0;}
        if(ui->pushButton_18->isFlat()){}
        else{arr_rulette[18] = 0;}

        ui->pushButton_15_plus_18->setFlat(false);
    }
    else
    {
        if(ui->pushButton_15->isFlat()){}
        else{arr_rulette[15] = 1;}
        if(ui->pushButton_18->isFlat()){}
        else{arr_rulette[18] = 1;}

        ui->pushButton_15_plus_18->setFlat(true);
    }
}

void MainWindow::on_pushButton_18_plus_21_clicked()
{
    if(ui->pushButton_18_plus_21->isFlat())
    {
        if(ui->pushButton_18->isFlat()){}
        else{arr_rulette[18] = 0;}
        if(ui->pushButton_21->isFlat()){}
        else{arr_rulette[21] = 0;}

        ui->pushButton_18_plus_21->setFlat(false);
    }
    else
    {
        if(ui->pushButton_18->isFlat()){}
        else{arr_rulette[18] = 1;}
        if(ui->pushButton_21->isFlat()){}
        else{arr_rulette[21] = 1;}

        ui->pushButton_18_plus_21->setFlat(true);
    }
}

void MainWindow::on_pushButton_21_plus_24_clicked()
{
    if(ui->pushButton_21_plus_24->isFlat())
    {
        if(ui->pushButton_21->isFlat()){}
        else{arr_rulette[21] = 0;}
        if(ui->pushButton_24->isFlat()){}
        else{arr_rulette[24] = 0;}

        ui->pushButton_21_plus_24->setFlat(false);
    }
    else
    {
        if(ui->pushButton_21->isFlat()){}
        else{arr_rulette[21] = 1;}
        if(ui->pushButton_24->isFlat()){}
        else{arr_rulette[24] = 1;}

        ui->pushButton_21_plus_24->setFlat(true);
    }
}

void MainWindow::on_pushButton_24_plus_27_clicked()
{
    if(ui->pushButton_24_plus_27->isFlat())
    {
        if(ui->pushButton_24->isFlat()){}
        else{arr_rulette[24] = 0;}
        if(ui->pushButton_27->isFlat()){}
        else{arr_rulette[27] = 0;}

        ui->pushButton_24_plus_27->setFlat(false);
    }
    else
    {
        if(ui->pushButton_24->isFlat()){}
        else{arr_rulette[24] = 1;}
        if(ui->pushButton_27->isFlat()){}
        else{arr_rulette[27] = 1;}

        ui->pushButton_24_plus_27->setFlat(true);
    }
}

void MainWindow::on_pushButton_27_plus_30_clicked()
{
    if(ui->pushButton_27_plus_30->isFlat())
    {
        if(ui->pushButton_27->isFlat()){}
        else{arr_rulette[27] = 0;}
        if(ui->pushButton_30->isFlat()){}
        else{arr_rulette[30] = 0;}

        ui->pushButton_27_plus_30->setFlat(false);
    }
    else
    {
        if(ui->pushButton_27->isFlat()){}
        else{arr_rulette[27] = 1;}
        if(ui->pushButton_30->isFlat()){}
        else{arr_rulette[30] = 1;}

        ui->pushButton_27_plus_30->setFlat(true);
    }
}

void MainWindow::on_pushButton_30_plus_33_clicked()
{
    if(ui->pushButton_30_plus_33->isFlat())
    {
        if(ui->pushButton_30->isFlat()){}
        else{arr_rulette[30] = 0;}
        if(ui->pushButton_33->isFlat()){}
        else{arr_rulette[33] = 0;}

        ui->pushButton_30_plus_33->setFlat(false);
    }
    else
    {
        if(ui->pushButton_30->isFlat()){}
        else{arr_rulette[30] = 1;}
        if(ui->pushButton_33->isFlat()){}
        else{arr_rulette[33] = 1;}

        ui->pushButton_30_plus_33->setFlat(true);
    }
}

void MainWindow::on_pushButton_33_plus_36_clicked()
{
    if(ui->pushButton_33_plus_36->isFlat())
    {
        if(ui->pushButton_33->isFlat()){}
        else{arr_rulette[33] = 0;}
        if(ui->pushButton_36->isFlat()){}
        else{arr_rulette[36] = 0;}

        ui->pushButton_33_plus_36->setFlat(false);
    }
    else
    {
        if(ui->pushButton_33->isFlat()){}
        else{arr_rulette[33] = 1;}
        if(ui->pushButton_36->isFlat()){}
        else{arr_rulette[36] = 1;}

        ui->pushButton_33_plus_36->setFlat(true);
    }
}

void MainWindow::on_pushButton_1_plus_4_2_5_clicked()
{
    if(ui->pushButton_1_plus_4_2_5->isFlat())
    {
        if(ui->pushButton_1->isFlat()){}
        else{arr_rulette[1] = 0;}
        if(ui->pushButton_2->isFlat()){}
        else{arr_rulette[2] = 0;}
        if(ui->pushButton_4->isFlat()){}
        else{arr_rulette[4] = 0;}
        if(ui->pushButton_6->isFlat()){}
        else{arr_rulette[6] = 0;}

        ui->pushButton_1_plus_4_2_5->setFlat(false);
    }
    else
    {
        if(ui->pushButton_1->isFlat()){}
        else{arr_rulette[1] = 1;}
        if(ui->pushButton_2->isFlat()){}
        else{arr_rulette[2] = 1;}
        if(ui->pushButton_4->isFlat()){}
        else{arr_rulette[4] = 1;}
        if(ui->pushButton_6->isFlat()){}
        else{arr_rulette[6] = 1;}

        ui->pushButton_1_plus_4_2_5->setFlat(true);
    }
}

void MainWindow::on_pushButton_2_plus_5_3_6_clicked()
{
    if(ui->pushButton_2_plus_5_3_6->isFlat())
    {
        if(ui->pushButton_2->isFlat()){}
        else{arr_rulette[2] = 0;}
        if(ui->pushButton_3->isFlat()){}
        else{arr_rulette[3] = 0;}
        if(ui->pushButton_5->isFlat()){}
        else{arr_rulette[5] = 0;}
        if(ui->pushButton_6->isFlat()){}
        else{arr_rulette[6] = 0;}

        ui->pushButton_2_plus_5_3_6->setFlat(false);
    }
    else
    {
        if(ui->pushButton_2->isFlat()){}
        else{arr_rulette[2] = 1;}
        if(ui->pushButton_3->isFlat()){}
        else{arr_rulette[3] = 1;}
        if(ui->pushButton_5->isFlat()){}
        else{arr_rulette[5] = 1;}
        if(ui->pushButton_6->isFlat()){}
        else{arr_rulette[6] = 1;}

        ui->pushButton_2_plus_5_3_6->setFlat(true);
    }
}

void MainWindow::on_pushButton_5_plus_8_6_9_clicked()
{
    if(ui->pushButton_5_plus_8_6_9->isFlat())
    {
        if(ui->pushButton_5->isFlat()){}
        else{arr_rulette[5] = 0;}
        if(ui->pushButton_6->isFlat()){}
        else{arr_rulette[6] = 0;}
        if(ui->pushButton_8->isFlat()){}
        else{arr_rulette[8] = 0;}
        if(ui->pushButton_9->isFlat()){}
        else{arr_rulette[9] = 0;}

        ui->pushButton_5_plus_8_6_9->setFlat(false);
    }
    else
    {
        if(ui->pushButton_5->isFlat()){}
        else{arr_rulette[5] = 1;}
        if(ui->pushButton_6->isFlat()){}
        else{arr_rulette[6] = 1;}
        if(ui->pushButton_8->isFlat()){}
        else{arr_rulette[8] = 1;}
        if(ui->pushButton_9->isFlat()){}
        else{arr_rulette[9] = 1;}

        ui->pushButton_5_plus_8_6_9->setFlat(true);
    }
}

void MainWindow::on_pushButton_4_plus_7_5_8_clicked()
{
    if(ui->pushButton_4_plus_7_5_8->isFlat())
    {
        if(ui->pushButton_4->isFlat()){}
        else{arr_rulette[4] = 0;}
        if(ui->pushButton_5->isFlat()){}
        else{arr_rulette[5] = 0;}
        if(ui->pushButton_7->isFlat()){}
        else{arr_rulette[7] = 0;}
        if(ui->pushButton_8->isFlat()){}
        else{arr_rulette[8] = 0;}

        ui->pushButton_4_plus_7_5_8->setFlat(false);
    }
    else
    {
        if(ui->pushButton_4->isFlat()){}
        else{arr_rulette[4] = 1;}
        if(ui->pushButton_5->isFlat()){}
        else{arr_rulette[5] = 1;}
        if(ui->pushButton_7->isFlat()){}
        else{arr_rulette[7] = 1;}
        if(ui->pushButton_8->isFlat()){}
        else{arr_rulette[8] = 1;}

        ui->pushButton_4_plus_7_5_8->setFlat(true);
    }
}

void MainWindow::on_pushButton_7_plus_10_8_11_clicked()
{
    if(ui->pushButton_7_plus_10_8_11->isFlat())
    {
        if(ui->pushButton_7->isFlat()){}
        else{arr_rulette[7] = 0;}
        if(ui->pushButton_8->isFlat()){}
        else{arr_rulette[8] = 0;}
        if(ui->pushButton_10->isFlat()){}
        else{arr_rulette[10] = 0;}
        if(ui->pushButton_11->isFlat()){}
        else{arr_rulette[11] = 0;}

        ui->pushButton_7_plus_10_8_11->setFlat(false);
    }
    else
    {
        if(ui->pushButton_7->isFlat()){}
        else{arr_rulette[7] = 1;}
        if(ui->pushButton_8->isFlat()){}
        else{arr_rulette[8] = 1;}
        if(ui->pushButton_10->isFlat()){}
        else{arr_rulette[10] = 1;}
        if(ui->pushButton_11->isFlat()){}
        else{arr_rulette[11] = 1;}

        ui->pushButton_7_plus_10_8_11->setFlat(true);
    }
}

void MainWindow::on_pushButton_8_plus_11_9_12_clicked()
{
    if(ui->pushButton_8_plus_11_9_12->isFlat())
    {
        if(ui->pushButton_8->isFlat()){}
        else{arr_rulette[8] = 0;}
        if(ui->pushButton_9->isFlat()){}
        else{arr_rulette[9] = 0;}
        if(ui->pushButton_11->isFlat()){}
        else{arr_rulette[11] = 0;}
        if(ui->pushButton_12->isFlat()){}
        else{arr_rulette[12] = 0;}

        ui->pushButton_8_plus_11_9_12->setFlat(false);
    }
    else
    {
        if(ui->pushButton_8->isFlat()){}
        else{arr_rulette[8] = 1;}
        if(ui->pushButton_9->isFlat()){}
        else{arr_rulette[9] = 1;}
        if(ui->pushButton_11->isFlat()){}
        else{arr_rulette[11] = 1;}
        if(ui->pushButton_12->isFlat()){}
        else{arr_rulette[12] = 1;}

        ui->pushButton_8_plus_11_9_12->setFlat(true);
    }
}

void MainWindow::on_pushButton_11_plus_14_12_15_clicked()
{
    if(ui->pushButton_11_plus_14_12_15->isFlat())
    {
        if(ui->pushButton_11->isFlat()){}
        else{arr_rulette[11] = 0;}
        if(ui->pushButton_12->isFlat()){}
        else{arr_rulette[12] = 0;}
        if(ui->pushButton_14->isFlat()){}
        else{arr_rulette[14] = 0;}
        if(ui->pushButton_15->isFlat()){}
        else{arr_rulette[15] = 0;}

        ui->pushButton_11_plus_14_12_15->setFlat(false);
    }
    else
    {
        if(ui->pushButton_11->isFlat()){}
        else{arr_rulette[11] = 1;}
        if(ui->pushButton_12->isFlat()){}
        else{arr_rulette[12] = 1;}
        if(ui->pushButton_14->isFlat()){}
        else{arr_rulette[14] = 1;}
        if(ui->pushButton_15->isFlat()){}
        else{arr_rulette[15] = 1;}

        ui->pushButton_11_plus_14_12_15->setFlat(true);
    }
}

void MainWindow::on_pushButton_10_plus_13_11_14_clicked()
{
    if(ui->pushButton_10_plus_13_11_14->isFlat())
    {
        if(ui->pushButton_10->isFlat()){}
        else{arr_rulette[10] = 0;}
        if(ui->pushButton_11->isFlat()){}
        else{arr_rulette[11] = 0;}
        if(ui->pushButton_13->isFlat()){}
        else{arr_rulette[13] = 0;}
        if(ui->pushButton_14->isFlat()){}
        else{arr_rulette[14] = 0;}

        ui->pushButton_10_plus_13_11_14->setFlat(false);
    }
    else
    {
        if(ui->pushButton_10->isFlat()){}
        else{arr_rulette[10] = 1;}
        if(ui->pushButton_11->isFlat()){}
        else{arr_rulette[11] = 1;}
        if(ui->pushButton_13->isFlat()){}
        else{arr_rulette[13] = 1;}
        if(ui->pushButton_14->isFlat()){}
        else{arr_rulette[14] = 1;}

        ui->pushButton_10_plus_13_11_14->setFlat(true);
    }
}

void MainWindow::on_pushButton_13_plus_16_14_17_clicked()
{
    if(ui->pushButton_13_plus_16_14_17->isFlat())
    {
        if(ui->pushButton_13->isFlat()){}
        else{arr_rulette[13] = 0;}
        if(ui->pushButton_14->isFlat()){}
        else{arr_rulette[14] = 0;}
        if(ui->pushButton_16->isFlat()){}
        else{arr_rulette[16] = 0;}
        if(ui->pushButton_17->isFlat()){}
        else{arr_rulette[17] = 0;}

        ui->pushButton_13_plus_16_14_17->setFlat(false);
    }
    else
    {
        if(ui->pushButton_13->isFlat()){}
        else{arr_rulette[13] = 1;}
        if(ui->pushButton_14->isFlat()){}
        else{arr_rulette[14] = 1;}
        if(ui->pushButton_16->isFlat()){}
        else{arr_rulette[16] = 1;}
        if(ui->pushButton_17->isFlat()){}
        else{arr_rulette[17] = 1;}

        ui->pushButton_13_plus_16_14_17->setFlat(true);
    }
}

void MainWindow::on_pushButton_14_plus_17_15_18_clicked()
{
    if(ui->pushButton_14_plus_17_15_18->isFlat())
    {
        if(ui->pushButton_14->isFlat()){}
        else{arr_rulette[14] = 0;}
        if(ui->pushButton_15->isFlat()){}
        else{arr_rulette[15] = 0;}
        if(ui->pushButton_17->isFlat()){}
        else{arr_rulette[17] = 0;}
        if(ui->pushButton_18->isFlat()){}
        else{arr_rulette[18] = 0;}

        ui->pushButton_14_plus_17_15_18->setFlat(false);
    }
    else
    {
        if(ui->pushButton_14->isFlat()){}
        else{arr_rulette[14] = 1;}
        if(ui->pushButton_15->isFlat()){}
        else{arr_rulette[15] = 1;}
        if(ui->pushButton_17->isFlat()){}
        else{arr_rulette[17] = 1;}
        if(ui->pushButton_18->isFlat()){}
        else{arr_rulette[18] = 1;}

        ui->pushButton_14_plus_17_15_18->setFlat(true);
    }
}

void MainWindow::on_pushButton_17_plus_20_18_21_clicked()
{
    if(ui->pushButton_17_plus_20_18_21->isFlat())
    {
        if(ui->pushButton_17->isFlat()){}
        else{arr_rulette[17] = 0;}
        if(ui->pushButton_18->isFlat()){}
        else{arr_rulette[18] = 0;}
        if(ui->pushButton_20->isFlat()){}
        else{arr_rulette[20] = 0;}
        if(ui->pushButton_21->isFlat()){}
        else{arr_rulette[21] = 0;}

        ui->pushButton_17_plus_20_18_21->setFlat(false);
    }
    else
    {
        if(ui->pushButton_17->isFlat()){}
        else{arr_rulette[17] = 1;}
        if(ui->pushButton_18->isFlat()){}
        else{arr_rulette[18] = 1;}
        if(ui->pushButton_20->isFlat()){}
        else{arr_rulette[20] = 1;}
        if(ui->pushButton_21->isFlat()){}
        else{arr_rulette[21] = 1;}

        ui->pushButton_17_plus_20_18_21->setFlat(true);
    }
}

void MainWindow::on_pushButton_16_plus_19_17_20_clicked()
{
    if(ui->pushButton_16_plus_19_17_20->isFlat())
    {
        if(ui->pushButton_16->isFlat()){}
        else{arr_rulette[16] = 0;}
        if(ui->pushButton_17->isFlat()){}
        else{arr_rulette[17] = 0;}
        if(ui->pushButton_19->isFlat()){}
        else{arr_rulette[19] = 0;}
        if(ui->pushButton_20->isFlat()){}
        else{arr_rulette[20] = 0;}

        ui->pushButton_16_plus_19_17_20->setFlat(false);
    }
    else
    {
        if(ui->pushButton_16->isFlat()){}
        else{arr_rulette[16] = 1;}
        if(ui->pushButton_17->isFlat()){}
        else{arr_rulette[17] = 1;}
        if(ui->pushButton_19->isFlat()){}
        else{arr_rulette[19] = 1;}
        if(ui->pushButton_20->isFlat()){}
        else{arr_rulette[20] = 1;}

        ui->pushButton_16_plus_19_17_20->setFlat(true);
    }
}

void MainWindow::on_pushButton_19_plus_22_20_23_clicked()
{
    if(ui->pushButton_19_plus_22_20_23->isFlat())
    {
        if(ui->pushButton_19->isFlat()){}
        else{arr_rulette[19] = 0;}
        if(ui->pushButton_20->isFlat()){}
        else{arr_rulette[20] = 0;}
        if(ui->pushButton_22->isFlat()){}
        else{arr_rulette[22] = 0;}
        if(ui->pushButton_23->isFlat()){}
        else{arr_rulette[23] = 0;}

        ui->pushButton_19_plus_22_20_23->setFlat(false);
    }
    else
    {
        if(ui->pushButton_19->isFlat()){}
        else{arr_rulette[19] = 1;}
        if(ui->pushButton_20->isFlat()){}
        else{arr_rulette[20] = 1;}
        if(ui->pushButton_22->isFlat()){}
        else{arr_rulette[22] = 1;}
        if(ui->pushButton_23->isFlat()){}
        else{arr_rulette[23] = 1;}

        ui->pushButton_19_plus_22_20_23->setFlat(true);
    }
}

void MainWindow::on_pushButton_20_plus_23_21_24_clicked()
{
    if(ui->pushButton_20_plus_23_21_24->isFlat())
    {
        if(ui->pushButton_20->isFlat()){}
        else{arr_rulette[20] = 0;}
        if(ui->pushButton_21->isFlat()){}
        else{arr_rulette[21] = 0;}
        if(ui->pushButton_23->isFlat()){}
        else{arr_rulette[23] = 0;}
        if(ui->pushButton_24->isFlat()){}
        else{arr_rulette[24] = 0;}

        ui->pushButton_20_plus_23_21_24->setFlat(false);
    }
    else
    {
        if(ui->pushButton_20->isFlat()){}
        else{arr_rulette[20] = 1;}
        if(ui->pushButton_21->isFlat()){}
        else{arr_rulette[21] = 1;}
        if(ui->pushButton_23->isFlat()){}
        else{arr_rulette[23] = 1;}
        if(ui->pushButton_24->isFlat()){}
        else{arr_rulette[24] = 1;}

        ui->pushButton_20_plus_23_21_24->setFlat(true);
    }
}

void MainWindow::on_pushButton_22_plus_25_23_26_clicked()
{
    if(ui->pushButton_22_plus_25_23_26->isFlat())
    {
        if(ui->pushButton_22->isFlat()){}
        else{arr_rulette[22] = 0;}
        if(ui->pushButton_23->isFlat()){}
        else{arr_rulette[23] = 0;}
        if(ui->pushButton_25->isFlat()){}
        else{arr_rulette[25] = 0;}
        if(ui->pushButton_26->isFlat()){}
        else{arr_rulette[26] = 0;}

        ui->pushButton_22_plus_25_23_26->setFlat(false);
    }
    else
    {
        if(ui->pushButton_22->isFlat()){}
        else{arr_rulette[22] = 1;}
        if(ui->pushButton_23->isFlat()){}
        else{arr_rulette[23] = 1;}
        if(ui->pushButton_25->isFlat()){}
        else{arr_rulette[25] = 1;}
        if(ui->pushButton_26->isFlat()){}
        else{arr_rulette[26] = 1;}

        ui->pushButton_22_plus_25_23_26->setFlat(true);
    }
}

void MainWindow::on_pushButton_23_plus_26_24_27_clicked()
{
    if(ui->pushButton_23_plus_26_24_27->isFlat())
    {
        if(ui->pushButton_23->isFlat()){}
        else{arr_rulette[23] = 0;}
        if(ui->pushButton_24->isFlat()){}
        else{arr_rulette[24] = 0;}
        if(ui->pushButton_26->isFlat()){}
        else{arr_rulette[26] = 0;}
        if(ui->pushButton_27->isFlat()){}
        else{arr_rulette[27] = 0;}

        ui->pushButton_23_plus_26_24_27->setFlat(false);
    }
    else
    {
        if(ui->pushButton_23->isFlat()){}
        else{arr_rulette[23] = 1;}
        if(ui->pushButton_24->isFlat()){}
        else{arr_rulette[24] = 1;}
        if(ui->pushButton_26->isFlat()){}
        else{arr_rulette[26] = 1;}
        if(ui->pushButton_27->isFlat()){}
        else{arr_rulette[27] = 1;}

        ui->pushButton_23_plus_26_24_27->setFlat(true);
    }
}

void MainWindow::on_pushButton_25_plus_28_26_29_clicked()
{
    if(ui->pushButton_25_plus_28_26_29->isFlat())
    {
        if(ui->pushButton_25->isFlat()){}
        else{arr_rulette[25] = 0;}
        if(ui->pushButton_26->isFlat()){}
        else{arr_rulette[26] = 0;}
        if(ui->pushButton_28->isFlat()){}
        else{arr_rulette[28] = 0;}
        if(ui->pushButton_29->isFlat()){}
        else{arr_rulette[29] = 0;}

        ui->pushButton_25_plus_28_26_29->setFlat(false);
    }
    else
    {
        if(ui->pushButton_25->isFlat()){}
        else{arr_rulette[25] = 1;}
        if(ui->pushButton_26->isFlat()){}
        else{arr_rulette[26] = 1;}
        if(ui->pushButton_28->isFlat()){}
        else{arr_rulette[28] = 1;}
        if(ui->pushButton_29->isFlat()){}
        else{arr_rulette[29] = 1;}

        ui->pushButton_25_plus_28_26_29->setFlat(true);
    }
}

void MainWindow::on_pushButton_26_plus_29_27_30_clicked()
{
    if(ui->pushButton_26_plus_29_27_30->isFlat())
    {
        if(ui->pushButton_26->isFlat()){}
        else{arr_rulette[26] = 0;}
        if(ui->pushButton_27->isFlat()){}
        else{arr_rulette[27] = 0;}
        if(ui->pushButton_29->isFlat()){}
        else{arr_rulette[29] = 0;}
        if(ui->pushButton_30->isFlat()){}
        else{arr_rulette[30] = 0;}

        ui->pushButton_26_plus_29_27_30->setFlat(false);
    }
    else
    {
        if(ui->pushButton_26->isFlat()){}
        else{arr_rulette[26] = 1;}
        if(ui->pushButton_27->isFlat()){}
        else{arr_rulette[27] = 1;}
        if(ui->pushButton_29->isFlat()){}
        else{arr_rulette[29] = 1;}
        if(ui->pushButton_30->isFlat()){}
        else{arr_rulette[30] = 1;}

        ui->pushButton_26_plus_29_27_30->setFlat(true);
    }
}

void MainWindow::on_pushButton_29_plus_32_30_33_clicked()
{
    if(ui->pushButton_29_plus_32_30_33->isFlat())
    {
        if(ui->pushButton_29->isFlat()){}
        else{arr_rulette[29] = 0;}
        if(ui->pushButton_30->isFlat()){}
        else{arr_rulette[30] = 0;}
        if(ui->pushButton_32->isFlat()){}
        else{arr_rulette[32] = 0;}
        if(ui->pushButton_33->isFlat()){}
        else{arr_rulette[33] = 0;}

        ui->pushButton_29_plus_32_30_33->setFlat(false);
    }
    else
    {
        if(ui->pushButton_29->isFlat()){}
        else{arr_rulette[29] = 1;}
        if(ui->pushButton_30->isFlat()){}
        else{arr_rulette[30] = 1;}
        if(ui->pushButton_32->isFlat()){}
        else{arr_rulette[32] = 1;}
        if(ui->pushButton_33->isFlat()){}
        else{arr_rulette[33] = 1;}

        ui->pushButton_29_plus_32_30_33->setFlat(true);
    }
}

void MainWindow::on_pushButton_28_plus_31_29_32_clicked()
{
    if(ui->pushButton_28_plus_31_29_32->isFlat())
    {
        if(ui->pushButton_28->isFlat()){}
        else{arr_rulette[28] = 0;}
        if(ui->pushButton_29->isFlat()){}
        else{arr_rulette[29] = 0;}
        if(ui->pushButton_31->isFlat()){}
        else{arr_rulette[31] = 0;}
        if(ui->pushButton_32->isFlat()){}
        else{arr_rulette[32] = 0;}

        ui->pushButton_28_plus_31_29_32->setFlat(false);
    }
    else
    {
        if(ui->pushButton_28->isFlat()){}
        else{arr_rulette[28] = 1;}
        if(ui->pushButton_29->isFlat()){}
        else{arr_rulette[29] = 1;}
        if(ui->pushButton_31->isFlat()){}
        else{arr_rulette[31] = 1;}
        if(ui->pushButton_32->isFlat()){}
        else{arr_rulette[32] = 1;}

        ui->pushButton_28_plus_31_29_32->setFlat(true);
    }
}

void MainWindow::on_pushButton_31_plus_34_32_35_clicked()
{
    if(ui->pushButton_31_plus_34_32_35->isFlat())
    {
        if(ui->pushButton_31->isFlat()){}
        else{arr_rulette[31] = 0;}
        if(ui->pushButton_32->isFlat()){}
        else{arr_rulette[32] = 0;}
        if(ui->pushButton_34->isFlat()){}
        else{arr_rulette[34] = 0;}
        if(ui->pushButton_35->isFlat()){}
        else{arr_rulette[35] = 0;}

        ui->pushButton_31_plus_34_32_35->setFlat(false);
    }
    else
    {
        if(ui->pushButton_31->isFlat()){}
        else{arr_rulette[31] = 1;}
        if(ui->pushButton_32->isFlat()){}
        else{arr_rulette[32] = 1;}
        if(ui->pushButton_34->isFlat()){}
        else{arr_rulette[34] = 1;}
        if(ui->pushButton_35->isFlat()){}
        else{arr_rulette[35] = 1;}

        ui->pushButton_31_plus_34_32_35->setFlat(true);
    }
}

void MainWindow::on_pushButton_32_plus_35_33_36_clicked()
{
    if(ui->pushButton_32_plus_35_33_36->isFlat())
    {
        if(ui->pushButton_32->isFlat()){}
        else{arr_rulette[32] = 0;}
        if(ui->pushButton_33->isFlat()){}
        else{arr_rulette[33] = 0;}
        if(ui->pushButton_35->isFlat()){}
        else{arr_rulette[35] = 0;}
        if(ui->pushButton_36->isFlat()){}
        else{arr_rulette[36] = 0;}

        ui->pushButton_32_plus_35_33_36->setFlat(false);
    }
    else
    {
        if(ui->pushButton_32->isFlat()){}
        else{arr_rulette[32] = 1;}
        if(ui->pushButton_33->isFlat()){}
        else{arr_rulette[33] = 1;}
        if(ui->pushButton_35->isFlat()){}
        else{arr_rulette[35] = 1;}
        if(ui->pushButton_36->isFlat()){}
        else{arr_rulette[36] = 1;}

        ui->pushButton_32_plus_35_33_36->setFlat(true);
    }
}

void MainWindow::on_Bet_button1_clicked()
{
    //place lowest posibble bet
}

void MainWindow::on_Bet_button2_clicked()
{
    //place low mid bet
}

void MainWindow::on_Bet_button3_clicked()
{
    //place high mid bet
}

void MainWindow::on_Bet_button4_clicked()
{
    //place highest bet
}

void MainWindow::on_Clear_Button_clicked()
{
    //clears all the bets
}

void MainWindow::on_redButton_red_clicked()
{
    if(ui->redButton_red->isFlat())
    {
        color1 = 'W';
        ui->redButton_red->setFlat(false);
    }
    else
    {
        color1 = 'R';
        ui->redButton_red->setFlat(true);
    }
}

void MainWindow::on_pushButton_black_clicked()
{
    if(ui->pushButton_black->isFlat())
    {
        color2 = 'W';
        ui->pushButton_black->setFlat(false);
    }
    else
    {
        color2 = 'B';
        ui->pushButton_black->setFlat(true);
    }
}

void MainWindow::on_pushButton_spin_clicked()
{
    QMovie *movie = new QMovie("/home/aleksandar/Desktop/roulette working/NETB375_Roulette-master/netb375_roulette/img/roulette3.gif");
    ui->label_gif->setMovie(movie);
    movie->setSpeed(130);
    movie->start();
    
    n=rand()%38;
    check_color(n);
}
