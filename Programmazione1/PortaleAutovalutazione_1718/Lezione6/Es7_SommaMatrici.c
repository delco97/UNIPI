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

//Print result of sum a+b in matrix sum
int printSum(int a[][DIM_C],int b[][DIM_C], int dimr,int dimc){
    for(int i=0;i<dimr;i++){
    	for(int j=0;j<dimc;j++)
          printf("%d ",a[i][j]+b[i][j]);
        printf("\n");
    }
}


int main(void){
    int a[DIM_R][DIM_C],b[DIM_R][DIM_C],sum[DIM_R][DIM_C];
    
	readIntValues(a,DIM_R,DIM_C);
	readIntValues(b,DIM_R,DIM_C);

	printSum(a,b,DIM_R,DIM_C);

	//printMat(sum,DIM_R,DIM_C);
    
    
    return 0;
    
}
