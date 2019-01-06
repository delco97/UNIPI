//
//  main.c
//  Es7.3_AnagrammaPrincipale
//
//  Created by Andrea Del Corto on 06/01/19.
//  Copyright © 2019 Andrea Del Corto. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 20

int comapareChar(const void * a,const void * b){
    char c1 = *((char *)a);
    char c2 = *((char *)b);
    return c1 - c2;
}

void printStrings(char ** a,int n){
    for(int i=0;i<n;i++)printf("%s\n",a[i]);
}

void deallocationStrings(char ** a,int k){
    if(a!=NULL){
        for(int i=0;i<=k;i++)free(a[i]);
        free(a);
    }
}

char ** allocationStrings(int n,int max_char){
    char ** aux = NULL;
    aux = (char **)malloc(n * sizeof(char *));
    if(aux == NULL)printf("Bad allocation (1)");
    else{//Good allocation
        for (int i=0; i<n; i++) {
            aux[i] = (char *)malloc(max_char * sizeof(char *));
            if(aux[i] == NULL){
                printf("Bad allocation (2)");
                deallocationStrings(aux,i-1);
                aux = NULL;
                break;
            }
        }
    }
    return aux;
}

char ** readStrings(int * size){
    char ** aux = NULL;
    int n = 0;
    
    scanf("%d",&n);
    if(n<=0)printf("n must be greater then 0.");
    else{
        aux = allocationStrings(n,MAX_CHAR);
        if(aux != NULL)//Good allocation
            for(int i=0;i<n;i++)scanf("%s",aux[i]); //Read strings
    }
    
    *size = n;
    return aux;
}

int main(int argc, const char * argv[]) {
    char ** inputStrings;
    int n;
    
    inputStrings = readStrings(&n);
    if(inputStrings == NULL)printf("Read went wrong.");
    else{//Good read
        //Sort each string charcater
        for(int i=0;i<n;i++) qsort(inputStrings[i], strlen(inputStrings[i]), sizeof(char), comapareChar);
        //printf("\nSorted strings: \n");printStrings(inputStrings,n); //TEST
        
    }
    
    
    
    return 0;
}
