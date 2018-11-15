/*
 ============================================================================
 Name        : es2.c
 Author      : Andrea Del Corto
 Version     :
 Copyright   : none
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define DIM 10

void reset(int a[], int len, int set); //inizializza l’array dei contatori a set;
void add(int a[], int len, int val); //incrementa il contatore array[val] se val `e tra 0 e len-1.
void printArray(int *q,int dim);//Print array

void reset(int a[], int len, int set){
	for (int i = 0; i < len; i++) *(a+i) = set;
}

void add(int a[], int len, int val){
	if(val>=0 && val<len)a[val]++;
}

void printArray(int *a,int dim){
	for (int i = 0; i < dim; i++) {
		printf("%d\n",a[i]);
	}
}

int main(void) {
	int counters[DIM];
	int x=0;

	reset(counters,DIM,0);
	do{
		scanf("%d",&x);
		if(x!=-1)add(counters,DIM,x);
	}while(x!=-1);
	printArray(counters,DIM);

	return EXIT_SUCCESS;
}
