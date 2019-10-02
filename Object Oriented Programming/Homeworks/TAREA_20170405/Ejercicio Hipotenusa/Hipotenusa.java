import java.io.*;
import java.lang.Math.*;

class Hipotenusa {
	private static BufferedReader buffer;
	private double a,
		       b,
		       c;

	public void establecerA(double n) {
		this.a = n;
	}

	public void establecerB(double n) {
		this.b = n;
	}

	public void calcularC() {
		this.c = Math.sqrt((this.a * this.a) + (this.b * this.b));
	}

	public double obtenerC() {
		return this.c;
	}

	public static void main(String[] arg) throws IOException {
		Hipotenusa h = new Hipotenusa();
		buffer = new BufferedReader(new InputStreamReader(System.in));
		System.out.print("Ingrese el valor de A: ");
		h.establecerA(Double.parseDouble(buffer.readLine()));
		System.out.print("Ingrese el valor de B: ");
		h.establecerB(Double.parseDouble(buffer.readLine()));
		h.calcularC();
		System.out.println("El valor de la hipotenusa (C) es " + h.obtenerC());
	}
}
