#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *coup(int *coord)
{
    char choix;
    printf("z pour haut, q pour gauche, s pour bas, d pour droite : ");
    scanf(" %c", &choix);
    system("clear");//clear le terminal
    if (choix == 'd')
    {
        coord[1] = coord[1] + 1;// MArque le déplacement vers la droit
        if ((coord[1] == 0) || (coord[1] == 9))
            {
                printf("Le mouvement n'est pas possible\n"); //Protection pour que le joueur ne rentre pas dans le mur
                coord[1] = coord[1] - 1;
                
            }
        if ((coord[0] == coord[4]) && (coord[1] == coord[5])) // Si la coordonnée du joueur est celle de la boite, alors ça déplace la boite dans le sens du mouvement;
        {
            coord[5] = coord[5] + 1; 
            if ((coord[4] == 0) || (coord[4] == 9) || (coord[5] == 0) || (coord[5] == 9)) //Protection pour que la caisse ne rentre pas dans le mur
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
        if ((coord[0] == coord[4]) && (coord[1] == coord[5]))                       //La meme chose sur tous les déplacements
        {
            coord[4] = coord[4] - 1; 
            if ((coord[4] == 0) || (coord[4] == 9) || (coord[5] == 0) || (coord[5] == 9))
            {
                printf("Le mouvement n'est pas possible\n");
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
                printf("Le mouvement n'est pas possible\n");
                coord[1] = coord[1] + 1;
            }
        if ((coord[0] == coord[4]) && (coord[1] == coord[5]))
        {
            coord[5] = coord[5] - 1; 
            if ((coord[4] == 0) || (coord[4] == 9) || (coord[5] == 0) || (coord[5] == 9))
            {
                printf("Le mouvement n'est pas possible\n");
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
                printf("Le mouvement n'est pas possible\n");
                coord[1] = coord[1] - 1;
            }
        if ((coord[0] == coord[4]) && (coord[1] == coord[5]))
        {
            coord[4] = coord[4] + 1; 
            if ((coord[4] == 0) || (coord[4] == 9) || (coord[5] == 0) || (coord[5] == 9))
            {
                printf("Le mouvement n'est pas possible\n");
                coord[0] = coord[0] - 1;
                coord[4] = coord[4] - 1;
            }
        }
    }
    else
    {
        printf("Ce mouvement n'est pas valide\n");//Si le joueur ne choisis pas z ou q ou s ou d
    }
    
    return coord;
}