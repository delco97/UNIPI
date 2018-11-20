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
	printf("%s\n",(my_strcmp(s1,s2)==1)?"+1":"-1");

	return EXIT_SUCCESS;
}
