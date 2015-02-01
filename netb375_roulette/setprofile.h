#ifndef SETPROFILE_H
#define SETPROFILE_H
#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class SetProfile;
}

class SetProfile : public QWidget
{
    Q_OBJECT

public:
    explicit SetProfile(QWidget *parent = 0);
    ~SetProfile();

private slots:
    void on_pushButton_play_clicked();

private:

    Ui::SetProfile *ui;
    MainWindow *mwindow;
};

#endif // SETPROFILE_H
