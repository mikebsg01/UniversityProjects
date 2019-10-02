/** ---------------------------------------------------------------------------------------------------
 * Problema ACM: Street Numbers (Números de calle)
 *
 * @author Serrato Guerrero Michael Brandon - Expediente: 258849
 * @author Balderas Beltrán Alan - Expediente: 237020
 * @author Vargas Aguillón Jesús - Expediente: 258872
 */

 /* --------------------------------------------------------------------------------------------------
  ALGORITMO (VERSIÓN No.1 DE LA SOLUCIÓN) - COMPLEJIDAD O(N):
------------------------------------------------------------------------------------------------------

1.- Inicio
2.- Se obtiene el número de casas (N).
3.- Primero, mediante la "Suma de Gauss" {(N * (N + 1)) / 2} calcular la sumatoria de los
    números de todas las casas (totalSum), cuyo valor se utilizará posteriormente.
4.a- Iterar desde 1 hasta N (que es el número de casas):
    4.1- Para calcular la sumatoria de las casas a la izquierda de la casa actual se deberá calcular
        la suma de gauss de la casa actual menos uno (i - 1).
    4.2- El valor de la sumatoria de las casas a la derecha de la casa actual será
        la sumatoria total menos el valor de la casa actual y menos la sumatoria de las casas a
        la izquierda (previamente calculada) (totalSum - i - izq).
    4.3- Si la sumatoria de las casas a la izquierda es igual a la sumatoria de las casas a la derecha
        entonces retornar el valor de la casa actual ( return i if izq == der ).
4.b- Fin del ciclo
5.- En caso de no haber encontrado la posición que satisfaciera la
      igualdad en el paso 4.3, retornar entonces el valor -1.
6.- Imprimir el resultado
7.- Fin del programa

------------------------------------------------------------------------------------------------------
  COMPLEJIDAD DEL ALGORITMO "BIG-O":
------------------------------------------------------------------------------------------------------

  Debido a la única iteración (for) significativa en cuestión de tiempo cuya función es recorrer
  únicamente todos los elementos (de 1 a N) se concluye que la complejidad del algoritmo es O(n),
  es decir, de tipo LINEAL.

------------------------------------------------------------------------------------------------------
  CÓDIGO FUENTE:
------------------------------------------------------------------------------------------------------ */

#include <iostream>
typedef long long int lli;
using namespace std;

lli gaussSum(lli n);
lli calculate(int numOfHouses);

int  main() {
  int numOfHouses;

  cout << "Introducir numero de casas: ";
  cin >> numOfHouses;
  cout << "Casa central (resultado): " << calculate(numOfHouses) << endl;
  return 0;
}

lli gaussSum(lli n) {
  return (n * (n + 1)) / 2;
}

lli calculate(int numOfHouses) {
  if (numOfHouses == 1) { // Caso especial
    return -1;
  }

  int i;
  lli totalSum, izq, der;

  totalSum = gaussSum(numOfHouses);

  for (i = 1; i <= numOfHouses; ++i) {
    izq = gaussSum(i - 1);
    der = totalSum - i - izq;

    // cout << izq << " - " << der << endl;

    if (izq == der) {
      return i;
    }
  }

  return -1;
}

/* --------------------------------------------------------------------------------------------------
 ALGORITMO (VERSIÓN No.2 DE LA SOLUCIÓN CON BÚSQUEDA BINARIA) - COMPLEJIDAD O(log N):
------------------------------------------------------------------------------------------------------

1.- Inicio
2.- Se obtiene el número de casas (N).
3.- Primero, mediante la "Suma de Gauss" {(N * (N + 1)) / 2} calcular la sumatoria de los
    números de todas las casas (totalSum), cuyo valor se utilizará posteriormente.
4.- Obtener el número de la casa inicial (a)
5.- Obtener el número de la casa final (b)
6.a- Iterar mientras a < b:
      6.1.- Calcular la mitad del rango {m = (a + b)/2}
      6.2.- Para calcular la sumatoria de las casas a la izquierda de la casa actual se deberá
          calcular la suma de gauss de la casa actual menos uno (i - 1).
      6.3.- El valor de la sumatoria de las casas a la derecha de la casa actual será
          la sumatoria total menos el valor de la casa actual y menos la sumatoria de las casas a
          la izquierda (previamente calculada) (totalSum - i - izq).
      6.4.a.- Si la sumatoria de las casas a la izquierda es menor a la sumatoria de las casas a
          la derecha (if izq < der):
          6.4.a.1.- a = m + 1.
      6.4.b- Si no:
          6.4.b.1.- b = m.
      6.4.c Fin de la condición.
6.b Fin del ciclo
7.- Realizar los pasos 6.1, 6.2 y 6.3 nuevamente (esto con la finalidad de recalcular los valores
     de las sumatorias en base a los rangos A y B obtenidos como resultado de la búsqueda binaria).
8.- Si la sumatoria de las casas a la izquierda es igual a la sumatoria de las casas a la derecha
     entonces retornar la posición "m" (la mitad de los rangos finales obtenidos A y B)
     ( return m if izq == der ).
9.- En caso de no haber encontrado la posición que satisfaciera la
     igualdad en el paso 8, retornar entonces el valor -1.
10.- Imprimir el resultado
11.- Fin del programa

------------------------------------------------------------------------------------------------------
 COMPLEJIDAD DEL ALGORITMO "BIG-O":
------------------------------------------------------------------------------------------------------

 Basándonos en la complejidad ya conocida de la búsqueda binaria por ser un algoritmo logarítmico
 (debido a su función de buscar entre un rango de valores ordenados "partiendo en mitades") y siendo
 este el algoritmo implementado más significativo en cuestión de tiempo, se concluye que
 la complejidad del algorítmo es O(log n), es decir, de tipo LOGARÍTMICO, y por lo tanto
 este algoritmo es más rápido que el de la versión no.1 que es de tipo lineal.

------------------------------------------------------------------------------------------------------
 CÓDIGO FUENTE:
------------------------------------------------------------------------------------------------------ */

#include <iostream>
typedef long long int lli;
using namespace std;

lli gaussSum(lli n);
lli calculate(int numOfHouses);

int  main() {
  int numOfHouses;

  cout << "Introducir numero de casas: ";
  cin >> numOfHouses;
  cout << "Casa central (resultado): " << calculate(numOfHouses) << endl;
  return 0;
}

lli gaussSum(lli n) {
  return (n * (n + 1)) / 2;
}

lli calculate(int numOfHouses) {
  if (numOfHouses == 1) { // Caso especial
    return -1;
  }

  int a, b, m;
  lli totalSum, izq, der;

  totalSum = gaussSum(numOfHouses);

  a = 1;
  b = numOfHouses;
  while (a < b) {
    m = (a + b) / 2;
    izq = gaussSum(m - 1);
    der = totalSum - m - izq;

    // cout << izq << " - " << der << endl;

    if (izq < der) {
      a = m + 1;
    } else {
      b = m;
    }
  }

  m = (a + b) / 2;
  izq = gaussSum(m - 1);
  der = totalSum - m - izq;

  // cout << izq << " - " << der << endl;

  if (izq == der) {
    return m;
  }

  return -1;
}

/* ---------------------------------------------------------------------------------------------------
                                            FIN DEL ARCHIVO
------------------------------------------------------------------------------------------------------ */
