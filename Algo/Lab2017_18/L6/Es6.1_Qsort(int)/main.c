#include <stdio.h>
#include <stdlib.h>

void printArray(int * a,int dim){
	for (int i = 0; i < dim; i++)printf("%d\n",a[i]);
}

/*
Return values:
	<0: p_a < p_b
	>0: p_a > p_b
	=0: p_a = p_b
In this case the order relationship is the following:
	1 - even numbers (0 included) come first, then odd numbers
	2 - even numbers in increasing order
	3 - odd numbers with decreasing order
*/
int compare(const void * p_a,const void * p_b){
	int a = *((int *)p_a);
	int b = *((int *)p_b);
	
	if((a % 2) == 0 && (b % 2) == 0){//Two even number
		return a - b; //Both even => Increasing order
	}else{//One, or both are odd
		if((a % 2) != 0 && (b % 2) != 0)return b - a; //Both odd => decreasing order
		if((a % 2) == 0)return -1;//a even and b odd => a first
		return 1;//a is odd and b in even => b first
	}
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
        else{//Good allocation
            for(int i=0;i<n1;i++)scanf("%d",&a1[i]);
						
          	qsort(a1,n1,sizeof(int),compare);
            printArray(a1,n1);
						
            free(a1);
        }
    }
}
