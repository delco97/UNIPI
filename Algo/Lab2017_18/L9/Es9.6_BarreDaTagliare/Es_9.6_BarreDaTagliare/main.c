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
        if(a == NULL) printf("A problem with memory allocation occurred.");
        else{//Good allocation
            for (int i=0; i<n; i++) //Read prices
                scanf("%d",&a[i]);
        }
    }
    *dim = n;
    return a;
}

int getMaxProfit_OLD(int * a,int n,int sx,int dx,int  max){
    if(dx < sx) return 0; //Price for no bar
    if(sx == dx) return a[dx-sx]; //price for bar long 1
    //Bar is long more then 1
    int cx = (sx + dx)/2; //Cut bar in the middle
    int lenSx = (cx - sx) + 1; //length left bar (at least is 1)
    int lenDx = (dx - (cx + 1)) + 1; //length right bar (at least is 1)
    if( (a[lenSx-1] + a[lenDx-1]) > max) //Check if the price of barSx + barDx is bigger then the current max price
        max = (a[lenSx-1] + a[lenDx-1]);
    int maxSx = getMaxProfit(a,n,sx,cx,max); //Get the max profit of the left bar
    int maxDx = getMaxProfit(a,n,cx + 1, dx,max); //Get the max profit of the right bar
    if( maxSx + maxDx > max) max = maxSx + maxDx;
    return max;
}


void print


int main(int argc, const char * argv[]) {
    int * prices = NULL; //Arry of bars prices for each bar size from 1 to n.
                         //i=0 => price for bar of lenght 1, i=1 => price for bar of lenght 2, ....
    
    int n; //Lenght of the bar to cut. (*) I know the prices of all the bars less then n;
    prices = readBarsPrices(&n);
    
    if(n>0){//Bar is at least 1 inch long
        printf("\n%d",getMaxProfit(prices,n,0,n-1,prices[n-1]));
    }
    
    return 0;
}
