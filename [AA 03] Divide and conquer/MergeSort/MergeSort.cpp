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

 FECHA: 12/09/2018
*/


#include <bits/stdc++.h>
using namespace std;

#define MAX 10
int cont = 0;

void Merge(int A[],int p, int q, int r);
void MergeSort(int A[],int p,int r);

//Main que pobla los arreglos los cuales serán ordenados
//Así mismo ingresa la salida a el archivo out.txt

int main(){
	ofstream al;
	al.open("out.txt");
	srand (time(NULL));
 for(int NUM = 1;NUM<=MAX;NUM++){
	 
	 int n=pow(2,NUM);
	 int *A = new int[n];   
	 for(int i=0;i<n;i++){
 		A[i] = (rand() % 50)+1;
		}
		
	 cont = 0;
	 MergeSort(A,0,n-1);
	 al << n << ": " << cont << '\n';
	}
	al.close();
	return 0;
}

//Algoritmo MergeSort implementado

void MergeSort(int A[],int p,int r){
	int q;
	cont++;
	if(p<r){
		q=(p+r)/2;
		MergeSort(A,p,q);
		MergeSort(A,q+1,r);
		Merge(A,p,q,r);
	}
}

//Algoritmo Merge implementado

void Merge(int A[],int p, int q, int r){
	int n1 = q-p+1;
	int n2 = r-q;
	int L[n1],R[n2],i,j;
	for(i=0; i<n1; i++){
		L[i] = A[p+i];
	}	
	for(j=0; j<n2; j++)
		R[j] = A[q+1+j];
	i=0;
	j=0;
	for(int k=p; k<=r; k++ ){
		cont++;
		if(L[i]<=R[j]){
			A[k]=L[i];
			i++;
		}else{
			A[k]=R[j];
			j++;
		}
	}
}
