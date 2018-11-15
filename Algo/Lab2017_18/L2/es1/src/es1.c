/*
 ============================================================================
 Name        : es1.c
 Author      : Andrea Del Corto
 Version     :
 Copyright   : none
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define DIM 10//Numero elementi

//Prototypes
int* FinDVal(int *a,int dim, int v);
void readArray(int *a,int dim);
void printArray(int *a,int dim);
//Implementations
int* FinDVal(int *a,int dim, int v){
	int *p = NULL;
	int i=0;
	while(p==NULL && i<dim){
		if(a[i] == v)p = a + i;
		else i++;
	}
	return p;
}

void printArray(int *a,int dim){
	for (int i = 0; i < dim; i++) printf("%d\n",a[i]);
}

void readArray(int *a,int dim){
	for (int i = 0; i < dim; i++) scanf("%d",&a[i]);
}

int main(void) {
	int a[DIM];
	int val;

	readArray(a,DIM);
	scanf("%d",&val);
	printf("%s",FinDVal(a,DIM,val)==NULL?"non trovato":"trovato");

	return EXIT_SUCCESS;
}
