#include <stdio.h>
#include <stdlib.h>

int Pot2(int n){
	if(n<2){
		return 2;
	}else{//n>=2
		return 2*Pot2(n-1);
	}
}

int main(){
    int n;
    
	scanf("%d",&n);
	printf("%d\n",Pot2(n));
	
	return 0;
}

