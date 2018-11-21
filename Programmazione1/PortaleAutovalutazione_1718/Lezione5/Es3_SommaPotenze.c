#include <stdio.h>

float pow(float x, int n){
	float res = 1.0;
	while(n>0){
		res*=x;
		n--;
	}
	return res;
}

float sum_pow(float x, int n){
	float sum = 0;
    for(int i=0;i<=n;i++){
		sum += pow(x,i);
    }
	return sum;
}


int main(void){
    int n;
    float x;
    
    scanf("%d",&n);
    scanf("%f",&x);
    
    printf("%.2f",sum_pow(x,n));
    
    return 0;
    
}
