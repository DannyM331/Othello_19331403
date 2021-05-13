#include "othello.h"

int playerScore(int colour, int *board)
{
    int i, score = 0;

    /* check the entire board and if a piece is the same as the current colour, increase the score by one */
    for ( i = 1; i <= 64; i++)
    {
        if (board[i] == colour)
        {
            score++;
        }
        
    }
    
    return score;

}