
#include <stdio.h>

void MenuPrincipal();
void MenuModificarCliente();
void MenuModificarMascota();
void HeaderCliente(char IdCliente[],char nombre[],char apellido[],char localidad[],char telefono[], char edad[],char sexo[]);
void HeaderMascota(char IdMascota[],char nombre[],char tipo[], char raza[],char edad[],char peso[],char sexo[]);
void HeaderRaza(char id[], char raza[]);
void Banner(char msj[]);
void MenuMascotasPorTipo();
void HeaderMascotaConPais(char IdMascota[],char nombre[],char tipo[],char raza[],char otraRaza[],char pais[],char edad[],char peso[],char sexo[]);
void MenuModificarMascotaBIS();
