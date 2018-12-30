#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/*
  !!!!!!!!!!!! D A  F A R E !!!!!!!!!!!!
  sx e dx sono le posizioni del primo e dell'ultimo elemento dell'array mentre
  px � la posizione dell'elemento perno.
  La funzione deve restituire la posizione del perno dopo che gli elementi sono
  stati partizionati.
*/

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int distribuzione(int a[], int sx, int px, int dx) {
    int i = sx - 1;
    int j;

    swap(&a[px],&a[dx]); //pivot in the rightmost position

    for(j=sx;j<=dx-1;j++){
        if(a[j] <= a[dx]){//a[j] needs to stay in area 1
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[dx]); //pivot in the position immediately after the biggest item of area 1
    return i+1;
}

void quicksort( int a[], int sx, int dx ) {

  int perno, pivot;
  if( sx < dx ) {
    /* DA IMPLEMENTARE: scelta del pivot. Scegliere una posizione a caso tra sx e dx inclusi. */
    //srand(time(0));
    //num = (rand() % (upper � lower + 1)) + lower
    //num = Random[lower;upper]
    pivot = (rand() % (dx - sx + 1)) + sx;

    perno = distribuzione(a, sx, pivot, dx);
    /* Ordina ricorsivamente le due met� */
    quicksort(a, sx, perno-1);
    quicksort(a, perno+1, dx);
  }

}

int distribuzioneEvenOdd(int a[], int sx, int dx) {
    int i = sx - 1;
    int j;

    for(j=sx;j<=dx;j++){
        if((a[j] % 2) == 0){//a[j] needs to stay in area 1 (even numbers)
            i++;
            swap(&a[i],&a[j]);
        }
    }
    return i+1;
}

void quicksortStrange( int a[], int sx, int dx ){
  int perno;
  if( sx < dx ) {

    perno = distribuzioneEvenOdd(a, sx, dx);
    /* Ordina ricorsivamente le due met� */
    quicksort(a, sx, perno-1);
    quicksort(a, perno, dx);
  }
}

/* Lettura di un array di interi da input.
Il primo elemento � la lunghezza dell'array */
int legge(int **a, int *len) {

  int i;
  scanf("%d", len);
  if(*len <= 0) return 1;

  *a = (int *) malloc(*len * sizeof(int));
  if(*a == NULL) return 1;

  for( i = 0; i < *len; i++ )
	  scanf("%d", (*a)+i);

  return 0;

}

int main() {

  int i, n, *A;

  if( legge(&A, &n)) return 1;

  srand(time(NULL));
  quicksortStrange(A, 0, n-1);

  /* Stampa l'array ordinato */
  for( i = 0; i < n; i++ )
    printf("%d ", A[i]);

  return 0;
}
