public class Venta {
  private String name;
  private double value;

  public Venta(String name, double value) {
    this.name = name;
    this.value = value;
  }

  public String getName() {
    return this.name;
  }

  public double getValue() {
    return this.value;
  }
}