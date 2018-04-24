#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define TAM 5
#define LONG 20
//prueba de git lalallalalala
typedef struct
{
int legajo;
char nombre[LONG];
int nota1;
int nota2;
float promedio;
} eAlumno;

eAlumno pedirAlumno(void);
void mostrarAlumno(eAlumno );
int buscarLibre(eAlumno [],int);
float calcularPromedio(int,int);
int buscarLegajo(eAlumno [],int,int);

int main(void)
{
    eAlumno aux;
    eAlumno listadoDeAlumnos[TAM]= {{20,"Sebastian",10,7,8.5}, {11,"Florencia",8,6,7}, {14,"Javier",9,9,9}};



    int opcion;
    int index;
    int leg;
    do{
        fflush(stdin);
        system("cls");
        printf("1 - ALTAS\n");
        printf("2 - BAJAS\n");
        printf("3 - MODIFICACIONES\n");
        printf("4 - MOSTRAR LISTA\n");
        printf("5 - ORDENAR POR LEGAJO\n");
        printf("9 - SALIR\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                index=buscarLibre(listadoDeAlumnos,TAM);
                if(index!=-1){

                  aux = pedirAlumno();

                    listadoDeAlumnos[index]=aux;
                }else{
                    printf("No hay mas espacio para guardar legajos!!!");
                    getche();
                }
                break;
            case 2:
                printf("Ingrese legajo: ");
                scanf("%d",&leg);
                fflush(stdin);
                index=buscarLegajo(listadoDeAlumnos,TAM,leg);
                if(index!=-1){
                    listadoDeAlumnos[index].legajo=0;
                }else{
                    printf("Legajo no encontrado!!!");
                    getche();
                }
                break;
            case 3:
                printf("Ingrese legajo: ");
                scanf("%d",&leg);
                fflush(stdin);
                index=buscarLegajo(listadoDeAlumnos,TAM,leg);
                if(index!=-1){
                    printf("\nLegajo N: %d",listadoDeAlumnos[index].legajo);
                    printf("\nModificar nombre: ");
                    gets(listadoDeAlumnos[index].nombre);
                    fflush(stdin);
                    printf("\nModificar nota1: ");
                    scanf("%d",&listadoDeAlumnos[index].nota1);
                    fflush(stdin);
                    printf("\nModificar nota2: ");
                    scanf("%d",&listadoDeAlumnos[index].nota2);
                    fflush(stdin);
                    listadoDeAlumnos[index].promedio=calcularPromedio(listadoDeAlumnos[index].nota1,listadoDeAlumnos[index].nota2);

                }else{
                    printf("Legajo no encontrado!!!");
                    getche();
                }
                break;
            case 4:
                for(int i=0;i<TAM;i++){
                    if(listadoDeAlumnos[i].legajo!=0){

                        mostrarAlumno(listadoDeAlumnos[i]);
                    }
                }
                getche();
                break;
            case 5:

                for(int i=0;i<TAM;i++){
                    for(int j=0;j<TAM;j++){
                        if(listadoDeAlumnos[j].legajo>listadoDeAlumnos[j+1].legajo){

                            aux=listadoDeAlumnos[j];
                            listadoDeAlumnos[j]=listadoDeAlumnos[j+1];
                            listadoDeAlumnos[j+1]= aux;
                        }
                    }
                }
                for(int i=0;i<TAM;i++){
                    if(listadoDeAlumnos[i].legajo!=0){

                        mostrarAlumno(listadoDeAlumnos[i]);
                    }
                }
                getche();
                break;
        }
    }while(opcion!=9);

    return 0;
}

int buscarLibre(eAlumno vec[],int tam)
{
    int index = -1;
    for(int i=0;i<tam;i++){
        if(vec[i].legajo==0){
            index=i;
            break;
        }
    }
    return index;
}

float calcularPromedio(int nota1, int nota2)
{
    float promedio;
    promedio = (float)(nota1+nota2)/2;
    return promedio;
}

int buscarLegajo(eAlumno vec[],int tam,int legajo){

    int retorno= -1;
    for(int i=0;i<tam;i++){
        if(vec[i].legajo==legajo){
            retorno = i;
        }
    }
    return retorno;
}

void mostrarAlumno(eAlumno listadoDeAlumnos )
{
    printf("\nLegajo N: %d\n",listadoDeAlumnos.legajo);
    printf("El nombre es: %s\n",listadoDeAlumnos.nombre);
    printf("Nota 1: %d\n",listadoDeAlumnos.nota1);
    printf("Nota 2: %d\n",listadoDeAlumnos.nota2);
    printf("El promedio: %.1f",listadoDeAlumnos.promedio);
    printf("\n");
}

eAlumno pedirAlumno()
{
    eAlumno aluReturn;

    printf("Ingrese Legajo: ");
    scanf("%d", &aluReturn.legajo);
    printf("Ingrese Nombre: ");
    fflush(stdin);
    gets(aluReturn.nombre);
    printf("Ingrese primer nota: ");
    scanf("%d", &aluReturn.nota1);
    printf("Ingrese segunda nota: ");
    scanf("%d", &aluReturn.nota2);
    printf("\n");

    aluReturn.promedio=calcularPromedio(aluReturn.nota1,aluReturn.nota2);

    return aluReturn;
}


