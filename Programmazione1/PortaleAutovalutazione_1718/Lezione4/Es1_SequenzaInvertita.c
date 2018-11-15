/*
Scrivere un programma che legga da tastiera una sequenza di 10 interi, e
stampi la stessa sequenza con ordine invertito, dividendo per 2 gli elementi
pari della sequenza
*/

#include <stdio.h>
#define DIM 10

void readVect(int *a,int dim){
	for(int i=0;i<dim;i++)scanf("%d",&a[i]);
}

void printVectInv(int *a,int dim){
	for(int i=dim-1;i>=0;i--){
		if(a[i]%2 == 0)printf("%d\n",a[i]/2);
		else printf("%d\n",a[i]);
	}
}


int main(){
	int a[DIM];

	readVect(a,DIM);
	printVectInv(a,DIM);
	
	return 0;
	
}
