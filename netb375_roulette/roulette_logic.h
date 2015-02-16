#ifndef ROULETTE_LOGIC_H
#define ROULETTE_LOGIC_H
#include <QString>
#include <QVector>
#include <game_loader.h>
#include <stdlib.h>
#include "NumberGenerator.h"

struct bet {
  int multiplyer;
  int symbol;
  int bet_amount_cents;
  bool genuine_bet;

  bool operator==(bet a) const{
      if(a.multiplyer== this->multiplyer && a.symbol == this->symbol && a.bet_amount_cents == this->bet_amount_cents && a.genuine_bet == this->genuine_bet)return true;
      else return false;
  }
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
    // Default constructor
    RouletteLogic();
    // A constructor which takes the path to the save file
    RouletteLogic(QString save_file_path);
    // A constructor which takes the path to the save file and
    RouletteLogic(QString person_name, int person_money_cents, QString save_file_path);

    // Game functionallity methods
    int getRandomNumber();
    int createBet(int symbol, int bet_amount_cents, int multiplyer, bool is_genuine_bet = false);
    int finishRound();
    void clearBet(bet depricated_bet);
    void clearAllBets();

    // Wrappers arround the  game_loader object
    int SetSaveLoadPath(QString save_file_path);
    int saveGame();
    int loadGame(QString player_name);

    // Setters and getters
    void setPlayer(player new_player);
    player getPlayer();
};

#endif // ROULETTE_LOGIC_H
