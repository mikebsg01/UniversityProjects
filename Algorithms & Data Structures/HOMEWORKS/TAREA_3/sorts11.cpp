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

Obtener n (que es la longitud del arreglo)
Para i = 0 hasta n hacer:
    obtener el valor de Ai (donde A es el arreglo)
Hacer Mientras haya cambios:
    Para j = 0 hasta n-1:
        Si Aj+1 es menor a Aj entonces:
            Cambiar Aj+1 con Aj
        Fin del Si
    Fin del Para
Fin del Hacer Mientas

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
{ 3, 6, -1, 6, 12, 2, 3, 11 }
{ 3, 6, -1, 6, 2, 12, 3, 11 }
{ 3, 6, -1, 6, 2, 3, 12, 11 }
{ 3, 6, -1, 6, 2, 3, 11, 12 }
{ 3, -1, 6, 6, 2, 3, 11, 12 }
{ 3, -1, 6, 2, 6, 3, 11, 12 }
{ 3, -1, 6, 2, 3, 6, 11, 12 }
{ -1, 3, 6, 2, 3, 6, 11, 12 }
{ -1, 3, 2, 6, 3, 6, 11, 12 }
{ -1, 3, 2, 3, 6, 6, 11, 12 }
{ -1, 2, 3, 3, 6, 6, 11, 12 }

------------------------------------------------------------------------------------------------------
*/
