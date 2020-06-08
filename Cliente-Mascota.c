
#include "Cliente-Mascota.h"


//PUNTO 2
void MostrarTodasLasMascotasConSusClientes (eMascota listaMascotas[],int sizeMascotas,eCliente listaClientes[],int sizeClientes)
{
    int i;
    Banner("LISTA DE MASCOTAS");
    HeaderMascota("ID","NOMBRE","TIPO","RAZA","EDAD","PESO","SEXO");
    printf("    DUENIO    \n\n");
    for (i=0;i<sizeMascotas;i++)
    {
        MostrarUnaMascotaConSuCliente(listaMascotas[i],listaClientes,sizeClientes);
    }
    printf("\n");
}

//PUNTO 3
void MostrarClienteYsusMastocas(eCliente listaClientes[],int sizeCliente,eMascota listaMascotas[],int sizeMascotas)
{
    int i;
    int j;
    int bandera;
    for (i=0;i<sizeCliente;i++)
    {
        bandera=0;

        if(listaClientes[i].isEmpty==OCUPADO)
        {
            printf("Nombre Cliente: %s ID:%d  Localidad: %s\n ",listaClientes[i].nombre,listaClientes[i].id,listaClientes[i].localidad);
            for(j=0;j<sizeMascotas;j++)
            {
                if (listaClientes[i].id == listaMascotas[j].idCliente && listaMascotas[j].isEmpty==OCUPADO)
                {
                    if (bandera==0)//para no repetirlo y en caso de no tener mascotas no mostrarlo
                    {
                        printf("\nMascotas del cliente\n\n");
                        HeaderMascota("ID","NOMBRE","TIPO","RAZA","EDAD","PESO","SEXO\n");
                        bandera=1;
                    }
                    MostrarUnaMascota(listaMascotas[j]);
                    printf("\n");
                }
            }
            if(bandera==0)
            {
            printf("\n**No tiene Mascotas\n");
            }
            printf("\n");
            printf("-----------------------------------------------------------------------------------------------\n");
        }

    }
}


//PUNTO 4
int AgregarMascota (eMascota listaMascotas[],int sizeMascotas,int iDnueva,eCliente listaClientes[],int sizeClientes,char msj[],char error[],char error2[],eRaza listaRaza[],int sizeRaza)
{

    int bandera=-1;
    int retornoCliente;
    int retornoRaza;
    int indiceLibre;
    indiceLibre = BuscarMascotaLibre(listaMascotas,sizeMascotas);
    if (indiceLibre!=-1)
    {
        Banner("AGREGAR MASCOTA");
        listaMascotas[indiceLibre] = CargarMascota(iDnueva);
        retornoCliente = ValidarClienteIngresado (listaClientes,sizeClientes,listaMascotas[indiceLibre].idCliente);
        retornoRaza = ValidarRazaIngresada (listaRaza,sizeRaza,listaMascotas[indiceLibre].idRazaPais);
        if (retornoCliente!=-1 && retornoRaza!=-1 )
        {
            strcpy(listaMascotas[indiceLibre].raza,listaRaza[retornoRaza].raza);
            strcat(listaMascotas[indiceLibre].raza," ");
            strcat(listaMascotas[indiceLibre].raza,listaRaza[retornoRaza].pais);
            listaMascotas[indiceLibre].isEmpty=OCUPADO;
            printf("%s %d\n",msj,listaMascotas[indiceLibre].id);
            bandera=0;
            iDnueva++;
        }

        if (bandera ==-1)
        {
            printf("%s",error2);//no coincide idIngresada con la de algun cliente o id raza
        }
    }
    else
    {
        printf("%s",error);//no hay espacio
    }
    return iDnueva;
}


//PUNTO 8
int EliminarClienteYsusMascotas(eCliente listaClientes[],int sizeClientes,eMascota listaMascotas[],int sizeMascotas,int idIngresada)
{
    int i;
    int retorno=-1;
    int eliminoCliente;
    eliminoCliente = EliminarCliente(listaClientes,sizeClientes,idIngresada);
    if (eliminoCliente == 0)
    {
        for (i=0;i<sizeMascotas;i++)
        {
            if (listaMascotas[i].idCliente == idIngresada && listaMascotas[i].isEmpty == OCUPADO)
            {
                listaMascotas[i].isEmpty = LIBRE;
            }
        }
        retorno = 0;
    }
    return retorno;
}

