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

void printList_Recursicve(LDE l){
	if(l==NULL)printf("NULL\n");
	else {
		printf("%d -> ",l->info);
		printList_Recursicve(l->next);
	}
}


LDE canc_rec(LDE l, int n){
	if(l==NULL){
		return l;
	}else{
		if((l->info %n)==0)return canc_rec(l->next,n);
		else{
			LDE partial = canc_rec(l->next,n);
			push(&partial,l->info);
			return partial;
		}
	}
}

int main(){
    int input,n;
    LDE l = NULL;
    scanf("%d",&n);
	do{
		scanf("%d",&input);
		if(input>=0){//Aggiungi elemento alla lista
			push(&l,input);
		}
	}while(input>=0);
	l = canc_rec(l,n);
	printList_Recursicve(l);
	return 0;
}

