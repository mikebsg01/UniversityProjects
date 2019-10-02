/*
 * PROGRAMA: ÁRBOL BINARIO
 *
 * @author Serrato Guerrero Michael Brandon - Expediente: 258849
 * @author Balderas Beltrán Alan - Expediente: 237020
 * @author Vargas Aguillón Jesús - Expediente: 258872
 */
#include <iostream>
#include <cstdlib>
using namespace std;

struct Nodo {
    int dato;
    Nodo* der;
    Nodo* izq;
};

Nodo* arbol = NULL;

/* ---------------------------------   P R O T O T I P O S   ----------------------------------- */
void menu();
Nodo  *crearNodo(int n);
void insertar(Nodo *&arbol, int n);
void mostrarArbol(Nodo *&arbol, int contadorDeNiveles);
bool busqueda(Nodo *arbol, int n);
void recorridoPreOrder(Nodo *arbol);
void recorridoInOrder(Nodo *arbol);
void recorridoPostOrder(Nodo *arbol);
void copiarNodo(Nodo** nodoB, Nodo** nodoA);
void remplazarPorPredecesor(Nodo **subarbolIzquierdo, Nodo **nodoARemplazar);
bool borrar(Nodo **arbol, int n);
/* ------------------------------   F I N   P R O T O T I P O S   ------------------------------ */

int main() {
   menu();
   return 0;
}

void menu() {
   int dato, opcion, contador = 0;

    do {
        cout << "\t === MENU ===" << endl << endl
             << "1. Insertar un nuevo nodo." << endl
             << "2. Mostrar el Arbol Completo." << endl
             << "3. Buscar un elemento en el Arbol." << endl
             << "4. Recorrido PreOrder del Arbol." << endl
             << "5. Recorrido InOrder del Arbol." << endl
             << "6. Recorrido PostOrder del Arbol." << endl
             << "7. Eliminar nodo" << endl
             << "8. Salir" << endl
	         << "Opcion: ";
	    cin >> opcion;
        cout << endl;

        switch(opcion) {
            case 1:  cout << "\nDigite un numero: ";
                    cin >> dato;
                    cout << endl;
                    insertar(arbol, dato);
                    break;
            case 2:  cout << "Mostrar el arbol.\n\n";
                    cout << endl;
                    mostrarArbol(arbol, contador);
                    cout << endl << endl;
                    //cout << "<ENTER> para continuar..." << endl;
                    system("pause");
                    break;
            case 3:  cout << "Buscar un elemento en el arbol.\n\n";
                    cout << "\nDigite un numero: ";
                    cin >> dato;
                    cout << endl;
                    if (busqueda(arbol, dato) == true) {
                        cout << "El elemento " << dato << " ha sido encontrado." << endl;
                    } else
                        cout << "El elemento " << dato << " No existe." << endl;
                    cout << endl << endl;
                    system("pause");
                    break;
            case 4:  cout << "\nRecorrido en PreOrder: " << endl << endl;
                    recorridoPreOrder(arbol);
                    cout << endl << endl;
                    system("pause");
                    break;
            case 5:  cout << "\nRecorrido en InOrder: " << endl << endl;
                    recorridoInOrder(arbol);
                    cout << endl << endl;
                    system("pause");
                    break;
            case 6:  cout << "\nRecorrido en PostOrder: " << endl << endl;
                    recorridoPostOrder(arbol);
                    cout << endl << endl;
                    system("pause");
                    break;
                    
            case 7:  cout << "\nEliminar un elemento en el arbol.\n\n";
                    cout << "\nDigite un numero: ";
                    cin >> dato;
                    cout << endl;
                    if (busqueda(arbol, dato) == true) {
                        int op;
                        // Mostrar la información del Elemento en Pantalla y preguntar si se desea eliminar.
                        // Según lo que conteste el usuario, proceder a eliminar o no eliminar.
                        cout << "El elemento " << dato << " ha sido encontrado.\n"
                             << "\n\tDesea eliminarlo?\n"
                             << "\t1.- Si\n"
                             << "\t2.- No\n"
                             << "\tRespuesta: ";
                            cin >> op;
                        cout << endl;
                        
                        if (op == 1) {
                            if (borrar(&arbol, dato)) {
                                cout << "\tEl elemento " << dato << " ha sido eliminado exitosamente! :)";
                            }
                        } else {
                            cout << "\tOperacion cancelada, elemento no eliminado.";
                        }
                    } else
                        cout << "El elemento " << dato << " No existe." << endl;
                    cout << endl << endl;
                    system("pause");
                    break;
                case 8:
                    cout << "\tSaliendo...\n" << endl;
                    system("pause");
                    return;
                    break;
                default:
                    cout << "\tLa opcion ingresada no existe!\n" << endl;
                    system("pause");
                    break;
        }
        system("cls");
   } while(opcion != 8);
}

Nodo  *crearNodo(int n) {
   Nodo* nuevo_nodo = new Nodo();
   nuevo_nodo->dato = n;
   nuevo_nodo->der = NULL;
   nuevo_nodo->izq = NULL;

   return nuevo_nodo;
}

