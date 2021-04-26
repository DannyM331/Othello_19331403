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
int boardUpdater(int a, int b, int *board);
//int boardCopy(int *board);

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
    int Co_Ord;
    char name[MAX_NAME];
    int turnCounter = 1;
    int *board, *board1;

    printf("Enter Player 1's name, they will be black.\n");
    scanf("%s", BLACKPLAYER);

    printf("Enter Player 2's name, they will be white.\n");
    scanf("%s", WHITEPLAYER);

    board = initialiseBoard();
    boardPrint(board);
    
    //board1 = boardCopy(board);
    do
    {
        strcpy(name, turnTracker(turnCounter));

        printf("Your turn %s.\n", name);
        printf("Enter X Co-Ord\n");
        scanf(" %c", &xMove);

        printf("Enter Y Co-Ord\n");
        scanf("%d", &yMove);
        Co_Ord = getMove(xMove, yMove);
        
        do
        {
            boardUpdater(Co_Ord, turnCounter, board);
            boardPrint(board);
        } while (1 == 2);
        
        
        WINNER++;
        turnCounter++;
    } while (WINNER != 10);
    
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

boardPrint(int *a)
{

    int i, j, counter = 0;

    //a = initialiseBoard();

    printf("  a b c d e f g h [%s:%d  %s:%d]\n", "BLACK", playerScore(BLACK, a), "WHITE", playerScore(WHITE, a));
    
    for ( i = 0; i < 8; i++)
    {
        printf("%d ", i+1);
        for ( j = 0; j < 8; j++)
        {
            printf("%c ", numToChar(a[counter]));
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

    int arrayPosition, z, w;
    z = y;
    w = x;

    arrayPosition = (z - 1) * (8) + (w-1);
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

int boardUpdater(int a, int b, int *board)
{

    printf("Entered boardUpdater\n");

    if ((b % 2) == 0)
    {
        board[a] = WHITE;
        printf("%d", board[a]);
    }

    else
    {
        board[a] = BLACK;
        printf("%d", board[a]);
    }
    
    for (int i = 1; i < 65; i++)
    {
        printf("%d ", board[i]);
    }
    printf("\n");
    

}

// int boardCopy(int *board)
// {

//     int *cpyBoard;

//     cpyBoard = (int*)calloc(BOARDSIZE, sizeof(int)); 

//     for (int i = 1; i <= 64; i++)
//     {
//         cpyBoard[i] = board[i];
//     }
    
//     boardPrint(cpyBoard);

//     return cpyBoard;
// }