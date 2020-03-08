/*
INSTITUTO POLITÉCNICO NACIONAL
ESCUELA SUPERIOR DE CÓMPUTO
ANÁLISIS DE ALGORITMOS
GRUPO: 3CV1
ALUMNOS: HERNÁNDEZ CASTELLANOS CÉSAR URIEL
        AGUILAR GARCIA MAURICIO

PROFESOR: DR. BENJAMÍN LUNA BENOSO
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
CLASE ENCARGADA DE OBTENER LA SUMA DE DOS NÚMEROS BINARIOS DE N_BITS Y OBTENER LA TABLA DE VALORES A GRAFICAR

 FECHA: 28/08/2018
*/

//Paquete donde se encuentra nuestra clase.
package practicauno;

// Librerias necesarias para trabajar.
import java.util.BitSet;
import java.util.Random;

public class binaryCalculatorExperimental {

    // Usaremos dos variables BitSet (A, B) y una constante que nos indique el número de bits a sumar.
    private BitSet A, B;
    private int N_BITS = 0;

    // Constructor  que se encarga inicializar a A y B
    public binaryCalculatorExperimental() {
        A = new BitSet(N_BITS);
        B = new BitSet(N_BITS);
    }

    // Función que se encarga de mostrarnos la tabla de valores a graficar.
    public void proveApplication() {
        setRandomBits(A);
        setRandomBits(B);
        for (int i = 0; i <= 10000; i++) {
            N_BITS = i;
            addBinaryNumber(A, B);

        }
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

        int k = 0;

        BitSet C = new BitSet(N_BITS);
        k++;

        String finalBit = "0";
        k++;

        boolean sum = false, bitOne, bitTwo, carry = false;
        k++;

        for (int i = 0; i <= N_BITS; i++) {
            k++;

            int constant = N_BITS - i;
            k++;

            bitOne = A.get(constant);
            k++;

            bitTwo = B.get(constant);
            k++;

            if (carry) {
                k++;

                if (bitOne && bitTwo) {
                    k++;
                    carry = true;
                    k++;
                    sum = true;
                    k++;
                } else if (bitOne || bitTwo) {
                    k++;
                    carry = true;
                    k++;
                    sum = false;
                    k++;
                } else {
                    k++;
                    carry = false;
                    k++;
                    sum = true;
                    k++;
                }

            } else {
                k++;

                if (bitOne && bitTwo) {
                    k++;
                    carry = true;
                    k++;
                    sum = false;
                    k++;
                } else if (bitOne || bitTwo) {
                    k++;
                    carry = false;
                    k++;
                    sum = true;
                    k++;
                } else {
                    k++;
                    carry = false;
                    k++;
                    sum = false;
                    k++;
                }

            }

            if (sum) {
                k++;
                C.set(constant, true);
                k++;
            }

        }
        if (carry) {
            k++;
            finalBit = "1";
            k++;
        }

        printBits("Array  C: " + finalBit, C);
        k++;

        System.out.println((String.valueOf(N_BITS) + "," + String.valueOf(k)));
    }

}
