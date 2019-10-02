/**
 * The <code>Figure</code> is the class base abstract for all figure contexts
 * which allows to calculate its area and perimeter.
 * 
 * @author Michael Serrato - E-mail <a href="mailto:mikebsg01@gmail.com">mikebsg01@gmail.com</a>
 * @version 1.0.0
 */
public abstract class Figure {

  /* Main attributes of a figure. */
  private String name;
  private double area;
  private double perimeter;

  Figure() {
    this.setName("Figure");
  }

  /**
   * Sets the name of the figure.
   * 
   * @param name The name of the figure.
   * @return The current instance of the <code>Figure</code> class.
   */
  public Figure setName(String name) {
    this.name = name;
    return this;
  }

  /**
   * Gets the name of the figure.
   * 
   * @return The name of the figure.
   */
  public String getName() {
    return this.name;
  }

  /**
   * Calculates the area of the figure.
   * 
   * @return The current instance of the <code>Figure</code> class.
   */
  public abstract Figure calculateArea();

  /**
   * Calculates the perimeter of the figure.
   * 
   * @return The current instance of the <code>Figure</code> class.
   */
  public abstract Figure calculatePerimeter();

  /**
   * Gets the area of the figure.
   * 
   * @return The area of the figure.
   */
  public abstract double getArea();

  /**
   * Gets the perimeter of the figure.
   * 
   * @return The perimeter of the figure.
   */
  public abstract double getPerimeter();
}