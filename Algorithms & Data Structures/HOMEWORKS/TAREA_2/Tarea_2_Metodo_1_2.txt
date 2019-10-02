/**
 * Insertar un número entero en un arreglo pero de manera ordenada;
 * Sí el elemento a insertar ya existe NO se debe insertar.
 *
 * @author Serrato Guerrero Michael Brandon - Expediente: 258849
 * @author Balderas Beltrán Alan - Expediente: 237020
 * @author Vargas Aguillón Jesús - Expediente: 258872
 */
#include <iostream>
using namespace std;

int insertarEnOrden(int a[], int* len, int v);
void imprimirArreglo(int a[], int len);

int main() {
    int i,
        valor,
        cantidad,
        posicion,
        longitud = 0;

    cout << "========== METODO 1.2 InsertarEnOrden ==========\n\n"
         << "CANTIDAD DE VALORES A AGREGAR: ";
    cin >> cantidad;
    cout << "=================================================\n";

    int arreglo[cantidad];

    for (i = 0; i < cantidad; ++i) {
        cout << "VALOR #" << (i + 1) << ": ";
        cin >> valor;
        cout << "\n";
        posicion = insertarEnOrden(arreglo, &longitud, valor);
        cout << "\nVALOR ENCONTRADO/INSERTADO EN LA POSICION #" << posicion << "\n\n";
        imprimirArreglo(arreglo, longitud);
    }
    return 0;
}

int insertarEnOrden(int a[], int* len, int v) {
    int i,
        temp1,
        temp2,
        pos = 0;

    while (pos < *len && a[pos] <= v) {
        if (a[pos] == v) {
            return pos;
        }
        ++pos;
    }

    ++*len;
    temp1 = a[pos];

    for (i = pos + 1; i < *len; ++i) {
        temp2 = a[i];
        a[i] = temp1;
        temp1 = temp2;
    }

    a[pos] = v;
    return pos;
}

void imprimirArreglo(int a[], int len) {
    int i;

    cout << "ARREGLO: \n";

    for(i = 0; i < len; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n=================================================\n";
}

