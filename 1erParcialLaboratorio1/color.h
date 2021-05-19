#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{
    int id;
    char nombreColor[20];
}eColor;


#endif // COLOR_H_INCLUDED

void mostrarColores(eColor colores[], int tam);
void mostrarColor(eColor color);
int cargarDescripcionColor(int id, eColor colores[], int tam, char desc[]);
