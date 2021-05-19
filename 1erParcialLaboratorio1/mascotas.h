#include "tipo.h"
#include "color.h"
#include "funciones.h"

#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

typedef struct{
    int id;
    char nombre[20];
    int idTipo;
    int idColor;
    int edad;
    int isEmpty;
}eMascotas;

#endif // MASCOTAS_H_INCLUDED

void inicializarmascotas(eMascotas lista[], int tam);
int buscarLibre(eMascotas lista[], int tam);
int altaMascotas(eMascotas lista[], int tam, int* pId, eTipo tipos[], eColor colores[], int tamTC);
void mostrarMascotas(eMascotas lista[], int tam, int limpiar, eTipo tipos[], eColor colores[], int tamTC);
void mostrarMascota(eMascotas mascota, eTipo tipos[], eColor colores[], int tamTC);
int buscarMascota(eMascotas lista[], int tam, int id);
int modificarMascota(eMascotas lista[], int tam, eTipo tipos[], eColor colores[], int tamTC);
int bajaMascotas(eMascotas lista[], int tam, eTipo tipos[], eColor colores[], int tamTC);
