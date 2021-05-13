#include "othello.h"

int GameOver(int *board)
{
    int blackScore, whiteScore;

    blackScore = playerScore(BLACK, board);//set "blackscore" to equal Blacks's score
    whiteScore = playerScore(WHITE, board);//set "whitescore" to equal Whites'S score

    if ((((passChecker(BLACK, board)) != 1) && ((passChecker(WHITE, board)) != 1)) || ((blackScore + whiteScore) == 5))//if black and white have no valid moves or the total score is 64, enter the if statment
    {
        if (blackScore > whiteScore)//if black won, enter this if statment
        {
            printf("\nBlack - %s has won the game!\nThe final score was [BLACK:%d  WHITE:%d]\n", BLACKPLAYER, blackScore, whiteScore);
        }

        else if (whiteScore > blackScore)//if white won, enter this if statment
        {
            printf("\nWhite - %s has won the game!\nThe final score was [BLACK:%d  WHITE:%d]\n", WHITEPLAYER, blackScore, whiteScore);
        }

        else//if neither won, enter this if statment
        {
            printf("\nIts a Draw!\nThe final score was [BLACK:%d  WHITE:%d]\n", blackScore, whiteScore);
        }
        
        writeToFile(blackScore, whiteScore);//call write to file
        
        return 1;
    }
    
    else
    {
        return 0;
    }
    
}