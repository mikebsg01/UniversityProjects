import java.io.*;
import java.util.List;
import java.util.ArrayList;

public class Program {
	
	private static BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String[] args) {
		List<Vendedor> vendedores = new ArrayList<Vendedor>();
		double total = 0.00; // El total de todas las ventas registradas por todos los vendedores.

		System.out.println("\tPROGRAMA: Ventas por mes");

		do {
			Vendedor v = new Vendedor();
			v.requestName();
			v.requestSales();
			v.showAllSales();
			vendedores.add(v);
		} while (askToLeave());

		for (Vendedor v : vendedores) {
			v.showAllSales();
			total += v.getTotal();
		}
		System.out.println("\n\tMonto total de todas las ventas registradas: " + Vendedor.formatCurrency.format(total) + "\n");
	}

	private static boolean askToLeave() {
		char c = '\0';

		do {
			System.out.print("\n\tDesea continuar? (y/n): ");

			try {
				c = buffer.readLine().charAt(0);
			}  catch (IOException ex) {
	      System.out.println("\n\tError en la lectura\n");
	    } catch (Exception ex) {
	    	c = '\0';
	    }

	    if (c == 'y' || c == 'n') {
	    	return (c == 'y') ? true : false;
	    } else {
	    	System.out.println("\n\tPor favor, introduzca \'y\' o \'n\' segun sea el caso que desee.\n");
	    }
		} while(true);
	}
}