void insertar(Nodo *&arbol, int n) {
   if (arbol == NULL) {  // si está vacio
      Nodo* nuevo_nodo = crearNodo(n);
	  arbol = nuevo_nodo;
   } else {
       int valorRaiz = arbol->dato;
       if (n < valorRaiz) {
	      insertar(arbol->izq, n);
	   } else {
	      insertar(arbol->der, n);
	   }
   }
}

// Utiliza un recorrido en profundidad: inorder
// pero inicia por la derecha
void mostrarArbol(Nodo *&arbol, int contadorDeNiveles) {
   if (arbol == NULL) {
      return;
   } else {
       mostrarArbol(arbol->der, contadorDeNiveles+1);
	   for (int i=0; i < contadorDeNiveles; i++) {
	      cout << "  ";
	   }
	   cout << arbol->dato << endl;
	   mostrarArbol(arbol->izq, contadorDeNiveles+1);
   }
}

bool busqueda(Nodo *arbol, int n) {
   if (arbol == NULL) {
      return false;
   } else if (arbol->dato == n) {
       return true;
   } else if (n < arbol->dato) {
       return busqueda(arbol->izq, n);
   } else {
       return busqueda(arbol->der, n);
   }
}


void recorridoPreOrder(Nodo *arbol) {
   if (arbol == NULL) {
      return;
   }

   cout << arbol->dato << " ";
   recorridoPreOrder(arbol->izq);
   recorridoPreOrder(arbol->der);
}

void recorridoInOrder(Nodo *arbol) {
   if (arbol == NULL) {
      return;
   }

   recorridoInOrder(arbol->izq);
   cout << arbol->dato << " ";
   recorridoInOrder(arbol->der);
}

void recorridoPostOrder(Nodo *arbol) {
   if (arbol == NULL) {
      return;
   }

   recorridoPostOrder(arbol->izq);
   recorridoPostOrder(arbol->der);
   cout << arbol->dato << " ";
}

void copiarNodo(Nodo** nodoB, Nodo** nodoA) {
    (*nodoB)->dato = (*nodoA)->dato;
}

void remplazarPorPredecesor(Nodo **subarbolIzquierdo, Nodo **nodoARemplazar) {
    if ((*subarbolIzquierdo)->der != NULL) {
        remplazarPorPredecesor(&(*subarbolIzquierdo)->der, &(*nodoARemplazar));
    } else {
        copiarNodo(&(*nodoARemplazar), &(*subarbolIzquierdo));
        *nodoARemplazar = *subarbolIzquierdo;
        *subarbolIzquierdo = (*subarbolIzquierdo)->izq;
    }
}

bool borrar(Nodo **arbol, int n) {
    if (*arbol == NULL)
        return false;
    
    if (n < (*arbol)->dato) {
        return borrar(&(*arbol)->izq, n);
    } else if (n > (*arbol)->dato) {
        return borrar(&(*arbol)->der, n);
    } else if (n == (*arbol)->dato) {
        Nodo *temp = *arbol;

        if ((*arbol)->izq != NULL and (*arbol)->der != NULL) {
            remplazarPorPredecesor(&(*arbol)->izq, &temp);
        } else if ((*arbol)->izq != NULL and (*arbol)->der == NULL) {
            (*arbol) = (*arbol)->izq;
        } else if ((*arbol)->der != NULL) {
            (*arbol) = (*arbol)->der;
        } else {
            delete *arbol;
            *arbol = NULL;
            return true;
        }

        delete temp;
        temp = NULL;
        return true;
    }
    return false;
}

/* --------------------------------------------------------------------------------------------------- //
                                CORRIDAS - Programa: ÁRBOL BINARIO
------------------------------------------------------------------------------------------------------ // 

Opcion: 1
*** OPCION INSERTAR ***
Digite un numero: 16

Opcion: 1
*** OPCION INSERTAR ***
Digite un numero: 59

Opcion: 1
*** OPCION INSERTAR ***
Digite un numero: 8

Opcion: 1
*** OPCION INSERTAR ***
Digite un numero: 22

Opcion: 1
*** OPCION INSERTAR ***
Digite un numero: 70

Opcion: 1
*** OPCION INSERTAR ***
Digite un numero: 7

Opcion: 1
*** OPCION INSERTAR ***
Digite un numero: 74

Opcion: 2
*** OPCION MOSTRAR ARBOL COMPLETO ***
Mostrar el arbol.
      74
    70
  59
    22
16
  8
    7

Opcion: 7
*** OPCION ELIMINAR UN ELEMENTO DEL ARBOL ***
Digite un numero: 59

El elemento 59 ha sido encontrado.

        Desea eliminarlo?
        1.- Si
        2.- No
        Respuesta: 1

        El elemento 59 ha sido eliminado exitosamente! :)

Opcion: 2
*** OPCION MOSTRAR ARBOL COMPLETO ***
Mostrar el arbol.
      74
    70
  22
16
  8
    7

Opcion: 8
*** OPCION SALIR ***

        Saliendo...

        **** Programa finalizado ****

------------------------------------------------------------------------------------------------------ */