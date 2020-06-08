#define LIBRE 0
#define OCUPADO 1
#define MAXMASCOTAS 20

#include "funciones.h"
#include "menu.h"
//(hasta 20 mascotas)(nombre,tipo{gato
//,perro,raro},raza,edad,peso,sexo)


typedef struct
{
    int id;
    char nombre[40];
    char tipo[20];
    char raza[30];
    int edad;
    float peso;
    char sexo;
    int isEmpty;
    int idCliente;//fk
    int idRazaPais;//fk
}eMascota;

void HardcodearMascotas(eMascota listaMascotas[],int sizeMascotas);

void MostrarUnaMascota(eMascota unaMascota);
void MostrarTodasLasMascota(eMascota listaMascotas[],int sizeMascotas);

void InicializarMascotasLibre(eMascota listaMascotas[],int sizeMascotas);
int BuscarMascotaLibre(eMascota listaMascotas[],int sizeMascotas);

//PUNTO 4
eMascota CargarMascota(int id);

//punto 5
int EliminarMascota (eMascota listaMascotas[],int sizeMascotas,int idIngresado,char confirma[]);

//PUNTO 6
void ModificarMascota(eMascota listaMascotas[],int sizeMascotas,int idIngresado,char msj[],char error[]);

//PUNTO 9
void OrdenarMascotasPorTipo(eMascota listaMascotas[],int sizeMascotas);

//aux punto 12 devuelve 0 si es mayor,-1 si es menor
int MascotaMayorAtresAnios(eMascota UnaMascota);

//punto 13 (sub menu)
void MostrarMascotasPorTipo(eMascota listaMascotas[],int sizeMascotas);
//aux punto 13
void CompararYMostrarTipoMascota(eMascota UnaMascota,char tipo[]);

//PUNTO 16
float SacarPromedioEdadMascotas(eMascota listaMascotas[],int sizeMascotas);

//PUNTO 17
void MostrarPromedioEdadPorTipo(eMascota listaMascotas[],int sizeMascotas);
