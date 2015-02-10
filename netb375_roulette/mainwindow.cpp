#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QMovie>
#include <QThread>
#include "rules.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->rl.SetSaveLoadPath("/home/bloodcount/saves.txt");
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(refreshShowcase()));
    timer->start(1000);

    ui->setupUi(this);

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
    
    this->move(500, 150);//window positioning
    setStyleSheet("MainWindow {background-color:green};"); //setting background color only to MainWindow
    QPixmap pixmap(":/imgs/roulette3.gif");
    this->ButtonIcon = QIcon(":/imgs/Chip_5.gif");
    this->current_button_value = 5;
    ui->label_gif->setPixmap(pixmap); //setting an image for the spin button
}

MainWindow::~MainWindow()//Destructor
{
    delete ui;
}

QPushButton *currentbutton;//defines a pointer used by every function that covers multiple bet options

bool MainWindow::check_num()//creates and displayes a message to tell you which is the random number after a spin
{
    int symbol =   this->rl.finishRound();
    QString current_symbol;
    current_symbol.setNum(symbol);
    QMessageBox message1;
    message1.setText("The number is: "+current_symbol);
    message1.exec();
    return false;
}
/* This method takes an integer as a bet
 * this integers correspondes to a element in the array of buttons
 * makes the element flat, places a chip, resizes it, makes a bet and removes the text
 * This method doesn't return anything
 */

void MainWindow::single_button_bet(int x)
{
    this->rl.createBet(x, this->current_button_value, 37, true);
    array_to_buttons[x]->setText("");
    array_to_buttons[x]->setIcon(ButtonIcon);
    array_to_buttons[x]->setIconSize(QSize(40,40));
    array_to_buttons[x]->setFlat(true);
}

/* This method takes the first integer as first number in the bet,
 * takes an integer as the difference between the 2 or more bets,
 * takes an pointer to an object so that it would execute the code on that object
 * and takes the geometry of that object x,y, width and lenght
 * and a bool value for creating or removing the chip
 * makes the object flat, places a chip, resizes it, makes a bet and removes the text
 * This method doesn't return anything
 */

void MainWindow::multi_bet_animation(int x1,int d,QPushButton* currentbutton,int xg,int yg,int width,int lenght,bool add)
{
    if(d==1)
    {
        if(add)
        {
            this->rl.createBet(x1, this->current_button_value, 17, true);
            this->rl.createBet(x1+1, this->current_button_value, 17, false);
            currentbutton->setGeometry(xg+10,yg-18,width-21,lenght+32);
            currentbutton->setIcon(ButtonIcon);
            currentbutton->setIconSize(QSize(40,40));
            currentbutton->setFlat(true);
        }
        else
        {
            currentbutton->setGeometry(xg,yg,width,lenght);
            currentbutton->setIcon(QIcon());
            currentbutton->setFlat(false);
        }
    }
    else if(d==2)
    {
        if(add)
        {
            this->rl.createBet(x1, this->current_button_value, 11, true);
            this->rl.createBet(x1+1, this->current_button_value, 11, false);
            this->rl.createBet(x1+2, this->current_button_value, 11, false);
            currentbutton->setGeometry(xg+10,yg-18,width-21,lenght+32);
            currentbutton->setIcon(ButtonIcon);
            currentbutton->setIconSize(QSize(40,40));
            currentbutton->setFlat(true);
        }
        else
        {
            currentbutton->setGeometry(xg,yg,width,lenght);
            currentbutton->setIcon(QIcon());
            currentbutton->setFlat(false);
        }
    }
    else if(d==3)
    {
        if(add)
        {
            this->rl.createBet(x1, this->current_button_value, 17, true);
            this->rl.createBet(x1+3, this->current_button_value, 17, false);
            currentbutton->setGeometry(xg-16,yg+10,width+32,lenght-21);
            currentbutton->setIcon(ButtonIcon);
            currentbutton->setIconSize(QSize(40,40));
            currentbutton->setFlat(true);
        }
        else
        {
            currentbutton->setGeometry(xg,yg,width,lenght);
            currentbutton->setIcon(QIcon());
            currentbutton->setFlat(false);
        }
    }
    else if(d==4)
    {
        if(add)
        {
            this->rl.createBet(x1, this->current_button_value, 8, true);
            this->rl.createBet(x1+1, this->current_button_value, 8, false);
            this->rl.createBet(x1+3, this->current_button_value, 8, false);
            this->rl.createBet(x1+4, this->current_button_value, 8, false);
            currentbutton->setGeometry(xg-14,yg-13,width+28,lenght+28);
            currentbutton->setIcon(ButtonIcon);
            currentbutton->setIconSize(QSize(40,40));
            currentbutton->setFlat(true);
        }
        else
        {
            currentbutton->setGeometry(xg,yg,width,lenght);
            currentbutton->setIcon(QIcon());
            currentbutton->setFlat(false);
        }
    }
    else if(d==5)
    {
        if(add)
        {
            this->rl.createBet(x1, this->current_button_value, 5, true);
            this->rl.createBet(x1+1, this->current_button_value, 5, false);
            this->rl.createBet(x1+2, this->current_button_value, 5, false);
            this->rl.createBet(x1+3, this->current_button_value, 5, false);
            this->rl.createBet(x1+4, this->current_button_value, 5, false);
            this->rl.createBet(x1+5, this->current_button_value, 5, false);
            currentbutton->setGeometry(xg-14,yg-13,width+28,lenght+28);
            currentbutton->setIcon(ButtonIcon);
            currentbutton->setIconSize(QSize(40,40));
            currentbutton->setFlat(true);
        }
        else
        {
            currentbutton->setGeometry(xg,yg,width,lenght);
            currentbutton->setIcon(QIcon());
            currentbutton->setFlat(false);
        }
    }
    else if(d==11)
    {
        if(add)
        {
            this->rl.createBet(x1, this->current_button_value, 2, true);
            this->rl.createBet(x1+3, this->current_button_value, 2, false);
            this->rl.createBet(x1+6, this->current_button_value, 2, false);
            this->rl.createBet(x1+9, this->current_button_value, 2, false);
            this->rl.createBet(x1+12, this->current_button_value, 2, false);
            this->rl.createBet(x1+15, this->current_button_value, 2, false);
            this->rl.createBet(x1+18, this->current_button_value, 2, false);
            this->rl.createBet(x1+21, this->current_button_value, 2, false);
            this->rl.createBet(x1+24, this->current_button_value, 2, false);
            this->rl.createBet(x1+27, this->current_button_value, 2, false);
            this->rl.createBet(x1+30, this->current_button_value, 2, false);
            this->rl.createBet(x1+33, this->current_button_value, 2, false);
            currentbutton->setGeometry(xg-16,yg+10,width+32,lenght-21);
            currentbutton->setIcon(ButtonIcon);
            currentbutton->setIconSize(QSize(40,40));
            currentbutton->setFlat(true);
        }
        else
        {
            currentbutton->setGeometry(xg,yg,width,lenght);
            currentbutton->setIcon(QIcon());
            currentbutton->setFlat(false);
        }
    }
}

/* Every of the fallowing function are when a button is clicked they take no parameters
 * calls the method to make a single bet on the board with only the coresponding number to tbe button
 * This method doesn't return anything
 * Applies to all 37 single number buttons(bets)
 */

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

