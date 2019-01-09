//
//  main.c
//  Es_9.6_BarreDaTagliare
//
//  Created by Andrea Del Corto on 09/01/19.
//  Copyright © 2019 Andrea Del Corto. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


int * readBarsPrices(int * dim){
    int * a = NULL;
    int n;
    scanf("%d",&n);
    if(n<=0) printf("The bar should be at least 1 inch long");
    else{//Good lenght
        a = (int *)malloc(n * sizeof(int));
        if(a == NULL) printf("A problem with memory allocation occurred.")
        else{//Good allocation
            for (int i=0; i<n; i++) //Read prices
                scanf("%d",&a[i]);
        }
    }
    *dim = n;
    return a;
}



int main(int argc, const char * argv[]) {
    int * prices = NULL; //Arry of bars prices for each bar size from 1 to n.
                         //i=0 => price for bar of lenght 1, i=1 => price for bar of lenght 2, ....
    
    int n; //Lenght of the bar to cut. (*) I know the prices of all the bars less then n;
    a = readBarsPrices(&n);

    
    return 0;
}
