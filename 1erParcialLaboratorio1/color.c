#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "color.h"



void mostrarColores(eColor colores[], int tam)
{
    printf("************** Lista de colores **************\n");
    printf(" _______________________________________\n");
    printf("|\tID\t|\tSector\t\t|\n");
    printf("|_______________|_______________________|\n");
    for(int i = 0; i < tam; i++)
    {
        mostrarColor(colores[i]);
        printf("|_______________|_______________________|\n");
    }
}
void mostrarColor(eColor color)
{
    printf("|\t%d\t|  %-20s\t|\n", color.id, color.nombreColor);
}


int cargarDescripcionColor(int id, eColor colores[], int tam, char desc[])
{
    int todoOk = 0;
    if(id >= 5000 && id <= 5004 && colores != NULL && tam > 0 && desc != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(colores[i].id == id)
            {
                strcpy(desc, colores[i].nombreColor);
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}
