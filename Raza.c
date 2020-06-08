#include "Raza.h"

void HardcodearRaza(eRaza lista[],int sizeRaza)
{
    int i;
    char raza[6][20]={"pastor","dogo","gato","gato","Overo","lagarto"};
    char pais[6][20]={"aleman","argentino","siames","persa","chileno","hungaro"};
    int id[6]={1,2,3,4,5,6};
    for (i=0;i<sizeRaza;i++)
    {
        strcpy(lista[i].raza,raza[i]);
        strcpy(lista[i].pais,pais[i]);
        lista[i].id=id[i];
    }
}


void MostrarUnaRaza(eRaza lista)
{
    printf("%-4d %s %s\n",lista.id,lista.raza,lista.pais);
}

void MostrarTodasLasRazas(eRaza lista[],int sizeRaza)
{
    int i;
    Banner("LISTA DE RAZAS");
    HeaderRaza("ID","RAZA");
    for (i=0;i<sizeRaza;i++)
    {
        MostrarUnaRaza(lista[i]);
    }
}

int ValidarRazaIngresada (eRaza listaRaza[],int sizeRaza, int idIngresada)//devuelve la posicion de la raza ingresada, para despues copiarla
{
    int retorno = -1;
    int i;
    for (i=0;i<sizeRaza;i++)
    {
        if (listaRaza[i].id == idIngresada)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

