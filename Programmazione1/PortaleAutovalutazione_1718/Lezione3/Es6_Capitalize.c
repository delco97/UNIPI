/*
Scrivere un programma che legga da tastiera carattere alfabetico in minuscolo
e stampi lo stesso carattere in maiuscolo.
N.B.: ricordatevi che ogni carattere puo’ essere visto come un intero.
*/

#include <stdio.h>


int main(){
	char a;
	scanf("%c",&a);
	printf("%c\n",a-('a'-'A'));

	return 0;
	
}
