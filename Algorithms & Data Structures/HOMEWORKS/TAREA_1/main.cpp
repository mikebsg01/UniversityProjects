/**
 * Programa para generar un MEN� de opciones en CONSOLA y
 * calcular el �rea y perimtero de figuras geom�tricas.
 *
 * @author Serrato Guerrero Michael Brandon - Expediente: 258849
 * @author Balderas Beltr�n Alan
 * @author Vargas Aguill�n Jes�s
 */
#include <stdio.h>

/* Constantes */
#define PI 3.14159265359
#define OPCION_1 1
#define OPCION_2 2
#define OPCION_3 3
#define OPCION_SALIR 4

/* Prototipos de funciones */
void menu();
int obtener_opcion();
double obtener_valor();
void ejecutar(int opc);


/* Programa Principal */
int main(int argc, char** argv) {
	int opc;

    printf("\n========== Programa: Calculo de area y perimetro de figuras geometricas ==========\n\n");

	do {
		menu();
		opc = obtener_opcion();
		ejecutar(opc);
		printf("=================================================\n\n");
	} while(opc != OPCION_SALIR);

	return 0;
}

/* Implementaci�n de funciones */

void menu() {
	printf("1. Cuadrado\n");
	printf("2. Rectangulo\n");
	printf("3. Circulo\n");
	printf("4. Salir del sistema\n");
	printf("\n\t> Elegir opcion: ");
}


int obtener_opcion() {
	int opcion;

	scanf("%d", &opcion);
	return opcion;
}

double obtener_valor() {
    double valor;

    scanf("%lf", &valor);
    return valor;
}

void ejecutar(int opc) {
    printf("\n");

    switch(opc) {
        case OPCION_1:
            double lado;

            printf("\t***** Ha elegido la opcion #1 ***** \n\n"
                   "========== CASO 1: Figura \"Cuadrado\" ==========\n\n"
                   "Lado del cuadrado: ");
            lado = obtener_valor();
            printf("\nArea: %.2f\n"
                   "Perimetro: %.2f\n\n",
                   lado * lado,
                   4 * lado);
        break;
        case OPCION_2:
            double ladoA,
                   ladoB;

            printf("\t***** Ha elegido la opcion #2 ***** \n\n"
                   "========== CASO 2: Figura \"Rectangulo\" ==========\n\n"
                   "Lado A del rectangulo: ");
            ladoA = obtener_valor();
            printf("Lado B del rectangulo: ");
            ladoB = obtener_valor();
            printf("\nArea: %.2f\n"
                   "Perimetro: %.2f\n\n",
                   ladoA * ladoB,
                   2 * ladoA + 2 * ladoB);
        break;
        case OPCION_3:
            double radio;

            printf("\t***** Ha elegido la opcion #3 ***** \n\n"
                   "========== CASO 3: Figura \"Circulo\" ==========\n\n"
                   "Radio del Circulo: ");
            radio = obtener_valor();
            printf("\nArea: %.2f\n"
                   "Perimetro: %.2f\n\n",
                   PI * radio * radio,
                   PI * 2 * radio);
        break;
        case OPCION_SALIR:
            printf("\tSaliendo ... \n\n");
        break;
      default:
        printf("\tSELECCION incorrecta.\n\n");
        break;
   }
}
