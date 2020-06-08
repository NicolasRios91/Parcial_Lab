#include "menu.h"

void MenuPrincipal()
{
        Banner("MENU PRINCIPAL");
        printf("(1)  Mostrar Clientes\n");
        printf("(2)  MOSTRAR MASCOTAS\n");
        printf("(3)  MOSTRAR CLIENTES CON SUS MASCOTAS\n");
        printf("(4)  CARGAR MASCOTA\n");
        printf("(5)  ELIMINAR MASCOTA\n");
        printf("(6)  MODIFICAR MASCOTA\n");
        printf("(7)  CARGAR CLIENTE\n");
        printf("(8)  BORRRA CLIENTE (JUNTO CON SUS MASCOTAS)\n");
        printf("(9)  MOSTRAR MASCOTAS POR TIPO CON SU DUENIO\n");
        printf("(10) MODIFICAR DUENIO\n");
        printf("(11) CLIENTES CON MAS DE UNA MASCOTA\n");
        printf("(12) MASCOTAS MAS DE 3 AÑOS\n");
        printf("(13) MASCOTAS POR TIPO \n");
        printf("(14) CLIENTE POR CANTIDADES\n");
        printf("(15) CLIENTE POR CANTIDADES ORDENADOS\n");
        printf("(16) PROMEDIO DE EDAD DE MASCOTAS\n");
        printf("(17) PROMEDIO DE EDAD DE MASCOTAS POR TIPO\n");
        printf("(18) PROMEDIO MUJERES\n");
        printf("(19) LISTAR DUENIOS QUE TIENEN MASCOTAS DEL MISMO SEXO\n");
        printf("(20) SALIR\n");
}

void MenuModificarCliente()
{
        printf("\n\nMODIFICAR CLIENTE\n\n");
        printf("(1) CAMBIAR NOMBRE\n");
        printf("(2) CAMBIAR APELLIDO\n");
        printf("(3) CAMBIAR LOCALIDAD\n");
        printf("(4) CAMBIAR TELEFONO\n");
        printf("(5) CAMBIAR EDAD: \n");
        printf("(6) CAMBIAR SEXO: \n");
        printf("(7) APLICAR CAMBIOS\n");
        printf("(8) SALIR\n");
}

void MenuModificarMascota()
{
        printf("\n\nMODIFICAR MASCOTA\n\n");
        printf("(1) CAMBIAR NOMBRE\n");
        printf("(2) CAMBIAR TIPO\n");
        printf("(3) CAMBIAR RAZA\n");
        printf("(4) CAMBIAR EDAD\n");
        printf("(5) CAMBIAR PESO: \n");
        printf("(6) CAMBIAR SEXO: \n");
        printf("(7) APLICAR CAMBIOS\n");
        printf("(8) Salir\n");
}

void MenuModificarMascotaBIS()
{
        printf("\n\nMODIFICAR MASCOTA\n\n");
        printf("(1) CAMBIAR NOMBRE\n");
        printf("(2) CAMBIAR TIPO\n");
        printf("(3) CAMBIAR RAZA\n");
        printf("(4) CAMBIAR EDAD\n");
        printf("(5) CAMBIAR PESO: \n");
        printf("(6) CAMBIAR SEXO: \n");
        printf("(7) CAMBIAR ID CLIENTE\n");
        printf("(8) APLICAR CAMBIOS\n");
        printf("(9) Salir\n");
}

void MenuMascotasPorTipo()
{
        printf("(1)PERROS\n");
        printf("(2)GATOS\n");
        printf("(3)RAROS\n");
        printf("(4)SALIR\n");
}

void HeaderCliente(char IdCliente[],char nombre[],char apellido[],char localidad[],char telefono[], char edad[],char sexo[])
{
    printf("%-5s %-18s %-18s %-18s %-18s %-8s %-5s",IdCliente,nombre,apellido,localidad,telefono,edad,sexo);
}


void HeaderMascota(char IdMascota[],char nombre[],char tipo[], char raza[],char edad[],char peso[],char sexo[])
{
    printf("%-5s %-14s %-12s %-14s %-7s %-7s %-5s",IdMascota,nombre,tipo,raza,edad,peso,sexo);
}

void HeaderRaza(char id[], char raza[])
{
    printf("%-4s %s\n",id,raza);
}


void Banner(char msj[])
{
    printf("========================================================================================================\n");
    printf("%s\n",msj);
    printf("========================================================================================================\n");
}

