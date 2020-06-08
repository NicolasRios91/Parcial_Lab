
//Alumno: Ríos Paredes Ricardo Nicolás

#include "Cliente-Mascota.h"


int main()
{
    float promedio;
    float promedioHombres;
    float promedioMujeres;

    int idMascota=112;//inicializadas asi por el hardcodeo;
    int idCliente=5;

    int idIngresada;
    int aux;//controla los valores de retorno

    int opcion;

    eRaza listaRaza[6];
    eCliente listaClientes[MAXMASCOTAS];
    eMascota listaMascotas[MAXMASCOTAS];

    InicializarMascotasLibre(listaMascotas,MAXMASCOTAS);
    InicializarClientes(listaClientes,MAXCLIENTES);

    HardcodearRaza(listaRaza,6);
    HardcodearCliente(listaClientes,5);
    HardcodearMascotas(listaMascotas,11);

    do
    {
        system("cls");
        MenuPrincipal();
        fflush(stdin);
        opcion = getInt("\nIngrese una opcion: ");

        switch(opcion)
        {
            case 1:
                system("cls");
                MostrarTodosLosClientes(listaClientes,MAXCLIENTES);
                LimpiarPantalla();
                break;
            case 2:
                system("cls");

                MostrarTodasLasMascotasConSusClientes (listaMascotas,MAXMASCOTAS,listaClientes,MAXCLIENTES);
                LimpiarPantalla();
                break;
            case 3:
                system("cls");
                MostrarClienteYsusMastocas(listaClientes,MAXCLIENTES,listaMascotas,MAXMASCOTAS);
                LimpiarPantalla();
                break;
            case 4:
                system("cls");
                MostrarTodosLosClientes(listaClientes,MAXCLIENTES);
                MostrarTodasLasRazas(listaRaza,6);
                idMascota = AgregarMascota(listaMascotas,MAXMASCOTAS,idMascota,listaClientes,MAXCLIENTES,"Se agrego la mascota con el ID:","ERROR: No hay lugar\n",
                                                                        "ERROR: La ID del cliente o raza ingresada no existe,no se cargo la mascota\n",listaRaza,6);
                LimpiarPantalla();
                break;
            case 5:
                system("cls");
                MostrarTodasLasMascota(listaMascotas,MAXMASCOTAS);
                idIngresada = getInt("\ningrese la ID de la mascota que desa eliminar: ");
                aux = EliminarMascota(listaMascotas,MAXMASCOTAS,idIngresada,"Confirma la baja de la mascota?(y/n): ");
                if (aux !=-1)
                {
                    printf("La mascota fue eliminada\n");
                }
                else
                {
                    printf("No se elimino la mascota o no se encontro la ID\n");
                }
                LimpiarPantalla();
                break;
            case 6:
                system("cls");
                MostrarTodasLasMascota(listaMascotas,MAXMASCOTAS);
                idIngresada = getInt("\nIngrese la ID de la mascota que quiere modificar: ");
                //ModificarMascota(listaMascotas,MAXMASCOTAS,idIngresada,"Se guardo el cambio\n","No se encontro la ID\n");
                ModificarMascotaYDuenio(listaMascotas,MAXMASCOTAS,listaClientes,MAXCLIENTES,listaRaza,6,idIngresada,"Se guardo el cambio\n","No se encontro la ID\n");
                break;
            case 7:
                system("cls");
                Banner("AGREGAR CLIENTE");
                idCliente = AgregarCliente(listaClientes,MAXCLIENTES,idCliente,"El cliente se cargo exitosamente\n","No se pudo cargar al cliente\n");
                LimpiarPantalla();
                break;
            case 8:
                system("cls");
                Banner("ELIMINAR CLIENTE Y SUS MASCOTAS");
                MostrarTodosLosClientes(listaClientes,MAXCLIENTES);
                idIngresada = getInt("\nIngrese la ID que desea eliminar: ");
                aux = EliminarClienteYsusMascotas(listaClientes,MAXCLIENTES,listaMascotas,MAXMASCOTAS,idIngresada);
                if (aux ==0 )
                {
                    printf("Se elimino al cliente con sus mascotas\n");
                }
                else
                {
                    printf("No se elimino al cliente o no se encontro\n");
                }
                LimpiarPantalla();
                break;
            case 9:
                system("cls");
                Banner("MASCOTAS POR TIPO Y SU DUENIO");
                aux = MostrarMascotraPorTipoConSuDuenio(listaMascotas,MAXMASCOTAS,listaClientes,MAXCLIENTES);
                printf("\n");
                LimpiarPantalla();
                break;
            case 10:
                system("cls");
                Banner("MODIFICAR CLIENTE");
                MostrarTodosLosClientes(listaClientes,MAXCLIENTES);
                idIngresada = getInt("\nIngrese la ID: ");
                aux = ModificarCliente(listaClientes,MAXCLIENTES,idIngresada,"Se guardaron los cambios\n");
                break;
            case 11:
                system("cls");
                Banner("CLIENTES CON MAS DE UNA MASCOTA");
                aux = MostrarClientesConMasDeUnaMascota(listaClientes,MAXCLIENTES,listaMascotas,MAXMASCOTAS);
                if (aux==-1)
                {
                    printf("Ningun cliente tiene mas de una mascota\n");
                }
                LimpiarPantalla();
                break;
            case 12:
                system("cls");
                Banner("MASCOTAS MAYORES A 3 AÑOS CON SUS DUENIOS");
                aux = MostrarMascotasMasDeTresAniosConDuenio(listaMascotas,MAXMASCOTAS,listaClientes,MAXCLIENTES);
                if (aux ==-1)
                {
                    printf("Ninguna mascota supera los 3 años\n");
                }
                LimpiarPantalla();
                break;
            case 13:
                system("cls");
                MostrarMascotasPorTipo(listaMascotas,MAXMASCOTAS);
                break;
            case 14:
                system("cls");
                Banner("CLIENTES POR CANTIDADES DE MASCOTAS");
                MostrarClientesPorCantidadesDeMascotas(listaClientes,MAXCLIENTES,listaMascotas,MAXMASCOTAS);
                LimpiarPantalla();
                break;
            case 15:
                system("cls");
                Banner("CLIENTES POR CANTIDADES DE MASCOTAS Y ORDENADOS ALFABETICAMENTE");
                MostrarClientesPorCantidadesDeMascotasOrdenados(listaClientes,MAXCLIENTES,listaMascotas,MAXMASCOTAS);
                LimpiarPantalla();
                break;
            case 16:
                promedio = SacarPromedioEdadMascotas(listaMascotas,MAXMASCOTAS);
                printf("\nPromedio edad mascotas: %.2f\n\n",promedio);
                LimpiarPantalla();
                break;
            case 17:
                MostrarPromedioEdadPorTipo(listaMascotas,MAXMASCOTAS);
                LimpiarPantalla();
                break;
            case 18:
                //promedioHombres = SacarPromedioClientes(listaClientes,MAXCLIENTES,'m');
                promedioMujeres = SacarPromedioClientes(listaClientes,MAXCLIENTES,'F');
                //printf("Promedio hombres: %.2f (%.2f%% de los clientes)\n",promedioHombres,promedioHombres*100);
                printf("Promedio mujeres: %.2f (%.2f%% de los clientes)\n\n",promedioMujeres,promedioMujeres*100);
                LimpiarPantalla();
                break;
            case 19:
                system("cls");
                MostrarClientesConMascotasDelMismoSexo(listaClientes,MAXCLIENTES,listaMascotas,MAXMASCOTAS);
                LimpiarPantalla();
                break;
            case 20:
                break;
            default:
                printf("Ingrese una opcion valida\n");
                LimpiarPantalla();
                break;
        }
    }while(opcion!=20);

    return 0;
}
