//This program is othello in the c programing language.
//All code was written by Danny Murray - 19331403.
//NOTE: I used arrays over stuctures because I found it more efficent and.
//I emailed john about this on the 1/5/21 and i never got a responce.

/* These are the libarys that i used */
#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 20 // The max lenght of a name.

int playgame();// This is the function that plays the game, it is the hub of where all my functions are called.
int initialiseBoard();// This function initialises the board.
int boardPrint(int *a);// This function prints the current version of the board.
int numToChar(int a);// This translates the letters part of the co - ords into numbers.
int getMove(char xMove, int yMove);// This function gets the next move.
int playerScore(int colour, int *board);// This function  calculates the score for the given player.
int coordFormula(int x, int y);// This function takes the x and y co-ord and translates it into a location in the board array.
int turnTracker(int a);// This fucntion checks whos turn it is, either white or black.
int turnTrackerInt(int a);// This function does the same as turnTracker but returns a 1 if black or 2 if white.
int boardUpdater(int coord, int b, int direction, int *board);// This funciton updates the board with new moves.
int legalMoveChecker(int colour, int coord, int *board);// This function checks if the given move is legal.
int validPosition(int coord, int direction, int opposite, int *board);// This funciton checks if there is atleast one of the surrounding pieces are of the opposite colours.
int bracketEdgeChecker(int coord, int direction, int opposite, int colour, int *board);// While the co-ord is in the A or H column, this functions checks if the given move has a bracketing piece of the same colour.
int bracketChecker(int coord, int direction, int opposite, int colour, int *board);// While the co-ord isn't in the A or H column, this function checks if the given move has a bracketing piece of the same colour.
int passChecker(int colour, int *board);// This function checks if the current player has any valid moves in general, if not they have to pass.
int GameOver(int *board);// This function checks to see if any of the conditions have been met for the game to be over.
int writeToFile(int black, int white);// This funciton writes the result to the specific file.

/* These are my global parameters */
int BLACKPLAYER[MAX_NAME];//This array holds the name for the black player.
int WHITEPLAYER[MAX_NAME];//This array holds the name for the white player.

/* The Directions are realative to the 8x8 othello board, e.g. if youre co-ord is 22, to move up, you add -8, to move down you add 8 and so on. */
int DIRECTIONS[8] = {-9,-8,-7,-1,1,7,8,9};//These are the possible directions that the player can move while not in the A or H column.
int DIRECTIONSH[5] = {-9,-8,-1,7,8};//These are the possible directions that the player can move while in the H column.
int DIRECTIONSA[5] = {-8,-7,1,8,9};//These are the possible directions that the player can move while in the A column.

/* These are the number representation for the pieces in the board array */
int EMPTY=0;
int BLACK=1;
int WHITE=2;

int main(void)
{
    printf("Welcome to Othello, get ready to play.\n\n");

    playgame();//call the playgame function

    printf("\nThank you for playing Othello.\n\n");
}

int playgame()
{
    char xMove;//this holds the x co-ord character
    int yMove;//this holds the y co-ord number
    int Co_Ord;//this holds the converted array possition
    char colour[MAX_NAME];//this holds the current colour
    int turnCounter = 1;//this holds the current turn counter
    int *board;//this is the board array pointer
    int flag = 0;//this is my flag intager, very similar to a boolean value
    int colourInt;//this holds the current colour as a number

    printf("\nEnter Player 1's name, they will be black.\n");
    scanf("%s", BLACKPLAYER);//scans in the black players name

    printf("\nEnter Player 2's name, they will be white.\n");
    scanf("%s", WHITEPLAYER);//scans in the whiteplayers name

    printf("\nPlease enter the moves in the format xy where x is your letter and y is your number, example: c3\n");

    board = initialiseBoard();//sets the board pointer to the initialiseBoard funtions
    boardPrint(board);//prints the array "baord", in the 8x8 game board formate
    do
    {
        strcpy(colour, turnTracker(turnCounter));//this copies the current turns colour into the string "colour"
        colourInt = turnTrackerInt(turnCounter);//this copies the current colour into the intager value "colourInt"
        printf("\nYour turn %s.\n", colour);
        flag = 0;
        if ((passChecker(colourInt, board)) == 1)//if the current player has a move, enter this if statment
        {
            while (flag == 0)//exit this statment if flag is anything other than 0
            {
                printf("Enter your move.\n");
                scanf(" %c%d", &xMove, &yMove);//scans in x co-ord

                Co_Ord = getMove(xMove, yMove);//call getmove and set the array position as "Co_Ord"

                if ((legalMoveChecker(colourInt, Co_Ord, board)) == 1)//if the given move was legal, enter this if statment
                {
                    printf("was a legal move\n\n");

                    for (int i = 0; i < 8; i++)
                    {
                        if (Co_Ord % 8 == 0)//if the co-ord is in the H column, enter this if statment
                        {
                            boardUpdater(Co_Ord, turnCounter, DIRECTIONSH[i], board);//update the board with the given move
                        }

                        else if ((Co_Ord - 1) % 8 == 0)//if the co-ord is in the A column, enter this if statment
                        {
                            boardUpdater(Co_Ord, turnCounter, DIRECTIONSA[i], board);//update the board with the given move
                        }
                        
                        else//if the move isnt in the A or H column, enter this else statment
                        {
                            boardUpdater(Co_Ord, turnCounter, DIRECTIONS[i], board);//update the board with the given move
                        }
                        
                    }
                
                    boardPrint(board);//after the move has been updated, print the new board
                    flag = 1;
                }

                else//if the move was not legal, enter this else statment
                {
                    printf("That move was invalid.\n");
                }
                
            }
         
  
        }

        else//if the player ahs no valid moves, they must pass to the other player
        {
            printf("%s has no valid moves, you must pass.\n", colour);
        }
        
        turnCounter++;//increase turn counter
    } while ((GameOver(board)) == 0);//exit the loop if the game is over
    
}

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

