#include "funciones.h"

int getInt(char msj[])
{
    int valor;
    printf("%s",msj);
    fflush(stdin);//si pone una letra en el bucle de validar se rompe
    scanf("%d",&valor);
    return valor;
}

int ValidarEdad(int edad, int parametro)//el parametro a evaluar la edad ingresada
{
    int retorno=-1;
    if (edad >parametro)
    {
        retorno=0;
    }
    return retorno;
}

int getEdadValidada(char msj[],char error[],int parametro)
{
    int edad;
    int aux;
    edad = getInt(msj);
    aux = ValidarEdad(edad,parametro);
    while(aux!=0)
    {
        edad = getInt(error);
        aux = ValidarEdad(edad,parametro);
    }
    return edad;
}


float getFloat(char msj[])
{
    float valor;
    printf("%s",msj);
    fflush(stdin);
    scanf("%f",&valor);
    return valor;
}

float ValidarPeso(float peso, int parametro)//el parametro a evaluar la edad ingresada
{
    int retorno=-1;
    if (peso >parametro)
    {
        retorno=0;
    }
    return retorno;
}

float getPesoValidado(char msj[],char error[],int parametro)
{
    float peso;
    float aux;
    peso = getFloat(msj);
    aux = ValidarPeso(peso,parametro);
    while(aux!=0)
    {
        peso = getFloat(error);
        aux = ValidarPeso(peso,parametro);
    }
    return peso;
}


void ConvertirPrimerCaracterAMayus(char cadena[])
{
    int i=0;
    cadena[0]=toupper(cadena[0]);
    while(cadena[i]!='\0')
    {
        if (cadena[i] == ' ')
        {
            cadena[i+1]=toupper(cadena[i+1]);
        }
        i++;
    }
}

void ConvertirMinusculas(char cadena[])
{
    int i=0;
    while(cadena[i]!='\0')
    {
        cadena[i]=tolower(cadena[i]);
        i++;
    }
}


void getStr(char msj[],char palabra[],int largo)
{
    printf("%s",msj);
    fflush(stdin);
    fgets(palabra,largo,stdin);
    palabra[strlen(palabra)-1]='\0';
    ConvertirMinusculas(palabra);
    ConvertirPrimerCaracterAMayus(palabra);
}


int ValidarSexo(char sexo)
{
    int retorno = -1;
    if (sexo =='M' || sexo =='F')
    {
        retorno=0;
    }
    return retorno;
}

char getSexoValidado(char msj[],char error[])
{
    char sexo;
    int aux;
    printf("%s",msj);
    fflush(stdin);
    sexo = getchar();
    sexo = toupper(sexo);
    aux = ValidarSexo(sexo);
    while(aux !=0)
    {
        printf("%s",error);
        fflush(stdin);
        sexo = getchar();
        sexo = toupper(sexo);
        aux = ValidarSexo(sexo);
    }
    return sexo;
}

void LimpiarPantalla()
{
    printf("Presione una tecla para continuar...");
    fflush(stdin);
    getch();
    system("cls");
}




