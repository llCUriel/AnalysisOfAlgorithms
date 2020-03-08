 #INSTITUTO POLITÉCNICO NACIONAL
 #ESCUELA SUPERIOR DE CÓMPUTO
 #ANÁLISIS DE ALGORITMOS
 #GRUPO: 3CV1
 #ALUMNOS: HERNÁNDEZ CASTELLANOS CÉSAR URIEL
 #AGUILAR GARCIA MAURICIO

 #PROFESOR: DR. BENJAMÍN LUNA BENOSO
 #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 #PRÁCTICA 10

#FECHA: 03/12/2018

import sys

from itertools import tee


#Función encargada de probar la app

def probadorDeAplicacion(n,s):

    for i in range(3,n+1,s):
        Grafo = [[ 1 for j in range(i)] for k in range(i)]
        caminoHam = [j for j in range(i)]
        caminoHam.append(0)
        contador = checarCicloHamiltoniano(Grafo, caminoHam, i)
        print ("{},{}".format(i,contador))

#Funcion encargada de verificar si es un ciclo hamiltoniano.

def checarCicloHamiltoniano(Grafo, caminoHam, n):

    contador = 0
    vertices = [ i for i in range(n)]
    for i in range(n-1):
        a = caminoHam[i];
        b = caminoHam[i+1];
        contador += 1
        if Grafo[a][b] == 0:
            return contador
        if a not in vertices:
            return contador
        else:
            vertices.remove(a)
    return contador

#Función encargada de leer el ciclo hamiltoniano
def leercaminoHamilton(n):

    c = input("")
    caminoHam = [int(k) for k in c.split(",")]
    if c[0] != c[-1]:
        print("El ciclo debe terminar en el inicio")
        exit(0)
    if len(caminoHam) != n+1:
        print("No es solucion :c")
        exit(0)
    return caminoHam

#Función encargada de construir la matriz de adyacencia
def leer_Grafo(n):

    Grafo = [[ 0 for i in range(n)]\
              for j in range(n)]
    for i in range(n):
        fila = input("")
        fila = [int(j) for j in fila.split()]
        for j in range(len(fila)):
            if int(j) in range(n):
                Grafo[i][j] = fila[j]
            else:
                print("Grafo inválido {} y {}".format(i,j))
    return Grafo

#Mostrar grado
def mostrarGrafo(Grafo, n):

    for i in range(n):
        for j in range(n):
            print(Grafo[i][j], end=' ')
        print()

#Funcion para iterar en pares
def iterarEnPares(iterable):

    "Camino -> (Camino0,Camino1), (Camino1,Camino2), (Camino2, Camino3), ... etc"
    uno, dos = tee(iterable)
    next(dos, None)
    return zip(uno, dos)
