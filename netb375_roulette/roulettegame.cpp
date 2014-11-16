#include "roulettegame.h"

RouletteGame::RouletteGame(int m_player_id, int m_wallet_id, QString db_name, QString db_host, QString db_user, QString db_user_pass)
{
    player_id = m_player_id;
    wallet_id = m_wallet_id;
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(db_host);
    db.setDatabaseName(db_name);
    db.setUserName(db_user);
    db.setPassword(db_user_pass);
    db.open();

    // Fill the game board
    QSqlQuery query(db);

    query.prepare("select ET.name, ET.multiplier, BE.sygil from element_types AS ET JOIN board_elements__element_types AS BEET ON ET.id = BEET.element_type_id JOIN board_elements AS BE ON BEET.board_element_id = BE.id;");
    //query.prepare("SELECT now() as tt1;");
    query.exec();
    while (query.next())
    {
        QString time = query.value("tt1").toString();
        board_element new_element;
        //new_element.multiplier = query.value("multiplier");
        new_element.name = query.value("name").toString();
        new_element.sygil  = query.value("sygil").toString();
        qDebug() << "Printing new_element:  " <<  new_element.name << "  " << new_element.sygil << "  ";
        board.push_back(new_element);
    }
    //get the intial round id
}

/* This function represents a bet which has been made from the player
 * This function may be called as many times as needed during each round.
 *
 * @param amount -> the amount of money that are being bet in cents
 * @param sygil -> the sygil (symbol) of the field
 * @param attribute -> the attribute of the sygil on which the player bets (even/odd, red/black, number)
 */
void RouletteGame::BetMoney(int amount, QString sygil, QString attribute)
{
    for(int i = 0; i < board.length(); i++)
    {
        // check if sygil and attribute match (which is sygil / name.
    }
    QSqlQuery query(db);
    //QString insert_bet =
}

/* This function will go through every bet made this round and will
 * pay the player for each correct guess.
 *
 * @param  sygil of the element on which the ball has landed
 */
void RouletteGame::FinishRound(QString sygil)
{
    // go through the requests once.
    // check for every attribute of the sygil
}

RouletteGame::~RouletteGame()
{
    db.close();
}
