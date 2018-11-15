/*
Scrivere un programma che legga da tastiera tre numeri interi e stampi il
massimo tra i tre.
*/

#include <stdio.h>

int getMax(int a,int b,int c){
	int m =a;
	if(b>m)m=b;
	if(c>m)m=c;
	return m;
}

int main(){
	int a,b,c;
	scanf("%d\n%d\n%d",&a,&b,&c);
	printf("%d\n",getMax(a,b,c));

	return 0;
}
