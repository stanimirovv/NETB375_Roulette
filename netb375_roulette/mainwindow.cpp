#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
<<<<<<< HEAD

    array_to_buttons[0] = ui->pushButton_0;
    array_to_buttons[1] = ui->pushButton_1;
    array_to_buttons[2] = ui->pushButton_2;
    array_to_buttons[3] = ui->pushButton_3;
    array_to_buttons[4] = ui->pushButton_4;
    array_to_buttons[5] = ui->pushButton_5;
    array_to_buttons[6] = ui->pushButton_6;
    array_to_buttons[7] = ui->pushButton_7;
    array_to_buttons[8] = ui->pushButton_8;
    array_to_buttons[9] = ui->pushButton_9;
    array_to_buttons[10] = ui->pushButton_10;
    array_to_buttons[11] = ui->pushButton_11;
    array_to_buttons[12] = ui->pushButton_12;
    array_to_buttons[13] = ui->pushButton_13;
    array_to_buttons[14] = ui->pushButton_14;
    array_to_buttons[15] = ui->pushButton_15;
    array_to_buttons[16] = ui->pushButton_16;
    array_to_buttons[17] = ui->pushButton_17;
    array_to_buttons[18] = ui->pushButton_18;
    array_to_buttons[19] = ui->pushButton_19;
    array_to_buttons[20] = ui->pushButton_20;
    array_to_buttons[21] = ui->pushButton_21;
    array_to_buttons[22] = ui->pushButton_22;
    array_to_buttons[23] = ui->pushButton_23;
    array_to_buttons[24] = ui->pushButton_24;
    array_to_buttons[25] = ui->pushButton_25;
    array_to_buttons[26] = ui->pushButton_26;
    array_to_buttons[27] = ui->pushButton_27;
    array_to_buttons[28] = ui->pushButton_28;
    array_to_buttons[29] = ui->pushButton_29;
    array_to_buttons[30] = ui->pushButton_30;
    array_to_buttons[31] = ui->pushButton_31;
    array_to_buttons[32] = ui->pushButton_32;
    array_to_buttons[33] = ui->pushButton_33;
    array_to_buttons[34] = ui->pushButton_34;
    array_to_buttons[35] = ui->pushButton_35;
    array_to_buttons[36] = ui->pushButton_36;
=======
    setStyleSheet("MainWindow {background-color:green};"); //setting background color only to MainWindow
    QPixmap pixmap("/home/aleksandar/Desktop/roulette working/NETB375_Roulette-master/netb375_roulette/img/roulette3.gif");
    ui->label_gif->setPixmap(pixmap); //setting an image for the spin button
>>>>>>> origin/master
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
QIcon ButtonIcon; // defines an Object of QIcon that we use to store the currnet chip in

