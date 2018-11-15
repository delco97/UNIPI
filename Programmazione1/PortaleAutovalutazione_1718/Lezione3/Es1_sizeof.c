/*
Si realizzi un programma che legga 3 interi da standard input ed applichi
la funzione a 3 argomenti ordered swap(·,·,·) alle 3 variabili in cui sono
stati memorizzati i 3 valori. I valori letti devono essere passati alla funzione
nell’ordine in cui vengono acquisiti da tastiera.
Si implementi la funzione ordered swap, che scambia il contenuto delle 3
variabili di input in modo che la variabile corrispondente al primo argomento
contenga l’intero minore, la seconda variabile contenga l’intero mediano e la
terza contenga l’intero di valore maggiore.
Si stampi a video il contenuto delle 3 variabili all’uscita dall’esecuzione
della funzione.
*/

#include <stdlib.h>
#include <stdio.h>

int getMin(int a, int b, int c){
	int m =a;
	if(b<m)m = b;
	if(c<m)m = c;
	return m;
}

int getMax(int a, int b, int c){
	int m =a;
	if(b>m)m = b;
	if(c>m)m = c;
	return m;
}


void swap_ord(int *a,int *b,int *c){
	int min= getMin(*a,*b,*c), max=getMax(*a,*b,*c), med=*a;
	if(*a!=max && *a!=min)med=*a;
	if(*b!=max && *b!=min)med=*b;
	if(*c!=max && *c!=min)med=*c;
	
	*a=min;
	*b=med;
	*c=max;
}

int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	swap_ord(&a,&b,&c);
	printf("%d\n%d\n%d\n",a,b,c);

	return 0;
}
