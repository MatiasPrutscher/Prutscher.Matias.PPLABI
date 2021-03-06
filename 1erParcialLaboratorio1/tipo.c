#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "tipo.h"



void mostrarTipos(eTipo tipos[], int tam)
{
    printf("************** Lista de tipos **************\n");
    printf(" _______________________________________\n");
    printf("|\tID\t|\tSector\t\t|\n");
    printf("|_______________|_______________________|\n");
    for(int i = 0; i < tam; i++)
    {
        mostrarTipo(tipos[i]);
        printf("|_______________|_______________________|\n");
    }
}
void mostrarTipo(eTipo tipo)
{
    printf("|\t%d\t|  %-20s\t|\n", tipo.id, tipo.descripcion);
}

int cargarDescripcionTipo(int id, eTipo tipos[], int tam, char desc[])
{
    int todoOk = 0;
    if(id >= 1000 && id <= 1004 && tipos != NULL && tam > 0 && desc != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(tipos[i].id == id)
            {
                strcpy(desc, tipos[i].descripcion);
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}
