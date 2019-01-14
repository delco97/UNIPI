/*
 ============================================================================
 Name        : es5.c
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
char* my_strcat1(char *s1, char *s2);
//Implementations
char* my_strcat1(char *s1, char *s2){
	char *cat = malloc(((DIM_STR*2)-1)*sizeof(char));
	int i=0,j=0;

	while(s1[j]!='\0' && i<(DIM_STR*2)-1){cat[i]=s1[j];i++;j++;}
	j=0;
	while(s2[j]!='\0' && i<(DIM_STR*2)-1){cat[i]=s2[j];i++;j++;}
	return cat;
}

int main(void) {
	char s1[DIM_STR];
	char s2[DIM_STR];
	char *cat;

	scanf("%s",s1);
	scanf("%s",s2);
	cat = my_strcat1(s1,s2);
	printf("%s\n",cat);
	free(cat);

	return EXIT_SUCCESS;
}
