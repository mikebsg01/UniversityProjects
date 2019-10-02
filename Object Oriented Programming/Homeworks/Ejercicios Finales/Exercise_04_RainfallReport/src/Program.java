/**
 * Program to generate rainfall reports.
 * 
 * @author Michael Serrato - E-mail <a href="mailto:mikebsg01@gmail.com">mikebsg01@gmail.com</a>
 * @version 1.0.0
 * @see Input
 * @see Population
 * @see Report
 */
public class Program {

  private Input input = new Input();
  private Report report = new Report();

  Program() {
    this.printTitle().askForData().showRainfallReport();
  }

  public Program printTitle() {
    System.out.println("\n\tPrograma: Reporte de Lluvias\n");
    return this;
  }

  public Program askForData() {
    Population tmpPopulation;
    String name;
    double rainfall;
    char option;

    do {
      name = input.readLine("Introduzca el nombre de la poblacion: ");
      rainfall = input.readDouble("Introduzca la cantidad de lluvia (mm2): ");
      tmpPopulation = new Population(name, rainfall);
      this.report.addPopulationToList(tmpPopulation);
      System.out.println("\n\tPoblacion agregada exitosamente!\n");
      option = input.readYesOrNot("Desea agregar mas datos al reporte? (y/n): ");
      System.out.println();
    } while (option == 'y');
    return this;
  }

  public Program showRainfallReport() {
    System.out.println(this.report.toString());
    return this;
  }

  public static void main(String[] args) {
    new Program();
  }
}