void MainWindow::on_pushButton_1_18_clicked()
{
        this->rl.createBet(1, this->current_button_value, 1, true );
        this->rl.createBet(2, this->current_button_value, 1, false );
        this->rl.createBet(3, this->current_button_value, 1, false );
        this->rl.createBet(4, this->current_button_value, 1, false );
        this->rl.createBet(5, this->current_button_value, 1, false );
        this->rl.createBet(6, this->current_button_value, 1, false );
        this->rl.createBet(7, this->current_button_value, 1, false );
        this->rl.createBet(8, this->current_button_value, 1, false );
        this->rl.createBet(9, this->current_button_value, 1, false );
        this->rl.createBet(10, this->current_button_value, 1, false );
        this->rl.createBet(11, this->current_button_value, 1, false );
        this->rl.createBet(12, this->current_button_value, 1, false );
        this->rl.createBet(13, this->current_button_value, 1, false );
        this->rl.createBet(14, this->current_button_value, 1, false );
        this->rl.createBet(15, this->current_button_value, 1, false );
        this->rl.createBet(16, this->current_button_value, 1, false );
        this->rl.createBet(17, this->current_button_value, 1, false );
        this->rl.createBet(18, this->current_button_value, 1, false );
        ui->pushButton_1_18->setText("");
        ui->pushButton_1_18->setIcon(ButtonIcon);
        ui->pushButton_1_18->setIconSize(QSize(40,40));
        ui->pushButton_1_18->setFlat(true);
}

void MainWindow::on_pushButton_19_36_clicked()
{
        this->rl.createBet(19, this->current_button_value, 1, true );
        this->rl.createBet(20, this->current_button_value, 1, false );
        this->rl.createBet(21, this->current_button_value, 1, false );
        this->rl.createBet(22, this->current_button_value, 1, false );
        this->rl.createBet(23, this->current_button_value, 1, false );
        this->rl.createBet(24, this->current_button_value, 1, false );
        this->rl.createBet(25, this->current_button_value, 1, false );
        this->rl.createBet(26, this->current_button_value, 1, false );
        this->rl.createBet(27, this->current_button_value, 1, false );
        this->rl.createBet(28, this->current_button_value, 1, false );
        this->rl.createBet(29, this->current_button_value, 1, false );
        this->rl.createBet(30, this->current_button_value, 1, false );
        this->rl.createBet(31, this->current_button_value, 1, false );
        this->rl.createBet(32, this->current_button_value, 1, false );
        this->rl.createBet(33, this->current_button_value, 1, false );
        this->rl.createBet(34, this->current_button_value, 1, false );
        this->rl.createBet(35, this->current_button_value, 1, false );
        this->rl.createBet(36, this->current_button_value, 1, false );
        ui->pushButton_19_36->setText("");
        ui->pushButton_19_36->setIcon(ButtonIcon);
        ui->pushButton_19_36->setIconSize(QSize(40,40));
        ui->pushButton_19_36->setFlat(true);
}

void MainWindow::on_pushButton_1st_clicked()
{
        this->rl.createBet(1, this->current_button_value, 2, true );
        this->rl.createBet(2, this->current_button_value, 2, false );
        this->rl.createBet(3, this->current_button_value, 2, false );
        this->rl.createBet(4, this->current_button_value, 2, false );
        this->rl.createBet(5, this->current_button_value, 2, false );
        this->rl.createBet(6, this->current_button_value, 2, false );
        this->rl.createBet(7, this->current_button_value, 2, false );
        this->rl.createBet(8, this->current_button_value, 2, false );
        this->rl.createBet(9, this->current_button_value, 2, false );
        this->rl.createBet(10, this->current_button_value, 2, false );
        this->rl.createBet(11, this->current_button_value, 2, false );
         this->rl.createBet(12, this->current_button_value, 2, false );
        ui->pushButton_1st->setText("");
        ui->pushButton_1st->setIcon(ButtonIcon);
        ui->pushButton_1st->setIconSize(QSize(40,40));
        ui->pushButton_1st->setFlat(true);
}
void MainWindow::on_pushButton_2nd_clicked()
{
        this->rl.createBet(13, this->current_button_value, 2, true );
        this->rl.createBet(14, this->current_button_value, 2, false );
        this->rl.createBet(15, this->current_button_value, 2, false );
        this->rl.createBet(16, this->current_button_value, 2, false );
        this->rl.createBet(17, this->current_button_value, 2, false );
        this->rl.createBet(18, this->current_button_value, 2, false );
        this->rl.createBet(19, this->current_button_value, 2, false );
        this->rl.createBet(20, this->current_button_value, 2, false );
        this->rl.createBet(21, this->current_button_value, 2, false );
        this->rl.createBet(22, this->current_button_value, 2, false );
        this->rl.createBet(23, this->current_button_value, 2, false );
        this->rl.createBet(24, this->current_button_value, 2, false );
        ui->pushButton_2nd->setText("");
        ui->pushButton_2nd->setIcon(ButtonIcon);
        ui->pushButton_2nd->setIconSize(QSize(40,40));
        ui->pushButton_2nd->setFlat(true);
}

void MainWindow::on_pushButton_3rd_clicked()
{
        this->rl.createBet(25, this->current_button_value, 2, true );
        this->rl.createBet(26, this->current_button_value, 2, false );
        this->rl.createBet(27, this->current_button_value, 2, false );
        this->rl.createBet(28, this->current_button_value, 2, false );
        this->rl.createBet(29, this->current_button_value, 2, false );
        this->rl.createBet(30, this->current_button_value, 2, false );
        this->rl.createBet(31, this->current_button_value, 2, false );
        this->rl.createBet(32, this->current_button_value, 2, false );
        this->rl.createBet(33, this->current_button_value, 2, false );
        this->rl.createBet(34, this->current_button_value, 2, false );
        this->rl.createBet(35, this->current_button_value, 2, false );
        this->rl.createBet(36, this->current_button_value, 2, false );
        ui->pushButton_3rd->setText("");
        ui->pushButton_3rd->setIcon(ButtonIcon);
        ui->pushButton_3rd->setIconSize(QSize(40,40));
        ui->pushButton_3rd->setFlat(true);
}

void MainWindow::on_pushButton_even_clicked()
{
        this->rl.createBet(2, this->current_button_value, 1, true );
        this->rl.createBet(4, this->current_button_value, 1, false );
        this->rl.createBet(6, this->current_button_value, 1, false );
        this->rl.createBet(8, this->current_button_value, 1, false );
        this->rl.createBet(10, this->current_button_value, 1, false );
        this->rl.createBet(12, this->current_button_value, 1, false );
        this->rl.createBet(14, this->current_button_value, 1, false );
        this->rl.createBet(16, this->current_button_value, 1, false );
        this->rl.createBet(18, this->current_button_value, 1, false );
        this->rl.createBet(20, this->current_button_value, 1, false );
        this->rl.createBet(22, this->current_button_value, 1, false );
        this->rl.createBet(24, this->current_button_value, 1, false );
        this->rl.createBet(26, this->current_button_value, 1, false );
        this->rl.createBet(28, this->current_button_value, 1, false );
        this->rl.createBet(30, this->current_button_value, 1, false );
        this->rl.createBet(32, this->current_button_value, 1, false );
        this->rl.createBet(34, this->current_button_value, 1, false );
        this->rl.createBet(36, this->current_button_value, 1, false );
        ui->pushButton_even->setText("");
        ui->pushButton_even->setIcon(ButtonIcon);
        ui->pushButton_even->setIconSize(QSize(40,40));
        ui->pushButton_even->setFlat(true);
}

