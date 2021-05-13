#include "othello.h"

int initialiseBoard()
{
    int i, *board;
    board = (int*)calloc(65, sizeof(int));//set memory for the board

    for ( i = 1; i <= 64; i++)//this for loop sets the board up for othello
    {
        if ((i == 28) || (i == 37))
        {
            board[i] = WHITE;
        }

        else if ((i == 29) || (i == 36))
        {
            board[i] = BLACK;
        }

        else
        {
            board[i] = EMPTY;
        }
        
    }

    return board;
}