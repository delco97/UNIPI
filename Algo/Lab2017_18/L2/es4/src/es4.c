/*
 ============================================================================
 Name        : es4.c
 Author      : Andrea Del Corto
 Version     :
 Copyright   : none
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define DIM_ASCII 256
#define DIM_STR 100
//Prototypes
int anagramma(unsigned char *s1, unsigned char *s2);

void setArray(int *a,int dim,int val){
	for (int i = 0; i < dim; i++) a[i]=val;
}

int anagramma(unsigned char *s1, unsigned char *s2){
	int i=0;
	int aS[DIM_ASCII]; //Counters for each possible ASCII character that can be found in s1
	int bS[DIM_ASCII]; //Counters for each possible ASCII character that can be found in s2
	int res = 1;
	//Init arrays counters
	setArray(aS,DIM_ASCII,0);
	setArray(bS,DIM_ASCII,0);
	//Loop s1 and s2 until it finish to scroll one of two
	while(s1[i]!='\0' && s2[i]!='\0' ){
		aS[s1[i]]++;bS[s2[i]]++; i++;
	}
	//s1 and s2 have NOT the same length
	if( (s1[i]=='\0' && s2[i]!='\0') || (s1[i]!='\0' && s2[i]=='\0')){
		res = 0;
	}else{//s1 and s2 have  the same length, but are they anagrams?
		/*Two anagram need to:
		 *  - Have the same size (checked at this point)
		 *  - The number of occurrences of each character contained in s1 (aS) must match with
		 *    the number of occurrences of each character contained in s2 (bS)
		 */
		i=0;
		while(i<DIM_ASCII && res){
			if(aS[i]!=bS[i])res = 0;//One character has a different number of occurrences => NOT anagrams
			else i++;
		}
	}

	return res;

}


int main(void) {
	unsigned char s1[DIM_STR];
	unsigned char s2[DIM_STR];
	scanf("%s",s1);
	scanf("%s",s2);
	printf("%d",anagramma(s1,s2));

	return EXIT_SUCCESS;
}
