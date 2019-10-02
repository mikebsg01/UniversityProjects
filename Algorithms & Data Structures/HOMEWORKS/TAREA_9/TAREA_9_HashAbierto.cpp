/*
 * PROGRAMA: HASH ABIERTO
 *
 * @author Serrato Guerrero Michael Brandon - Expediente: 258849
 * @author Balderas Beltrán Alan - Expediente: 237020
 * @author Vargas Aguillón Jesús - Expediente: 258872
 */
#include <stdio.h>
#include <malloc.h>

/* -------------------------------   E S T R U C T U R A S   ------------------------------- */
struct pair {
    int key;
    int dato;
    struct pair* next;  // porque están encadenados como lista lineal dinámica
};
typedef struct pair t_pair;


/* -----------------------------------   P R O T O T I P O S   ------------------------------ */

void search(t_pair h_table[], int size);
void display(t_pair h_table[], int size);
void insert(t_pair h_table[], int size);
void eliminar(t_pair h_table[], int size);
void inicializarValoresHashTable(t_pair h_table[], int size);
void ingresarElementos(t_pair h_table[], int size);
int menu();
/* ------------------------------   F I N     P R O T O T I P O S   ------------------------- */

int main() {
    int size, opc;

    printf("===    HASH ABIERTO   ===\n\n");
    printf("Ingresa el tamano de la tabla: ");
    scanf("%d", &size);
    printf("------------------------------------------------\n\n");

    t_pair hash_table[size];
    inicializarValoresHashTable(hash_table, size);
    ingresarElementos(hash_table, size);

    do {
        opc = menu();
        printf("\n");
        switch(opc) {
        case 1  : printf("**** Se activo la opcion #1: Desplegar Tabla Hash. \n\n");
                display(hash_table, size);
                break;
        case 2  : printf("**** Se activo la opcion #2: Insertar en Tabla Hash. \n\n");
                printf("Ingresar elemento que se desea insertar: ");
                insert(hash_table, size);
                break;
        case 3  : printf("**** Se activo la opcion #3: Buscar en Tabla Hash. \n\n");
                search(hash_table, size);
                break;
        case 4  : printf("**** Se activo la opcion #4: Eliminar en Tabla Hash. \n\n");
                eliminar(hash_table, size);
                break;
        } // switch
        printf("--------------------------------------------------------------------------------\n\n");
    } while (opc != 5);


    return 0;
} // fin main


/* --------------------------   I M P L E M E N T A C I O N E S   ---------------------------- */

void display(t_pair h_table[], int size) {
    printf("Key\tDatos\n");

    for (int i = 0; i < size; ++i) {
        printf("%d\t%d\n", h_table[i].key, h_table[i].dato);

        t_pair* ptr;
        ptr = h_table[i].next;

        while (ptr != 0) {
            printf("\t%d", ptr->dato);
            ptr = ptr->next;
        }
        printf("\n\n");
    }
} // display


void search(t_pair h_table[], int size) {
    int key, 
        elemento;

    printf("Ingresar elemento que se desea buscar: ");
    scanf("%d", &elemento);
    key = elemento%size;

    if (h_table[key].dato == elemento) {
        printf("Elemento: <%d, %d>", key, h_table[key].dato);
    } else { // Buscar en la lista de <key, dato>
        int encontrado = 0;

        printf("Cabeza (%d, %d): ", key, h_table[key].dato);
        t_pair* ptr;
        ptr = h_table[key].next;

        while (ptr != 0) {
            printf("<%d, %d> ", key, ptr->dato);

            if (ptr->dato == elemento) {
                printf(" *Elemento: [%d, %d]", key, ptr->dato);
                encontrado = 1;
                break;
            }
            ptr = ptr->next;
        }

        if (encontrado == 0)
            printf("Elemento: [%d] No existe en la Tabla Hash.", elemento);
    }// else
    printf("\n");
} // search

void insert(t_pair h_table[], int size) {
    int elemento;
    int key;

    scanf("%d", &elemento);
    key = elemento%size;

    if (h_table[key].key == -1) {
        h_table[key].key  = key;
        h_table[key].dato = elemento;
    } else {
        t_pair* ptr_pair;
        ptr_pair = (t_pair*)malloc(sizeof(t_pair));
        ptr_pair->key = key;
        ptr_pair->dato = elemento;
        ptr_pair->next = h_table[key].next;
        h_table[key].next = ptr_pair;
    }
} // insert

