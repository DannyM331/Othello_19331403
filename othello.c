#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 20

int playgame();
int initialiseBoard();
int boardPrint(int *board);
int numToChar(int a);
int getMove(char xMove, int yMove);
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

    char xMove;
    int yMove;

    printf("Enter Player 1's name, they will be black.\n");
    scanf("%s", BLACKPLAYER);

    printf("Enter Player 2's name, they will be white.\n");
    scanf("%s", WHITEPLAYER);

    boardPrint(initialiseBoard());

    printf("Enter X Co-Ord\n");
    scanf(" %c", &xMove);
    printf("Enter Y Co-Ord\n");
    scanf("%d", &yMove);

    //printf("%c %d", xMove, yMove);
    getMove(xMove, yMove);
    
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

int getMove(char xMove, int yMove)
{

    int xMoveInt;
    int answer;
    char alphabet[9] = "abcdefgh";

    for (int i = 0; i < 8; i++)
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

    printf("Entered\n");
    printf("%d %d\n", x, y);
    int arrayPosition, z;
    z = y;

    arrayPosition = (z - 1) * (8) + x;
    printf("%d", arrayPosition);

}