/**--------------------------------------------------------------------------------------------------------------------
 * Algoritmo Bubble Sort
 *
 * @author Serrato Guerrero Michael Brandon - Expediente: 258849
 * @author Balderas Beltrán Alan - Expediente: 237020
 * @author Vargas Aguillón Jesús - Expediente: 258872
 */

/*
Análisis del algoritmo Bubble Sort:
--Descripción del proceso:
El algoritmo consiste en iterar todo el arreglo buscando elementos que no se encuentren en orden dependiendo del elemento
inmediatamente anterior, esto se realiza varias veces hasta que no se obtengan nuevos cambios.

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
#include <iostream>

using namespace std;

void bubbleSort(int* array, int len);
inline void swap(int* array, int i, int j);
void printArray(int array[], int len);

int main() {
    int n,
        i;

    cout << "\t\tMETODO DE ORDENAMIENTO: BUBBLE SORT\n\n"
         << "Cantidad de valores a ordenar: ";
    cin >> n;
    int array[n];

    for (i = 0; i < n; ++i) {
        cout << "Ingrese el valor #" << (i + 1) << ": ";
        cin >> array[i];
    }

    cout << "\nESTADOS DEL ARREGLO:\n";
    bubbleSort(array, n);
    return 0;
}

void bubbleSort(int* array, int len) {
    int n = len,
        i, j;
    bool changes;

    do {
        changes = false;
        for (j = 0; j < n-1; ++j) {
            if (array[j + 1] < array[j]) {
                swap(array, j + 1, j);
                printArray(array, n);
                changes = true;
            }
        }
    } while (changes);
}

inline void swap(int* array, int i, int j) {
    int temp = array[j];
    array[j] = array[i];
    array[i] = temp;
}

void printArray(int array[], int len) {
    int i;

    cout << "{ ";
    for (i = 0; i < len; ++i) {
        if (i) {
            cout << ", " << array[i];
        } else {
            cout << array[i];
        }
    }
    cout << " }\n";
}

/*
 *************** CORRIDA DEL PROGRAMA:  ***************

        METODO DE ORDENAMIENTO: BUBBLE SORT

Cantidad de valores a ordenar: 8
Ingrese el valor #1: 6
Ingrese el valor #2: 3
Ingrese el valor #3: 12
Ingrese el valor #4: -1
Ingrese el valor #5: 6
Ingrese el valor #6: 2
Ingrese el valor #7: 3
Ingrese el valor #8: 11

ESTADOS DEL ARREGLO:
{ 3, 6, 12, -1, 6, 2, 3, 11 }
{ 3, 6, -1, 12, 6, 2, 3, 11 }
{ 3, -1, 6, 12, 6, 2, 3, 11 }
{ -1, 3, 6, 12, 6, 2, 3, 11 }
{ -1, 3, 6, 6, 12, 2, 3, 11 }
{ -1, 3, 6, 6, 2, 12, 3, 11 }
{ -1, 3, 6, 2, 6, 12, 3, 11 }
{ -1, 3, 2, 6, 6, 12, 3, 11 }
{ -1, 2, 3, 6, 6, 12, 3, 11 }
{ -1, 2, 3, 6, 6, 3, 12, 11 }
{ -1, 2, 3, 6, 3, 6, 12, 11 }
{ -1, 2, 3, 3, 6, 6, 12, 11 }
{ -1, 2, 3, 3, 6, 6, 11, 12 }

------------------------------------------------------------------------------------------------------
*/
