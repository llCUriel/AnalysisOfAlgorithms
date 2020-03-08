// Escuela Superior de CÛmputo

// An·lisis de Algoritmos

// Practica 8 MultiplicaciÛn Subsecuencia de matrices

//Aguilar Garcia Mauricio

//Hern·ndez Castellanos CÈsar Uriel

//ImplentaciÛn del algoritmo visto en clase

//para encontrar la optima subsecuencia de matrices 

#include <iostream>

#include <vector>

#include <stdio.h>

using namespace std;

//clase de tablas para facilitar el regreso de las tablas mas importantes

class tablas{
	
	public:

		long **m;

		long **s;

};


//Funcion para imprimir las dos tablas generadas en el algoritmo

void imprimirT(long **T, long i,long j);

// Funcion para imprimir los parentesis correctamente seg√∫n las tablas generadas

// esta funci√≥n es recursiva

void imprimeParenti(long ** s,long i, long j);

//Funcion para obtener la secuencia de matrices mas optima, se le manda un vector

//con los tama√±os de las matrices

tablas secuenciaMatrices(vector <long> P);

int main(){

	vector<long> p;
	int n;
	
	cin >> n;
	
	while(n--){
	
		int aux;
	
		cin >> aux;
	
		p.push_back(aux);
	
	}
	
	tablas resultado = secuenciaMatrices(p);
	
	imprimirT(resultado.s,p.size()-2,p.size()-1);
	
	cout << "-------------------------------------------";
	
	imprimirT(resultado.m,p.size()-1,p.size()-1);
	
	cout << "-------------------------------------------" << endl ;
	
	imprimeParenti(resultado.s,0,p.size()-2);
	
	cout << endl << "-----------------------------------";
	
	return 0;

}




void imprimirT(long **T, long i,long j){

	cout << endl;

	for(long x = 0; x < i; x++ ){

		for(long y = 0; y < j; y++){

			printf("%d\t\t",T[x][y]);

		}

		cout << endl;

	}

}


void imprimeParenti(long ** s,long i, long j){


	if(i == j)

		cout << "A" << i+1 << " ";

	else{

		cout << "(";

		imprimeParenti(s,i,s[i][j]);

		cout << " * ";

		imprimeParenti(s,s[i][j]+1,j);

		cout << ")";

	}

}


tablas secuenciaMatrices(vector <long> P){

	long n = P.size()-1;

	tablas tab;

	tab.m = (long **) calloc((n),sizeof(long *));

	for(long i = 0; i < n; i++)

		tab.m[i] = (long *) calloc((n),sizeof(long));

	tab.s = (long **) calloc((n),sizeof(long *));

	for(long i = 0; i < n; i++)

		tab.s[i] = (long *) calloc((n),sizeof(long));

	for(long l = 2; l <= n; l++){

		for(long i = 0; i+l-1 < n; i++){

			long j = i + l -1;

			tab.m[i][j] = LONG_MAX;

			for(long k = i; k < j; k++){

				long q = tab.m[i][k] + tab.m[k+1][j] + (P[i]*P[k+1]*P[j+1]) ;

				if(q < tab.m[i][j]){

					tab.m[i][j] = q;

					tab.s[i][j] = k;

				}

			}

		}

	}

	return tab;

}
