#include <stdio.h>

void multipli(int n, int m){

    for(int i=1;i<=n;i++){
		if((i % m) == 0){//Divisible by m
			printf("%d\n",i);
		}
    }

}


int main(void){
    int n,m;
    
    scanf("%d",&n);
    scanf("%d",&m);
    
    multipli(n,m);
    
    return 0;
    
}
