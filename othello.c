#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_NAME 20

int playgame();
int initialiseBoard();
int boardPrint(int *board);
int numToChar(int a);
int getMove(char string[]);

int BLACKPLAYER[MAX_NAME];
int WHITEPLAYER[MAX_NAME];

int EMPTY=0;
int BLACK=1;
int WHITE=2;

int WINNER = 0;
int BOARDSIZE = 64;

int main(void)
{
    printf("Welcome to Othello, get ready to play.\n\n");

    playgame();

    printf("Thank you for playing Othello.\n\n");
}

int playgame()
{

    printf("Enter Player 1's name, they will be black.\n");
    scanf("%s", BLACKPLAYER);

    printf("Enter Player 2's name, they will be white.\n");
    scanf("%s", WHITEPLAYER);

    boardPrint(initialiseBoard());
    
    do
    {
        printf("Black, please enter your move\n");
        getMove();

        printf("White, please enter your mover\n");
        getMove();
    } while (WINNER == 0);
    

}

int initialiseBoard()
{

    int i, j, counter = 0, *board;
    board = (int*)calloc(BOARDSIZE, sizeof(int));

    for ( i = 0; i < 64; i++)
    {
        if ((i == 27) || (i == 36))
        {
            board[i] = WHITE;
        }

        else if ((i == 28) || (i == 35))
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

boardPrint(int *board)
{

    int i, j, counter = 0;

    board = initialiseBoard();

    printf("  a b c d e f g h\n");
    
    for ( i = 0; i < 8; i++)
    {
        printf("%d ", i+1);
        for ( j = 0; j < 8; j++)
        {
            printf("%c ", numToChar(board[counter]));
            counter++;
        }
        
        printf("\n");
    }
    
    printf("\n");

}

int numToChar(int a)
{

    char charArray[4] = ".WB";
    return charArray[a];

}

int getMove(char string[])
{

    int yMove;
    char xMove;

    scanf("%c%d", xMove, yMove);

}