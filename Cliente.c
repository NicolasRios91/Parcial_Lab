#include "Cliente.h"

#include "funciones.h"
//nombre, apellido,localidad,teléfono,edad,sexo)

void HardcodearCliente(eCliente listaClientes[],int sizeClientes)//PUNTO 1
{
    int i;
    int id[5]={1,2,3,4,5};
    char nombre [5][40]={"Ana","Luis","Lucia","Dante","Carlos"};
    char apellido[5][40]={"AAA","BBB","CCC","DDD","EEE"};
    char localidad[5][30]={"Quilmes","Rosario","Rosario","Santa Rosa","Quilmes"};
    char telefono[5][20]={"0111500046001","+15460046002","0460046003","+0460046004","460046005"};
    int edad[5] = {30,35,18,19,30};
    char sexo[5]={'F','M','F','M','M'};
    int isEmpty[5]={1,1,1,1,1};
    for (i=0;i<5;i++)
    {
        listaClientes[i].id=id[i];
        strcpy(listaClientes[i].nombre,nombre[i]);
        strcpy(listaClientes[i].apellido,apellido[i]);
        strcpy(listaClientes[i].localidad,localidad[i]);
        strcpy(listaClientes[i].telefono,telefono[i]);
        listaClientes[i].edad=edad[i];
        listaClientes[i].sexo=sexo[i];
        listaClientes[i].isEmpty=OCUPADO;
    }
}


void InicializarClientes(eCliente listaClientes[],int sizeClientes)
{
    int i;
    for (i=0;i<sizeClientes;i++)
    {
        listaClientes[i].isEmpty=LIBRE;
    }
}


void MostrarUnCliente(eCliente unCliente)
{
    printf("%-5d %-18s %-18s %-18s %-18s %-8d %-2c",unCliente.id,
                                unCliente.nombre,
                                unCliente.apellido,
                                unCliente.localidad,
                                unCliente.telefono,
                                unCliente.edad,
                                unCliente.sexo);
}

int ValidarClienteIngresado (eCliente listaClientes[], int sizeCliente, int idIngresada)//para agregar mascota
{
    int retorno =-1;
    int i;
    for (i=0;i<sizeCliente;i++)
    {
        if (listaClientes[i].id == idIngresada && listaClientes[i].isEmpty == OCUPADO)
        {
        retorno = 1;
        break;
        }
    }
    return retorno;
}


//PUNTO 1
void MostrarTodosLosClientes(eCliente listaClientes[],int sizeClientes)
{
    int i;
    Banner("LISTA DE CLIENTES");
    HeaderCliente("ID","NOMBRE","APELLIDO","LOCALIDAD","TELEFONO","EDAD","SEXO\n");
    for (i=0;i<sizeClientes;i++)
    {
        if (listaClientes[i].isEmpty == OCUPADO)
        {
            MostrarUnCliente(listaClientes[i]);
            printf("\n");
        }
    }
    printf("\n");
}

int BuscarClienteLibre(eCliente listaClientes[],int sizeClientes)
{
    int i;
    int indice=-1;
    for (i=0;i<sizeClientes;i++)
    {
        if (listaClientes[i].isEmpty ==LIBRE)
        {
            indice=i;
            break;
        }
    }
    return indice;
}



//PUNTO 7
eCliente CargarCliente(int idNueva)
{
    eCliente UnCliente;
    UnCliente.id = idNueva;
    getStr("Ingrese el nombre: ",UnCliente.nombre,LARGOSTR);
    getStr("Ingrese el apellido: ",UnCliente.apellido,LARGOSTR);
    getStr("Ingrese la localidad: ",UnCliente.localidad,LARGOSTR);
    getStr("Ingrese el numero de telefono: ",UnCliente.telefono,20);
    UnCliente.edad = getEdadValidada("Ingrese la edad: ","ERROR: El cliente debe ser mayor de edad: ",17);
    UnCliente.sexo = getSexoValidado("Ingrese el sexo: ","ERROR: El sexo debe ser f/m : ");
    UnCliente.isEmpty = OCUPADO;
    return UnCliente;
}

//PUNTO 7
int AgregarCliente(eCliente listaClientes[],int sizeClientes,int idNueva,char msj[],char error[])
{
    int indiceLibre;
    int i;
    indiceLibre = BuscarClienteLibre(listaClientes,sizeClientes);
    if (indiceLibre!=-1)
    {
        idNueva++;
        listaClientes[indiceLibre] = CargarCliente(idNueva);
        printf("%s",msj);
    }
    else
    {
        printf("%s",error);
    }
    return idNueva;
}

