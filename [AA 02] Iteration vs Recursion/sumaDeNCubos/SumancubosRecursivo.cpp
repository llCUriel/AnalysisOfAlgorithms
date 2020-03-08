/*
INSTITUTO POLITÉCNICO NACIONAL
ESCUELA SUPERIOR DE CÓMPUTO
ANÁLISIS DE ALGORITMOS
GRUPO: 3CV1
ALUMNOS: HERNÁNDEZ CASTELLANOS CÉSAR URIEL
        AGUILAR GARCIA MAURICIO

PROFESOR: DR. BENJAMÍN LUNA BENOSO
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
PROGRAMA ENCARGADO DE CONSEGUIR LA SUMA DE N CUBOS

 FECHA: 05/09/2018
*/

#include <bits/stdc++.h>
using namespace std;

int Sumancubos(int n, int k);

int main(){
	int seguir;
	do{
	int n,res,k=0;
	cin>>n;
	//LLAMADA A LA FUNCION RECURSIVA
	res = Sumancubos(n,k);
	cout<<res;
	cout<<"      Seguir? 0=NO";
	cin>>seguir;
	}while(seguir!=0);
}


//FUNCION RECURSIVA DE LA SUMA DE CUBOS
int Sumancubos(int n, int k){
		if(n==1){
			cout<<k<<"\n";
			return 1;
			}
		else{
			k++;
			return Sumancubos(n-1,k)+n*n*n;
			
		}
		
}

