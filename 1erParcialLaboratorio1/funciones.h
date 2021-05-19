#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    float sueldo;
    eFecha fIngreso;
    int isEmpty;
}ePersona;

#endif // FUNCIONES_H_INCLUDED

/** \brief recibe un array de tipo int y los ordena por orden ascendente o desendente
 *
 * \param lista[] int array a ordenar
 * \param tam int tamaño tamaño del array a ordenar
 * \param orden int criterio de ordenamiento 1 para ascendente o 0 para desendente
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int ordenamientoInt(int lista[], int tam, int orden);

/** \brief recibe un array de char y los ordena por orden ascendente o desendente
 *
 * \param lista[] char array a ordenar
 * \param tam int tamaño tamaño del array a ordenar
 * \param orden int criterio de ordenamiento 1 para ascendente o 0 para desendente
 * \return devuelve 1 si esta todo bien o 0 si esta mal
 *
 */
int ordenamientoString(char lista[][20], int tam, int orden);

/** \brief recibe un array de tipo char, un char a buscar dentro del array y un char para reemplazarlo
 *
 * \param palabra char[] array a buscar coincidencias
 * \param unaLetra char letra a buscar dentro del array
 * \param otraLetra char letra a reemplazar
 * \return retorna 0 si no encontro coincidencias o la cantidad de coincidencias y reemplazos que realizo
 *
 */
int DameCantidadReemplazos(char palabra[],char unaLetra, char otraLetra);

/** \brief recibe un array de tipo char y lo da vuelta
 *
 * \param cadena char[] array a dar vuelta
 * \return retorna 0 si hubo un error o 1 si esta todo bien
 *
 */
int invertirCadena(char cadena[]);

/** \brief recibe un array de tipo char y ordena de forma ascendiente 1 o desendiente 0
 *
 * \param nombre char[] array a dar vuelta
 * \param orden int el orden en el que se desea ordenar la cadena, 1 para ascendiente o 0 para desendiente
 * \return retorna 0 si hubo un error o 1 si esta todo bien
 *
 */
int ordenarCaracteres(char nombre[], int orden);

/** \brief recibe un año (int, AAAA) y devuelve 1 si es bisiesto o 0 sino
 *
 * \param anio int año a validar
 * \return retorna 0 si hubo un error o 1 si esta todo bien
 *
 */
int aBisiesto(int anio);

/** \brief recibe una fecha, valida la misma y devuelve 1 si esta todo bien o en caso contrario 0
 *
 * \param fecha eFecha recibe la fecha a validar
 * \return retorna 0 si hubo un error o 1 si esta todo bien
 *
 */
int validarFecha(eFecha fecha);

int isChar(char string[]);
int getString(char input[], int tam);
int SizeString(char string[]);
int utn_getString(char mensaje[], char mensajeError[], int tam, int reintentos, char input[]);
int isInt(char input[]);
int getInt(int* input);
int utn_getInt(char mensaje[], char mensajeError[], int min, int max, int reintentos, int* input);
int isFloat(char input[]);
int getFloat(float* input);
int utn_getFloat(char mensaje[], char mensajeError[], float min, float max, int reintentos, float* input);
