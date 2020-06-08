#include "Mascota.h"


void HardcodearMascotas(eMascota listaMascotas[],int sizeMascotas)//PUNTO 2
{
    int i;
    int id[11]={101,102,103,104,105,106,107,108,109,110,111};
    char nombre[11][20]={"gato 1","gato 2","perro 3","perro 4","gato 5","perro 6",
                        "iguana 7","perro 8","gato 9","gato 10","perro 11"};
    char tipo[11][20]={"Gato","Gato","Perro","Perro","Gato","Perro","Iguana","Perro","Gato","Gato","Perro"};
    char raza[11][20]={"mestizo","mestizo","mestizo","mestizo","mestizo","pitbull","--","labrador","mestizo","mestizo","Bulldog"};

    int edad[11]={10,10,2,8,6,1,10,3,3,4,4};//{1,2,1,3,1,2,1,2,1,1,1};
    float peso[11]={5,5,15,12,15,5,25,2,20,4,10};
    char sexo [11]={'F','F','M','M','M','M','M','M','M','M','M'};
    int idCliente[11]={1,1,2,2,2,3,3,4,5,5,5};
    for (i=0;i<11;i++)
    {
        listaMascotas[i].id = id[i];
        strcpy(listaMascotas[i].nombre,nombre[i]);
        strcpy(listaMascotas[i].tipo,tipo[i]);
        strcpy(listaMascotas[i].raza,raza[i]);
        listaMascotas[i].edad=edad[i];
        listaMascotas[i].peso=peso[i];
        listaMascotas[i].sexo=sexo[i];
        listaMascotas[i].idCliente=idCliente[i];
        listaMascotas[i].isEmpty=OCUPADO;
    }
}


void MostrarUnaMascota(eMascota unaMascota)
{
    printf("%-5d %-14s %-12s %-15s %-6d %-8.2f %-3c",unaMascota.id,
                                        unaMascota.nombre,
                                        unaMascota.tipo,
                                        unaMascota.raza,
                                        unaMascota.edad,
                                        unaMascota.peso,
                                        unaMascota.sexo);
}

void MostrarTodasLasMascota(eMascota listaMascotas[],int sizeMascotas)
{
    int i;
    Banner("LISTA DE MASCOTAS");
    HeaderMascota("ID","NOMBRE","TIPO","RAZA","EDAD","PESO","SEXO\n\n");
    for (i=0;i<sizeMascotas;i++)
    {
        if (listaMascotas[i].isEmpty == OCUPADO)
        {
            MostrarUnaMascota(listaMascotas[i]);
            printf("\n");
        }
    }
}

void InicializarMascotasLibre(eMascota listaMascotas[],int sizeMascotas)
{
    int i;
    for (i=0;i<sizeMascotas;i++)
    {
        listaMascotas[i].isEmpty == LIBRE;
    }
}

int BuscarMascotaLibre(eMascota listaMascotas[],int sizeMascotas)
{
    int i;
    int indice=-1;
    for (i=0;i<sizeMascotas;i++)
    {
        if (listaMascotas[i].isEmpty ==LIBRE)
        {
            indice=i;
            break;
        }
    }
    return indice;
}


//PUNTO 4
eMascota CargarMascota(int id)
{
    eMascota UnaMascota;
    UnaMascota.id=id;
    getStr("Ingrese el nombre de la mascota: ",UnaMascota.nombre,40);
    getStr("Ingrese el tipo de mascota (perro,gato,otro): ",UnaMascota.tipo,20);
    UnaMascota.edad = getEdadValidada("Ingrese la edad de la mascota: ","ERROR: La edad minima es un año: ",1);
    UnaMascota.peso = getPesoValidado("Ingrese el peso de la mascota: ","ERROR: Ingrese un peso valido: ",0);
    UnaMascota.sexo = getSexoValidado("Ingrese el sexo: ","ERROR: El sexo debe ser f/m : ");
    UnaMascota.idRazaPais = getInt("Ingrese la id raza: ");
    UnaMascota.idCliente = getInt("Ingrese el id del cliente: ");
    //UnaMascota.isEmpty=OCUPADO; lo cambia en otra funcion al validar la id del cliente y raza
    return UnaMascota;
}

//punto 5
int EliminarMascota (eMascota listaMascotas[],int sizeMascotas,int idIngresado,char confirma[])
{
    int i;
    int retorno =-1;
    char respuesta;
    for (i=0;i<sizeMascotas;i++)
    {
        if (idIngresado == listaMascotas[i].id &&listaMascotas[i].isEmpty == OCUPADO)
        {
            system("cls");
            Banner("MASCOTA A ELIMINAR");
            HeaderMascota("ID","NOMBRE","TIPO","RAZA","EDAD","PESO","SEXO\n");
            MostrarUnaMascota(listaMascotas[i]);
            printf("\n");
            printf("\n%s",confirma);
            fflush(stdin);
            respuesta=getchar();
            if (respuesta=='y' || respuesta=='Y')
            {
                listaMascotas[i].isEmpty=LIBRE;
                retorno = 0;
            }
            break;
        }
    }

    return retorno;
}


