import java.io.*;

class Palindrome {

	/**
	 * ===================================================//
	 * PROGRAMA:
	 * ===================================================//
	 * En base a un cadena de entrada determina si
	 * es un Palindromo o no.
	 *
	 * Ejemplo:
	 * anitalavalatina
	 *
	 * Resultado: "Es un palindromo".
	 * ===================================================*/
	
	private static BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String[] args) throws IOException {
		String word;

		word = getWord();

		if (isPalindrome(word.toLowerCase())) {
			System.out.print("Es un palindromo");
		} else {
			System.out.print("No es un palindromo");
		}
	}
	
	private static String getWord() {
		String tmp = null;
		do {
			System.out.print("Introduzca una palabra: ");
			try {
				tmp = buffer.readLine();	
			} catch (IOException ex) {
				System.out.println("Error de lectura");
			} catch (Exception ex) {
				ex.printStackTrace();
			}
		} while (tmp == null);
		return tmp;
	}

	private static boolean isPalindrome(String str) {
		int i = 0, 
		    j = str.length() - 1;

		while (i < j) {
			if (str.charAt(i) != str.charAt(j))
				return false;
			++i;
			--j;
		}
		return true;
	}
}
