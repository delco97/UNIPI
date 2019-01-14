#include <stdio.h>
#include <stdlib.h>
void printArray(int * a,int dim){
	for (int i = 0; i < dim; i++)printf("%d ",a[i]);
}

int countZero(int * a,int sx,int dx){
  if(sx > dx)return 0; //Base case empty subarray
  if(sx == dx){//Base case: 1 element
    if(a[sx] == 0)return sx + 1;
    else return sx;
  }else{//Divide
    int cx = (sx+dx)/2;
    if(a[cx] == 1)return countZero(a,sx,cx-1);
    else return countZero(a,cx+1,dx);
  }
}

/*
 A way to perform findMissing in θ(log(k))
*/
int countZero_k(int * a,int sx,int dx){
	int i=0;
	int n= (dx-sx)+1;
	while(i<n && a[i] == 0)i = (2 * i) + 1;
	if(i>=n)//Array lopped without encountering a[i] - 1 != i => The missing number could be found in [(i/2) + 1;n-1]
		return countZero(a,(i/2),n-1);
	else //Array lopped interrupted due to a[i] - 1 == i => The missing number could be found in [(i/2) + 1;i]
		return countZero(a,(i/2),i);
}

int main(void) {
	int n1=0;
	int * a1;

    //printf("**** ARRAY OF STRING ****\n ");
	//printf("Number of strings: ");
	scanf("%d",&n1);
	if(n1 <= 0){
        printf("The array must be made at least of one element");
	}else{//Good size
        a1 = (int *) malloc(sizeof(int) * n1);
        if(a1==NULL)printf("A problem occurred during memory allocation (1) ");
        else{
            for(int i=0;i<n1;i++)scanf("%d",&a1[i]);

            printf("Count 0: %d\n",countZero_k(a1,0,n1-1));
            //printArray(a1,n1);
            free(a1);
        }
    }
}