//PUNTO 6
void ModificarMascota(eMascota listaMascotas[],int sizeMascotas,int idIngresado,char msj[],char error[])
{
    int i;
    int opcion;
    int control;

    int auxInt;
    float auxFloat;
    char auxChar;

    char cambios;
    char respuesta='n';
    char bandera=0;
    eMascota aux;

    for (i=0;i<sizeMascotas;i++)
    {
        if (listaMascotas[i].id == idIngresado)
        {
            bandera=1;//para el msj de id no encontrada
            aux=listaMascotas[i];
         do
            {
                system("cls");
                Banner("MASCOTA A MODIFICAR");
                HeaderMascota("ID","NOMBRE","TIPO","RAZA","EDAD","PESO","SEXO\n");
                MostrarUnaMascota(listaMascotas[i]);
                printf("\n");
                Banner("CAMBIOS HECHOS");
                HeaderMascota("ID","NOMBRE","TIPO","RAZA","EDAD","PESO","SEXO\n");
                MostrarUnaMascota(aux);
                MenuModificarMascota();
                fflush(stdin);//si pongo una letra repita el loop infinitamenta salteandose el scanf
                opcion= getInt("\nIngrese una opcion: ");
                switch (opcion)
                {
                    case 1:
                        getStr("Ingrese el nuevo nombre: ",aux.nombre,40);
                        cambios='y';
                        printf("%s",msj);
                        LimpiarPantalla();
                        break;
                    case 2:
                        getStr("Ingrese el nuevo tipo: ",aux.tipo,20);
                        cambios='y';
                        printf("%s",msj);
                        LimpiarPantalla();
                        break;
                    case 3:
                        getStr("Ingrese la nueva raza: ",aux.raza,20);//poner la estructura
                        cambios='y';
                        printf("%s",msj);
                        LimpiarPantalla();
                        break;
                    case 4:
                        auxInt = getInt("Ingrese la nueva edad: ");
                        control = ValidarEdad(auxInt,0);
                        if (control == 0)
                        {
                            aux.edad = auxInt;
                            cambios='y';
                            printf("%s",msj);
                        }
                        else
                        {
                            printf("Edad invalida\n");
                        }
                        LimpiarPantalla();
                        break;
                    case 5:
                        auxFloat = getFloat("Ingrese el nuevo peso: ");
                        control = ValidarPeso(auxFloat,0);
                        if (control == 0)
                        {
                            aux.peso = auxFloat;
                            cambios='y';
                            printf("%s",msj);
                        }
                        else
                        {
                            printf("Peso invalido\n");
                        }
                        LimpiarPantalla();
                        break;
                    case 6:
                        printf("Ingrese el sexo: ");
                        fflush(stdin);
                        auxChar = getchar();
                        auxChar = toupper(auxChar);
                        if (auxChar =='F' || auxChar =='M')
                        {
                            aux.sexo = auxChar;
                            cambios='y';
                            printf("%s",msj);
                        }
                        else
                        {
                            printf("El sexo ingresado no es valido\n");
                        }
                        LimpiarPantalla();
                    case 7:
                        if (cambios =='y')
                        {
                            printf("Confirma los cambios? (y/n): ");
                            fflush(stdin);
                            respuesta = getchar();
                            if (respuesta=='y' || respuesta=='Y')
                            {
                                listaMascotas[i]=aux;
                                printf("Los cambios fueron aplicados\n");

                            }
                            else
                            {
                            printf("No se aplicaron los cambios\n");

                            }
                        }
                        else
                        {
                            printf("No hay cambios para aplicar\n");

                        }
                        LimpiarPantalla();
                        break;
                    case 8:
                        break;
                    default:
                        printf("Ingrese una opcion valida\n");
                }
            }while(opcion!=8);
        }
    }
    if (bandera==0)
    {
        printf("%s",error);
        LimpiarPantalla();
    }
}

//aux PUNTO 9
void OrdenarMascotasPorTipo(eMascota listaMascotas[],int sizeMascotas)
{
    int i;
    int j;
    eMascota aux;
    for (i=0;i<sizeMascotas;i++)
    {
        ConvertirMinusculas(listaMascotas[i].tipo);//en caso de que se harcodeen otros datos
        ConvertirPrimerCaracterAMayus(listaMascotas[i].tipo);
    }
    for (i=0;i<sizeMascotas-1;i++)
    {
        for(j=i+1;j<sizeMascotas;j++)
        {
            if (strcmp(listaMascotas[i].tipo,listaMascotas[j].tipo)>0)
            {
                aux=listaMascotas[i];
                listaMascotas[i]=listaMascotas[j];
                listaMascotas[j]=aux;
            }
        }
    }
}

