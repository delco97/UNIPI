/*
 ============================================================================
 Name        : es8.c
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
int my_strcmp(char* s1, char* s2);
//Implementations
char* my_strcat(char *s1, char *s2){

	int i=0,j=0;

	while(s1[i]!='\0')i++;//Find end of s1
	//Append s2 on s1 overwriting '\0' of s1.
	while(s2[j]!='\0'){s1[i]=s2[j];i++;j++;}
	s1[i]='\0';//Add new end-of-string char

	return s1;
}

int my_strcmp(char* s1, char* s2){
	int i=0,res=0;
	while(res==0 && s1[i]!='\0' && s2[i]!='\0'){
		if(s1[i] == s2[i])i++;
		else res = (s1[i] < s2[i])?-1:1;
	}
	return res;
}

int main(void) {
	char s1[DIM_STR];
	char s2[DIM_STR];

	scanf("%s",s1);
	scanf("%s",s2);
	printf("%d\n",my_strcmp(s1,s2));

	return EXIT_SUCCESS;
}
