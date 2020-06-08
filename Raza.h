#include <stdio.h>
#include <string.h>
#include "menu.h"


typedef struct
{
    int id;
    char raza[20];
    char pais[20];
}eRaza;

void HardcodearRaza(eRaza lista[],int sizeRaza);

void MostrarUnaRaza(eRaza lista);

void MostrarTodasLasRazas(eRaza lista[],int sizeRaza);

int ValidarRazaIngresada (eRaza listaRaza[],int sizeRaza, int idIngresada);
