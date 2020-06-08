#include "localidad.h"

void HardcodearLocalidad (eLocalidad lista[],int sizeLocalidad)
{
    int i;
    char provincia[3][30]={"Buenos Aires","Santa Fe","La Pampa"};
    char codigo[3][10]= {"100","150","200"};
    char descripcion[3][30]={"Quilmes","Rosario","Santa Rosa"};
    int id[3]={1,2,3};
    for(i=0;i<3;i++)
    {
        strcpy(lista[i].provincia,provincia[i]);
        strcpy(lista[i].codigo,codigo[i]);
        strcpy(lista[i].descripcion,descripcion[i]);
        lista[i].id = id[i];
    }
}

void MostrarLocalidad (eLocalidad UnaLocalidad)
{
    printf("%s %s %s",UnaLocalidad.provincia,UnaLocalidad.codigo,UnaLocalidad.descripcion);
}

void MostrarTodasLasLocalidades (eLocalidad listaLocalidad[],int sizeLocalidad)
{
    int i;
    printf("PROVINCIA   CODIGO    DESCRIPCION");
    for (i=0;i<3;i++)
    {
        MostrarLocalidad(listaLocalidad[i]);
    }
}
