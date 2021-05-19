#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char menu()
{
    char opcion;

    printf("************************Menu************************\n\n");
    printf("A. ALTA MASCOTA: ");
    printf("\nB. MODIFICAR MASCOTA:: ");
    printf("\nC. BAJA MASCOTA:: ");
    printf("\nD. LISTAR MASCOTAS: ");
    printf("\nE. LISTAR TIPOS: ");
    printf("\nF. LISTAR COLORES: ");
    printf("\nG. LISTAR SERVICIOS: ");
    printf("\nH. ALTA TRABAJO: ");
    printf("\nI. LISTAR TRABAJOS:  ");
    printf("\nJ. SALIR: ");
    scanf("%c", &opcion);
    opcion = toupper(opcion);
    return opcion;
}
