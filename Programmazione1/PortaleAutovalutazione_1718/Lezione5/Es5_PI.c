#include <stdio.h>

float power(float x, int n){
	float res = 1.0;
	while(n>0){
		res*=x;
		n--;
	}
	return res;
}

float approx_pi(int n){
	float res = 0;
	for(int i= 0, j=1; i<n ;i++,j+=2){
	    printf("i %d: res = %f + ( %f * (4.0 / %f) )\n",i,res,power(-1.0,i),(float)(j));
		res+=  power(-1.0,i) * ( (float)4.0 / (float)(j) );
	}
	return res;
}

int main(void){
    int n;
    
    scanf("%d",&n);
    
    printf("%.6f\n",approx_pi(n));
    
    return 0;
    
}
