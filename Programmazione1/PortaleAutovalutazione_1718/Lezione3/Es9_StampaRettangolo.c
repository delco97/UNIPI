/*
Scrivere un programma che stampi un rettangolo di 10 righe e 3 colonne la
cui cornice sia costituita da caratteri asterisco e la parte interna da ’X’.
*/

#include <stdio.h>


int main(){
	float r=10,c=3;

	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			if(i!=1 && i!=r &&  j!=1 && j!=c)printf("X");
			else printf("*");
		}
		printf("\n");
	}
	return 0;
	
}
