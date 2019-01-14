/*
 ============================================================================
 Name        : 4.c
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
	for (int i = 0; i < dim; i++) printf("%d\n",a[i]);
}
/*
Scrivere un programma che accetti in input due array ordinati di interi
e restituisca in output l’unione ordinata dei due array. Si assuma che la
lunghezza di ogni array sia fornita prima dell’immissione degli elementi.
Per semplicit`a si assuma che l’intersezione tra i due array sia vuota
(non hanno elementi in comune).
 */
int * unionArrays(int *a1,int d1,int *a2,int d2){
	int i=0,k=0,j=0;
	int *res = NULL;
	res = malloc(sizeof(int)*(d1+d2));
	//Insert the elements in the new array
	for (i = 0; i < d1+d2 && k<d1 && j<d2; i++) {
		if(a1[k]==a2[j]){
			res[i]=a1[k];
			k++;
			j++;
		}else{
			if(a1[k]<a2[j]){
				res[i]=a1[k];
				k++;
			}
			else{//a1[k]>a2[j]
				res[i]=a2[j];
				j++;
			}
		}
	}
	//Check if all elements have been processed in both arrays
	while(k<d1)res[i++]=a1[k++];
	while(j<d2)res[i++]=a2[j++];

	return res;
}

int main(void) {
	int n1=0,n2=0;
	int * a1;
	int * a2;
	int * res;

	scanf("%d",&n1);
	a1 = malloc(sizeof(int)*n1);
	readArray(a1,n1);

	scanf("%d",&n2);
	a2 = malloc(sizeof(int)*n2);
	readArray(a2,n2);

	res = unionArrays(a1,n1,a2,n2);
	printArray(res,n1+n2);

	free(a1);
	free(a2);
	free(res);

	return EXIT_SUCCESS;
}
