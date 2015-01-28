#include "game.h"

game::game()
{
}

bool check_below18()
{
    if(n!=0 && n<=18)
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

bool check_above19()
{
    if(n>18)
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

bool check_first12()
{
    if(n>=1 && n<=12)
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

bool check_second12()
{
    if(n>=13 && n<=24)
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

bool check_third12()
{
    if(n>=25 && n<=36)
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

bool check_num()
{
    if(arr_rulette[n] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

bool check_color()
{
    if(true)
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

bool check_even(int i)
{
    if(i%2==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool check_odd(int i)
{
    if(i%2!=0)
    {
        return true;
    }
    else
    {
        return false;
    }

}
