#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 101

typedef struct _string{
	char str [MAX_STR];
	int len;
}String;

void printStrings(String * a,int n){
	for(int i=0;i<n;i++)printf("%s\n",a[i].str);
}

int readStrings(String ** a, int * n){
	String * aux = NULL; 
	scanf("%d",n);
	if(*n <= 0){
		printf("No points to read.");
		return -1;
	}else{//n > 0
		 aux = (String *)malloc((*n) * sizeof(String));
		 if(aux == NULL){
		 		printf("An error occurred during memory allocation.");
				return -2;
		 }else{//Good allocation
		 		for(int i=0;i<(*n);i++){//Allocate and read n points
					scanf("%s",aux[i].str);
					aux[i].len = strlen(aux[i].str);
				}
		 }
	}
	*a = aux;
	return 0;
}

/*
Return values:
	<0: a < b
	>0: a > b
	=0: a = b
In this case the order relationship is the following:
	For equal length, the lexicographical order is used. Use one
	struct that stores a string and its length to avoid calculating
	the latter at every confrontation
*/
int compare(const void * a,const void * b){
	String s1 = *((String *)a);
	String s2 = *((String *)b);
	if(s1.len == s2.len) //order with lexicographical
		return strcmp(s1.str,s2.str);
	else  //order string on lenght, increasing order
		return s1.len - s2.len;
}

int main(){
	String * a;
	int n;
	
	if(readStrings(&a,&n) == 0){//Good allocation and read
		//qsort(void *base, size_t nel, size_t width,int (*compar)(const void *, const void *));
		qsort(a,n,sizeof(String),compare);
		printStrings(a,n);
		//Deallocation
		free(a);
	}
	
	return 0;
}