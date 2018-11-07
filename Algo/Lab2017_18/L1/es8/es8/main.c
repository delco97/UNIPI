//
//  main.c
//  es8
//
//  Created by Andrea Del Corto on 07/11/2018.
//  Copyright © 2018 Andrea Del Corto. All rights reserved.
//

#include <stdio.h>
#define DIM 10

void readArray(int *a,int dim){
    for(int i=0;i<dim;i++){
        scanf("%d",&a[i]);
    }
}

void minmax(int *a,int dim,int *min,int *max){
    if(dim<=0){
        *min = -1;
        *max = -1;
    }else{
        *min = 0;
        *max = 0;
        for(int i=1;i<dim;i++){
            if(a[i]>a[*max])*max = i;
            if(a[i]<a[*min])*min = i;
        }
    }
}


int main(int argc, const char * argv[]) {
    int a[DIM];
    int min=-1,max=-1;
    readArray(a,DIM);
    minmax(a,DIM,&min,&max);
    if(min==-1 || max==-1){
        printf("Impossibile individuare elementi min e max");
    }else{
        printf("%d\n%d\n%d\n%d\n",min,a[min],max,a[max]);
    }
    return 0;
}
