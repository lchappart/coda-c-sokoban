#include <stdlib.h>
#include <stdio.h> 
#include <time.h>

void printgrid(int **tab, int *coord)
{
    int i = 0;
    int j;
    printf("Joueur : (%d;%d)\n", coord[0], coord[1]);
    printf("Boite : (%d;%d)\n", coord[4], coord[5]);// Affiche les coordonnées du joueur et de la boite et de l'arrivée
    printf("Arrivée : (%d;%d)\n", coord[2], coord[3]);
    while (tab[i] != NULL)
    {
        j = 0;
        printf("\n");
        while(tab[i][j] != 9)
        {
            if (tab[i][j] == 0)
            {
                printf(" ");
            }
            else if (tab[i][j] == 1)
            {
                printf("#");
            }
            else if (tab[i][j] == 2)
            {
                printf("o");                        // Traduit le tableau en printf
            }
            else if (tab[i][j] == 3)
            {
                printf("X");
            }
            else if (tab[i][j] == 4)
            {
                printf(".");
            }
            else{
                printf("Le caractère n'est pas reconnu\n");
            }
            j++;
        } 
        i++;  
    }
    printf("\n");
}



void majgrid(int **tab_grid, int *coord)
{
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if (tab_grid[i][j] != 1)
                tab_grid[i][j] = 0;
        }                                   //Sert à actualiser la position du joueur, de la caisse  et de l'arrivée.
    }
    tab_grid[coord[2]][coord[3]] = 4;
    tab_grid[coord[0]][coord[1]] = 2;
    tab_grid[coord[4]][coord[5]] = 3;
    
}