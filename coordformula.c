#include "othello.h"

int coordFormula(int x, int y)
{
    /* take in the x and y as intagers are return the equivalent place in the array */
    int arrayPosition, z, w;
    z = y;
    w = x;
    
    arrayPosition = (z - 1) * (8) + (w);//this is the formula
    return arrayPosition;
}