boardPrint(int *a)
{
    int i, j, k, counter = 1;

    printf("    a   b   c   d   e   f   g   h   [%s (%s):%d  %s (%s):%d]\n", "BLACK", BLACKPLAYER, playerScore(BLACK, a), "WHITE", WHITEPLAYER, playerScore(WHITE, a));//this prints out the X axis letters and the current score
    
    for ( i = 0; i < 8; i++)
    {
        printf("   --- --- --- --- --- --- --- --- \n");
        printf("%d ", i+1);//this prints out the Y axis numbers

        
        for ( j = 0; j < 8; j++)
        {
            
            if (a[counter] == EMPTY)//if the array at the position "counter", is = EMPTY, print out the EMPTY piece
            {
                printf("|   ");
            }

            else if (a[counter] == BLACK)//if the array at the position "counter", is = BLACK, print out the black piece
            {
                printf("| B ");
            }

            else//if its not EMPTY or BLACK it means its WHITE so print the white piece
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

int coordFormula(int x, int y)
{
    /* take in the x and y as intagers are return the equivalent place in the array */
    int arrayPosition, z, w;
    z = y;
    w = x;
    
    arrayPosition = (z - 1) * (8) + (w);//this is the formula
    return arrayPosition;
}

int turnTracker(int a)
{
    char Black[] = "Black";
    char White[] = "White";

    if ((a % 2) == 0)//if a is even then its white turn
    {
        return White;
    }
    
    else//if its not even then its odd, meaning its blacks turn
    {
        return Black;
    }
    
}

int turnTrackerInt(int a)
{
    if ((a % 2) == 0)//if a is even then its white turn
    {
        return 2;
    }
    
    else//if its not even then its odd, meaning its blacks turn
    {
        return 1;
    }
    
}

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

int validPosition(int coord, int direction, int opposite, int *board)
{
    int pieceChecker;
    pieceChecker = coord + direction;

    if (board[pieceChecker] == opposite)//if the pieceChecker is of the opposite colour, enter the if statment
    {
        return 1;
    }
    
}

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

int passChecker(int colour, int *board)
{
    int i;

    /* this keeps checking looping until it either finds a legal move or has gone through all the pieces */
    for (int i = 1; i < 65; i++)
    {
        if ((legalMoveChecker(colour, i, board)) == 1)//if a legal move is found, enter the if statment
        {
            return 1;
        }
        
    }

    return 0;

}

int GameOver(int *board)
{
    int blackScore, whiteScore;

    blackScore = playerScore(BLACK, board);//set "blackscore" to equal Blacks's score
    whiteScore = playerScore(WHITE, board);//set "whitescore" to equal Whites'S score

    if ((((passChecker(BLACK, board)) != 1) && ((passChecker(WHITE, board)) != 1)) || ((blackScore + whiteScore) == 64))//if black and white have no valid moves or the total score is 64, enter the if statment
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

int writeToFile(int black, int white)
{
    FILE *fp = fopen("othello-results.txt", "w");//set the file pointer "fp" to open "othello-results.txt"

    if (fp == NULL)//if fp = null, enter this if statment
    {
        printf("Could not find / open othello-results.txt.\n");
    }

    else//if fp isnt = null, enter this if statment
    {
        if (black > white)//if black won, enter this if statment
        {
            fprintf(fp, "%s Won! The score was [%s (Black):%d %s (White):%d]\n", BLACKPLAYER, BLACKPLAYER, black, WHITEPLAYER, white);
        }

        else if (white > black)//if white won, enter this if statment
        {
            fprintf(fp, "%s Won! The score was [%s (Black):%d %s (White):%d]\n", WHITEPLAYER, BLACKPLAYER, black, WHITEPLAYER, white);
        }

        else//if neither won, enter this if statment
        {
            fprintf(fp, "Its a Draw! The score was [%s (Black):%d %s (White):%d]\n", BLACKPLAYER, black, WHITEPLAYER, white);
        }
        
        printf("\nThe results have been posted into othello-results.txt!\n");
        
    }

    fclose(fp);//close the file pointer "fp"
    return 0;

}