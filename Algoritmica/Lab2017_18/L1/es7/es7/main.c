//
//  main.c
//  es6
//
//  Created by Andrea Del Corto on 07/11/2018.
//  Copyright © 2018 Andrea Del Corto. All rights reserved.
//

#include <stdio.h>

void tswap(int *x,int *y,int *z){
    int temp_x = *x,temp_y = *y,temp_z = *z;
    *x = temp_z;
    *y = temp_x;
    *z = temp_y;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int a=0,b=0,c=0;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    tswap(&a,&b,&c);
    printf("%d\n%d\n%d\n",a,b,c);
    return 0;
}
