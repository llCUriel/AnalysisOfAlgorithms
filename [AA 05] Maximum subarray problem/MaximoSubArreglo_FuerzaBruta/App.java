/*
INSTITUTO POLITÉCNICO NACIONAL
ESCUELA SUPERIOR DE CÓMPUTO
ANÁLISIS DE ALGORITMOS
GRUPO: 3CV1
ALUMNOS: HERNÁNDEZ CASTELLANOS CÉSAR URIEL
        AGUILAR GARCIA MAURICIO

PROFESOR: DR. BENJAMÍN LUNA BENOSO
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
CLASE ENCARGADA DE INSTANCIAR LA CLASE MaximoSubArreglo, además de imprimir los valores k & n de diferentes arreglos

 FECHA: 03/10/2018
*/

//PAQUETE
package pr05;

public class App {

    //Función principal que obtiene arreglos aleatorios y va variendo su tamaño n, además de obtener el máximo subarreglos de cada uno de ellos.
    public static void main(String[] args) {
        int X = -10, Y = 10, numero = 0;
        int array[];
        MaximoSubArreglo m = new MaximoSubArreglo();

        for (int i = 1; i < 1000; i++) {
            array = new int[i];
            for (int j = 0; j < i; j++) {
                numero = (int) (Math.random() * (X - Y + 1) + Y);
                array[j] = numero;
            }
            System.out.println(m.obtenerMaximoSubArreglo(array).getLast().toString());
        }
    }
}
