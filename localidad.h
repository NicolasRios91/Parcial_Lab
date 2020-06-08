#include "funciones.h"

typedef struct
{
    char provincia[30];
    char codigo[15];
    char descripcion[30];
    int id;
}eLocalidad;


void HardcodearLocalidad (eLocalidad lista[],int sizeLocalidad);
void MostrarLocalidad (eLocalidad UnaLocalidad);
void MostrarTodasLasLocalidades (eLocalidad listaLocalidad[],int sizeLocalidad);
