/*
 ============================================================================
 Name        : 3.c
 Author      : Andrea Del Corto
 Version     :
 Copyright   : none
 Description : Hello World in C, Ansi-style
 ============================================================================
 */



#include <stdio.h>
#include <stdlib.h>

void readArray(int *a,int dim){
	for (int i = 0; i < dim; i++) scanf("%d",&a[i]);
}

void printArray(int *a,int dim){
	for (int i = 0; i < dim; i++) printf("%d ",a[i]);
}

int maxSumSub(int *a,int dim){
	int max_sum=0,sum=0;

	for(int i=0;i<dim;i++){
		sum = 0;
		for(int j=i;j<dim;j++){
			sum+=a[j];
			if(sum>max_sum)max_sum = sum;
		}
	}
	return max_sum;
}

//Soluzione proposta sul portale.
//NON MI TORNA QUESTA SOLUZIONE: se a contiene solo numeri negativi questo algoritmo non è corretto.
//Per funzionare in modo corretto dovrebbe sempre esserci almeno un elemento positivo in a.
int maxSumSub2(int *a,int dim){
	int max_sum=a[0],sum=0;

	for(int i=0;i<dim;i++){
		if(sum>0)sum+=a[i];
		else sum=a[i];
		if(sum>max_sum)max_sum = sum;
	}
	return max_sum;
}

int main(void) {
	int n1=0;
	int * a1;

	scanf("%d",&n1);
	a1 = malloc(sizeof(int)*n1);
	readArray(a1,n1);

	printf("%d\n",maxSumSub(a1,n1));

	free(a1);

	return EXIT_SUCCESS;
}
