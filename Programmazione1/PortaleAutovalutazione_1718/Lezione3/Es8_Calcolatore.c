/*
Scrivere un programma che legga da tastiera due numeri a e b (anche con
virgola) e un operatore tra + - / % e stampi il risultato ottenuto applicando
l’operatore ai due numeri inseriti. Per l’operazione % gli operandi sono bac
e bbc
*/

#include <stdio.h>


int main(){
	float a,b,ris;
	char op;
	
	scanf("%f\n%f\n%c",&a,&b,&op);
	
	switch(op){
		case '+':
			ris = a + b;
		break;
		case '-':
			ris = a - b;
		break;
		case '/':
			ris = a / b;
		break;
		case '%':
			ris = (int)a % (int)b;
		break;
	}
	
	printf("%.1f\n",ris);

	return 0;
	
}
