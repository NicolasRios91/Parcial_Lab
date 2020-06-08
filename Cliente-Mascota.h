


#include "funciones.h"
#include "Cliente.h"
#include "Mascota.h"
#include "menu.h"
#include "Raza.h"

typedef struct
{
    int idCliente;
    int cantidadMascotas;
}eCantidades;



//aux punto 3,12,
void MostrarUnaMascotaConSuCliente (eMascota UnaMascota,eCliente listaClientes[],int sizeClientes);

//PUNTO 3
void MostrarTodasLasMascotasConSusClientes (eMascota listaMascotas[],int sizeMascotas,eCliente listaClientes[],int sizeClientes);

//AUX ordena un auxiliar por cantidad de mayor a menor
void OrdenarAuxDescendente(eCantidades listaAux[],int sizeClientes);

//AUX ordena un auxiliar por cantidad de mayor a menor y por nombre
//void OrdenarAuxDescendenteCantYNombre(eCantidades listaAux[],int sizeClientes);

//aux PUNTO 3
void MostrarClienteYsusMastocas(eCliente listaClientes[],int sizeCliente,eMascota listaMascotas[],int sizeMascotas);

//punto 6 bis
void ModificarMascotaYDuenio(eMascota listaMascotas[],int sizeMascotas,eCliente listaClientes[],int sizeClientes,eRaza listaRaza[],int sizeRaza,int idIngresado,char msj[],char error[]);

//PUNTO 8
int EliminarClienteYsusMascotas(eCliente listaClientes[],int sizeClientes,eMascota listaMascotas[],int sizeMascotas,int idIngresada);

//punto 9
int MostrarMascotraPorTipoConSuDuenio(eMascota listaMascotas[],int sizeMascotas,eCliente listaClientes[], int sizeClientes);

//PUNTO 11
int MostrarClientesConMasDeUnaMascota(eCliente listaClientes[],int sizeClientes, eMascota listaMascotas[], int sizeMascotas);

//PUNTO 12
int MostrarMascotasMasDeTresAniosConDuenio(eMascota listaMascotas[],int sizeMascotas, eCliente listaClientes[],int sizeClientes);

//AUX PUNTOS 11,14
int SacarCantidadDeMascotasDeUnCliente(eCantidades unCliente,eMascota listaMascotas[],int sizeMascotas);

//AUX
void SacarCantidadDeMascotasDeUnArrayClientes(eCantidades auxiliar[],eCliente listaClientes[],int sizeClientes,eMascota listaMascotas[],int sizeMascotas);

//PUNTO 14
void MostrarClientesPorCantidadesDeMascotas(eCliente listaClientes[],int sizeClientes, eMascota listaMascotas[], int sizeMascotas);

//PUNTO 15
void MostrarClientesPorCantidadesDeMascotasOrdenados(eCliente listaClientes[],int sizeClientes, eMascota listaMascotas[], int sizeMascotas);

//PUNTO 4 VALIDADO, devuelve el id incrementado si la carga es correcta
int AgregarMascota (eMascota listaMascotas[],int sizeMascotas,int idIngresada,eCliente listaClientes[],int sizeClientes,char msj[],char error[],char error2[],eRaza lista[],int sizeRaza);

//PUNTO 19

void MostrarClientesConMascotasDelMismoSexo(eCliente listaClientes[],int sizeClientes,eMascota listaMascotas[],int sizeMascotas);