void MainWindow::on_pushButton_odd_clicked()
{
        this->rl.createBet(1, this->current_button_value, 1, true );
        this->rl.createBet(3, this->current_button_value, 1, false );
        this->rl.createBet(5, this->current_button_value, 1, false );
        this->rl.createBet(7, this->current_button_value, 1, false );
        this->rl.createBet(9, this->current_button_value, 1, false );
        this->rl.createBet(11, this->current_button_value, 1, false );
        this->rl.createBet(13, this->current_button_value, 1, false );
        this->rl.createBet(15, this->current_button_value, 1, false );
        this->rl.createBet(17, this->current_button_value, 1, false );
        this->rl.createBet(19, this->current_button_value, 1, true );
        this->rl.createBet(21, this->current_button_value, 1, false );
        this->rl.createBet(23, this->current_button_value, 1, false );
        this->rl.createBet(25, this->current_button_value, 1, false );
        this->rl.createBet(27, this->current_button_value, 1, false );
        this->rl.createBet(29, this->current_button_value, 1, false );
        this->rl.createBet(31, this->current_button_value, 1, false );
        this->rl.createBet(33, this->current_button_value, 1, false );
        this->rl.createBet(35, this->current_button_value, 1, false );
        ui->pushButton_odd->setText("");
        ui->pushButton_odd->setIcon(ButtonIcon);
        ui->pushButton_odd->setIconSize(QSize(40,40));
        ui->pushButton_odd->setFlat(true);
}

void MainWindow::on_redButton_red_clicked()
{
        this->rl.createBet(1, this->current_button_value, 1, true );
        this->rl.createBet(3, this->current_button_value, 1, false );
        this->rl.createBet(5, this->current_button_value, 1, false );
        this->rl.createBet(7, this->current_button_value, 1, false );
        this->rl.createBet(9, this->current_button_value, 1, false );
        this->rl.createBet(12, this->current_button_value, 1, false );
        this->rl.createBet(14, this->current_button_value, 1, false );
        this->rl.createBet(16, this->current_button_value, 1, false );
        this->rl.createBet(18, this->current_button_value, 1, false );
        this->rl.createBet(19, this->current_button_value, 1, false );
        this->rl.createBet(21, this->current_button_value, 1, false );
        this->rl.createBet(23, this->current_button_value, 1, false );
        this->rl.createBet(25, this->current_button_value, 1, false );
        this->rl.createBet(27, this->current_button_value, 1, false );
        this->rl.createBet(30, this->current_button_value, 1, false );
        this->rl.createBet(32, this->current_button_value, 1, false );
        this->rl.createBet(34, this->current_button_value, 1, false );
        this->rl.createBet(36, this->current_button_value, 1, false );
        ui->redButton_red->setText("");
        ui->redButton_red->setIcon(ButtonIcon);
        ui->redButton_red->setIconSize(QSize(40,40));
        ui->redButton_red->setFlat(true);
}

void MainWindow::on_pushButton_black_clicked()
{
        this->rl.createBet(2, this->current_button_value, 1, true );
        this->rl.createBet(4, this->current_button_value, 1, false );
        this->rl.createBet(6, this->current_button_value, 1, false );
        this->rl.createBet(8, this->current_button_value, 1, false );
        this->rl.createBet(10, this->current_button_value, 1, false );
        this->rl.createBet(11, this->current_button_value, 1, false );
        this->rl.createBet(13, this->current_button_value, 1, false );
        this->rl.createBet(15, this->current_button_value, 1, false );
        this->rl.createBet(17, this->current_button_value, 1, false );
        this->rl.createBet(20, this->current_button_value, 1, false );
        this->rl.createBet(22, this->current_button_value, 1, false );
        this->rl.createBet(24, this->current_button_value, 1, false );
        this->rl.createBet(26, this->current_button_value, 1, false );
        this->rl.createBet(28, this->current_button_value, 1, false );
        this->rl.createBet(29, this->current_button_value, 1, false );
        this->rl.createBet(31, this->current_button_value, 1, false );
        this->rl.createBet(33, this->current_button_value, 1, false );
        this->rl.createBet(35, this->current_button_value, 1, false );
        ui->pushButton_black->setText("");
        ui->pushButton_black->setIcon(ButtonIcon);
        ui->pushButton_black->setIconSize(QSize(40,40));
        ui->pushButton_black->setFlat(true);
}
/* Sets the currentbutton pointer to coresponding pointer of tbe button
 * and calls the multi_bet_animation method with parameters specific to this button
 * takes no arguments and this method doesn't return anything
 * Apllies to all the multiple bet options
*/
void MainWindow::on_pushButton_1_plus_2_clicked()
{
        currentbutton = ui->pushButton_1_plus_2;
        multi_bet_animation(1,1,currentbutton,100,243,61,8,true);
}

void MainWindow::on_pushButton_2_plus_3_clicked()
{
        currentbutton = ui->pushButton_2_plus_3;
        multi_bet_animation(2,1,currentbutton,100,176,61,8,true);
}

void MainWindow::on_pushButton_4_plus_5_clicked()
{
        currentbutton =  ui->pushButton_4_plus_5;
        multi_bet_animation(4,1,currentbutton,167,243,61,8,true);
}

void MainWindow::on_pushButton_5_plus_6_clicked()
{
        currentbutton = ui->pushButton_5_plus_6;
        multi_bet_animation(5,1,currentbutton,167,176,61,8,true);
}

void MainWindow::on_pushButton_7_plus_8_clicked()
{
        currentbutton = ui->pushButton_7_plus_8;
        multi_bet_animation(7,1,currentbutton,234,242,61,8,true);
}

void MainWindow::on_pushButton_8_plus_9_clicked()
{
        currentbutton =  ui->pushButton_8_plus_9;
        multi_bet_animation(8,1,currentbutton,234,175,61,8,true);
}

void MainWindow::on_pushButton_10_plus_11_clicked()
{
        currentbutton = ui->pushButton_10_plus_11;
        multi_bet_animation(10,1,currentbutton,301,242,61,8,true);
}

void MainWindow::on_pushButton_11_plus_12_clicked()
{
        currentbutton = ui->pushButton_11_plus_12;
        multi_bet_animation(11,1,currentbutton,301,175,61,8,true);
}

void MainWindow::on_pushButton_13_plus_14_clicked()
{
        currentbutton = ui->pushButton_13_plus_14;
        multi_bet_animation(13,1,currentbutton,368,241,61,8,true);
}

void MainWindow::on_pushButton_14_plus_15_clicked()
{
        currentbutton = ui->pushButton_14_plus_15;
        multi_bet_animation(14,1,currentbutton,368,174,61,8,true);
}

void MainWindow::on_pushButton_16_plus_17_clicked()
{
        currentbutton = ui->pushButton_16_plus_17;
        multi_bet_animation(16,1,currentbutton,435,241,61,8,true);
}

void MainWindow::on_pushButton_17_plus_18_clicked()
{
        currentbutton = ui->pushButton_17_plus_18;
        multi_bet_animation(17,1,currentbutton,435,174,61,8,true);
}

void MainWindow::on_pushButton_19_plus_20_clicked()
{
        currentbutton = ui->pushButton_19_plus_20;
        multi_bet_animation(19,1,currentbutton,503,241,61,8,true);
}

void MainWindow::on_pushButton_20_plus_21_clicked()
{
        currentbutton = ui->pushButton_20_plus_21;
        multi_bet_animation(20,1,currentbutton,503,174,61,8,true);
}

void MainWindow::on_pushButton_22_plus_23_clicked()
{
        currentbutton = ui->pushButton_22_plus_23;
        multi_bet_animation(22,1,currentbutton,570,241,61,8,true);
}

