/*
 ============================================================================
 Name        : 1.c
 Author      : Andrea Del Corto
 Version     :
 Copyright   : none
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define DIM 5

void insertionSortNotIncreasing(int *a,int dim){
	int key,j;
	for(int i=1;i<dim;i++){
		key = a[i];
		j = i-1;
		while(j>=0 && a[j]<key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}

void readArray(int *a, int dim){
	for(int i=0;i<dim;i++)scanf("%d",&a[i]);
}

void printArray(int *a, int dim){
	for(int i=0;i<dim;i++)printf("%d\n",a[i]);
}

int main(void) {
	int *a;
	int n;
	printf("Numero elementi:\n");
	scanf("%d",&n);
	a = (int *) malloc(sizeof(int)*n);
	printf("Inserisci %d elementi da ordinare in ordine non crescente:\n",n); /* prints !!!Hello World!!! */
	readArray(a,n);
	insertionSortNotIncreasing(a,n);
	printArray(a,n);
	free(a);
	return EXIT_SUCCESS;
}
