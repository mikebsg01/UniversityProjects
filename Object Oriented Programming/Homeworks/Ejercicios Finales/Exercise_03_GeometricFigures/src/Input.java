import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

/**
 * The <code>Input</code> class <b>extends the standard input the java</b> 
 * to get precise data and correct formats.
 * 
 * @author Michael Serrato - E-mail <a href="mailto:mikebsg01@gmail.com">mikebsg01@gmail.com</a>
 * @version 1.0.0
 * @see java.io.BufferedReader
 * @see java.io.InputStreamReader
 * @see java.io.IOException
 */
public class Input {

  /* Attributes */
  private BufferedReader buffer;

  /**
   * Initializes the input stream.
   */
  Input() {
    buffer = new BufferedReader(new InputStreamReader(System.in));
  }

  /**
   * Reads an <code>integer</code> value.
   * <p>Any other type of value will be rejected and
   * will be prompted for an integer value again.
   * 
   * @return an integer value obtained from the input.
   */
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

  /**
   * It's the same method that <code>readInt()</code> only with a 
   * <code>prompt</code> message to describe the input.
   *
   * @param prompt a prompt message <code>string</code>.
   * @return an integer value obtained from the input.
   */
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

  /**
   * Reads a positive <code>integer</code> value.
   * <p>Any other type of value, negative integer <b>or 
   * even zero</b> will be rejected and will be prompted for a 
   * positive integer value again.
   * <p><b>Important:</b> This method implements the <code>readInt</code>
   * method of the class for its operation.
   * 
   * @return a positive integer value obtained from the input.
   * @see Input#readInt()
   */
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

  /**
   * It's the same method that <code>readPositiveInt()</code> only with a 
   * <code>prompt</code> message to describe the input.
   *
   * @param prompt a prompt message <code>string</code>.
   * @return a positive integer value obtained from the input.
   */
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

  /**
   * Reads a negative <code>integer</code> value.
   * <p>Any other type of value, positive integer <b>or 
   * even zero</b> will be rejected and will be prompted for a 
   * negative integer value again.
   * <p><b>Important:</b> This method implements the <code>readInt</code>
   * method of the class for its operation.
   * 
   * @return a negative integer value obtained from the input.
   * @see Input#readInt()
   */
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

  /**
   * It's the same method that <code>readNotNegativeInt()</code> only with a 
   * <code>prompt</code> message to describe the input.
   *
   * @param prompt a prompt message <code>string</code>.
   * @return a negative integer value obtained from the input.
   */
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

  /**
   * Reads an <code>integer</code> value in a range from <b>A</b> (<code>start</code>)
   * to <b>B</b> (<code>end</code>).
   * <p><b>Important:</b> This method implements the <code>readInt</code>
   * method of the class for its operation.
   * 
   * @param start The <code>start</code> integer - <b>A</b>
   * @param end The <code>end</code> integer - <b>B</b>
   * @return an <code>integer</code> value in the specified range.
   * @throws IllegalArgumentException If the established range is invalid.
   *         <p><b>For example:</b></p>
   *         <pre>
   *           readIntInRange(3, 2)
   *         </pre>
   *         <p>Where the <code>start</code> parameter is greater than 
   *         the <code>end</code> parameter.</p>
   * @see Input#readInt()
   */
  public int readIntInRange(int start, int end) {
    if (start > end) {
      throw new IllegalArgumentException("El rango establecido es invalido. El entero de inicio debe ser menor o igual al entero final.");
    }

    int val = -1;
    boolean isCorrectValue = false;

    do {
      val = readInt();

      if (val >= start && val <= end) {
        isCorrectValue = true;
      } else {
        System.out.println("\n\tPor favor, ingrese un numero entero en el rango de " + start + " a " + end + ".\n");
      }
    } while (!isCorrectValue);
    return val;
  }