void MainWindow::on_pushButton_23_plus_24_clicked()
{
        currentbutton = ui->pushButton_23_plus_24;
        multi_bet_animation(23,1,currentbutton,570,174,61,8,true);
}

void MainWindow::on_pushButton_25_plus_26_clicked()
{
        currentbutton = ui->pushButton_25_plus_26;
        multi_bet_animation(25,1,currentbutton,637,241,61,8,true);
}

void MainWindow::on_pushButton_26_plus_27_clicked()
{
        currentbutton = ui->pushButton_26_plus_27;
        multi_bet_animation(26,1,currentbutton,637,174,61,8,true);
}

void MainWindow::on_pushButton_28_plus_29_clicked()
{
        currentbutton = ui->pushButton_28_plus_29;
        multi_bet_animation(28,1,currentbutton,704,241,61,8,true);
}

void MainWindow::on_pushButton_29_plus_30_clicked()
{
        currentbutton = ui->pushButton_29_plus_30;
        multi_bet_animation(29,1,currentbutton,704,174,61,8,true);
}

void MainWindow::on_pushButton_31_plus_32_clicked()
{
        currentbutton = ui->pushButton_31_plus_32;
        multi_bet_animation(31,1,currentbutton,771,241,61,8,true);
}

void MainWindow::on_pushButton_32_plus_33_clicked()
{
        currentbutton = ui->pushButton_32_plus_33;
        multi_bet_animation(32,1,currentbutton,771,174,61,8,true);
}

void MainWindow::on_pushButton_34_plus_35_clicked()
{
        currentbutton = ui->pushButton_34_plus_35;
        multi_bet_animation(34,1,currentbutton,838,241,61,8,true);
}

void MainWindow::on_pushButton_35_plus_36_clicked()
{
        currentbutton = ui->pushButton_35_plus_36;
        multi_bet_animation(35,1,currentbutton,838,174,61,8,true);
}

void MainWindow::on_pushButton_1_plus_4_clicked()
{
        currentbutton = ui->pushButton_1_plus_4;
        multi_bet_animation(1,3,currentbutton,160,250,8,61,true);
}

void MainWindow::on_pushButton_4_plus_7_clicked()
{
        currentbutton = ui->pushButton_4_plus_7;
        multi_bet_animation(4,3,currentbutton,227,250,8,61,true);
}

void MainWindow::on_pushButton_7_plus_10_clicked()
{
        currentbutton = ui->pushButton_7_plus_10;
        multi_bet_animation(7,3,currentbutton,294,250,8,61,true);
}

void MainWindow::on_pushButton_10_plus_13_clicked()
{
        currentbutton = ui->pushButton_10_plus_13;
        multi_bet_animation(10,3,currentbutton,362,250,8,61,true);
}

void MainWindow::on_pushButton_13_plus_16_clicked()
{
        currentbutton = ui->pushButton_13_plus_16;
        multi_bet_animation(13,3,currentbutton,429,250,8,61,true);
}

void MainWindow::on_pushButton_16_plus_19_clicked()
{
        currentbutton = ui->pushButton_16_plus_19;
        multi_bet_animation(16,3,currentbutton,496,250,8,61,true);
}

void MainWindow::on_pushButton_19_plus_22_clicked()
{
        currentbutton = ui->pushButton_19_plus_22;
        multi_bet_animation(19,3,currentbutton,563,250,8,61,true);
}

void MainWindow::on_pushButton_22_plus_25_clicked()
{
        currentbutton = ui->pushButton_22_plus_25;
        multi_bet_animation(22,3,currentbutton,630,250,8,61,true);
}

void MainWindow::on_pushButton_25_plus_28_clicked()
{
        currentbutton = ui->pushButton_25_plus_28;
        multi_bet_animation(25,3,currentbutton,697,250,8,61,true);
}

void MainWindow::on_pushButton_28_plus_31_clicked()
{
        currentbutton = ui->pushButton_28_plus_31;
        multi_bet_animation(28,3,currentbutton,764,250,8,61,true);
}

void MainWindow::on_pushButton_31_plus_34_clicked()
{
        currentbutton = ui->pushButton_31_plus_34;
        multi_bet_animation(31,3,currentbutton,831,250,8,61,true);
}

void MainWindow::on_pushButton_2_plus_5_clicked()
{
        currentbutton = ui->pushButton_2_plus_5;
        multi_bet_animation(2,3,currentbutton,160,181,8,61,true);
}

void MainWindow::on_pushButton_5_plus_8_clicked()
{
        currentbutton = ui->pushButton_5_plus_8;
        multi_bet_animation(5,3,currentbutton,227,181,8,61,true);
}

void MainWindow::on_pushButton_8_plus_11_clicked()
{
        currentbutton = ui->pushButton_8_plus_11;
        multi_bet_animation(8,3,currentbutton,294,181,8,61,true);
}

void MainWindow::on_pushButton_11_plus_14_clicked()
{
        currentbutton = ui->pushButton_11_plus_14;
        multi_bet_animation(11,3,currentbutton,362,181,8,61,true);
}

void MainWindow::on_pushButton_14_plus_17_clicked()
{
        currentbutton = ui->pushButton_14_plus_17;
        multi_bet_animation(14,3,currentbutton,429,181,8,61,true);
}

void MainWindow::on_pushButton_17_plus_20_clicked()
{
        currentbutton = ui->pushButton_17_plus_20;
        multi_bet_animation(17,3,currentbutton,496,181,8,61,true);
}

void MainWindow::on_pushButton_20_plus_23_clicked()
{
        currentbutton =  ui->pushButton_20_plus_23;
        multi_bet_animation(20,3,currentbutton,563,181,8,61,true);
}

void MainWindow::on_pushButton_23_plus_26_clicked()
{
        currentbutton =  ui->pushButton_23_plus_26;
        multi_bet_animation(23,3,currentbutton,630,181,8,61,true);
}

void MainWindow::on_pushButton_26_plus_29_clicked()
{
        currentbutton =  ui->pushButton_26_plus_29;
        multi_bet_animation(26,3,currentbutton,697,181,8,61,true);
}

void MainWindow::on_pushButton_29_plus_32_clicked()
{
        currentbutton =  ui->pushButton_29_plus_32;
        multi_bet_animation(29,3,currentbutton,764,181,8,61,true);
}

void MainWindow::on_pushButton_32_plus_35_clicked()
{
        currentbutton =  ui->pushButton_32_plus_35;
        multi_bet_animation(32,3,currentbutton,831,181,8,61,true);
}

void MainWindow::on_pushButton_3_plus_6_clicked()
{
        currentbutton =  ui->pushButton_3_plus_6;
        multi_bet_animation(3,3,currentbutton,160,113,8,61,true);
}

void MainWindow::on_pushButton_6_plus_9_clicked()
{
        currentbutton =  ui->pushButton_6_plus_9;
        multi_bet_animation(6,3,currentbutton,227,113,8,61,true);
}

void MainWindow::on_pushButton_9_plus_12_clicked()
{
        currentbutton =  ui->pushButton_9_plus_12;
        multi_bet_animation(9,3,currentbutton,294,113,8,61,true);
}

void MainWindow::on_pushButton_12_plus_15_clicked()
{
        currentbutton =  ui->pushButton_12_plus_15;
        multi_bet_animation(12,3,currentbutton,362,113,8,61,true);
}

