/*
Scrivere un programma che legga da tastiera tre numeri (anche con virgola)
e stampi in uscita la media, riportandola con tre cifre decimali.
*/

#include <stdio.h>


int main(){
	float a,b,c;
	scanf("%f\n%f\n%f",&a,&b,&c);
	printf("%.3f\n",(a+b+c)/3);

	return 0;
}
