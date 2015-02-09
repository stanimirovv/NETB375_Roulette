#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <game_loader.h>
#include <roulette_logic.h>
#include <QTime>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QIcon ButtonIcon;
    int current_button_value;
    QMovie *spinner;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void single_button_bet(int x);
    void multi_bet_animation(int x1,int d,QPushButton* currentbutton,int xg,int yg,int width,int lenght,bool add);
    bool check_num();
    RouletteLogic rl;
    void clear_bets_gui();

private slots:
    void refreshShowcase();
    void slotStopMovie();
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_0_clicked();

    void on_pushButton_1_18_clicked();

    void on_pushButton_19_36_clicked();

    void on_pushButton_1st_clicked();

    void on_pushButton_2nd_clicked();

    void on_pushButton_3rd_clicked();

    void on_pushButton_even_clicked();

    void on_pushButton_odd_clicked();

    void on_pushButton_1_plus_2_clicked();

    void on_pushButton_2_plus_3_clicked();

    void on_pushButton_4_plus_5_clicked();

    void on_pushButton_5_plus_6_clicked();

    void on_pushButton_7_plus_8_clicked();

    void on_pushButton_8_plus_9_clicked();

    void on_pushButton_10_plus_11_clicked();

    void on_pushButton_11_plus_12_clicked();

    void on_pushButton_13_plus_14_clicked();

    void on_pushButton_14_plus_15_clicked();

    void on_pushButton_16_plus_17_clicked();

    void on_pushButton_17_plus_18_clicked();

    void on_pushButton_19_plus_20_clicked();

    void on_pushButton_20_plus_21_clicked();

    void on_pushButton_22_plus_23_clicked();

    void on_pushButton_23_plus_24_clicked();

    void on_pushButton_25_plus_26_clicked();

    void on_pushButton_26_plus_27_clicked();

    void on_pushButton_28_plus_29_clicked();

    void on_pushButton_29_plus_30_clicked();

    void on_pushButton_31_plus_32_clicked();

    void on_pushButton_32_plus_33_clicked();

    void on_pushButton_34_plus_35_clicked();

    void on_pushButton_35_plus_36_clicked();

    void on_pushButton_1_plus_4_clicked();

    void on_pushButton_4_plus_7_clicked();

    void on_pushButton_7_plus_10_clicked();

    void on_pushButton_10_plus_13_clicked();

    void on_pushButton_13_plus_16_clicked();

    void on_pushButton_16_plus_19_clicked();

    void on_pushButton_19_plus_22_clicked();

    void on_pushButton_22_plus_25_clicked();

    void on_pushButton_25_plus_28_clicked();

    void on_pushButton_28_plus_31_clicked();

    void on_pushButton_31_plus_34_clicked();

    void on_pushButton_2_plus_5_clicked();

    void on_pushButton_5_plus_8_clicked();

    void on_pushButton_8_plus_11_clicked();

    void on_pushButton_11_plus_14_clicked();

    void on_pushButton_14_plus_17_clicked();

    void on_pushButton_17_plus_20_clicked();

    void on_pushButton_20_plus_23_clicked();

    void on_pushButton_23_plus_26_clicked();

    void on_pushButton_26_plus_29_clicked();

    void on_pushButton_29_plus_32_clicked();

    void on_pushButton_32_plus_35_clicked();

    void on_pushButton_3_plus_6_clicked();

    void on_pushButton_6_plus_9_clicked();

    void on_pushButton_9_plus_12_clicked();

    void on_pushButton_12_plus_15_clicked();

    void on_pushButton_15_plus_18_clicked();

    void on_pushButton_18_plus_21_clicked();

    void on_pushButton_21_plus_24_clicked();

    void on_pushButton_24_plus_27_clicked();

    void on_pushButton_27_plus_30_clicked();

    void on_pushButton_30_plus_33_clicked();

    void on_pushButton_33_plus_36_clicked();

    void on_pushButton_1_plus_4_2_5_clicked();

    void on_pushButton_2_plus_5_3_6_clicked();

    void on_pushButton_5_plus_8_6_9_clicked();

    void on_pushButton_4_plus_7_5_8_clicked();

    void on_pushButton_7_plus_10_8_11_clicked();

    void on_pushButton_8_plus_11_9_12_clicked();

    void on_pushButton_11_plus_14_12_15_clicked();

    void on_pushButton_10_plus_13_11_14_clicked();

    void on_pushButton_13_plus_16_14_17_clicked();

    void on_pushButton_14_plus_17_15_18_clicked();

    void on_pushButton_17_plus_20_18_21_clicked();

    void on_pushButton_16_plus_19_17_20_clicked();

    void on_pushButton_19_plus_22_20_23_clicked();

    void on_pushButton_22_plus_25_23_26_clicked();

    void on_pushButton_23_plus_26_24_27_clicked();

    void on_pushButton_20_plus_23_21_24_clicked();

    void on_pushButton_25_plus_28_26_29_clicked();

    void on_pushButton_26_plus_29_27_30_clicked();

    void on_pushButton_29_plus_32_30_33_clicked();

    void on_pushButton_28_plus_31_29_32_clicked();

    void on_pushButton_31_plus_34_32_35_clicked();

    void on_pushButton_32_plus_35_33_36_clicked();

    void on_Bet_button1_clicked();

    void on_Bet_button2_clicked();

    void on_Bet_button3_clicked();

    void on_Bet_button4_clicked();

    void on_Clear_Button_clicked();

    void on_redButton_red_clicked();

    void on_pushButton_black_clicked();

    void on_pushButton_spin_clicked();

    void on_Bet_button5_clicked();

    void on_Bet_button6_clicked();

    void on_pushButton_street_1_clicked();

    void on_pushButton_street_2_clicked();

    void on_pushButton_street_3_clicked();

    void on_pushButton_street_4_clicked();

    void on_pushButton_street_5_clicked();

    void on_pushButton_street_6_clicked();

    void on_pushButton_street_7_clicked();

    void on_pushButton_street_8_clicked();

    void on_pushButton_street_9_clicked();

    void on_pushButton_street_10_clicked();

    void on_pushButton_street_11_clicked();

    void on_pushButton_street_12_clicked();

    void on_pushButton_line_1_clicked();

    void on_pushButton_line_2_clicked();

    void on_pushButton_line_3_clicked();

    void on_pushButton_line_4_clicked();

    void on_pushButton_line_5_clicked();

    void on_pushButton_line_6_clicked();

    void on_pushButton_line_7_clicked();

    void on_pushButton_line_8_clicked();

    void on_pushButton_line_9_clicked();

    void on_pushButton_line_10_clicked();

    void on_pushButton_line_11_clicked();

    void on_pushButton_1st_row_clicked();

    void on_pushButton_2nd_row_clicked();

    void on_pushButton_3rd_row_clicked();

    void on_Clear_Button_pressed();

private:
    Ui::MainWindow *ui;
    QPushButton *array_to_buttons[37];
};

#endif // MAINWINDOW_H
