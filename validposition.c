#include "othello.h"

int validPosition(int coord, int direction, int opposite, int *board)
{
    int pieceChecker;
    pieceChecker = coord + direction;

    if (board[pieceChecker] == opposite)//if the pieceChecker is of the opposite colour, enter the if statment
    {
        return 1;
    }
    
}