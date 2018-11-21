#include <stdio.h>
#define DIM 3

void readIntValues(int * a,int dim){
    for(int i=0;i<dim;i++){
        scanf("%d",&a[i]);
    }
}


int getMin(int a[], int dim){
	int min = *a;
	for(int i=0;i<dim;i++){
		if(*(a + i)<min)min = *(a + i);
	}
	return min;
}

int check(int a[], int b[], int dim){
    int trovato = 0;
    int i = 0;
    int min_b = getMin(b,dim);
    
	while(trovato == 0 && i<dim){
		if(*(a+i) < min_b)trovato = 1; //Elemento di a minore dell'elemento minimo di b => trovato!
		else i++;//continua ricerca
	}
    
    return trovato;
}


int main(void){
    int a[DIM], b[DIM];
    
	readIntValues(a,DIM);
	readIntValues(b,DIM);
	if (check(a,b,DIM)) printf("TRUE\n");
    else printf("FALSE\n");
    
    
    return 0;
    
}
