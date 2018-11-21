/*
 ============================================================================
 Name        : 2.c
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

int intersections(int *a1,int d1,int *a2,int d2){
	int count = 0,i=0,j=0;
	while(i<d1 && j<d2){
		if(a1[i]==a2[j]){count++;i++;j++;}
		else{
			if(a1[i]<a2[j])i++;
			else j++; //a1[i]>a2[j]
		}
	}
	return count;
}
//This function doesn't assume that a1 and a2 are ordered!
int intersections_OLD(int *a1,int d1,int *a2,int d2){
	int count = 0;
	for(int i=0;i<d1;i++){
		for(int j=0;j<d2;j++){
			if(a1[i]==a2[j])count++;
		}
	}
	return count;
}

int main(void) {
	int n1=0,n2=0;
	int * a1;
	int * a2;

	scanf("%d",&n1);
	a1 = malloc(sizeof(int)*n1);
	readArray(a1,n1);
//	printf("a1: ");
//	printArray(a1,n1);
//	printf("\n");

	scanf("%d",&n2);
	a2 = malloc(sizeof(int)*n2);
	readArray(a2,n2);

	printf("%d\n",intersections(a1,n1,a2,n2));

	free(a1);
	free(a2);

	return EXIT_SUCCESS;
}
