#include <stdio.h>
#define DIMA_R 4
#define DIMA_C 2

#define DIMB_R 2
#define DIMB_C 3


int printProd(int a[][DIMA_C],int b[][DIMB_C],int c[][DIMB_C], int dima_r,int dima_c,int dimb_r, int dimb_c){
    
    for(int i=0;i<dima_r;i++){//Loop c rows
		for(int j=0;j<dimb_c;j++){//Loop c cols
			c[i][j] = 0;
			for(int k=0;k<dimb_r;k++){//Loop rows b (cols a would be equal)
				c[i][j] += a[i][k]*b[k][j]; 
			}
			printf("%d ",c[i][j]);
		}
		printf("\n");
    }
    
}


int main(void){
    int a[DIMA_R][DIMA_C],b[DIMB_R][DIMB_C],c[DIMA_R][DIMB_C];
    int i,j;
    
    //Read a
    for(i=0;i<DIMA_R;i++){
      for(j=0;j<DIMA_C;j++)
        scanf("%d",&a[i][j]);
    }
    //Read b
    for(i=0;i<DIMB_R;i++){
      for(j=0;j<DIMB_C;j++)
        scanf("%d",&b[i][j]);
    }

	printProd(a,b,c,DIMA_R,DIMA_C,DIMB_R,DIMB_C);
	printf("\n");
    
    
    return 0;
    
}
