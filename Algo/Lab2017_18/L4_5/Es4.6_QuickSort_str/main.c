#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

void swap(char **a, char **b) {
  char *temp = *a;
  *a = *b;
  *b = temp;
}

int distribuzione(char ** a, int sx, int px, int dx) {
    int i = sx - 1;
    int j;

    swap(&a[px],&a[dx]); //pivot in the rightmost position

    for(j=sx;j<=dx-1;j++){
        if(strcmp(a[j],a[dx]) <= 0){//a[j]<=a[dx]: needs to stay in area 1
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[dx]); //pivot in the position immediately after the biggest item of area 1
    return i+1;
}

void quicksort( char ** a, int sx, int dx ) {

  int perno, pivot;
  if( sx < dx ) {
    /* DA IMPLEMENTARE: scelta del pivot. Scegliere una posizione a caso tra sx e dx inclusi. */
    srand(time(0));
    //num = (rand() % (upper � lower + 1)) + lower
    //num = Random[lower;upper]
    pivot = (rand() % (dx - sx + 1)) + sx;

    perno = distribuzione(a, sx, pivot, dx); /* separa gli elementi minori di a[pivot]
                                                da quelli maggiori o uguali */
    /* Ordina ricorsivamente le due met� */
    quicksort(a, sx, perno-1);
    quicksort(a, perno+1, dx);

  }

}

int main(void) {
	int n=0;
	char ** a;

    //printf("**** ARRAY OF STRING ****\n ");
	//printf("Number of strings: ");
	scanf("%d",&n);
	if(n <= 0){
        printf("The array must be made at least of one element");
	}else{//Good size
        a = (char **) malloc(sizeof(char *) * n);
        if(a==NULL)printf("A problem occurred during memory allocation (1) ");
        else{
            //Read strings
            for(int i=0;i<n;i++){
                a[i] = (char *)malloc(sizeof(char) * MAX_STR);
                if(a[i]==NULL)printf("A problem occurred during memory allocation (2).\nWill be impossible to get the %d ° string.",i+1);
                else{
                    //printf("String %d on %d:\n",i+1,n);
                    scanf("%s",a[i]);
                }
            }

            srand(time(NULL));
            quicksort(a, 0, n-1);
            printStrings(a,n);

            //Deallocation of strings
            for(int i=0;i<n;i++){
                if(a[i]!=NULL)free(a[i]);
            }

            free(a);
        }
    }
    return 0;
}
