#ifndef ROULETTE_LOGIC_H
#define ROULETTE_LOGIC_H
#include <QString>
#include <QVector>
#include <game_loader.h>

struct bet {
  int multiplyer;
  int symbol;
  int bet_amount_cents;
} ;

struct player{
    int current_money_cents;
    QString name;
};

class RouletteLogic
{
private:
    QVector<bet> round_bets;
    GameLoader game_loader;
    player person;
public:
    RouletteLogic();
    RouletteLogic(QString save_file_path);
    RouletteLogic(QString person_name, int person_money_cents, QString save_file_path);
    int SetSaveLoadPath(QString save_file_path);
    int getRandomNumber();

    int createBet(int symbol, int bet_amount_cents, int multiplyer);
    int finishRound();
    int saveGame();
    int loadGame(QString player_name);
};

#endif // ROULETTE_LOGIC_H