//PUNTO 8
int EliminarCliente(eCliente listaClientes[],int sizeClientes,int IdIngresada)
{
    int i;
    int retorno=-1;
    char respuesta;
    for (i=0;i<sizeClientes;i++)
    {
        if (listaClientes[i].id == IdIngresada && listaClientes[i].isEmpty == OCUPADO)
        {
            Banner("CLIENTE A ELIMINAR");
            HeaderCliente("ID","NOMBRE","APELLIDO","LOCALIDAD","TELEFONO","EDAD","SEXO\n");
            MostrarUnCliente(listaClientes[i]);
            printf("\nDesea eliminarlo? y/n: ");
            fflush(stdin);
            respuesta = getchar();
            if (respuesta=='y' || respuesta=='Y')
            {
                listaClientes[i].isEmpty = LIBRE;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//PUNTO 10
int ModificarCliente(eCliente listaClientes[],int sizeCliente, int IdIngresada,char msj[])
{
    int i;
    int opcion;
    eCliente aux;

    int bandera=0;
    char respuesta;
    char cambios;
    int retorno=-1;

    int auxInt;
    int control;
    char auxChar;

    for (i=0;i<sizeCliente;i++)
    {
        if (listaClientes[i].id == IdIngresada && listaClientes[i].isEmpty == OCUPADO)
        {
            bandera=1;
            aux=listaClientes[i];
            do
            {
                system("cls");
                Banner("CLIENTE A MODIFICAR");
                HeaderCliente("ID","NOMBRE","APELLIDO","LOCALIDAD","TELEFONO","EDAD","SEXO\n");
                MostrarUnCliente(listaClientes[i]);
                printf("\n");
                Banner("CAMBIOS HECHOS (OPCION 7 PARA APLICAR CAMBIOS");
                HeaderCliente("ID","NOMBRE","APELLIDO","LOCALIDAD","TELEFONO","EDAD","SEXO\n");
                MostrarUnCliente(aux);

                MenuModificarCliente();
                opcion = getInt("\nElija una opcion: ");
                fflush(stdin);
                switch(opcion)
                {
                    case 1:
                        getStr("Ingrese el nuevo nombre: ",aux.nombre,LARGOSTR);
                        cambios='y';
                        printf("%s\n",msj);
                        LimpiarPantalla();
                        break;
                    case 2:
                        getStr("Ingrese el nuevo apellido: ",aux.apellido,LARGOSTR);
                        cambios='y';
                        printf("%s\n",msj);
                        LimpiarPantalla();
                        break;
                    case 3:
                        getStr("Ingrese la nueva localidad: ",aux.localidad,LARGOSTR);
                        cambios='y';
                        printf("%s\n",msj);
                        LimpiarPantalla();
                        break;
                    case 4:
                        getStr("Ingrese el nuevo numero de contacto: ",aux.telefono,LARGOSTR);
                        cambios='y';
                        printf("%s\n",msj);
                        LimpiarPantalla();
                        break;
                    case 5:
                        auxInt = getInt("Ingrese la nueva edad: ");
                        control = ValidarEdad(auxInt,17);
                        if (control == 0)
                        {
                            aux.edad = auxInt;
                            cambios='y';
                            printf("%s\n",msj);
                            LimpiarPantalla();
                        }
                        else
                        {
                            printf("Le edad es invalida\n");
                            LimpiarPantalla();
                        }
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
                            printf("%s\n",msj);
                            LimpiarPantalla();
                        }
                        else
                        {
                            printf("El sexo ingresado no es valido\n");
                            LimpiarPantalla();
                        }
                        break;
                    case 7:
                        if (cambios =='y')
                        {
                            printf("Confirma los cambios? (y/n): ");
                            fflush(stdin);
                            respuesta = getchar();
                            if (respuesta=='y' || respuesta=='Y')
                            {
                                listaClientes[i]=aux;
                                printf("Los cambios fueron aplicados\n");
                                LimpiarPantalla();
                                retorno = 0;//0 msj positivo -1 no se hizo nada
                            }
                            else
                            {
                            printf("No se aplicaron los cambios\n");
                            LimpiarPantalla();
                            }
                        }
                        else
                        {
                            printf("No hay cambios para aplicar\n");
                            LimpiarPantalla();
                        }
                    case 8:
                        system("cls");
                        break;
                    default:
                        printf("Ingrese una opcion valida\n");
                        LimpiarPantalla();
                }
            }while(opcion!=8);
        break;
        }
    }
    if (bandera ==0)
    {
        printf("No se encontro la ID\n");
        LimpiarPantalla();
    }
    return retorno;
}

//PUNTO 18
float SacarPromedioClientes(eCliente listaClientes[],int sizeClientes,char sexo)
{
    int i;
    int contadorCliente=0;
    int contadorTotal=0;
    sexo = toupper(sexo);
    for (i=0;i<sizeClientes;i++)
    {
        if (listaClientes[i].isEmpty == OCUPADO)
        {
            contadorTotal++;
            if (listaClientes[i].sexo == sexo)
            {
                contadorCliente++;
            }
        }
    }
    return (float)contadorCliente/contadorTotal;
}

void OrdenarPorNombre(eCliente listaClientes[],int sizeClientes)//BURBUJEO POR NOMBRE
{
    int i;
    int j;
    eCliente aux;
    for (i=0;i<sizeClientes-1;i++)
    {
        for (j=i+1;j<sizeClientes;j++)
        {
            if(strcmp(listaClientes[i].nombre,listaClientes[j].nombre)>0 && listaClientes[i].isEmpty==OCUPADO && listaClientes[j].isEmpty==OCUPADO)
            {
                aux = listaClientes[i];
                listaClientes[i] = listaClientes[j];
                listaClientes[j] = aux;
            }
        }
    }
}




