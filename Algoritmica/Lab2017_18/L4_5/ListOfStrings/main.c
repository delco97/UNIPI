#include <stdio.h>
#include <stdlib.h>
#define MAX_STR 101


void printStrings(char ** a,int ns){
    for(int i=0;i<ns;i++)printf("%s\n",a[i]);
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
	char ** a1;

    printf("**** ARRAY OF STRING ****\n ");
	printf("Number of strings: ");
	scanf("%d",&n1);
	if(n1 <= 0){
        printf("The array must be made at least of one element");
	}else{//Good size
        a1 = (char **) malloc(sizeof(char *) * n1);
        if(a1==NULL)printf("A problem occurred during memory allocation (1) ");
        else{
            for(int i=0;i<n1;i++){
                a1[i] = (char *)malloc(sizeof(char) * MAX_STR);
                if(a1[i]==NULL)printf("A problem occurred during memory allocation (2).\nWill be impossible to get the %d ° string.",i+1);
                else{
                    printf("String %d on %d:\n",i+1,n1);
                    scanf("%s",a1[i]);
                }
            }


            printf("Inserted strings:\n");
            printStrings(a1,n1);
            //Deallocation of strings
            for(int i=0;i<n1;i++){
                if(a1[i]!=NULL)free(a1[i]);
            }

            free(a1);
        }
	}


	return EXIT_SUCCESS;
}
