#ifndef STARTWINDOW_H
#define STARTWINDOW_H
#include <QWidget>
#include "setprofile.h"

namespace Ui {
class StartWindow;
}

class StartWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();

private slots:
    void on_pushButton_new_clicked();

    void on_pushButton_quit_clicked();

private:
    Ui::StartWindow *ui;
    SetProfile *setprof;
};

#endif // STARTWINDOW_H
