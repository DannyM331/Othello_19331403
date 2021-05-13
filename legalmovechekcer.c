#include "othello.h"

int legalMoveChecker(int colour, int coord, int *board)
{
    int opposite, i;

    if (colour == BLACK)
    {
        opposite = WHITE;
    }
    
    else if (colour == WHITE)
    {
        opposite = BLACK;
    }

    if (((board[coord]) == EMPTY) && ((coord % 8) == 0))//if the board is empty and the co-ord is in the H column, enter the if statment
    {
        for ( i = 0; i < 5; i++)
        {
            if ((validPosition(coord, DIRECTIONSH[i], opposite, board)) == 1)//if the valitposition funtion returns 1, enter the if statment
            {
                if (bracketEdgeChecker(coord, DIRECTIONSH[i], opposite, colour, board) == 1)//if a valid bracketing piece was found, enter the if statment
                {
                    return 1;
                }
                
            }
            
        }
        return 0;
        
    }

    else if (((board[coord]) == EMPTY) && (((coord - 1) % 8) == 0))//if the board is empty and the co-ord is in the A column, enter the if statment
    {
        for ( i = 0; i < 5; i++)
        {
            if ((validPosition(coord, DIRECTIONSA[i], opposite, board)) == 1)//if the valitposition funtion returns 1, enter the if statment
            {
                if (bracketEdgeChecker(coord, DIRECTIONSA[i], opposite, colour, board) == 1)//if a valid bracketing piece was found, enter the if statment
                {
                    return 1;
                }
                
            }
            
        }
        return 0;
        
    }
    
    
    else if ((board[coord]) == EMPTY)//if the board is empty and the co-ord is not in either the A or H column, enter the if statment
    {
        
        for ( i = 0; i < 8; i++)
        {
            if ((validPosition(coord, DIRECTIONS[i], opposite, board)) == 1)//if the valitposition funtion returns 1, enter the if statment
            {
                if ((bracketChecker(coord, DIRECTIONS[i], opposite, colour, board)) == 1)//if a valid bracketing piece was found, enter the if statment
                {
                    return 1;
                }

            }
            
        }

        return 0;
        
    }

    else
    {
        return 0;
    }
    
    
}