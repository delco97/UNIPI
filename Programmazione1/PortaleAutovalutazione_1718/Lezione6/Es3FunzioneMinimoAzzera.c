#include <stdio.h>
#define DIM 10

void readIntValues(int * a,int dim){
    for(int i=0;i<dim;i++){
        scanf("%d",&a[i]);
    }
}

void min_azzera(int * a,int dim){
	int *p = a;
	int min = *p;
	for(int i=0; p < a + dim; p++, i++){
	  if(*p < min)min = *p;
	  if (i%2 != 0) *p = 0; //Azzero elementi in posizione non pari (dispari)
	  printf("%d\n",*p);
	}
	printf("%d",min);
}

int main(void){
    int a[DIM];
    
    readIntValues(a,DIM);
    min_azzera(a,DIM);
    
    return 0;
    
}
