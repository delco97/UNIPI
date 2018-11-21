/*
Scrivere un programma che legga da tastiera un numero e stabilisca se pari
o meno, stampando in uscita rispettivamente 1 o 0.
*/

#include <stdio.h>


int main(){
	char a;
	scanf("%c\n",&a);
	printf("%d\n",a%2==0);

	return 0;
}
