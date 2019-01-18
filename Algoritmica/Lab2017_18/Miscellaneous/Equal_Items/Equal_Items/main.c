//
//  main.c
//  Equal_Items
//
//  Created by Andrea Del Corto on 18/01/19.
//  Copyright © 2019 Andrea Del Corto. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int * readArray(int * dim){
    int * a = NULL;
    int n = -1;
    scanf("%d",&n);
    if(n>0){
        a = (int *) malloc(n * sizeof(int));
        if(a == NULL) printf("\nAn error occurred during memory allocation.");
        for (int i=0; i<n; i++) scanf("%d",&a[i]);
    }
    *dim = n;
    return a;
}

int BinarySearch(int * a,int sx,int dx,int k){
    if(sx > dx) return -1;
    int cx = (sx + dx)/2;
    if(a[cx] == k) return cx;
    if(a[cx] < k) return BinarySearch(a, cx +1, dx, k);
    else return BinarySearch(a, sx, cx - 1, k); //a[cx] > k
}

int sharedItems(int * a,int * b,int n, int m){
    int i = 0, j = 0, count = 0;
    int lastPosA = -1, lastPosB = -1, startPosB = -1;
    int nEqualsA = 0, nEqualsB = 0;
    while(i < n && j < m){
        lastPosA = BinarySearch(a, i+1, n-1, a[i]);
        startPosB = BinarySearch(b, j, m-1, a[i]);
        if(startPosB != -1){
            lastPosB = BinarySearch(b, j+1, m-1, a[i]);
            nEqualsB = nEqualsA = 1;
            if(lastPosA != -1) nEqualsA = lastPosA - i + 1;
            if(lastPosB != -1) nEqualsB = lastPosB - j + 1;
            if(nEqualsA <= nEqualsB) count += nEqualsA;
            else count += nEqualsB;
            j = startPosB + 1;
        }
        if(lastPosA == -1) i++;
        else i = lastPosA + 1;
    }
    return count;
}

int main(int argc, const char * argv[]) {
    int * a = NULL, *b = NULL;
    int n; //dim a
    int m; //dim b
    a = readArray(&n);
    b = readArray(&m);
    if(a != NULL && b != NULL){
        printf("Elementi condivisi: %d\n",sharedItems(a,b,n,m));
    }
    return 0;
}
