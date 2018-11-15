/*
Scrivere un programma che legga da tastiera 10 interi, li scriva in un array
A, e stampi l’indice i del primo elemento che verifica la seguente condizione:
A[i] = A[i + 1] − A[i − 1]
oppure stampi -1 nel caso in cui nessun elemento verifichi la suddetta condizione.
*/

#include <stdio.h>
#define DIM 10

void readVect(int *a,int dim){
	for(int i=0;i<dim;i++)scanf("%d",&a[i]);
}


int check(int *a,int dim){
	int ris = -1,i=1;
	
	while(i<dim-1 && ris==-1){
		if(a[i] == a[i+1] - a[i-1])ris = i;
		else i++;
	}
	
	return ris;
}


int main(){
	int a[DIM];
	readVect(a,DIM);
	printf("%d\n",check(a,DIM));
	return 0;
	
}
