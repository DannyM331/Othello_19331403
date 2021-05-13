#include "othello.h"

int turnTrackerInt(int a)
{
    if ((a % 2) == 0)//if a is even then its white turn
    {
        return 2;
    }
    
    else//if its not even then its odd, meaning its blacks turn
    {
        return 1;
    }
    
}