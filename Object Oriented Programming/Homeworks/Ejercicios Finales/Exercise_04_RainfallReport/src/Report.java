import java.util.List;
import java.util.ArrayList;

/**
 * The <code>Report</code> class allows to generate the rainfall report
 * from a population list.
 * 
 * @author Michael Serrato - E-mail <a href="mailto:mikebsg01@gmail.com">mikebsg01@gmail.com</a>
 * @version 1.0.0
 * @see java.util.List
 * @see java.util.ArrayList
 * @see Population
 */
public class Report {

  private List<Population> populationList = new ArrayList<>();

  public Report addPopulationToList(Population population) {
    populationList.add(population);
    return this;
  }

  public String toString() {
    String report = "";
    int numberOfPopulationsNoRain = 0;
    double rainfall,
           sumRainfall = 0;

    report += "\tREPORTE DE LLUVIAS\n\n";

    for (Population tmpPopulation : this.populationList) {
      rainfall = tmpPopulation.getRainfall();

      report += "Poblacion: " + tmpPopulation.getName() + "\n" +
                "Lluvia: " + rainfall + " mm2\n\n";
      sumRainfall += rainfall;

      if (rainfall == 0) {
        ++numberOfPopulationsNoRain;
      }
    }

    report += "\n\tTotal de poblaciones: " + this.populationList.size() + "\n" +
              "\n\tTotal de lluvia: " + sumRainfall + " mm2\n" +
              "\n\tTotal de poblaciones donde no llovio: " + numberOfPopulationsNoRain + "\n";

    return report;
  }
}