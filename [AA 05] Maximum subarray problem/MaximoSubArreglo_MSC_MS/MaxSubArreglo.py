/*
INSTITUTO POLITÉCNICO NACIONAL
ESCUELA SUPERIOR DE CÓMPUTO
ANÁLISIS DE ALGORITMOS
GRUPO: 3CV1
ALUMNOS: HERNÁNDEZ CASTELLANOS CÉSAR URIEL
        AGUILAR GARCIA MAURICIO

PROFESOR: DR. BENJAMÍN LUNA BENOSO
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
PROGRAMA ENCARGADO DE IMPLEMENTAR DOS ALGORITMOS PARA OBTENER EL MÁXIMO SUBARREGLO

 FECHA: 03/10/2018
*/

//FUNCIÓN ENCARGADA DE LLAMAR A LAS FUNCIONES QUE OBTIENEN EL MÁXIMO SUBARREGLO
def main():
    arreglo = [2, 3, 6, 5, 3,4,5,0,1,-6,4]
    #sum_c = obtenerMaximoSubArregloCruzado(arreglo,0,len(arreglo)/2,len(arreglo)-1)
    #print(sum_c)
    sum_f =obtenerMaximoSubArreglo(arreglo,0,len(arreglo)-1)
    print(sum_f)

//FUNCIÓN ENCARGADA DE OBTENER EL MÁXIMO SUBARREGLO
def obtenerMaximoSubArreglo(arreglo,bajo,alto):
    if(bajo == alto):
        return arreglo[bajo]
    else:
        medio = (bajo + alto)/2
        return max(obtenerMaximoSubArreglo(arreglo,bajo,medio),
                   obtenerMaximoSubArreglo(arreglo,medio+1,alto),
                   obtenerMaximoSubArregloCruzado(arreglo,bajo,medio,alto))

//FUNCIÓN ENCARGADA DE OBTENER EL MÁXIMO SUBARREGLO
def obtenerMaximoSubArregloCruzado(arreglo,bajo,medio,alto):
    suma_izq = max_izq = suma = 0
    for x in range(medio,bajo-1,-1):
        suma = suma + arreglo[x]
        if(suma > suma_izq):
            suma_izq = suma
            max_izq = x
    suma_der = max_der = suma = 0
    for y in range(medio+1,alto+1):
        suma = suma + arreglo[y]
        if(suma >= suma_der):
            suma_der = suma
            max_der = y
    return suma_der+suma_izq        

//FUNCIÓN ENCARGADA DE LLAMAR A MAIN()
if __name__ == '__main__':
    main()