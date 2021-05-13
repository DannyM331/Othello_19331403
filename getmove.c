#include "othello.h"

int getMove(char xMove, int yMove)
{
    int xMoveInt;
    int answer;
    char alphabet[9] = "abcdefgh";//this is the possible list of letters

    for (int i = 0; i < 9; i++)
    {
        if (xMove == alphabet[i])//if the letter is the same as alphabet[i], enter the if statment
        {
            xMoveInt = i+1;
            
        }
        
    }
    
    answer = coordFormula(xMoveInt, yMove);
    return answer;

}