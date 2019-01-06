//
//  main.c
//  Es7.3_AnagrammaPrincipale
//
//  Created by Andrea Del Corto on 06/01/19.
//  Copyright © 2019 Andrea Del Corto. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 20

typedef struct _String {
    char text[MAX_CHAR];
    char firstAn[MAX_CHAR];
} String;

int comapareChar(const void * a,const void * b){
    char c1 = *((char *)a);
    char c2 = *((char *)b);
    return c1 - c2;
}

int comapareString(const void * a,const void * b){
    String s1 = *((String *)a);
    String s2 = *((String *)b);
    int cmp = strcmp(s1.firstAn,s2.firstAn);
    if(cmp == 0)return strcmp(s1.text,s2.text);
    return cmp;
}

void printStrings_text(String * a,int n){
    for(int i=0;i<n;i++)printf("%s\n",a[i].text);
}

void printStrings(String * a,int n){
    for(int i=0;i<n;i++)printf("%s %s\n",a[i].text,a[i].firstAn);
}

void printStrings_firstAn(String * a,int n){
    for(int i=0;i<n;i++)printf("%s\n",a[i].firstAn);
}

String * allocationStrings(int n,int max_char){
    String * aux = NULL;
    aux = (String *)malloc(n * sizeof(String));
    if(aux == NULL)printf("Bad allocation");
    return aux;
}

String * readStrings(int * size){
    String * aux = NULL;
    int n = 0;
    
    scanf("%d",&n);
    if(n<=0)printf("n must be greater then 0.");
    else{
        aux = allocationStrings(n,MAX_CHAR);
        if(aux != NULL)//Good allocation
            for(int i=0;i<n;i++){//Read strings
                scanf("%s",aux[i].text);
                strcpy(aux[i].firstAn,aux[i].text);
                qsort(aux[i].firstAn, strlen(aux[i].firstAn), sizeof(char), comapareChar);
            }
    }
    
    *size = n;
    return aux;
}

int main(int argc, const char * argv[]) {
    String * inputStrings;
    int n;
    int j=-1;
    
    inputStrings = readStrings(&n);
    if(inputStrings == NULL)printf("Read went wrong.");
    else{//Good read
        //printf("\nRead strings: \n");printStrings(inputStrings,n); //TEST
        qsort(inputStrings, n, sizeof(String), comapareString);
        //printf("\nSorted strings: \n");printStrings(inputStrings,n); //TEST
        for(int i=0;i<n;i++){
            if(j == -1){//First loop
                printf("%s",inputStrings[i].text);
                j++;
            }else{
                if(strcmp(inputStrings[i].firstAn,inputStrings[j].firstAn) != 0){//String with new firstAn
                    printf("\n%s",inputStrings[i].text);
                    j = i;
                }else{//String with the same firstAn
                    printf(" %s",inputStrings[i].text);
                }
            }
        }
        printf("\n");
    }
    
    return 0;
}
