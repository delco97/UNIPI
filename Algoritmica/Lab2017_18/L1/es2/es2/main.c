//
//  main.c
//  es2
//
//  Created by Andrea Del Corto on 06/11/2018.
//  Copyright © 2018 Andrea Del Corto. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,n=0,result=1;
    scanf("%d",&n);
    n = abs(n);
    i=n-1;
    while(result && i>1){
        //n è divisibile anche per un numero che NON è n stesso o 1 => NON primo
        if(n%i == 0)result = 0;
        i--;
    }
    printf("%d\n",result);
    return 0;
}
