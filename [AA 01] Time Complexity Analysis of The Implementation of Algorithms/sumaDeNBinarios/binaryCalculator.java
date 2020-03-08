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

 FECHA: 28/08/2018
*/

//Paquete donde se encuentra nuestra clase.
package practicauno;

// Librerias necesarias para trabajar.
import java.util.BitSet;
import java.util.Random;


public class binaryCalculator {

    // Usaremos dos variables BitSet (A, B) y una constante que nos indique el número de bits a sumar.
    private final BitSet A, B;
    private final int N_BITS = 64;

    // Constructor  que se encarga inicializar a A y B
    public binaryCalculator() {

        A = new BitSet(N_BITS);

        B = new BitSet(N_BITS);

    }

    // Función que se encarga de llamar a los métodos implementados para el funcionamiento del programa.
    public void proveApplication() {
        setRandomBits(A);
        setRandomBits(B);
        printBits("Array  A:  ", A);
        printBits("Array  B:  ", B);
        addBinaryNumber(A, B);
    }

    // Función encargada de poblar nuestros BitSet de valores aleatorios.
    public void setRandomBits(BitSet b) {
        Random r = new Random();
        for (int i = 0; i < N_BITS / 2; i++) {
            b.set(r.nextInt(N_BITS));
        }
    }

    // Función encargada de imprimir los arreglos de bits
    public void printBits(String prompt, BitSet b) {
        System.out.print(prompt + "");
        for (int i = 0; i < N_BITS; i++) {
            System.out.print(b.get(i) ? "1" : "0");
        }
        System.out.println();
    }

    // Función encargada de sumar y mostrar el resultado en pantalla de la suma binaria
    public void addBinaryNumber(BitSet A, BitSet B) {

        BitSet C = new BitSet(N_BITS);

        String finalBit = "0";

        boolean sum = false, carry = false, bitOne, bitTwo;

        for (int i = 0; i <= N_BITS; i++) {

            int constant = N_BITS - i;

            bitOne = A.get(constant);

            bitTwo = B.get(constant);

            if (carry) {
                if (bitOne && bitTwo) {
                    carry = true;
                    sum = true;
                } else if (bitOne || bitTwo) {
                    carry = true;
                    sum = false;
                } else {
                    carry = false;
                    sum = true;
                }

            } else {
                if (bitOne && bitTwo) {
                    carry = true;
                    sum = false;
                } else if (bitOne || bitTwo) {
                    carry = false;
                    sum = true;
                } else {
                    carry = false;
                    sum = false;
                }

            }

            if (sum) {
                C.set(constant, true);
            }

        }
        if (carry) {
            finalBit = "1";
        }

        printBits("Array  C: " + finalBit, C);

    }

}