void MainWindow::on_pushButton_15_plus_18_clicked()
{
        currentbutton =  ui->pushButton_15_plus_18;
        multi_bet_animation(15,3,currentbutton,429,113,8,61,true);
}

void MainWindow::on_pushButton_18_plus_21_clicked()
{
        currentbutton =  ui->pushButton_18_plus_21;
        multi_bet_animation(18,3,currentbutton,496,113,8,61,true);
}

void MainWindow::on_pushButton_21_plus_24_clicked()
{
        currentbutton =  ui->pushButton_21_plus_24;
        multi_bet_animation(21,3,currentbutton,563,113,8,61,true);
}

void MainWindow::on_pushButton_24_plus_27_clicked()
{
        currentbutton =  ui->pushButton_24_plus_27;
        multi_bet_animation(24,3,currentbutton,630,113,8,61,true);
}

void MainWindow::on_pushButton_27_plus_30_clicked()
{
        currentbutton =  ui->pushButton_27_plus_30;
        multi_bet_animation(27,3,currentbutton,697,113,8,61,true);
}

void MainWindow::on_pushButton_30_plus_33_clicked()
{
        currentbutton =  ui->pushButton_30_plus_33;
        multi_bet_animation(30,3,currentbutton,764,113,8,61,true);
}

void MainWindow::on_pushButton_33_plus_36_clicked()
{
        currentbutton =  ui->pushButton_33_plus_36;
        multi_bet_animation(33,3,currentbutton,831,113,8,61,true);
}

void MainWindow::on_pushButton_1_plus_4_2_5_clicked()
{
        currentbutton = ui->pushButton_1_plus_4_2_5;
        multi_bet_animation(1,4,currentbutton,158,240,12,12,true);
}

void MainWindow::on_pushButton_2_plus_5_3_6_clicked()
{
        currentbutton = ui->pushButton_2_plus_5_3_6;
        multi_bet_animation(2,4,currentbutton,158,173,12,12,true);
}

void MainWindow::on_pushButton_5_plus_8_6_9_clicked()
{
        currentbutton = ui->pushButton_5_plus_8_6_9;
        multi_bet_animation(5,4,currentbutton,225,173,12,12,true);
}

void MainWindow::on_pushButton_4_plus_7_5_8_clicked()
{
        currentbutton = ui->pushButton_4_plus_7_5_8;
        multi_bet_animation(4,4,currentbutton,225,240,12,12,true);
}

void MainWindow::on_pushButton_7_plus_10_8_11_clicked()
{
        currentbutton = ui->pushButton_7_plus_10_8_11;
        multi_bet_animation(7,4,currentbutton,292,240,12,12,true);
}

void MainWindow::on_pushButton_8_plus_11_9_12_clicked()
{
        currentbutton = ui->pushButton_8_plus_11_9_12;
        multi_bet_animation(8,4,currentbutton,292,173,12,12,true);
}

void MainWindow::on_pushButton_11_plus_14_12_15_clicked()
{
        currentbutton = ui->pushButton_11_plus_14_12_15;
        multi_bet_animation(11,4,currentbutton,360,173,12,12,true);
}

void MainWindow::on_pushButton_10_plus_13_11_14_clicked()
{
        currentbutton = ui->pushButton_10_plus_13_11_14;
        multi_bet_animation(10,4,currentbutton,360,240,12,12,true);
}

void MainWindow::on_pushButton_13_plus_16_14_17_clicked()
{
        currentbutton = ui->pushButton_13_plus_16_14_17;
        multi_bet_animation(13,4,currentbutton,426,240,12,12,true);
}

void MainWindow::on_pushButton_14_plus_17_15_18_clicked()
{
        currentbutton = ui->pushButton_14_plus_17_15_18;
        multi_bet_animation(14,4,currentbutton,426,173,12,12,true);
}

void MainWindow::on_pushButton_17_plus_20_18_21_clicked()
{
        currentbutton = ui->pushButton_17_plus_20_18_21;
        multi_bet_animation(17,4,currentbutton,493,173,12,12,true);
}

void MainWindow::on_pushButton_16_plus_19_17_20_clicked()
{
        currentbutton = ui->pushButton_16_plus_19_17_20;
        multi_bet_animation(16,4,currentbutton,493,240,12,12,true);
}

void MainWindow::on_pushButton_19_plus_22_20_23_clicked()
{
        currentbutton = ui->pushButton_19_plus_22_20_23;
        multi_bet_animation(19,4,currentbutton,561,240,12,12,true);
}

void MainWindow::on_pushButton_20_plus_23_21_24_clicked()
{
        currentbutton = ui->pushButton_20_plus_23_21_24;
        multi_bet_animation(20,4,currentbutton,561,173,12,12,true);
}

void MainWindow::on_pushButton_22_plus_25_23_26_clicked()
{
        currentbutton = ui->pushButton_22_plus_25_23_26;
        multi_bet_animation(22,4,currentbutton,628,239,12,12,true);
}

void MainWindow::on_pushButton_23_plus_26_24_27_clicked()
{
        currentbutton = ui->pushButton_23_plus_26_24_27;
        multi_bet_animation(23,4,currentbutton,628,173,12,12,true);
}

void MainWindow::on_pushButton_25_plus_28_26_29_clicked()
{
        currentbutton = ui->pushButton_25_plus_28_26_29;
        multi_bet_animation(25,4,currentbutton,695,240,12,12,true);
}

void MainWindow::on_pushButton_26_plus_29_27_30_clicked()
{
        currentbutton = ui->pushButton_26_plus_29_27_30;
        multi_bet_animation(26,4,currentbutton,695,173,12,12,true);
}

void MainWindow::on_pushButton_29_plus_32_30_33_clicked()
{
        currentbutton = ui->pushButton_29_plus_32_30_33;
        multi_bet_animation(29,4,currentbutton,762,173,12,12,true);
}

void MainWindow::on_pushButton_28_plus_31_29_32_clicked()
{
        currentbutton = ui->pushButton_28_plus_31_29_32;
        multi_bet_animation(28,4,currentbutton,762,240,12,12,true);
}

void MainWindow::on_pushButton_31_plus_34_32_35_clicked()
{
        currentbutton = ui->pushButton_31_plus_34_32_35;
        multi_bet_animation(31,4,currentbutton,829,240,12,12,true);
}

void MainWindow::on_pushButton_32_plus_35_33_36_clicked()
{
        currentbutton = ui->pushButton_32_plus_35_33_36;
        multi_bet_animation(32,4,currentbutton,829,173,12,12,true);
}

void MainWindow::on_pushButton_street_1_clicked()
{
        currentbutton = ui->pushButton_street_1;
        multi_bet_animation(1,2,currentbutton,99,311,61,8,true);
}

void MainWindow::on_pushButton_street_2_clicked()
{
        currentbutton = ui->pushButton_street_2;
        multi_bet_animation(4,2,currentbutton,166,311,61,8,true);
}

void MainWindow::on_pushButton_street_3_clicked()
{
        currentbutton = ui->pushButton_street_3;
        multi_bet_animation(7,2,currentbutton,233,310,61,8,true);
}

void MainWindow::on_pushButton_street_4_clicked()
{
        currentbutton = ui->pushButton_street_4;
        multi_bet_animation(10,2,currentbutton,300,310,61,8,true);
}

void MainWindow::on_pushButton_street_5_clicked()
{
        currentbutton = ui->pushButton_street_5;
        multi_bet_animation(13,2,currentbutton,367,309,61,8,true);
}

