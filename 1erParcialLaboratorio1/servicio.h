#include "funciones.h"

#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED


typedef struct{
    int id;
    char descripcion[20];
    float precio;
}eServicio;


#endif // SERVICIO_H_INCLUDED
void mostrarServicios(eServicio sevicios[], int tam);
void mostrarServicio(eServicio servicio);
int cargarDescripcionServicio(int id, eServicio servicios[], int tam, char desc[]);
