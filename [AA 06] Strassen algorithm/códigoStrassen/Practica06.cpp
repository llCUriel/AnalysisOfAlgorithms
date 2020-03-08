#include <bits/stdc++.h>

/*
INSTITUTO POLITÉCNICO NACIONAL
ESCUELA SUPERIOR DE CÓMPUTO
ANÁLISIS DE ALGORITMOS
GRUPO: 3CV1
ALUMNOS: HERNÁNDEZ CASTELLANOS CÉSAR URIEL
        AGUILAR GARCIA MAURICIO

PROFESOR: DR. BENJAMÍN LUNA BENOSO
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
MERGESORT

 FECHA: 10/10/2018
*/

using namespace std;

void strassen(double **a, double **b, double **c, int tam);
void suma(double **a, double **b, double **Resultado, int tam);
void resta(double **a, double **b, double **Resultado, int tam);
double **creaMatriz(int tam, int random);
double **limpiaMatriz(double **v, int tam);
void imprimeMatriz(double **matriz, int n);

#define MAX 7

int cont = 0;

int main(){
	ofstream al;
	al.open("out.txt");
	srand (time(NULL));
 	for(int NUM = 1;NUM<=MAX;NUM++){
	 	cont = 0;
	 	int n=pow(2,NUM);
	 	double **a = creaMatriz(n,1);
		double **b = creaMatriz(n,1);
		double **c = creaMatriz(n,0);
	 	strassen(a,b,c,n);
        //Imprimir matrices
	 	/*imprimeMatriz(a,n);
	 	cout << "-------" << endl;
	 	imprimeMatriz(b,n);
	 	cout << "-------" << endl;
	 	imprimeMatriz(c,n);*/
	 	cout << NUM << endl;
	 	al << n << "," << cont << '\n';
	}
	al.close();
	return 0;
}

void imprimeMatriz(double **matriz, int n) {
    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            if (j != 0) {
                cout << " ";
            }
            cout << matriz[i][j];
        }
        cout << endl;
    }
}

void strassen(double **a, double **b, double **c, int tam) {

    // cuando matriz es 1 x 1:
    if (tam == 1) {
        c[0][0] = a[0][0] * b[0][0];
        cont++;
        return;
    }

    // otros casos:
    else {
        int newTam = tam/2;
        double **a11, **a12, **a21, **a22;
        double **b11, **b12, **b21, **b22;
        double **c11, **c12, **c21, **c22;
        double **p1, **p2, **p3, **p4, **p5, **p6, **p7;

        // creaciÃ³n de matrices:
        a11 = creaMatriz(newTam, -1);
        a12 = creaMatriz(newTam, -1);
        a21 = creaMatriz(newTam, -1);
        a22 = creaMatriz(newTam, -1);

        b11 = creaMatriz(newTam, -1);
        b12 = creaMatriz(newTam, -1);
        b21 = creaMatriz(newTam, -1);
        b22 = creaMatriz(newTam, -1);

        c11 = creaMatriz(newTam, -1);
        c12 = creaMatriz(newTam, -1);
        c21 = creaMatriz(newTam, -1);
        c22 = creaMatriz(newTam, -1);

        p1 = creaMatriz(newTam, -1);
        p2 = creaMatriz(newTam, -1);
        p3 = creaMatriz(newTam, -1);
        p4 = creaMatriz(newTam, -1);
        p5 = creaMatriz(newTam, -1);
        p6 = creaMatriz(newTam, -1);
        p7 = creaMatriz(newTam, -1);

        double **aResultado = creaMatriz(newTam, -1);
        double **bResultado = creaMatriz(newTam, -1);

        int i, j;

        //divide las matrices en 4 matrices:
        for (i = 0; i < newTam; i++) {
            for (j = 0; j < newTam; j++) {
                a11[i][j] = a[i][j];
                a12[i][j] = a[i][j + newTam];
                a21[i][j] = a[i + newTam][j];
                a22[i][j] = a[i + newTam][j + newTam];
				
                b11[i][j] = b[i][j];
                b12[i][j] = b[i][j + newTam];
                b21[i][j] = b[i + newTam][j];
                b22[i][j] = b[i + newTam][j + newTam];
            }
        }

        // Calculando p1 a p7:

        suma(a11, a22, aResultado, newTam); // a11 + a22
        suma(b11, b22, bResultado, newTam); // b11 + b22
        strassen(aResultado, bResultado, p1, newTam); // p1 = (a11+a22) * (b11+b22)

        suma(a21, a22, aResultado, newTam); // a21 + a22
        strassen(aResultado, b11, p2, newTam); // p2 = (a21+a22) * (b11)

        resta(b12, b22, bResultado, newTam); // b12 - b22
        strassen(a11, bResultado, p3, newTam); // p3 = (a11) * (b12 - b22)

        resta(b21, b11, bResultado, newTam); // b21 - b11
        strassen(a22, bResultado, p4, newTam); // p4 = (a22) * (b21 - b11)

        suma(a11, a12, aResultado, newTam); // a11 + a12
        strassen(aResultado, b22, p5, newTam); // p5 = (a11+a12) * (b22)	

        resta(a21, a11, aResultado, newTam); // a21 - a11
        suma(b11, b12, bResultado, newTam); // b11 + b12
        strassen(aResultado, bResultado, p6, newTam); // p6 = (a21-a11) * (b11+b12)

        resta(a12, a22, aResultado, newTam); // a12 - a22
        suma(b21, b22, bResultado, newTam); // b21 + b22
        strassen(aResultado, bResultado, p7, newTam); // p7 = (a12-a22) * (b21+b22)

        // calculando c21, c21, c11 e c22:

        suma(p3, p5, c12, newTam); // c12 = p3 + p5
        suma(p2, p4, c21, newTam); // c21 = p2 + p4

        suma(p1, p4, aResultado, newTam); // p1 + p4
        suma(aResultado, p7, bResultado, newTam); // p1 + p4 + p7
        resta(bResultado, p5, c11, newTam); // c11 = p1 + p4 - p5 + p7

        suma(p1, p3, aResultado, newTam); // p1 + p3
        suma(aResultado, p6, bResultado, newTam); // p1 + p3 + p6
        resta(bResultado, p2, c22, newTam); // c22 = p1 + p3 - p2 + p6

        // Se juntan las matrices resultantes en una sola:
        for (i = 0; i < newTam ; i++) {
            for (j = 0 ; j < newTam ; j++) {
                c[i][j] = c11[i][j];
                c[i][j + newTam] = c12[i][j];
                c[i + newTam][j] = c21[i][j];
                c[i + newTam][j + newTam] = c22[i][j];
            }
        }

        // Liberando memoria:
        a11 = limpiaMatriz(a11, newTam);
        a12 = limpiaMatriz(a12, newTam);
        a21 = limpiaMatriz(a21, newTam);
        a22 = limpiaMatriz(a22, newTam);

        b11 = limpiaMatriz(b11, newTam);
        b12 = limpiaMatriz(b12, newTam);
        b21 = limpiaMatriz(b21, newTam);
        b22 = limpiaMatriz(b22, newTam);

        c11 = limpiaMatriz(c11, newTam);
        c12 = limpiaMatriz(c12, newTam);
        c21 = limpiaMatriz(c21, newTam);
        c22 = limpiaMatriz(c22, newTam);

        p1 = limpiaMatriz(p1, newTam);
        p2 = limpiaMatriz(p2, newTam);
        p3 = limpiaMatriz(p3, newTam);
        p4 = limpiaMatriz(p4, newTam);
        p5 = limpiaMatriz(p5, newTam);
        p6 = limpiaMatriz(p6, newTam);
        p7 = limpiaMatriz(p7, newTam);
        aResultado = limpiaMatriz(aResultado, newTam);
        bResultado = limpiaMatriz(bResultado, newTam);
    } // fin de else
    
} // fin de funciÃ³n de Strassen