void MainWindow::on_pushButton_street_6_clicked()
{
        currentbutton = ui->pushButton_street_6;
        multi_bet_animation(16,2,currentbutton,434,309,61,8,true);
}

void MainWindow::on_pushButton_street_7_clicked()
{
        currentbutton = ui->pushButton_street_7;
        multi_bet_animation(19,2,currentbutton,502,309,61,8,true);
}

void MainWindow::on_pushButton_street_8_clicked()
{
        currentbutton = ui->pushButton_street_8;
        multi_bet_animation(22,2,currentbutton,569,309,61,8,true);
}

void MainWindow::on_pushButton_street_9_clicked()
{
        currentbutton = ui->pushButton_street_9;
        multi_bet_animation(25,2,currentbutton,636,309,61,8,true);
}

void MainWindow::on_pushButton_street_10_clicked()
{
        currentbutton = ui->pushButton_street_10;
        multi_bet_animation(28,2,currentbutton,703,309,61,8,true);
}

void MainWindow::on_pushButton_street_11_clicked()
{
        currentbutton = ui->pushButton_street_11;
        multi_bet_animation(31,2,currentbutton,770,309,61,8,true);
}

void MainWindow::on_pushButton_street_12_clicked()
{
        currentbutton = ui->pushButton_street_12;
        multi_bet_animation(34,2,currentbutton,837,309,61,8,true);
}

void MainWindow::on_pushButton_line_1_clicked()
{
        currentbutton = ui->pushButton_line_1;
        multi_bet_animation(1,5,currentbutton,157,308,12,12,true);
}

void MainWindow::on_pushButton_line_2_clicked()
{
        currentbutton = ui->pushButton_line_2;
        multi_bet_animation(4,5,currentbutton,224,308,12,12,true);
}

void MainWindow::on_pushButton_line_3_clicked()
{
        currentbutton = ui->pushButton_line_3;
        multi_bet_animation(7,5,currentbutton,291,308,12,12,true);
}

void MainWindow::on_pushButton_line_4_clicked()
{
        currentbutton = ui->pushButton_line_4;
        multi_bet_animation(10,5,currentbutton,358,308,12,12,true);
}

void MainWindow::on_pushButton_line_5_clicked()
{
        currentbutton = ui->pushButton_line_5;
        multi_bet_animation(13,5,currentbutton,425,307,12,12,true);
}

void MainWindow::on_pushButton_line_6_clicked()
{
        currentbutton = ui->pushButton_line_6;
        multi_bet_animation(16,5,currentbutton,492,307,12,12,true);
}

void MainWindow::on_pushButton_line_7_clicked()
{
        currentbutton = ui->pushButton_line_7;
        multi_bet_animation(19,5,currentbutton,560,307,12,12,true);
}

void MainWindow::on_pushButton_line_8_clicked()
{
        currentbutton = ui->pushButton_line_8;
        multi_bet_animation(22,5,currentbutton,627,307,12,12,true);
}

void MainWindow::on_pushButton_line_9_clicked()
{
        currentbutton = ui->pushButton_line_9;
        multi_bet_animation(25,5,currentbutton,694,307,12,12,true);
}

void MainWindow::on_pushButton_line_10_clicked()
{
        currentbutton = ui->pushButton_line_10;
        multi_bet_animation(28,5,currentbutton,761,307,12,12,true);
}

void MainWindow::on_pushButton_line_11_clicked()
{
        currentbutton = ui->pushButton_line_11;
        multi_bet_animation(31,5,currentbutton,828,307,12,12,true);
}

void MainWindow::on_pushButton_1st_row_clicked()
{
        currentbutton = ui->pushButton_1st_row;
        multi_bet_animation(1,11,currentbutton,950,250,8,61,true);
}

void MainWindow::on_pushButton_2nd_row_clicked()
{
        currentbutton = ui->pushButton_2nd_row;
        multi_bet_animation(2,11,currentbutton,950,180,8,61,true);
}

void MainWindow::on_pushButton_3rd_row_clicked()
{
        currentbutton = ui->pushButton_3rd_row;
        multi_bet_animation(3,11,currentbutton,950,110,8,61,true);
}
/* Changes the Button Icon to the coresponding chip on the picture
 * and sets the value appropriate for the chip
 * takes no arguments and doesn't return anything
 * Applies to the fallowing 6 methods
*/
void MainWindow::on_Bet_button1_clicked()
{
    this->ButtonIcon = QIcon(":/imgs/Chip_5.gif");
    this->current_button_value = 5;
}

void MainWindow::on_Bet_button2_clicked()
{
    this->ButtonIcon = QIcon(":/imgs/Chip_10.gif");
    this->current_button_value = 10;
}

void MainWindow::on_Bet_button3_clicked()
{
    this->ButtonIcon = QIcon(":/imgs/Chip_50.gif");
    this->current_button_value = 50;
}

void MainWindow::on_Bet_button4_clicked()
{
    this->ButtonIcon = QIcon(":/imgs/Chip_100.gif");
    this->current_button_value = 100;
}

void MainWindow::on_Bet_button5_clicked()
{
    this->ButtonIcon = QIcon(":/imgs/Chip_500.gif");
    this->current_button_value = 500;
}

void MainWindow::on_Bet_button6_clicked()
{
    this->ButtonIcon = QIcon(":/imgs/Chip_1000.gif");
    this->current_button_value = 1000;
}
/*This method sets a gif as qmovie and displays it on the label
 * when the button is pressed the movie playes for 2.5 second
 * after that calls the check_num function to the display the random number
 * and clears all the chips and bets from the board
 * takes no arguments and doesn't return anything
*/
void MainWindow::on_pushButton_spin_clicked()
{
    this->spinner = new QMovie(":/imgs/roulette3.gif");
    ui->label_gif->setMovie(this->spinner);
    this->spinner->setSpeed(130);
    this->spinner->start();
    QTimer::singleShot(2500, this, SLOT(slotStopMovie()));

    this->check_num();
    this->clear_bets_gui();
}


void MainWindow::slotStopMovie()
{
    this->spinner->stop();
}

void MainWindow::refreshShowcase()
{
    ui->nameShowcase->setText(this->rl.getPlayer().name);
    ui->creditsShowcase->setText(QString::number(this->rl.getPlayer().current_money_cents));
}

