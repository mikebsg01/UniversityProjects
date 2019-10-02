class Program {

  /**
   * Program Class
   * @author Michael Serrato - mikebsg01@gmail.com
   * @description \
   * Crear una clase Lista que realice las siguientes tareas:
   * Una lista simple que contenga cero o más elementos de algún tipo específico.
   * Crear una lista vacia.
   * Añadir elementos a la lista.
   * Determinar si la lista esta vacia.
   * Determinar si la lista esta llena.
   * Acceder a cada elemento de la lista y realizar alguna acción sobre ella.
   */

  // Class Attributes
  private static Input input;
  private static Lists list;

  // Main Method
  public static void main(String[] args) {
    input = new Input();
    list = new Lists();

    System.out.println("\n\t\tPROGRAMA: Listas - Estructura de Datos\n");
    mainMenu();
    pause();
  }

  private static void mainMenu() {
    boolean backToMenu = true, repeatWindow = false;
    int option;

    do {
      do {
        System.out.println("==================== MENU ====================\n" +
                           " 1.- Crear lista de N elementos\n" + 
                           " 2.- Crear lista vacia\n" +
                           " 3.- Agregar elementos a la lista\n" +
                           " 4.- Verificar estado de la lista\n" +
                           " 5.- Cambiar un valor dentro de la lista\n" +
                           " 6.- Salir\n" +
                           "==============================================\n");
        option = input.readInt("\tElegir opcion: ");

        switch (option) {
          case 1:
            createList();
            break;
          case 2:
            createEmptyList();
            break;
          case 3:
            addElementsToTheList();
            break;
          case 4:
            checkListStatus();
            break;
          case 5:
            changeListValues();
            break;
          case 6:
            backToMenu = false;
            repeatWindow = false;
            break;
          default:
            repeatWindow = true;
            break;
        }
      } while (repeatWindow);
    } while (backToMenu);
  }

  private static void pause() {
    Input tmpInput = new Input();

    System.out.print("\n\tPresione la tecla ENTER para continuar . . .");
    tmpInput.readLine();
    System.out.println();
  }

  private static void showListElements() {
    int i = 0;

    System.out.println("\nElementos de la lista:");

    for (int element : list.getAll()) {
      if (i > 0) {
        System.out.print(" " + element);
      } else {
        System.out.print(element);
      }
      ++i;
    }

    System.out.println();
  }

  private static void showListElementsWithIndex() {
    int i = 0;

    System.out.println("\nElementos de la lista:");

    for (int element : list.getAll()) {
      System.out.println(" #" + i + ": " + element);
      ++i;
    }
  }

  private static void createList() {
    int n, i, val;

    System.out.println("\n> CREAR NUEVA LISTA\n");
    n = input.readIntInRange("Cantidad de elementos (N): ", 0, 100);
    list.createEmptyList();
    System.out.println();

    for (i = 0; i < n; ++i) {
      val = input.readInt("Ingrese el valor #" + (i + 1) + ": ");
      list.add(val);
    }

    showListElements();
    System.out.println("\n\tLista creada exitosamente!");
    pause();
  }

  private static void createEmptyList() {
    list.createEmptyList();
    System.out.println("\n> CREAR NUEVA LISTA VACIA\n");
    System.out.println("\tLista creada exitosamente!");
    pause();
  }

  private static void addElementsToTheList() {
    int val;
    char option;

    do {     
      System.out.println("\n> AGREGAR ELEMENTOS A LA LISTA\n");
      val = input.readInt("Ingrese el valor: ");
      list.add(val);
      showListElements();
      System.out.println("\n\tElemento agregado exitosamente!\n");
      option = input.readYesOrNot("\tDesea agregar otro elemento? (y/n): ");
    } while (option == 'y');
    pause();
  }

  private static void checkListStatus() {
    System.out.println("\n> VERIFICAR ESTADO DE LA LISTA");
    if (list.isEmpty()) {
      System.out.println("\n\tLa lista esta vacia.\n");
    } else {
      showListElements();

      if (list.isFull()) {
        System.out.println("\n\tLa lista esta llena.\n");
      } else {
        System.out.println("\n\tLa lista aun no esta llena.\n");
      }
    }
    pause();
  }

  private static void changeListValues() {
    int pos, newVal;
    char option;

    do {
      System.out.println("\n> CAMBIAR VALOR DE ELEMENTOS DE LA LISTA");
      showListElementsWithIndex();
      pos = input.readIntInRange("\nPosicion del elemento: ", 0, list.getSize() - 1);
      newVal = input.readInt("Nuevo valor: ");
      list.changeValue(pos, newVal);
      showListElements();
      System.out.println("\n\tEl cambio ha sido realizado!\n");
      option = input.readYesOrNot("\tDesea cambiar otro elemento de la lista? (y/n): ");
    } while (option == 'y');
    pause();
  }
}