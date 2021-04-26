#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_NAME 20

int playgame();
int initialiseBoard();
int boardPrint(int *board);
int numToChar(int a);
int getMove();
int playerScore(int colour, int *board);
int coordFormula(int x, int y);

int BLACKPLAYER[MAX_NAME];
int WHITEPLAYER[MAX_NAME];

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

    printf("Enter Player 1's name, they will be black.\n");
    scanf("%s", BLACKPLAYER);

    printf("Enter Player 2's name, they will be white.\n");
    scanf("%s", WHITEPLAYER);

    boardPrint(initialiseBoard());

    getMove();
    
    // do
    // {
    //     printf("Black, please enter your move\n");
    //     //getMove();

    //     printf("White, please enter your mover\n");
    //     //getMove();
    // } while (WINNER == 0);
    

}

int initialiseBoard()
{

    int i, j, counter = 0, *board;
    board = (int*)calloc(BOARDSIZE, sizeof(int));

    for ( i = 1; i <= 64; i++)
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

    printf("  a b c d e f g h [%s:%d  %s:%d]\n", "BLACK", playerScore(BLACK, board), "WHITE", playerScore(WHITE, board));
    
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

int getMove()
{

    int yMove;
    char xMove;

    scanf("%c%d", xMove, yMove);

    if (xMove = 'a')
    {
        xMove = 1;
    }

    else if (xMove = 'b')
    {
        xMove = 2;
    }

    coordFormula(xMove, yMove);    

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

    int arrayPosition, z;
    z = y;

    arrayPosition = (z - 1) * (8) + x;
    return arrayPosition;

}