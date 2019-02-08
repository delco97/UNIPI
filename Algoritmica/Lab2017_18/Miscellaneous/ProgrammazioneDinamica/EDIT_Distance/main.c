#define _GNU_SOURCE //For getline
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_STR 31
#define SIZE 1024

typedef enum _Choice{
    UP = 1,
    LEFT = 2,
    DIAGONAL = 4,
} Choice;

typedef struct _TString{//Target string
    char txt[MAX_STR];
    int dist;
} TString;

typedef struct _PDCell{
    int dist;
    Choice choice;
} PDCell;

int printEDIT(PDCell ** tab, char * x,char * y,char * allX,char * allY,int i,int j,int h){
    if(i==0 || j==0) return h;
    int aux;
    if(tab[i][j].choice & UP){//UP choice
        allX[h] = x[i-1]; //printf("%c",x[i-1]);
        allY[h] = '-';//printf("-");
        aux = printEDIT(tab,x,y,allX,allY,i-1,j,h-1);
    }else{
        if(tab[i][j].choice & LEFT){//LEFT choice
            allX[h] = '-'; //printf("-");
            allY[h] = y[j-1]; //printf("%c",y[j-1]);
            aux = printEDIT(tab,x,y,allX,allY,i,j-1,h-1);
        }else{//DIAGONAL
            allX[h] = x[i-1];//printf("%c",x[i-1]);
            allY[h] = y[j-1];//printf("%c",y[j-1]);
            aux = printEDIT(tab,x,y,allX,allY,i-1,j-1,h-1);
        }
    }
    return aux;
}

void printRow(char * c,int n){
    for(int i=0;i<n;i++) printf("%s",c);
}

void printTab(PDCell ** tab,char * x,char * y, int r, int c){
    printf("         ");
    for(int j=0;j<c-1;j++)printf("%c   ",y[j]);
    for(int i=0;i<r;i++){
        printf("\n   ");
        printRow("----",c);
        if(i>0) printf("\n %c |",x[i-1]);
        else printf("\n   |");
        for(int j=0;j<c;j++){
            printf(" %d |",tab[i][j].dist);
        }
    }
    printf("\n   ");
    printRow("----",c);
}

int min(int a,int b,int c, Choice * choice){
    int min=a;
    if(b < min) min = b;
    if(c < min) min = c;
    //Min selected, now get possible choices
    if(a == min) *choice = DIAGONAL;
    else if(b == min) *choice = *choice | UP;
    else if(c == min) *choice = *choice | LEFT;
    return min;
}

PDCell ** calcEDIT(char * x, char * y,unsigned long xn, unsigned long yn){
    PDCell ** pdTab = NULL;
    int p;
    int left,diagonal,up;
    Choice choice;
    //1 - Setup dynamic programming table
    pdTab = (PDCell **) malloc( (xn + 1) * sizeof(PDCell *));
    for(int i=0;i<=xn;i++)
        pdTab[i] = (PDCell *)malloc( (yn + 1) * sizeof(PDCell));
    //2 - Solve simple probelms
    for(int i=0;i<=xn;i++) pdTab[i][0].dist = i;
    for(int j=0;j<=yn;j++) pdTab[0][j].dist = j;
    //3 - Fill remaining cells
    for(int i=1;i<=xn;i++){
        for(int j=1;j<=yn;j++){
            if(x[i-1] == y[j-1]) p = 0;
            else p = 1;
            //The order will determine which position has the priority.
            left = pdTab[i][j-1].dist + 1;
            diagonal = pdTab[i-1][j-1].dist + p;
            up = pdTab[i-1][j].dist + 1;
            pdTab[i][j].dist  = min(left,diagonal, up , &choice);
            //pdTab[i][j].dist  = min(up, diagonal, left, &choice);
            //pdTab[i][j].dist  = min(diagonal, up, left, &choice);
            pdTab[i][j].choice = choice;
        }
    }
    //4 - Get result
    return pdTab;
}

/*
 //printTab(pdTab,x,y,xn+1,yn+1); //DEBUG
 //printEDIT(pdTab,x,y,xn,yn); //OLD
 char * ALLX = malloc( (xn+yn) * sizeof(char));
 char * ALLY = malloc( (xn+yn) * sizeof(char));
 char * ALLX_fine;
 char * ALLY_fine;
 
 ALLX[xn+yn-1] = '\0';
 ALLY[xn+yn-1] = '\0';
 int h = printEDIT(pdTab,x,y,ALLX,ALLY,xn,yn,xn+yn-2);
 int allSize = ((xn+yn-2) - (h+1)) + 1;
 ALLX_fine = malloc(allSize + 1 * sizeof(char));
 ALLY_fine = malloc(allSize + 1 * sizeof(char));
 memcpy(ALLX_fine,&ALLX[h+1],allSize+1);
 memcpy(ALLY_fine,&ALLY[h+1],allSize+1);
 printf("%s\n%s",ALLX_fine,ALLY_fine);
 printf("\n");
 */

