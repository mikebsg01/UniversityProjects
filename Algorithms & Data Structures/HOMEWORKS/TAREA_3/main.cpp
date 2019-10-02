/**--------------------------------------------------------------------------------------------------------------------
 * Algoritmo Insertion Sort
 *
 * @author Serrato Guerrero Michael Brandon - Expediente: 258849
 * @author Balderas Beltrán Alan - Expediente: 237020
 * @author Vargas Aguillón Jesús - Expediente: 258872
 */
#include <iostream>

using namespace std;

void insertionSort(int* array, int len);
inline void swap(int* array, int i, int j);
void printArray(int array[], int len);

int main() {
    int n,
        i;

    cout << "\t\tMETODO DE ORDENAMIENTO: INSERTION SORT\n\n"
         << "Cantidad de valores a ordenar: ";
    cin >> n;
    int array[n];

    for (i = 0; i < n; ++i) {
        cout << "Ingrese el valor #" << (i + 1) << ": ";
        cin >> array[i];
    }

    cout << "\nESTADOS DEL ARREGLO:\n";
    insertionSort(array, n);
    return 0;
}

void insertionSort(int* array, int len) {
    int n = len,
        i, j;

    for (i = 1; i < n; ++i){
        for (j = i; (j > 0) && (array[j] < array[j-1]); --j) {
            swap(array, j, j-1);
            printArray(array, n);
        }
    }
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

        METODO DE ORDENAMIENTO: INSERTION SORT

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
