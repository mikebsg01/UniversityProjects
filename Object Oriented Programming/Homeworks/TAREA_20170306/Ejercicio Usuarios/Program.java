import java.io.*;

public class Program {
  
  private static BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));

  public static void main(String[] args) {
    int i;
    User[] user = new User[100];

    System.out.println("\tPROGRAMA: Alta de Usuarios\n");
    
    for (i = 0; i < 100; ++i) {
      user[i] = new User();
      user[i].getID();
      user[i].getDomain();
      user[i].getPassword();

      if (user[i].correct()) {
        System.out.println("\n\tEl usuario ha sido creado exitosamente! :)\n");
        user[i].showData();
      }
    }
  }
}