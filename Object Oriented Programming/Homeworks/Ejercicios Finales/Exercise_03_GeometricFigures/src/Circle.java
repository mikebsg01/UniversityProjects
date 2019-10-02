/**
 * The <code>Circle</code> is a class that inherits from the abstract class 
 * <code>Figure</code>, so it provides the attributes and methods own of a 
 * circle.
 * 
 * @author Michael Serrato - E-mail <a href="mailto:mikebsg01@gmail.com">mikebsg01@gmail.com</a>
 * @version 1.0.0
 * @see Figure
 */
public class Circle extends Figure {

  /* Own attributes of a rectangle. */
  private double radio;
  private double area;
  private double perimeter;

  Circle() {
    this.setName("Circle");
  }

  /**
   * Sets the name of the circle.
   * <p><b>Important:</b> Calls the method <code>setName()</code> of the super class
   * <code>Figure</code> for its operation.
   * 
   * @param name The name of the circle.
   * @return The current instance of the <code>Circle</code> class.
   * @see Figure
   */
  public Circle setName(String name) {
    super.setName(name);
    return this;
  }

  /**
   * Sets the radio of the circle.
   * 
   * @param radio Radio of the circle.
   * @return The current instance of the <code>Circle</code> class.
   */
  public Circle setRadio(double radio) {
    this.radio = radio;
    return this;
  }

  /**
   * Calculates the area of the circle.
   * 
   * @return The current instance of the <code>Circle</code> class.
   */
  public Circle calculateArea() {
    this.area = Math.PI * this.radio * this.radio;
    return this;
  }

  /**
   * Calculates the perimeter of the circle.
   * 
   * @return The current instance of the <code>Circle</code> class.
   */
  public Circle calculatePerimeter() {
    this.perimeter = 2 * Math.PI * this.radio;
    return this;
  }

  /**
   * Gets the area of the circle.
   * 
   * @return The area of the circle.
   */
  public double getArea() {
    return this.area;
  }

  /**
   * Gets the perimeter of the circle.
   * 
   * @return The perimeter of the circle.
   */
  public double getPerimeter() {
    return this.perimeter;
  }
}