import java.io.*;

class Input {

  private static BufferedReader buffer;

  Input() {
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
        System.out.println("\n\tPor favor, ingrese un valor numerico de tipo entero.\n");
      } catch (IOException ex) {
        System.out.println("\n\tError de lectura\n");
      } catch (Exception ex) {
        ex.printStackTrace();
      }
    } while (!isCorrectValue);
    return val;
  }

  public int readInt(String prompt) {
    int val = -1;
    boolean isCorrectValue = false;

    do {
      try {
        System.out.print(prompt);
        val = Integer.parseInt(buffer.readLine());
        isCorrectValue = true;
      } catch (NumberFormatException ex) {
        System.out.println("\n\tPor favor, ingrese un valor numerico de tipo entero.\n");
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

  public int readPosInt(String prompt) {
    int val = -1;
    boolean isCorrectValue = false;

    do {
      val = readInt(prompt);

      if (val > 0) {
        isCorrectValue = true;
      } else {
        System.out.println("\n\tPor favor, ingrese un entero positivo.\n");
      }
    } while (!isCorrectValue);
    return val;
  }

  public String readLine() {
    String str = null;
    boolean isCorrectValue = false;

    do {
      try {
        str = buffer.readLine();
        isCorrectValue = true;
      } catch (IOException ex) {
        System.out.println("\n\tError de lectura\n");
      } catch (Exception ex) {
        ex.printStackTrace();
      }
    } while (!isCorrectValue);
    return str;
  }

  public String readLine(String prompt) {
    String str = null;
    boolean isCorrectValue = false;

    do {
      try {
        System.out.print(prompt);
        str = buffer.readLine();
        isCorrectValue = true;
      } catch (IOException ex) {
        System.out.println("\n\tError de lectura\n");
      } catch (Exception ex) {
        ex.printStackTrace();
      }
    } while (!isCorrectValue);
    return str;
  }

  public String readLineNotEmpty() {
    String str = null;
    boolean isCorrectValue = false;

    do {
      str = readLine().trim();

      if (str.length() > 0) {
        isCorrectValue = true;
      } else {
        System.out.println("\n\tPor favor, ingrese el dato correspondiente, dicho dato no debe ser nulo o vacio.\n");
      }
    } while (!isCorrectValue);
    return str;
  }

  public String readLineNotEmpty(String prompt) {
    String str = null;
    boolean isCorrectValue = false;

    do {
      str = readLine(prompt).trim();

      if (str.length() > 0) {
        isCorrectValue = true;
      } else {
        System.out.println("\n\tPor favor, ingrese el dato correspondiente, dicho dato no debe ser nulo o vacio.\n");
      }
    } while (!isCorrectValue);
    return str;
  }
}
