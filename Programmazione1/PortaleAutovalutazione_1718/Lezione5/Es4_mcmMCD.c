#include <stdio.h>

int MCD(int a, int b){
	if(a>b)
		return MCD(a-b,b);
	else {
	  if(b>a)
	  	return MCD(a,b-a);
	  else//a == b
	  	return a;
	}
} 

int mcm(int a, int b){
	return (a*b)/(MCD(a,b));
}

int main(void){
    int n,m;
    
    scanf("%d",&n);
    scanf("%d",&m);
    
    printf("%d\n",MCD(n,m));
    printf("%d\n",mcm(n,m));
    
    return 0;
    
}
