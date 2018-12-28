#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 101

/*
Scrivere una funzione che, dato un array di interi e la sua lunghezza, lo
ordini utilizzando l’algoritmo Selection Sort.
Scrivere un programma che utilizzi la funzione per ordinare un array di
N interi letti da input e stampi in output gli elementi dell’array ordinato.
La prima riga dell’input contiene la dimensione N dell’array. Le righe
successive contengono gli elementi dell’array, uno per riga.
L’output contiene gli elementi dell’array ordinato, uno per riga.
 */

void printStrings(char **a,int dim){
	for (int i = 0; i < dim; i++)printf("%s\n",a[i]);
}

int findMissing(int * a,int sx,int dx,int n){
  if(sx > dx)return n; //Base case empty subarray
  if(sx == dx){//Base case: 1 element
    if(a[sx] - 1  == sx)return sx + 1;
    else return sx;
  }else{//Divide
    int cx = (sx+dx)/2;
    if(a[sx] - 1 == sx)return findMissing(a,cx + 1,dx, n);
    else return findMissing(a,sx,cx, n);
  }
}

int main(void) {
	int n1=0;
	int * a1;

    //printf("**** ARRAY OF STRING ****\n ");
	//printf("Number of strings: ");
	scanf("%d",&n1);
	if(n1 <= 0){
        printf("The array must be made at least of one element");
	}else{//Good size
        a1 = (int *) malloc(sizeof(int) * n1);
        if(a1==NULL)printf("A problem occurred during memory allocation (1) ");
        else{
            for(int i=0;i<n1;i++)scanf("%d",&a1[i]);

            printf("Missing number: %d\n",findMissing(a1,0,n1-1,n1));

            free(a1);
        }
    }
}
