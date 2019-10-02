#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void quick_sort(long[],long,long);
long partition(long[],long,long);
void imprime(long[], long);
void obtenerDatos(long** ptr_de_a);
void imprimeResultados();

// Variables Globales
long cantidadElementos, nComparaciones, nIntercambios;
double tiempo = 0;

int main() {
    long* arreglo = 0;

    nComparaciones = 0;
    nIntercambios  = 0;

	obtenerDatos(&arreglo);
    printf("\nArreglo: ");
    imprime(arreglo, cantidadElementos);
    clock_t tic;
    clock_t toc;
    tic = clock();
    quick_sort(arreglo,0,cantidadElementos-1);
    toc = clock();
    tiempo = (double ) (toc - tic ) / (1.0*CLOCKS_PER_SEC); // número de segundos

    //printf("\nArreglo despues de ordenar: ");
    //imprime(arreglo, cantidadElementos);
    imprimeResultados();

    return 0;
}

void quick_sort( long a[],long l,long u)
{
    long j;

    if(l<u)
    {
        //printf("PARTITION:\n\tl: %d - u: %d\n", l, u);
        j=partition(a,l,u);
        //printf("END PARTITION:\n\tj: %d\n", j);
        //printf("QUICKSORT:\n\tl: %d - j-1: %d\n", l, j-1);
        quick_sort(a,l,j-1);
        //printf("QUICKSORT:\n\tj+1: %d - u: %d\n", j+1, u);
        quick_sort(a,j+1,u);
    }
}

long partition(long a[], long l, long u)
{
    long v,i,j,temp;

    v=a[l];
    i=l;
    j=u+1;

    do
    {
        do {
           i++;
           nComparaciones++;
        } while(a[i]<v&&i<=u);


        do {
           j--;
           nComparaciones++;
        } while(v<a[j]);

        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            imprime(a, cantidadElementos);
            nIntercambios++;
        }
    }while(i<j);

    a[l]=a[j];
    a[j]=v;
    imprime(a, cantidadElementos);
    ++nIntercambios;

    return(j);
}

// Métodos de Soporte

void imprime(long a[], long n) {

    for(long i=0; i<n; i++)
        printf("%ld ",a[i]);
    printf("\n");
}

void obtenerDatos(long** ptr_de_a) {

    //cantidadElementos = 8; long datos[] = {10,2,7,3,9,54,14,1};
    //cantidadElementos = 5;     long datos[] = {8,7,1,9,4};
    //cantidadElementos = 12;  unsigned long datos[] = {12,2,44,10,4,15,7,28,9,45,1,8};
    //cantidadElementos = 22;    long datos[] = {10,2,3,4,7,9,14,28,45,1,8,40,43,49,51,70,72,75,77,80,82,5};
   /* cantidadElementos = 43;
    long datos[] = {10,2,33,448,7,9,14,28,-1,12,45,1,8,40,43,12,49,51,70,72,13,75,
    77,80,82,55,6,3,48,66,124,667,221,5,222,447,41,11,79,44,450,13,-1};
    */

    int datos[] = { 0, 12, -3, -7, 13, 8, 10, 0, -13, 15 };
    cantidadElementos = sizeof(datos) /sizeof(int);
    printf("n: %d\n", cantidadElementos);
    *ptr_de_a = new long[cantidadElementos];

    /*
    cantidadElementos = 2000000;
    srand(time(NULL));
    *ptr_de_a = new long[cantidadElementos];
    */
    for(long i = 0; i < cantidadElementos; i++) {
        *(*ptr_de_a + i) = datos[i];
        //*(*ptr_de_a + i) = rand() % 1000000 + 1;
    }
}

void imprimeResultados() {
    printf("ALGORITMO Sort: Quick Sort <recursivo> \n");
    printf("Numero de elementos: %ld \n", cantidadElementos);
    printf("Numero de comparaciones: %ld \n", nComparaciones);
    printf("Numero de intercambios: %ld \n", nIntercambios);
    printf("Tiempo de ejecucion: %f \n", tiempo);
}
