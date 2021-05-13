#include "othello.h"

int writeToFile(int black, int white)
{
    FILE *fp = fopen("othello-results.txt", "w+");//set the file pointer "fp" to open "othello-results.txt"

    /* These set the time */
    time_t t;
    time(&t);

    if (fp == NULL)//if fp = null, enter this if statment
    {
        printf("Could not find / open othello-results.txt.\n");
    }

    else//if fp isnt = null, enter this if statment
    {
        if (black > white)//if black won, enter this if statment
        {
            fprintf(fp, "%s Won! The score was [%s (Black):%d %s (White):%d] - %s\n", BLACKPLAYER, BLACKPLAYER, black, WHITEPLAYER, white, ctime(&t));
        }

        else if (white > black)//if white won, enter this if statment
        {
            fprintf(fp, "%s Won! The score was [%s (Black):%d %s (White):%d] - %s\n", WHITEPLAYER, BLACKPLAYER, black, WHITEPLAYER, white, ctime(&t));
        }

        else//if neither won, enter this if statment
        {
            fprintf(fp, "Its a Draw! The score was [%s (Black):%d %s (White):%d] - %s\n", BLACKPLAYER, black, WHITEPLAYER, white,  ctime(&t));
        }
        
        printf("\nThe results have been posted into othello-results.txt!\n");
        
    }

    fclose(fp);//close the file pointer "fp"
    return 0;

}