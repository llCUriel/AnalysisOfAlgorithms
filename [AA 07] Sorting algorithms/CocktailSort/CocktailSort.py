import random

def main():
    n = 5
    Arreglo = list()
    for i in range (n,0,-1):
        Arreglo.append(i)
    print(Arreglo)
    print(cocktail(Arreglo))

def cocktail(Arreglo):
    tiempo=0
    for i in range(len(Arreglo)-1, 0, -1):
        tiempo+=1
        cambio = False
        for j in range(i, 0, -1):
            tiempo+=1
            if Arreglo[j]<Arreglo[j-1]:
                tiempo+=1
                Arreglo[j], Arreglo[j-1] = Arreglo[j-1], Arreglo[j]
                cambio = True

        for j in range(i):
            tiempo+=1
            if Arreglo[j] > Arreglo[j+1]:
                tiempo+=1
                Arreglo[j], Arreglo[j+1] = Arreglo[j+1], Arreglo[j]
                cambio = True

        if not cambio:
            tiempo+=1
            return Arreglo,tiempo

main()