#include "othello.h"

int main(void)
{
    printf("Welcome to Othello, get ready to play.\n\n");

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

    printf("\nThank you for playing Othello.\n\n");
}

