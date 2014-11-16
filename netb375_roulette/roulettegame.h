#ifndef ROULETTEGAME_H
#define ROULETTEGAME_H
#include <QString>
#include <QHash>
#include <QtSql>

struct board_element
{
  QString name;
  QString sygil;
  double multiplier;

} ;

class RouletteGame
{
private:
    // TODO add setting variables here
    // TODO implement round mechanic
    // TODO consider creating a player class which will hold all
    // the player's data including the wallet with which the player is playing
    int wallet_id;
    int player_id;
    QHash<QString, board_element> board;
    QSqlDatabase db;
public:
    RouletteGame(int player_id, int wallet_id, QString db_name, QString db_host, QString db_user, QString db_user_pass);
    ~RouletteGame();
    void BetMoney(int amount, QString sygil);
    void WinMoney(int amount);
};

#endif // ROULETTEGAME_H
