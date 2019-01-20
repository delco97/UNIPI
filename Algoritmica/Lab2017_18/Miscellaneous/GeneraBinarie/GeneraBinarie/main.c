//
//  main.c
//  Piu0Che1
//
//  Created by Andrea Del Corto on 19/01/19.
//  Copyright © 2019 Andrea Del Corto. All rights reserved.
//

#include <stdio.h>
#include <string.h>

void GeneraBinarie(char * a ,int k, long n){
    if(k >= n) printf("%s\n",a);
    else{
        a[k+1] = '0';
        GeneraBinarie(a, k+1, n);
        a[k+1] = '1';
        GeneraBinarie(a, k+1, n);
    }
}

void Scambia(char * a, char * b){
    char aux = *a;
    *a = *b;
    *b = aux;
}

void GeneraPermutazioni(char * a ,long p){
    if (p == 0) printf("%s\n",a);
    else {
         for (long i = p-1; i >= 0; i = i-1) {
             Scambia( &a[i], &a[p-1] );
             GeneraPermutazioni( a, p-1);
             Scambia( &a[i], &a[p-1] );
         }
    }
}

int main(int argc, const char * argv[]) {
    char a[] = "abc";
    long n = strlen(a);
    //GeneraBinarie(a,-1,n-1);
    GeneraPermutazioni(a, n);
    return 0;
}
