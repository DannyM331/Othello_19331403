#include "othello.h"

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