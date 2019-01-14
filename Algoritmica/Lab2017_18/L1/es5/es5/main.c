//
//  main.c
//  es5
//
//  Created by Andrea Del Corto on 06/11/2018.
//  Copyright © 2018 Andrea Del Corto. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int sumOdd(int n,int i,int sum) {
    if(n>0){//At least one odd number need to be added
        if(i%2 != 0){//Odd number -> add to sum
            sum += i;
            n--;
        }
        return sumOdd(n,i+1,sum);//Continue recursion
    }
    return sum;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n=0;
    scanf("%d",&n);
    n = abs(n);
    printf("%d",sumOdd(n,0,0));
    return 0;
}
