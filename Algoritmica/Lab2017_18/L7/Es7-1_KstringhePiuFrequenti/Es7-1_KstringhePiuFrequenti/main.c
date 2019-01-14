#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_CHAR 101 //max string size is 100 characters + 1 for the termination character

typedef struct _StringOcc{
    char text[MAX_CHAR];
    int occurrences;
} StringOcc;

void printStrings(char ** a, int n){
    for(int i=0;i<n;i++)printf("%s\n",a[i]);
    
}

void printStringOcc(StringOcc * a, int n){
    for(int i=0;i<n;i++)printf("%s\n",a[i].text);
}

void stringsDeallocation(char ** a,int j){
    for(int i=0;i<=j;i++)free(a[i]);
    free(a);
}


StringOcc * stringsAllocation2(int n){
    StringOcc * a = NULL;
    a = (StringOcc *)malloc(n * sizeof(StringOcc));
    if(a == NULL)printf("Probelm during memory allocation (1)\n");
    return a;
}

char ** stringsAllocation(int n,int max_str){
    char ** a = NULL;
    a = (char **)malloc(n * sizeof(char *));
    if(a == NULL)printf("Probelm during memory allocation (1)\n");
    else{
        for(int i=0;i<n;i++){
            a[i] = (char *)malloc(max_str * sizeof(char));
            if(a[i] == NULL){
                printf("Problem during memory allocation (i = %d) (2)\n",i);
                stringsDeallocation(a,i-1);
                break;
            }
        }
    }
    return a;
}

char ** readStrings(int n,int max_str){
    char ** a = NULL;
    a = stringsAllocation(n,max_str);
    if(a != NULL)//Good memory allocation
        for(int i=0;i<n;i++)scanf("%s",a[i]);
    return a;
}

/*
 Return values:
 <0: a < b
 >0: a > b
 =0: a = b
 */
int compare(const void * a, const void * b ){
    char ** s1 = (char **)a;
    char ** s2 = (char **)b;
    return strcmp(*s1,*s2);
}

int compareStringOcc_occurrences(const void * a, const void * b ){
    StringOcc s1 = *((StringOcc *)a);
    StringOcc s2 = *((StringOcc *)b);
    return s2.occurrences - s1.occurrences;
}

int compareStringOcc_text(const void * a, const void * b ){
    StringOcc s1 = *((StringOcc *)a);
    StringOcc s2 = *((StringOcc *)b);
    return strcmp(s1.text,s2.text);
}

int getlastOccurrence(char ** a, char * str, int sx,int dx,int n){
    if(sx > dx)return -1; //Base case empty subarray
    else{//At least one element
        int cx = (sx+dx)/2;
        int comp = strcmp(a[cx],str);
        if(comp == 0){//a[cx] == str
            if(cx == n-1 || strcmp(a[cx+1],str) != 0)return cx;
            else  return getlastOccurrence(a,str,cx+1,dx,n);
        }else{
            if(comp < 0)//a[cx] < str
                return getlastOccurrence(a,str,cx+1,dx,n);
            else //a[cx] > str
                return getlastOccurrence(a,str,sx,cx-1,n);
        }
    }
}

int countDsitinct(char ** a,int n){
    int i = 0;
    int count = 0;
    int lastOccurrence;
    do{
        count++;
        lastOccurrence = getlastOccurrence(a,a[i],i,n-1,n); //Get last occurrence of a[i] in a[0...n-1]
        i = lastOccurrence + 1;
    }while(i<n);
    return count;
}

void getStringsOcc(char ** a,StringOcc * b,int n,int m){
    int j = 0;
    int i = 0;
    int lastOccurrence;
    
    do{
        strcpy(b[j].text, a[i]);
        lastOccurrence = getlastOccurrence(a,a[i],i,n-1,n); //Get last occurrence of a[i] in a[0...n-1]
        b[j].occurrences = (lastOccurrence - i) + 1; //Calculate number o occurrences of a[i] in a[0...n-1]
        i = lastOccurrence + 1;
        j++;
    }while(i<n && j<m);
    
}

int main(){
    int n = 0,k = 0,num_distinct=0;
    char ** a = NULL;
    StringOcc * b = NULL;
    
    scanf("%d",&n);
    scanf("%d",&k);
    if(k > n){//Error
        printf("k must be less then or equal to n\n");
    }else{//Good input
        //max_distinct = (-1 + sqrt(1 + 8*n))/2;
        a = readStrings(n,MAX_CHAR);
        qsort(a, n ,sizeof(char *),compare); //Lexicographically order input strings  O(nlog(n))
        //printf("\nSorted strings: \n");/
        //printStrings(a,n); //Test
        if(a != NULL){//Good read and allocations
            num_distinct = countDsitinct(a,n);
            b = stringsAllocation2(num_distinct);
            if(b!=NULL){
                getStringsOcc(a,b,n,num_distinct);
                qsort(b, num_distinct ,sizeof(StringOcc),compareStringOcc_occurrences); //O(nlog(n))
                qsort(b, k ,sizeof(StringOcc),compareStringOcc_text); //O(nlog(n))
                //printf("\nK strings: \n");
                printStringOcc(b, k);
                
                free(b);
            }
            //Deallocation
            stringsDeallocation(a, n-1);
        }
    }
    
    return 0;
}