  /**
   * It's the same method that <code>readIntInRange()</code> only with a 
   * <code>prompt</code> message to describe the input.
   *
   * @param prompt a prompt message <code>string</code>.
   * @param start The <code>start</code> integer - <b>A</b>
   * @param end The <code>end</code> integer - <b>B</b>
   * @return an <code>integer</code> value in the specified range.
   * @throws IllegalArgumentException If the established range is invalid.
   */
  public int readIntInRange(String prompt, int start, int end) {
    if (start > end) {
      throw new IllegalArgumentException("El rango establecido es invalido. El entero de inicio debe ser menor o igual al entero final.");
    }

    int val = -1;
    boolean isCorrectValue = false;

    do {
      val = readInt(prompt);

      if (val >= start && val <= end) {
        isCorrectValue = true;
      } else {
        System.out.println("\n\tPor favor, ingrese un numero entero en el rango de " + start + " a " + end + ".\n");
      }
    } while (!isCorrectValue);
    return val;
  }

  /**
   * Reads an <code>double</code> value.
   * <p>Any other type of value will be rejected and
   * will be prompted for an double value again.
   * 
   * @return an double value obtained from the input.
   */
  public double readDouble() {
    double val = -1;
    boolean isCorrectValue = false;

    do {
      try {
        val = Double.parseDouble(buffer.readLine());
        isCorrectValue = true;
      } catch (NumberFormatException ex) {
        System.out.println("\n\tPor favor, ingrese un valor numerico (puede ser decimal).\n");
      } catch (IOException ex) {
        System.out.println("\n\tError de lectura.\n");
      } catch (Exception ex) {
        ex.printStackTrace();
      }
    } while (!isCorrectValue);
    return val;
  }

  /**
   * It's the same method that <code>readDouble()</code> only with a 
   * <code>prompt</code> message to describe the input.
   *
   * @param prompt a prompt message <code>string</code>.
   * @return an double value obtained from the input.
   */
  public double readDouble(String prompt) {
    double val = -1;
    boolean isCorrectValue = false;

    do {
      try {
        System.out.print(prompt);
        val = Double.parseDouble(buffer.readLine().trim());
        isCorrectValue = true;
      } catch (NumberFormatException ex) {
        System.out.println("\n\tPor favor, ingrese un valor numerico (puede ser decimal).\n");
      } catch (IOException ex) {
        System.out.println("\n\tError de lectura.\n");
      } catch (Exception ex) {
        ex.printStackTrace();
      }
    } while (!isCorrectValue);
    return val;
  }

  /**
   * Reads a line of text.
   * 
   * @return a string of the line of text obtained from the input.
   */
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

  /**
   * It's the same method that <code>readLine()</code> only with a 
   * <code>prompt</code> message to describe the input.
   *
   * @param prompt a prompt message <code>string</code>.
   * @return a string of the line of text obtained from the input.
   */
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

  /**
   * Reads a line of non-empty text.
   * <p>An empty text string or only with spaces will be rejected and
   * will be prompted for a line of text again.</p>
   * <p><b>Important:</b> This method implements the <code>readLine</code>
   * method of the class for its operation.
   * 
   * @return a string of the non-empty line of text obtained from the input.
   * @see Input#readLine()
   */
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

  /**
   * It's the same method that <code>readLineNotEmpty()</code> only with a 
   * <code>prompt</code> message to describe the input.
   *
   * @param prompt a prompt message <code>string</code>.
   * @return a string of the non-empty line of text obtained from the input.
   */
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

  /**
   * Reads a <b>y</b> or <b>n</b> character (according to the case) for a
   * closed question.
   * <p>Any value other than <b>y</b> or <b>n</b> will be rejected and
   * will be prompted again.</p>
   * <p><b>Important:</b> This method implements the <code>readLine</code>
   * method of the class for its operation.
   * 
   * @return a <b>y</b> or <b>n</b> character (according to the selected option).
   * @see Input#readLine()
   */
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

  /**
   * It's the same method that <code>readYesOrNot()</code> only with a 
   * <code>prompt</code> message to describe the input.
   *
   * @param prompt a prompt message <code>string</code>.
   * @return a <b>y</b> or <b>n</b> character (according to the selected option).
   */
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