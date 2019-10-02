import java.io.*;

public class Principal {
	
	private static BufferedReader buffer;
	private static PrintWriter printWriter;

	public static void main(String[] args) throws IOException {
		int option;

		buffer = new BufferedReader(new InputStreamReader(System.in));
		printWriter = new PrintWriter(System.out, true);
		
		printWriter.print("1.- Suma\n"+
				 "2.- Resta\n"+
				 "3.- Multiplicacion\n"+
				 "4.- Division\n\n"+
				 "Escribe una opcion: ");
		printWriter.flush();
		option = Integer.parseInt(buffer.readLine());

		Operaciones operacion = new Operaciones();

		switch (option) {
			case 1:
				printWriter.println("\nResultado: " + operacion.suma(getValue(), getValue()));
				break;
			case 2:
				printWriter.println("\nResultado: " + operacion.resta(getValue(), getValue()));
				break;
			case 3:
				printWriter.println("\nResultado: " + operacion.multiplicacion(getValue(), getValue()));
				break;
			case 4:
				printWriter.print("\nResultado: " + operacion.division(getValue(), getValue()));
				break;
			default:
				break;
		}
		printWriter.flush();
	}
	
	public static int getValue() throws IOException {
		int val;
		
		printWriter.print("Escribe un numero: ");
		printWriter.flush();
		val = Integer.parseInt(buffer.readLine());
		return val;
	}
}
