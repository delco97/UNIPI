/*
 ============================================================================
 Name        : es10.c
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
char* product(char *str, int k);
int my_strlen(char* s);
//Implementations
char* my_strcat(char *s1, char *s2){

	int i=0,j=0;

	while(s1[i]!='\0')i++;//Find end of s1
	//Append s2 on s1 overwriting '\0' of s1.
	while(s2[j]!='\0'){s1[i]=s2[j];i++;j++;}
	s1[i]='\0';//Add new end-of-string char

	return s1;
}

int my_strlen(char* s){
	int i=0;
	if(s!=NULL){
		while(s[i]!='\0')i++;
	}
	return i;
}

char* product(char *str, int k){
	int dim = (my_strlen(str) * k) +1;
	char *res = malloc(sizeof(char)*dim);

	while(k>0){
		my_strcat(res,str);
		k--;
	}
	return res;
}

int main(void) {
	char s1[DIM_STR];
	char *res;
	int n=0;

	scanf("%s",s1);
	scanf("%d",&n);
	res = product(s1,n);
	printf("%s\n",res);
	free(res);

	return EXIT_SUCCESS;
}
