#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_STR 101


typedef struct _PDCell{
	int lcs;
	int choice;//
} PDCell;

void printLCS(PDCell ** tab, char * x,int i,int j){
	if(i==0 || j==0) return;
	if(tab[i][j].choice == 2){
		printLCS(tab,x,i-1,j-1);
		printf("%c",x[i-1]);
	}else{
		if(tab[i][j].choice == 3) printLCS(tab,x,i-1,j);
		else printLCS(tab,x,i,j-1);
	}
}

void printRow(char * c,int n){
	for(int i=0;i<n;i++) printf("%s",c);
}

void printTab(PDCell ** tab, int r, int c){
	for(int i=0;i<r;i++){
		printf("\n");
		printRow("----",c);
		printf("\n|");
		for(int j=0;j<c;j++){
			printf(" %d |",tab[i][j].lcs);
		}
	}
	printf("\n");
	printRow("----",c);
}

void getLCS(char * x, char * y){
	int xn = strlen(x) + 1;
	int yn = strlen(y) + 1;
	//1 - Setup dynamic programming table
	PDCell ** pdTab = (PDCell **) malloc(xn * sizeof(PDCell *));
	for(int i=0;i<xn;i++)
		pdTab[i] = (PDCell *)malloc(yn * sizeof(PDCell));
	//2 - Solve simple probelms
	for(int i=0;i<xn;i++) pdTab[i][0].lcs = 0;
	for(int j=0;j<yn;j++) pdTab[0][j].lcs = 0;
	//3 - Fill remaining cells
	for(int i=1;i<xn;i++){
		for(int j=1;j<yn;j++){
			if(x[i-1] == y[j-1]){
				pdTab[i][j].lcs = pdTab[i-1][j-1].lcs + 1;
				pdTab[i][j].choice = 2;
			}else{
				if(pdTab[i-1][j].lcs >= pdTab[i][j-1].lcs){
					pdTab[i][j].lcs = pdTab[i-1][j].lcs;
					pdTab[i][j].choice = 3;
				}else{
					pdTab[i][j].lcs = pdTab[i][j-1].lcs;
					pdTab[i][j].choice = 1;
				}
			}
		}
	}
	//4 - Get result
	printTab(pdTab,xn,yn); //****DEBUG****
	printf("\nLCS size: %d",pdTab[xn-1][yn-1].lcs);
	printf("\nLCS string: ");
	printLCS(pdTab,x,xn-1,yn-1);
	printf("\n");
}

int main(){
	char x[MAX_STR];
	char y[MAX_STR];
	
	scanf("%s",x);
	scanf("%s",y);
	getLCS(x,y);
	
	return 0;
}


