public class Operaciones {
	public int suma(int a, int b) {
		return a + b;
	}

	public int resta(int a, int b) {
		return a - b;
	}

	public double multiplicacion(double a, double b) {
		return a * b;
	}

	public double division(double a, double b) {
		if (a != 0) {
			return a / b;
		} else {
			return 0;
		}
	}
}