/*------------------------------------------------------------------------------*/
// funcion para sumar dos matrices
void suma(double **a, double **b, double **Resultado, int tam) {

    int i, j;

    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            Resultado[i][j] = a[i][j] + b[i][j];
            
        }
    }
}

/*------------------------------------------------------------------------------*/
// funciones para restar dos matrices
void resta(double **a, double **b, double **Resultado, int tam) {

    int i, j;

    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            Resultado[i][j] = a[i][j] - b[i][j];
            
        }
    }	
}

/*------------------------------------------------------------------------------*/
//Si random es igual a 0 entonces la matriz se llena con ceros, si random es 1 entonces se llena con números random, si la random es diferente entonces se llena sin valores
double **creaMatriz(int tam, int random) {

    int i, j, n = tam, m = tam;
    double **v, a;         // pointer to the vector

    //selecciona un vector de vectores
    v = (double**) malloc(n * sizeof(double*));

    if (v == NULL) {
        printf ("** Error en seleccionar memoria: sin memoria **");
        return (NULL);
    }

    //selecciona cada linea de la matriz
    for (i = 0; i < n; i++) {
        v[i] = (double*) malloc(m * sizeof(double));

        if (v[i] == NULL) {
            printf ("** Error: Memoria insuficiente **");
            limpiaMatriz(v, n);
            return (NULL);
        }

        // llena la matriz con ceros
        if (random == 0) {
            for (j = 0; j < m; j++)
                v[i][j] = 0.0;
        }

        // llena la matriz con numeros aleatorios entre 0 y 10
        else {
            if (random == 1) {
                for (j = 0; j < m; j++) {
                    v[i][j] = (rand() % 10)+1;
                }
            }
        }
    }

    return (v);     // regresa el vector
}

/*------------------------------------------------------------------------------*/
// Esta funcion limpia la matriz
double **limpiaMatriz(double **v, int tam) {

    int i;

    if (v == NULL) {
        return (NULL);
    }

    for (i = 0; i < tam; i++) { 
        if (v[i]) { 
            free(v[i]); // libera la fila de la matriz
            v[i] = NULL;
        } 
    } 

    free(v);         // libera el apuntador
    v = NULL;

    return (NULL);   //regresa null
}

