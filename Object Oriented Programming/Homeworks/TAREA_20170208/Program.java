import java.io.*;

class Program {
  private static int[] array;
  private static int index;
  public static BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));

  public static void main(String[] args) {
    array = new int[20];
    int opcion = 0, val;

    while (true) {
      System.out.print(" =========== MENU =========== \n"+
        "1.- Agregar\n"+
        "2.- Obtener Media\n"+
        "3.- Obtener Varianza\n"+
        "4.- Desviacion\n"+
        "5.- Salir\n"+
        "\n\tElegir opcion: ");

      opcion = getInputNumber();
      System.out.println();

      if (opcion == 1) {
        System.out.print("Agregar valor: ");
        val = getInputNumber();
        add(val);
      }
      else if (opcion == 2) {
        System.out.println("El valor de la media es: " + median() + "\n");
      }
      else if (opcion == 3) {
        System.out.println("El valor de la varianza es: " + variance() + "\n");
      }
      else if (opcion == 4) {
        System.out.println("El valor de la deviacion es: " + deviationStandard() + "\n");
      } 
      else if (opcion == 5) {
        break;
      } else {
        System.out.println("\n\tLa opcion es invalida.\n");
      }
    }
  }

  public static int getInputNumber() {
    int a = 0;
    try {
      a = Integer.parseInt(buffer.readLine());
    } catch (IOException ex) {
      System.out.println("\n\tError de lectura.\n\n");
    } catch (NumberFormatException ex) {
      System.out.println("\n\tSe espera un numero.\n\n");
    }
    return a;
  }

  public static void add(int val) {
    if (index < 20) {
      array[index++] = val;
    }
  }

  public static float median() {
    int i, accumulator = 0;

    if (index > 0) {
      for (i = 0; i < index; ++i) {
        accumulator += array[i];
      }
      return accumulator / index;
    }
    return 0;
  }

  public static float variance() {
    int i;
    float summation = 0, 
          deviation = 0,
          m = median();

    for (i = 0; i <= index; ++i) {
      deviation = array[i] - m;
      deviation = deviation * deviation;
      summation = summation + deviation;
    }
    return summation / (index - 1);
  }

  public static double deviationStandard() {
    return Math.sqrt(variance());
  }
}