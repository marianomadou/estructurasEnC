#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3
#define LONG 30

typedef struct
{
int codigo;
char descripcion[LONG];
int stock;
int precio;
} eProducto;

eProducto cargarProducto ();

void mostrarListadoDeProductos(eProducto[], int);

void  mostrarProducto(eProducto prod);


int main()
{

    eProducto listadoDeProductos[TAM];
    eProducto aux[TAM];

    int i;
    for(i=0;i<TAM;i++)
    {
        listadoDeProductos[i]=cargarProducto();
    }

//ordenar por descripcion
    for(int i=0; i<TAM-1; i++)
    {
        for(int j=i+1; j<TAM; j++)
        {
            if((strcmp(listadoDeProductos[i].descripcion,listadoDeProductos[j].descripcion))>0)
            {
                aux[i]= listadoDeProductos[i];
                listadoDeProductos[i]=listadoDeProductos[j];
                listadoDeProductos[j]=aux[i];
            }
        }
    }
    mostrarListadoDeProductos(listadoDeProductos, TAM);
    return 0;
     }

void mostrarListadoDeProductos(eProducto lista[], int cantidad)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        mostrarProducto(lista[i]);
    }
}
//
void  mostrarProducto(eProducto prod)
{
   printf("%d --, %s --, %d --, %d --\n",prod.codigo, prod.descripcion, prod.stock, prod.precio);
}

eProducto cargarProducto ()
{
    eProducto prod;

    printf("Ingrese codigo: ");
    scanf("%d", &prod.codigo);
    printf("Ingrese descripcion: ");
    fflush(stdin);
    gets(prod.descripcion);
    printf("Ingrese stock: ");
    scanf("%d", &prod.stock);
    printf("Ingrese Precio: ");
    scanf("%d", &prod.precio);
    printf("\n");

    return prod;
}
