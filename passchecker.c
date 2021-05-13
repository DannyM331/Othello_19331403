#include "othello.h"

int passChecker(int colour, int *board)
{
    int i;

    /* this keeps checking looping until it either finds a legal move or has gone through all the pieces */
    for (int i = 1; i < 65; i++)
    {
        if ((legalMoveChecker(colour, i, board)) == 1)//if a legal move is found, enter the if statment
        {
            return 1;
        }
        
    }

    return 0;

}