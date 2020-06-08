#define LIBRE 0
#define OCUPADO 1
#define MAXCLIENTES 10
#define LARGOSTR 40

#include "funciones.h"
#include "menu.h"

typedef struct
{
    int id;
    char nombre[LARGOSTR];
    char apellido[LARGOSTR];
    char localidad[LARGOSTR];
    char telefono[LARGOSTR];
    int edad;
    char sexo;
    int isEmpty;
    int idLocalidad;
}eCliente;


void HardcodearCliente(eCliente listaClientes[],int sizeClientes);
void InicializarClientes(eCliente listaClientes[],int sizeClientes);
void MostrarUnCliente(eCliente unCliente);
int ValidarClienteIngresado (eCliente listaClientes[], int sizeCliente, int idIngresada);

//PUNTO 1
void MostrarTodosLosClientes(eCliente listaClientes[],int sizeClientes);


eCliente CargarCliente(int idNueva);
int BuscarClienteLibre(eCliente listaClientes[],int sizeClientes);

//PUNTO 7
int AgregarCliente(eCliente listaClientes[],int sizeClientes,int idNueva,char msj[],char error[]);

//PUNTO 8
int EliminarCliente(eCliente listaClientes[],int sizeClientes,int IdIngresada);

//PUNTO 10
int ModificarCliente(eCliente listaClientes[],int sizeCliente, int IdIngresada,char msj[]);

//PUNTO 18
float SacarPromedioClientes(eCliente listaClientes[],int sizeClientes,char sexo);

//AUX PUNTO 15
void OrdenarPorNombre(eCliente listaClientes[],int sizeClientes);

