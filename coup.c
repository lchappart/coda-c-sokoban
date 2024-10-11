#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *coup(int *coord)
{
    char choix;
    printf("z pour haut, q pour gauche, s pour bas, d pour droite : ");
    scanf(" %c", &choix);
    system("clear");
    if (choix == 'd')
    {
        coord[1] = coord[1] + 1;
        if ((coord[1] == 0) || (coord[1] == 9))
            {
                printf("Le mouvement n'est pas possible\n");
                coord[1] = coord[1] - 1;
                
            }
        if ((coord[0] == coord[4]) && (coord[1] == coord[5]))
        {
            coord[5] = coord[5] + 1; 
            if ((coord[4] == 0) || (coord[4] == 9) || (coord[5] == 0) || (coord[5] == 9))
            {
                printf("Le mouvement n'est pas possible\n");
                coord[1] = coord[1] - 1;
                coord[5] = coord[5] - 1; 
            }
        }
    }
    else if (choix == 'z')
    {
        coord[0] = coord[0] - 1;
        if ((coord[0] == 0) || (coord[0] == 9))
            {
                printf("Le mouvement n'est pas possible\n");
                coord[0] = coord[0] + 1;
            }
        if ((coord[0] == coord[4]) && (coord[1] == coord[5]))
        {
            coord[4] = coord[4] - 1; 
            if ((coord[4] == 0) || (coord[4] == 9) || (coord[5] == 0) || (coord[5] == 9))
            {
                printf("Le mouvement n'est pas possible");
                coord[0] = coord[0] + 1;
                coord[4] = coord[4] + 1; 
            }
        }
    }
    else if (choix == 'q')
    {
        coord[1] = coord[1] - 1;
        if ((coord[1] == 0) || (coord[1] == 9))
            {
                printf("Le mouvement n'est pas possible");
                coord[1] = coord[1] + 1;
            }
        if ((coord[0] == coord[4]) && (coord[1] == coord[5]))
        {
            coord[5] = coord[5] - 1; 
            if ((coord[4] == 0) || (coord[4] == 9) || (coord[5] == 0) || (coord[5] == 9))
            {
                printf("Le mouvement n'est pas possible");
                coord[1] = coord[1] + 1;
                coord[5] = coord[5] + 1;
            }
        }
    }
    else if (choix == 's')
    {
        coord[0]  = coord[0] + 1;
        if ((coord[0] == 0) || (coord[0] == 9))
            {
                printf("Le mouvement n'est pas possible");
                coord[1] = coord[1] - 1;
            }
        if ((coord[0] == coord[4]) && (coord[1] == coord[5]))
        {
            coord[4] = coord[4] + 1; 
            if ((coord[4] == 0) || (coord[4] == 9) || (coord[5] == 0) || (coord[5] == 9))
            {
                printf("Le mouvement n'est pas possible");
                coord[0] = coord[0] - 1;
                coord[4] = coord[4] - 1;
            }
        }
    }
    else
    {
        printf("Ce mouvement n'est pas valide\n");
    }
    
    return coord;
}