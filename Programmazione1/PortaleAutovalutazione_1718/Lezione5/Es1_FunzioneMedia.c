#include <stdio.h>
#define DIM 10

void readIntValues(float * a,int dim){
    for(int i=0;i<dim;i++){
        scanf("%f",&a[i]);
    }
}

float media(float * a,int dim){
    int count = 0;
    float med = 0;
    for(int i=0;i<dim;i++){
        //Count for average if != 0 and if has the same sign of the last element
		if(a[i]!=0 && (a[i]*a[dim-1] > 0)){
			med+=a[i];
			count++;
		}
    }
    
    return med/count;

}

int main(void){
    float a[DIM];
    
    readIntValues(a,DIM);
    
    printf("%.2f",media(a,DIM));
    
    return 0;
    
}
