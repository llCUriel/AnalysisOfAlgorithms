/*
INSTITUTO POLIT�CNICO NACIONAL
ESCUELA SUPERIOR DE C�MPUTO
AN�LISIS DE ALGORITMOS
GRUPO: 3CV1
ALUMNOS: HERN�NDEZ CASTELLANOS C�SAR URIEL
        AGUILAR GARCIA MAURICIO

PROFESOR: DR. BENJAM�N LUNA BENOSO
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
	int n,res=0,k=0;
	cin>>n;
	//Forma iterativa de conseguir la suma de n cubos
	for(int i=n;i!=0;i--){
		k++;
		res+=(i*i*i);k++;
		
	}
	cout<<k<<"\n";
	cout<<res;
	cout<<"      Seguir? 0=NO";
	cin>>seguir;
	}while(seguir!=0);
}



