#include "othello.h"

int bracketEdgeChecker(int coord, int direction, int opposite, int colour, int *board)
{
    int pieceChecker, i;

    pieceChecker = coord + direction;

    if ((board[pieceChecker] == opposite) && ((coord - 1) % 8 == 0))//if the piece is the opposite colour and in the A column, enter the if statment
    {
        while ((board[pieceChecker]) == opposite && (pieceChecker >= 0) && (pieceChecker <= 64) && ((pieceChecker) % 8 != 0))//as long as all the conditions are met, stay in the loop
        {
            pieceChecker += direction;
                    
            if (board[pieceChecker] == colour)//once the bracketing piece is found, enter the if statment
            {
                return 1;
            }        
                    
        }
                
    }

    else if ((board[pieceChecker] == opposite) && (coord % 8 == 0))//if the piece is the opposite colour and in the H column, enter the if statment
    {
        while ((board[pieceChecker]) == opposite && (pieceChecker >= 0) && (pieceChecker <= 64) && ((pieceChecker - 1) % 8 != 0))//as long as all the contions are met, stay in the loop
        {
            pieceChecker += direction;
                    
            if (board[pieceChecker] == colour)//once the bracketing piece is found, enter the if statment
            {
                return 1;
            }
         
        }
                
    }

    return 0;

}