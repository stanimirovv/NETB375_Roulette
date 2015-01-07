#ifndef ROULETTEGAME_H
#define ROULETTEGAME_H
#include <QString>

#include <QVector>

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
    // TODO there needs to be some mapping between the sygils and the numbers which
    int wallet_id;
    int player_id;
    int round_id;
    // it is an array and not a hash because most board_elements have several attributes.
    QVector<board_element> board;
    QSqlDatabase db;
public:
    RouletteGame(int player_id, int wallet_id, QString db_name, QString db_host, QString db_user, QString db_user_pass);
    ~RouletteGame();
    void BetMoney(int amount, QString sygil, QString attribute);
    void FinishRound(QString sygil);
};

#endif // ROULETTEGAME_H
