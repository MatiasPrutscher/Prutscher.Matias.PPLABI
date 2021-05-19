#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "trabajo.h"

void inicializarTrabajos(eTrabajo lista[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        lista[i].isEmpty = 1;
    }
}

int buscarLibreT(eTrabajo lista[], int tam)
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

int altaTrabajo(eTrabajo trabajos[], eMascotas lista[], eServicio servicios[], int tamT, int tamM, int* nTrabajo, eTipo tipos[], eColor colores[], int tamTC, int idMActual, int tamS)
{
    int todoOk = 0;
    eTrabajo auxTrabajo;
    int i;

    system("cls");
    printf("******* Alta trabajo *******\n\n");

    if(lista != NULL && tamT > 0 && nTrabajo && trabajos != NULL && servicios != NULL)
    {
        i = buscarLibreT(trabajos, tamT);
        if(i != -1)
        {
            printf("Trabajo numero: %d\n", *nTrabajo);

            mostrarMascotas(lista, tamM, 0, tipos, colores, tamTC);
            utn_getInt("ingrese id de una mascota: ", "Error, reingrese: ", 100, idMActual, 5, &auxTrabajo.idMascota);

            mostrarServicios(servicios, tamS);
            utn_getInt("ingrese id del servicio a realizar: ", "Error, reingrese: ", 20000, 20002, 5, &auxTrabajo.idServicio);

            printf("ingrese la fecha DD/MM/AAAA: ");
            scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);

            {
                printf("Error, reingrese el año: ");
                scanf("%d", &auxTrabajo.fecha.anio);
            }
            while((!validarFecha(auxTrabajo.fecha)) && (auxTrabajo.fecha.anio < 2000 && auxTrabajo.fecha.anio >2022))
            {
                printf("Reingrese: ");
                scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);
            }

            auxTrabajo.isEmpty = 0;
            auxTrabajo.id = *nTrabajo;
            (*nTrabajo)++;
            trabajos[i] = auxTrabajo;
            todoOk = 1;
        }
        else
        {
            printf("No hay lugar\n");
        }
    }


    return todoOk;
}


void mostrarTrabajos(eTrabajo trabajos[], int tamT, eMascotas lista[], int tamM, eServicio servicios[], int tamS, int limpiar)
{
    int hayTrabajos = 0;

    if(limpiar == 1)
    {
        system("cls");
    }
    printf("\t********************************* Lista de trabajos *********************************\n");
    printf("____________________________________________________________________________________\n");
    printf("|\t\t|\t\t    |\t\t|        |\t\t\t|\t\t    |            |\n");
    printf("|     Nro Trabajo:\t|\t Nombre:    |\t Servicio:\t|  Fecha: |\n");
    printf("|_______________|___________________|___________|________|\n");
    for(int i = 0; i < tamT; i++)
    {
        if(!trabajos[i].isEmpty)
        {
            mostrarTrabajo(trabajos[i], lista, tamM, servicios, tamS);
            printf("|_______________|___________________|___________|________|\n");
            hayTrabajos = 1;
        }
    }
    if(!hayTrabajos)
    {
        printf("No hay trabajos para mostrar\n");
    }
    printf("\n\n");
}

void mostrarTrabajo(eTrabajo trabajo, eMascotas mascota[], int tamM, eServicio servicios[], int tamS)
{
    char nombre[20];
    char descripcionS[25];

    cargarDescripcionServicio(trabajo.idServicio, servicios, tamS, descripcionS);


    printf("|      %d\t|\t %-10s |\t %-10s\t|   %d/&d/&d \t|"
           , trabajo.id
           , nombre
           , descripcionS
           , trabajo.fecha.dia
           , trabajo.fecha.mes
           , trabajo.fecha.anio);
}
