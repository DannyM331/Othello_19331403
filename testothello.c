#include <stdio.h>

int boardPrint(int *board);
int setBoard(int *board);

int T = 0;
int L = 1;
int E = 2;
int B = 3;
int W = 4;
int G = 5;

int main()
{

    int *board;
    board = (int*)calloc(289, sizeof(int));

    setBoard(board);
    
    boardPrint(board);
}

boardPrint(int *board)
{

    int i, j, k, counter = 1;

    //printf("   a   b   c   d   e   f   g   h  [%s:%d  %s:%d]\n", "BLACK", playerScore(BLACK, a), "WHITE", playerScore(WHITE, a));
    
    for ( i = 0; i < 17; i++)
    {
        
        //printf("%d ", i+1);
        
        

        
        for ( j = 0; j < 17; j++)
        {
            
            if (board[counter] == 0)
            {
                printf("---");
            }

            else if (board[counter] == 1)
            {
                printf("|");
            }

            else if (board[counter] == 2)
            {
                printf("   ");
            }

            else if (board[counter] == 5)
            {
                printf(" ");
            }
            
            counter++;
        }
        
        printf("\n");
    }
    
    printf("\n");

}

int setBoard(int *board)
{
    int i, j, counter = 1, rowCounter = 1;

    for ( i = 1; i < 289; i++)
    {
        
        if ((i % 17) == 0)
        {
            rowCounter++;
        }

        if ((counter % 34) == 0)
        {
            board[i] = L;
        }

        else if (counter == 289)
        {
            board[i] = G;
        }
        
        
        else if ((((counter - (17 * rowCounter)) % 2) == 0) && ((rowCounter % 2)) != 0)
        {
            board[i] = G;
        }

        else if ((((counter - (17 * rowCounter)) % 2) != 0) && ((rowCounter % 2)) != 0)
        {
            board[i] = T;
        }
        
        else if ((((counter - (17 * rowCounter)) % 2) == 0) && ((rowCounter % 2)) == 0)
        {
            board[i] = L;
        }
        
        else if ((((counter - (17 * rowCounter)) % 2) != 0) && ((rowCounter % 2)) == 0)
        {
            board[i] = E;
        }
        
        counter++;
    }

    for ( i = 1; i < 289; i++)
    {
        printf("%d ", board[i]);
    }
    
    printf("\n");
    

}