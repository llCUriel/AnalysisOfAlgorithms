
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

        #Añade un bit a la izquierda al camino

        #Construye camino, 0 izquierda, para X

        for pair in x[1:]:

            pair[1] = '0' + pair[1]

        #Construye camino, 1 derecha, para Y

        for pair in y[1:]:

            pair[1] = '1' + pair[1]

        #Suma de las frecuencias
        
        heappush(heap, [x[0] + y[0]] + x[1:] + y[1:])
        
    return heappop(heap)

#Verificar que se proporcione un argumento

if len(sys.argv) != 3:

    quit()

compressedFile = str(sys.argv[1])

#Leer el archivo binario

data = ""

with open(compressedFile, 'rb') as f:

    byte = f.read(1)

    while byte:

        byte = ord(byte)

        bits = bin(byte)[2:].rjust(8, '0')

        data += bits

        byte = f.read(1)

#Remover el padding que se agrego para hacer los octetos
n = len(data)

padding = int(data[:8], 2)

data = data[8: n - padding]

n = len(data)

codesFile = str(sys.argv[2])

#Leer el archivo de codificacion, codigos de Huffman

huffmanCodes = defaultdict(str)

with open(codesFile, 'r') as f:

    for line in f:

        char, code= line[:10].strip(), line[10:].strip()

        #Recuperar el espacio y el salto de linea

        if char == "":

            char = " "

        if char == "\\n":

            char = "\n"

        huffmanCodes[code] = char;


#Descomprimir el archivo e imprimirlo
with open("archivoDecodificado.txt", 'w') as f:

    currentCode = ""

    decompressedData = ""

    for bit in data:

        currentCode += bit

        if currentCode in huffmanCodes:

            decompressedData += huffmanCodes[currentCode]

            currentCode = ""

    f.write(decompressedData)

print ("Se descomprimio correctamente")

print ("Se genero archivoDecodificado.txt")
