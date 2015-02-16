#include "roulette_logic.h"

/*
 * Default constructor. It is rarely used.
 */
RouletteLogic::RouletteLogic()
{

}

/*
 * A constructor for the RouletteLogic. Takes the path to the file with the saves as a parameter
 * and sets the game_loader's current path to the passed value.
 */
RouletteLogic::RouletteLogic(QString save_file_path)
{
    this->game_loader.setCurrentPath(save_file_path);
}

/*
 * Has one parameter which is a QString.
 * Sets the path to the save file.
 * Returns 1 if the operation was successful and 0 of the operation failed.
 */
int RouletteLogic::SetSaveLoadPath(QString save_file_path)
{
    return this->game_loader.setCurrentPath(save_file_path);
}

/*
 * The last constructor and the one which is most commonly used.
 * Takes 3 parameters - the location to the file with the saves, the name of
 * the person and the money of the person.
 */
RouletteLogic::RouletteLogic(QString person_name, int person_money_cents, QString save_file_path)
{
    this->person.name = person_name;
    this->person.current_money_cents = person_money_cents;
    this->game_loader.setCurrentPath(save_file_path);
}

/*
 * Returns a random number.(integer)
 * Doesn't take any parameters
 */
int RouletteLogic::getRandomNumber()
{
    NumberGenerator ng = NumberGenerator(0, 36);
    ng.set_seed(5);
    //return ng.rand();
    return rand() % 36 + 1;
}


/*
 *  Takes as a parameter the symbol on which the player has bet, the amount and the multiplier for the bet.
 *  It also takes an optional boolean which is false by default and decides if the money for the bet should be
 *  subtracted from the player's money.
 *  If all the passed parameters are okay it creates a bet and inserts it into the round's vector of bets.
 *  Returns 1 if everything is okay and 0 if there was an error.
 *
 */
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

/*
 * Takes no arguments.
 * Takes a random number from the function which returns random numbers.
 * Visits every bet. If the bet is a winner it pays out the money to the player.
 * Returns the symbol which has been generated
 */

int RouletteLogic::finishRound()
{
    //int symbol = 1;
    int symbol = this->getRandomNumber();
    qDebug() << "Money before end round for player: " << this->person.current_money_cents << endl;
    qDebug() << "Symbol is: " << symbol << endl;
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
    return symbol;
}

/*
 * This is a wrapper function which calles the game_loader's setMoneyForAccount method.
 * It saves the passed values to the save file.
 * Returns 0 if there was a problem, 1 if everything was okay.
 */
int RouletteLogic::saveGame()
{
    return this->game_loader.setMoneyForAccount(this->person.name, this->person.current_money_cents);
}

/*
 * takes as a parameter the name of an account.
 * returns the money of the account if the enery exists. If the entry doesn't exist it returns 0.
 */
int RouletteLogic::loadGame(QString player_name)
{
    this->person.name = player_name;
    this->person.current_money_cents = this->game_loader.getMoneyForAccount(player_name);
    return 0;
}

/*  Takes as a parameter the new player.
 *  Set the player of the roulette.
 *  Doesn't return anything.
 */
void RouletteLogic::setPlayer(player new_player)
{
    this->person = new_player;
}

/*
 * Takes no parameters.
 * Returns the player of the roulette.
 */
player RouletteLogic::getPlayer()
{
    return this->person;
}


/*
 * Takes a bet structure as a parameter. It removes the bet which is passed as a parameter from the current round bets.
 * NOTE: This function is depricated.
 */
void RouletteLogic::clearBet(bet depricated_bet)
{
    //this->round_bets.remove(this->round_bets.indexOf(depricated_bet));
}

/*
 * Takes no parameters. Removes the betsfrom the game board.
 * Returns the money for the bet to the player's account.
 * Returns nothing.
 */
void RouletteLogic::clearAllBets()
{
    for(int i = 0; i < this->round_bets.length(); i++)
    {
        if(this->round_bets[i].genuine_bet == true)
        {
            this->person.current_money_cents += round_bets[i].bet_amount_cents;
        }
    }
    this->round_bets.clear();
}
