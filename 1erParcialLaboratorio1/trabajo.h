#include "mascotas.h"
#include "servicio.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{
    int id;
    int idMascota;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED

void inicializarTrabajos(eTrabajo lista[], int tam);
int buscarLibreT(eTrabajo lista[], int tam);
int altaTrabajo(eTrabajo trabajos[], eMascotas lista[], eServicio servicios[], int tamT, int tamM, int* nTrabajo, eTipo tipos[], eColor colores[], int tamTC, int idMActual, int tamS);
void mostrarTrabajos(eTrabajo trabajos[], int tamT, eMascotas lista[], int tamM, eServicio servicios[], int tamS, int limpiar);
void mostrarTrabajo(eTrabajo trabajo, eMascotas mascota[], int tamM, eServicio servicios[], int tamS);
