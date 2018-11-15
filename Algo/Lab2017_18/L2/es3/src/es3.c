/*
 ============================================================================
 Name        : es3.c
 Author      : Andrea Del Corto
 Version     :
 Copyright   : none
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

#define DIM 1000

int my_strlen(char *s);

int my_strlen(char *s){
	int n=0,i=0;
	while(s[i]!='\0'){//equivalente a scrivere: a[i] != '\0'
		n++;
		i++;
	}
	return n;
}

int main(void) {
	char s[DIM];
	scanf("%s",s);
	printf("%d",my_strlen(s));
	return EXIT_SUCCESS;
}
