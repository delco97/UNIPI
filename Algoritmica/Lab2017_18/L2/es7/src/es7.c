/*
 ============================================================================
 Name        : es7.c
 Author      : Andrea Del Corto
 Version     :
 Copyright   : none
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

#define DIM_STR 1001
//Prototypes
char* my_strcat(char *s1, char *s2);
//Implementations
char* my_strcat(char *s1, char *s2){

	int i=0,j=0;

	while(s1[i]!='\0')i++;//Find end of s1
	//Append s2 on s1 overwriting '\0' of s1.
	while(s2[j]!='\0'){s1[i]=s2[j];i++;j++;}
	s1[i]='\0';//Add new end-of-string char

	return s1;
}

int main(void) {
	char s1[DIM_STR];
	char s2[DIM_STR];
	char *concat;

	scanf("%s",s1);
	scanf("%s",s2);
	concat = my_strcat(s1,s2);
	printf("%s\n",concat);


	return EXIT_SUCCESS;
}
