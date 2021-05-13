#include "othello.h"

int turnTracker(int a)
{
    char Black[] = "Black";
    char White[] = "White";

    if ((a % 2) == 0)//if a is even then its white turn
    {
        return White;
    }
    
    else//if its not even then its odd, meaning its blacks turn
    {
        return Black;
    }
    
}