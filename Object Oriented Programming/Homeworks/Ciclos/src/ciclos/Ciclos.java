/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ciclos;
import java.io.*;

/**
 *
 * @author michael
 */
public class Ciclos {

    /**
     * @param args the command line arguments
     */
    private static BufferedReader stdIn = new BufferedReader(
        new InputStreamReader(System.in)
    );
    private static PrintWriter stdOut = new PrintWriter(System.out, true);
    
    public int menu() {
        int opcion = -1;
        do {
           try {
               stdOut.print("1.- Factorial"+
                            "\n2.- Primo"+
                            "\n3.- Salir"+
                            "\n0.- Salir"+
                            "\nEscribe tu opcion: ");
               stdOut.flush();
               opcion = Integer.parseInt(stdIn.readLine());
           } catch (Exception ex) {
               ex.printStackTrace();
           }
        } while (opcion == -1);
        return opcion;
    }
    
    public int factorial(int n) {
        int i, fac = 1;
        for (i = n; i >= 2; --i) {
            fac *= i;
        }
        return fac;
    }
    
    public boolean esPrimo(int valor) {
        int i;
        
        if (valor == 1)
            return false;
        if (valor == 2)
            return true;
        if (valor % 2 == 0)
            return false;
        
        for (i = 2; i * i <= valor; ++i)
            if (valor % i == 0)
                return false;
        return true;
    }
    
    public static int solicitaValor() {
        int val;

        while (true) {
            stdOut.print("Introduce un numero: ");
            stdOut.flush();

            try {
                    val = Integer.parseInt(stdIn.readLine());
            } catch (IOException e) {
                    stdOut.print("\n\tError de lectura.\n\n");
                    continue;
            } catch (NumberFormatException e) {
                    stdOut.print("\n\tSe espera un numero.\n\n");
                    continue;
            }
            return val;
        }
    }
    
    public static void main(String[] args) {
        // TODO code application logic here
        int opcion, valor, resultado;
        Ciclos ciclo;
        
        ciclo = new Ciclos();
        opcion = ciclo.menu();
        
        if (opcion == 1) {
            valor = solicitaValor();
            resultado = ciclo.factorial(valor);
            stdOut.print("\n\tEl factorial de " + valor + " es " + resultado + ".\n");
            stdOut.flush();
        }
        else if (opcion == 2) {
            valor = solicitaValor();
            resultado = ciclo.esPrimo(valor) ? 1 : 0;
            
            if (resultado == 1) {
                stdOut.print("\n\tSi es un numero primo.\n");
                stdOut.flush();
            } else {
                stdOut.print("\n\tNo es un numero primo.\n");
                stdOut.flush();
            }
        }
    }
}
