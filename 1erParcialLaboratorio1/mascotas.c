#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "mascotas.h"

void inicializarmascotas(eMascotas lista[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        lista[i].isEmpty = 1;
    }
}

int buscarLibre(eMascotas lista[], int tam)
{
    int ubicacion = -1;
    for(int i = 0; i < tam; i++)
    {
        if(lista[i].isEmpty)
        {
            ubicacion = i;
            break;
        }
    }
    return ubicacion;
}

int altaMascotas(eMascotas lista[], int tam, int* pId, eTipo tipos[], eColor colores[], int tamTC)
{
    int todoOk = 0;
    eMascotas auxMascota;
    int i;

    system("cls");
    printf("******* Alta MAscota *******\n\n");
    printf("Id: %d\n", *pId);

    if(lista != NULL && tam > 0 && pId)
    {
        i = buscarLibre(lista, tam);
        if(i != -1)
        {
            utn_getString("Ingrese el nombre: ", "Error, reingrese: ", 20, 5, auxMascota.nombre);

            mostrarTipos(tipos, tamTC);
            utn_getInt("ingrese el tipo: ", "Error, reingrese: ", 1000, 1004, 5, &auxMascota.idTipo);

            mostrarColores(colores, tamTC);
            utn_getInt("Ingrese el color: ", "Error, reingrese: ", 5000, 5004, 5, &auxMascota.idColor);

            utn_getInt("ingrese la edad (1-15): ", "Error, reingrese: ", 1, 15, 5, &auxMascota.edad);

            auxMascota.isEmpty = 0;
            auxMascota.id = *pId;
            (*pId)++;
            lista[i] = auxMascota;
            todoOk = 1;
        }
        else
        {
            printf("No hay lugar\n");
        }
    }


    return todoOk;
}

void mostrarMascotas(eMascotas lista[], int tam, int limpiar, eTipo tipos[], eColor colores[], int tamTC)
{
    int hayMascotas = 0;

    if(limpiar == 1)
    {
        system("cls");
    }
    printf("\t********************************* Lista de mascotas *********************************\n");
    printf("_________________________________________________________________________________\n");
    printf("|\t\t|\t\t    |\t\t|        |\t\t\t|\n");
    printf("|     id:\t|\t Nombre:    |\t Edad:\t|  Tipo: |\ Color:\t\t|\n");
    printf("|_______________|___________________|___________|________|______________________| \n");
    for(int i = 0; i < tam; i++)
    {
        if(!lista[i].isEmpty)
        {
            mostrarMascota(lista[i], tipos, colores, tamTC);
            printf("|_______________|___________________|___________|________|______________________|\n");
            hayMascotas = 1;
        }
    }
    if(!hayMascotas)
    {
        printf("No hay mascotas para mostrar\n");
    }
    printf("\n\n");
}

void mostrarMascota(eMascotas mascota, eTipo tipos[], eColor colores[], int tamTC)
{
    char descripcionC[20];
    char descripcionT[20];

    cargarDescripcionColor(mascota.idColor, colores, tamTC, descripcionC);
    cargarDescripcionTipo(mascota.idTipo, tipos, tamTC, descripcionT);

    printf("|      %d\t|\t %-10s |\t %d\t|   %s   |\t%-10s\t|\n"
           , mascota.id
           , mascota.nombre
           , mascota.edad
           , descripcionT
           , descripcionC);
}


int buscarMascota(eMascotas lista[], int tam, int id)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(!lista[i].isEmpty && lista[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int modificarMascota(eMascotas lista[], int tam, eTipo tipos[], eColor colores[], int tamTC)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirmacion;
    int opcion;


    system("cls");
    printf("*****************Modificar Mascota*****************\n");
    mostrarMascotas(lista, tam, 0, tipos, colores, tamTC);
    printf("\nIngrese id: ");
    scanf("%d", &id);
    indice = buscarMascota(lista, tam, id);
    if(indice != -1)
    {
        printf("La mascota a modificar es:\n");
        mostrarMascota(lista[indice], tipos, colores, tamTC);
        utn_getString("Confirmar? ", "Error, reingrese: ", 4, 5, &confirmacion);
        confirmacion = tolower(confirmacion);
        if(confirmacion == 's')
        {
            utn_getInt("\n1-Modificiar tipo: \n2-Modificiar edad: \n", "Error, reingrese: ", 1, 2, 5, &opcion);
            switch(opcion)
            {
                case 1:
                    mostrarTipos(tipos, tamTC);
                    utn_getInt("ingrese el tipo: ", "Error, reingrese: ", 1000, 1004, 5, &lista[indice].idTipo);
                    break;
                case 2:
                    utn_getInt("ingrese la edad (1-15): ", "Error, reingrese: ", 1, 15, 5, &lista[indice].edad);
            }

            todoOk = 1;
            printf("\nSe realizo la modificacion con exito\n\n");
        }
        else
        {
            printf("\nSe cancelo la modificacion por el usuario\n\n");
        }

    }
    else
    {
        printf("El id indicado no existe.\n\n");
    }
    return todoOk;
}

int bajaMascotas(eMascotas lista[], int tam, eTipo tipos[], eColor colores[], int tamTC)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirmacion;


    system("cls");
    printf("*****************Baja Mascota*****************\n");
    mostrarMascotas(lista, tam, 0, tipos, colores, tamTC);
    printf("\nIngrese id: ");
    scanf("%d", &id);
    indice = buscarMascota(lista, tam, id);
    if(indice != -1)
    {
        printf("La mascota a dar de baja es:\n");
        mostrarMascota(lista[indice], tipos, colores, tamTC);
        utn_getString("Confirmar? ", "Error, reingrese: ", 4, 5, &confirmacion);
        confirmacion = tolower(confirmacion);
        if(confirmacion == 's')
        {
            lista[indice].isEmpty = 1;

            todoOk = 1;
            printf("\nSe realizo la modificacion con exito\n\n");
        }
        else
        {
            printf("\nSe cancelo la modificacion por el usuario\n\n");
        }

    }
    else
    {
        printf("El id indicado no existe.\n\n");
    }
    return todoOk;
}

int cargarNombreDeMascota(int id, eMascotas lista[], int tam, char desc[])
{
    int todoOk = 0;
    if(id >= 5000 && id <= 5004 && lista != NULL && tam > 0 && desc != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].id == id)
            {
                strcpy(desc, lista[i].nombre);
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}
