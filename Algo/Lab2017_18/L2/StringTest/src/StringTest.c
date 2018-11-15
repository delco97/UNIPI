/*
 ============================================================================
 Name        : StringTest.c
 Author      : Andrea Del Corto
 Version     :
 Copyright   : none
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void myPrintf(char *s){
	int i=0;
	while(s[i]){//Cicla fino al carattere di fine stringa (equivalenti: s[i]!='\0', *s != '\0', *s)
		//i++ (post incremento) => viene valutata prima s[i] poi i viene incrementato
		//printf("%c\n", s[i++]);
		printf("%c\n", *s++);/*incrementa s (puntatore all'i-esimo carattere della stringa)
								dopo avere stampato l'i-esimo carattere. s è una copia! Quindi puntatore in funzione chiamante non viene modificato. */
	}

}

void test1(){
	//stringa è una array di caratteri (char)
	printf("**Test 1**\n");
	char *s = "ciao"; //Lunga 5 caratteri (viene aggiunto automaticamente il carattere di fine stringa '\0')
	printf("%s\n", s);//'ciao'
	printf("%s\n", s+1);//'iao' (s: indirizzo primo carattere della stringa)
	printf("%c\n", *s);//'c' (*s equivalente a s[0]: valore del primo carattere della stringa)
	printf("%c\n", *(s+1));//'i' (*(s+1) equivalente a s[1]: valore del secondo carattere della stringa)
}



void test2(){
	char aux[101];//100 caratteri (101° è per \0)

	printf("**Test 2**\n");
	printf("Inserisci stringa: ");
	scanf("%s",aux);
	myPrintf(aux);

	free(aux);
}

int main(void) {

	test1();
	test2();

	return EXIT_SUCCESS;
}
