/**
 Algoritmo Selection Sort

 @author Serrato Guerrero Michael Brandon - Expediente: 258849
 @author Balderas Beltr�n Alan - Expediente: 237020
 @author Vargas Aguill�n Jes�s - Expediente: 258872
*/

/*
An�lisis del algoritmo Selection Sort:
--Descripci�n del proceso:

 Ordenar por selecci�n toma 2 valores que ser�an el tama�o del arreglo y el arreglo junto con todos los valores contenidos en �l, lo que hace es del arreglo encontrar el n�mero m�s peque�o y ponerlo en la primera posici�n, despu�s encontrar el siguiente elemento m�s peque�o y ponerlo en la segunda posici�n, as� repetidamente hasta que todos los elementos est�n en la posici�n correcta.
--Pseudoc�digo:

 Escribir: Ordenamiento por el m�todo Selection sort
 La constante n: es un entero de valor 8;
 nums : es un arreglo con los n�meros {6, 3, 12, -1, 6, 2, 3, 11};
 Mandar llamar al m�todo Ordenar por selecci�n envi�ndole (nums y n);
 Mandar llamar al m�todo Imprimir datos envi�ndole (nums y n);
 Ordenar por selecci�n es un m�todo que recibe los valores del arreglo nums y la constante n {
 	Los valores i, j y aux: son variables enteras;
 	Para (i es igual a cero; si i es menor que n-1; i se incrementa en uno)
 	   Para (j es igual a i+1; si j es menor que n; j se incrementa en uno)
 	      Si ( el arreglo a que est� en la posici�n[i] es menor al arreglo a que est� en la posici�n [j]) {
 	      	  El aux toma el valor del arreglo a en la posici�n[i];
 	      	  El arreglo a en la posici�n [i] toma el valor del arreglo a en la posici�n [j];
 	      	  El arreglo a en la posici�n [j] toma el valor del aux;
 }
 Imprimir datos es un m�todo que recibe los valores del arreglo nums y la constante n {
 	Escribir:  Imprimiendo Datos ;
 	Para (el entero i es igual a 0; si i es menor que n; i se incrementa en uno)
	   Escribir: arreglo a en la posici�n [i] ;
	   Escribir: salto de l�nea;

--C�digo:
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
