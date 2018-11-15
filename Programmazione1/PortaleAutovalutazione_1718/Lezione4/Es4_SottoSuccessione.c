/*
Scrivere un programma che legga da tastiera una sequenza di 10 interi scrivendola
in un array, quindi stampi (uno per linea, e nello stesso ordine in cui
sono stati immessi) i valori della sequenza che rispettano una di queste due
propriet`a:
1. Siano positivi e pari, oppure
2. Siano negativi e succeduti da un valore positivo.
Note: lo zero `e considerato un valore positivo.
*/

#include <stdio.h>
#define DIM 10

void readVect(int *a,int dim){
	for(int i=0;i<dim;i++)scanf("%d",&a[i]);
}


void check(int *a,int dim){
	for(int i=0;i<dim;i++)
		if( (a[i]>=0 && a[i]%2==0) || (i!=dim-1 && a[i]<0 && a[i+1]>=0))printf("%d\n",a[i]);
}


int main(){
	int a[DIM];
	readVect(a,DIM);
	check(a,DIM);
	return 0;
	
}
