/**
 * Program to calculate the <b>area</b> and <b>perimeter</b> of 
 * <b>Geometric Figures</b>.
 * 
 * @author Michael Serrato - E-mail <a href="mailto:mikebsg01@gmail.com">mikebsg01@gmail.com</a>
 * @version 1.0.0
 * @see Input
 * @see Figure
 * @see Triangle
 * @see Square
 * @see Rectangle
 * @see Circle
 */
public class Program {

  /* Standard input extended */
  private Input input = new Input();

  /**
   * Starts the program.
   */
  Program() {
    this.mainMenu().pause();
  }

  /**
   * Main method.
   * 
   * @param args not used
   */
  public static void main(String[] args) {
    new Program();
  }

  /**
   * Program title.
   * 
   * @return The program title.
   */
  public String title(){
    return "\n\tPrograma: Figuras Geometricas\n\n";
  }

  /**
   * Display the list of possible operations to perform.
   *
   * @return The current instance of the <code>Program</code> class.
   */
  public Program mainMenu() {
    boolean backToMenu = true;
    byte option;

    do {
      option = (byte) input.readIntInRange("" +
        this.title() +
        "==================== MENU ====================\n" +
        "1.- Triangulo\n" +
        "2.- Cuadrado\n" +
        "3.- Rectangulo\n" +
        "4.- Circulo\n" +
        "5.- Fin\n" +
        "==============================================\n"+
        "\n\tElegir opcion: ", 1, 5);

      switch (option) {
        case 1:
          this.triangleView();
          break;
        case 2:
          this.squareView();
          break;
        case 3:
          this.rectangleView();
          break;
        case 4:
          this.circleView();
          break;
        case 5:
          backToMenu = false;
          break;
        default:
          break;
      }
    } while (backToMenu);
    return this;
  }

  /**
   * Pause the current program.
   *
   * @return The current instance of the <code>Program</code> class.
   */
  public Program pause() {
    Input tmpInput = new Input();

    System.out.print("\n\tPresione la tecla <ENTER> para continuar . . .");
    tmpInput.readLine();
    System.out.println();
    return this;
  }

  /**
   * View designed to introduce the data of a <code>Triangle</code> and
   * display its results.
   *
   * @return The current instance of the <code>Program</code> class.
   * @see  Triangle
   */
  public Program triangleView() {
    Triangle triangle = new Triangle();
    String name;
    double base,
           height,
           sideA,
           sideB,
           sideC;

    System.out.println("\n> CALCULAR AREA Y PERIMETRO DE UN TRIANGULO\n");
    name = input.readLine("Introduzca el nombre de la figura: ");
    base = input.readDouble("Introduzca el valor de la base: ");
    height = input.readDouble("Introduzca el valor de la altura: ");
    sideA = input.readDouble("Introduzca el valor del lado A: ");
    sideB = input.readDouble("Introduzca el valor del lado B: ");
    sideC = input.readDouble("Introduzca el valor del lado C: ");

    triangle
      .setName(name)
      .setBase(base)
      .setHeight(height)
      .setSideA(sideA)
      .setSideB(sideB)
      .setSideC(sideC)
      .calculateArea()
      .calculatePerimeter();

    return this.showResults(triangle);
  }

  /**
   * View designed to introduce the data of a <code>Square</code> and
   * display its results.
   *
   * @return The current instance of the <code>Program</code> class.
   * @see Square
   */
  public Program squareView() {
    Square square = new Square();
    String name;
    double side;

    System.out.println("\n> CALCULAR AREA Y PERIMETRO DE UN CUADRADO\n");
    name = input.readLine("Introduzca el nombre de la figura: ");
    side = input.readDouble("Introduzca el valor del lado: ");

    square
      .setName(name)
      .setSide(side)
      .calculateArea()
      .calculatePerimeter();

    return this.showResults(square);
  }

  /**
   * View designed to introduce the data of a <code>Rectangle</code> and
   * display its results.
   *
   * @return The current instance of the <code>Program</code> class.
   * @see Rectangle
   */
  public Program rectangleView() {
    Rectangle rectangle = new Rectangle();
    String name;
    double base,
           height;

    System.out.println("\n> CALCULAR AREA Y PERIMETRO DE UN RECTANGULO\n");
    name = input.readLine("Introduzca el nombre de la figura: ");
    base = input.readDouble("Introduzca el valor de la base: ");
    height = input.readDouble("Introduzca el valor de la altura: ");

    rectangle
      .setName(name)
      .setBase(base)
      .setHeight(height)
      .calculateArea()
      .calculatePerimeter();

    return this.showResults(rectangle);
  }

  /**
   * View designed to introduce the data of a <code>Circle</code> and
   * displays its results.
   *
   * @return The current instance of the <code>Program</code> class.
   * @see Circle
   */
  public Program circleView() {
    Circle circle = new Circle();
    String name;
    double radio;

    System.out.println("\n> CALCULAR AREA Y PERIMETRO DE UN CIRCULO\n");
    name = input.readLine("Introduzca el nombre de la figura: ");
    radio = input.readDouble("Introduzca el valor del radio: ");

    circle
      .setName(name)
      .setRadio(radio)
      .calculateArea()
      .calculatePerimeter();

    return this.showResults(circle);
  }

  /**
   * Displays the results of a <code>Figure</code> (<b>area</b> and <b>perimeter</b>).
   *
   * @param  figure The <code>Figure</code> object to display the results
   * @return The current instance of the <code>Program</code> class.
   */
  public Program showResults(Figure figure) {
    System.out.println(""+
      "\n\t\tRESULTADOS\n"+
      "\n\tNombre de la Figura: " + figure.getName() + "\n" +
      "\n\tArea: " + figure.getArea() + "\n" +
      "\n\tPerimetro: " + figure.getPerimeter() + "\n");
    return this.pause();
  }
}