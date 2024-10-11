#ifndef SOKOBAN_H
#define SOKOBAN_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int wincheck(int *coord);
void printgrid(int **tab);
int *coup(int *coord);
void majgrid(int **tab_grid, int *coord);
int *initgame();

#endif