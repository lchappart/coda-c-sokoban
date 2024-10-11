#include <stdlib.h>
#include <stdio.h> 
#include <time.h>


int main()
{
    int x, y, xp, yp, xb, yb;
    int wincondition = 0;
    int *coord= malloc(6 * sizeof(int));
    int **tab_grid = malloc(11 * sizeof(int*));

    srand(time(NULL));
    for (int i = 0; i < 11; i++) {
        tab_grid[i] = malloc(11 * sizeof(int));
    }
    tab_grid[10] = NULL;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 0 || i == 9 || j == 0 || j == 9) {
                tab_grid[i][j] = 1;
            } else {
                tab_grid[i][j] = 0;
            }
        }
        tab_grid[i][10] = 9;
    }

    printf("Bienvenue dans ce Sokoban ! Commençons !\n");
    coord = initgame(); 
    
    x = coord[0];
    y = coord[1];
    xp = coord[2];
    yp = coord[3];
    xb = coord[4];
    yb = coord[5];

    tab_grid[x][y] = 2;
    tab_grid[xb][yb] = 3;
    tab_grid[xp][yp] = 4;
    
    printgrid(tab_grid);

    while (wincondition != 1)
    {
        
        coord = coup(coord);
        majgrid(tab_grid, coord);
        printgrid(tab_grid);
        wincondition = wincheck(coord);
    }

    free(coord);
    for (int i = 0; i < 11; i++) {
        free(tab_grid[i]);
    }
    free(tab_grid);

    return 0; 
}