void MostrarUnaMascotaConSuCliente (eMascota UnaMascota,eCliente listaClientes[],int sizeClientes)
{
    int i;
    for(i=0;i<sizeClientes;i++)
    {
        if (listaClientes[i].id == UnaMascota.idCliente && UnaMascota.isEmpty == OCUPADO && listaClientes[i].isEmpty == OCUPADO)
        {
            MostrarUnaMascota(UnaMascota);
            printf("    %s %s\n",listaClientes[i].nombre,listaClientes[i].apellido);
            break;
        }
    }
}


//PUNTO 9
int MostrarMascotraPorTipoConSuDuenio(eMascota listaMascotas[],int sizeMascotas,eCliente listaClientes[], int sizeClientes)
{
    int i;
    int retorno=-1;
    OrdenarMascotasPorTipo(listaMascotas,sizeMascotas);
    HeaderMascota("ID","NOMBRE","TIPO","RAZA","EDAD","PESO","SEXO");
    printf("    DUENIO    \n\n");
    for (i=0;i<sizeMascotas;i++)
    {
        MostrarUnaMascotaConSuCliente(listaMascotas[i],listaClientes,sizeClientes);
    }
    return retorno;
}


//PUNTO 11
int MostrarClientesConMasDeUnaMascota(eCliente listaClientes[],int sizeClientes, eMascota listaMascotas[], int sizeMascotas)
{
    int retorno=-1;//-1 si ningun cliente tiene mas de una mascota
    int i;
    int j;
    eCantidades auxiliar[sizeClientes];
    for (i=0;i<sizeClientes;i++)
    {
        auxiliar[i].idCliente = listaClientes[i].id;
    }
    SacarCantidadDeMascotasDeUnArrayClientes(auxiliar,listaClientes,sizeClientes,listaMascotas,sizeMascotas);
    HeaderCliente("ID","NOMBRE","APELLIDO","LOCALIDAD","TELEFONO","EDAD","SEXO");
    printf("    CANTIDAD DE MASCOTAS\n");
    for (i=0;i<sizeClientes;i++)
    {
        for (j=0;j<sizeClientes;j++)//para matchear la iD del auxiliar
        {
            if (listaClientes[i].id == auxiliar[j].idCliente && auxiliar[j].cantidadMascotas >1)
            {
                MostrarUnCliente(listaClientes[i]);
                printf("%14d",auxiliar[j].cantidadMascotas);
                printf("\n");
                retorno=0;
                break;
            }
        }
    }
    printf("\n");
    return retorno;
}



//PUNTO 12
int MostrarMascotasMasDeTresAniosConDuenio(eMascota listaMascotas[],int sizeMascotas, eCliente listaClientes[],int sizeClientes)
{
    int retorno=-1;
    int i;
    int control;

    for (i=0;i<sizeMascotas;i++)
    {
        control = MascotaMayorAtresAnios(listaMascotas[i]);//para no imprimir todos las mascotas a la vez
        if(control == 0) //0 = mayor a 3 años
        {
            if (retorno == -1)//para no repetir de nuevo el header
            {
                HeaderMascota("ID","NOMBRE","TIPO","RAZA","EDAD","PESO","SEXO");
                printf("    DUENIO\n\n");
            }
            MostrarUnaMascotaConSuCliente(listaMascotas[i],listaClientes,sizeClientes);
            retorno =0;
        }
    }
    printf("\n");
    return retorno;//-1 ninguna mascota mayor a 3
}


//aux recibe el auxiliar con las id ya copiada
int SacarCantidadDeMascotasDeUnCliente(eCantidades unCliente,eMascota listaMascotas[],int sizeMascotas)
{
    int i;
    int cantidadMascotas=0;
    for (i=0;i<sizeMascotas;i++)
    {
        if (unCliente.idCliente == listaMascotas[i].idCliente && listaMascotas[i].isEmpty==OCUPADO)
        {
            cantidadMascotas++;
        }
    }
    return cantidadMascotas;
}

void SacarCantidadDeMascotasDeUnArrayClientes(eCantidades auxiliar[],eCliente listaClientes[],int sizeClientes,eMascota listaMascotas[],int sizeMascotas)
{
    int i;
    for (i=0;i<sizeClientes;i++)
    {
        auxiliar[i].cantidadMascotas = SacarCantidadDeMascotasDeUnCliente(auxiliar[i],listaMascotas,sizeMascotas);
    }
}

