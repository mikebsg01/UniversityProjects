import java.io.*;

class Program {
	private static BufferedReader buffer;

	public static void main(String[] arg) throws IOException {
		Articulo art = new Articulo();
		buffer = new BufferedReader(new InputStreamReader(System.in));
		System.out.print("Ingrese la descripcion: ");
		art.establecerDescripcion(buffer.readLine());
		System.out.print("Ingrese el costo: ");
		art.establecerCosto(Double.parseDouble(buffer.readLine()));
		art.calcularPrecioVta();
		System.out.println("Descripcion: " + art.obtenerDescripcion());
		System.out.println("Precio Venta: " + art.obtenerPrecioVta());
	}
}