//aux punto 12
int MascotaMayorAtresAnios(eMascota UnaMascota)
{
    int retorno=-1;
    if (UnaMascota.edad >3 && UnaMascota.isEmpty == OCUPADO)
    {
        retorno=0;
    }
    return retorno;
}

//PUNTO 13
void MostrarMascotasPorTipo(eMascota listaMascotas[],int sizeMascotas)
{
    int i;
    int opcion;
    do
    {
        Banner("MASCOTAS POR TIPO");
        MenuMascotasPorTipo();
        opcion = getInt("\nIngrese una opcion: ");
        switch(opcion)
        {
           case 1:
                Banner("LISTA DE PERROS");
                HeaderMascota("ID","NOMBRE","TIPO","RAZA","EDAD","PESO","SEXO\n");
                for(i=0;i<sizeMascotas;i++)
                {
                    CompararYMostrarTipoMascota(listaMascotas[i],"Perro");
                }
                printf("\n");
                LimpiarPantalla();
                break;
            case 2:
                Banner("LISTA DE GATOS");
                HeaderMascota("ID","NOMBRE","TIPO","RAZA","EDAD","PESO","SEXO\n");
                for(i=0;i<sizeMascotas;i++)
                {
                    CompararYMostrarTipoMascota(listaMascotas[i],"Gato");

                }
                printf("\n");
                LimpiarPantalla();
                break;
            case 3:
                Banner("LISTA RAROS");
                HeaderMascota("ID","NOMBRE","TIPO","RAZA","EDAD","PESO","SEXO\n");
                for (i=0;i<sizeMascotas;i++)
                {
                    if(strcmp(listaMascotas[i].tipo,"Gato") !=0 && strcmp(listaMascotas[i].tipo,"Perro")!=0 && listaMascotas[i].isEmpty == OCUPADO)
                    {
                        MostrarUnaMascota(listaMascotas[i]);
                        printf("\n");

                    }
                }
                printf("\n");
                LimpiarPantalla();
                break;
            case 4:
                break;
            default:
                printf("Ingrese una opcion valida\n");
        }
    }while(opcion!=4);
}

//AUX PUNTO 13
void CompararYMostrarTipoMascota(eMascota UnaMascota,char tipo[])
{
    ConvertirMinusculas(UnaMascota.tipo);//en caso de que se harcodeen otros datos
    ConvertirPrimerCaracterAMayus(UnaMascota.tipo);

    if (strcmp(UnaMascota.tipo,tipo) == 0 && UnaMascota.isEmpty == OCUPADO)
    {
        MostrarUnaMascota(UnaMascota);
        printf("\n");
    }
}


//PUNTO 16
float SacarPromedioEdadMascotas(eMascota listaMascotas[],int sizeMascotas)
{
    int i;
    int contador=0;
    int acumulador=0;
    for (i=0;i<sizeMascotas;i++)
    {
        if (listaMascotas[i].isEmpty == OCUPADO)
        {
            acumulador+=listaMascotas[i].edad;
            contador++;
        }
    }
    return (float)acumulador/contador;
}


//PUNTO 17
void MostrarPromedioEdadPorTipo(eMascota listaMascotas[],int sizeMascotas)
{
    int i;
    int acumuladores[3]={0,0,0};
    int contadores[3]={0,0,0};
    float promedios[3];
    for (i=0;i<sizeMascotas;i++)
    {
        if (listaMascotas[i].isEmpty == OCUPADO)
        {
            if (strcmp(listaMascotas[i].tipo,"Perro")==0)
            {
                acumuladores[0]+=listaMascotas[i].edad;
                contadores[0]++;
            }
            else
            {
                if (strcmp(listaMascotas[i].tipo,"Gato")==0)
                {
                    acumuladores[1]+=listaMascotas[i].edad;
                    contadores[1]++;
                }
                else
                {
                acumuladores[2]+=listaMascotas[i].edad;
                contadores[2]++;
                }
            }
        }
    }
    for (i=0;i<3;i++)
    {
        promedios[i]= (float)acumuladores[i]/contadores[i];
    }
    printf("\nPromedio edad Perros %.2f: \n",promedios[0]);
    printf("Promedio edad Gatos %.2f: \n",promedios[1]);
    printf("Promedio edad raros %.2f: \n\n",promedios[2]);

}





