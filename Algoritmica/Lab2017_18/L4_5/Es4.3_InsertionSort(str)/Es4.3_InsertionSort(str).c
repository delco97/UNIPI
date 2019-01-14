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

void insertionSort_Str(char ** a,int n){
    char * key;
    int j=0;
    for(int i=1;i<n;i++){
        key = a[i];
        j = i-1;
        while(j>=0 && strcmp(a[j],key)>0){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main(void) {
	int n1=0;
	char ** a1;

    //printf("**** ARRAY OF STRING ****\n ");
	//printf("Number of strings: ");
	scanf("%d",&n1);
	if(n1 <= 0){
        printf("The array must be made at least of one element");
	}else{//Good size
        a1 = (char **) malloc(sizeof(char *) * n1);
        if(a1==NULL)printf("A problem occurred during memory allocation (1) ");
        else{
            for(int i=0;i<n1;i++){
                a1[i] = (char *)malloc(sizeof(char) * MAX_STR);
                if(a1[i]==NULL)printf("A problem occurred during memory allocation (2).\nWill be impossible to get the %d ° string.",i+1);
                else{
                    //printf("String %d on %d:\n",i+1,n1);
                    scanf("%s",a1[i]);
                }
            }


            //printf("Inserted strings:\n");
            insertionSort_Str(a1,n1);
            printStrings(a1,n1);

            //Deallocation of strings
            for(int i=0;i<n1;i++){
                if(a1[i]!=NULL)free(a1[i]);
            }

            free(a1);
        }
    }
}
