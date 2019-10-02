/**
 * The <code>Square</code> is a class that inherits from the abstract class 
 * <code>Figure</code>, so it provides the attributes and methods own of a 
 * square.
 * 
 * @author Michael Serrato - E-mail <a href="mailto:mikebsg01@gmail.com">mikebsg01@gmail.com</a>
 * @version 1.0.0
 * @see Figure
 */
public class Square extends Figure {

  /* Own attributes of a square. */
  private double side;
  private double area;
  private double perimeter;

  Square() {
    this.setName("Square");
  }

  /**
   * Sets the name of the square.
   * <p><b>Important:</b> Calls the method <code>setName()</code> of the super class
   * <code>Figure</code> for its operation.
   * 
   * @param name The name of the square.
   * @return The current instance of the <code>Square</code> class.
   * @see Figure
   */
  public Square setName(String name) {
    super.setName(name);
    return this;
  }

  /**
   * Sets the side value of the square.
   * 
   * @param side The <b>side</b> value of the square.
   * @return The current instance of the <code>Square</code> class.
   */
  public Square setSide(double side) {
    this.side = side;
    return this;
  }

  /**
   * Calculates the area of the square.
   * 
   * @return The current instance of the <code>Square</code> class.
   */
  public Square calculateArea() {
    this.area = this.side * this.side;
    return this;
  }

  /**
   * Calculates the perimeter of the square.
   * 
   * @return The current instance of the <code>Square</code> class.
   */
  public Square calculatePerimeter() {
    this.perimeter = 4 * this.side;
    return this;
  }

  /**
   * Gets the area of the square.
   * 
   * @return The area of the square.
   */
  public double getArea() {
    return this.area;
  }

  /**
   * Gets the perimeter of the square.
   * 
   * @return The perimeter of the square.
   */
  public double getPerimeter() {
    return this.perimeter;
  }
}