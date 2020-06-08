
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include <conio.h>


//INT
int getInt(char msj[]);
int ValidarEdad(int edad,int parametro);
int getEdadValidada(char msj[],char error[],int parametro);

//FLOAT
float getFloat(char msj[]);
float ValidarPeso(float peso, int parametro);
float getPesoValidado(char msj[],char error[],int parametro);

//CADENAS
void getStr(char msj[],char palabra[],int largo);
void ConvertirPrimerCaracterAMayus(char cadena[]);
void ConvertirMinusculas(char cadena[]);

//CHARS
char getSexoValidado(char msj[],char error[]);
int ValidarSexo(char sexo);

//limpiar pantalla
void LimpiarPantalla();





