#include <stdio.h>
#define DIM 5

void readIntValues(int * a,int dim){
    for(int i=0;i<dim;i++){
        scanf("%d",&a[i]);
    }
}

void print(int * a,int dim){
    printf("[");
    for(int i=0;i<dim;i++){
        printf("%d",a[i]);
        if(i!=dim-1)printf(",");
    }
    printf("]\n");
}

void sum(int * a, int * b, int * sum, int dim){
    printf("[");
    for(int i=0;i<dim;i++){
		sum[i] = a[i] + b[i];
    }
    printf("]\n");
}

int main(void){
    int a[DIM],b[DIM], sum[DIM];
    
    readIntValues(a,DIM);
    readIntValues(b,DIM);
    sum(a,b,DIM);
    
    print(a, DIM);
    print(b, DIM);
    print(sum, DIM);
    
    return 0;
    
}