//PUNTO 14
void MostrarClientesPorCantidadesDeMascotas(eCliente listaClientes[],int sizeClientes, eMascota listaMascotas[], int sizeMascotas)
{
    int i;
    int j;
    eCantidades auxiliar[sizeClientes];
    for (i=0;i<sizeClientes;i++)
    {
        auxiliar[i].idCliente = listaClientes[i].id;
    }
    SacarCantidadDeMascotasDeUnArrayClientes(auxiliar,listaClientes,sizeClientes,listaMascotas,sizeMascotas);
    OrdenarAuxDescendente(auxiliar,sizeClientes);
    HeaderCliente("ID","NOMBRE","APELLIDO","LOCALIDAD","TELEFONO","EDAD","SEXO");
    printf("   CANTIDAD DE MASCOTAS\n");
    for (i=0;i<sizeClientes;i++)
    {
        for (j=0;j<sizeClientes;j++)
        {
            if (auxiliar[i].idCliente == listaClientes[j].id && listaClientes[j].isEmpty == OCUPADO)
            {
                MostrarUnCliente(listaClientes[j]);
                printf("%14d\n",auxiliar[i].cantidadMascotas);
            }
        }
    }
    printf("\n");
}


//PUNTO 15
void MostrarClientesPorCantidadesDeMascotasOrdenados(eCliente listaClientes[],int sizeClientes, eMascota listaMascotas[], int sizeMascotas)
{
    int i;
    int j;
    eCantidades aux;
    eCliente aux2;
    eCantidades auxiliar[sizeClientes];

    for (i=0;i<sizeClientes;i++)
    {
        auxiliar[i].idCliente = listaClientes[i].id;
    }
    SacarCantidadDeMascotasDeUnArrayClientes(auxiliar,listaClientes,sizeClientes,listaMascotas,sizeMascotas);
    for (i=0;i<sizeClientes-1;i++)//como "arrays" paralelos
    {
        for (j=i+1;j<sizeClientes;j++)
        {
            if (auxiliar[i].cantidadMascotas < auxiliar[j].cantidadMascotas ||
                (auxiliar[i].cantidadMascotas == auxiliar[j].cantidadMascotas && strcmp(listaClientes[i].nombre,listaClientes[j].nombre)>0 ))
            {
                aux = auxiliar[i];
                auxiliar[i] = auxiliar[j];
                auxiliar[j] = aux;
                aux2 = listaClientes[i];
                listaClientes[i] = listaClientes[j];
                listaClientes[j] = aux2;
            }
        }
    }

    HeaderCliente("ID","NOMBRE","APELLIDO","LOCALIDAD","TELEFONO","EDAD","SEXO");
    printf("   CANTIDAD DE MASCOTAS\n");
    for (i=0;i<sizeClientes;i++)
    {
        if(listaClientes[i].isEmpty == OCUPADO)
        {
        MostrarUnCliente(listaClientes[i]);
        printf("%14d\n",auxiliar[i].cantidadMascotas);
        }
    }
    printf("\n");
}

//Cantidades, recibe una listaAux de Clientes y compara las cantidades
void OrdenarAuxDescendente(eCantidades listaAux[],int sizeClientes)
{
    int i;
    int j;
    eCantidades aux;
    for (i=0;i<sizeClientes-1;i++)//por cantidad
    {
        for (j=i+1;j<sizeClientes;j++)
        {
            if (listaAux[i].cantidadMascotas < listaAux[j].cantidadMascotas)
            {
                aux = listaAux[i];
                listaAux[i] = listaAux[j];
                listaAux[j] = aux;
            }
        }
    }

}


