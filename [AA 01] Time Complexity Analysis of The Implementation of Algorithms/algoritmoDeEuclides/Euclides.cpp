/*
INSTITUTO POLITÉCNICO NACIONAL
ESCUELA SUPERIOR DE CÓMPUTO
ANÁLISIS DE ALGORITMOS
GRUPO: 3CV1
ALUMNOS: HERNÁNDEZ CASTELLANOS CÉSAR URIEL
        AGUILAR GARCIA MAURICIO

PROFESOR: DR. BENJAMÍN LUNA BENOSO
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
ALGORITMO DE EUCLIDES

 FECHA: 28/08/2018
*/

//Librerias
#include <bits/stdc++.h>
using namespace std;

// Prototipo de la función Euclides
int Euclides(int m, int r, int n, int k);


// Función principal encargada de obtener los valores del teclado y pasarlos como parámetros a la función Euclides, además de calcular el número de pasos que se realizaron.
int main(){
	int n,r,m,k=0,h=0,time;
	do{
	k=0;
	cout<<"Ingresa el primer valor: ";
	cin>>m;
	cout<<"Ingresa el segundo valor: ";
	cin>>n;
	time = Euclides(m,r,n,k);

	cout<<"Tiempo: "<<time<<"\n";
	cout<<"Seguir: ";
	cin>>h;
	}while(h==0);
}

// Implementación del algoritmo de euclides.
int Euclides(int m, int r, int n, int k){
		while(n!=0){
		k++;
		r=m%n;k++;
		m=n;k++;
		n=r;k++;
	}
		cout<<"MCD: "<<m<<"\n";
	return k;
}


