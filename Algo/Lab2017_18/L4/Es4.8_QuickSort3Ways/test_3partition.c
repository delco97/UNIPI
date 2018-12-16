#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

int goodPartition(int a[], int sx, int px, int dx, int *pn) {
    int pivot = a[px];
    int i = sx - 1, j, tmp;
    tmp = a[dx];
    a[dx] = a[px];
    a[px] = tmp;
    px = dx;
    *pn = 1;

    for (j = sx; j < dx; j++) {
        if(a[j] == pivot) *pn++;
        if (a[j] <= pivot) {
            i++;
            tmp = a[j];
            a[j] = a[i];
            a[i] = tmp;
        }
    }
    i++;
    tmp = a[i];
    a[i] = pivot;
    a[px] = tmp;
    return i;
}

int Mypartition3(int a[], int sx, int px, int dx, int *np) {
    int i = sx - 1;
    int k = 0;
    int j;

    swap(&a[px],&a[dx]); //pivot in the rightmost position

    for(j= sx;j <= (dx-1);j++){
        if(a[j] == a[dx]){
          k++;
          swap(&a[i+k],&a[j]);//Move a[j] in area 2
        }else{
          if(a[j] < a[dx]){
            i++;
            swap(&a[i+k],&a[j]);//Move a[j] in area 1            
            swap(&a[i],&a[i+k]);//Move the current a[i] in area 2
          }
        }
        /*Debug
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

/* Lettura di un array di interi da input.
Il primo elemento � la lunghezza dell'array */
int legge(int **a, int n) {

  int i;
  if(n <= 0) return 1;

  *a = (int *) malloc(n * sizeof(int));
  if(*a == NULL) return 1;

  for( i = 0; i < n; i++ ){
	  scanf("%d", (*a)+i);
  }

  return 0;

}

void Myquicksort( int a[], int sx, int dx ) {

  int perno, pivot, np;
  if( sx < dx ) {
    /* DA IMPLEMENTARE: scelta del pivot. Scegliere una posizione a caso tra sx e dx inclusi. */
    //pivot = (rand() % (dx - sx + 1)) + sx; //num = Random[lower;upper]
    pivot = dx;
    perno = Mypartition3(a, sx, pivot, dx, &np);
    /* Ordina ricorsivamente le parte con gli elementi minori del pivot e quella con gli elmenti magiori del pivot.
    Quella che cotine gli elementi uguali al pivot non ha bisogno di essere ordinata. */
    Myquicksort(a, sx, perno - 1);
    Myquicksort(a, perno+1, dx);
  }

}

void Goodquicksort(int a[], int sx, int dx) {

    int perno, pivot, pn;
    if (sx < dx) {
        /* DA IMPLEMENTARE: scelta del pivot. Scegliere una posizione a caso tra sx e dx inclusi. */
        //pivot = (rand() % (dx - sx + 1)) + sx;
        pivot = dx;
        perno = goodPartition(a, sx, pivot, dx, &pn); /* separa gli elementi minori di a[pivot]
                                                 da quelli maggiori o uguali */
                                                 /* Ordina ricorsivamente le due metà */
        Goodquicksort(a, sx, perno - pn);
        Goodquicksort(a, perno + 1, dx);

    }

}

int * intdup(int const * src, size_t len)
{
   int * p = malloc(len * sizeof(int));
   memcpy(p, src, len * sizeof(int));
   return p;
}

int isEqual(int *a,int *b,int n ){
  int res = 1;
  int i=0;
  while(i<n && res==1){
      if(a[i] != b[i])res = 0;
      else i++;
  }
  return res;
}

int main() {

  int n, *A,*A1,*A2,perno1=-1,np1=-1,perno2=-1,np2=-1, nComb=0,err=0,i;
  scanf("%d",&nComb);
  scanf("%d",&n);
  i=nComb;
  while(i>0){
    A = (int *) malloc(n * sizeof(int));
    A1 = (int *) malloc(n * sizeof(int));
    A2 = (int *) malloc(n * sizeof(int));
    if(A == NULL || A1 == NULL || A2 == NULL) return 1;
    for(int i = 0; i < n; i++ ){
  	  scanf("%d", &A[i]);
      A1[i] = A[i];
      A2[i] = A[i];
    }

    srand(time(NULL));
    //********MY CODE********
    //perno1 = Mypartition3(A1, 0, n-1, n-1,&np1);
    Myquicksort(A1, 0, n - 1);
    ////********GOOD CODE********
    //perno2 = goodPartition(A2, 0, n-1, n-1,&np2);
    Goodquicksort(A2, 0, n - 1);
    if(isEqual(A1,A2,n)!=1){// Stampa gli array se sono diversi
      err++;
      printf("\nArray that has produced a different result: ");
      printArray(A,n);
      printf("\n");
      
      printf("  My code: ");
      printArray(A1,n);
      //printf("  (perno = %d  ;  np = %d)\n",perno1,np1);
      
      printf("  Good code: ");
      printArray(A2,n);
      //printf("  (perno = %d  ;  np = %d)\n",perno2,np2);
    }
    free(A);
    free(A1);
    free(A2);
    i--;
  }
  printf("Errori: %d/%d",err,nComb);

  return 0;
}
