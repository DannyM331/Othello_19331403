#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 20

int playgame();
int initialiseBoard();
int boardPrint(int *a);
int numToChar(int a);
int getMove(char xMove, int yMove);
int playerScore(int colour, int *board);
int coordFormula(int x, int y);
int turnTracker(int a);
int boardUpdater(int coord, int b, int direction, int *board);
int legalMoveChecker(int colour, int coord, int *board);
int pieceChange(int move, int colour, int *board, int directions[]);
int turnTrackerInt(int a);
int validPosition(int coord, int direction, int opposite, int *board);
int bracketEdgeChecker(int coord, int direction, int opposite, int colour, int *board);
int bracketChecker(int coord, int direction, int opposite, int colour, int *board);
int passChecker(int colour, int *board);
int GameOver(int *board);
int writeToFile(int black, int white);

int BLACKPLAYER[MAX_NAME];
int WHITEPLAYER[MAX_NAME];

int DIRECTIONS[8] = {-9,-8,-7,-1,1,7,8,9};
int DIRECTIONSH[5] = {-9,-8,-1,7,8};
int DIRECTIONSA[5] = {-8,-7,1,8,9};

int EMPTY=0;
int BLACK=1;
int WHITE=2;

int WINNER = 0;
int BOARDSIZE = 65;

int main(void)
{
    printf("Welcome to Othello, get ready to play.\n\n");

    playgame();

    printf("Thank you for playing Othello.\n\n");
}

int playgame()
{

    char xMove;
    int yMove;
    int Co_Ord;
    char colour[MAX_NAME];
    int turnCounter = 1;
    int *board;
    int flag = 0;
    int colourInt, test;

    printf("Enter Player 1's name, they will be black.\n");
    scanf("%s", BLACKPLAYER);

    printf("Enter Player 2's name, they will be white.\n");
    scanf("%s", WHITEPLAYER);

    board = initialiseBoard();
    boardPrint(board);
    do
    {
        strcpy(colour, turnTracker(turnCounter));
        colourInt = turnTrackerInt(turnCounter);
        printf("Your turn %s.\n", colour);
        flag = 0;

        while (flag == 0)
        {
            //flag = 0;
            printf("Enter X Co-Ord\n");
            scanf(" %c", &xMove);

            printf("Enter Y Co-Ord\n");
            scanf("%d", &yMove);
            Co_Ord = getMove(xMove, yMove);

            if ((passChecker(colourInt, board)) == 1)
            {
                if ((legalMoveChecker(colourInt, Co_Ord, board)) == 1)
                {
                    printf("was a legal move\n\n");

                    for (int i = 0; i < 8; i++)
                    {
                        if (Co_Ord % 8 == 0)
                        {
                            boardUpdater(Co_Ord, turnCounter, DIRECTIONSH[i], board);
                        }

                        else if ((Co_Ord - 1) % 8 == 0)
                        {
                            boardUpdater(Co_Ord, turnCounter, DIRECTIONSA[i], board);
                        }
                        
                        else
                        {
                            boardUpdater(Co_Ord, turnCounter, DIRECTIONS[i], board);
                        }
                        
                    }
                
                    boardPrint(board);
                    flag = 1;
                }

                else
                {
                    printf("Invalid Input\n");
                }
                
            }
            
            else
            {
                printf("%s has no valid moves, you must pass.\n", colour);
            }
            
  
        }
        
        turnCounter++;
    } while ((GameOver(board)) == 0);
    
}

