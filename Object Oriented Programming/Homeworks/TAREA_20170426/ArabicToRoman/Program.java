import java.io.*;

class Program {

  private static BufferedReader buffer;

  public static void main(String[] arg) {
    int arabicNum;

    buffer = new BufferedReader(new InputStreamReader(System.in));
    System.out.println("\n\t\tPROGRAMA: Numero Arabigo a Romano\n");
    arabicNum = readArabicNumber();
    ArabicNumber arabicNumber = new ArabicNumber(arabicNum);
    System.out.println("\nEl numero en romano es: " + arabicNumber.getInRoman());
  }

  private static int readArabicNumber() {
    int val = -1;
    boolean isCorrectValue = false;

    do {
      try {
        do {
          System.out.print("Introduzca el numero arabigo: ");
          val = Integer.parseInt(buffer.readLine());

          if (val < 1 || val > 3999) {
            System.out.println("\n\tPor favor, introduzca un numero cuyo rango se encuentre entre 1 y 3999.\n");
          }
        } while (val < 1 || val > 3999);

        isCorrectValue = true;
        
      } catch (NumberFormatException ex) {
          System.out.println("\n\tPor favor, introduzca un valor de tipo numerico.\n");
      } catch (IOException ex) {
        System.out.println("\n\tError de lectura\n");
      } catch (Exception ex) {
        ex.printStackTrace();
      }
    } while (!isCorrectValue);
    return val;
  }
}