import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class Input {

  /**
   * Input Class
   * @author Michael Serrato - mikebsg01@gmail.com
   */

  // Class Attributes
  private BufferedReader buffer;

  // Constructor
  Input() {
    buffer = new BufferedReader(new InputStreamReader(System.in));
  }

  // Methods
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
        System.out.println("\n\tError de lectura.\n");
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
        val = Integer.parseInt(buffer.readLine().trim());
        isCorrectValue = true;
      } catch (NumberFormatException ex) {
        System.out.println("\n\tPor favor, ingrese un valor numerico de tipo entero.\n");
      } catch (IOException ex) {
        System.out.println("\n\tError de lectura.\n");
      } catch (Exception ex) {
        ex.printStackTrace();
      }
    } while (!isCorrectValue);
    return val;
  }

  public int readPositiveInt() {
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

  public int readPositiveInt(String prompt) {
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

  public int readNotNegativeInt() {
    int val = -1;
    boolean isCorrectValue = false;

    do {
      val = readInt();

      if (val >= 0) {
        isCorrectValue = true;
      } else {
        System.out.println("\n\tPor favor, ingrese un entero no negativo.\n");
      }
    } while (!isCorrectValue);
    return val;
  }

  public int readNotNegativeInt(String prompt) {
    int val = -1;
    boolean isCorrectValue = false;

    do {
      val = readInt(prompt);

      if (val >= 0) {
        isCorrectValue = true;
      } else {
        System.out.println("\n\tPor favor, ingrese un entero no negativo.\n");
      }
    } while (!isCorrectValue);
    return val;
  }

  public int readIntInRange(int begin, int end) {
    if (begin > end) {
      throw new InputException("El rango establecido es invalido.");
    }

    int val = -1;
    boolean isCorrectValue = false;

    do {
      val = readInt();

      if (val >= begin && val <= end) {
        isCorrectValue = true;
      } else {
        System.out.println("\n\tPor favor, ingrese un numero entero en el rango de " + begin + " a " + end + ".\n");
      }
    } while (!isCorrectValue);
    return val;
  }

  public int readIntInRange(String prompt, int begin, int end) {
    if (begin > end) {
      throw new InputException("El rango establecido es invalido.");
    }

    int val = -1;
    boolean isCorrectValue = false;

    do {
      val = readInt(prompt);

      if (val >= begin && val <= end) {
        isCorrectValue = true;
      } else {
        System.out.println("\n\tPor favor, ingrese un numero entero en el rango de " + begin + " a " + end + ".\n");
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
        System.out.println("\n\tError de lectura.\n");
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
        System.out.println("\n\tError de lectura.\n");
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

  public char readYesOrNot() {
    char c = '\0';
    String tmpStr;
    boolean isCorrectValue = false;

    do {
      System.out.print("Desea continuar? (y/n): ");
      tmpStr = readLine().trim();
      
      if (tmpStr.length() == 1) {
        c = tmpStr.charAt(0);

        if (c == 'y' || c == 'n') {
          isCorrectValue = true;
        }
      }
    } while (!isCorrectValue);
    return c;
  }

  public char readYesOrNot(String prompt) {
    char c = '\0';
    String tmpStr;
    boolean isCorrectValue = false;

    do {
      System.out.print(prompt);
      tmpStr = readLine().trim();
      
      if (tmpStr.length() == 1) {
        c = tmpStr.charAt(0);

        if (c == 'y' || c == 'n') {
          isCorrectValue = true;
        }
      }
    } while (!isCorrectValue);
    return c;
  }
}

class InputException extends RuntimeException {

  private String msg;

  InputException() {
    msg = "Input Declaration Exception";
  }

  InputException(String msg) {
    this.msg = msg;
  }

  public String getMessage() {
    return msg;
  }
}