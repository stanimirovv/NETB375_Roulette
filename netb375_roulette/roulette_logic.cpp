#include "roulette_logic.h"

RouletteLogic::RouletteLogic(QString save_file_path)
{
    this->game_loader.setCurrentPath(save_file_path);
}

RouletteLogic::RouletteLogic()
{

}

int RouletteLogic::SetSaveLoadPath(QString save_file_path)
{
    return this->game_loader.setCurrentPath(save_file_path);
}

RouletteLogic::RouletteLogic(QString person_name, int person_money_cents, QString save_file_path)
{
    this->person.name = person_name;
    this->person.current_money_cents = person_money_cents;
    this->game_loader.setCurrentPath(save_file_path);
}


int RouletteLogic::getRandomNumber()
{
    return 14;
}

int RouletteLogic::createBet(int symbol, int bet_amount_cents, int multiplyer, bool is_genuine_bet)
{
    qDebug() << "Printing the is_genuine_bet variable:" << is_genuine_bet << endl;
    if(bet_amount_cents <= 0 || multiplyer <= 0)
    {
        qDebug() << "There is an issue with the passed parameter" << endl;
        return 0;
    }
    if(this->person.current_money_cents < bet_amount_cents)
    {
        qDebug() << "The player can't bet that much money!" << endl;
        return 0;
    }

    if(is_genuine_bet)
    {
        this->person.current_money_cents -= bet_amount_cents;
    }
    bet new_bet;
    new_bet.bet_amount_cents = bet_amount_cents;
    new_bet.multiplyer = multiplyer;
    new_bet.symbol = symbol;
    qDebug() << "Creating a new bet! amount:  " << new_bet.bet_amount_cents << "  multi:" << new_bet.multiplyer << "  symbol:" << new_bet.symbol << endl;
    this->round_bets.append(new_bet);
    return 1;
}

int RouletteLogic::finishRound()
{
    int symbol = 1;
    //int symbol = this->getRandomNumber();
    qDebug() << "Money before end round for player: " << this->person.current_money_cents << endl;
    while(this->round_bets.length() > 0)
    {
        qDebug() << "Testing new bet!" << endl;
        if(symbol == this->round_bets[0].symbol)
        {
            qDebug() << "We have a winner, adding: " << this->round_bets[0].bet_amount_cents * this->round_bets[0].multiplyer << endl;
            this->person.current_money_cents += this->round_bets[0].bet_amount_cents * this->round_bets[0].multiplyer;
        }
        this->round_bets.pop_front();
    }
    qDebug() << "Money after end round for player: " << this->person.current_money_cents << endl;
    this->saveGame();
    return 0;
}

int RouletteLogic::saveGame()
{
    return this->game_loader.setMoneyForAccount(this->person.name, this->person.current_money_cents);
}

int RouletteLogic::loadGame(QString player_name)
{
    this->person.name = player_name;
    this->person.current_money_cents = this->game_loader.getMoneyForAccount(player_name);
    return 0;
}

void RouletteLogic::setPlayer(player new_player)
{
    this->person = new_player;
}

player RouletteLogic::getPlayer()
{
    return this->person;
}
