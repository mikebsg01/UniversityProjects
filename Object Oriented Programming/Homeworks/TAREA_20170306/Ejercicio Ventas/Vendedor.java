import java.io.*;
import java.text.NumberFormat;

public class Vendedor {

  // Variables requeridas para su uso en la interfaz
  private static BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
  private static String[] months = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", 
                                     "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
  public static NumberFormat formatCurrency = NumberFormat.getCurrencyInstance();

  // Atributos de la clase
  private String name;
  private Venta[] ventas = new Venta[12];
  private double total = 0.00;

  public void requestName() {
    String a = null;

    do {
      System.out.print("\nIntroduzca el nombre del vendedor: ");
      try {
        a = buffer.readLine();
      } catch (IOException ex) {
        System.out.println("\n\tError en la lectura\n");
      } catch (Exception ex) {
        ex.printStackTrace();
      }
    } while (a == null || a.isEmpty());
    this.name = a;
  }

  public void requestSales() {
    int i;
    String name;
    double val = 0.0;

    for (i = 0; i < 12; ++i) {
      System.out.print("\n\t Mes de " + months[i] + "\n");

      name = this.getNameOfTheSale();
      val = this.getValueOfTheSale();
      this.ventas[i] = new Venta(name, val);
      this.total += val;
    }
  }

  public void showAllSales() {
    int i;

    System.out.println("\n======================================================================");
    System.out.println("\n\t\tVendedor: " + this.name + "\n");
    
    for (i = 0; i < 12; ++i) {
      System.out.println("\tVenta del mes de " + months[i] + ": \t" + this.ventas[i].getName() + "\n" +
                       "\tValor de la venta: \t\t" + formatCurrency.format(this.ventas[i].getValue()) + "\n");
    }

    System.out.println("\tMonto Total de las Ventas: \t" + formatCurrency.format(this.total) + "\n");
    System.out.println("=====================================================================");
  }

  private String getNameOfTheSale() {
    String name = null;

    do {
      System.out.print("Nombre de la venta: ");

      try {
        name = buffer.readLine();
      } catch (IOException ex) {
        System.out.println("\n\tError en la lectura\n");
      } catch (Exception ex) {
          ex.printStackTrace();
      }
    } while (name == null || name.isEmpty());
    return name;
  }

  private double getValueOfTheSale() {
    double val = -1.0;

    do {
      System.out.print("Valor de la venta ($): ");

      try {
        val = Double.parseDouble(buffer.readLine());
      } catch (IOException ex) {
        System.out.println("\n\tError en la lectura\n");
      } catch (NumberFormatException ex) {
        System.out.println("\n\tPor favor, introduzca un valor de tipo numerico.\n");
      } catch (Exception ex) {
        ex.printStackTrace();
      }

      if (val < 0 && val != -1.0) {
        System.out.println("\n\tEl valor de la venta debe ser mayor o igual a cero.\n");
        val = -1.0;
      }
    } while (val < 0);
    return val;
  }

  public double getTotal() {
    return this.total;
  }
}