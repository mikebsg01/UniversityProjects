import java.util.ArrayList;
import java.util.List;

class Program {

  private static Input input;

  public static void main(String[] args) {
    input = new Input();
    List<Employee> employeeList = new ArrayList<Employee>();
    DataTable dataTable = new DataTable();
    int n = 15, i;

    System.out.println("\n\t\tPROGRAMA: Lista de Empleados\n");
    System.out.println("> INGRESAR DATOS DE EMPLEADOS\n");

    for (i = 0; i < n; ++i) {
      Employee tmpEmployee;
      String name;
      int id;

      System.out.println(">> Empleado #" + (i + 1) + ":");
      name = input.readLineNotEmpty("Ingrese el nombre: ");
      id = input.readPosInt("Ingrese el ID: ");
      tmpEmployee = new Employee(name, id);
      employeeList.add(tmpEmployee);
      System.out.println("\n\n\tDatos guardados exitosamente: \n");
      System.out.println("\t" +tmpEmployee.toString() + "\n");
    }

    System.out.println("\n> DATOS DE LOS EMPLEADOS\n");

    dataTable.addSeparator(39)
             .addColumn("ID", 6)
             .addColumn("Nombre", 25)
             .addSeparator(39);

    for (Employee tmpEmployee : employeeList) {
      dataTable.addColumn("" + tmpEmployee.getId() + "", 6)
               .addColumn(tmpEmployee.getName(), 25)
               .nextRow();
    }

    dataTable.addSeparator(39);
    System.out.println(dataTable.toString());
  }
}