/* This Method assumes that every button is flat and has a chip on it and removes them
 * takes no arguments and doesn't return anything
*/
void MainWindow::clear_bets_gui()
{
    for(int x = 0;x<37;x++)
    {
            QString s = QString::number(x);
            array_to_buttons[x]->setText(s);
            array_to_buttons[x]->setIcon(QIcon());
            array_to_buttons[x]->setFlat(false);
    }
            ui->pushButton_1_18->setText("1-18");
            ui->pushButton_1_18->setIcon(QIcon());
            ui->pushButton_1_18->setFlat(false);
            ui->pushButton_19_36->setText("19-36");
            ui->pushButton_19_36->setIcon(QIcon());
            ui->pushButton_19_36->setFlat(false);
            ui->pushButton_1st->setText("1st 12");
            ui->pushButton_1st->setIcon(QIcon());
            ui->pushButton_1st->setFlat(false);
            ui->pushButton_2nd->setText("2nd 12");
            ui->pushButton_2nd->setIcon(QIcon());
            ui->pushButton_2nd->setFlat(false);
            ui->pushButton_3rd->setText("3rd 12");
            ui->pushButton_3rd->setIcon(QIcon());
            ui->pushButton_3rd->setFlat(false);
            ui->pushButton_even->setText("Even");
            ui->pushButton_even->setIcon(QIcon());
            ui->pushButton_even->setFlat(false);
            ui->pushButton_odd->setText("Odd");
            ui->pushButton_odd->setIcon(QIcon());
            ui->pushButton_odd->setFlat(false);
            ui->redButton_red->setText("RED");
            ui->redButton_red->setIcon(QIcon());
            ui->redButton_red->setFlat(false);
            ui->pushButton_black->setText("BLACK");
            ui->pushButton_black->setIcon(QIcon());
            ui->pushButton_black->setFlat(false);
            currentbutton = ui->pushButton_1_plus_2;
            multi_bet_animation(1,1,currentbutton,100,243,61,8,false);
            currentbutton = ui->pushButton_2_plus_3;
            multi_bet_animation(2,1,currentbutton,100,176,61,8,false);
            currentbutton =  ui->pushButton_4_plus_5;
            multi_bet_animation(4,1,currentbutton,167,243,61,8,false);
            currentbutton = ui->pushButton_5_plus_6;
            multi_bet_animation(5,1,currentbutton,167,176,61,8,false);
            currentbutton = ui->pushButton_7_plus_8;
            multi_bet_animation(7,1,currentbutton,234,242,61,8,false);
            currentbutton =  ui->pushButton_8_plus_9;
            multi_bet_animation(8,1,currentbutton,234,175,61,8,false);
            currentbutton = ui->pushButton_10_plus_11;
            multi_bet_animation(10,1,currentbutton,301,242,61,8,false);
            currentbutton = ui->pushButton_11_plus_12;
            multi_bet_animation(11,1,currentbutton,301,175,61,8,false);
            currentbutton = ui->pushButton_13_plus_14;
            multi_bet_animation(13,1,currentbutton,368,241,61,8,false);
            currentbutton = ui->pushButton_14_plus_15;
            multi_bet_animation(14,1,currentbutton,368,174,61,8,false);
            currentbutton = ui->pushButton_16_plus_17;
            multi_bet_animation(16,1,currentbutton,435,241,61,8,false);
            currentbutton = ui->pushButton_17_plus_18;
            multi_bet_animation(17,1,currentbutton,435,174,61,8,false);
            currentbutton = ui->pushButton_19_plus_20;
            multi_bet_animation(19,1,currentbutton,503,241,61,8,false);
            currentbutton = ui->pushButton_20_plus_21;
            multi_bet_animation(20,1,currentbutton,503,174,61,8,false);
            currentbutton = ui->pushButton_22_plus_23;
            multi_bet_animation(22,1,currentbutton,570,241,61,8,false);
             currentbutton = ui->pushButton_23_plus_24;
            multi_bet_animation(23,1,currentbutton,570,174,61,8,false);
            currentbutton = ui->pushButton_25_plus_26;
            multi_bet_animation(25,1,currentbutton,637,241,61,8,false);
            currentbutton = ui->pushButton_26_plus_27;
            multi_bet_animation(26,1,currentbutton,637,174,61,8,false);
            currentbutton = ui->pushButton_28_plus_29;
            multi_bet_animation(28,1,currentbutton,704,241,61,8,false);
            currentbutton = ui->pushButton_29_plus_30;
            multi_bet_animation(29,1,currentbutton,704,174,61,8,false);
            currentbutton = ui->pushButton_31_plus_32;
            multi_bet_animation(31,1,currentbutton,771,241,61,8,false);
            currentbutton = ui->pushButton_32_plus_33;
            multi_bet_animation(32,1,currentbutton,771,174,61,8,false);
            currentbutton = ui->pushButton_34_plus_35;
            multi_bet_animation(34,1,currentbutton,838,241,61,8,false);
            currentbutton = ui->pushButton_35_plus_36;
            multi_bet_animation(35,1,currentbutton,838,174,61,8,false);
            currentbutton = ui->pushButton_1_plus_4;
            multi_bet_animation(1,3,currentbutton,160,250,8,61,false);
            currentbutton = ui->pushButton_4_plus_7;
            multi_bet_animation(4,3,currentbutton,227,250,8,61,false);
            currentbutton = ui->pushButton_7_plus_10;
            multi_bet_animation(7,3,currentbutton,294,250,8,61,false);
            currentbutton = ui->pushButton_10_plus_13;
            multi_bet_animation(10,3,currentbutton,362,250,8,61,false);
            currentbutton = ui->pushButton_13_plus_16;
            multi_bet_animation(13,3,currentbutton,429,250,8,61,false);
            currentbutton = ui->pushButton_16_plus_19;
            multi_bet_animation(16,3,currentbutton,496,250,8,61,false);
            currentbutton = ui->pushButton_19_plus_22;
            multi_bet_animation(19,3,currentbutton,563,250,8,61,false);
            currentbutton = ui->pushButton_22_plus_25;
            multi_bet_animation(22,3,currentbutton,630,250,8,61,false);
            currentbutton = ui->pushButton_25_plus_28;
            multi_bet_animation(25,3,currentbutton,697,250,8,61,false);
            currentbutton = ui->pushButton_28_plus_31;
            multi_bet_animation(28,3,currentbutton,764,250,8,61,false);
            currentbutton = ui->pushButton_31_plus_34;
            multi_bet_animation(31,3,currentbutton,831,250,8,61,false);
            currentbutton = ui->pushButton_2_plus_5;
            multi_bet_animation(2,3,currentbutton,160,181,8,61,false);
            currentbutton = ui->pushButton_5_plus_8;
            multi_bet_animation(5,3,currentbutton,227,181,8,61,false);
            currentbutton = ui->pushButton_8_plus_11;
            multi_bet_animation(8,3,currentbutton,294,181,8,61,false);
            currentbutton = ui->pushButton_11_plus_14;
            multi_bet_animation(11,3,currentbutton,362,181,8,61,false);
            currentbutton = ui->pushButton_14_plus_17;
            multi_bet_animation(14,3,currentbutton,429,181,8,61,false);
            currentbutton = ui->pushButton_17_plus_20;
            multi_bet_animation(17,3,currentbutton,496,181,8,61,false);
            currentbutton =  ui->pushButton_20_plus_23;
            multi_bet_animation(20,3,currentbutton,563,181,8,61,false);
            currentbutton =  ui->pushButton_23_plus_26;
            multi_bet_animation(23,3,currentbutton,630,181,8,61,false);
            currentbutton =  ui->pushButton_26_plus_29;
            multi_bet_animation(26,3,currentbutton,697,181,8,61,false);
            currentbutton =  ui->pushButton_29_plus_32;
            multi_bet_animation(29,3,currentbutton,764,181,8,61,false);
            currentbutton =  ui->pushButton_32_plus_35;
            multi_bet_animation(32,3,currentbutton,831,181,8,61,false);
            currentbutton =  ui->pushButton_3_plus_6;
            multi_bet_animation(3,3,currentbutton,160,113,8,61,false);
            currentbutton =  ui->pushButton_6_plus_9;
            multi_bet_animation(6,3,currentbutton,227,113,8,61,false);
            currentbutton =  ui->pushButton_9_plus_12;
            multi_bet_animation(9,3,currentbutton,294,113,8,61,false);
            currentbutton =  ui->pushButton_12_plus_15;
            multi_bet_animation(12,3,currentbutton,362,113,8,61,false);
            currentbutton =  ui->pushButton_15_plus_18;
            multi_bet_animation(15,3,currentbutton,429,113,8,61,false);
            currentbutton =  ui->pushButton_18_plus_21;
            multi_bet_animation(18,3,currentbutton,496,113,8,61,false);
            currentbutton =  ui->pushButton_21_plus_24;
            multi_bet_animation(21,3,currentbutton,563,113,8,61,false);
            currentbutton =  ui->pushButton_24_plus_27;
            multi_bet_animation(24,3,currentbutton,630,113,8,61,false);
            currentbutton =  ui->pushButton_27_plus_30;
            multi_bet_animation(27,3,currentbutton,697,113,8,61,false);
            currentbutton =  ui->pushButton_30_plus_33;
            multi_bet_animation(30,3,currentbutton,764,113,8,61,false);
            currentbutton =  ui->pushButton_33_plus_36;
            multi_bet_animation(33,3,currentbutton,831,113,8,61,false);
            currentbutton = ui->pushButton_1_plus_4_2_5;
            multi_bet_animation(1,4,currentbutton,158,240,12,12,false);
            currentbutton = ui->pushButton_2_plus_5_3_6;
            multi_bet_animation(2,4,currentbutton,158,173,12,12,false);
            currentbutton = ui->pushButton_5_plus_8_6_9;
            multi_bet_animation(5,4,currentbutton,225,173,12,12,false);
            currentbutton = ui->pushButton_4_plus_7_5_8;
            multi_bet_animation(4,4,currentbutton,225,240,12,12,false);
            currentbutton = ui->pushButton_7_plus_10_8_11;
            multi_bet_animation(7,4,currentbutton,292,240,12,12,false);
            currentbutton = ui->pushButton_8_plus_11_9_12;
            multi_bet_animation(8,4,currentbutton,292,173,12,12,false);
            currentbutton = ui->pushButton_11_plus_14_12_15;
            multi_bet_animation(11,4,currentbutton,360,173,12,12,false);
            currentbutton = ui->pushButton_10_plus_13_11_14;
            multi_bet_animation(10,4,currentbutton,360,240,12,12,false);
            currentbutton = ui->pushButton_13_plus_16_14_17;
            multi_bet_animation(13,4,currentbutton,426,240,12,12,false);
            currentbutton = ui->pushButton_14_plus_17_15_18;
            multi_bet_animation(14,4,currentbutton,426,173,12,12,false);
            currentbutton = ui->pushButton_17_plus_20_18_21;
            multi_bet_animation(17,4,currentbutton,493,173,12,12,false);
            currentbutton = ui->pushButton_16_plus_19_17_20;
            multi_bet_animation(16,4,currentbutton,493,240,12,12,false);
            currentbutton = ui->pushButton_19_plus_22_20_23;
            multi_bet_animation(19,4,currentbutton,561,240,12,12,false);
            currentbutton = ui->pushButton_20_plus_23_21_24;
            multi_bet_animation(20,4,currentbutton,561,173,12,12,false);
            currentbutton = ui->pushButton_22_plus_25_23_26;
            multi_bet_animation(22,4,currentbutton,628,173,12,12,false);
            currentbutton = ui->pushButton_23_plus_26_24_27;
            multi_bet_animation(23,4,currentbutton,628,240,12,12,false);
            currentbutton = ui->pushButton_25_plus_28_26_29;
            multi_bet_animation(25,4,currentbutton,695,240,12,12,false);
            currentbutton = ui->pushButton_26_plus_29_27_30;
            multi_bet_animation(26,4,currentbutton,695,173,12,12,false);
            currentbutton = ui->pushButton_29_plus_32_30_33;
            multi_bet_animation(29,4,currentbutton,762,173,12,12,false);
            currentbutton = ui->pushButton_28_plus_31_29_32;
            multi_bet_animation(28,4,currentbutton,762,240,12,12,false);
            currentbutton = ui->pushButton_31_plus_34_32_35;
            multi_bet_animation(31,4,currentbutton,829,240,12,12,false);
            currentbutton = ui->pushButton_32_plus_35_33_36;
            multi_bet_animation(32,4,currentbutton,829,173,12,12,false);
            currentbutton = ui->pushButton_street_1;
            multi_bet_animation(1,2,currentbutton,99,311,61,8,false);
            currentbutton = ui->pushButton_street_2;
            multi_bet_animation(4,2,currentbutton,166,311,61,8,false);
            currentbutton = ui->pushButton_street_3;
            multi_bet_animation(7,2,currentbutton,233,310,61,8,false);
            currentbutton = ui->pushButton_street_4;
            multi_bet_animation(10,2,currentbutton,300,310,61,8,false);
            currentbutton = ui->pushButton_street_5;
            multi_bet_animation(13,2,currentbutton,367,309,61,8,false);
            currentbutton = ui->pushButton_street_6;
            multi_bet_animation(16,2,currentbutton,434,309,61,8,false);
            currentbutton = ui->pushButton_street_7;
            multi_bet_animation(19,2,currentbutton,502,309,61,8,false);
            currentbutton = ui->pushButton_street_8;
            multi_bet_animation(22,2,currentbutton,569,309 ,61,8,false);
            currentbutton = ui->pushButton_street_9;
            multi_bet_animation(25,2,currentbutton,636,309,61,8,false);
            currentbutton = ui->pushButton_street_10;
            multi_bet_animation(28,2,currentbutton,703,309,61,8,false);
            currentbutton = ui->pushButton_street_11;
            multi_bet_animation(31,2,currentbutton,770,309,61,8,false);
            currentbutton = ui->pushButton_street_12;
            multi_bet_animation(34,2,currentbutton,837,309,61,8,false);
            currentbutton = ui->pushButton_line_1;
            multi_bet_animation(1,5,currentbutton,157,308,12,12,false);
            currentbutton = ui->pushButton_line_2;
            multi_bet_animation(4,5,currentbutton,224,308,12,12,false);
            currentbutton = ui->pushButton_line_3;
            multi_bet_animation(7,5,currentbutton,291,308,12,12,false);
            currentbutton = ui->pushButton_line_4;
            multi_bet_animation(10,5,currentbutton,358,308,12,12,false);
            currentbutton = ui->pushButton_line_5;
            multi_bet_animation(13,5,currentbutton,425,307,12,12,false);
            currentbutton = ui->pushButton_line_6;
            multi_bet_animation(16,5,currentbutton,492,307,12,12,false);
            currentbutton = ui->pushButton_line_7;
            multi_bet_animation(19,5,currentbutton,560,307,12,12,false);
            currentbutton = ui->pushButton_line_8;
            multi_bet_animation(22,5,currentbutton,627,307,12,12,false);
            currentbutton = ui->pushButton_line_9;
            multi_bet_animation(25,5,currentbutton,694,307,12,12,false);
            currentbutton = ui->pushButton_line_10;
            multi_bet_animation(28,5,currentbutton,761,307,12,12,false);
            currentbutton = ui->pushButton_line_11;
            multi_bet_animation(31,5,currentbutton,828,307,12,12,false);
            currentbutton = ui->pushButton_1st_row;
            multi_bet_animation(1,11,currentbutton,950,250,8,61,false);
            currentbutton = ui->pushButton_2nd_row;
            multi_bet_animation(2,11,currentbutton,950,180,8,61,false);
            currentbutton = ui->pushButton_3rd_row;
            multi_bet_animation(3,11,currentbutton,950,110,8,61,false);
}

void MainWindow::on_Clear_Button_pressed()
{
    this->rl.clearAllBets();
    this->clear_bets_gui();
}

void MainWindow::on_rules_button_clicked()
{
    rulespointer = new Rules();
    rulespointer->show();
}

void MainWindow::on_Clear_Button_clicked()
{

}