void MostrarClientesConMascotasDelMismoSexo(eCliente listaClientes[],int sizeClientes,eMascota listaMascotas[],int sizeMascotas)
{
    int i;
    int j;
    int contadorClientesF=0;
    int contadorClientesM=0;
    int contadorM[sizeClientes];
    int contadorF[sizeClientes];
    int id[sizeClientes];
    for (i=0;i<sizeClientes;i++)
    {
        id[i]=listaClientes[i].id;
        contadorM[i] = 0;
        contadorF[i] = 0;
        for (j=0;j<sizeMascotas;j++)
        {
            if (listaClientes[i].id == listaMascotas[j].idCliente && listaClientes[i].isEmpty == OCUPADO)
            {
                if(listaMascotas[j].sexo == 'f' || listaMascotas[j].sexo =='F')
                {
                    contadorF[i]++;//cantidad de mascotas hembra que tiene
                }
                else
                {
                    if(listaMascotas[j].sexo == 'm' || listaMascotas[j].sexo == 'M')
                    {
                        contadorM[i]++;
                    }
                }
            }
        }
        if (contadorF[i]>0)
        {
            contadorClientesF++;//el cliente tiene por lo menos 1 mascota hembra, en caso de comparar por clientes
        }
        if (contadorM[i]>0)
        {
            contadorClientesM++;
        }
    }
    if (contadorClientesF>1)
    {
        printf("Clientes con mascotas hembra\n\n");//entre clientes
        HeaderCliente("ID","NOMBRE","APELLIDO","LOCALIDAD","TELEFONO","EDAD","SEXO");
        printf("    Cantidad\n");
        for (i=0;i<sizeClientes;i++)
        {
            for (j=0;j<sizeClientes;j++)
            {
                if (contadorF[j]>0 && listaClientes[i].isEmpty == OCUPADO && listaClientes[i].id == id[j])
                {
                    MostrarUnCliente(listaClientes[i]);
                    printf("%10d\n",contadorF[j]);
                    break;
                }
            }
        }
    }
    else
    {
        printf("No hay clientes o solo uno tiene mascotas hembra\n");
    }

    if (contadorClientesM>1)
    {
        printf("\nClientes con mascotas macho\n\n");
        HeaderCliente("ID","NOMBRE","APELLIDO","LOCALIDAD","TELEFONO","EDAD","SEXO");
        printf("    Cantidad\n");
        for (i=0;i<sizeClientes;i++)
        {
            for (j=0;j<sizeClientes;j++)
            {
                if (contadorM[j]>0 && listaClientes[i].isEmpty == OCUPADO && listaClientes[i].id == id[j])
                {
                    MostrarUnCliente(listaClientes[i]);
                    printf("%10d\n",contadorM[j]);
                    break;
                }
            }
        }
    }
    else
    {
        printf("No hay clientes o solo uno tiene mascotas macho\n");
    }

    printf("\n");
}


//punto 6 BIS
void ModificarMascotaYDuenio(eMascota listaMascotas[],int sizeMascotas,eCliente listaClientes[],int sizeClientes,eRaza listaRaza[],int sizeRaza,int idIngresado,char msj[],char error[])
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
                HeaderMascota("ID","NOMBRE","TIPO","RAZA","EDAD","PESO","SEXO");
                printf("  ID CLIENTE\n");
                MostrarUnaMascota(listaMascotas[i]);
                printf("%6d",listaMascotas[i].idCliente);
                printf("\n");
                Banner("CAMBIOS HECHOS");
                HeaderMascota("ID","NOMBRE","TIPO","RAZA","EDAD","PESO","SEXO");
                printf("  ID CLIENTE\n");
                MostrarUnaMascota(aux);
                printf("%6d",aux.idCliente);
                MenuModificarMascotaBIS();
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
                        MostrarTodasLasRazas(listaRaza,sizeRaza);
                        auxInt = getInt("Ingrese la id de la nueva raza: ");
                        control = ValidarRazaIngresada(listaRaza,sizeRaza,auxInt);
                        if (control !=-1)
                        {
                            strcpy(aux.raza,listaRaza[control].raza);
                            strcat(aux.raza," ");
                            strcat(aux.raza,listaRaza[control].pais);
                            cambios='y';
                            printf("%s",msj);
                        }
                        else
                        {
                            printf("valor incorreto\n");
                        }
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
                        break;
                    case 7:
                        MostrarTodosLosClientes(listaClientes,sizeClientes);
                        auxInt = getInt("Ingrese el id del nuevo duenio: ");
                        control = ValidarClienteIngresado (listaClientes,sizeClientes,auxInt);
                        if (control !=-1)
                        {
                            aux.idCliente = auxInt;
                            cambios='y';
                            printf("%s",msj);
                        }
                        else
                        {
                            printf("Cliente invalido\n");
                        }
                        LimpiarPantalla();
                        break;
                    case 8:
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
                    case 9:
                        break;
                    default:
                        printf("Ingrese una opcion valida\n");
                        LimpiarPantalla();
                        break;
                }
            }while(opcion!=9);
        }
    }
    if (bandera==0)
    {
        printf("%s",error);
        LimpiarPantalla();
    }
}
