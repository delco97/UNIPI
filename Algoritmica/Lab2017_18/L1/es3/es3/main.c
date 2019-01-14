//
//  main.c
//  es3
//
//  Created by Andrea Del Corto on 06/11/2018.
//  Copyright © 2018 Andrea Del Corto. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int x=0,somma=0;
    do {
        scanf("%d",&x);
        if(x!=0)somma+=x;
    } while (x!=0);
    printf("%d\n",somma);
    return 0;
}
