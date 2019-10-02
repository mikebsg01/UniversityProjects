import java.io.*;

class Console {

  private static BufferedReader buffer;

  Console() {
    buffer = new BufferedReader(new InputStreamReader(System.in));
  }

  public int readInt() {
    int val = -1;
    boolean isCorrectValue = false;

    do {
      try {
        val = Integer.parseInt(buffer.readLine());
        isCorrectValue = true;
      } catch (NumberFormatException ex) {
        System.out.println("\n\tPor favor, ingrese un valor de tipo numerico.\n");
      } catch (IOException ex) {
        System.out.println("\n\tError de lectura\n");
      } catch (Exception ex) {
        ex.printStackTrace();
      }
    } while (!isCorrectValue);
    return val;
  }

  public int readPosInt() {
    int val = -1;
    boolean isCorrectValue = false;

    do {
      val = readInt();

      if (val > 0) {
        isCorrectValue = true;
      } else {
        System.out.println("\n\tPor favor, ingrese un entero positivo.\n");
      }
    } while (!isCorrectValue);
    return val;
  }
}
