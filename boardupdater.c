#include "othello.h"

int boardUpdater(int coord, int b, int direction, int *board)
{
    int opposite, colour;
    int pieceChecker = coord;
    int needsToFlip[8];
    int i = 0;

    if ((b % 2) == 0)//if b(the current turn) is even, that means its whites turn, set the following information to represent that
    {
        board[coord] = WHITE;
        opposite = BLACK;
        colour = WHITE;
    }

    else//if b isnt even, that means its black, set the following information to represent that
    {
        board[coord] = BLACK;
        opposite = WHITE;
        colour = BLACK;
    }

    if (((coord % 8) == 0) || ((coord - 1) % 8 == 0))//if the co-ord is in either the A or H column, enter this if statment
    {
        if ((bracketEdgeChecker(coord, direction, opposite, colour, board)) == 1)//if there is a valid bracket piece, enter this if statment
        {
            do
            {
                pieceChecker += direction;
                if (board[pieceChecker] == opposite)//if the current piece is the opposite colour, enter this if statment
                {
                    needsToFlip[i] = pieceChecker;//add it to the "needsToFlip" array
                    i++;
                }
            } while (board[pieceChecker] == opposite);//exit when the piece is not of the opposite colour
            
        }
        
    }
    

    else if ((bracketChecker(coord, direction, opposite, colour, board)) == 1)//if the co-ord is in any other column and there is infact a valid bracket piece, enter this if statment
    {
        do
        {
            pieceChecker += direction;
            if (board[pieceChecker] == opposite)//if the current piece is the opposite colour, enter this if statment
            {
                needsToFlip[i] = pieceChecker;//add it to the "needsToFlip" array
                i++;
            }
        
        } while (board[pieceChecker] == opposite);//exit when the piece is not of the opposite colour
    
    }
    
    for (int j = 0; j < i; j++)//this for loop flips everything between the co-ord and the bracketing piece
    {
        board[needsToFlip[j]] = colour;
    }
    

}