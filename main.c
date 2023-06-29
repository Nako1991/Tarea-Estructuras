#include <stdio.h>
#include <stdlib.h>

#define DIM 30

//ESTRUCTURAS
typedef struct {
    int habitaciones;
    int anio;
    float metrosCuadrados;
    float precio;
    char direccion[DIM];
} Casa;

//PROTOTIPADO
int cargarCasasHasta(Casa []);
void cargarCasa(Casa [], int );
void mostrarCasas(Casa [], int );
void mostrarCasa(Casa [], int );

//MAIN
int main()
{
    //DECLARACIONES
    Casa casas[DIM];
    int validosCasas;

    //LLAMADOS A FUNCION
    validosCasas = cargarCasasHasta(casas);
    printf("\nvalidosCasas: %i", validosCasas); //debug
    mostrarCasas(casas, validosCasas);

    return 0;
}

//FUNCIONES
int cargarCasasHasta(Casa casa[])
{
    int i = 0;
    char continuar = 's';
    while( continuar == 's' && i < DIM )
    {
        cargarCasa(casa, i);

        printf("\nDesea seguir ingresando casas? s/n: ");
        fflush(stdin);
        scanf("%c", &continuar);
        i++;
    }
    return i;
}

void cargarCasa(Casa casa[], int indexCasa)
{
    printf("\nEsta modificando la casa nro: %i\n", indexCasa+1);
    printf("\nIngrese la cantidad de habitaciones que tiene la casa: ");
    fflush(stdin);
    scanf("%i", &casa[indexCasa].habitaciones);
    printf("\nIngrese el anio de fabricacion de la casa: ");
    fflush(stdin);
    scanf("%i", &casa[indexCasa].anio);
    printf("\nIngrese la cantidad de metros cuadrados de la casa: ");
    fflush(stdin);
    scanf("%f", &casa[indexCasa].metrosCuadrados);
    printf("\nIngrese la direccion de la casa: ");
    fflush(stdin);
    gets(casa[indexCasa].direccion);
    printf("\nIngrese el precio de la casa: ");
    fflush(stdin);
    scanf("%f", &casa[indexCasa].precio);
}

void mostrarCasas(Casa casas[], int validos)
{
    int i = 0;
    while( i < validos )
    {
        mostrarCasa(casas, i);
        i++;
    }
}

void mostrarCasa(Casa casa[], int indexCasa)
{
    printf("\nCasa nro: %i\n", indexCasa+1);
    printf("\nNumero de habitaciones: %i", casa[indexCasa].habitaciones);
    printf("\nAnio de fabricacion: %i", casa[indexCasa].anio);
    printf("\nCantidad de metros cuadrados: %.2f", casa[indexCasa].metrosCuadrados);
    printf("\nDireccion: %s", casa[indexCasa].direccion);
    printf("\nPrecio: %.2f", casa[indexCasa].precio);
}
