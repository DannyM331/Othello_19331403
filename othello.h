#ifndef othello
/* These are the libarys that i used */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME 20 // The max lenght of a name.

int playgame();// This is the function that plays the game, it is the hub of where all my functions are called.
int initialiseBoard();// This function initialises the board.
int boardPrint(int *a);// This function prints the current version of the board.
int numToChar(int a);// This translates the letters part of the co - ords into numbers.
int getMove(char xMove, int yMove);// This function gets the next move.
int playerScore(int colour, int *board);// This function  calculates the score for the given player.
int coordFormula(int x, int y);// This function takes the x and y co-ord and translates it into a location in the board array.
int turnTracker(int a);// This fucntion checks whos turn it is, either white or black.
int turnTrackerInt(int a);// This function does the same as turnTracker but returns a 1 if black or 2 if white.
int boardUpdater(int coord, int b, int direction, int *board);// This funciton updates the board with new moves.
int legalMoveChecker(int colour, int coord, int *board);// This function checks if the given move is legal.
int validPosition(int coord, int direction, int opposite, int *board);// This funciton checks if there is atleast one of the surrounding pieces are of the opposite colours.
int bracketEdgeChecker(int coord, int direction, int opposite, int colour, int *board);// While the co-ord is in the A or H column, this functions checks if the given move has a bracketing piece of the same colour.
int bracketChecker(int coord, int direction, int opposite, int colour, int *board);// While the co-ord isn't in the A or H column, this function checks if the given move has a bracketing piece of the same colour.
int passChecker(int colour, int *board);// This function checks if the current player has any valid moves in general, if not they have to pass.
int GameOver(int *board);// This function checks to see if any of the conditions have been met for the game to be over.
int writeToFile(int black, int white);// This funciton writes the result to the specific file.

/* These are my global parameters */
int BLACKPLAYER[MAX_NAME];//This array holds the name for the black player.
int WHITEPLAYER[MAX_NAME];//This array holds the name for the white player.

/* The Directions are realative to the 8x8 othello board, e.g. if youre co-ord is 22, to move up, you add -8, to move down you add 8 and so on. */
int DIRECTIONS[8] = {-9,-8,-7,-1,1,7,8,9};//These are the possible directions that the player can move while not in the A or H column.
int DIRECTIONSH[5] = {-9,-8,-1,7,8};//These are the possible directions that the player can move while in the H column.
int DIRECTIONSA[5] = {-8,-7,1,8,9};//These are the possible directions that the player can move while in the A column.

/* These are the number representation for the pieces in the board array */
int EMPTY=0;
int BLACK=1;
int WHITE=2;
#define othello
#endif