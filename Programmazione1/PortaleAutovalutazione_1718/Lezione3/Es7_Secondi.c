/*
Scrivere un programma che legga da tastiera un numero che rappresenta un
numero di secondi, e stampi le ore, i minuti e i secondi compresi.
*/

#include <stdio.h>


int main(){
	int s,m,h;
	scanf("%d",&s);
	
	h = s/(3600);
	m = (s%3600)/60;
	s = (s%3600)%60;
	
	printf("%d h %d min %d s",h,m,s);

	return 0;
	
}
