//
//  main.c
//  es6
//
//  Created by Andrea Del Corto on 07/11/2018.
//  Copyright © 2018 Andrea Del Corto. All rights reserved.
//

#include <stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int a=0,b=0;
    scanf("%d",&a);
    scanf("%d",&b);
    swap(&a,&b);
    printf("%d\n%d\n",a,b);
    return 0;
}
