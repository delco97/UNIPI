#include <stdio.h>
#define DIM 7

void readIntValues(int * a,int dim){
    for(int i=0;i<dim;i++){
        scanf("%d",&a[i]);
    }
}

void primoultimopari(int arr[], int dim, int* primaocc,int* ultimaocc){
    //Con un solo ciclo scorro contemporaneamente prima e seconda metà dell'array
    for(int i=0;i<dim/2;i++){
        if( *primaocc == -1 && (*(arr+i) % 2) == 0)*primaocc = i;
        if( *ultimaocc==-1 && (*(arr+dim-1-i) % 2) == 0 )*ultimaocc = (dim-1) - i;
    }
    //Se c'è un solo elemnto pari, ma sio trova nella seconda metà
    if (*primaocc == -1 && *ultimaocc != -1) *primaocc = *ultimaocc;
}


int main(void){
    int a[DIM];
    int prima_occ = -1,sec_occ = -1;
    
	readIntValues(a,DIM);
	primoultimopari(a,DIM,&prima_occ,&sec_occ);
    
    printf("%d %d\n",prima_occ,sec_occ);
    
    return 0;
    
}