int initialiseBoard()
{

    int i, *board;
    board = (int*)calloc(BOARDSIZE, sizeof(int));

    for ( i = 1; i <= 64; i++)
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

boardPrint(int *a)
{

    int i, j, k, counter = 1;

    printf("    a   b   c   d   e   f   g   h  [%s:%d  %s:%d]\n", "BLACK", playerScore(BLACK, a), "WHITE", playerScore(WHITE, a));
    
    for ( i = 0; i < 8; i++)
    {
        printf("   --- --- --- --- --- --- --- --- \n");
        printf("%d ", i+1);

        
        for ( j = 0; j < 8; j++)
        {
            
            if (a[counter] == 0)
            {
                printf("|   ");
            }

            else if (a[counter] == 1)
            {
                printf("| B ");
            }

            else
            {
                printf("| W ");
            }
            
            
            
            counter++;
        }
        
        printf("|\n");
    }
    
    printf("   --- --- --- --- --- --- --- ---\n");

}

int getMove(char xMove, int yMove)
{

    int xMoveInt;
    int answer;
    char alphabet[9] = "abcdefgh";

    for (int i = 0; i < 9; i++)
    {
        if (xMove == alphabet[i])
        {
            xMoveInt = i+1;
            
        }
        
    }
    
    answer = coordFormula(xMoveInt, yMove);
    return answer;


}

int playerScore(int colour, int *board)
{

    int i, score = 0;

    for ( i = 1; i <= 64; i++)
    {
        if (board[i] == colour)
        {
            score++;
        }
        
    }
    
    return score;

}

int coordFormula(int x, int y)
{

    int arrayPosition, z, w;
    z = y;
    w = x;
    
    arrayPosition = (z - 1) * (8) + (w);
    return arrayPosition;
}

int turnTracker(int a)
{

    char Black[] = "Black";
    char White[] = "White";

    if ((a % 2) == 0)
    {
        return White;
    }
    
    else
    {
        return Black;
    }
    
}

int boardUpdater(int coord, int b, int direction, int *board)
{

    int opposite, colour;
    int pieceChecker = coord;
    int needsToFlip[8];
    int i = 0;

    if ((b % 2) == 0)
    {
        board[coord] = WHITE;
        opposite = BLACK;
        colour = WHITE;
    }

    else
    {
        board[coord] = BLACK;
        opposite = WHITE;
        colour = BLACK;
    }

    if (((coord % 8) == 0) || ((coord - 1) % 8 == 0))
    {
        if ((bracketEdgeChecker(coord, direction, opposite, colour, board)) == 1)
        {
            do
            {
                pieceChecker += direction;
                if (board[pieceChecker] == opposite)
                {
                    needsToFlip[i] = pieceChecker;
                    i++;
                }
            } while (board[pieceChecker] == opposite);
            
        }
        
    }
    

    else if ((bracketChecker(coord, direction, opposite, colour, board)) == 1)
    {
        do
        {
            pieceChecker += direction;
            if (board[pieceChecker] == opposite)
            {
                needsToFlip[i] = pieceChecker;
                i++;
            }
        
        } while (board[pieceChecker] == opposite);
    
    }
    
    for (int j = 0; j < i; j++)
    {
        board[needsToFlip[j]] = colour;
    }
    

}

int turnTrackerInt(int a)
{

    if ((a % 2) == 0)
    {
        return 2;
    }
    
    else
    {
        return 1;
    }
    
}

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

    if (((board[coord]) == EMPTY) && ((coord % 8) == 0))
    {
        for ( i = 0; i < 5; i++)
        {
            if ((validPosition(coord, DIRECTIONSH[i], opposite, board)) == 1)
            {
                if (bracketEdgeChecker(coord, DIRECTIONSH[i], opposite, colour, board) == 1)
                {
                    return 1;
                }
                
            }
            
        }
        
    }

    else if (((board[coord]) == EMPTY) && (((coord - 1) % 8) == 0))
    {
        for ( i = 0; i < 5; i++)
        {
            //printf("TestA1\n");
            if ((validPosition(coord, DIRECTIONSA[i], opposite, board)) == 1)
            {
                //printf("TestA2\n");
                if (bracketEdgeChecker(coord, DIRECTIONSA[i], opposite, colour, board) == 1)
                {
                    //printf("TestA3\n");
                    return 1;
                }
                
            }
            
        }
        
    }
    
    
    else if ((board[coord]) == EMPTY)
    {
        
        for ( i = 0; i < 8; i++)
        {
            //printf("TEST\n");
            if ((validPosition(coord, DIRECTIONS[i], opposite, board)) == 1)
            {
                //printf("TEST1\n");
                if ((bracketChecker(coord, DIRECTIONS[i], opposite, colour, board)) == 1)
                {
                    //printf("TEST2\n");
                    return 1;
                }

            }
            
        }
        
    }

    else
    {
        return 0;
    }
    
    
}

int validPosition(int coord, int direction, int opposite, int *board)
{

    int pieceChecker;
    pieceChecker = coord + direction;

    //printf("TEST4\n");

    if (board[pieceChecker] == opposite)
    {
        //printf("TEST5\n");
        return 1;
    }

    
    
}

int bracketEdgeChecker(int coord, int direction, int opposite, int colour, int *board)
{

    int pieceChecker, i;

    pieceChecker = coord + direction;

    if ((board[pieceChecker] == opposite) && ((coord - 1) % 8 == 0))
    {
        //printf("TestA6\n");
        while ((board[pieceChecker]) == opposite && (pieceChecker >= 0) && (pieceChecker <= 64) && ((pieceChecker) % 8 != 0)) 
        {
            //printf("TestA7\n");
            pieceChecker += direction;
                    
            if (board[pieceChecker] == colour)
            {
                //printf("TestA8\n");
                return 1;
            }

            // else if ((pieceChecker <= 0) || (pieceChecker >= 64) || (pieceChecker % 8 == 0) || ((pieceChecker - 1) % 8 == 0))
            // {
            //     return 0;
            // }
                    
                    
        }
                
    }

    else if ((board[pieceChecker] == opposite) && (coord % 8 == 0))
    {
        while ((board[pieceChecker]) == opposite && (pieceChecker >= 0) && (pieceChecker <= 64) && ((pieceChecker - 1) % 8 != 0))
        {
            pieceChecker += direction;
                    
            if (board[pieceChecker] == colour)
            {
                return 1;
            }

            // else if ((pieceChecker <= 0) || (pieceChecker >= 64) || (pieceChecker % 8 == 0) || ((pieceChecker - 1) % 8 == 0))
            // {
            //     return 0;
            // }
                    
                    
        }
                
    }

}

