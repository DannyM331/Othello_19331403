#include <stdio.h>
#include <string.h>

int main(void)
{

    char xMove;
    char alphabet[9] = "abcdefgh";

    scanf(" %c", &xMove);
    printf("%c\n", xMove);
    printf("%c\n", alphabet[1]);

    for (int i = 0; i < 8; i++)
    {
        printf("%c %c ", xMove, alphabet[i]);
        if (xMove == alphabet[i])
        {
            printf("Entered at %d\n", i);
            //printf(" %c %c", &xMove[0], &alphabet[i]);
        }

        else
        {
            printf("Failed\n");
        }
        
        
    }
    
    
    

}