void eliminar(t_pair h_table[], int size) {
    int key, elemento;
    t_pair *prev, *current;

    printf("Ingresar elemento que se desea eliminar: ");
    scanf("%d", &elemento);
    key = elemento % size;
    prev = &h_table[key];

    if (h_table[key].dato == elemento) {
        current = &h_table[key];
        printf("Elemento: <%d, %d> - encontrado!\n", key, current->dato);
    } else {
        int encontrado = 0;

        printf("Cabeza (%d, %d): ", key, h_table[key].dato);
        current = prev->next;

        while (current != 0) {
            printf("<%d, %d> ", key, current->dato);

            if (current->dato == elemento) {
                printf(" *Elemento: [%d, %d] - encontrado!\n", key, current->dato);
                encontrado = 1;
                break;
            }
            prev = current;
            current = current->next;
        }

        if (encontrado != 1) {
            printf("Imposible eliminar el elemento: [%d] ya que no existe en la Tabla Hash.\n", elemento);
            return;
        }
    }

    if (prev != current) {
        prev->next = current->next;
        free(current);
    } else {
        current = current->next;

        if (current != 0) {
            prev->key = current->key;
            prev->dato = current->dato;
            prev->next = current->next;
            free(current);
        } else {
            prev->key = prev->dato = -1;
            prev->next = 0;
        }
    }
    printf("El elemento: [%d] ha sido eliminado exitosamente! :)\n", elemento);
} // eliminar

void inicializarValoresHashTable(t_pair h_table[], int size) {
    for (int key = 0; key < size; ++key) {
        h_table[key].key   = -1;
        h_table[key].dato  = -1;
        h_table[key].next = 0;
    }
} // inicializarValoresHashTable

void ingresarElementos(t_pair h_table[], int size) {
    int elemento;

    printf("Ingrese los elementos: \n");

    for (int i = 0; i < size; ++i) {
        insert(h_table, size);
    }
    printf("-----------------------\n");
} // ingresarElementos

/* -----------------------------------   m e n u   ----------------------------------- */

int menu() {
    int opcion = 0;

    do {
        printf("Elija una opcion [1..5] \n\n");
        printf("1. Desplegar Tabla Hash. \n");
        printf("2. Insertar Elemento en Tabla Hash. \n");
        printf("3. Buscar Elementos en Tabla Hash. \n");
        printf("4. Eliminar Elemento en Tabla Hash. \n");
        printf("5. Salir del sistema \n");
        printf("> ");
        scanf("%d", &opcion);
        printf("\n");
        if (opcion >=1 && opcion <= 5)
            break;
        else
            printf("ERROR. Opcion no valida [%d] \n", opcion);
    } while (true);

    return opcion;
} // fin menu

/* --------------------------------------------------------------------------------------------------- //
                                CORRIDAS - Programa: HASH ABIERTO
------------------------------------------------------------------------------------------------------ // 

Ingresa el tamano de la tabla: 3

Ingrese los elementos:
3
8
10

Elija una opcion [1..5]> 1
**** Se activo la opcion #1: Desplegar Tabla Hash.

Key     Datos
0       3
1       10
2       8

Elija una opcion [1..5]> 2
**** Se activo la opcion #2: Insertar en Tabla Hash.

Ingresar elemento que se desea insertar: 4

Elija una opcion [1..5]> 2
**** Se activo la opcion #2: Insertar en Tabla Hash.

Ingresar elemento que se desea insertar: 7

Elija una opcion [1..5]> 1
**** Se activo la opcion #1: Desplegar Tabla Hash.

Key     Datos
0       3
1       10   
        7   4
2       8

Elija una opcion [1..5]> 4
**** Se activo la opcion #4: Eliminar en Tabla Hash.

Ingresar elemento que se desea eliminar: 7

Cabeza (1, 10): <1, 7>  *Elemento: [1, 7] - encontrado!
El elemento: [7] ha sido eliminado exitosamente! :)

Elija una opcion [1..5]> 1

**** Se activo la opcion #1: Desplegar Tabla Hash.

Key     Datos
0       3
1       10
        4
2       8

Elija una opcion [1..5]> 4

**** Se activo la opcion #4: Eliminar en Tabla Hash.

Ingresar elemento que se desea eliminar: 4

Cabeza (1, 10): <1, 4>  *Elemento: [1, 4] - encontrado!
El elemento: [4] ha sido eliminado exitosamente! :)

Elija una opcion [1..5]> 1

**** Se activo la opcion #1: Desplegar Tabla Hash.

Key     Datos
0       3
1       10
2       8

Elija una opcion [1..5]> 4

**** Se activo la opcion #4: Eliminar en Tabla Hash.

Ingresar elemento que se desea eliminar: 18

Cabeza (0, 3): Imposible eliminar el elemento: [18] ya que no existe en la Tabla Hash.

Elija una opcion [1..5]> 4

**** Se activo la opcion #4: Eliminar en Tabla Hash.

Ingresar elemento que se desea eliminar: 10

Elemento: <1, 10> - encontrado!
El elemento: [10] ha sido eliminado exitosamente! :)

Elija una opcion [1..5]> 1

**** Se activo la opcion #1: Desplegar Tabla Hash.

Key     Datos
0       3
-1      -1
2       8

Elija una opcion [1..5]> 5

Saliendo...

**** Programa finalizado ****

------------------------------------------------------------------------------------------------------ */