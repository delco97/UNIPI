//
//  main.c
//  TrovaMaxRec
//
//  Created by Andrea Del Corto on 20/01/19.
//  Copyright © 2019 Andrea Del Corto. All rights reserved.
//

#include <stdio.h>

int max(int a, int b){
    return a>=b?a:b;
}

int posMax(int * a ,int sx, int dx){
    if(sx == dx) return sx;
    int posM = posMax(a, sx, dx-1);
    int m = max(a[dx],a[posM]);
    if(m == a[dx]) return dx;
    else return posM;
}

int posMax2(int * a,int sx, int dx){
    if(sx == dx) return sx;
    int cx = (sx+dx)/2;
    int m1 = posMax(a, sx, cx);
    int m2 = posMax(a, cx+1, dx);
    return a[m1] <= a[m2] ? m1:m2;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int a [] = {7,3,4,9,1};
    int n = 5;
    int m = posMax(a, 0, n-1);
    int m2 = posMax2(a, 0, n-1);
    printf("\nFirst max in pos %d: %d\n",m,a[m]);
    printf("\nSecond max in pos %d: %d\n",m2,a[m2]);
    return 0;
}
