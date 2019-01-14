#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 101
#define MAX_SEARCH 1000
/*
 Scrivere una funzione che, dato un array di interi e la sua lunghezza, lo
 ordini utilizzando lÍalgoritmo Selection Sort.
 Scrivere un programma che utilizzi la funzione per ordinare un array di
 N interi letti da input e stampi in output gli elementi dellÍarray ordinato.
 La prima riga dellÍinput contiene la dimensione N dellÍarray. Le righe
 successive contengono gli elementi dellÍarray, uno per riga.
 LÍoutput contiene gli elementi dellÍarray ordinato, uno per riga.
 */

void printStrings(char **a,int dim){
    for (int i = 0; i < dim; i++)printf("%s\n",a[i]);
}

void insertionSort_Str(char ** a,int n){
    char * key;
    int j=0;
    for(int i=1;i<n;i++){
        key = a[i];
        j = i-1;
        while(j>=0 && strcmp(key,a[j])< 0){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int binarySearch_Str(char** a,int n,char *target){
    int res = -1;
    int l = 0,r = n-1,pivot;
    int cmp;

    while(l<=r && res == -1){
        pivot = (l+r)/2;
        cmp = strcmp(a[pivot],target);
        if(cmp==0)res = pivot;
        else{//Where could the target be? left
            if(cmp<0) l=pivot+1; //target could be in the right part of pivot
            else r=pivot-1; //target could be in the left part of pivot
        }
    }

    return res;
}

void searchStrings(char** a,int n){
    int tmp = 0;
    int numsearch = 0;
    char s[MAX_STR];
    int res[MAX_SEARCH];
    do{
        scanf("%d",&tmp);
        if(tmp!=0){
            scanf("%s",s);
            res[numsearch] = binarySearch_Str(a,n,s);
            numsearch++;
        }
    }while(tmp!=0 && numsearch<MAX_SEARCH);
    //Print results
    for(int i=0;i<numsearch;i++)printf("%d\n",res[i]);
}

int main(void) {
    int n1=0;
    char ** a1;

    //printf("**** ARRAY OF STRING ****\n ");
    //printf("Number of strings: ");
    scanf("%d",&n1);
    if(n1 <= 0){
        printf("The array must be made at least of one element");
    }else{//Good size
        a1 = (char **) malloc(sizeof(char *) * n1);
        if(a1==NULL)printf("A problem occurred during memory allocation (1) ");
        else{
            for(int i=0;i<n1;i++){
                a1[i] = (char *)malloc(sizeof(char) * MAX_STR);
                if(a1[i]==NULL)printf("A problem occurred during memory allocation (2).\nWill be impossible to get the %d string.",i+1);
                else{
                    //printf("String %d on %d:\n",i+1,n1);
                    scanf("%s",a1[i]);
                }
            }

            searchStrings(a1,n1);

            //Deallocation of strings
            for(int i=0;i<n1;i++){
                if(a1[i]!=NULL)free(a1[i]);
            }

            free(a1);
        }
    }
}
