#include "othello.h"

int bracketChecker(int coord, int direction, int opposite, int colour, int *board)
{

    int pieceChecker, i;

    pieceChecker = coord + direction;
    
    if (board[pieceChecker] == opposite)//if the piece is the opposite colour, enter the if statment
    {
        while (((board[pieceChecker]) == opposite) && (pieceChecker > 0) && (pieceChecker < 64) && (pieceChecker % 8 != 0) && ((pieceChecker - 1) % 8 != 0))//as long as all these conditions are met, stay in the loop
        {
            pieceChecker += direction;

            if (board[pieceChecker] == colour)
            {
                return 1;
            }

        }
        
    }

    return 0;

}