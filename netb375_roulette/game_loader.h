#ifndef GAME_LOADER_H
#define GAME_LOADER_H
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QRegExp>

class GameLoader
{
private:
    QString file_path;

public:
    //Constructors
    GameLoader();
    GameLoader(QString intial_path);

    //Setters and getters
    QString getCurrentPath();
    int setCurrentPath(QString new_path);

    //Working with the data in the file
    int getMoneyForAccount(QString account_name);
    int setMoneyForAccount(QString account_name, int current_money_cents);
};

#endif // GAME_LOADER_H
