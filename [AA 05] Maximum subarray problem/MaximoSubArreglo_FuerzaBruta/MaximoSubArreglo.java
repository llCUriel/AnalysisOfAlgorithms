package pr05;
/*
INSTITUTO POLITÉCNICO NACIONAL
ESCUELA SUPERIOR DE CÓMPUTO
ANÁLISIS DE ALGORITMOS
GRUPO: 3CV1
ALUMNOS: HERNÁNDEZ CASTELLANOS CÉSAR URIEL
        AGUILAR GARCIA MAURICIO

PROFESOR: DR. BENJAMÍN LUNA BENOSO
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
CLASE ENCARGADA DE OBTENER EL MÁXIMO SUBARREGLOS

 FECHA: 03/10/2018
*/


//LIBRERIAS
import java.util.Arrays;
import java.util.LinkedList;

public class MaximoSubArreglo {

    // ATRIBUTOS UTILIZADOS EN LA CLASE
    private int suma_max, suma;
    private int n, max_izq, max_der;

    // CONSTRUCTOR QUE INICIALIZA sum_ax & suma
    public MaximoSubArreglo() {
        this.suma_max = Integer.MIN_VALUE;
        this.suma = 0;
    }

    //FUNCIÓN ENCARGADA DE OBTENER EL MÁXIMO SUBARREGLO POR FUERZA BRUTA.
    public LinkedList obtenerMaximoSubArreglo(int[] arreglo) {
        n = arreglo.length;
        for (int i = 0; i < n; i++) {
            suma = 0;
            for (int j = 0; j < n; j++) {
                suma += arreglo[j];
                if (suma > suma_max) {
                    suma_max = suma;
                    max_izq = i;
                    max_der = j;
                }
            }
        }
        return new LinkedList(Arrays.asList(max_izq, max_der, suma_max));
    }
}