int bracketChecker(int coord, int direction, int opposite, int colour, int *board)
{

    int pieceChecker, i;

    pieceChecker = coord + direction;
    
    if (board[pieceChecker] == opposite)
    {
        
        while (((board[pieceChecker]) == opposite) && (pieceChecker > 0) && (pieceChecker < 64) && (pieceChecker % 8 != 0) && ((pieceChecker - 1) % 8 != 0))
        {
            pieceChecker += direction;

            if (board[pieceChecker] == colour)
            {
                return 1;
            }

            // else if ((pieceChecker <= 0) || (pieceChecker >= 64) || (pieceChecker % 8 == 0) || ((pieceChecker - 1) % 8 == 0))
            // {
            //     return 0;
            // }

        }
        
    }

}

int passChecker(int colour, int *board)
{

    int i;

    for (int i = 1; i < 65; i++)
    {
        if ((legalMoveChecker(colour, i, board)) == 1)
        {
            return 1;
        }
        
    }

}

int GameOver(int *board)
{

    //FILE *fileptr;
    int blackScore, whiteScore;

    blackScore = playerScore(BLACK, board);
    whiteScore = playerScore(WHITE, board);

    if ((((passChecker(BLACK, board)) != 1) && ((passChecker(WHITE, board)) != 1)) || ((blackScore + whiteScore) == 5))
    {
        if (blackScore > whiteScore)
        {
            printf("Black - %s has won the game!\nThe final score was [BLACK:%d  WHITE:%d]\n", BLACKPLAYER, blackScore, whiteScore);
        }

        else if (whiteScore > blackScore)
        {
            printf("White - %s has won the game!\nThe final score was [BLACK:%d  WHITE:%d]\n", WHITEPLAYER, blackScore, whiteScore);
        }

        else
        {
            printf("Its a Draw!\nThe final score was [BLACK:%d  WHITE:%d]\n", blackScore, whiteScore);
        }
        
        // if ((fopen("othello-results.txt", "w")) == NULL)
        // {
        //     printf("Could not find / open othello-results.txt.\n");
        // }

        // else
        // {
        //     if (blackScore > whiteScore)
        //     {
        //         fprintf(fileptr, "%s Won! The score was [%s (Black):%d %s (White):%d]\n", BLACKPLAYER, BLACKPLAYER, blackScore, WHITEPLAYER, whiteScore);
        //     }

        //     else if (whiteScore > blackScore)
        //     {
        //     fprintf(fileptr, "%s Won! The score was [%s (Black):%d %s (White):%d]\n", WHITEPLAYER, BLACKPLAYER, blackScore, WHITEPLAYER, whiteScore);
        //     }

        //     else
        //     {
        //     fprintf(fileptr, "Its a Draw! The score was [%s (Black):%d %s (White):%d]\n", BLACKPLAYER, blackScore, WHITEPLAYER, whiteScore);
        //     }
        
        
        
        // }

        // fclose(fileptr);

        writeToFile(blackScore, whiteScore);
        
        return 1;
    }
    
    else
    {
        return 0;
        //fclose(fileptr);
    }
    
}

int writeToFile(int black, int white)
{

    FILE *fileptr;

    if (fileptr =(fopen("othello-results.txt", "w")) == NULL)
    {
        printf("Could not find / open othello-results.txt.\n");
    }

    else
    {
        if (black > white)
        {
            fprintf(fileptr, "%s Won! The score was [%s (Black):%d %s (White):%d]\n", BLACKPLAYER, BLACKPLAYER, black, WHITEPLAYER, white);
        }

        else if (white > black)
        {
            fprintf(fileptr, "%s Won! The score was [%s (Black):%d %s (White):%d]\n", WHITEPLAYER, BLACKPLAYER, black, WHITEPLAYER, white);
        }

        else
        {
            fprintf(fileptr, "Its a Draw! The score was [%s (Black):%d %s (White):%d]\n", BLACKPLAYER, black, WHITEPLAYER, white);
        }
        
        printf("The results have been posted into othello-results.txt!\n");
        
    }

    fclose(fileptr);
    return 0;

}