bool check_num(int n)//checks for 1 in the array of bets on the random generated number's position
{
    if(arr_rulette[n]!=0)
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

void MainWindow::bet_handler(int x,bool again)
{
    if(again)
    {
        arr_rulette[x]=(arr_rulette[x])-1;
    }
    else
    {
        arr_rulette[x]=(arr_rulette[x])+1;
    }
}

void MainWindow::single_button_bet(int x)
{
    if(array_to_buttons[x]->isFlat())
    {
        bet_handler(x,true);
        QString s = QString::number(x);
        array_to_buttons[x]->setText(s);
        array_to_buttons[x]->setIcon(QIcon());
        array_to_buttons[x]->setFlat(false);
    }
    else
    {
        bet_handler(x,false);
        array_to_buttons[x]->setText("");
        array_to_buttons[x]->setIcon(ButtonIcon);
        array_to_buttons[x]->setIconSize(QSize(40,40));
        array_to_buttons[x]->setFlat(true);
    }
}

void MainWindow::multi_button_bet(int x1, int x2,bool more)
{
    if(x2-x1==1)
    {
        if(more)
        {
            bet_handler(x1,true);
            bet_handler(x2,true);
        }
        else
        {
            bet_handler(x1,false);
            bet_handler(x2,false);
        }
    }
    else if(x2-x1==3)
    {
        if(more)
        {
            bet_handler(x1,true);
            bet_handler(x2,true);
        }
        else
        {
            bet_handler(x1,false);
            bet_handler(x2,false);
        }
    }
    else if(x2-x1==4)
    {
        if(more)
        {
            bet_handler(x1,true);
            bet_handler(x2,true);
            bet_handler(x1+1,true);
            bet_handler(x2-1,true);
        }
        else
        {
            bet_handler(x1,false);
            bet_handler(x2,false);
            bet_handler(x1+1,false);
            bet_handler(x2-1,false);
        }
    }
    else if(x2-x1>4)
    {
        if(more)
        {
            for(;x1<=x2;x1++)
            {
                bet_handler(x1,true);
            }
        }
        else
        {
            for(;x1<=x2;x1++)
            {
                bet_handler(x1,false);
            }
        }
    }
}



void MainWindow::on_pushButton_1_clicked()
{
    single_button_bet(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    single_button_bet(2);
}

void MainWindow::on_pushButton_3_clicked()
{
    single_button_bet(3);
}

void MainWindow::on_pushButton_4_clicked()
{
    single_button_bet(4);
}

void MainWindow::on_pushButton_5_clicked()
{
    single_button_bet(5);
}

void MainWindow::on_pushButton_6_clicked()
{
    single_button_bet(6);
}

void MainWindow::on_pushButton_7_clicked()
{
    single_button_bet(7);
}

void MainWindow::on_pushButton_8_clicked()
{
    single_button_bet(8);
}

void MainWindow::on_pushButton_9_clicked()
{
    single_button_bet(9);
}

void MainWindow::on_pushButton_10_clicked()
{
    single_button_bet(10);
}

void MainWindow::on_pushButton_11_clicked()
{
    single_button_bet(11);
}

void MainWindow::on_pushButton_12_clicked()
{
    single_button_bet(12);
}

void MainWindow::on_pushButton_13_clicked()
{
    single_button_bet(13);
}

void MainWindow::on_pushButton_14_clicked()
{
    single_button_bet(14);
}

void MainWindow::on_pushButton_15_clicked()
{
    single_button_bet(15);
}

void MainWindow::on_pushButton_16_clicked()
{
    single_button_bet(16);
}

void MainWindow::on_pushButton_17_clicked()
{
    single_button_bet(17);
}

void MainWindow::on_pushButton_18_clicked()
{
    single_button_bet(18);
}

void MainWindow::on_pushButton_19_clicked()
{
    single_button_bet(19);
}

void MainWindow::on_pushButton_20_clicked()
{
    single_button_bet(20);
}

void MainWindow::on_pushButton_21_clicked()
{
    single_button_bet(21);
}

void MainWindow::on_pushButton_22_clicked()
{
    single_button_bet(22);
}

void MainWindow::on_pushButton_23_clicked()
{
    single_button_bet(23);
}

void MainWindow::on_pushButton_24_clicked()
{
    single_button_bet(24);
}

void MainWindow::on_pushButton_25_clicked()
{
    single_button_bet(25);
}

void MainWindow::on_pushButton_26_clicked()
{
    single_button_bet(26);
}

void MainWindow::on_pushButton_27_clicked()
{
    single_button_bet(27);
}

void MainWindow::on_pushButton_28_clicked()
{
    single_button_bet(28);
}

void MainWindow::on_pushButton_29_clicked()
{
    single_button_bet(29);
}

void MainWindow::on_pushButton_30_clicked()
{
    single_button_bet(30);
}

void MainWindow::on_pushButton_31_clicked()
{
    single_button_bet(31);
}

void MainWindow::on_pushButton_32_clicked()
{
    single_button_bet(32);
}

void MainWindow::on_pushButton_33_clicked()
{
    single_button_bet(33);
}

void MainWindow::on_pushButton_34_clicked()
{
    single_button_bet(34);
}

void MainWindow::on_pushButton_35_clicked()
{
    single_button_bet(35);
}

void MainWindow::on_pushButton_36_clicked()
{
    single_button_bet(36);
}

void MainWindow::on_pushButton_0_clicked()
{
    single_button_bet(0);
}
// works the same but on multiple buttons without changeing them
// checks if the button is flat if not set's it to 0 when removing bets if yes does nothing
// same for all the fallowing buttons
void MainWindow::on_pushButton_1_18_clicked()
{
    if(ui->pushButton_1_18->isFlat())
    {
        multi_button_bet(1,18,true);

        ui->pushButton_1_18->setText("1-18");
        ui->pushButton_1_18->setIcon(QIcon());
        ui->pushButton_1_18->setFlat(false);
    }
    else
    {
        multi_button_bet(1,18,false);

        ui->pushButton_1_18->setText("");
        ui->pushButton_1_18->setIcon(ButtonIcon);
        ui->pushButton_1_18->setIconSize(QSize(40,40));
        ui->pushButton_1_18->setFlat(true);
    }
}

void MainWindow::on_pushButton_19_36_clicked()
{
    if(ui->pushButton_19_36->isFlat())
    {
        multi_button_bet(19,36,true);

        ui->pushButton_19_36->setText("19-36");
        ui->pushButton_19_36->setIcon(QIcon());
        ui->pushButton_19_36->setFlat(false);
    }
    else
    {
        multi_button_bet(19,36,false);

        ui->pushButton_19_36->setText("");
        ui->pushButton_19_36->setIcon(ButtonIcon);
        ui->pushButton_19_36->setIconSize(QSize(40,40));
        ui->pushButton_19_36->setFlat(true);
    }
}

void MainWindow::on_pushButton_1st_clicked()
{
    if(ui->pushButton_1st->isFlat())
    {
        multi_button_bet(1,12,true);

        ui->pushButton_1st->setText("1st 12");
        ui->pushButton_1st->setIcon(QIcon());
        ui->pushButton_1st->setFlat(false);
    }
    else
    {
        multi_button_bet(1,12,false);

        ui->pushButton_1st->setText("");
        ui->pushButton_1st->setIcon(ButtonIcon);
        ui->pushButton_1st->setIconSize(QSize(40,40));
        ui->pushButton_1st->setFlat(true);
    }
}
void MainWindow::on_pushButton_2nd_clicked()
{
    if(ui->pushButton_2nd->isFlat())
    {
        multi_button_bet(13,24,true);

        ui->pushButton_2nd->setText("2nd 12");
        ui->pushButton_2nd->setIcon(QIcon());
        ui->pushButton_2nd->setFlat(false);
    }
    else
    {
        multi_button_bet(13,24,false);

        ui->pushButton_2nd->setText("");
        ui->pushButton_2nd->setIcon(ButtonIcon);
        ui->pushButton_2nd->setIconSize(QSize(40,40));
        ui->pushButton_2nd->setFlat(true);
    }
}

void MainWindow::on_pushButton_3rd_clicked()
{
    if(ui->pushButton_3rd->isFlat())
    {
        multi_button_bet(25,36,true);

        ui->pushButton_3rd->setText("3rd 12");
        ui->pushButton_3rd->setIcon(QIcon());
        ui->pushButton_3rd->setFlat(false);
    }
    else
    {
        multi_button_bet(25,36,false);

        ui->pushButton_3rd->setText("");
        ui->pushButton_3rd->setIcon(ButtonIcon);
        ui->pushButton_3rd->setIconSize(QSize(40,40));
        ui->pushButton_3rd->setFlat(true);
    }
}

void MainWindow::on_pushButton_even_clicked()
{
    if(ui->pushButton_even->isFlat())
    {
        for(int i=2;i<=36;i+=2)
        {
            bet_handler(i,true);
        }

        ui->pushButton_even->setText("Even");
        ui->pushButton_even->setIcon(QIcon());
        ui->pushButton_even->setFlat(false);
    }
    else
    {
        for(int i=2;i<=36;i+=2)
        {
            bet_handler(i,false);
        }

        ui->pushButton_even->setText("");
        ui->pushButton_even->setIcon(ButtonIcon);
        ui->pushButton_even->setIconSize(QSize(40,40));
        ui->pushButton_even->setFlat(true);
    }
}

void MainWindow::on_pushButton_odd_clicked()
{
    if(ui->pushButton_odd->isFlat())
    {
        for(int i=1;i<=36;i+=2)
        {
            bet_handler(i,true);
        }

        ui->pushButton_odd->setText("Odd");
        ui->pushButton_odd->setIcon(QIcon());
        ui->pushButton_odd->setFlat(false);
    }
    else
    {
        for(int i=1;i<=36;i+=2)
        {
            bet_handler(i,false);
        }
        ui->pushButton_odd->setText("");
        ui->pushButton_odd->setIcon(ButtonIcon);
        ui->pushButton_odd->setIconSize(QSize(40,40));
        ui->pushButton_odd->setFlat(true);
    }
}

void MainWindow::on_redButton_red_clicked()
{
    if(ui->redButton_red->isFlat())
    {
        color1 = 'W';
        ui->redButton_red->setText("RED");
        ui->redButton_red->setIcon(QIcon());
        ui->redButton_red->setFlat(false);
    }
    else
    {
        color1 = 'R';
        ui->redButton_red->setText("");
        ui->redButton_red->setIcon(ButtonIcon);
        ui->redButton_red->setIconSize(QSize(40,40));
        ui->redButton_red->setFlat(true);
    }
}

void MainWindow::on_pushButton_black_clicked()
{
    if(ui->pushButton_black->isFlat())
    {
        color2 = 'W';
        ui->pushButton_black->setText("BLACK");
        ui->pushButton_black->setIcon(QIcon());
        ui->pushButton_black->setFlat(false);
    }
    else
    {
        color2 = 'B';
        ui->pushButton_black->setText("");
        ui->pushButton_black->setIcon(ButtonIcon);
        ui->pushButton_black->setIconSize(QSize(40,40));
        ui->pushButton_black->setFlat(true);
    }
}

void MainWindow::on_pushButton_1_plus_2_clicked()
{
    if(ui->pushButton_1_plus_2->isFlat())
    {
        multi_button_bet(1,2,true);

        ui->pushButton_1_plus_2->setFlat(false);
    }
    else
    {
        multi_button_bet(1,2,false);

        ui->pushButton_1_plus_2->setFlat(true);
    }

}

void MainWindow::on_pushButton_2_plus_3_clicked()
{
    if(ui->pushButton_2_plus_3->isFlat())
    {
        multi_button_bet(2,3,true);

        ui->pushButton_2_plus_3->setFlat(false);
    }
    else
    {
        multi_button_bet(2,3,false);

        ui->pushButton_2_plus_3->setFlat(true);
    }
}

void MainWindow::on_pushButton_4_plus_5_clicked()
{
    if(ui->pushButton_4_plus_5->isFlat())
    {
        multi_button_bet(4,5,true);

        ui->pushButton_4_plus_5->setFlat(false);
    }
    else
    {
        multi_button_bet(4,5,false);

        ui->pushButton_4_plus_5->setFlat(true);
    }
}

void MainWindow::on_pushButton_5_plus_6_clicked()
{
    if(ui->pushButton_5_plus_6->isFlat())
    {
        multi_button_bet(5,6,true);

        ui->pushButton_5_plus_6->setFlat(false);
    }
    else
    {
        multi_button_bet(5,6,false);

        ui->pushButton_5_plus_6->setFlat(true);
    }
}

void MainWindow::on_pushButton_7_plus_8_clicked()
{
    if(ui->pushButton_7_plus_8->isFlat())
    {
        multi_button_bet(7,8,true);

        ui->pushButton_7_plus_8->setFlat(false);
    }
    else
    {
        multi_button_bet(7,8,false);

        ui->pushButton_7_plus_8->setFlat(true);
    }
}

void MainWindow::on_pushButton_8_plus_9_clicked()
{
    if(ui->pushButton_8_plus_9->isFlat())
    {
        multi_button_bet(8,9,true);

        ui->pushButton_8_plus_9->setFlat(false);
    }
    else
    {
        multi_button_bet(8,9,false);

        ui->pushButton_8_plus_9->setFlat(true);
    }
}

void MainWindow::on_pushButton_10_plus_11_clicked()
{
    if(ui->pushButton_10_plus_11->isFlat())
    {
        multi_button_bet(10,11,true);

        ui->pushButton_10_plus_11->setFlat(false);
    }
    else
    {
        multi_button_bet(10,11,false);

        ui->pushButton_10_plus_11->setFlat(true);
    }
}

void MainWindow::on_pushButton_11_plus_12_clicked()
{
    if(ui->pushButton_11_plus_12->isFlat())
    {
        multi_button_bet(11,12,true);

        ui->pushButton_11_plus_12->setFlat(false);
    }
    else
    {
        multi_button_bet(11,12,false);

        ui->pushButton_11_plus_12->setFlat(true);
    }
}

void MainWindow::on_pushButton_13_plus_14_clicked()
{
    if(ui->pushButton_13_plus_14->isFlat())
    {
        multi_button_bet(13,14,true);

        ui->pushButton_13_plus_14->setFlat(false);
    }
    else
    {
        multi_button_bet(13,14,false);

        ui->pushButton_13_plus_14->setFlat(true);
    }
}

void MainWindow::on_pushButton_14_plus_15_clicked()
{
    if(ui->pushButton_14_plus_15->isFlat())
    {
        multi_button_bet(14,15,true);

        ui->pushButton_14_plus_15->setFlat(false);
    }
    else
    {
        multi_button_bet(14,15,false);

        ui->pushButton_14_plus_15->setFlat(true);
    }
}

void MainWindow::on_pushButton_16_plus_17_clicked()
{
    if(ui->pushButton_16_plus_17->isFlat())
    {
        multi_button_bet(16,17,true);

        ui->pushButton_16_plus_17->setFlat(false);
    }
    else
    {
        multi_button_bet(16,17,false);

        ui->pushButton_16_plus_17->setFlat(true);
    }
}

void MainWindow::on_pushButton_17_plus_18_clicked()
{
    if(ui->pushButton_17_plus_18->isFlat())
    {
        multi_button_bet(17,18,true);

        ui->pushButton_17_plus_18->setFlat(false);
    }
    else
    {
        multi_button_bet(17,18,false);

        ui->pushButton_17_plus_18->setFlat(true);
    }
}

void MainWindow::on_pushButton_19_plus_20_clicked()
{
    if(ui->pushButton_19_plus_20->isFlat())
    {
        multi_button_bet(19,20,true);

        ui->pushButton_19_plus_20->setFlat(false);
    }
    else
    {
        multi_button_bet(19,20,false);

        ui->pushButton_19_plus_20->setFlat(true);
    }
}

void MainWindow::on_pushButton_20_plus_21_clicked()
{
    if(ui->pushButton_20_plus_21->isFlat())
    {
        multi_button_bet(20,21,true);

        ui->pushButton_20_plus_21->setFlat(false);
    }
    else
    {
        multi_button_bet(20,21,false);

        ui->pushButton_20_plus_21->setFlat(true);
    }
}

void MainWindow::on_pushButton_22_plus_23_clicked()
{
    if(ui->pushButton_22_plus_23->isFlat())
    {
         multi_button_bet(22,23,true);

        ui->pushButton_22_plus_23->setFlat(false);
    }
    else
    {
         multi_button_bet(22,23,false);

        ui->pushButton_22_plus_23->setFlat(true);
    }
}

void MainWindow::on_pushButton_23_plus_24_clicked()
{
    if(ui->pushButton_23_plus_24->isFlat())
    {
         multi_button_bet(23,24,true);

        ui->pushButton_23_plus_24->setFlat(false);
    }
    else
    {
        multi_button_bet(23,24,false);

        ui->pushButton_23_plus_24->setFlat(true);
    }
}

void MainWindow::on_pushButton_25_plus_26_clicked()
{
    if(ui->pushButton_25_plus_26->isFlat())
    {
        multi_button_bet(25,26,true);

        ui->pushButton_25_plus_26->setFlat(false);
    }
    else
    {
        multi_button_bet(25,26,false);

        ui->pushButton_25_plus_26->setFlat(true);
    }
}

void MainWindow::on_pushButton_26_plus_27_clicked()
{
    if(ui->pushButton_26_plus_27->isFlat())
    {
        multi_button_bet(26,27,true);

        ui->pushButton_26_plus_27->setFlat(false);
    }
    else
    {
        multi_button_bet(26,27,false);

        ui->pushButton_26_plus_27->setFlat(true);
    }
}

void MainWindow::on_pushButton_28_plus_29_clicked()
{
    if(ui->pushButton_28_plus_29->isFlat())
    {
        multi_button_bet(28,29,true);

        ui->pushButton_28_plus_29->setFlat(false);
    }
    else
    {
        multi_button_bet(28,29,false);

        ui->pushButton_28_plus_29->setFlat(true);
    }
}

void MainWindow::on_pushButton_29_plus_30_clicked()
{
    if(ui->pushButton_29_plus_30->isFlat())
    {
        multi_button_bet(29,30,true);

        ui->pushButton_29_plus_30->setFlat(false);
    }
    else
    {
        multi_button_bet(29,30,false);

        ui->pushButton_29_plus_30->setFlat(true);
    }
}

void MainWindow::on_pushButton_31_plus_32_clicked()
{
    if(ui->pushButton_31_plus_32->isFlat())
    {
        multi_button_bet(31,32,true);

        ui->pushButton_31_plus_32->setFlat(false);
    }
    else
    {
        multi_button_bet(31,32,false);

        ui->pushButton_31_plus_32->setFlat(true);
    }
}

void MainWindow::on_pushButton_32_plus_33_clicked()
{
    if(ui->pushButton_32_plus_33->isFlat())
    {
        multi_button_bet(32,33,true);

        ui->pushButton_32_plus_33->setFlat(false);
    }
    else
    {
        multi_button_bet(32,33,false);

        ui->pushButton_32_plus_33->setFlat(true);
    }
}

void MainWindow::on_pushButton_34_plus_35_clicked()
{
    if(ui->pushButton_34_plus_35->isFlat())
    {
        multi_button_bet(34,35,true);

        ui->pushButton_34_plus_35->setFlat(false);
    }
    else
    {
        multi_button_bet(34,35,false);

        ui->pushButton_34_plus_35->setFlat(true);
    }
}

void MainWindow::on_pushButton_35_plus_36_clicked()
{
    if(ui->pushButton_35_plus_36->isFlat())
    {
        multi_button_bet(35,36,true);

        ui->pushButton_35_plus_36->setFlat(false);
    }
    else
    {
        multi_button_bet(35,36,false);

        ui->pushButton_35_plus_36->setFlat(true);
    }
}

void MainWindow::on_pushButton_1_plus_4_clicked()
{
    if(ui->pushButton_1_plus_4->isFlat())
    {
        multi_button_bet(1,4,true);

        ui->pushButton_1_plus_4->setFlat(false);
    }
    else
    {
        multi_button_bet(1,4,false);

        ui->pushButton_1_plus_4->setFlat(true);
    }
}

void MainWindow::on_pushButton_4_plus_7_clicked()
{
    if(ui->pushButton_4_plus_7->isFlat())
    {
        multi_button_bet(4,7,true);

        ui->pushButton_4_plus_7->setFlat(false);
    }
    else
    {
        multi_button_bet(4,7,false);

        ui->pushButton_4_plus_7->setFlat(true);
    }
}

void MainWindow::on_pushButton_7_plus_10_clicked()
{
    if(ui->pushButton_7_plus_10->isFlat())
    {
        multi_button_bet(7,10,true);

        ui->pushButton_7_plus_10->setFlat(false);
    }
    else
    {
        multi_button_bet(7,10,false);

        ui->pushButton_7_plus_10->setFlat(true);
    }
}

void MainWindow::on_pushButton_10_plus_13_clicked()
{
    if(ui->pushButton_10_plus_13->isFlat())
    {
        multi_button_bet(10,13,true);

        ui->pushButton_10_plus_13->setFlat(false);
    }
    else
    {
        multi_button_bet(10,13,false);

        ui->pushButton_10_plus_13->setFlat(true);
    }
}

void MainWindow::on_pushButton_13_plus_16_clicked()
{
    if(ui->pushButton_13_plus_16->isFlat())
    {
        multi_button_bet(13,16,true);

        ui->pushButton_13_plus_16->setFlat(false);
    }
    else
    {
        multi_button_bet(13,16,false);

        ui->pushButton_13_plus_16->setFlat(true);
    }
}

void MainWindow::on_pushButton_16_plus_19_clicked()
{
    if(ui->pushButton_16_plus_19->isFlat())
    {
        multi_button_bet(16,19,true);

        ui->pushButton_16_plus_19->setFlat(false);
    }
    else
    {
        multi_button_bet(16,19,false);

        ui->pushButton_16_plus_19->setFlat(true);
    }
}

void MainWindow::on_pushButton_19_plus_22_clicked()
{
    if(ui->pushButton_19_plus_22->isFlat())
    {
        multi_button_bet(19,22,true);

        ui->pushButton_19_plus_22->setFlat(false);
    }
    else
    {
        multi_button_bet(19,22,false);

        ui->pushButton_19_plus_22->setFlat(true);
    }
}

void MainWindow::on_pushButton_22_Plus_25_clicked()
{
    if(ui->pushButton_22_Plus_25->isFlat())
    {
        multi_button_bet(22,25,true);

        ui->pushButton_22_Plus_25->setFlat(false);
    }
    else
    {
        multi_button_bet(22,25,false);

        ui->pushButton_22_Plus_25->setFlat(true);
    }
}

void MainWindow::on_pushButton_25_plus_28_clicked()
{
    if(ui->pushButton_25_plus_28->isFlat())
    {
        multi_button_bet(25,28,true);

        ui->pushButton_25_plus_28->setFlat(false);
    }
    else
    {
        multi_button_bet(25,28,false);

        ui->pushButton_25_plus_28->setFlat(true);
    }
}

void MainWindow::on_pushButton_28_Plus_31_clicked()
{
    if(ui->pushButton_28_Plus_31->isFlat())
    {
        multi_button_bet(28,31,true);

        ui->pushButton_28_Plus_31->setFlat(false);
    }
    else
    {
        multi_button_bet(28,31,false);

        ui->pushButton_28_Plus_31->setFlat(true);
    }
}

void MainWindow::on_pushButton_31_plus_34_clicked()
{
    if(ui->pushButton_31_plus_34->isFlat())
    {
        multi_button_bet(31,34,true);

        ui->pushButton_31_plus_34->setFlat(false);
    }
    else
    {
        multi_button_bet(31,34,false);

        ui->pushButton_31_plus_34->setFlat(true);
    }
}

void MainWindow::on_pushButton_2_plus_5_clicked()
{
    if(ui->pushButton_2_plus_5->isFlat())
    {
        multi_button_bet(2,5,true);

        ui->pushButton_2_plus_5->setFlat(false);
    }
    else
    {
        multi_button_bet(2,5,false);

        ui->pushButton_2_plus_5->setFlat(true);
    }
}

void MainWindow::on_pushButton_5_plus_8_clicked()
{
    if(ui->pushButton_5_plus_8->isFlat())
    {
        multi_button_bet(5,8,true);

        ui->pushButton_5_plus_8->setFlat(false);
    }
    else
    {
        multi_button_bet(5,8,false);

        ui->pushButton_5_plus_8->setFlat(true);
    }
}

void MainWindow::on_pushButton_8_plus_11_clicked()
{
    if(ui->pushButton_8_plus_11->isFlat())
    {
        multi_button_bet(8,11,true);

        ui->pushButton_8_plus_11->setFlat(false);
    }
    else
    {
        multi_button_bet(8,11,false);

        ui->pushButton_8_plus_11->setFlat(true);
    }
}

void MainWindow::on_pushButton_11_plus_14_clicked()
{
    if(ui->pushButton_11_plus_14->isFlat())
    {
        multi_button_bet(11,13,true);

        ui->pushButton_11_plus_14->setFlat(false);
    }
    else
    {
        multi_button_bet(11,13,false);

        ui->pushButton_11_plus_14->setFlat(true);
    }
}

void MainWindow::on_pushButton_14_plus_17_clicked()
{
    if(ui->pushButton_14_plus_17->isFlat())
    {
        multi_button_bet(14,17,true);

        ui->pushButton_14_plus_17->setFlat(false);
    }
    else
    {
        multi_button_bet(14,17,false);

        ui->pushButton_14_plus_17->setFlat(true);
    }
}

void MainWindow::on_pushButton_17_plus_20_clicked()
{
    if(ui->pushButton_17_plus_20->isFlat())
    {
        multi_button_bet(17,20,true);

        ui->pushButton_17_plus_20->setFlat(false);
    }
    else
    {
        multi_button_bet(17,20,false);

        ui->pushButton_17_plus_20->setFlat(true);
    }
}

void MainWindow::on_pushButton_20_plus_23_clicked()
{
    if(ui->pushButton_20_plus_23->isFlat())
    {
        multi_button_bet(20,23,true);

        ui->pushButton_20_plus_23->setFlat(false);
    }
    else
    {
        multi_button_bet(20,23,false);

        ui->pushButton_20_plus_23->setFlat(true);
    }
}

void MainWindow::on_pushButton_23_plus_26_clicked()
{
    if(ui->pushButton_23_plus_26->isFlat())
    {
        multi_button_bet(23,26,true);

        ui->pushButton_23_plus_26->setFlat(false);
    }
    else
    {
        multi_button_bet(23,26,false);

        ui->pushButton_23_plus_26->setFlat(true);
    }
}

void MainWindow::on_pushButton_26_plus_29_clicked()
{
    if(ui->pushButton_26_plus_29->isFlat())
    {
        multi_button_bet(26,29,true);

        ui->pushButton_26_plus_29->setFlat(false);
    }
    else
    {
        multi_button_bet(26,29,false);

        ui->pushButton_26_plus_29->setFlat(true);
    }
}

void MainWindow::on_pushButton_29_plus_32_clicked()
{
    if(ui->pushButton_29_plus_32->isFlat())
    {
        multi_button_bet(29,32,true);

        ui->pushButton_29_plus_32->setFlat(false);
    }
    else
    {
        multi_button_bet(29,32,false);

        ui->pushButton_29_plus_32->setFlat(true);
    }
}

void MainWindow::on_pushButton_32_plus_35_clicked()
{
    if(ui->pushButton_32_plus_35->isFlat())
    {
        multi_button_bet(32,35,true);

        ui->pushButton_32_plus_35->setFlat(false);
    }
    else
    {
        multi_button_bet(32,35,false);

        ui->pushButton_32_plus_35->setFlat(true);
    }
}

void MainWindow::on_pushButton_3_plus_6_clicked()
{
    if(ui->pushButton_3_plus_6->isFlat())
    {
        multi_button_bet(3,6,true);

        ui->pushButton_3_plus_6->setFlat(false);
    }
    else
    {
        multi_button_bet(3,6,false);

        ui->pushButton_3_plus_6->setFlat(true);
    }
}

void MainWindow::on_pushButton_6_plus_9_clicked()
{
    if(ui->pushButton_6_plus_9->isFlat())
    {
        multi_button_bet(6,9,true);

        ui->pushButton_6_plus_9->setFlat(false);
    }
    else
    {
        multi_button_bet(6,9,false);

        ui->pushButton_6_plus_9->setFlat(true);
    }
}

void MainWindow::on_pushButton_9_plus_12_clicked()
{
    if(ui->pushButton_9_plus_12->isFlat())
    {
        multi_button_bet(9,12,true);

        ui->pushButton_9_plus_12->setFlat(false);
    }
    else
    {
        multi_button_bet(9,12,false);

        ui->pushButton_9_plus_12->setFlat(true);
    }
}

void MainWindow::on_pushButton_12_plus_15_clicked()
{
    if(ui->pushButton_12_plus_15->isFlat())
    {
        multi_button_bet(12,15,true);

        ui->pushButton_12_plus_15->setFlat(false);
    }
    else
    {
        multi_button_bet(12,15,false);

        ui->pushButton_12_plus_15->setFlat(true);
    }
}

void MainWindow::on_pushButton_15_plus_18_clicked()
{
    if(ui->pushButton_15_plus_18->isFlat())
    {
        multi_button_bet(15,18,true);

        ui->pushButton_15_plus_18->setFlat(false);
    }
    else
    {
        multi_button_bet(15,18,false);

        ui->pushButton_15_plus_18->setFlat(true);
    }
}

void MainWindow::on_pushButton_18_plus_21_clicked()
{
    if(ui->pushButton_18_plus_21->isFlat())
    {
        multi_button_bet(18,21,true);

        ui->pushButton_18_plus_21->setFlat(false);
    }
    else
    {
        multi_button_bet(18,21,false);

        ui->pushButton_18_plus_21->setFlat(true);
    }
}

void MainWindow::on_pushButton_21_plus_24_clicked()
{
    if(ui->pushButton_21_plus_24->isFlat())
    {
        multi_button_bet(21,24,true);

        ui->pushButton_21_plus_24->setFlat(false);
    }
    else
    {
        multi_button_bet(21,24,false);

        ui->pushButton_21_plus_24->setFlat(true);
    }
}

void MainWindow::on_pushButton_24_plus_27_clicked()
{
    if(ui->pushButton_24_plus_27->isFlat())
    {
        multi_button_bet(24,27,true);

        ui->pushButton_24_plus_27->setFlat(false);
    }
    else
    {
        multi_button_bet(24,27,false);

        ui->pushButton_24_plus_27->setFlat(true);
    }
}

void MainWindow::on_pushButton_27_plus_30_clicked()
{
    if(ui->pushButton_27_plus_30->isFlat())
    {
        multi_button_bet(27,30,true);

        ui->pushButton_27_plus_30->setFlat(false);
    }
    else
    {
        multi_button_bet(27,30,false);

        ui->pushButton_27_plus_30->setFlat(true);
    }
}

void MainWindow::on_pushButton_30_plus_33_clicked()
{
    if(ui->pushButton_30_plus_33->isFlat())
    {
        multi_button_bet(30,33,true);

        ui->pushButton_30_plus_33->setFlat(false);
    }
    else
    {
        multi_button_bet(30,33,false);

        ui->pushButton_30_plus_33->setFlat(true);
    }
}

void MainWindow::on_pushButton_33_plus_36_clicked()
{
    if(ui->pushButton_33_plus_36->isFlat())
    {
        multi_button_bet(33,36,true);

        ui->pushButton_33_plus_36->setFlat(false);
    }
    else
    {
        multi_button_bet(33,36,false);

        ui->pushButton_33_plus_36->setFlat(true);
    }
}

void MainWindow::on_pushButton_1_plus_4_2_5_clicked()
{
    if(ui->pushButton_1_plus_4_2_5->isFlat())
    {
        multi_button_bet(1,5,true);

        ui->pushButton_1_plus_4_2_5->setFlat(false);
    }
    else
    {
        multi_button_bet(1,5,false);

        ui->pushButton_1_plus_4_2_5->setFlat(true);
    }
}

void MainWindow::on_pushButton_2_plus_5_3_6_clicked()
{
    if(ui->pushButton_2_plus_5_3_6->isFlat())
    {
        multi_button_bet(2,6,true);

        ui->pushButton_2_plus_5_3_6->setFlat(false);
    }
    else
    {
        multi_button_bet(2,6,false);

        ui->pushButton_2_plus_5_3_6->setFlat(true);
    }
}

void MainWindow::on_pushButton_5_plus_8_6_9_clicked()
{
    if(ui->pushButton_5_plus_8_6_9->isFlat())
    {
        multi_button_bet(5,9,true);

        ui->pushButton_5_plus_8_6_9->setFlat(false);
    }
    else
    {
        multi_button_bet(5,9,false);

        ui->pushButton_5_plus_8_6_9->setFlat(true);
    }
}

void MainWindow::on_pushButton_4_plus_7_5_8_clicked()
{
    if(ui->pushButton_4_plus_7_5_8->isFlat())
    {
        multi_button_bet(4,8,true);

        ui->pushButton_4_plus_7_5_8->setFlat(false);
    }
    else
    {
        multi_button_bet(4,8,false);

        ui->pushButton_4_plus_7_5_8->setFlat(true);
    }
}

void MainWindow::on_pushButton_7_plus_10_8_11_clicked()
{
    if(ui->pushButton_7_plus_10_8_11->isFlat())
    {
        multi_button_bet(7,11,true);

        ui->pushButton_7_plus_10_8_11->setFlat(false);
    }
    else
    {
        multi_button_bet(7,11,false);

        ui->pushButton_7_plus_10_8_11->setFlat(true);
    }
}

void MainWindow::on_pushButton_8_plus_11_9_12_clicked()
{
    if(ui->pushButton_8_plus_11_9_12->isFlat())
    {
        multi_button_bet(8,12,true);

        ui->pushButton_8_plus_11_9_12->setFlat(false);
    }
    else
    {
        multi_button_bet(8,12,false);

        ui->pushButton_8_plus_11_9_12->setFlat(true);
    }
}

void MainWindow::on_pushButton_11_plus_14_12_15_clicked()
{
    if(ui->pushButton_11_plus_14_12_15->isFlat())
    {
        multi_button_bet(11,15,true);

        ui->pushButton_11_plus_14_12_15->setFlat(false);
    }
    else
    {
        multi_button_bet(11,15,false);

        ui->pushButton_11_plus_14_12_15->setFlat(true);
    }
}

void MainWindow::on_pushButton_10_plus_13_11_14_clicked()
{
    if(ui->pushButton_10_plus_13_11_14->isFlat())
    {
        multi_button_bet(10,14,true);

        ui->pushButton_10_plus_13_11_14->setFlat(false);
    }
    else
    {
        multi_button_bet(10,14,false);

        ui->pushButton_10_plus_13_11_14->setFlat(true);
    }
}

void MainWindow::on_pushButton_13_plus_16_14_17_clicked()
{
    if(ui->pushButton_13_plus_16_14_17->isFlat())
    {
        multi_button_bet(13,17,true);

        ui->pushButton_13_plus_16_14_17->setFlat(false);
    }
    else
    {
        multi_button_bet(13,17,false);

        ui->pushButton_13_plus_16_14_17->setFlat(true);
    }
}

void MainWindow::on_pushButton_14_plus_17_15_18_clicked()
{
    if(ui->pushButton_14_plus_17_15_18->isFlat())
    {
        multi_button_bet(14,18,true);

        ui->pushButton_14_plus_17_15_18->setFlat(false);
    }
    else
    {
        multi_button_bet(14,18,false);

        ui->pushButton_14_plus_17_15_18->setFlat(true);
    }
}

void MainWindow::on_pushButton_17_plus_20_18_21_clicked()
{
    if(ui->pushButton_17_plus_20_18_21->isFlat())
    {
        multi_button_bet(17,21,true);

        ui->pushButton_17_plus_20_18_21->setFlat(false);
    }
    else
    {
        multi_button_bet(17,21,false);

        ui->pushButton_17_plus_20_18_21->setFlat(true);
    }
}

void MainWindow::on_pushButton_16_plus_19_17_20_clicked()
{
    if(ui->pushButton_16_plus_19_17_20->isFlat())
    {
        multi_button_bet(16,20,true);

        ui->pushButton_16_plus_19_17_20->setFlat(false);
    }
    else
    {
        multi_button_bet(16,20,false);

        ui->pushButton_16_plus_19_17_20->setFlat(true);
    }
}

void MainWindow::on_pushButton_19_plus_22_20_23_clicked()
{
    if(ui->pushButton_19_plus_22_20_23->isFlat())
    {
        multi_button_bet(19,23,true);

        ui->pushButton_19_plus_22_20_23->setFlat(false);
    }
    else
    {
        multi_button_bet(19,23,false);

        ui->pushButton_19_plus_22_20_23->setFlat(true);
    }
}

void MainWindow::on_pushButton_20_plus_23_21_24_clicked()
{
    if(ui->pushButton_20_plus_23_21_24->isFlat())
    {
        multi_button_bet(20,24,true);

        ui->pushButton_20_plus_23_21_24->setFlat(false);
    }
    else
    {
        multi_button_bet(20,24,false);

        ui->pushButton_20_plus_23_21_24->setFlat(true);
    }
}

void MainWindow::on_pushButton_22_plus_25_23_26_clicked()
{
    if(ui->pushButton_22_plus_25_23_26->isFlat())
    {
        multi_button_bet(22,26,true);

        ui->pushButton_22_plus_25_23_26->setFlat(false);
    }
    else
    {
        multi_button_bet(22,26,false);

        ui->pushButton_22_plus_25_23_26->setFlat(true);
    }
}

void MainWindow::on_pushButton_23_plus_26_24_27_clicked()
{
    if(ui->pushButton_23_plus_26_24_27->isFlat())
    {
        multi_button_bet(23,27,true);

        ui->pushButton_23_plus_26_24_27->setFlat(false);
    }
    else
    {
        multi_button_bet(23,27,false);

        ui->pushButton_23_plus_26_24_27->setFlat(true);
    }
}

void MainWindow::on_pushButton_25_plus_28_26_29_clicked()
{
    if(ui->pushButton_25_plus_28_26_29->isFlat())
    {
        multi_button_bet(25,29,true);

        ui->pushButton_25_plus_28_26_29->setFlat(false);
    }
    else
    {
        multi_button_bet(25,29,false);

        ui->pushButton_25_plus_28_26_29->setFlat(true);
    }
}

void MainWindow::on_pushButton_26_plus_29_27_30_clicked()
{
    if(ui->pushButton_26_plus_29_27_30->isFlat())
    {
        multi_button_bet(26,30,true);

        ui->pushButton_26_plus_29_27_30->setFlat(false);
    }
    else
    {
        multi_button_bet(26,30,false);

        ui->pushButton_26_plus_29_27_30->setFlat(true);
    }
}

void MainWindow::on_pushButton_29_plus_32_30_33_clicked()
{
    if(ui->pushButton_29_plus_32_30_33->isFlat())
    {
        multi_button_bet(29,33,true);

        ui->pushButton_29_plus_32_30_33->setFlat(false);
    }
    else
    {
        multi_button_bet(29,33,false);

        ui->pushButton_29_plus_32_30_33->setFlat(true);
    }
}

void MainWindow::on_pushButton_28_plus_31_29_32_clicked()
{
    if(ui->pushButton_28_plus_31_29_32->isFlat())
    {
        multi_button_bet(28,32,true);

        ui->pushButton_28_plus_31_29_32->setFlat(false);
    }
    else
    {
        multi_button_bet(28,32,false);

        ui->pushButton_28_plus_31_29_32->setFlat(true);
    }
}

void MainWindow::on_pushButton_31_plus_34_32_35_clicked()
{
    if(ui->pushButton_31_plus_34_32_35->isFlat())
    {
        multi_button_bet(31,35,true);

        ui->pushButton_31_plus_34_32_35->setFlat(false);
    }
    else
    {
        multi_button_bet(31,35,false);

        ui->pushButton_31_plus_34_32_35->setFlat(true);
    }
}

void MainWindow::on_pushButton_32_plus_35_33_36_clicked()
{
    if(ui->pushButton_32_plus_35_33_36->isFlat())
    {
        multi_button_bet(32,36,true);

        ui->pushButton_32_plus_35_33_36->setFlat(false);
    }
    else
    {
        multi_button_bet(32,36,false);

        ui->pushButton_32_plus_35_33_36->setFlat(true);
    }
}

void MainWindow::on_Bet_button1_clicked()
{
    ButtonIcon = QIcon(":/imgs/Chip_5.gif");
}

void MainWindow::on_Bet_button2_clicked()
{
    ButtonIcon = QIcon(":/imgs/Chip_10.gif");
}

void MainWindow::on_Bet_button3_clicked()
{
    ButtonIcon = QIcon(":/imgs/Chip_50.gif");
}

void MainWindow::on_Bet_button4_clicked()
{
    ButtonIcon = QIcon(":/imgs/Chip_100.gif");
}

void MainWindow::on_Bet_button5_clicked()
{
    ButtonIcon = QIcon(":/imgs/Chip_500.gif");
}

void MainWindow::on_Bet_button6_clicked()
{
    ButtonIcon = QIcon(":/imgs/Chip_1000.gif");
}

void MainWindow::on_Clear_Button_clicked()
{
    //clears all the bets
}

void MainWindow::on_pushButton_spin_clicked()
{
<<<<<<< HEAD
    n=1;

    check_num(n);
=======
    QMovie *movie = new QMovie("/home/aleksandar/Desktop/roulette working/NETB375_Roulette-master/netb375_roulette/img/roulette3.gif");
    ui->label_gif->setMovie(movie);
    movie->setSpeed(130);
    movie->start();
    
    n=rand()%38;
    check_color(n);
>>>>>>> origin/master
}
