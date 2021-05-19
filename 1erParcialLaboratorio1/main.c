#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "trabajo.h"
#include "menu.h"

#define TAM 5
#define TAMTC 5
#define TAMS 3

int main()
{
    int flagAlta = 0;
    char salir;
    int tamT = TAM*3;
    int nextId = 100;
    int nextTrabajo = 1;

    eTipo tipos[TAMTC] = { {1000, "Ave"},
                       {1001, "Perro"},
                       {1002, "Gato"},
                       {1003, "Roedor"},
                       {1004, "Pez"}};

    eColor colores[TAMTC] = {{5000, "Negro"},
                         {5001, "Blanco"},
                         {5002, "Gris"},
                         {5003, "Rojo"},
                         {5004, "Azul"}};

    eServicio servicios[TAMS] = {{20000, "corte", 250},
                              {20001, "Desparasitado", 300},
                              {20002, "Castrado", 400}};

    eMascotas mascotas[TAM];
    eTrabajo trabajos[tamT];

    inicializarmascotas(mascotas, TAM);
    inicializarTrabajos(trabajos, tamT);

    do
    {
        switch(menu())
        {
             case 'A':
                if(altaMascotas(mascotas, TAM, &nextId, tipos, colores, TAMTC))
                {
                    printf("Alta exitosa!!\n");
                }
                else
                {
                    printf("Hubo un problema al realizar el alta\n");
                }
                flagAlta = 1;
                break;
            case 'B':
                if(flagAlta == 0)
                {
                    printf("Para modificar una mascota, primero debe cargarla");
                }
                else
                {
                    if(!modificarMascota(mascotas, TAM, tipos, colores, TAMTC))
                    {
                        printf("Hubo un problema para realizar la modificacion");
                    }
                }
                break;
            case 'C':
                if(flagAlta == 0)
                {
                    printf("Para dar de baja una mascota, primero debe cargarla");
                }
                else
                {
                    if(!bajaMascotas(mascotas, TAM, tipos, colores, TAMTC))
                    {
                        printf("Hubo un problema para realizar la baja");
                    }
                }
                break;
            case 'D':
                if(flagAlta == 0)
                {
                    printf("Para dar de baja a un empleado primero tiene que tener empleados");
                }
                else
                {
                    mostrarMascotas(mascotas, TAM, 1, tipos, colores, TAMTC);
                }
                break;
            case 'E':
                mostrarTipos(tipos, TAMTC);
                break;
            case 'F':
                mostrarColores(colores, TAMTC);
                break;
            case 'G':
                mostrarServicios(servicios, TAMS);
                break;
            case 'H':
                altaTrabajo(trabajos, mascotas, servicios, tamT, TAM, &nextTrabajo, tipos, colores, TAMTC, nextId-1,TAMS);
                break;
            case 'I':
                mostrarTrabajos(trabajos, tamT, mascotas, TAM, servicios, TAMS, 1);
                break;
            case 'J':
                utn_getString("Confirmar salida: ", "Error, reingrese", 4, 5, &salir);
                break;
            default:
                printf("Error, reingrese una opcion valida\n");
                break;
        }
        system("pause");
        system("cls");
    }while(salir != 's');
    return 0;
}
