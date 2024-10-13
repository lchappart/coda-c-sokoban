#include <stdlib.h>
#include <stdio.h> 
#include <time.h>
#include "sokoban.h"

int wincheck(int *coord)
{    
    if ((coord[2] == coord[4]) && (coord[3] == coord[5])) // Si les coordonnées de la caisse  et de l'arrivé sont les mêmes alors c'est gagné
    {
        printf("C'est gagné !!\n");
        return 1;
    }
    else if ((coord[4] == 1 && coord[5] == 1) || (coord[4] == 1 && coord[5] == 8) || 
        (coord[4] == 8 && coord[5] == 1) || (coord[4] == 8 && coord[5] == 8)) //SI la caisse est coincée dans un coin, alors la partie est perdue
    {
        printf("Vous êtes coincé dans un coin, vous avez perdu.\n");
        return 1;
    }

    return 0;
    {
        return 0;
    }

}



int *initgame()
{
    int *initcoor = calloc(6, sizeof(int));
    for (int i = 0; i < 4; i++)
    {
        while (initcoor[i] == 0)
        {
            initcoor[i] = rand() % 9;
        }
    }
    
    for (int i = 4; i < 6; i++)
    {
        while ((initcoor[i] == 0) || (initcoor[i] == 8) || (initcoor[i] == 1))
        {
            initcoor[i] = rand() % 9;
        }
    }
    return initcoor;
}

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
        tab_grid[i][10] = 9; // Ca va servir pour la fonction qui print (Ca sera le \n)
    }
    system("clear");
    printf("Bienvenue dans ce Sokoban ! Commençons !\n");
    coord = initgame(); // Le tableau coord prendra les valeurs aléatoires donnéees par la fonction initgame
    
    x = coord[0];
    y = coord[1];
    xp = coord[2];
    yp = coord[3];//Attribution des valeurs grâce à coord
    xb = coord[4];                                                                                                                           
    yb = coord[5];

    tab_grid[x][y] = 2; //Aux coordonnées du joueur, attribuer la valeur 2
    tab_grid[xb][yb] = 3;//Aux coordonnées de la boîte, attribuer la valeur 3
    tab_grid[xp][yp] = 4;//Aux coordonnées de l'arrivée, attribuer la valeur 4
    
    printgrid(tab_grid); // Voir fonction printgrid

    while (wincondition != 1) // Boucle du jeu
    {
        
        coord = coup(coord); // Voir coup
        majgrid(tab_grid, coord);// VOir maj_grid
        printgrid(tab_grid);//Revoir printgrid
        wincondition = wincheck(coord);//Voir wincheck
    }

    free(coord);
    for (int i = 0; i < 11; i++) {
        free(tab_grid[i]);
    }
    free(tab_grid);

    return 0; 
}
