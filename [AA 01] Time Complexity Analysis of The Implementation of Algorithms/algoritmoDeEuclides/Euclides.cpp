/*
INSTITUTO POLIT�CNICO NACIONAL
ESCUELA SUPERIOR DE C�MPUTO
AN�LISIS DE ALGORITMOS
GRUPO: 3CV1
ALUMNOS: HERN�NDEZ CASTELLANOS C�SAR URIEL
        AGUILAR GARCIA MAURICIO

PROFESOR: DR. BENJAM�N LUNA BENOSO
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
ALGORITMO DE EUCLIDES

 FECHA: 28/08/2018
*/

//Librerias
#include <bits/stdc++.h>
using namespace std;

// Prototipo de la funci�n Euclides
int Euclides(int m, int r, int n, int k);


// Funci�n principal encargada de obtener los valores del teclado y pasarlos como par�metros a la funci�n Euclides, adem�s de calcular el n�mero de pasos que se realizaron.
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

// Implementaci�n del algoritmo de euclides.
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


