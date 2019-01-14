#include <stdio.h>
#include <stdlib.h>
/*
Scrivere una funzione che, dato un array di interi e la sua lunghezza, lo
ordini utilizzando l’algoritmo Selection Sort.
Scrivere un programma che utilizzi la funzione per ordinare un array di
N interi letti da input e stampi in output gli elementi dell’array ordinato.
La prima riga dell’input contiene la dimensione N dell’array. Le righe
successive contengono gli elementi dell’array, uno per riga.
L’output contiene gli elementi dell’array ordinato, uno per riga.
 */

void readArray(int *a,int dim){
	for (int i = 0; i < dim; i++)scanf("%d",&a[i]);
}

void printArray(int *a,int dim){
	for (int i = 0; i < dim; i++)printf("%d\n",a[i]);
}

void swap(int * a,int * b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void insertionSort_Int(int *a,int n){
    int key=0,j=0;
    for(int i=1;i<n;i++){
        key = a[i];
        j = i-1;
        while(j>=0 && key < a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main(void) {
	int n1=0;
	int *a1;

	scanf("%d",&n1);
	a1 = malloc(sizeof(int)*n1);
	readArray(a1,n1);
	insertionSort_Int(a1,n1);
	printArray(a1,n1);

	free(a1);


	return EXIT_SUCCESS;
}
