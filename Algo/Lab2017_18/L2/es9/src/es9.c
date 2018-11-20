/*
 ============================================================================
 Name        : es9.c
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
char* my_strcpy(char* dest, char* src);
int my_strlen(char* s);
//Implementations
int my_strlen(char* s){
	int i=0;
	if(s!=NULL){
		while(s[i]!='\0')i++;
	}
	return i;
}
char* my_strcpy(char* dest, char* src){
	int i=0;
	while(src[i]!='\0'){
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

int main(void) {
	char s1[DIM_STR];
	char *s2;
	int dim2;

	scanf("%s",s1);
	dim2 = my_strlen(s1) + 1;
	//printf("dim2: %d",dim2);
	s2 = malloc(sizeof(char)*dim2);
	my_strcpy(s2,s1);
	printf("%s\n",s1);
	//printf("%s dim(%d)\n",s2,dim2);
	free(s2);

	return EXIT_SUCCESS;
}