void calcAligments(PDCell ** pdTab,char * x, char * y, int xn,int yn){
    char * ALLX = malloc( (xn+yn) * sizeof(char));
    char * ALLY = malloc( (xn+yn) * sizeof(char));
    char * ALLX_fine;
    char * ALLY_fine;
    
    ALLX[xn+yn-1] = '\0';
    ALLY[xn+yn-1] = '\0';
    int h = printEDIT(pdTab,x,y,ALLX,ALLY,xn,yn,xn+yn-2);
    int allSize = ((xn+yn-2) - (h+1)) + 1;
    ALLX_fine = malloc(allSize + 1 * sizeof(char));
    ALLY_fine = malloc(allSize + 1 * sizeof(char));
    memcpy(ALLX_fine,&ALLX[h+1],allSize+1);
    memcpy(ALLY_fine,&ALLY[h+1],allSize+1);
    printf("%s\n%s",ALLX_fine,ALLY_fine);
    printf("\n");
    free(ALLX);
    free(ALLY);
    free(ALLX_fine);
    free(ALLY_fine);
}

int countLines(char * filename){
    
    FILE *in_file;
    char buffer[SIZE + 1], lastchar = '\n';
    size_t bytes;
    int lines = 0;
    
    if (NULL == (in_file = fopen(filename, "r"))) {
        perror(filename);
        return EXIT_FAILURE;
    }
    
    while ((bytes = fread(buffer, 1, sizeof(buffer) - 1, in_file))) {
        lastchar = buffer[bytes - 1];
        for (char *c = buffer; (c = memchr(c, '\n', bytes - (c - buffer))); c++) {
            lines++;
        }
    }
    if (lastchar != '\n') {
        lines++;  /* Count the last line even if it lacks a newline */
    }
    if (ferror(in_file)) {
        perror(filename);
        fclose(in_file);
        return EXIT_FAILURE;
    }
    
    fclose(in_file);
    return lines;
}

TString * readDictionary(char * fName,int * nWords){
    TString * d = NULL;
    int n = countLines(fName);
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int i=0;
    d = malloc(n * sizeof(TString));
    if(d == NULL) printf("An error occurred during memory allocation");
    else{//Good allocation
        //Read file
        fp = fopen(fName, "r");
        if (fp == NULL)
            exit(EXIT_FAILURE);
        
        while ((read = getline(&line, &len, fp)) != -1) {
            //printf("Retrieved line of length %zu:\n", read);
            line[read-1] = '\0'; //printf("%s", line);
            strcpy(d[i].txt,line);
            d[i].dist = -1; //undefined distance
            i++;
        }
        
        fclose(fp);
        if (line)
            free(line);
    }
    *nWords = n;
    return d;
}

int compByDist(const void * a,const void * b){
    TString x = *((TString *)a);
    TString y = *((TString *)b);
    return x.dist - y.dist;
}

int main(){
    PDCell ** pdTab = NULL;
    TString * dictionary = NULL;
    char x[MAX_STR];
    //char y[MAX_STR];
    unsigned long xn; //size of string x
    unsigned long yn; //size of string y
    int continueLoop=0;
    int nWords=0;
    //int dist; //distance between x and y
    
    //Get dictionary
    dictionary = readDictionary("./Dictionaries/it.txt",&nWords);
    if(dictionary == NULL) printf("Impossible to read dictionary.");
    else{
        printf("****Perhaps you were looking for****\n");
        printf("Type a string, then a list of similar word will be shown\n");
        printf("To exit program insert the following char: *\n");
        int i,j;
        do{
            scanf("%s",x);
            continueLoop = strcmp(x,"*");
            if(continueLoop != 0){//Find similar words
                xn = strlen(x);
                for(i=0;i<nWords;i++){//Loop dictionary
                    yn = strlen(dictionary[i].txt);
                    pdTab = calcEDIT(x,dictionary[i].txt,xn,yn);
                    if(pdTab == NULL)
                        printf("\nImpossible to calculate distance with word %s",dictionary[i].txt);
                    else{//Distance calculated
                        dictionary[i].dist = pdTab[xn][yn].dist;
                        //printTab(pdTab,x,dictionary[i].txt,xn+1,yn+1); //****DEBUG****
                        //printf("\nDistance: %d\n",dist);
                        //printf("\Alignments:\n");
                        //calcAligments(pdTab,x,y,xn,yn);
                        //Deallocate dynamic table
                        for(j=0;j<xn;j++) free(pdTab[j]);
                        free(pdTab);
                    }
                }
                //Sort
                qsort(dictionary,nWords,sizeof(TString),compByDist);
                printf("\nPerhaps you were looking for...:\n");
                for(int i=0;i<10;i++){
                    printf("[%d] %s\n",dictionary[i].dist,dictionary[i].txt);
                }
            }
        }while(continueLoop != 0);
    }
    //Deallocation
    if(pdTab != NULL){
        for(int i=0;i<xn;i++)free(pdTab[i]);
        free(pdTab);
    }
    
    return 0;
}


