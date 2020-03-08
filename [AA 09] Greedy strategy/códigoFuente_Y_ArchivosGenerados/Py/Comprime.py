
#INSTITUTO POLITÉCNICO NACIONAL

#ESCUELA SUPERIOR DE CÓMPUTO

#ANÁLISIS DE ALGORITMOS

#GRUPO: 3CV1

#ALUMNOS: HERNÁNDEZ CASTELLANOS CÉSAR URIEL

#        AGUILAR GARCIA MAURICIO

#

#PROFESOR: DR. BENJAMÍN LUNA BENOSO

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

# PRÁCTICA 09 (HUFFMAN)

#

# FECHA: 28/11/2018

#
import sys

from heapq import heapify,heappop,heappush

from collections import defaultdict


def huffmanCodes(frequency):

    heap = [[weight, [symbol, '']] for symbol, weight in frequency.items()]
    
    heapify(heap)
    
    while len(heap) > 1:
    
        x = heappop(heap)
        y = heappop(heap)
        #anade un bit a la izquierda al camino
        #Construye camino, 0 izquierda, para X
        for pair in x[1:]:
            pair[1] = '0' + pair[1]
        #Construye camino, 1 derecha, para Y
    
        for pair in y[1:]:
            pair[1] = '1' + pair[1]
        #suma de las frecuencias,[caracter, camino],[caracter,camino]
    
        heappush(heap, [x[0] + y[0]] + x[1:] + y[1:])
    
    return heappop(heap)

#Verificar que se proporcione un argumento
if len(sys.argv) != 2:
    quit()

inputFile = str(sys.argv[1])
#Leer el archivo
data = ""
with open(inputFile , 'r') as f:
    data += f.read()

frequency = defaultdict(int)
#Construir el diccionario de frecuencias
for symbol in data:
    frequency[symbol] += 1

#Imprimir el diccionario de frecuencias
with open("frecuencias.txt", 'w') as f:

    for char, freq in frequency.items():
    
        if char == "\n":
    
            char = "\\n"
    
        f.write(str(char).ljust(10) + str(freq).ljust(10) + "\n")

huff = huffmanCodes(frequency)

#Ordenar de mayor a menor los caminos
# huffman = sorted(huff[1:], key=lambda p: (len(p[-1]), p))

#Imprimir la codificacion
with open("codificacion.txt", 'w') as f:
  
    for p in huff[1:]:
  
        if p[0] == "\n":
  
            f.write("\\n".ljust(10) + p[1] + "\n")
  
        else:
  
            f.write(p[0].ljust(10) + p[1] + "\n")


#Imprimir el archivo codificado
n = len(frequency)
with open("archivoCodificado.bin", "wb") as f:
    #Generar la secuencia codificada
  
    dataCompressed = ""
  
    for symbol in data:
  
        for char, code  in huff[1:]:
  
            if symbol == char:
  
                dataCompressed += code
  
    #Anadir bits extra para completar octetos
  
    padding = 8 - len(dataCompressed)%8
  
    for i in range(padding):
  
        dataCompressed += "0"

    #Empaquetar de 8 en 8 los bits en un byte, para lograr la compresion
    dataCoded = "{0:08b}".format(padding) + dataCompressed
  
    b = bytearray()
  
    for i in range(0, len(dataCoded), 8):
  
        byte = dataCoded[i:i+8]
  
        b.append(int(byte,2))
  
    f.write(bytes(b))

print ("Se codificó correctamente")

print ("Se generó frecuencias.txt")

print ("Se generó codificacion.txt")

print ("Se generó archivoCodificado.txt")
