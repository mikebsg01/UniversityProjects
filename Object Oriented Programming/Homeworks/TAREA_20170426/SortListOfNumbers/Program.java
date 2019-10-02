import java.util.Arrays;

class Program {

  private static Console console;

  public static void main(String[] arg) {
    console = new Console();
    int[] array;
    int n, i;

    System.out.println("\n\t\tPROGRAMA: Ordenar Lista de Numeros\n");
    System.out.print("Ingrese la cantidad de numeros a ordenar (N): ");
    n = console.readPosInt();
    array = new int[n];

    System.out.println("Ingrese la lista de numeros (separados por la tecla <<Enter>>):");

    for (i = 0; i < n; ++i) {
      array[i] = console.readInt();
    }

    System.out.println("Lista de numeros ordenada en forma ascendente:");
    Arrays.sort(array);

    for (i = 0; i < n; ++i) {
      if (i > 0) {
        System.out.print(" " + array[i]);
      } else {
        System.out.print(array[i]);
      }
    }

    System.out.println("\n");
    System.out.println("Lista de numeros ordenada en forma descendente:");

    for (i = n-1; i >= 0; --i) {
      if (i != (n-1)) {
        System.out.print(" " + array[i]);
      } else {
        System.out.print(array[i]);
      }
    }

    System.out.println();
  }
}
