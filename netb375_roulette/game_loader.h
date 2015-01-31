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
    GameLoader();
    GameLoader(QString intial_path);
    QString getCurrentPath();
    int setCurrentPath(QString new_path);
    int getMoneyForAccount(QString account_name);
    int setMoneyForAccount(QString account_name, int current_money_cents);
};

#endif // GAME_LOADER_H
