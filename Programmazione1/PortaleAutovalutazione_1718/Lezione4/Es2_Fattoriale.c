/*
Scrivere un programma che legga da tastiera un numero intero x e stampi il
valore di x!.
Per x! si intende x fattoriale, ovvero x · (x − 1) · (x − 2)· · · 1.
*/

#include <stdio.h>

int fact_rec(int n){
	if(n<=0)return 1;
	else return n * fact_rec(n-1);
}

int fact(int n){
	int ris=1;
	while(n>1){
		ris*=n;
		n--;
	}
	return ris;
}

int main(){
	int a;
	scanf("%d",&a);
	printf("%d",fact(a));
	return 0;
	
}
