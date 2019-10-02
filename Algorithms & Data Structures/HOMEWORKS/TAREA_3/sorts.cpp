/**
 Algoritmo Selection Sort

 @author Serrato Guerrero Michael Brandon - Expediente: 258849
 @author Balderas Beltrán Alan - Expediente: 237020
 @author Vargas Aguillón Jesús - Expediente: 258872
*/

/*
Análisis del algoritmo Selection Sort:
--Descripción del proceso:

 Ordenar por selección toma 2 valores que serían el tamaño del arreglo y el arreglo junto con todos los valores contenidos en él, lo que hace es del arreglo encontrar el número más pequeño y ponerlo en la primera posición, después encontrar el siguiente elemento más pequeño y ponerlo en la segunda posición, así repetidamente hasta que todos los elementos estén en la posición correcta.
--Pseudocódigo:

 Escribir: Ordenamiento por el método Selection sort
 La constante n: es un entero de valor 8;
 nums : es un arreglo con los números {6, 3, 12, -1, 6, 2, 3, 11};
 Mandar llamar al método Ordenar por selección enviándole (nums y n);
 Mandar llamar al método Imprimir datos enviándole (nums y n);
 Ordenar por selección es un método que recibe los valores del arreglo nums y la constante n {
 	Los valores i, j y aux: son variables enteras;
 	Para (i es igual a cero; si i es menor que n-1; i se incrementa en uno)
 	   Para (j es igual a i+1; si j es menor que n; j se incrementa en uno)
 	      Si ( el arreglo a que está en la posición[i] es menor al arreglo a que está en la posición [j]) {
 	      	  El aux toma el valor del arreglo a en la posición[i];
 	      	  El arreglo a en la posición [i] toma el valor del arreglo a en la posición [j];
 	      	  El arreglo a en la posición [j] toma el valor del aux;
 }
 Imprimir datos es un método que recibe los valores del arreglo nums y la constante n {
 	Escribir:  Imprimiendo Datos ;
 	Para (el entero i es igual a 0; si i es menor que n; i se incrementa en uno)
	   Escribir: arreglo a en la posición [i] ;
	   Escribir: salto de línea;

--Código:
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void imprimirDatos(int a[], int n);
void ordenarPorSeleccion(int a[], int n);
void imprimirOrdenamiento(int a[],int n);

int main(){
    int n, i;

    cout << "\t\tMETODO DE ORDENAMIENTO: SELECTION SORT\n\n"
         << "Cantidad de valores a ordenar: ";
    cin >> n;
    int array[n];

    for (i = 0; i < n; ++i) {
        cout << "Ingrese el valor #" << (i + 1) << ": ";
        cin >> array[i];
    }

    imprimirDatos(array, n);
    ordenarPorSeleccion(array, n);
    imprimirDatos(array, n);
    return 0;
}
void imprimirDatos(int a[], int n) {
	cout << "== Imprimiendo Datos ==" << endl << endl;
	for(int i = 0; i < n; i++)
	   cout << a[i] << " ";
	cout << endl << "-----------------------------------" << endl;
}
void imprimirOrdenamiento(int a[], int n) {
	for(int i = 0; i < n; i++)
	   cout << a[i] << " ";
	cout <<endl;
}
void ordenarPorSeleccion(int a[], int n) {
	int i,j,aux;
	for(i = 0; i < n-1; i++)
	   for(j = i+1; j < n; j++)
	      if ( a[i] > a[j]) {
	      	  aux = a[i];
	      	  a[i] = a[j];
	      	  a[j] = aux;
	      	  imprimirOrdenamiento(a,n);
	      }
}

/*
 *************** CORRIDA DEL PROGRAMA:  ***************

    METODO DE ORDENAMIENTO: SELECTION SORT

Cantidad de valores a ordenar: 8
Ingrese el valor #1: 6
Ingrese el valor #2: 3
Ingrese el valor #3: 12
Ingrese el valor #4: -1
Ingrese el valor #5: 6
Ingrese el valor #6: 2
Ingrese el valor #7: 3
Ingrese el valor #8: 11
== Imprimiendo Datos ==

6 3 12 -1 6 2 3 11
-----------------------------------
3 6 12 -1 6 2 3 11
-1 6 12 3 6 2 3 11
-1 3 12 6 6 2 3 11
-1 2 12 6 6 3 3 11
-1 2 6 12 6 3 3 11
-1 2 3 12 6 6 3 11
-1 2 3 6 12 6 3 11
-1 2 3 3 12 6 6 11
-1 2 3 3 6 12 6 11
-1 2 3 3 6 6 12 11
-1 2 3 3 6 6 11 12
== Imprimiendo Datos ==

-1 2 3 3 6 6 11 12
-----------------------------------
*/
