import java.io.*;

class Date {

	/**
	 * ===================================================//
	 * PROGRAMA:
	 * ===================================================//
	 * Obtiene una fecha en el siguiente formato:
	 * DDMMAAAA
	 * 
	 * E imprime el resultado en el siguiente formato:
	 * Día de Mes del Año
	 *
	 * Ejemplo:
	 * 20 de Febrero del 2017
	 * ===================================================*/

	private static BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
	private static String months[] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
	private static boolean finish = false;

	public static void main(String[] args) {
		String date;

		do {
			date = getDate();
			System.out.print(getFullDate(date));
		} while (!finish);
	}

	private static boolean isDate(String date) {
		int i, n = date.length();

		if (date == null)
			return false;
		if (n != 8)
			return false;

		for (i = 0; i < n; ++i) {
			if (!Character.isDigit(date.charAt(i))) {
				return false;
			}
		}
		return true;
	}

	private static String getDate() {
		String date = null;
		do {
			System.out.print("Introduzca una fecha: ");
			try {
				date = buffer.readLine();
			} catch (IOException e) {
				System.out.println("Error en la lectura.");
			} catch (Exception e) {
				e.printStackTrace();
			}
		} while (date == null || !isDate(date));
		return date;
	}

	private static int getNumberByCharsOfString(String str, int a, int b) {
		int n = 0, i;
		
		for (i = a; i <= b; ++i) {
			n = (n * 10) + Integer.parseInt("" + str.charAt(i));
		}
		return n;
	}

	private static String getFullDate(String date) {
		int day, month, year;
		
		day = getNumberByCharsOfString(date, 0, 1);
		month = getNumberByCharsOfString(date, 2, 3);
		year = getNumberByCharsOfString(date, 4, 7);

		if (day > 31) {
			System.out.println("El valor del dia no puede ser mayor a 31.");
			return null;
		}

		if (month > 12) {
			System.out.println("El valor del mes no puede ser mayor a 12.");
			return null;
		}

		finish = true;
		return day + " de " + months[month - 1] + " de " + year;
	}
}
