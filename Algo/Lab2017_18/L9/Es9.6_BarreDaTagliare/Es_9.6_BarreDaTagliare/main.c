//
//  main.c
//  Es_9.6_BarreDaTagliare
//
//  Created by Andrea Del Corto on 09/01/19.
//  Copyright © 2019 Andrea Del Corto. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int max(int a,int b){
    int m = a;
    if(b > m)m = b;
    return m;
}

int getMaxProfit_Inefficient(int * p,int n){
    if(n == 0) return 0; //Price for bar of lenght 0
    int m = INT_MIN; // -infinity
    for(int i=1;i<=n;i++)
        m = max(m,p[i-1] + getMaxProfit_Inefficient(p, n - i));
    return m;
}

int bottomUp_MaxProfit(int * p,int n,int * optimal_size){
    int * r = malloc( (n+1) * sizeof(int)); //r[0...n]
    int * s = malloc( (n+1) * sizeof(int)); //s[0...n]
    int m; //hold max revenue
    r[0] = 0;
    for(int j = 1; j<= n; j++){
        m = INT_MIN;
        for(int i = 1; i<= j; i++){
            if(m < p[i -1] + r[j - i]){//New optimal size
                m = p[i -1] + r[j - i]; //Updated max revenue
                s[j] = i;
            }
        }
        r[j] = m; //get max revenue for rod of lenght j
    }
    *optimal_size = s[n]; //get optimal size cut for rod n
    return r[n];
}


int main(int argc, const char * argv[]) {
    int * prices = NULL; //Arry of bars prices for each bar size from 1 to n.
                         //i=0 => price for bar of lenght 1, i=1 => price for bar of lenght 2, ....
    
    int n; //Lenght of the bar to cut. (*) I know the prices of all the bars less then n;
    prices = readBarsPrices(&n);
    
    if(n>0){//Bar is at least 1 inch long
        int optimalSize = n;
        int maxRevenue = bottomUp_MaxProfit(prices,n,&optimalSize);
        printf("%d\n",maxRevenue);
        if(optimalSize == n) printf("%d\n",n);
        else
            printf("%d %d\n",optimalSize,n-optimalSize);
        
    }
    
    return 0;
}
