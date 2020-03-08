/*
 INSTITUTO POLITÉCNICO NACIONAL
 ESCUELA SUPERIOR DE CÓMPUTO
 ANÁLISIS DE ALGORITMOS
 GRUPO: 3CV1
 ALUMNOS: HERNÁNDEZ CASTELLANOS CÉSAR URIEL
 AGUILAR GARCIA MAURICIO

 PROFESOR: DR. BENJAMÍN LUNA BENOSO
 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 CLASE ENCARGADA DE OBTENER LA SERIE DE FIBONACCI

 FECHA: 05/09/2018
 */
// Paquete donde se encuentra nuestra clase
package practicados;

public class SucesionDeFibonacci {

    //Atributos de la clase SucesionDeFibonacci
    private int numA, numB;

    //Constructor de la clase SucesionDeFibonacci
    public SucesionDeFibonacci() {
        this.numA = 0;
        this.numB = 1;
    }

    //Método encargado de mostrar la sucesión de Fibonacci implementando un algoritmo incremental
    public void imprimirFibonacciIterativa(int numeroDeTerminos) {
        System.out.print(numA + " ");
        for (int i = 2; i <= numeroDeTerminos; i++) {
            System.out.print(numB + " ");
            numB = numA + numB;
            numA = numB - numA;
        }
    }

    // Método encargado de mostrar los números de Fibonacci de manera recursiva.
    public int mostrarNFibonacci(int numeroDeTerminos) {
        if (numeroDeTerminos == 0 || numeroDeTerminos == 1) {
            return numeroDeTerminos;
        } else {
            return mostrarNFibonacci(numeroDeTerminos - 1) + mostrarNFibonacci(numeroDeTerminos - 2);
        }
    }

    // Método encargado de mostrar la serie de Fibonacci de manera recursiva.
    public void imprimirFibonacciRecursivo(int numeroDeTerminos) {
        for (int i = 0; i < numeroDeTerminos; i++) {
            System.out.print(mostrarNFibonacci(i)+" ");
        }
    }

}
