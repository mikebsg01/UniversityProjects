/**
 * Buscar e insertar en orden un número entero en un arreglo ordenado; 
 * sí lo encuentra no lo duplica, retorna la posición donde se ubica; 
 * sí no lo encuentra retorna la posición donde fue insertado.
 *
 * @author Serrato Guerrero Michael Brandon - Expediente: 258849
 * @author Balderas Beltrán Alan - Expediente: 237020
 * @author Vargas Aguillón Jesús - Expediente: 258872
 */
#include <iostream>
#define NOT_FOUND -1
using namespace std;

int buscarEInsertarEnOrden(int a[], int* len, int v);
int buscarEnOrden(int a[], int len, int v);
int insertarEnOrden(int a[], int* len, int v);
void imprimirArreglo(int a[], int len);

int main() {
    int i,
        valor,
        cantidad,
        posicion,
        longitud = 0;

    cout << "========== METODO 1.4 BuscarEInsertarEnOrden ==========\n\n"
         << "CANTIDAD DE VALORES A AGREGAR: ";
    cin >> cantidad;
    cout << "=================================================\n";

    int arreglo[cantidad];

    for (i = 0; i < cantidad; ++i) {
        cout << "VALOR #" << (i + 1) << ": ";
        cin >> valor;
        cout << "\n";
        posicion = buscarEInsertarEnOrden(arreglo, &longitud, valor);
        cout << "\nVALOR ENCONTRADO/INSERTADO EN LA POSICION #" << posicion << "\n\n";
        imprimirArreglo(arreglo, longitud);
    }
    return 0;
}

int buscarEInsertarEnOrden(int a[], int* len, int v) {
    int posicion = buscarEnOrden(a, *len, v);

    if (posicion == -1) {
        return insertarEnOrden(a, len, v);
    }

    return posicion;
}

int insertarEnOrden(int a[], int* len, int v) {
    int i,
        temp1,
        temp2,
        pos = 0;

    while (pos < *len && a[pos] <= v) {
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

int buscarEnOrden(int a[], int len, int v) {
    int enmedio,
        inicio = 0,
        fin = len - 1;

    while (inicio < fin) {
        enmedio = (inicio + fin) / 2;

        if (a[enmedio] < v) {
            inicio = enmedio + 1; 
        } else {
            fin = enmedio;
        }
    }

    if (a[inicio] != v) {
        return NOT_FOUND;
    }

    return inicio;
}

void imprimirArreglo(int a[], int len) {
    int i;

    cout << "ARREGLO: \n";

    for(i = 0; i < len; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n=================================================\n";
}
