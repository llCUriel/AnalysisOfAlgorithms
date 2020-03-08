/*
 INSTITUTO POLITÉCNICO NACIONAL
 ESCUELA SUPERIOR DE CÓMPUTO
 ANÁLISIS DE ALGORITMOS
 GRUPO: 3CV1
 ALUMNOS: HERNÁNDEZ CASTELLANOS CÉSAR URIEL
 AGUILAR GARCIA MAURICIO

 PROFESOR: DR. BENJAMÍN LUNA BENOSO
 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 CLASE ENCARGADA DE OBTENER LA SUMA DE DOS NÚMEROS BINARIOS DE N_BITS

 FECHA: 04/09/2018
 */
package practicados;

public class Application {

    public static void main(String[] args) {
        int numeroDeTerminos = 20;
        SucesionDeFibonacci m = new SucesionDeFibonacci();

        System.out.println("\nGenerando sucesión de Fibonacci de manera recursiva...");
        m.imprimirFibonacciRecursivo(numeroDeTerminos);
        System.out.println("\nGenerando sucesión de Fibonacci de manera iterativa...");
        m.imprimirFibonacciIterativa(numeroDeTerminos);
        
    }
}
