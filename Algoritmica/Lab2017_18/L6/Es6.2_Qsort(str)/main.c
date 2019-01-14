#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 101

void printStrings(char ** a,int n){
	for(int i=0;i<n;i++)printf("%s\n",a[i]);
}

int readStrings(char *** a, int * n, int max_str){
	scanf("%d",n);
	if(*n <= 0){
		printf("No strings to read.");
		return -1;
	}else{//n > 0
		 *a = (char **)malloc((*n) * sizeof(char *));
		 if(a == NULL){
		 		printf("An error occurred during memory allocation.");
				return -2;
		 }else{//Good allocation
		 		for(int i=0;i<(*n);i++){//Allocate and read n strings
					(*a)[i] = (char *)malloc(max_str * sizeof(char));
					if((*a)[i] == NULL){
						printf("A problem occurred during memory allocation for %d° string.",i+1);
						return -3;
					} else //Good allocation
							scanf("%s",(*a)[i]);
				}
		 }
	}
	return 0;
}

/*
Return values:
	<0: a < b
	>0: a > b
	=0: a = b
In this case the order relationship is the following:
	1 - even numbers (0 included) come first, then odd numbers
	2 - even numbers in increasing order
	3 - odd numbers with decreasing order
*/
int compare(const void * a,const void * b){
	char ** s1 = (char **)a;
	char ** s2 = (char **)b;
	return strcmp(*s1,*s2) * -1;
}

int main(){
	char ** a;
	int n;
	
	if(readStrings(&a,&n,MAX_STR) == 0){//Good allocation and read
		//qsort(void *base, size_t nel, size_t width,int (*compar)(const void *, const void *));
		qsort(a,n,sizeof(char *),compare);
		printStrings(a,n);
		//Strings deallocation
		for(int i=0;i<n;i++)free(a[i]);
		free(a);
		
	}
	
	return 0;
}