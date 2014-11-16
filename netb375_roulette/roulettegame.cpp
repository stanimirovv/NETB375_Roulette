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
    query.prepare("select ET.name, ET.multiplier, BE.sygil from element_types AS ET JOIN board_elements__element_types AS BEET ON ET.id = BEET.element_type_id JOIN board_elements AS BE ON BEET.board_element_id = BE.id; ");
    query.exec();
    int index = query.record().indexOf("tt1");
    while (query.next())
    {
        QString time = query.value(index).toString();
        qDebug() << "Qdebug:r" << time;
    }

}

/* This function represents a bet which has been made from the player
 *
 *
 */
void RouletteGame::BetMoney(int amount, QString sygil)
{

}

/*
 *
 *
 *
 */
void RouletteGame::WinMoney(int amount)
{

}
