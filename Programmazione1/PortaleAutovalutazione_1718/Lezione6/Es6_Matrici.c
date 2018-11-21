#include <stdio.h>
#define DIM_R 4
#define DIM_C 3

void readIntValues(int mat[][DIM_C],int dimr, int dimc){
    for(int i=0;i<dimr;i++){
    	for(int j=0;j<dimc;j++)
          scanf("%d",&mat[i][j]);
    }
}

void printMat(int mat[][DIM_C],int dimr, int dimc){
    for(int i=0;i<dimr;i++){
    	for(int j=0;j<dimc;j++)
          printf("%d ",mat[i][j]);
        printf("\n");
    }
}

//Get index of column with only multiple of n. If no column has only n multiples returs -1.
int getColIndexMultiple(int mat[][DIM_C], int dimr,int dimc, int n){
    int trovato = -1, good_col = 0;
    int i=0;
    int j=0;
	while(i<dimc){//Scan col if no good one has beeen found.
		good_col = 1;
		j=0;
		while(good_col && j<dimr){//Scan rows if coll is good
			if( (mat[j][i] % n) != 0)good_col = 0;
			else j++;
		}
		if(good_col)trovato = i;
		i++;
	}
    
    return trovato;
}


int main(void){
    int m[DIM_R][DIM_C];
    
	readIntValues(m,DIM_R,DIM_C);
	
	//printMat(m,DIM_R,DIM_C);
	
	printf("%d\n",getColIndexMultiple(m,DIM_R,DIM_C,3));
    
    
    return 0;
    
}
