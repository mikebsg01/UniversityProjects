/**
 * The <code>Triangle</code> is a class that inherits from the abstract class 
 * <code>Figure</code>, so it provides the attributes and methods own of a 
 * triangle.
 * 
 * @author Michael Serrato - E-mail <a href="mailto:mikebsg01@gmail.com">mikebsg01@gmail.com</a>
 * @version 1.0.0
 * @see Figure
 */
public class Triangle extends Figure {

  /* Own attributes of a triangle. */
  private double base;
  private double height;
  private double sideA;
  private double sideB;
  private double sideC;
  private double area;
  private double perimeter;

  Triangle() {
    this.setName("Triangle");
  }

  /**
   * Sets the name of the triangle.
   * <p><b>Important:</b> Calls the method <code>setName()</code> of the super class
   * <code>Figure</code> for its operation.
   * 
   * @param name The name of the triangle.
   * @return The current instance of the <code>Triangle</code> class.
   * @see Figure
   */
  public Triangle setName(String name) {
    super.setName(name);
    return this;
  }

  /**
   * Sets the base of the triangle.
   * 
   * @param base Base of the triangle.
   * @return The current instance of the <code>Triangle</code> class.
   */
  public Triangle setBase(double base) {
    this.base = base;
    return this;
  }

  /**
   * Sets the height of the triangle.
   * 
   * @param height Height of the triangle.
   * @return The current instance of the <code>Triangle</code> class.
   */
  public Triangle setHeight(double height) {
    this.height = height;
    return this;
  }

  /**
   * Sets the side <b>A</b> of the triangle.
   * 
   * @param sideA Side <b>A</b> of the triangle.
   * @return The current instance of the <code>Triangle</code> class.
   */
  public Triangle setSideA(double sideA) {
    this.sideA = sideA;
    return this;
  }

  /**
   * Sets the side <b>B</b> of the triangle.
   * 
   * @param sideB Side <b>B</b> of the triangle.
   * @return The current instance of the <code>Triangle</code> class.
   */
  public Triangle setSideB(double sideB) {
    this.sideB = sideB;
    return this;
  }

  /**
   * Sets the side <b>C</b> of the triangle.
   * 
   * @param sideC Side <b>C</b> of the triangle.
   * @return The current instance of the <code>Triangle</code> class.
   */
  public Triangle setSideC(double sideC) {
    this.sideC = sideC;
    return this;
  }

  /**
   * Calculates the area of the triangle.
   * 
   * @return The current instance of the <code>Triangle</code> class.
   */
  public Triangle calculateArea() {
    this.area = (base * height) / 2;
    return this;
  }

  /**
   * Calculates the perimeter of the triangle.
   * 
   * @return The current instance of the <code>Triangle</code> class.
   */
  public Triangle calculatePerimeter() {
    this.perimeter = this.sideA + this.sideB + this.sideC;
    return this;
  }

  /**
   * Gets the area of the triangle.
   * 
   * @return The area of the triangle.
   */
  public double getArea() {
    return this.area;
  }

  /**
   * Gets the perimeter of the triangle.
   * 
   * @return The perimeter of the triangle.
   */
  public double getPerimeter() {
    return this.perimeter;
  }
}