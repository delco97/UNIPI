//
//  main.c
//  es4
//
//  Created by Andrea Del Corto on 06/11/2018.
//  Copyright © 2018 Andrea Del Corto. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_DIM 10000

void readArray(int * a, int dim){
    for(int i=0;i<dim;i++)scanf("%d",&a[i]);
}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverseArray(int * a, int dim){
    if(a!=NULL){
        int i=0,j=dim-1;
        while(i<(dim/2)){
            swap(&a[i],&a[j]);
            i++;
            j--;
        }
    }
}

void printArray(int * a, int dim){
    for(int i=0;i<dim;i++)printf("%d\n",a[i]);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int dim=0;
    int * a = NULL;
    scanf("%d",&dim);
    if(dim>MAX_DIM)
        printf("Too much element to process. The biggest array that you can reverse is %d long",MAX_DIM);
    else{
        a = malloc(dim*sizeof(int));
        if(a==NULL){//Bad malloc -> not enough memory space
            printf("Malloc failed. Out of memory");
        }else{//Good malloc
            readArray(a,dim);
            reverseArray(a,dim);
            printArray(a,dim);
            free(a);
        }
    }
    return 0;
}
