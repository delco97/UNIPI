//
//  main.c
//  Piu0Che1
//
//  Created by Andrea Del Corto on 19/01/19.
//  Copyright © 2019 Andrea Del Corto. All rights reserved.
//

#include <stdio.h>

int Piu0Che1(int * a ,int sx, int dx){
    if(sx == dx){
        if(a[sx] == 0) return 1;
        return -1;
    }
    int cx = (sx + dx)/2;
    int diffSx = Piu0Che1(a,sx,cx);
    int diffDx = Piu0Che1(a,cx+1,dx);
    return (diffSx + diffDx) > 0;
}

int main(int argc, const char * argv[]) {
    int a [] = {0,1,1,0,1,1,1,0};
    int n = 8;
    printf("%s",Piu0Che1(a,0,n-1) == 1 ? "\nTrue\n":"\nFalse\n");
    return 0;
}
