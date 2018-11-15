#include <stdio.h>
#define DIM 5

void readIntValues(int * a,int dim){
    for(int i=0;i<dim;i++){
        scanf("%d",&a[i]);
    }
}

int count_larger(int x, int *a,int dim){
    int counter = 0;
    for(int i=0;i<dim;i++){
        if(a[i]>x)counter++;
    }
    return counter;
}


int main(void){
    int x, a[DIM];
    
    scanf("%d",&x);
    readIntValues(a, DIM);
    
    printf("%d",count_larger(x,a,DIM));
    
    return 0;
    
}
