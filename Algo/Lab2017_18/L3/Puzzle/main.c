#include <stdio.h>
#include <stdlib.h>

void readArray(int *a,int dim, int inf,int sup){
	int i=0,x=0;
    if(a==NULL || dim<1 || inf>sup)return;
    while(i!=dim){
        printf("  %d/%d: \n",i+1,dim);
        scanf("%d",&x);
        if(x>=inf && x<=sup)a[i++]=x;
        else printf("Ricorda gli elementi dell'array devo appartenere al seguente range: [%d,%d]\n",inf,sup);
    }
}

void printArray(int *a,int dim){
	for (int i = 0; i < dim; i++) printf("%d\n",a[i]);
}

int missing(int *a,int N){
    int *aux;
    int i=0,mis=-1;

    aux = (int *)calloc(N+1,sizeof(int));//like malloc but this init elemnts to 0
    if(aux != NULL){
        for(i=0;i<N;i++)aux[a[i]-1]=a[i];
        i=0;
        while(i<N+1 && mis==-1){
            if(aux[i]==0)mis = i+1;
            else i++;
        }
        free(aux);
    }
    return mis;

}


int main(void) {
	int n1=0;
	int * a1;

    printf("**** THE MISSING NUMBER ****\n ");
	printf("Array size: ");
	scanf("%d",&n1);
	if(n1 <= 0){
        printf("The array must be made at least of one element");
	}else{//Good size
        a1 = malloc(sizeof(int)*n1);
        if(a1==NULL)printf("Impossible to allocate an array of %d elements",n1);
        else{
            printf("Insert array elements (allowed range: [1;array:size]):\n");

            readArray(a1,n1,1,n1+1);
            printf("The missing number is: %d",missing(a1,n1));

            free(a1);
        }
	}


	return EXIT_SUCCESS;
}
