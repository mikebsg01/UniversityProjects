import java.io.*;

public class User {

  // Variables requeridas para su uso en la interfaz
  private static BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));

  // Atributos de la clase
  private String id;
  private String domain;
  private String password;

  public void getID() {
    String id = null;

    do {
      System.out.print("Introduzca el ID: ");

      try {
        id = buffer.readLine();
      } catch (IOException ex) {
        System.out.println("\n\tError en la lectura\n");
      } catch (Exception ex) {
        ex.printStackTrace();
      }
    } while (id == null || id.isEmpty());
    this.id = id;
  }

  public void getDomain() {
    String domain = null;

    do {
      System.out.print("Introduzca el Dominio: ");
      
      try {
        domain = buffer.readLine();
      } catch (IOException ex) {
        System.out.println("\n\tError en la lectura\n");
      } catch (Exception ex) {
        ex.printStackTrace();
      }
    } while (domain == null || domain.isEmpty());
    this.domain = domain;
  }

  public void getPassword() {
    String password = null,
           confirmPassword = null;

    do {      
      try {
        System.out.print("Introduzca la Contrasena: ");
        password = buffer.readLine();
        System.out.print("Confirmar contrasena: ");
        confirmPassword = buffer.readLine();
      } catch (IOException ex) {
        System.out.println("\n\tError en la lectura\n");
      } catch (Exception ex) {
        ex.printStackTrace();
      }

      if (password == null || password.isEmpty() || password.length() < 6) {
        System.out.println("\n\tEl password debe tener un minimo de 6 caracteres.\n");
      }
      else if (!password.equals(confirmPassword)) {
        System.out.println("\n\tLa confirmacion del password debe coincidir.\n");
      }

    } while (password == null || password.isEmpty() || password.length() < 6 || !password.equals(confirmPassword));
    this.password = password;
  }

  public void showData() {
    System.out.println("==================================================\n");
    System.out.println("\tCorreo electronico: " + this.getEmail());
    System.out.println("\tPassword: " + this.password + "\n");
    System.out.println("==================================================\n");
  }

  public boolean correct() {
    return !this.id.isEmpty() && !this.domain.isEmpty() && !this.password.isEmpty();
  }

  private String getEmail() {
    return this.id + "@" + this.domain;
  }
}