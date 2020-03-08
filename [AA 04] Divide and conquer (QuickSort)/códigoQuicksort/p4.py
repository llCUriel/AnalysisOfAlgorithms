/*
INSTITUTO POLITÉCNICO NACIONAL
ESCUELA SUPERIOR DE CÓMPUTO
ANÁLISIS DE ALGORITMOS
GRUPO: 3CV1
ALUMNOS: HERNÁNDEZ CASTELLANOS CÉSAR URIEL
        AGUILAR GARCIA MAURICIO

PROFESOR: DR. BENJAMÍN LUNA BENOSO
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
PROGRAMA ENCARGADO DE ORDENAR UN ARREGLO UNIDIMENSIONAL MEDIENTE EL ALGORITMO DE QUICKSORT

 FECHA: 19/09/2018
*/


//Función que declara un arreglo bidimensional y lo ordena.
def main():
    arreglo = [34,32,2,4,34,3,4,3,6,4,5]
    quickSort(arreglo,0,len(arreglo)-1)
    print(arreglo)

//Función que realiza la llamada a main.
if __name__ == '__main__':
    main()


//Función encargada de implementar quicksort
def quickSort(arreglo, p, r):
    if p < r:
        q = partition(arreglo, p, r)
        quickSort(arreglo,p, q-1)
        quickSort(arreglo,q+1,r)


//Función encargada de dividir un arreglo de tamaño n = p-r+1 en dos arreglos de tamaño q-p+1 y r-p
def partition(arreglo, p, r):
    x = arreglo[r]
    j = p - 1
    for i in range(p,r):
        if arreglo[i] < x:
            j += 1
            arreglo[j],arreglo[i] = arreglo[i],arreglo[j]
    
    j += 1
    arreglo[j],arreglo[r] = arreglo[r],arreglo[j]
    return j

