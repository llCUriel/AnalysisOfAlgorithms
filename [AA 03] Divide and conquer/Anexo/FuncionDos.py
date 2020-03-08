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

 FECHA: 12/09/2018
*/

//Función principal encargada de llamar a FuncionDos
def main():
    arreglo = [4234,32432,23432,23423,3243,223,233]
    x = 0
    FuncionDos(arreglo,x)
    print arreglo

//Llamar a main()
if __name__ == '__main__':
    main()

//Función dos encargada de poner el número máximo en todo el arreglo.
def FuncionDos(array, x):
    for i in range(0,len(arreglo)):
        if(arreglo[i] < x):
            arreglo[i] = min(arreglo)
        elif(array[i] > x):
            arreglo[i] = max(arreglo)
        else:
            break
