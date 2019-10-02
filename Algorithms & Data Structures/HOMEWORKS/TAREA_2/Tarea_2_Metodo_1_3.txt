/**
 * Buscar un número entero en un arreglo ordenado, 
 * sí lo encuentra retorna la posición
 * del número encontrado en el arreglo; 
 * sí no lo encuentra retorna -1.
 *
 * @author Serrato Guerrero Michael Brandon - Expediente: 258849
 * @author Balderas Beltrán Alan - Expediente: 237020
 * @author Vargas Aguillón Jesús - Expediente: 258872
 */
#include <iostream>
#define NOT_FOUND -1
using namespace std;

int buscarEnOrden(int a[], int len, int v);
void imprimirArreglo(int a[], int len);

int main() {
    int i,
        valor,
        cantidad,
        posicion;

    cout << "========== METODO 1.3 BuscarEnOrden ==========\n\n"
         << "CANTIDAD DE VALORES A AGREGAR: ";
    cin >> cantidad;
    cout << "=================================================\n";

    int arreglo[cantidad];

    for (i = 0; i < cantidad; ++i) {
        cout << "VALOR #" << (i + 1) << ": ";
        cin >> arreglo[i];
    }

    cout << "\n";
    imprimirArreglo(arreglo, cantidad);
    cout << "BUSCAR VALOR: ";

    while (cin >> valor) {
        posicion = buscarEnOrden(arreglo, cantidad, valor);
        cout << "\n";

        if (posicion != NOT_FOUND) {
            cout << "ENCONTRADO EN LA POSICION #" << posicion;
        } else {
            cout << "EL VALOR " << valor << " NO EXISTE EN EL ARREGLO";
        }
        
        cout << "\n=================================================\n"
             << "BUSCAR VALOR: ";
    }
    return 0;
}

int buscarEnOrden(int a[], int len, int v) {
    int enmedio,
        inicio = 0,
        fin = len;

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
