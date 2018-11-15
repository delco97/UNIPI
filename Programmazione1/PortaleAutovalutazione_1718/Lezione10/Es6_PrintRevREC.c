#include <stdio.h>
#include <stdlib.h>

struct elemento{
	int info;
	struct elemento * next;
};

typedef struct elemento EDL;
typedef EDL* LDE;

void push(LDE *l, int v){
	LDE aux = malloc(sizeof(EDL));
	aux->info = v;
	aux->next = *l;
	*l=aux;
}

void printListInv_Rec(LDE l){
	if(l!=NULL){
		printListInv_Rec(l->next);
		printf("%d -> ",l->info);
	}
}

void printList_Rec(LDE l){
	if(l==NULL)printf("NULL\n");
	else {
		printf("%d -> ",l->info);
		printList_Rec(l->next);
	}
}

int main(){
    int input;
    LDE l = NULL;

	do{
		scanf("%d",&input);
		if(input>=0){//Aggiungi elemento alla lista
			push(&l,input);
		}
	}while(input>=0);

	//printList_Rec(l);
	printListInv_Rec(l);
	printf("NULL\n");
	return 0;
}

