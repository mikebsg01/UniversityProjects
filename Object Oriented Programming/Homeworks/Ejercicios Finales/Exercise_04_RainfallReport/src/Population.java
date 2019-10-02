/**
 * The <code>Population</code> class contains the name and rainfall data 
 * of a given population.
 * 
 * @author Michael Serrato - E-mail <a href="mailto:mikebsg01@gmail.com">mikebsg01@gmail.com</a>
 * @version 1.0.0
 */
public class Population {

  private String name;
  private double rainfall;

  Population(String name, double rainfall) {
    this.setName(name).setRainfall(rainfall);
  }

  public Population setName(String name) {
    this.name = name;
    return this;
  }

  public String getName() {
    return this.name;
  }

  public Population setRainfall(double rainfall) {
    this.rainfall = rainfall;
    return this;
  }

  public double getRainfall() {
    return this.rainfall;
  }
}