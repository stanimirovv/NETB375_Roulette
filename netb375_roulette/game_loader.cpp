#include "game_loader.h"


/*
Default constructor.
*/
GameLoader::GameLoader()
{
    this->file_path = "";
}

/*
 * Constructor which takes the initial path to the file as a prameter and
 * sets the file_path member to the passed value.
 */
GameLoader::GameLoader(QString initial_path)
{
    this->file_path = initial_path;
}

/*
 * This function returns the current file path.
 */
QString GameLoader::getCurrentPath()
{
    return this->file_path;
}

/*
 * Sets the current path of the file. Takes as parameter the new file path
 * returns 0 if there has been an error. Returns 1 if the function has executed correctly
 */
int GameLoader::setCurrentPath(QString new_path)
{
    if(new_path == "")
    {
        return 0;
    }

    this->file_path = new_path;
    return 1;
}

/*
    The function will return 0 if there is no match found.
    If it finds the match it will return the money it's found.

    The function searches the text file for an entry with the matching account name.
    if it finds it, it will return the value. Else it will return 0.
*/
int GameLoader::getMoneyForAccount(QString account_name)
{

     QFile file(this->file_path);
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         return 0;

     QTextStream in(&file);
     while (!in.atEnd())
     {
         QString line = in.readLine();
         QStringList list = line.split(",");
         qDebug()<<"name:"<<list[0] << "  money:"  <<  list[1] << endl;
         if(account_name == list[0])
         {
             bool isNum = true;
             int current_money_cents = list[1].toInt(&isNum);
             if(isNum)
             {
                  qDebug()<<"Returning name:"<<list[0] << "  money:"  <<  list[1] << endl;
                  file.close();
                  return current_money_cents;
             }
         }
     }
     file.close();
     return 0;
}

/*
 note: for the functions below, 1 is considered that the function has finished successfully, where as a 0 return means
 that there has been an error.

 Attempts to save the money for an account. If the accoutn exists in the file the function will update the entry. If the account
 doesn't exist it will create a new entry.
 Takes the account name and the account's money as parameters.
*/

int GameLoader::setMoneyForAccount(QString account_name, int account_money)
{
    QFile file(this->file_path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return 0;

    QTextStream in(&file);
    QStringList list;
    bool is_existing_entry = false;
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList parsed_line = line.split(",");
        if(parsed_line[0] == account_name)
        {
            line = account_name + "," +QString::number(account_money);
        }
        list.append(line);
        if(account_name ==parsed_line[0])
        {
            qDebug()<< "Found a match for:" << account_name << "  " << list[0] << endl;
            is_existing_entry = true;
        }
    }
    file.close();
    if(is_existing_entry)
    {
        qDebug() << "The user exists, so I have to update him/her" << endl;
        // write every line to the file
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return 0;
        QTextStream outstream(&file);
        QMutableStringListIterator i(list);
        while (i.hasNext())
        {
            i.next();
            qDebug() << "Inserting new entry: " << i.value() << endl;
            outstream << i.value() <<"\n";
        }
        file.close();
        return 1;
    }
    qDebug() << "The user doesn't exist, I must make a new entry" << endl;
    if (!file.open(QIODevice::Append | QIODevice::Text))
        return 0;
    QString account_name_money = account_name + "," +QString::number(account_money);
    qDebug()<< "Account name money: " << account_name_money << endl;
    QTextStream outstream(&file);
    outstream << account_name_money;
    file.close();

    return 1;
}
