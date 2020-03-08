/*
 INSTITUTO POLITÉCNICO NACIONAL
 ESCUELA SUPERIOR DE CÓMPUTO
 ANÁLISIS DE ALGORITMOS
 GRUPO: 3CV1
 ALUMNOS: HERNÁNDEZ CASTELLANOS CÉSAR URIEL
 AGUILAR GARCIA MAURICIO

 PROFESOR: DR. BENJAMÍN LUNA BENOSO
 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 CLASE ENCARGADA DE IMPLEMENTAR BOGOSORT Y BUCKETSORT

 FECHA: 17/10/2018
 */

import java.util.*;

class AlgoritmosDeOrdenamiento {

    private int k = 0; // Entero encargado de contar el número de pasos de BucketSort

    private int k2 = 0; // Entero encargado de contar el número de pasos de BogoSort

    public Vector<Integer> ordenarPorCasilleros(Vector<Integer> datos, int inferior, int superior) { // Método que se encarga de implementar BucketSort
        int rango = (superior - inferior); // Calculo del rango
        k++;
        int tamanioDelCasillero = rango / 10; // Calculo del tamanio del casillero
        k++;
        Vector<Vector> Casilleros = new Vector<Vector>(); // Creación de un vector e vectores (Casillero)
        k++;
        for (int i = 0; i < 10; i++) { // Se crean 10 casilleros
            k++;
            Casilleros.addElement(new Vector<Integer>()); // Se crea cada casillero
        }
        k++;
        for (int i = 0; i < datos.size(); i++) { // Añadir datos a cada casillero
            k++;
            int casilla = (datos.elementAt(i) - inferior) / tamanioDelCasillero;
            k++;
            Vector<Integer> iCasilla = Casilleros.elementAt(casilla); // Casillo iésimo
            k++;
            iCasilla.addElement(datos.elementAt(i)); //Añadir elemento
            k++;
        }
        Vector<Integer> arregloDeSalida = new Vector<Integer>(); // Se declara el arreglo de salida
        k++;

        //Se ordena de manera recursiva cada uno de los casilleros
        for (int i = 0; i < Casilleros.size(); i++) {
            k++;
            int inferior_ = inferior + (i * tamanioDelCasillero);
            k++;
            int superior_ = inferior + (i * tamanioDelCasillero) + tamanioDelCasillero;
            k++;
            Vector<Integer> tmp = null;
            k++;
            if (superior_ - inferior_ == 1 || Casilleros.elementAt(i).size() == 1) {
                k++;
                tmp = Casilleros.elementAt(i);
            } else {
                k++;
                tmp = new AlgoritmosDeOrdenamiento().ordenarPorCasilleros(Casilleros.elementAt(i), inferior_, superior_);
            }

            //Se incorpora cada casillero al arreglo de salida
            for (int j = 0; j < tmp.size(); j++) {
                k++;
                arregloDeSalida.addElement(tmp.elementAt(j));
            }
        }
        k++;
        return arregloDeSalida;
    }
//Implementación de BogoSort

    public void BogoSort(Vector<Integer> datos) {
        k2++;
        // Mientras el arreglo no se encuentre ordenado haremos lo siguiente:
        while (!seEncuentraOrdenado(datos.toArray())) {
            k2++;
            // Ordenamos de manera aleatoria
            ordenarAleatoriamente(datos.toArray());
            k2++;
        }
        k2++;
        System.out.println(datos);
    }

    // Método encargado de ordenar aleatoriamente al arreglo
    private void ordenarAleatoriamente(Object[] i) {
        for (int x = 0; x < i.length; ++x) {
            int indice1 = (int) (Math.random() * i.length),
                    indice2 = (int) (Math.random() * i.length);
            Object a = i[indice1];
            i[indice1] = i[indice2];
            i[indice2] = a;
        }
    }

    // Método encargado de verificar si nuestro arreglo se encuentra ordenado
    private boolean seEncuentraOrdenado(Object[] i) {
        for (int x = 0; x < i.length - 1; ++x) {
            if ((int) i[x] > (int) i[x + 1]) {
                return false;
            }
        }
        return true;
    }

}
class probadorDeApp {
    // Función que ingresa valores aleatorios al arreglo y nos muestra los arreglos ordenados
    public static void main(String[] args) {
        //BucketSort
        int numeroDeDatos = 100;
        Random r = new Random();
        Vector<Integer> datos = new Vector<Integer>();
        for (int j = 0; j < numeroDeDatos; j++) {
            datos.addElement(r.nextInt(10000));
        }
        Vector<Integer> resultado = new AlgoritmosDeOrdenamiento().ordenarPorCasilleros(datos, 0, 10000);
        System.out.println(resultado);
        //BogoSort
        new AlgoritmosDeOrdenamiento().BogoSort(datos);
    }

}
