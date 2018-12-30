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

void printArray(int *a,int n){
  for( int i = 0; i < n; i++ )
    printf("%d ", a[i]);
}

int partition_old(int a[], int sx, int px, int dx) {
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

int partition3(int a[], int sx, int px, int dx, int *np) {
      int i = sx - 1;
      int k = 0;
      int j;

      swap(&a[px],&a[dx]); //move pivot in the rightmost position: pivot = a[dx]
      /*
      area 1:  all elements smaller then pivot
      area 2:  all elements equals to pivot
      area 3:  all unkown elements
      */
      for(j= sx;j < dx;j++){//Loop all elements in a[sx;dx) in order to move them in the correct area
          if(a[j] == a[dx]){//a[j] must stay in area 2
            k++;//increas area 2 that overflows in area 3
            swap(&a[j],&a[i+k]);//Move a[j] in area 2
          }else{
            if(a[j] < a[dx]){//a[j] must stay in area 1
              i++;//increase area 1 that overflows area 2
              swap(&a[j],&a[i+k]);//Move a[j] at the end of area 2            
              swap(&a[i+k],&a[i]);//Move a[j], that currently is in position i+k, at the end of area 1
            }
          }
          /*
          //***Debug***
          printf("j = %d: ",j);
          printArray(a,dx-sx+1);
          printf("\n");
          */
      }
      k++;
      swap(&a[i+k],&a[dx]); //pivot in the position immediately after the biggest item of area 1
      *np = k; //Number of items equal to pivot
      return i + k;
}

void quicksort( int a[], int sx, int dx ) {

  int perno, pivot, np;
  if( sx < dx ) {
    /* DA IMPLEMENTARE: scelta del pivot. Scegliere una posizione a caso tra sx e dx inclusi. */
    pivot = (rand() % (dx - sx + 1)) + sx; //num = Random[lower;upper]
    //pivot = dx;
    perno = partition3(a, sx, pivot, dx, &np);
    /* Ordina ricorsivamente le parte con gli elementi minori del pivot e quella con gli elmenti magiori del pivot.
    Quella che cotine gli elementi uguali al pivot non ha bisogno di essere ordinata. */
    quicksort(a, sx, perno - np);
    quicksort(a, perno+1, dx);
  }

}
/* Lettura di un array di interi da input.
Il primo elemento è la lunghezza dell'array */
int legge(int **a, int *len) {

    int i;
    scanf("%d", len);
    if (*len <= 0) return 1;

    *a = (int *)malloc(*len * sizeof(int));
    if (*a == NULL) return 1;

    for (i = 0; i < *len; i++)
        scanf("%d", (*a) + i);

    return 0;

}

int main() {

    int i, n, *A;

    if (legge(&A, &n)) return 1;

    srand(time(NULL));
    quicksort(A, 0, n - 1);

    /* Stampa l'array ordinato */
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}