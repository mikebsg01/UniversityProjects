/**
 * The <code>Rectangle</code> is a class that inherits from the abstract class 
 * <code>Figure</code>, so it provides the attributes and methods own of a 
 * rectangle.
 * 
 * @author Michael Serrato - E-mail <a href="mailto:mikebsg01@gmail.com">mikebsg01@gmail.com</a>
 * @version 1.0.0
 * @see Figure
 */
public class Rectangle extends Figure {

  /* Own attributes of a rectangle. */
  private double base;
  private double height;
  private double area;
  private double perimeter;

  Rectangle() {
    this.setName("Rectangle");
  }

  /**
   * Sets the name of the rectangle.
   * <p><b>Important:</b> Calls the method <code>setName()</code> of the super class
   * <code>Figure</code> for its operation.
   * 
   * @param name The name of the rectangle.
   * @return The current instance of the <code>Rectangle</code> class.
   * @see Figure
   */
  public Rectangle setName(String name) {
    super.setName(name);
    return this;
  }

  /**
   * Sets the base of the rectangle.
   * 
   * @param base Base of the rectangle.
   * @return The current instance of the <code>Rectangle</code> class.
   */
  public Rectangle setBase(double base) {
    this.base = base;
    return this;
  }

  /**
   * Sets the height of the rectangle.
   * 
   * @param height Height of the rectangle.
   * @return The current instance of the <code>Rectangle</code> class.
   */
  public Rectangle setHeight(double height) {
    this.height = height;
    return this;
  }

  /**
   * Calculates the area of the rectangle.
   * 
   * @return The current instance of the <code>Rectangle</code> class.
   */
  public Rectangle calculateArea() {
    this.area = this.base * this.height;
    return this;
  }

  /**
   * Calculates the perimeter of the rectangle.
   * 
   * @return The current instance of the <code>Rectangle</code> class.
   */
  public Rectangle calculatePerimeter() {
    this.perimeter = 2 * this.base + 2 * this.height;
    return this;
  }

  /**
   * Gets the area of the rectangle.
   * 
   * @return The area of the rectangle.
   */
  public double getArea() {
    return this.area;
  }

  /**
   * Gets the perimeter of the rectangle.
   * 
   * @return The perimeter of the rectangle.
   */
  public double getPerimeter() {
    return this.perimeter;
  }
}